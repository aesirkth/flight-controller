#include <Arduino.h>
#include <FlexCAN.h>  //https://github.com/pawelsky/FlexCAN_Library
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <stdio.h>
#include <map>

#include "MS5611.h"
#include "DmaSpi.h" // SPI using DMA, KurtE's branch, chipselect.h modified to support callbacks
#include "SdFat.h" // read and write from the sd-card
#include "RH_RF95.h" // LoRa radio, modified to skip some error checking 
#include "RHHardwareSPI1.h" // headers for SPI1 and radiohead
#include "hardware_definition_teensy.h" // pin definitions
#include "Gps.h" // GPS
#include "DataProtocol.h" // to extract and find data in a stream
#include "fc.h" // to decode and encode data
#include "FlashMemory.hpp" // read and write to the flash chip, hard coded to use SPI1

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
#define DUMPED_FILE_NAME "/DUMPEDDATA.BIN"
#define LEN_MS_SINCE_BOOT_MSG 7
#define GPS_LED 0
#define STATE_LED 1
#define PARACHUTE_DELAY_US 5000000
#define TELECOMMAND_MAX_MSG_LEN 30
#define GPS_BAUD 38400
#define TELEMETRY_BAUD 57600
#define BLUE 0x0000FF //blue
#define GREEN 0x00FF00 //green
#define RED 0xFF0000 //red
#define BACKUP_BUF_LEN 100
#define TELEMETRY_BUF_LEN 100
#define TELECOMMAND_BUF_LEN 100

#define CYCLES_PER_SEC 1000
#define CYCLE_DELAY_US (1000000 / CYCLES_PER_SEC)
#define CYCLE_DELAY_MS (1000 / CYCLES_PER_SEC)
#define LORA_SEND_CYCLE 3000
#define BLINK_LED_CYCLE 3000
#define PING_EDDA_CYCLE 5000
#define TC_GNSS_CYCLE 6000

struct default_uint8 {
  uint8_t val = 1;
};

std::map<uint8_t, struct default_uint8> can_relay_frequency;
std::map<uint8_t, uint8_t> can_message_count;

GPS gps1; // for gps on Serial1
GPS gps2; // for gps on Serial3
SPISettings settingsFlash(10000000, MSBFIRST, SPI_MODE0); // SPI bus settings to communicate with the Flash IC
Flash flash(&SPI1, settingsFlash, PIN_CS_FLASH, PIN_WP, PIN_HOLD); // flash chip
MS5611 ms1(PIN_CS_MS1, SPI); // pressure sensor
MS5611 ms2(PIN_CS_MS2, SPI); // pressure sensor
IntervalTimer para1_timer; // timer for parachute 1
IntervalTimer para2_timer; // timer for parachute 1
DataProtocol protocol; // data protocol reader
static CAN_message_t can_msg; // msg for the can bus
FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX
GPS* best_gps; // stores the best gps
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1); // LoRa modem
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400); // led lights
SdFs SD; // SD card handler
uint8_t backup_buf[BACKUP_BUF_LEN]; // buf for the flashchip
uint8_t backup_index = LEN_MS_SINCE_BOOT_MSG; // index for flashchip buf
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
  memcpy(telemetry_buf + telemetry_index, buf, size);
  telemetry_index += size;
}

void add_to_telecommand_buf(uint8_t* buf, uint8_t size) {
  memcpy(telecommand_buf + telecommand_index, buf, size);
  telecommand_index += size;
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
  digitalWriteFast(PIN_RFD_DIS, LOW); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_FPV_DIS, LOW); //HIGH MEANS DISABLED
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

void initSD() {
  if (not SD.begin(SdioConfig(FIFO_SDIO))) {
    showError();
    return;
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

void enableParachute1() {
  digitalWriteFast(PIN_PARA1, HIGH);
  analogWrite(PIN_BUZZER, 0);
  para1_timer.end();
}

void enableParachute2() {
  digitalWriteFast(PIN_PARA2, HIGH);
  analogWrite(PIN_BUZZER, 0);
  para2_timer.end();
}

void DataProtocolCallback(uint8_t id, uint8_t* buf, uint8_t len) {
  uint8_t header_buf[HEADER_SIZE];
  uint8_t header_index = 0;
  protocol.build_header(id, header_buf, &header_index);
  add_to_backup_buf(header_buf, header_index); // add header
  add_to_backup_buf(buf, len); // add message
  // parse the message no matter what, nothing will happen if it's invalid
  fc::parse_message(id, buf); 
  //relay gc -> ec messages
  if (GC_TO_EC_TC_START <= id && id <= GC_TO_EC_TC_END) {
    can_msg.id = id;
    memcpy(can_msg.buf, buf, len);
    can_msg.len = len;
    CANbus.write(can_msg);
  }
  //relay ec -> telecommand
  if (EC_TO_GC_TC_START <= id && id <= EC_TO_GC_TC_END) {
    add_to_telecommand_buf(header_buf, header_index);
    add_to_telecommand_buf(buf, len);
  }
  //relay ec -> telemetry
  if (EC_TO_GC_TM_START <= id && id <= EC_TO_GC_TM_END) {
    can_message_count[id] = (can_message_count[id] + 1) % can_relay_frequency[id].val;
    if (can_message_count[id] == 0) {
      add_to_telemetry_buf(header_buf, header_index);
      add_to_telemetry_buf(buf, len);
    }
  }
}

void handleDataStreams() {
  uint8_t buf[TELECOMMAND_MAX_MSG_LEN];
  uint8_t len = TELECOMMAND_MAX_MSG_LEN;
  while (Serial.available() > 0) {
    uint8_t byte = Serial.read();
    protocol.parse_byte(byte);
  }
  if (rfm.recv(buf, &len)) {
    protocol.parse_frame(buf, len);
  }
  if(CANbus.available()) {
    CANbus.read(can_msg);
    protocol.parse_CAN_message(can_msg);
  }
}

void fc::rx(fc::set_parachute_output_from_ground_station_to_flight_controller msg) {
  bool para1 = parachute_armed && msg.get_is_parachute1_en();
  bool para2 = parachute_armed && msg.get_is_parachute2_en();
  parachute_armed = msg.get_is_parachute_armed();

  if (para1) {
    analogWrite(PIN_BUZZER, 122);
    para1_timer.begin(enableParachute1, PARACHUTE_DELAY_US);
  }
  if (para2) {
    analogWrite(PIN_BUZZER, 122);
    para2_timer.begin(enableParachute1, PARACHUTE_DELAY_US); 
  }
  fc::return_parachute_output_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  response.set_is_parachute1_en(para1);
  response.set_is_parachute2_en(para2);
  response.set_is_parachute_armed(parachute_armed);
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc::rx(fc::set_data_logging_from_ground_station_to_flight_controller msg) {
  data_logging_enabled = msg.get_is_logging_en();
  fc::return_data_logging_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc::rx(fc::handshake_from_ground_station_to_flight_controller msg) {
  fc::return_handshake_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
  delay(100);
  Serial.write(buf, len);
  delay(500);
}

void emptyBuffers(uint64_t cycle_count, uint64_t current_time) {
  //empty all buffers
  if (telemetry_index > LEN_MS_SINCE_BOOT_MSG) {
    uint8_t index = 0;
    fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    msg.set_ms_since_boot(current_time);
    protocol.build_buf(msg, telemetry_buf, &index);
    if (telemetry_enabled) {
      Serial2.write(telemetry_buf, telemetry_index);
      Serial.write(telemetry_buf, telemetry_index);
    }
    telemetry_index = LEN_MS_SINCE_BOOT_MSG;
  }
  if (backup_index > LEN_MS_SINCE_BOOT_MSG) {
    uint8_t index = 0;
    fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    msg.set_ms_since_boot(current_time);
    protocol.build_buf(msg, backup_buf, &index);
    if (data_logging_enabled) {
      flash.bufferedWrite(backup_buf, backup_index);
    }
    Serial.write(telecommand_buf, telecommand_index);
    backup_index = LEN_MS_SINCE_BOOT_MSG;
  }
  if (telecommand_index > LEN_MS_SINCE_BOOT_MSG &&
      cycle_count % LORA_SEND_CYCLE  == 0 && !DMASPI1.busy()) {
    uint8_t index = 0;
    fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    msg.set_ms_since_boot(current_time);
    protocol.build_buf(msg, telecommand_buf, &index);
    if (telecommand_enabled) {
      rfm.send(telecommand_buf, telecommand_index);
    }
    telecommand_index = LEN_MS_SINCE_BOOT_MSG;
  }
}

void setup() {
  protocol.set_callback(&DataProtocolCallback);
  CANbus.begin();
  Serial.begin(115200);
  initRGB();
  initGps();
  initPins();
  initRadio();
  initSD();
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
  showOk();
}

void loop() {
  static uint64_t last_cycle_time = 0;
  static uint64_t cycle_count = 0;

  updateGps();
  handleDataStreams();

  uint32_t current_time = millis();
  if (current_time - last_cycle_time >= CYCLE_DELAY_MS) {
    if (current_time - last_cycle_time > CYCLE_DELAY_MS) {
      //Serial.println(current_time);
    }

    last_cycle_time = current_time;
    cycle_count++;
    if (cycle_count % BLINK_LED_CYCLE == 0) {
      showOk();
    }
    if ((cycle_count + BLINK_LED_CYCLE / 2) % BLINK_LED_CYCLE == 0) {
      showNeutral();
    }
    if (cycle_count % PING_EDDA_CYCLE == 0) {
      //PING!
      //PONG!
    }
    if (cycle_count % TC_GNSS_CYCLE == 0) {
      fc::gnss_data_from_flight_controller_to_ground_station tc_msg;
      fc::GNSS_data_1_from_flight_controller_to_ground_station tm_msg;
      uint8_t len = 0;
      uint8_t buf[50];
      uint32_t gnss_time = 0;
      int32_t latitude = 0, longitude = 0; 
      uint16_t h_dop = 0;
      uint8_t n_satellites = 0;
      if (best_gps->is_set(FLAG_HDOP))
      if (best_gps->is_set(FLAG_TIME)) {
        gnss_time = best_gps->raw_time;
      }
      if (best_gps->is_set(FLAG_LATITUDE)) {
        latitude = best_gps->latitude_degrees * 100 + best_gps->latitude_minutes;
      }
      if (best_gps->is_set(FLAG_LONGITUDE)) {
        latitude = best_gps->longitude_degrees * 100 + best_gps->longitude_minutes;
      }
      if (best_gps->is_set(FLAG_HDOP)) {
        h_dop = best_gps->hdop;
      }
      if (best_gps->is_set(FLAG_N_SATELLITES)) {
        n_satellites = best_gps->n_satellites;
      }
      gps1.clear_flags();
      gps2.clear_flags();
      tc_msg.set_gnss_time(gnss_time);
      tc_msg.set_latitude(latitude);
      tc_msg.set_longitude(longitude);
      tc_msg.set_h_dop(h_dop);
      tc_msg.set_n_satellites(n_satellites);
      protocol.build_buf(tc_msg, buf, &len);
      add_to_telecommand_buf(buf, len);
      add_to_backup_buf(buf, len);
      tm_msg.set_gnss_time(gnss_time);
      tm_msg.set_latitude(latitude);
      tm_msg.set_longitude(longitude);
      protocol.build_buf(tm_msg, buf, &len);
      add_to_telemetry_buf(buf, len);
      add_to_backup_buf(buf, len);
    }
  }

  emptyBuffers(cycle_count, current_time);
}