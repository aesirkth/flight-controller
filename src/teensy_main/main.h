#include <stdint.h>
#include <Adafruit_NeoPixel.h>

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

void add_to_telecommand_buf(uint8_t* buf, uint8_t len);
void add_to_telemetry_buf(uint8_t* buf, uint8_t len);
void add_to_backup_buf(uint8_t* buf, uint8_t len);
void showError();
void showOk();
void showNeutral();

extern GPS gps1; // for gps on Serial1
extern GPS gps2; // for gps on Serial3
extern Flash flash; // flash chip
extern MS5611 ms1; // pressure sensor
extern MS5611 ms2; // pressure sensor
extern IntervalTimer para1_timer; // timer for parachute 1
extern IntervalTimer para2_timer; // timer for parachute 1
extern DataProtocol protocol; // data protocol reader
extern FlexCAN CANbus;  // 1Mbs, CAN0, pins 29&30 for TX&RX
extern GPS* best_gps; // stores the best gps
extern RH_RF95 rfm; // LoRa modem
extern Adafruit_NeoPixel strip;
extern SdFs SD; // SD card handler
extern bool error;
extern bool parachute_armed;
extern bool data_logging_enabled;
extern bool telemetry_enabled;
extern bool telecommand_enabled;
extern bool FPV_enabled;
extern bool gps_led_on;
extern bool rfm_init_success;