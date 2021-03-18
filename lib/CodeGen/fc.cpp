/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#include "fc.h"
#include <stdint.h>

uint8_t fc::id_to_len(size_t id) {
  switch (id) {
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
  case 80:
    return 4;
    break;
  }
}

enum fc::units fc::id_to_source(size_t id) {
  switch (id) {
  case 16:
    return units::ground_station;
    break;
  case 17:
    return units::ground_station;
    break;
  case 18:
    return units::ground_station;
    break;
  case 19:
    return units::ground_station;
    break;
  case 20:
    return units::ground_station;
    break;
  case 21:
    return units::ground_station;
    break;
  case 22:
    return units::ground_station;
    break;
  case 32:
    return units::flight_controller;
    break;
  case 33:
    return units::flight_controller;
    break;
  case 34:
    return units::flight_controller;
    break;
  case 35:
    return units::flight_controller;
    break;
  case 36:
    return units::flight_controller;
    break;
  case 37:
    return units::flight_controller;
    break;
  case 38:
    return units::flight_controller;
    break;
  case 39:
    return units::flight_controller;
    break;
  case 40:
    return units::flight_controller;
    break;
  case 41:
    return units::flight_controller;
    break;
  case 80:
    return units::flight_controller;
    break;
  }
}

enum fc::units fc::id_to_target(size_t id) {
  switch (id) {
  case 16:
    return units::flight_controller_tc;
    break;
  case 17:
    return units::flight_controller_tc;
    break;
  case 18:
    return units::flight_controller_tc;
    break;
  case 19:
    return units::flight_controller_tc;
    break;
  case 20:
    return units::flight_controller_tc;
    break;
  case 21:
    return units::flight_controller_tc;
    break;
  case 22:
    return units::flight_controller_tc;
    break;
  case 32:
    return units::ground_station_tc;
    break;
  case 33:
    return units::ground_station_tc;
    break;
  case 34:
    return units::ground_station_tc;
    break;
  case 35:
    return units::ground_station_tc;
    break;
  case 36:
    return units::ground_station_tc;
    break;
  case 37:
    return units::ground_station_tc;
    break;
  case 38:
    return units::ground_station_tc;
    break;
  case 39:
    return units::ground_station_tc;
    break;
  case 40:
    return units::ground_station_tc;
    break;
  case 41:
    return units::ground_station_tc;
    break;
  case 80:
    return units::ground_station_tm;
    break;
  }
}
