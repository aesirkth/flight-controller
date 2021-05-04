#include <Arduino.h>
#include <FlexCAN.h>  //https://github.com/pawelsky/FlexCAN_Library
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <stdio.h>
#include <map>

#include "MS5611.h"
#include "DmaSpi.h"
#include "SdFat.h"
#include "RH_RF95.h"  //THIS IS A MODIFIED LIBRARY WITHOUT ERROR CHECKING 
#include "RHHardwareSPI1.h"
#include "hardware_definition_teensy.h"
#include "Gps.h"
#include "DataProtocol.h"
#include "fc.h"
#include "FlashMemory.hpp"
#include "ChipSelect.h"

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

struct default_uint8 {
  uint8_t val = 1;
};

std::map<uint8_t, struct default_uint8> can_relay_frequency;
std::map<uint8_t, uint8_t> can_message_count;

Flash flash(&SPI1, settingsFlash, PIN_CS_FLASH, PIN_WP, PIN_HOLD); // flash chip
MS5611 ms1(PIN_CS_MS1, SPI); // pressure sensor
IntervalTimer para1_timer; // timer for parachute 1
IntervalTimer para2_timer; // timer for parachute 1
DataProtocol protocol; // data protocol reader
static CAN_message_t can_msg; // msg for the can bus
FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX
GPS gps1; // for gps on Serial1
GPS gps2; // for gps on Serial3
GPS* best_gps; // stores the best gps
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1); // LoRa modem
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400); // led lights
SdFs SD; // SD card handler
FsFile live_file; // sd file that should be written to in real time
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
  ms1.begin(); 
  ms1.setOSR(0); 
  delay(100);
}

void setup() {
  initPins();

  uint8_t buf[2048];
  for (uint16_t i = 0; i < 2048; i++) {
    buf[i] = (uint8_t) i;
  }
  DMASPI1.begin();
  DMASPI1.start();
  Serial.begin(115200); 
  flash.begin();

  while (!Serial){}
  flash.checkFactoryBadBlocks();
  //flash.readBadBlockLUT();
}

void loop() {
  uint32_t before = micros(); 
  ms1.updateAsync();
  uint32_t after = micros(); 
  Serial.println("--------");
  Serial.printf("Timediff:\t%d\tms\n",(after - before)/1000); 
  Serial.printf("Pressure:\t%d \tmBar\nTemperature:\t%d\tC\n", ms1.pressure/100, ms1.temperature/100);
  Serial.println("--------");
}