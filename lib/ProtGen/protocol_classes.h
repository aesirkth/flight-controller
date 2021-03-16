/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#include "protocol_functions.h"
#include "protocol_structs.h"
class ground_station_time_sync {
public:
  struct struct_time_sync *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 16;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) { storage = (struct_time_sync *)pointer; }

  uint32_t get_system_time() { return storage->system_time; }
  void set_system_time(uint32_t value) { storage->system_time = value; }
};

class ground_station_set_power_mode {
public:
  struct struct_set_power_mode *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 17;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_set_power_mode *)pointer;
  }
};

class ground_station_set_radio_equipment {
public:
  struct struct_set_radio_equipment *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 18;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_set_radio_equipment *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class ground_station_set_parachute_output {
public:
  struct struct_set_parachute_output *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 19;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_set_parachute_output *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class ground_station_set_data_logging {
public:
  struct struct_set_data_logging *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 20;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_set_data_logging *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class ground_station_dump_flash_chip {
public:
  struct struct_dump_flash_chip *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 21;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_dump_flash_chip *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class ground_station_handshake {
public:
  struct struct_handshake *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 22;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) { storage = (struct_handshake *)pointer; }
};

class ground_station_return_time_sync {
public:
  struct struct_return_time_sync *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 32;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_return_time_sync *)pointer;
  }
};

class flight_controller_return_radio_equipment {
public:
  struct struct_return_radio_equipment *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 33;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_return_radio_equipment *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class flight_controller_return_parachute_output {
public:
  struct struct_return_parachute_output *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 34;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_return_parachute_output *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class flight_controller_onboard_battery_voltage {
public:
  struct struct_onboard_battery_voltage *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 35;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_onboard_battery_voltage *)pointer;
  }

  uint16_t get_battery_1() { return storage->battery_1; }
  void set_battery_1(uint16_t value) { storage->battery_1 = value; }

  uint16_t get_battery_2() { return storage->battery_2; }
  void set_battery_2(uint16_t value) { storage->battery_2 = value; }
};

class flight_controller_gnss_data {
public:
  struct struct_gnss_data *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 36;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) { storage = (struct_gnss_data *)pointer; }

  uint32_t get_gnss_time() { return storage->gnss_time; }
  void set_gnss_time(uint32_t value) { storage->gnss_time = value; }

  int32_t get_latitude() { return storage->latitude; }
  void set_latitude(int32_t value) { storage->latitude = value; }

  int32_t get_longitude() { return storage->longitude; }
  void set_longitude(int32_t value) { storage->longitude = value; }

  double get_h_dop() {
    double out;
    uint_to_scaledFloat(storage->h_dop, 100, &out);
    return out;
  }
  void set_h_dop(double value) {
    scaledFloat_to_uint(value, 100, &storage->h_dop);
  }

  uint8_t get_n_satellites() { return storage->n_satellites; }
  void set_n_satellites(uint8_t value) { storage->n_satellites = value; }
};

class flight_controller_flight_controller_status {
public:
  struct struct_flight_controller_status *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 37;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_flight_controller_status *)pointer;
  }

  uint8_t get_HW_state() { return storage->HW_state; }
  void set_HW_state(uint8_t value) { storage->HW_state = value; }

  uint8_t get_SW_state() { return storage->SW_state; }
  void set_SW_state(uint8_t value) { storage->SW_state = value; }

  uint8_t get_mission_state() { return storage->mission_state; }
  void set_mission_state(uint8_t value) { storage->mission_state = value; }
};

class flight_controller_return_data_logging {
public:
  struct struct_return_data_logging *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 38;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_return_data_logging *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class flight_controller_return_dump_flash {
public:
  struct struct_return_dump_flash *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 39;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_return_dump_flash *)pointer;
  }
  uint8_t get_bitfield() { return storage->bitField; }
};

class flight_controller_return_handshake {
public:
  struct struct_return_handshake *storage;
  uint8_t size = sizeof(*storage);
  uint64_t id = 40;
  uint8_t get_size() { return size; }
  void set_bytes(uint8_t *pointer) {
    storage = (struct_return_handshake *)pointer;
  }
};
