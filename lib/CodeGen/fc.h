/*****************************
GENERATED FILE DO NOT EDIT
******************************/

// pick if you want to use floats or doubles
#define fc_FLOAT_DEF float

#include <math.h>
#include <stdint.h>
#include <string.h>

namespace fc {
enum struct fix_status : uint8_t {
  no_fix = 0,
  fix_2D = 1,
  fix_3D = 2,
};
enum struct nodes : uint8_t {
  local = 0,
  test = 1,
  ground_station = 2,
  flight_controller = 3,
};
enum struct fields : uint8_t {
  timestamp = 0,
  ms_since_boot = 1,
  altitude = 2,
  catastrophe = 3,
  x = 4,
  y = 5,
  z = 6,
  system_time = 7,
  is_fpv_en = 8,
  is_tm_en = 9,
  is_parachute_armed = 10,
  is_parachute1_en = 11,
  is_parachute2_en = 12,
  is_logging_en = 13,
  dump_sd = 14,
  dump_usb = 15,
  battery_1 = 16,
  battery_2 = 17,
  gnss_time = 18,
  latitude = 19,
  longitude = 20,
  h_dop = 21,
  n_satellites = 22,
  HW_state = 23,
  SW_state = 24,
  mission_state = 25,
  us_since_boot = 26,
  current_time = 27,
  heading = 28,
  horiz_speed = 29,
  fix_status = 30,
  temperature_1 = 31,
  temperature_2 = 32,
  pressure_1 = 33,
  pressure_2 = 34,
  accel_x = 35,
  accel_y = 36,
  accel_z = 37,
  gyro_x = 38,
  gyro_y = 39,
  gyro_z = 40,
  magnet_x = 41,
  magnet_y = 42,
  magnet_z = 43,
};
enum struct messages : uint8_t {
  local_timestamp = 0,
  ms_since_boot = 1,
  altitude = 2,
  acceleration = 3,
  pressure = 4,
  catastrophe = 5,
  gyro = 6,
  time_sync = 7,
  set_power_mode = 8,
  set_radio_equipment = 9,
  set_parachute_output = 10,
  set_data_logging = 11,
  dump_flash = 12,
  handshake = 13,
  return_time_sync = 14,
  return_power_mode = 15,
  return_radio_equipment = 16,
  return_parachute_output = 17,
  onboard_battery_voltage = 18,
  gnss_data = 19,
  flight_controller_status = 20,
  return_data_logging = 21,
  return_dump_flash = 22,
  return_handshake = 23,
  us_since_boot = 24,
  current_time = 25,
  GNSS_data_1 = 26,
  GNSS_data_2 = 27,
  inside_static_temperature = 28,
  inside_static_pressure = 29,
  IMU1 = 30,
  IMU2 = 31,
};
enum struct categories : uint8_t {
  none = 0,
};
template <typename T>
void scaledFloat_to_uint(fc_FLOAT_DEF value, fc_FLOAT_DEF scale, T *out) {
  *out = value * scale;
}

template <typename T>
void uint_to_scaledFloat(T value, fc_FLOAT_DEF scale, fc_FLOAT_DEF *out) {
  *out = value / scale;
}

template <typename T>
void packedFloat_to_uint(fc_FLOAT_DEF value, fc_FLOAT_DEF minValue,
                         fc_FLOAT_DEF maxValue, T *out) {
  T intMax = ~0;
  if (value < minValue) {
    *out = 0;
    return;
  }
  if (value > maxValue) {
    *out = intMax;
    return;
  }
  fc_FLOAT_DEF ratio = (value - minValue) / (maxValue - minValue);
  *out = 1 + ((intMax - 2)) * ratio;
}

template <typename T>
void uint_to_packedFloat(T value, fc_FLOAT_DEF minValue, fc_FLOAT_DEF maxValue,
                         fc_FLOAT_DEF *out) {
  T intMax = ~0;
  if (value <= 0) {
    *out = minValue - 1.0;
    return;
  }
  if (value >= intMax) {
    *out = maxValue + 1.0;
    return;
  }
  fc_FLOAT_DEF ratio = (value - 1) / (intMax - 2);
  *out = ratio * (maxValue - minValue) + minValue;
}

class local_timestamp_from_local_to_local {
public:
  uint32_t timestamp;
  static_assert((sizeof(timestamp) == 4), "invalid size");
  uint8_t size = 4;
  enum messages message = messages::local_timestamp;
  enum nodes sender = nodes::local;
  enum nodes receiver = nodes::local;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 255;
  uint8_t get_id() { return id; }
  void set_timestamp(uint32_t value) { timestamp = value; }
  uint32_t get_timestamp() { return timestamp; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &timestamp, sizeof(timestamp));
    *index += sizeof(timestamp);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&timestamp, buf + index, sizeof(timestamp));
    index += sizeof(timestamp);
  }
};

class ms_since_boot_from_test_to_test {
public:
  uint32_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  enum messages message = messages::ms_since_boot;
  enum nodes sender = nodes::test;
  enum nodes receiver = nodes::test;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 64;
  uint8_t get_id() { return id; }
  void set_ms_since_boot(uint32_t value) { ms_since_boot = value; }
  uint32_t get_ms_since_boot() { return ms_since_boot; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &ms_since_boot, sizeof(ms_since_boot));
    *index += sizeof(ms_since_boot);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&ms_since_boot, buf + index, sizeof(ms_since_boot));
    index += sizeof(ms_since_boot);
  }
};

class altitude_from_test_to_test {
public:
  uint16_t altitude;
  static_assert((sizeof(altitude) == 2), "invalid size");
  uint8_t size = 2;
  enum messages message = messages::altitude;
  enum nodes sender = nodes::test;
  enum nodes receiver = nodes::test;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 0;
  uint8_t get_id() { return id; }
  void set_altitude(uint16_t value) { altitude = value; }
  uint16_t get_altitude() { return altitude; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &altitude, sizeof(altitude));
    *index += sizeof(altitude);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&altitude, buf + index, sizeof(altitude));
    index += sizeof(altitude);
  }
};

class acceleration_from_test_to_test {
public:
  uint8_t altitude;
  static_assert((sizeof(altitude) == 1), "invalid size");
  uint8_t size = 1;
  enum messages message = messages::acceleration;
  enum nodes sender = nodes::test;
  enum nodes receiver = nodes::test;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 1;
  uint8_t get_id() { return id; }
  void set_altitude(uint8_t value) { altitude = value; }
  uint8_t get_altitude() { return altitude; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &altitude, sizeof(altitude));
    *index += sizeof(altitude);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&altitude, buf + index, sizeof(altitude));
    index += sizeof(altitude);
  }
};

class pressure_from_test_to_test {
public:
  uint16_t altitude;
  static_assert((sizeof(altitude) == 2), "invalid size");
  uint8_t size = 2;
  enum messages message = messages::pressure;
  enum nodes sender = nodes::test;
  enum nodes receiver = nodes::test;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 2;
  uint8_t get_id() { return id; }
  void set_altitude(uint16_t value) { altitude = value; }
  uint16_t get_altitude() { return altitude; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &altitude, sizeof(altitude));
    *index += sizeof(altitude);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&altitude, buf + index, sizeof(altitude));
    index += sizeof(altitude);
  }
};

class catastrophe_from_test_to_test {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_catastrophe(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_catastrophe() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  enum messages message = messages::catastrophe;
  enum nodes sender = nodes::test;
  enum nodes receiver = nodes::test;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 3;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class gyro_from_test_to_test {
public:
  uint8_t x;
  static_assert((sizeof(x) == 1), "invalid size");
  uint8_t y;
  static_assert((sizeof(y) == 1), "invalid size");
  uint8_t z;
  static_assert((sizeof(z) == 1), "invalid size");
  uint8_t size = 3;
  enum messages message = messages::gyro;
  enum nodes sender = nodes::test;
  enum nodes receiver = nodes::test;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 4;
  uint8_t get_id() { return id; }
  void set_x(uint8_t value) { x = value; }
  void set_y(uint8_t value) { y = value; }
  void set_z(uint8_t value) { z = value; }
  uint8_t get_x() { return x; }
  uint8_t get_y() { return y; }
  uint8_t get_z() { return z; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &x, sizeof(x));
    *index += sizeof(x);
    memcpy(buf + *index, &y, sizeof(y));
    *index += sizeof(y);
    memcpy(buf + *index, &z, sizeof(z));
    *index += sizeof(z);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&x, buf + index, sizeof(x));
    index += sizeof(x);
    memcpy(&y, buf + index, sizeof(y));
    index += sizeof(y);
    memcpy(&z, buf + index, sizeof(z));
    index += sizeof(z);
  }
};

class time_sync_from_ground_station_to_flight_controller {
public:
  uint32_t system_time;
  static_assert((sizeof(system_time) == 4), "invalid size");
  uint8_t size = 4;
  enum messages message = messages::time_sync;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 16;
  uint8_t get_id() { return id; }
  void set_system_time(uint32_t value) { system_time = value; }
  uint32_t get_system_time() { return system_time; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &system_time, sizeof(system_time));
    *index += sizeof(system_time);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&system_time, buf + index, sizeof(system_time));
    index += sizeof(system_time);
  }
};

class set_power_mode_from_ground_station_to_flight_controller {
public:
  uint8_t size = 0;
  enum messages message = messages::set_power_mode;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 17;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
  void parse_buf(uint8_t *buf) {}
};

class set_radio_equipment_from_ground_station_to_flight_controller {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_fpv_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_fpv_en() { return bit_field & (1 << 0); }
  void set_is_tm_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  bool get_is_tm_en() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  enum messages message = messages::set_radio_equipment;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 18;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class set_parachute_output_from_ground_station_to_flight_controller {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_parachute_armed(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_parachute_armed() { return bit_field & (1 << 0); }
  void set_is_parachute1_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  bool get_is_parachute1_en() { return bit_field & (1 << 1); }
  void set_is_parachute2_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 2)) + !value * (bit_field & ~(1 << 2));
  }
  bool get_is_parachute2_en() { return bit_field & (1 << 2); }
  uint8_t size = 1;
  enum messages message = messages::set_parachute_output;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 19;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class set_data_logging_from_ground_station_to_flight_controller {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_logging_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_logging_en() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  enum messages message = messages::set_data_logging;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 20;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class dump_flash_from_ground_station_to_flight_controller {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_dump_sd(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_dump_sd() { return bit_field & (1 << 0); }
  void set_dump_usb(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  bool get_dump_usb() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  enum messages message = messages::dump_flash;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 21;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class handshake_from_ground_station_to_flight_controller {
public:
  uint8_t size = 0;
  enum messages message = messages::handshake;
  enum nodes sender = nodes::ground_station;
  enum nodes receiver = nodes::flight_controller;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 22;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
  void parse_buf(uint8_t *buf) {}
};

class return_time_sync_from_flight_controller_to_ground_station {
public:
  uint8_t size = 0;
  enum messages message = messages::return_time_sync;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 32;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
  void parse_buf(uint8_t *buf) {}
};

class return_power_mode_from_flight_controller_to_ground_station {
public:
  uint8_t size = 0;
  enum messages message = messages::return_power_mode;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 33;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
  void parse_buf(uint8_t *buf) {}
};

class return_radio_equipment_from_flight_controller_to_ground_station {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_fpv_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_fpv_en() { return bit_field & (1 << 0); }
  void set_is_tm_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  bool get_is_tm_en() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  enum messages message = messages::return_radio_equipment;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 34;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_parachute_output_from_flight_controller_to_ground_station {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_parachute_armed(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_parachute_armed() { return bit_field & (1 << 0); }
  void set_is_parachute1_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  bool get_is_parachute1_en() { return bit_field & (1 << 1); }
  void set_is_parachute2_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 2)) + !value * (bit_field & ~(1 << 2));
  }
  bool get_is_parachute2_en() { return bit_field & (1 << 2); }
  uint8_t size = 1;
  enum messages message = messages::return_parachute_output;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 35;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class onboard_battery_voltage_from_flight_controller_to_ground_station {
public:
  uint16_t battery_1;
  static_assert((sizeof(battery_1) == 2), "invalid size");
  uint16_t battery_2;
  static_assert((sizeof(battery_2) == 2), "invalid size");
  uint8_t size = 4;
  enum messages message = messages::onboard_battery_voltage;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 36;
  uint8_t get_id() { return id; }
  void set_battery_1(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &battery_1);
  }
  void set_battery_2(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &battery_2);
  }
  fc_FLOAT_DEF get_battery_1() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(battery_1, 100, &out);
    return out;
  }
  fc_FLOAT_DEF get_battery_2() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(battery_2, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &battery_1, sizeof(battery_1));
    *index += sizeof(battery_1);
    memcpy(buf + *index, &battery_2, sizeof(battery_2));
    *index += sizeof(battery_2);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&battery_1, buf + index, sizeof(battery_1));
    index += sizeof(battery_1);
    memcpy(&battery_2, buf + index, sizeof(battery_2));
    index += sizeof(battery_2);
  }
};

class gnss_data_from_flight_controller_to_ground_station {
public:
  uint32_t gnss_time;
  static_assert((sizeof(gnss_time) == 4), "invalid size");
  int32_t latitude;
  static_assert((sizeof(latitude) == 4), "invalid size");
  int32_t longitude;
  static_assert((sizeof(longitude) == 4), "invalid size");
  uint16_t h_dop;
  static_assert((sizeof(h_dop) == 2), "invalid size");
  uint8_t n_satellites;
  static_assert((sizeof(n_satellites) == 1), "invalid size");
  uint8_t size = 15;
  enum messages message = messages::gnss_data;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 37;
  uint8_t get_id() { return id; }
  void set_gnss_time(uint32_t value) { gnss_time = value; }
  void set_latitude(int32_t value) { latitude = value; }
  void set_longitude(int32_t value) { longitude = value; }
  void set_h_dop(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &h_dop);
  }
  void set_n_satellites(uint8_t value) { n_satellites = value; }
  uint32_t get_gnss_time() { return gnss_time; }
  int32_t get_latitude() { return latitude; }
  int32_t get_longitude() { return longitude; }
  fc_FLOAT_DEF get_h_dop() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(h_dop, 100, &out);
    return out;
  }
  uint8_t get_n_satellites() { return n_satellites; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &gnss_time, sizeof(gnss_time));
    *index += sizeof(gnss_time);
    memcpy(buf + *index, &latitude, sizeof(latitude));
    *index += sizeof(latitude);
    memcpy(buf + *index, &longitude, sizeof(longitude));
    *index += sizeof(longitude);
    memcpy(buf + *index, &h_dop, sizeof(h_dop));
    *index += sizeof(h_dop);
    memcpy(buf + *index, &n_satellites, sizeof(n_satellites));
    *index += sizeof(n_satellites);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&gnss_time, buf + index, sizeof(gnss_time));
    index += sizeof(gnss_time);
    memcpy(&latitude, buf + index, sizeof(latitude));
    index += sizeof(latitude);
    memcpy(&longitude, buf + index, sizeof(longitude));
    index += sizeof(longitude);
    memcpy(&h_dop, buf + index, sizeof(h_dop));
    index += sizeof(h_dop);
    memcpy(&n_satellites, buf + index, sizeof(n_satellites));
    index += sizeof(n_satellites);
  }
};

class flight_controller_status_from_flight_controller_to_ground_station {
public:
  uint8_t HW_state;
  static_assert((sizeof(HW_state) == 1), "invalid size");
  uint8_t SW_state;
  static_assert((sizeof(SW_state) == 1), "invalid size");
  uint8_t mission_state;
  static_assert((sizeof(mission_state) == 1), "invalid size");
  uint8_t size = 3;
  enum messages message = messages::flight_controller_status;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 38;
  uint8_t get_id() { return id; }
  void set_HW_state(uint8_t value) { HW_state = value; }
  void set_SW_state(uint8_t value) { SW_state = value; }
  void set_mission_state(uint8_t value) { mission_state = value; }
  uint8_t get_HW_state() { return HW_state; }
  uint8_t get_SW_state() { return SW_state; }
  uint8_t get_mission_state() { return mission_state; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &HW_state, sizeof(HW_state));
    *index += sizeof(HW_state);
    memcpy(buf + *index, &SW_state, sizeof(SW_state));
    *index += sizeof(SW_state);
    memcpy(buf + *index, &mission_state, sizeof(mission_state));
    *index += sizeof(mission_state);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&HW_state, buf + index, sizeof(HW_state));
    index += sizeof(HW_state);
    memcpy(&SW_state, buf + index, sizeof(SW_state));
    index += sizeof(SW_state);
    memcpy(&mission_state, buf + index, sizeof(mission_state));
    index += sizeof(mission_state);
  }
};

class return_data_logging_from_flight_controller_to_ground_station {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_logging_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_logging_en() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  enum messages message = messages::return_data_logging;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 39;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_dump_flash_from_flight_controller_to_ground_station {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_dump_sd(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_dump_sd() { return bit_field & (1 << 0); }
  void set_dump_usb(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  bool get_dump_usb() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  enum messages message = messages::return_dump_flash;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 40;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_handshake_from_flight_controller_to_ground_station {
public:
  uint8_t size = 0;
  enum messages message = messages::return_handshake;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 41;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
  void parse_buf(uint8_t *buf) {}
};

class ms_since_boot_from_flight_controller_to_ground_station {
public:
  uint16_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 2), "invalid size");
  uint8_t size = 2;
  enum messages message = messages::ms_since_boot;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 80;
  uint8_t get_id() { return id; }
  void set_ms_since_boot(uint16_t value) { ms_since_boot = value; }
  uint16_t get_ms_since_boot() { return ms_since_boot; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &ms_since_boot, sizeof(ms_since_boot));
    *index += sizeof(ms_since_boot);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&ms_since_boot, buf + index, sizeof(ms_since_boot));
    index += sizeof(ms_since_boot);
  }
};

class us_since_boot_from_flight_controller_to_ground_station {
public:
  uint32_t us_since_boot;
  static_assert((sizeof(us_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  enum messages message = messages::us_since_boot;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 81;
  uint8_t get_id() { return id; }
  void set_us_since_boot(uint32_t value) { us_since_boot = value; }
  uint32_t get_us_since_boot() { return us_since_boot; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &us_since_boot, sizeof(us_since_boot));
    *index += sizeof(us_since_boot);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&us_since_boot, buf + index, sizeof(us_since_boot));
    index += sizeof(us_since_boot);
  }
};

class current_time_from_flight_controller_to_ground_station {
public:
  uint32_t current_time;
  static_assert((sizeof(current_time) == 4), "invalid size");
  uint8_t size = 4;
  enum messages message = messages::current_time;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 82;
  uint8_t get_id() { return id; }
  void set_current_time(uint32_t value) { current_time = value; }
  uint32_t get_current_time() { return current_time; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &current_time, sizeof(current_time));
    *index += sizeof(current_time);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&current_time, buf + index, sizeof(current_time));
    index += sizeof(current_time);
  }
};

class GNSS_data_1_from_flight_controller_to_ground_station {
public:
  uint32_t gnss_time;
  static_assert((sizeof(gnss_time) == 4), "invalid size");
  int32_t latitude;
  static_assert((sizeof(latitude) == 4), "invalid size");
  int32_t longitude;
  static_assert((sizeof(longitude) == 4), "invalid size");
  uint8_t size = 12;
  enum messages message = messages::GNSS_data_1;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 83;
  uint8_t get_id() { return id; }
  void set_gnss_time(uint32_t value) { gnss_time = value; }
  void set_latitude(int32_t value) { latitude = value; }
  void set_longitude(int32_t value) { longitude = value; }
  uint32_t get_gnss_time() { return gnss_time; }
  int32_t get_latitude() { return latitude; }
  int32_t get_longitude() { return longitude; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &gnss_time, sizeof(gnss_time));
    *index += sizeof(gnss_time);
    memcpy(buf + *index, &latitude, sizeof(latitude));
    *index += sizeof(latitude);
    memcpy(buf + *index, &longitude, sizeof(longitude));
    *index += sizeof(longitude);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&gnss_time, buf + index, sizeof(gnss_time));
    index += sizeof(gnss_time);
    memcpy(&latitude, buf + index, sizeof(latitude));
    index += sizeof(latitude);
    memcpy(&longitude, buf + index, sizeof(longitude));
    index += sizeof(longitude);
  }
};

class GNSS_data_2_from_flight_controller_to_ground_station {
public:
  int32_t altitude;
  static_assert((sizeof(altitude) == 4), "invalid size");
  int16_t heading;
  static_assert((sizeof(heading) == 2), "invalid size");
  int16_t horiz_speed;
  static_assert((sizeof(horiz_speed) == 2), "invalid size");
  enum fix_status fix_status;
  static_assert((sizeof(fix_status) == 1), "invalid size");
  uint8_t n_satellites;
  static_assert((sizeof(n_satellites) == 1), "invalid size");
  uint16_t h_dop;
  static_assert((sizeof(h_dop) == 2), "invalid size");
  uint8_t size = 12;
  enum messages message = messages::GNSS_data_2;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 84;
  uint8_t get_id() { return id; }
  void set_altitude(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 10, &altitude);
  }
  void set_heading(int16_t value) { heading = value; }
  void set_horiz_speed(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 10, &horiz_speed);
  }
  void set_fix_status(enum fix_status value) { fix_status = value; }
  void set_n_satellites(uint8_t value) { n_satellites = value; }
  void set_h_dop(fc_FLOAT_DEF value) { scaledFloat_to_uint(value, 10, &h_dop); }
  fc_FLOAT_DEF get_altitude() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(altitude, 10, &out);
    return out;
  }
  int16_t get_heading() { return heading; }
  fc_FLOAT_DEF get_horiz_speed() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(horiz_speed, 10, &out);
    return out;
  }
  enum fix_status get_fix_status() { return fix_status; }
  uint8_t get_n_satellites() { return n_satellites; }
  fc_FLOAT_DEF get_h_dop() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(h_dop, 10, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &altitude, sizeof(altitude));
    *index += sizeof(altitude);
    memcpy(buf + *index, &heading, sizeof(heading));
    *index += sizeof(heading);
    memcpy(buf + *index, &horiz_speed, sizeof(horiz_speed));
    *index += sizeof(horiz_speed);
    memcpy(buf + *index, &fix_status, sizeof(fix_status));
    *index += sizeof(fix_status);
    memcpy(buf + *index, &n_satellites, sizeof(n_satellites));
    *index += sizeof(n_satellites);
    memcpy(buf + *index, &h_dop, sizeof(h_dop));
    *index += sizeof(h_dop);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&altitude, buf + index, sizeof(altitude));
    index += sizeof(altitude);
    memcpy(&heading, buf + index, sizeof(heading));
    index += sizeof(heading);
    memcpy(&horiz_speed, buf + index, sizeof(horiz_speed));
    index += sizeof(horiz_speed);
    memcpy(&fix_status, buf + index, sizeof(fix_status));
    index += sizeof(fix_status);
    memcpy(&n_satellites, buf + index, sizeof(n_satellites));
    index += sizeof(n_satellites);
    memcpy(&h_dop, buf + index, sizeof(h_dop));
    index += sizeof(h_dop);
  }
};

class inside_static_temperature_from_flight_controller_to_ground_station {
public:
  int32_t temperature_1;
  static_assert((sizeof(temperature_1) == 4), "invalid size");
  int32_t temperature_2;
  static_assert((sizeof(temperature_2) == 4), "invalid size");
  uint8_t size = 8;
  enum messages message = messages::inside_static_temperature;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 85;
  uint8_t get_id() { return id; }
  void set_temperature_1(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &temperature_1);
  }
  void set_temperature_2(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &temperature_2);
  }
  fc_FLOAT_DEF get_temperature_1() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(temperature_1, 100, &out);
    return out;
  }
  fc_FLOAT_DEF get_temperature_2() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(temperature_2, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &temperature_1, sizeof(temperature_1));
    *index += sizeof(temperature_1);
    memcpy(buf + *index, &temperature_2, sizeof(temperature_2));
    *index += sizeof(temperature_2);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&temperature_1, buf + index, sizeof(temperature_1));
    index += sizeof(temperature_1);
    memcpy(&temperature_2, buf + index, sizeof(temperature_2));
    index += sizeof(temperature_2);
  }
};

class inside_static_pressure_from_flight_controller_to_ground_station {
public:
  int32_t pressure_1;
  static_assert((sizeof(pressure_1) == 4), "invalid size");
  int32_t pressure_2;
  static_assert((sizeof(pressure_2) == 4), "invalid size");
  uint8_t size = 8;
  enum messages message = messages::inside_static_pressure;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 86;
  uint8_t get_id() { return id; }
  void set_pressure_1(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &pressure_1);
  }
  void set_pressure_2(fc_FLOAT_DEF value) {
    scaledFloat_to_uint(value, 100, &pressure_2);
  }
  fc_FLOAT_DEF get_pressure_1() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(pressure_1, 100, &out);
    return out;
  }
  fc_FLOAT_DEF get_pressure_2() {
    fc_FLOAT_DEF out;
    uint_to_scaledFloat(pressure_2, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &pressure_1, sizeof(pressure_1));
    *index += sizeof(pressure_1);
    memcpy(buf + *index, &pressure_2, sizeof(pressure_2));
    *index += sizeof(pressure_2);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&pressure_1, buf + index, sizeof(pressure_1));
    index += sizeof(pressure_1);
    memcpy(&pressure_2, buf + index, sizeof(pressure_2));
    index += sizeof(pressure_2);
  }
};

class IMU1_from_flight_controller_to_ground_station {
public:
  uint16_t accel_x;
  static_assert((sizeof(accel_x) == 2), "invalid size");
  uint16_t accel_y;
  static_assert((sizeof(accel_y) == 2), "invalid size");
  uint16_t accel_z;
  static_assert((sizeof(accel_z) == 2), "invalid size");
  uint16_t gyro_x;
  static_assert((sizeof(gyro_x) == 2), "invalid size");
  uint16_t gyro_y;
  static_assert((sizeof(gyro_y) == 2), "invalid size");
  uint16_t gyro_z;
  static_assert((sizeof(gyro_z) == 2), "invalid size");
  uint16_t magnet_x;
  static_assert((sizeof(magnet_x) == 2), "invalid size");
  uint16_t magnet_y;
  static_assert((sizeof(magnet_y) == 2), "invalid size");
  uint16_t magnet_z;
  static_assert((sizeof(magnet_z) == 2), "invalid size");
  uint8_t size = 18;
  enum messages message = messages::IMU1;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 87;
  uint8_t get_id() { return id; }
  void set_accel_x(uint16_t value) { accel_x = value; }
  void set_accel_y(uint16_t value) { accel_y = value; }
  void set_accel_z(uint16_t value) { accel_z = value; }
  void set_gyro_x(uint16_t value) { gyro_x = value; }
  void set_gyro_y(uint16_t value) { gyro_y = value; }
  void set_gyro_z(uint16_t value) { gyro_z = value; }
  void set_magnet_x(uint16_t value) { magnet_x = value; }
  void set_magnet_y(uint16_t value) { magnet_y = value; }
  void set_magnet_z(uint16_t value) { magnet_z = value; }
  uint16_t get_accel_x() { return accel_x; }
  uint16_t get_accel_y() { return accel_y; }
  uint16_t get_accel_z() { return accel_z; }
  uint16_t get_gyro_x() { return gyro_x; }
  uint16_t get_gyro_y() { return gyro_y; }
  uint16_t get_gyro_z() { return gyro_z; }
  uint16_t get_magnet_x() { return magnet_x; }
  uint16_t get_magnet_y() { return magnet_y; }
  uint16_t get_magnet_z() { return magnet_z; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &accel_x, sizeof(accel_x));
    *index += sizeof(accel_x);
    memcpy(buf + *index, &accel_y, sizeof(accel_y));
    *index += sizeof(accel_y);
    memcpy(buf + *index, &accel_z, sizeof(accel_z));
    *index += sizeof(accel_z);
    memcpy(buf + *index, &gyro_x, sizeof(gyro_x));
    *index += sizeof(gyro_x);
    memcpy(buf + *index, &gyro_y, sizeof(gyro_y));
    *index += sizeof(gyro_y);
    memcpy(buf + *index, &gyro_z, sizeof(gyro_z));
    *index += sizeof(gyro_z);
    memcpy(buf + *index, &magnet_x, sizeof(magnet_x));
    *index += sizeof(magnet_x);
    memcpy(buf + *index, &magnet_y, sizeof(magnet_y));
    *index += sizeof(magnet_y);
    memcpy(buf + *index, &magnet_z, sizeof(magnet_z));
    *index += sizeof(magnet_z);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&accel_x, buf + index, sizeof(accel_x));
    index += sizeof(accel_x);
    memcpy(&accel_y, buf + index, sizeof(accel_y));
    index += sizeof(accel_y);
    memcpy(&accel_z, buf + index, sizeof(accel_z));
    index += sizeof(accel_z);
    memcpy(&gyro_x, buf + index, sizeof(gyro_x));
    index += sizeof(gyro_x);
    memcpy(&gyro_y, buf + index, sizeof(gyro_y));
    index += sizeof(gyro_y);
    memcpy(&gyro_z, buf + index, sizeof(gyro_z));
    index += sizeof(gyro_z);
    memcpy(&magnet_x, buf + index, sizeof(magnet_x));
    index += sizeof(magnet_x);
    memcpy(&magnet_y, buf + index, sizeof(magnet_y));
    index += sizeof(magnet_y);
    memcpy(&magnet_z, buf + index, sizeof(magnet_z));
    index += sizeof(magnet_z);
  }
};

class IMU2_from_flight_controller_to_ground_station {
public:
  uint16_t accel_x;
  static_assert((sizeof(accel_x) == 2), "invalid size");
  uint16_t accel_y;
  static_assert((sizeof(accel_y) == 2), "invalid size");
  uint16_t accel_z;
  static_assert((sizeof(accel_z) == 2), "invalid size");
  uint16_t gyro_x;
  static_assert((sizeof(gyro_x) == 2), "invalid size");
  uint16_t gyro_y;
  static_assert((sizeof(gyro_y) == 2), "invalid size");
  uint16_t gyro_z;
  static_assert((sizeof(gyro_z) == 2), "invalid size");
  uint16_t magnet_x;
  static_assert((sizeof(magnet_x) == 2), "invalid size");
  uint16_t magnet_y;
  static_assert((sizeof(magnet_y) == 2), "invalid size");
  uint16_t magnet_z;
  static_assert((sizeof(magnet_z) == 2), "invalid size");
  uint8_t size = 18;
  enum messages message = messages::IMU2;
  enum nodes sender = nodes::flight_controller;
  enum nodes receiver = nodes::ground_station;
  uint8_t get_size() { return size; }
  enum nodes get_sender() { return sender; }
  enum nodes get_receiver() { return receiver; }
  uint8_t id = 88;
  uint8_t get_id() { return id; }
  void set_accel_x(uint16_t value) { accel_x = value; }
  void set_accel_y(uint16_t value) { accel_y = value; }
  void set_accel_z(uint16_t value) { accel_z = value; }
  void set_gyro_x(uint16_t value) { gyro_x = value; }
  void set_gyro_y(uint16_t value) { gyro_y = value; }
  void set_gyro_z(uint16_t value) { gyro_z = value; }
  void set_magnet_x(uint16_t value) { magnet_x = value; }
  void set_magnet_y(uint16_t value) { magnet_y = value; }
  void set_magnet_z(uint16_t value) { magnet_z = value; }
  uint16_t get_accel_x() { return accel_x; }
  uint16_t get_accel_y() { return accel_y; }
  uint16_t get_accel_z() { return accel_z; }
  uint16_t get_gyro_x() { return gyro_x; }
  uint16_t get_gyro_y() { return gyro_y; }
  uint16_t get_gyro_z() { return gyro_z; }
  uint16_t get_magnet_x() { return magnet_x; }
  uint16_t get_magnet_y() { return magnet_y; }
  uint16_t get_magnet_z() { return magnet_z; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &accel_x, sizeof(accel_x));
    *index += sizeof(accel_x);
    memcpy(buf + *index, &accel_y, sizeof(accel_y));
    *index += sizeof(accel_y);
    memcpy(buf + *index, &accel_z, sizeof(accel_z));
    *index += sizeof(accel_z);
    memcpy(buf + *index, &gyro_x, sizeof(gyro_x));
    *index += sizeof(gyro_x);
    memcpy(buf + *index, &gyro_y, sizeof(gyro_y));
    *index += sizeof(gyro_y);
    memcpy(buf + *index, &gyro_z, sizeof(gyro_z));
    *index += sizeof(gyro_z);
    memcpy(buf + *index, &magnet_x, sizeof(magnet_x));
    *index += sizeof(magnet_x);
    memcpy(buf + *index, &magnet_y, sizeof(magnet_y));
    *index += sizeof(magnet_y);
    memcpy(buf + *index, &magnet_z, sizeof(magnet_z));
    *index += sizeof(magnet_z);
  }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&accel_x, buf + index, sizeof(accel_x));
    index += sizeof(accel_x);
    memcpy(&accel_y, buf + index, sizeof(accel_y));
    index += sizeof(accel_y);
    memcpy(&accel_z, buf + index, sizeof(accel_z));
    index += sizeof(accel_z);
    memcpy(&gyro_x, buf + index, sizeof(gyro_x));
    index += sizeof(gyro_x);
    memcpy(&gyro_y, buf + index, sizeof(gyro_y));
    index += sizeof(gyro_y);
    memcpy(&gyro_z, buf + index, sizeof(gyro_z));
    index += sizeof(gyro_z);
    memcpy(&magnet_x, buf + index, sizeof(magnet_x));
    index += sizeof(magnet_x);
    memcpy(&magnet_y, buf + index, sizeof(magnet_y));
    index += sizeof(magnet_y);
    memcpy(&magnet_z, buf + index, sizeof(magnet_z));
    index += sizeof(magnet_z);
  }
};

void rx(local_timestamp_from_local_to_local msg);
void rx(local_timestamp_from_local_to_local msg, void *misc);
void rx(ms_since_boot_from_test_to_test msg);
void rx(ms_since_boot_from_test_to_test msg, void *misc);
void rx(altitude_from_test_to_test msg);
void rx(altitude_from_test_to_test msg, void *misc);
void rx(acceleration_from_test_to_test msg);
void rx(acceleration_from_test_to_test msg, void *misc);
void rx(pressure_from_test_to_test msg);
void rx(pressure_from_test_to_test msg, void *misc);
void rx(catastrophe_from_test_to_test msg);
void rx(catastrophe_from_test_to_test msg, void *misc);
void rx(gyro_from_test_to_test msg);
void rx(gyro_from_test_to_test msg, void *misc);
void rx(time_sync_from_ground_station_to_flight_controller msg);
void rx(time_sync_from_ground_station_to_flight_controller msg, void *misc);
void rx(set_power_mode_from_ground_station_to_flight_controller msg);
void rx(set_power_mode_from_ground_station_to_flight_controller msg,
        void *misc);
void rx(set_radio_equipment_from_ground_station_to_flight_controller msg);
void rx(set_radio_equipment_from_ground_station_to_flight_controller msg,
        void *misc);
void rx(set_parachute_output_from_ground_station_to_flight_controller msg);
void rx(set_parachute_output_from_ground_station_to_flight_controller msg,
        void *misc);
void rx(set_data_logging_from_ground_station_to_flight_controller msg);
void rx(set_data_logging_from_ground_station_to_flight_controller msg,
        void *misc);
void rx(dump_flash_from_ground_station_to_flight_controller msg);
void rx(dump_flash_from_ground_station_to_flight_controller msg, void *misc);
void rx(handshake_from_ground_station_to_flight_controller msg);
void rx(handshake_from_ground_station_to_flight_controller msg, void *misc);
void rx(return_time_sync_from_flight_controller_to_ground_station msg);
void rx(return_time_sync_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(return_power_mode_from_flight_controller_to_ground_station msg);
void rx(return_power_mode_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(return_radio_equipment_from_flight_controller_to_ground_station msg);
void rx(return_radio_equipment_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(return_parachute_output_from_flight_controller_to_ground_station msg);
void rx(return_parachute_output_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(onboard_battery_voltage_from_flight_controller_to_ground_station msg);
void rx(onboard_battery_voltage_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(gnss_data_from_flight_controller_to_ground_station msg);
void rx(gnss_data_from_flight_controller_to_ground_station msg, void *misc);
void rx(flight_controller_status_from_flight_controller_to_ground_station msg);
void rx(flight_controller_status_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(return_data_logging_from_flight_controller_to_ground_station msg);
void rx(return_data_logging_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(return_dump_flash_from_flight_controller_to_ground_station msg);
void rx(return_dump_flash_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(return_handshake_from_flight_controller_to_ground_station msg);
void rx(return_handshake_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(ms_since_boot_from_flight_controller_to_ground_station msg);
void rx(ms_since_boot_from_flight_controller_to_ground_station msg, void *misc);
void rx(us_since_boot_from_flight_controller_to_ground_station msg);
void rx(us_since_boot_from_flight_controller_to_ground_station msg, void *misc);
void rx(current_time_from_flight_controller_to_ground_station msg);
void rx(current_time_from_flight_controller_to_ground_station msg, void *misc);
void rx(GNSS_data_1_from_flight_controller_to_ground_station msg);
void rx(GNSS_data_1_from_flight_controller_to_ground_station msg, void *misc);
void rx(GNSS_data_2_from_flight_controller_to_ground_station msg);
void rx(GNSS_data_2_from_flight_controller_to_ground_station msg, void *misc);
void rx(inside_static_temperature_from_flight_controller_to_ground_station msg);
void rx(inside_static_temperature_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(inside_static_pressure_from_flight_controller_to_ground_station msg);
void rx(inside_static_pressure_from_flight_controller_to_ground_station msg,
        void *misc);
void rx(IMU1_from_flight_controller_to_ground_station msg);
void rx(IMU1_from_flight_controller_to_ground_station msg, void *misc);
void rx(IMU2_from_flight_controller_to_ground_station msg);
void rx(IMU2_from_flight_controller_to_ground_station msg, void *misc);
void parse_message(uint8_t id, uint8_t *buf);
void parse_message(uint8_t id, uint8_t *buf, void *misc);
bool is_valid_id(uint8_t id);
uint8_t id_to_len(uint8_t id);
enum nodes id_to_sender(uint8_t id);
enum nodes id_to_receiver(uint8_t id);
enum categories id_to_category(uint8_t id);
} // namespace fc