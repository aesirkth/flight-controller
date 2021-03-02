//#include <FlexCAN_.h>  // https://github.com/pawelsky/FlexCAN_Library
#include <FlexCAN.h>
#include <SPI.h>
#include <RH_RF95.h>
#include <RHSoftwareSPI.h>
#include <RHHardwareSPI1.h>
#include <Adafruit_NeoPixel.h>
#include <SD.h>
#include <stdio.h>

#include "hardware_definition_teensy.h"
#include "Gps.h"
#include "Clock.h"
#include "DataProtocol.h"

#define LIVE_FILE_NAME "/LIVEDATA.RAW"
#define DUMPED_FILE_NAME "/DUMPEDDATA.RAW"
#define LEN_CURRENT_TIME_MSG 6
#define GPS_LED 0
#define STATE_LED 1
#define PARACHUTE_DELAY_US 5000000
#define TELECOMMAND_MAX_MSG_LEN 30
#define GPS_BAUD 38400
#define TELEMETRY_BAUD 56000
#define BLUE 0x0000FF //blue
#define GREEN 0x00FF00 //green
#define RED 0xFF0000 //red
#define RFM_TX_POWER 13 //legal max
#define BACKUP_BUF_LEN 100
#define TELEMETRY_BUF_LEN 100
#define TELECOMMAND_BUF_LEN 100
#define CYCLES_PER_SEC 1000
#define CYCLE_DELAY_US (1000000 / CYCLES_PER_SEC)
#define CYCLE_DELAY_MS (1000 / CYCLES_PER_SEC)
#define BLINK_LED_CYCLE 3000
#define PING_EDDA_CYCLE 5000
#define TC_GNSS_CYCLE 5000

IntervalTimer para1_timer;
IntervalTimer para2_timer;
DataProtocol protocol;
static CAN_message_t msg;
FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX
GPS gps1;
GPS gps2;
GPS* best_gps;
uint32_t gps_updated = 0;
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);
File file; //SD-card backup
Clock clock;
uint8_t backup_buf[BACKUP_BUF_LEN];
uint8_t backup_index = LEN_CURRENT_TIME_MSG;
uint8_t telemetry_buf[TELEMETRY_BUF_LEN];
uint8_t telemetry_index = LEN_CURRENT_TIME_MSG;;
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
  digitalWriteFast(LED_BUILTIN, LOW);
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
  if (not SD.begin(BUILTIN_SDCARD)) {
    showError();
    return;
  }
  if (SD.exists(LIVE_FILE_NAME)) {
    SD.remove(LIVE_FILE_NAME);
  }
  file = SD.open(LIVE_FILE_NAME, FILE_WRITE);
  if (not file) {
    showError();
    return;
  }
}

void handleCAN() {
  if (!CANbus.available()) {
    return;
  }
  CANbus.read(msg);
  if (EC_TO_GS_TM_RANGE_START <= msg.id && msg.id <= EC_TO_GS_TM_RANGE_END) {
    add_to_backup_buf(msg.buf, msg.len);
    add_to_telemetry_buf(msg.buf, msg.len);
  }else
  if (EC_TO_GS_RANGE_START <= msg.id && msg.id <= EC_TO_GS_RANGE_END) {
    add_to_backup_buf(msg.buf, msg.len);
    add_to_telecommand_buf(msg.buf, msg.len);
  } else {
    add_to_backup_buf(msg.buf, msg.len);
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

void handleTelecommand() {
  uint8_t buf[TELECOMMAND_MAX_MSG_LEN];
  uint8_t len = TELECOMMAND_MAX_MSG_LEN;
  bool updated = false;
  while (Serial.available() > 0) {
    uint8_t byte = Serial.read();
    updated |= protocol.parse_byte((uint8_t) byte);
  }
  if (rfm.recv(buf, &len)) {
    updated |= protocol.parse_frame(buf, len);
    add_to_backup_buf(buf, len);
  }
  if (not updated) {
    return;
  }
  if (protocol.is_set(FLAG_ENGINE_MESSAGE_AVAILABLE)) {
    CANbus.write(protocol.engine_msg);
  }
  if (protocol.is_set(FLAG_SET_PARACHUTE_OUTPUT)) {
    bool para1 = parachute_armed && protocol.is_parachute1_en;
    bool para2 = parachute_armed && protocol.is_parachute2_en;
    parachute_armed = protocol.is_parachute_armed;
    if (para1) {
      analogWrite(PIN_BUZZER, 122);
      para1_timer.begin(enableParachute1, PARACHUTE_DELAY_US);
    }
    if (para2) {
      analogWrite(PIN_BUZZER, 122);
      para2_timer.begin(enableParachute1, PARACHUTE_DELAY_US); 
    }
    len = protocol.build_return_parachute_output(buf, parachute_armed, para1, para2);
    add_to_telecommand_buf(buf, len);
    add_to_backup_buf(buf, len);
  }
  if (protocol.is_set(FLAG_SET_DATA_LOGGING)) {
    data_logging_enabled = protocol.data_logging_en;
    len = protocol.build_return_data_logging(buf, data_logging_enabled);
    add_to_telecommand_buf(buf, len);
    add_to_backup_buf(buf, len);
  }
  if (protocol.is_set(FLAG_SET_RADIO_TRANSMITTERS)) {
    telemetry_enabled = protocol.is_tm_en;
    FPV_enabled = protocol.is_fpv_en;
    digitalWriteFast(PIN_RFD_DIS, telemetry_enabled);
    digitalWriteFast(PIN_FPV_DIS, FPV_enabled);
    len = protocol.build_return_radio_equipment(buf, FPV_enabled, telemetry_enabled);
    add_to_telecommand_buf(buf, len);
    add_to_backup_buf(buf, len);
  }
  if (protocol.is_set(FLAG_TIME_SYNC)) {
    clock.update(protocol.raw_time);
    len = protocol.build_return_time_sync(buf);
    add_to_telecommand_buf(buf, len);
    add_to_backup_buf(buf, len);
  }
  if (protocol.is_set(FLAG_HANDSHAKE)) {
    len = protocol.build_return_handshake(buf);
    add_to_telecommand_buf(buf, len);
    add_to_backup_buf(buf, len); 
  }
  protocol.clear_flags();
}

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

void loop() {
  updateGps();
  handleCAN();
  handleTelecommand();

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
      uint8_t buf[20], len;
      uint32_t gnss_time = 0;
      int32_t latitude, longitude = 0; 
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
      len = protocol.build_GNSS_data(buf, gnss_time, latitude, longitude, h_dop, n_satellites);
      add_to_telecommand_buf(buf, len);
    }

    //empty all buffers
    if (telemetry_index > LEN_CURRENT_TIME_MSG) {
      protocol.build_current_time(telemetry_buf, clock.get_current_time());
      if (telemetry_enabled) {
        Serial2.write(telemetry_buf, telemetry_index);
      }
      telemetry_index = LEN_CURRENT_TIME_MSG;;
    }
    if (backup_index > LEN_CURRENT_TIME_MSG) {
      protocol.build_current_time(backup_buf, clock.get_current_time());
      if (data_logging_enabled) {
        file.write(backup_buf, backup_index);
      }
      backup_index = LEN_CURRENT_TIME_MSG;
    }
    if (telecommand_index > 0) {
      //rfm.send(telecommand_buf, telecommand_index);
      Serial.write(telecommand_buf, telecommand_index);
      telecommand_index = 0;
    }
  }
}