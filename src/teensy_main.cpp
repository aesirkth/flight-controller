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
#include "FlashMemory.hpp"

#define LIVE_FILE_NAME "/LIVEDATA.BIN"
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

#define WT_PAGE_MSB 0x00
#define WT_PAGE_LSB 0x01

SPISettings settingsFlash(10000000, MSBFIRST, SPI_MODE0); // SPI bus settings to communicate with the Flash IC
Flash memory(&SPI1, settingsFlash, PIN_CS_FLASH, PIN_WP, PIN_HOLD);
uint8_t write_buffer[2048];
uint8_t read_buffer[2048];

uint8_t checkBusyFlash();
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
uint8_t telecommand_index = LEN_MS_SINCE_BOOT_MSG;
uint32_t gps_led_updated = 0;
uint64_t last_cycle_time = 0;
uint64_t cycle_count = 0;
bool error = false;
bool parachute_armed = false;
bool data_logging_enabled = false;
bool telemetry_enabled = true;
bool FPV_enabled = false;
bool gps_led_on = false;
bool rfm_init_success = 0;

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

  digitalWriteFast(PIN_RFD_DIS, LOW); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_FPV_DIS, LOW); //HIGH MEANS DISABLED
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
  /* Init radio communication and set frequency and power parameters */
  resetRadio();

  rfm_init_success = rfm.init();
  Serial.println(rfm_init_success);
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

void fc_rx(fc::set_data_logging msg) {
  data_logging_enabled = msg.get_is_logging_en();
  fc::return_data_logging_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc_rx(fc::handshake msg) {
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

//catch messages we don't care about
template <class T>
void fc_rx(T msg) {}

void DataProtocol_callback(uint64_t id, uint8_t* buf, uint8_t len) {
  uint8_t header_buf[HEADER_SIZE];
  uint8_t header_index = 0;
  protocol.build_header(id, header_buf, &header_index);
  add_to_backup_buf(header_buf, header_index); // add header
  add_to_backup_buf(buf, len); // add message
  // parse the message no matter what, nothing will happen if it's invalid
  FC_PARSE_MESSAGE(id, buf); 
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

void setup() {
  CANbus.begin();
  Serial.begin(115200);
  initRGB();
  initGps();
  initPins();
  initRadio();
  //initSD();
  //init telemetry
  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);
  Serial2.begin(TELEMETRY_BAUD);
  showOk();
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
      fc::gnss_data_from_flight_controller_to_ground_station tc_msg;
      fc::GNSS_data_1_from_flight_controller_to_ground_station tm_msg;
      uint8_t len = 0;
      uint8_t buf[50];
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
        live_file.write(backup_buf, backup_index);
      }
      backup_index = LEN_MS_SINCE_BOOT_MSG;
    }
    if (telecommand_index > LEN_MS_SINCE_BOOT_MSG && (cycle_count % LORA_SEND_CYCLE  == 0)) {
      uint8_t index = 0;
      fc::ms_since_boot_from_flight_controller_to_ground_station msg;
      msg.set_ms_since_boot(current_time);
      protocol.build_buf(msg, telecommand_buf, &index);
      rfm.send(telecommand_buf, telecommand_index);
      Serial.write(telecommand_buf, telecommand_index);
      telecommand_index = LEN_MS_SINCE_BOOT_MSG;
    }
  }

void setup()
{
    pinMode(PIN_RFM_NSS, OUTPUT);
    digitalWrite(PIN_RFM_NSS, HIGH);
    // Set Flash IC CS, WP, HOLD line to high (this should be done through pullup resistors)

    // Set I/O we don't care about at the moment
    pinMode(PIN_PARA1, OUTPUT);
    pinMode(PIN_PARA2, OUTPUT);
    digitalWrite(PIN_PARA1, LOW);  // LOW means inactive parachute
    digitalWrite(PIN_PARA2, LOW);  // LOW means inactive parachute
    pinMode(PIN_J2_DIS, OUTPUT);
    pinMode(PIN_J4_DIS, OUTPUT);
    digitalWrite(PIN_J2_DIS, LOW);  // LOW means active Telemetry output
    digitalWrite(PIN_J4_DIS, LOW);

    uint8_t count = 0;
    for (int i = 0; i < 2048; i++)
    {
        read_buffer[i] = 0;
        write_buffer[i] = count;
        count++;
        //count--;
    }
    

    delay(3000); //Make sure everything had time to initialize after power up

    SPI1.begin(); // Initialize the SPI bus for the Flash IC
    Serial.begin(57600); // Open Serial port with the PC
/*    for (int i = 0; i < 200; i++)
    {
    Serial.print(write_buffer[i]);
    Serial.print(",");
    }*/
    Serial.println("\nINIT");
}

void loop()
{
    if (memory.test() == RET_SUCCESS)
    {
        Serial.println("JEDEC ID match");
    }
    else
    {
        Serial.println("JEDEC don't match ERROR");
    }

    //memory.checkFactoryBadBlocks();
    //memory.readBadBlockLUT();


    uint8_t reg_val = 0;
    memory.readStatusRegister(SR_1_ADDR, &reg_val);
    Serial.print("SR-1: ");
    Serial.println(reg_val, BIN);

    memory.writeStatusRegister(SR_1_ADDR, 0x00);

    memory.readStatusRegister(SR_1_ADDR, &reg_val);
    Serial.print("SR-1: ");
    Serial.println(reg_val, BIN);

    testFlashMemory(&memory);

/*
    uint8_t register_val = 0;
    SPI1.beginTransaction(settingsFlash);

    // Read Status Register SR-1
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xA0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-1: ");
    Serial.println(register_val, BIN);

    // Read Status Register SR-2
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xB0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-2: ");
    Serial.println(register_val, BIN);

    // Read Status Register SR-3
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xC0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-3: ");
    Serial.println(register_val, BIN);

    // Write Status Register SR-1 (Disable Block Protect Bits)
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x1F); // Read Status Register
    SPI1.transfer(0xA0); //Register address
    SPI1.transfer(0x00); // Reset all bits on the register
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Read Status Register SR-1
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xA0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-1: ");
    Serial.println(register_val, BIN);

    // Check Busy flag == 0
    while (checkBusyFlash())
    {
        delay (1);
    }

    // Read Device ID
    uint8_t temp = 0;
    uint8_t manu_id = 0;
    uint16_t ic_id = 0;
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x9F); // Read chip ID
    SPI1.transfer(0xFF); // Dummy
    temp = SPI1.transfer(0xFF); // Get Manufacturer ID
    manu_id = temp;
    temp = SPI1.transfer(0xFF); // Get Device ID 1/2
    ic_id = (uint16_t)temp << 8;
    temp = SPI1.transfer(0xFF); // Get Device ID 2/2
    ic_id |= (uint16_t)temp;
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Print IC info
    Serial.print("Manufacturer ID: ");
    Serial.println(manu_id, HEX);
    Serial.print("Device ID: ");
    Serial.println(ic_id, HEX);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}

uint32_t time_dif = 0;
// Read data from the memory
    time_dif = micros();
    // Load page data into buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x13); // Page Data Read
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    // Page Address (16 bits)
    SPI1.transfer(WT_PAGE_MSB);
    SPI1.transfer(WT_PAGE_LSB);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Page Data Read => ");
    Serial.print(time_dif);
    Serial.println(" us");

    time_dif = micros();
    // Read memory buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x03); // Read Data
    SPI1.transfer(0x00); // Column Address (16-bit)
    SPI1.transfer(0x00);
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    for (int i = 0; i < 2048; i++)
    {
        read_buffer[i] = SPI1.transfer(0xFF); // Read 1 byte of data
    }
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Read Data (2048 Bytes) => ");
    Serial.print(time_dif);
    Serial.println(" us");

// Read data from the memory
Serial.println("READ DATA");
for (int i = 0; i < 200; i++)
{
    Serial.print(read_buffer[i]);
    Serial.print(",");
}
Serial.println("\nREAD DATA \n");

// Write data to the memory
    // Write enable
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x06);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Read Status Register SR-3
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xC0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-3: ");
    Serial.println(register_val, BIN);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}

    time_dif = micros();
    // Load data into buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x02); // Load Program Data
    SPI1.transfer(0x00); // Column Address (16-bit)
    SPI1.transfer(0x00);
    for (int i = 0; i < 2048; i++)
    {
        SPI1.transfer(write_buffer[i]); // Transfer 1 byte of data
    }
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Load Program Data (2048 Bytes) => ");
    Serial.print(time_dif);
    Serial.println(" us");

    time_dif = micros();
    // Save buffer into memory
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x10); // Program Execute
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    // Page Address (16 bits)
    SPI1.transfer(WT_PAGE_MSB);
    SPI1.transfer(WT_PAGE_LSB);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Program Execute => ");
    Serial.print(time_dif);
    Serial.println(" us");
// Write data to the memory

// Read data from the memory
    time_dif = micros();
    // Load page data into buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x13); // Page Data Read
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    // Page Address (16 bits)
    SPI1.transfer(WT_PAGE_MSB);
    SPI1.transfer(WT_PAGE_LSB);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Page Data Read => ");
    Serial.print(time_dif);
    Serial.println(" us");

    time_dif = micros();
    // Read memory buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x03); // Read Data
    SPI1.transfer(0x00); // Column Address (16-bit)
    SPI1.transfer(0x00);
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    for (int i = 0; i < 2048; i++)
    {
        read_buffer[i] = SPI1.transfer(0xFF); // Read 1 byte of data
    }
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Read Data (2048 Bytes) => ");
    Serial.print(time_dif);
    Serial.println(" us");

// Read data from the memory
Serial.println("READ DATA");
for (int i = 0; i < 200; i++)
{
    Serial.print(read_buffer[i]);
    Serial.print(",");
}
Serial.println("\nREAD DATA \n");
*/
    while(1)
    {
        delay(1000);
        Serial.print(".");
    }

}