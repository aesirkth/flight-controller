/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#include "protocol_enums.h"
#include <stdint.h>

struct __attribute__((packed)) struct_time_sync {
  uint32_t system_time;
};
struct __attribute__((packed)) struct_set_power_mode {};
struct __attribute__((packed)) struct_set_radio_equipment {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_set_parachute_output {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_set_data_logging {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_dump_flash_chip {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_handshake {};
struct __attribute__((packed)) struct_return_time_sync {};
struct __attribute__((packed)) struct_return_radio_equipment {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_return_parachute_output {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_onboard_battery_voltage {
  uint16_t battery_1;
  uint16_t battery_2;
};
struct __attribute__((packed)) struct_gnss_data {
  uint32_t gnss_time;
  int32_t latitude;
  int32_t longitude;
  uint16_t h_dop;
  uint8_t n_satellites;
};
struct __attribute__((packed)) struct_flight_controller_status {
  uint8_t HW_state;
  uint8_t SW_state;
  uint8_t mission_state;
};
struct __attribute__((packed)) struct_return_data_logging {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_return_dump_flash {
  uint8_t bitField;
};
struct __attribute__((packed)) struct_return_handshake {};
