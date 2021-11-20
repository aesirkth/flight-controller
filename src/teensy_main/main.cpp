#include <Arduino.h>
#include <FlexCAN_T4.h>  //https://github.com/pawelsky/FlexCAN_Library
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <stdio.h>

#include "main.h"
#include "protocol.h"

//*********************************** IMPORTANT *******************************************
// DUE TO A HARDWARE FAULT DO NOT USE THE LORA MORE THAN ONCE EVERY 3 SECONDS!!!
// The radiohead library has been modified to not do it.
//*********************************** IMPORTANT *******************************************

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
#define TELEMETRY_BAUD 57600
#define BLUE 0x0000FF //blue
#define GREEN 0x00FF00 //green
#define RED 0xFF0000 //red
#define BACKUP_BUF_LEN 512
#define TELEMETRY_BUF_LEN 100
#define TELECOMMAND_BUF_LEN 100

#define CYCLES_PER_SEC 1000
#define CYCLE_DELAY_US (1000000 / CYCLES_PER_SEC)
#define CYCLE_DELAY_MS (1000 / CYCLES_PER_SEC)
#define LORA_SEND_CYCLE 3000
#define BLINK_LED_CYCLE 3000
#define PING_EDDA_CYCLE 5000
#define TC_GNSS_CYCLE 6000

GPS gps1; // for gps on Serial1
GPS gps2; // for gps on Serial3
SPISettings settingsFlash(10000000, MSBFIRST, SPI_MODE0); // SPI bus settings to communicate with the Flash IC
Flash flash(&SPI1, settingsFlash, PIN_CS_FLASH, PIN_WP, PIN_HOLD); // flash chip
MS5611 ms1(PIN_CS_MS1, SPI); // pressure sensor
MS5611 ms2(PIN_CS_MS2, SPI); // pressure sensor
IntervalTimer para1_timer; // timer for parachute 1
IntervalTimer para2_timer; // timer for parachute 1
FlexCAN_T4<CAN0, RX_SIZE_128, TX_SIZE_128> CANbus;
GPS* best_gps; // stores the best gps
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1); // LoRa modem
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400); // led lights
SdFs SD; // SD card handler
uint8_t backup_buf[BACKUP_BUF_LEN]; // buf for the flashchip
uint16_t backup_index = LEN_MS_SINCE_BOOT_MSG; // index for flashchip buf
uint8_t telemetry_buf[TELEMETRY_BUF_LEN]; // buf for the telemetry modem
uint8_t telemetry_index = LEN_MS_SINCE_BOOT_MSG; // index for telemetry buf
uint8_t telecommand_buf[TELECOMMAND_BUF_LEN]; // buf for the LoRa modem
uint8_t telecommand_index = LEN_MS_SINCE_BOOT_MSG; // index for the LoRa modem buf
bool error = false;
bool parachute_armed = false;
bool data_logging_enabled = false;
bool telemetry_enabled = true;
bool telecommand_enabled = true;
bool FPV_enabled = false;
bool gps_led_on = false;
bool rfm_init_success = 0;

void showError();
void showOk();
void showNeutral();

void showError() {
  strip.setPixelColor(STATE_LED, RED);
  strip.show();
  error = true;
}

void showOk() {
  if (error){
    return;
  }
  strip.setPixelColor(STATE_LED, GREEN);
  strip.show();
}

void showNeutral() {
  if (error) {
    return;
  }
  strip.setPixelColor(STATE_LED, BLUE);
  strip.show();
}

void add_to_backup_buf(uint8_t* buf, uint8_t size) {
  memcpy(backup_buf + backup_index, buf, size);
  backup_index += size;
}

void add_to_telemetry_buf(uint8_t* buf, uint8_t size) {
  //memcpy(telemetry_buf + telemetry_index, buf, size);
  //telemetry_index += size;
}

void add_to_telecommand_buf(uint8_t* buf, uint8_t size) {
  add_to_telemetry_buf(buf, size);
  //memcpy(telecommand_buf + telecommand_index, buf, size);
  //telecommand_index += size;
}

void initPins() {
  pinMode(PIN_RFD_DIS, OUTPUT);
  pinMode(PIN_FPV_DIS, OUTPUT);
  pinMode(PIN_RFM_RST, OUTPUT);
  pinMode(PIN_PARA1, OUTPUT);
  pinMode(PIN_PARA2, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  analogWriteFrequency(PIN_BUZZER, BUZZER_FREQ);
  analogWriteRes(8);
  digitalWriteFast(PIN_RFD_DIS, !telemetry_enabled); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_FPV_DIS, !FPV_enabled); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_PARA1, LOW); //LOW IS INACTIVE
  digitalWriteFast(PIN_PARA2, LOW); //LOW IS INACTIVE
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
  strip.setBrightness(10);
  strip.show();
  delay(100);
  strip.setPixelColor(STATE_LED, BLUE);
  strip.show();
  digitalWriteFast(LED_BUILTIN, LOW);
}

void initGps() {
  //GPS 1
  Serial1.setRX(PIN_RX1);
  Serial1.setTX(PIN_TX1);
  Serial1.begin(GPS_BAUD);

  //GPS 2
  Serial3.setRX(PIN_RX3);
  Serial3.setTX(PIN_TX3);
  Serial3.begin(GPS_BAUD);
}

void resetRadio() {
  digitalWriteFast(PIN_RFM_RST, HIGH);
  delay(100);
  digitalWriteFast(PIN_RFM_RST, LOW);
  delay(100);
  digitalWriteFast(PIN_RFM_RST, HIGH);
  delay(100);  
}

void initRadio() {
  /* Init radio communication and set frequency and power parameters */
  resetRadio();

  rfm_init_success = rfm.init();
  if (rfm_init_success) {
    rfm.setFrequency(RFM_FREQ);
    rfm.setTxPower(RFM_TX_POWER);
  } else {
    showError();
  } 
}

void initFlash() {
  if (!flash.begin()) {
    showError();
  }
}

void initDMA() {
  if (not DMASPI1.begin()) {
    showError();
  }
  DMASPI1.start();
}

void initSensors() {
  ms1.begin();
}

void updateGps() {
  static uint32_t gps_led_updated = 0;
  //gps 1
  bool updated = false;
  while (Serial1.available() > 0) {
    if (gps1.parse_byte(Serial1.read())) {
      updated |= true;
    }
  }

  //gps 2
  while (Serial3.available() > 0) {
    if (gps2.parse_byte(Serial3.read())) {
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
  while(!Serial){}
  CANbus.begin();
  CANbus.setBaudRate(1000000);
  CANbus.setRX(ALT);
  CANbus.setTX(ALT);
  Serial.begin(115200);
  initRGB();
  initGps();
  initPins();
  initRadio();
  initFlash();
  initDMA();
  initSensors();
  //init telemetry
  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);
  Serial2.begin(TELEMETRY_BAUD);
  //This is very important, see above
  if (Serial2.availableForWrite() < 128) {
    showError();
  }

  flash.writeEnable();
  flash.blockErase(2);
  uint8_t write_buf[2048];
  uint8_t read_buf[2048] = {0};
  uint8_t byte = 0;
  
  showOk();
}

void emptyBuffers(uint64_t cycle_count, uint64_t current_time) {
  //empty all buffers
  if (telemetry_index > LEN_MS_SINCE_BOOT_MSG) {
    uint8_t index = 0;
    fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    msg.set_ms_since_boot(current_time);
    DataProtocol::build_buf(&msg, telemetry_buf, &index);
    if (telemetry_enabled) {
      Serial2.write(telemetry_buf, telemetry_index);
      //Serial.write(telemetry_buf, telemetry_index);
    }
    telemetry_index = LEN_MS_SINCE_BOOT_MSG;
  }
  if (backup_index > LEN_MS_SINCE_BOOT_MSG) {
    uint8_t index = 0;
    fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    msg.set_ms_since_boot(current_time);
    DataProtocol::build_buf(&msg, backup_buf, &index);
    if (data_logging_enabled) {
      flash.bufferedWrite(backup_buf, backup_index);
    }
    Serial.write(backup_buf, backup_index);
    backup_index = LEN_MS_SINCE_BOOT_MSG;
  }
  if (telecommand_index > LEN_MS_SINCE_BOOT_MSG &&
      cycle_count % LORA_SEND_CYCLE  == 0 && !DMASPI1.busy()) {
    uint8_t index = 0;
    fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    msg.set_ms_since_boot(current_time);
    DataProtocol::build_buf(&msg, telecommand_buf, &index);
    if (telecommand_enabled) {
      rfm.send(telecommand_buf, telecommand_index);
      Serial2.write(telecommand_buf, telecommand_index);
    }
    telecommand_index = LEN_MS_SINCE_BOOT_MSG;
  }
}

void loop() {
  return;
  static uint32_t last_cycle_time = 0;
  static uint32_t cycle_count = 0;
  updateGps();
  handleDataStreams();
  uint32_t current_time = millis();
  if (current_time - last_cycle_time < CYCLE_DELAY_MS) {
    return;
  }
  emptyBuffers(cycle_count, current_time);
}