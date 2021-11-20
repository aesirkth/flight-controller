#include <Arduino.h>
#include <FlexCAN_T4.h>  //https://github.com/pawelsky/FlexCAN_Library
#include <SPI.h>
#include <WS2812Serial.h>
#include <stdio.h>

#include "Sampler.h"
#include "main.h"
#include "protocol.h"
#include "RandomBuffer.h"

//*********************************** IMPORTANT *******************************************
// modify the serial2.c to increase the buffer size 
// On linux it can be found here
// "/home/olof/.platformio/packages/framework-arduinoteensy/cores/teensy3/serial2.c"
// line 40:
// #define SERIAL2_TX_BUFFER_SIZE     40
// change it to 256
// Otherwise everything will be waaay too slow
// slow code might be ok for debugging but WILL NOT work when actively using the telemetry modem
//*********************************** IMPORTANT *******************************************
#define LEN_MS_SINCE_BOOT_MSG 7
#define GPS_LED 0
#define STATE_LED 1
#define GPS_BAUD 38400
#define TELEMETRY_BAUD 115200

#define TELEMETRY_BANDWIDTH (4000) //bytes
#define TELEMETRY_WRITE_FREQUENCY 70 //Hz
#define TELEMETRY_WRITE_AMOUNT 50 //bytes
static_assert(TELEMETRY_WRITE_FREQUENCY * TELEMETRY_WRITE_AMOUNT < TELEMETRY_BANDWIDTH, "invalid telemtry configuration");

#define FLASH_BANDWIDTH 1250000 //bytes
#define FLASH_WRITE_FREQUENCY 1000 //Hz
#define FLASH_WRITE_AMOUNT 1000 //bytes
static_assert(FLASH_WRITE_FREQUENCY * FLASH_WRITE_AMOUNT < FLASH_BANDWIDTH, "invalid flash configuration");

#define LORA_WRITE_FREQUENCY 0.2 //Hz
//too slow to properly do this
static_assert(FLASH_WRITE_FREQUENCY * FLASH_WRITE_AMOUNT < FLASH_BANDWIDTH, "invalid flash configuration");


uint8_t telemetry_buf[2048];
uint8_t flash_buf[4096];
uint8_t lora_buf[256];
RandomBuffer telemetry_queue {telemetry_buf,  sizeof(telemetry_buf)};
RandomBuffer flash_queue {flash_buf, sizeof(flash_buf)};
RandomBuffer lora_queue {lora_buf, sizeof(lora_buf)};

Sampler sampler;
GPS gps1; // for gps
GPS gps2; // for gps
SPISettings settingsFlash(10000000, MSBFIRST, SPI_MODE0); // SPI bus settings to communicate with the Flash IC
Flash flash(&SPI_FLASH, settingsFlash, PIN_FLASH_CS); // flash chip
FlexCAN_T4<CAN2, RX_SIZE_16, TX_SIZE_16> can;  // 1Mbs, CAN0, pins 29&30 for TX&RX
IntervalTimer para1_timer; // timer for parachute 1
IntervalTimer para2_timer; // timer for parachute 1
GPS* best_gps; // stores the best gps
RH_RF95 rfm(PIN_RF_CS, PIN_RF_INT); // LoRa modem, on SPI0
byte drawingMemory[2*3];         //  3 bytes per LED
DMAMEM byte displayMemory[2*12]; // 12 bytes per LED
WS2812Serial strip(2, displayMemory, drawingMemory, 17, WS2812_RGB);
SdFs SD; // SD card handler

bool error = false;
bool parachute_armed = false;
bool data_logging_enabled = false;
bool telemetry_enabled = true;
bool telecommand_enabled = true;
bool FPV_enabled = false;
bool gps_led_on = false;

void showError();
void showOk();
void showNeutral();

void showError() {
  strip.setPixel(STATE_LED, RED);
  strip.show();
  error = true;
}

void showOk() {
  if (error){
    return;
  }
  strip.setPixel(STATE_LED, GREEN);
  strip.show();
}

void showNeutral() {
  if (error) {
    return;
  }
  strip.setPixel(STATE_LED, BLUE);
  strip.show();
}

void initPins() {
  pinMode(PIN_TM_MOS, OUTPUT);
  pinMode(PIN_CAN_MOS, OUTPUT);
  pinMode(PIN_FPV_MOS, OUTPUT);
  pinMode(PIN_RF_RESET, OUTPUT);
  pinMode(PIN_PYRO_1, OUTPUT);
  pinMode(PIN_PYRO_2, OUTPUT);
  pinMode(PIN_PYRO_3, OUTPUT);
  pinMode(PIN_PYRO_4, OUTPUT);
  pinMode(PIN_PYRO_5, OUTPUT);
  pinMode(PIN_PYRO_6, OUTPUT);
  pinMode(PIN_PYRO_EN, OUTPUT);
  pinMode(PIN_RGB_TX, OUTPUT);

  pinMode(PIN_BUZZER, OUTPUT); //this one is not routed on the PCB lol
  analogWriteFrequency(PIN_BUZZER, 2400);
  analogWriteRes(8);
  
  digitalWriteFast(PIN_TM_MOS, !telemetry_enabled); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_FPV_MOS, !FPV_enabled); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_PYRO_1, LOW); //LOW IS INACTIVE
  digitalWriteFast(PIN_PYRO_2, LOW);
  digitalWriteFast(PIN_PYRO_3, LOW);
  digitalWriteFast(PIN_PYRO_4, LOW);
  digitalWriteFast(PIN_PYRO_5, LOW);
  digitalWriteFast(PIN_PYRO_6, LOW);
  digitalWriteFast(PIN_PYRO_EN, LOW);
  digitalWriteFast(PIN_CAN_MOS, HIGH);
  
  SPI1.setMOSI(PIN_MOSI1);
  SPI1.setMISO(PIN_MISO1);
  SPI1.setSCK(PIN_SCK1);
  SPI1.begin();
  SPI.setMOSI(PIN_MOSI0);
  SPI.setMISO(PIN_MISO0);
  SPI.setSCK(PIN_SCK0);
  SPI.begin();
  delay(100);
}

void initRGB() {
  strip.begin();
  delay(10);
  strip.clear();
  strip.show();
  delay(100);
  strip.setPixel(STATE_LED, BLUE);
  strip.show();
}

void initGps() {
  //GPS 1
  GPS_SERIAL.setRX(PIN_GPS_RX);
  GPS_SERIAL.setTX(PIN_GPS_TX);
  GPS_SERIAL.begin(GPS_BAUD);

  //GPS 2
  EXT_SERIAL.setRX(PIN_EXT_RX);
  EXT_SERIAL.setTX(PIN_EXT_TX);
  EXT_SERIAL.begin(GPS_BAUD);
}

void saveFlash(void*) {
  static uint16_t leftover_bytes = 0;
  fc::ms_since_boot_from_flight_controller_to_ground_station time_msg;
  uint8_t timestamp_size = HEADER_SIZE + time_msg.get_size();
  uint8_t header_buf[HEADER_SIZE + time_msg.get_size()];
  uint8_t header_index = 0;
  time_msg.set_ms_since_boot(millis());
  time_msg.build_buf(header_buf, &header_index);
  uint16_t bytes_to_write = min(FLASH_WRITE_AMOUNT - timestamp_size + leftover_bytes, flash_queue.get_used_size());
  leftover_bytes -= bytes_to_write - (FLASH_WRITE_AMOUNT - timestamp_size);
  uint8_t content_buf[bytes_to_write];
  flash_queue.dequeue(content_buf, bytes_to_write);
  flash.bufferedWrite(header_buf, header_index);
  flash.bufferedWrite(content_buf, bytes_to_write);
}

void sendTelemetry(void*) {
  static uint16_t leftover_bytes = 0;
  fc::ms_since_boot_from_flight_controller_to_ground_station time_msg;
  uint8_t timestamp_size = HEADER_SIZE + time_msg.get_size();
  uint8_t header_buf[HEADER_SIZE + time_msg.get_size()];
  uint8_t header_index = 0;
  time_msg.set_ms_since_boot(millis());
  time_msg.build_buf(header_buf, &header_index);
  uint16_t bytes_to_write = min(TELEMETRY_WRITE_AMOUNT - timestamp_size + leftover_bytes, telemetry_queue.get_used_size());
  leftover_bytes -= bytes_to_write - (TELEMETRY_WRITE_AMOUNT - timestamp_size);
  uint8_t content_buf[bytes_to_write];
  telemetry_queue.dequeue(content_buf, bytes_to_write);
  TM_SERIAL.write(header_buf, header_index);
  TM_SERIAL.write(content_buf, bytes_to_write);
}

void sendLora(void*) {
  //TODO:
}

void initSampler() {
  sampler.insertFunction(saveFlash, FLASH_WRITE_FREQUENCY);
  sampler.insertFunction(sendTelemetry, TELEMETRY_WRITE_FREQUENCY);
  sampler.insertFunction(sendLora, LORA_WRITE_FREQUENCY);
}

void resetRadio() {
  digitalWriteFast(PIN_RF_RESET, HIGH);
  delay(100);
  digitalWriteFast(PIN_RF_RESET, LOW);
  delay(100);
  digitalWriteFast(PIN_RF_RESET, HIGH);
  delay(100);  
}

void initRadio() {
  /* Init radio communication and set frequency and power parameters */
  resetRadio();

  bool rfm_init_success = rfm.init();
  if (rfm_init_success) {
    rfm.setFrequency(RFM_FREQUENCY);
    rfm.setTxPower(RFM_POWER);
  } else {
    showError();
  } 
}

void initFlash() {
  if (!flash.begin()) {
    showError();
  }
}

void initSensors() {
  
}

void updateGps() {
  static uint32_t gps_led_updated = 0;
  //gps 1
  bool updated = false;
  while (GPS_SERIAL.available() > 0) {
    if (gps1.parse_byte(GPS_SERIAL.read())) {
      updated |= true;
    }
  }

  //gps 2
  while (EXT_SERIAL.available() > 0) {
    if (gps2.parse_byte(EXT_SERIAL.read())) {
      updated |= true;
    }
  }

  //get best GPS
  if (gps1.is_set(FLAG_HDOP) && gps2.is_set(FLAG_HDOP)) {
    best_gps = gps1.hdop < gps2.hdop ? &gps1 : &gps2;
  } else {
    best_gps = gps1.is_set(FLAG_HDOP) ? &gps1 : &gps2;
  }

  //update led
  if (updated && not gps_led_on) {
    if (gps1.is_set(FLAG_LATITUDE) || gps2.is_set(FLAG_LATITUDE)) {
      gps_led_updated = millis();
      strip.setPixelColor(GPS_LED, GREEN);
      gps_led_on = true;
      strip.show();
    } else
    if (gps1.is_set(FLAG_TIME) || gps2.is_set(FLAG_TIME)) {
      gps_led_updated = millis();
      strip.setPixelColor(GPS_LED, BLUE);
      gps_led_on = true;
      strip.show();
    }
  }
  if (millis() - gps_led_updated > 100 && gps_led_on) {
    strip.setPixelColor(0, 0);
    strip.show();
    gps_led_on = false;
  }
}

void setup() {
  while (!Serial){}
  can.begin();
  can.setBaudRate(1000000);
  Serial.begin(115200);
  initRGB();
  initGps();
  initPins();
  //initRadio();
  initFlash();
  initSensors();
  //init telemetry
  TM_SERIAL.setRX(PIN_TM_RX);
  TM_SERIAL.setTX(PIN_TM_TX);
  TM_SERIAL.begin(TELEMETRY_BAUD);
  //This is very important, see above
  if (Serial2.availableForWrite() < 256) {
    showError();
  }
  showOk();
}

void loop() {
  static uint32_t last_update = micros();
  uint32_t current_time = micros();
  uint32_t dt = current_time - last_update;
  last_update = current_time;
  sampler.update(dt);
  updateGps();
  handleDataStreams();
}