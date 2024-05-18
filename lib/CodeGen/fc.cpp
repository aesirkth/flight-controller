/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#include "fc.h"
#include <stdint.h>

namespace fc {
__attribute__((weak)) void
rx(ms_since_boot_from_flight_controller_to_ground_station msg) {}
__attribute__((weak)) void
rx(ms_since_boot_from_flight_controller_to_ground_station msg, void *misc) {}
__attribute__((weak)) void
rx(handshake_from_ground_station_to_flight_controller msg) {}
__attribute__((weak)) void
rx(handshake_from_ground_station_to_flight_controller msg, void *misc) {}
__attribute__((weak)) void
rx(return_handshake_from_flight_controller_to_ground_station msg) {}
__attribute__((weak)) void
rx(return_handshake_from_flight_controller_to_ground_station msg, void *misc) {}
void parse_message(uint8_t id, uint8_t *buf) {
  switch (id) {
  case 253: {
    ms_since_boot_from_flight_controller_to_ground_station __message;
    __message.parse_buf(buf);
    rx(__message);
    break;
  }
  case 254: {
    handshake_from_ground_station_to_flight_controller __message;
    __message.parse_buf(buf);
    rx(__message);
    break;
  }
  case 255: {
    return_handshake_from_flight_controller_to_ground_station __message;
    __message.parse_buf(buf);
    rx(__message);
    break;
  }
  }
}

void parse_message(uint8_t id, uint8_t *buf, void *misc) {
  switch (id) {
  case 253: {
    ms_since_boot_from_flight_controller_to_ground_station __message;
    __message.parse_buf(buf);
    rx(__message, misc);
    break;
  }
  case 254: {
    handshake_from_ground_station_to_flight_controller __message;
    __message.parse_buf(buf);
    rx(__message, misc);
    break;
  }
  case 255: {
    return_handshake_from_flight_controller_to_ground_station __message;
    __message.parse_buf(buf);
    rx(__message, misc);
    break;
  }
  }
}

bool is_valid_id(uint8_t id) {
  switch (id) {
  case 253:
    return true;
    break;
  case 254:
    return true;
    break;
  case 255:
    return true;
    break;
  default:
    return false;
  }
}

uint8_t id_to_len(uint8_t id) {
  switch (id) {
  case 253:
    return 4;
    break;
  case 254:
    return 0;
    break;
  case 255:
    return 0;
    break;
  default:
    return 0;
  }
}

enum nodes id_to_sender(uint8_t id) {
  switch (id) {
  case 253:
    return nodes::flight_controller;
    break;
  case 254:
    return nodes::ground_station;
    break;
  case 255:
    return nodes::flight_controller;
    break;
  }
}

enum nodes id_to_receiver(uint8_t id) {
  switch (id) {
  case 253:
    return nodes::ground_station;
    break;
  case 254:
    return nodes::flight_controller;
    break;
  case 255:
    return nodes::ground_station;
    break;
  }
}

enum categories id_to_category(uint8_t id) {
  switch (id) {
  case 253:
    return categories::none;
    break;
  case 254:
    return categories::none;
    break;
  case 255:
    return categories::none;
    break;
  }
}

} // namespace fc