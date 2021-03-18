//DUE TO A HARDWARE FAULT DO NOT USE THE LORA MORE THAN ONCE EVERY 3 SECONDS!!!

#include <FlexCAN.h>  //https://github.com/pawelsky/FlexCAN_Library
#include <SPI.h>
#include <RH_RF95.h> //THIS IS A MODIFIED LIBRARY WITHOUT ERROR CHECKING 
#include <RHHardwareSPI1.h>
#include <Adafruit_NeoPixel.h>
#include <SdFat.h>
#include <stdio.h>
#include <map>

#include "hardware_definition_teensy.h"
#include "Gps.h"
#include "Clock.h"
#include "DataProtocol.h"
#include "fc.h"

#define LIVE_FILE_NAME "/LIVEDATA.BIN"
#define DUMPED_FILE_NAME "/DUMPEDDATA.BIN"
#define LEN_MS_SINCE_BOOT_MSG 6
#define GPS_LED 0
#define STATE_LED 1
#define PARACHUTE_DELAY_US 5000000
#define TELECOMMAND_MAX_MSG_LEN 30
#define GPS_BAUD 38400
#define TELEMETRY_BAUD 56000
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

IntervalTimer para1_timer;
IntervalTimer para2_timer;
DataProtocol protocol;
static CAN_message_t can_msg;
FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX
GPS gps1;
GPS gps2;
GPS* best_gps;
uint32_t gps_updated = 0;
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);
SdFs SD;
FsFile live_file;
uint8_t backup_buf[BACKUP_BUF_LEN];
uint8_t backup_index = LEN_MS_SINCE_BOOT_MSG;
uint8_t telemetry_buf[TELEMETRY_BUF_LEN];
uint8_t telemetry_index = LEN_MS_SINCE_BOOT_MSG;
uint8_t telecommand_buf[TELECOMMAND_BUF_LEN];
uint8_t telecommand_index = 0;
uint32_t gps_led_updated = 0;
uint64_t last_cycle_time = 0;
uint64_t cycle_count = 0;
bool error = false;
bool parachute_armed = false;
bool data_logging_enabled = false;
bool telemetry_enabled = false;
bool FPV_enabled = false;
bool gps_led_on = false;

void showError() {
  strip.setPixelColor(STATE_LED, RED);
  strip.show();
  digitalWriteFast(LED_BUILTIN, HIGH);
  error = true;
}

void showOk() {
  if (error){
    return;
  }
  strip.setPixelColor(STATE_LED, GREEN);
  strip.show();
  digitalWriteFast(LED_BUILTIN, LOW);
}

void showNeutral() {
  if (error) {
    return;
  }
  strip.setPixelColor(STATE_LED, BLUE);
  strip.show();
  digitalWriteFast(LED_BUILTIN, HIGH);
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
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_PARA1, OUTPUT);
  pinMode(PIN_PARA2, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  analogWriteFrequency(PIN_BUZZER, BUZZER_FREQ);
  analogWriteRes(8);

  digitalWriteFast(PIN_RFD_DIS, HIGH); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_FPV_DIS, HIGH); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_PARA1, LOW); //LOW IS INACTIVE
  digitalWriteFast(PIN_PARA2, LOW); //LOW IS INACTIVE
  SPI1.setMOSI(PIN_MOSI1);
  SPI1.setMISO(PIN_MISO1);
  SPI1.setSCK(PIN_SCK1);

  delay(100);
}

void initRGB() {
  strip.begin();
  delay(10);
  strip.clear();
  strip.setBrightness(2);
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

void updateGps() {
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

void resetRadio() {
  digitalWriteFast(PIN_RFM_RST, HIGH);
  delay(100);
  digitalWriteFast(PIN_RFM_RST, LOW);
  delay(100);
  digitalWriteFast(PIN_RFM_RST, HIGH);
  delay(100);  
}

void initRadio() {
  resetRadio();
  if (not rfm.init()) {
    showError();
  }
}

void initSD() {
  if (not SD.begin(SdioConfig(FIFO_SDIO))) {
    showError();
    return;
  }
  if (not live_file.open(LIVE_FILE_NAME, O_RDWR | O_CREAT)) {
    showError();
    return;
  }
}

void enableParachute1() {
  digitalWriteFast(PIN_PARA1, LOW);
  analogWrite(PIN_BUZZER, 0);
}

void enableParachute2() {
  digitalWriteFast(PIN_PARA2, LOW);
  analogWrite(PIN_BUZZER, 0);
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

void fc_rx(fc::set_parachute_output msg) {
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
  fc::return_parachute_output_from_flight_controller_to_ground_station_tc response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  response.set_is_parachute1_en(para1);
  response.set_is_parachute2_en(para2);
  response.set_is_parachute_armed(parachute_armed);
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc_rx(fc::set_data_logging msg) {
  data_logging_enabled = msg.get_is_logging_en();
  fc::return_data_logging_from_flight_controller_to_ground_station_tc response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc_rx(fc::handshake msg) {
  fc::return_handshake_from_flight_controller_to_ground_station_tc response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

//catch messages we don't care about
template <class T>
void fc_rx(T msg) {}

void setup() {
  CANbus.begin();
  Serial.begin(115200);
  initRGB();
  initGps();
  initPins();
  initRadio();
  initSD();
  //init telemetry
  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);
  Serial2.begin(TELEMETRY_BAUD);
  showOk();
}

void DataProtocol_callback(uint64_t id, uint8_t* buf, uint8_t len) {
  uint8_t msg_buf[len + HEADER_SIZE];
  uint8_t index = 0;
  protocol.build_header(id, msg_buf, &index);
  add_to_backup_buf(msg_buf, index);
  FC_PARSE_MESSAGE(id, buf);
}

void loop() {
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
      fc::gnss_data_from_flight_controller_to_ground_station_tc msg;
      uint8_t len = msg.get_size() + HEADER_SIZE;
      uint8_t buf[len];
      uint32_t gnss_time = 0;
      int32_t latitude = 0, longitude = 0; 
      uint16_t h_dop = 0;
      uint8_t n_satellites = 0;
      if (gps1.is_set(FLAG_HDOP))
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
      msg.set_gnss_time(gnss_time);
      msg.set_latitude(latitude);
      msg.set_longitude(longitude);
      msg.set_h_dop(h_dop);
      msg.set_n_satellites(n_satellites);
      protocol.build_buf(msg, buf, &len);
      add_to_telecommand_buf(buf, len);
      add_to_backup_buf(buf, len);
    }

    //empty all buffers
    if (telemetry_index > LEN_MS_SINCE_BOOT_MSG) {
      uint8_t index = 0;
      fc::ms_since_boot_from_flight_controller_to_ground_station_tm msg;
      msg.set_ms_since_boot(current_time);
      protocol.build_buf(msg, telemetry_buf, &index);
      if (telemetry_enabled) {
        Serial2.write(telemetry_buf, telemetry_index);
      }
      telemetry_index = LEN_MS_SINCE_BOOT_MSG;
    }
    if (backup_index > LEN_MS_SINCE_BOOT_MSG) {
      uint8_t index = 0;
      fc::ms_since_boot_from_flight_controller_to_ground_station_tm msg;
      msg.set_ms_since_boot(current_time);
      protocol.build_buf(msg, backup_buf, &index);
      if (data_logging_enabled) {
        live_file.write(backup_buf, backup_index);
      }
      backup_index = LEN_MS_SINCE_BOOT_MSG;
    }
    if (telecommand_index > 0 && (cycle_count % LORA_SEND_CYCLE  == 0)) {
      rfm.send(telecommand_buf, telecommand_index);
      Serial.write(telecommand_buf, telecommand_index);
      telecommand_index = 0;
    }
  }
}