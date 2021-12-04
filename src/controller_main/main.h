#include <stdint.h>
#include <WS2812Serial.h>

#include "MS5611.h"
#include "SdFat.h" // read and write from the sd-card
#include "RH_RF95.h" // LoRa radio, modified to skip some error checking 
#include "RHHardwareSPI1.h" // headers for SPI1 and radiohead
#include "hardware_definition_main.h" // pin definitions
#include "Gps.h" // GPS
#include "DataProtocol.h" // to extract and find data in a stream
#include "fc.h" // to decode and encode data
#include "FlashMemory.hpp" // read and write to the flash chip, hard coded to use SPI1
#include "FlexCAN_T4.h"
#include "Sampler.h"
#include "RandomBuffer.h"

#define DUMPED_FILE_NAME "DATA"

#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010

void showError();
void showOk();
void showNeutral();

extern RandomBuffer telemetry_queue;
extern RandomBuffer flash_queue;
extern RandomBuffer lora_queue;

extern Sampler sampler;
extern GPS gps1; // for gps on Serial1
extern GPS gps2; // for gps on Serial3
extern Flash flash; // flash chip
extern IntervalTimer para1_timer; // timer for parachute 1
extern IntervalTimer para2_timer; // timer for parachute 1
extern FlexCAN_T4<CAN2, RX_SIZE_16, TX_SIZE_16> can;  // 1Mbs, CAN0, pins 29&30 for TX&RX
extern GPS* best_gps; // stores the best gps
extern RH_RF95 rfm; // LoRa modem
extern WS2812Serial strip;
extern SdFs SD; // SD card handler
extern bool error;
extern bool parachute_armed;
extern bool data_logging_enabled;
extern bool telemetry_enabled;
extern bool telecommand_enabled;
extern bool FPV_enabled;
extern bool gps_led_on;
extern bool rfm_init_success;
extern FsFile file;