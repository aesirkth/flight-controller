/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#include "fc.h"
#include <stdint.h>

bool fc::is_valid_id(uint8_t id) {
  switch (id) {
  case 0:
    return true;
    break;
  case 1:
    return true;
    break;
  case 2:
    return true;
    break;
  case 3:
    return true;
    break;
  case 4:
    return true;
    break;
  case 16:
    return true;
    break;
  case 17:
    return true;
    break;
  case 18:
    return true;
    break;
  case 19:
    return true;
    break;
  case 20:
    return true;
    break;
  case 21:
    return true;
    break;
  case 22:
    return true;
    break;
  case 32:
    return true;
    break;
  case 33:
    return true;
    break;
  case 34:
    return true;
    break;
  case 35:
    return true;
    break;
  case 36:
    return true;
    break;
  case 37:
    return true;
    break;
  case 38:
    return true;
    break;
  case 39:
    return true;
    break;
  case 40:
    return true;
    break;
  case 41:
    return true;
    break;
  case 64:
    return true;
    break;
  case 80:
    return true;
    break;
  case 81:
    return true;
    break;
  case 82:
    return true;
    break;
  case 83:
    return true;
    break;
  case 84:
    return true;
    break;
  case 85:
    return true;
    break;
  case 86:
    return true;
    break;
  case 87:
    return true;
    break;
  case 88:
    return true;
    break;
  case 255:
    return true;
    break;
  default:
    return false;
  }
}

uint8_t fc::id_to_len(uint8_t id) {
  switch (id) {
  case 0:
    return 2;
    break;
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  case 3:
    return 1;
    break;
  case 4:
    return 3;
    break;
  case 16:
    return 4;
    break;
  case 17:
    return 0;
    break;
  case 18:
    return 1;
    break;
  case 19:
    return 1;
    break;
  case 20:
    return 1;
    break;
  case 21:
    return 1;
    break;
  case 22:
    return 0;
    break;
  case 32:
    return 0;
    break;
  case 33:
    return 0;
    break;
  case 34:
    return 1;
    break;
  case 35:
    return 1;
    break;
  case 36:
    return 4;
    break;
  case 37:
    return 15;
    break;
  case 38:
    return 3;
    break;
  case 39:
    return 1;
    break;
  case 40:
    return 1;
    break;
  case 41:
    return 0;
    break;
  case 64:
    return 4;
    break;
  case 80:
    return 4;
    break;
  case 81:
    return 8;
    break;
  case 82:
    return 4;
    break;
  case 83:
    return 12;
    break;
  case 84:
    return 12;
    break;
  case 85:
    return 8;
    break;
  case 86:
    return 8;
    break;
  case 87:
    return 18;
    break;
  case 88:
    return 18;
    break;
  case 255:
    return 4;
    break;
  default:
    return 0;
  }
}

enum fc::units fc::id_to_source(uint8_t id) {
  switch (id) {
  case 0:
    return fc::units::test;
    break;
  case 1:
    return fc::units::test;
    break;
  case 2:
    return fc::units::test;
    break;
  case 3:
    return fc::units::test;
    break;
  case 4:
    return fc::units::test;
    break;
  case 16:
    return fc::units::ground_station;
    break;
  case 17:
    return fc::units::ground_station;
    break;
  case 18:
    return fc::units::ground_station;
    break;
  case 19:
    return fc::units::ground_station;
    break;
  case 20:
    return fc::units::ground_station;
    break;
  case 21:
    return fc::units::ground_station;
    break;
  case 22:
    return fc::units::ground_station;
    break;
  case 32:
    return fc::units::flight_controller;
    break;
  case 33:
    return fc::units::flight_controller;
    break;
  case 34:
    return fc::units::flight_controller;
    break;
  case 35:
    return fc::units::flight_controller;
    break;
  case 36:
    return fc::units::flight_controller;
    break;
  case 37:
    return fc::units::flight_controller;
    break;
  case 38:
    return fc::units::flight_controller;
    break;
  case 39:
    return fc::units::flight_controller;
    break;
  case 40:
    return fc::units::flight_controller;
    break;
  case 41:
    return fc::units::flight_controller;
    break;
  case 64:
    return fc::units::test;
    break;
  case 80:
    return fc::units::flight_controller;
    break;
  case 81:
    return fc::units::flight_controller;
    break;
  case 82:
    return fc::units::flight_controller;
    break;
  case 83:
    return fc::units::flight_controller;
    break;
  case 84:
    return fc::units::flight_controller;
    break;
  case 85:
    return fc::units::flight_controller;
    break;
  case 86:
    return fc::units::flight_controller;
    break;
  case 87:
    return fc::units::flight_controller;
    break;
  case 88:
    return fc::units::flight_controller;
    break;
  case 255:
    return fc::units::local;
    break;
  }
}

enum fc::units fc::id_to_target(uint8_t id) {
  switch (id) {
  case 0:
    return fc::units::test;
    break;
  case 1:
    return fc::units::test;
    break;
  case 2:
    return fc::units::test;
    break;
  case 3:
    return fc::units::test;
    break;
  case 4:
    return fc::units::test;
    break;
  case 16:
    return fc::units::flight_controller;
    break;
  case 17:
    return fc::units::flight_controller;
    break;
  case 18:
    return fc::units::flight_controller;
    break;
  case 19:
    return fc::units::flight_controller;
    break;
  case 20:
    return fc::units::flight_controller;
    break;
  case 21:
    return fc::units::flight_controller;
    break;
  case 22:
    return fc::units::flight_controller;
    break;
  case 32:
    return fc::units::ground_station;
    break;
  case 33:
    return fc::units::ground_station;
    break;
  case 34:
    return fc::units::ground_station;
    break;
  case 35:
    return fc::units::ground_station;
    break;
  case 36:
    return fc::units::ground_station;
    break;
  case 37:
    return fc::units::ground_station;
    break;
  case 38:
    return fc::units::ground_station;
    break;
  case 39:
    return fc::units::ground_station;
    break;
  case 40:
    return fc::units::ground_station;
    break;
  case 41:
    return fc::units::ground_station;
    break;
  case 64:
    return fc::units::test;
    break;
  case 80:
    return fc::units::ground_station;
    break;
  case 81:
    return fc::units::ground_station;
    break;
  case 82:
    return fc::units::ground_station;
    break;
  case 83:
    return fc::units::ground_station;
    break;
  case 84:
    return fc::units::ground_station;
    break;
  case 85:
    return fc::units::ground_station;
    break;
  case 86:
    return fc::units::ground_station;
    break;
  case 87:
    return fc::units::ground_station;
    break;
  case 88:
    return fc::units::ground_station;
    break;
  case 255:
    return fc::units::local;
    break;
  }
}
