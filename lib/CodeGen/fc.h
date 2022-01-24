/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#ifndef _fc_H
#define _fc_H
// if you want to use floats or doubles
#define fc_FLOAT_DEF float

#include <math.h>
#include <stdint.h>
#include <string.h>

namespace fc {
enum struct flight_state : uint8_t {
  sleeping = 0,
  idle = 1,
  ready = 2,
  burning = 3,
  ascending = 4,
  descending = 5,
  drogue = 6,
  main_chute = 7,
  landed = 8,
};
enum struct fix_status : uint8_t {
  no_fix = 0,
  fix_2D = 1,
  fix_3D = 2,
};
enum struct nodes : uint8_t {
  local = 0,
  ground_station = 1,
  flight_controller = 2,
};
enum struct fields : uint8_t {
  timestamp = 0,
  system_time = 1,
  state = 2,
  is_parachute_armed = 3,
  is_parachute1_en = 4,
  is_parachute2_en = 5,
  is_logging_en = 6,
  dump_sd = 7,
  dump_usb = 8,
  is_fpv_en = 9,
  is_tm_en = 10,
  battery_1 = 11,
  battery_2 = 12,
  ms_since_boot = 13,
  gnss_time = 14,
  altitude = 15,
  heading = 16,
  horiz_speed = 17,
  fix_status = 18,
  n_satellites = 19,
  h_dop = 20,
  pressure = 21,
  temperature = 22,
  imu_id = 23,
  accel_x = 24,
  accel_y = 25,
  accel_z = 26,
  gyro_x = 27,
  gyro_y = 28,
  gyro_z = 29,
  magnet_x = 30,
  magnet_y = 31,
  magnet_z = 32,
  longitude = 33,
  latitude = 34,
  differential_pressure = 35,
};
enum struct messages : uint8_t {
  local_timestamp = 0,
  time_sync = 1,
  set_state = 2,
  set_parachute_output = 3,
  set_data_logging = 4,
  dump_flash = 5,
  handshake = 6,
  return_time_sync = 7,
  return_power_mode = 8,
  return_radio_equipment = 9,
  return_parachute_output = 10,
  onboard_battery_voltage = 11,
  return_data_logging = 12,
  return_dump_flash = 13,
  return_handshake = 14,
  ms_since_boot = 15,
  GNSS_data = 16,
  ms_raw = 17,
  bmp_raw = 18,
  imu_raw = 19,
  position = 20,
  differential_pressure = 21,
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

class MessageBase {
public:
  virtual void build_buf(uint8_t *buf, uint8_t *index) {}
  virtual void parse_buf(uint8_t *buf) {}
  virtual uint8_t get_id() {}
  virtual enum categories get_category() {}
  virtual enum nodes get_receiver() {}
  virtual enum nodes get_sender() {}
  virtual uint8_t get_size() {}
};
class local_timestamp_from_local_to_local : public MessageBase {
public:
  uint32_t timestamp;
  static_assert((sizeof(timestamp) == 4), "invalid size");
  uint8_t size = 4;
  enum fc::messages message = fc::messages::local_timestamp;
  enum fc::nodes sender = fc::nodes::local;
  enum fc::nodes receiver = fc::nodes::local;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 255;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timestamp(uint32_t value) { timestamp = value; }
  uint32_t get_timestamp() { return timestamp; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timestamp, sizeof(timestamp));
    *index += sizeof(timestamp);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timestamp, buf + index, sizeof(timestamp));
    index += sizeof(timestamp);
  }
};

class time_sync_from_ground_station_to_flight_controller : public MessageBase {
public:
  uint32_t system_time;
  static_assert((sizeof(system_time) == 4), "invalid size");
  uint8_t size = 4;
  enum fc::messages message = fc::messages::time_sync;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 16;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_system_time(uint32_t value) { system_time = value; }
  uint32_t get_system_time() { return system_time; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &system_time, sizeof(system_time));
    *index += sizeof(system_time);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&system_time, buf + index, sizeof(system_time));
    index += sizeof(system_time);
  }
};

class set_state_from_ground_station_to_flight_controller : public MessageBase {
public:
  enum flight_state state;
  static_assert((sizeof(state) == 1), "invalid size");
  uint8_t size = 1;
  enum fc::messages message = fc::messages::set_state;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 17;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_state(enum flight_state value) { state = value; }
  enum flight_state get_state() { return state; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &state, sizeof(state));
    *index += sizeof(state);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&state, buf + index, sizeof(state));
    index += sizeof(state);
  }
};

class set_parachute_output_from_ground_station_to_flight_controller
    : public MessageBase {
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
  enum fc::messages message = fc::messages::set_parachute_output;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 18;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class set_data_logging_from_ground_station_to_flight_controller
    : public MessageBase {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_logging_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_logging_en() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  enum fc::messages message = fc::messages::set_data_logging;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 19;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class dump_flash_from_ground_station_to_flight_controller : public MessageBase {
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
  enum fc::messages message = fc::messages::dump_flash;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 20;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class handshake_from_ground_station_to_flight_controller : public MessageBase {
public:
  uint8_t size = 0;
  enum fc::messages message = fc::messages::handshake;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 3;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class return_time_sync_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint8_t size = 0;
  enum fc::messages message = fc::messages::return_time_sync;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 32;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class return_power_mode_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint8_t size = 0;
  enum fc::messages message = fc::messages::return_power_mode;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 33;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class return_radio_equipment_from_flight_controller_to_ground_station
    : public MessageBase {
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
  enum fc::messages message = fc::messages::return_radio_equipment;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 34;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_parachute_output_from_flight_controller_to_ground_station
    : public MessageBase {
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
  enum fc::messages message = fc::messages::return_parachute_output;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 35;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class onboard_battery_voltage_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint16_t battery_1;
  static_assert((sizeof(battery_1) == 2), "invalid size");
  uint16_t battery_2;
  static_assert((sizeof(battery_2) == 2), "invalid size");
  uint8_t size = 4;
  enum fc::messages message = fc::messages::onboard_battery_voltage;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 36;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
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
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &battery_1, sizeof(battery_1));
    *index += sizeof(battery_1);
    memcpy(buf + *index, &battery_2, sizeof(battery_2));
    *index += sizeof(battery_2);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&battery_1, buf + index, sizeof(battery_1));
    index += sizeof(battery_1);
    memcpy(&battery_2, buf + index, sizeof(battery_2));
    index += sizeof(battery_2);
  }
};

class return_data_logging_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_logging_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  bool get_is_logging_en() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  enum fc::messages message = fc::messages::return_data_logging;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 37;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_dump_flash_from_flight_controller_to_ground_station
    : public MessageBase {
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
  enum fc::messages message = fc::messages::return_dump_flash;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 38;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_handshake_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint8_t size = 0;
  enum fc::messages message = fc::messages::return_handshake;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 39;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class ms_since_boot_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint32_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  enum fc::messages message = fc::messages::ms_since_boot;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_ms_since_boot(uint32_t value) { ms_since_boot = value; }
  uint32_t get_ms_since_boot() { return ms_since_boot; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &ms_since_boot, sizeof(ms_since_boot));
    *index += sizeof(ms_since_boot);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&ms_since_boot, buf + index, sizeof(ms_since_boot));
    index += sizeof(ms_since_boot);
  }
};

class GNSS_data_from_flight_controller_to_ground_station : public MessageBase {
public:
  float_t gnss_time;
  static_assert((sizeof(gnss_time) == 4), "invalid size");
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
  uint8_t size = 16;
  enum fc::messages message = fc::messages::GNSS_data;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_gnss_time(float_t value) { gnss_time = value; }
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
  float_t get_gnss_time() { return gnss_time; }
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
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &gnss_time, sizeof(gnss_time));
    *index += sizeof(gnss_time);
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
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&gnss_time, buf + index, sizeof(gnss_time));
    index += sizeof(gnss_time);
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

class ms_raw_from_flight_controller_to_ground_station : public MessageBase {
public:
  float_t pressure;
  static_assert((sizeof(pressure) == 4), "invalid size");
  float_t temperature;
  static_assert((sizeof(temperature) == 4), "invalid size");
  uint8_t size = 8;
  enum fc::messages message = fc::messages::ms_raw;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 80;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_pressure(float_t value) { pressure = value; }
  void set_temperature(float_t value) { temperature = value; }
  float_t get_pressure() { return pressure; }
  float_t get_temperature() { return temperature; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &pressure, sizeof(pressure));
    *index += sizeof(pressure);
    memcpy(buf + *index, &temperature, sizeof(temperature));
    *index += sizeof(temperature);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&pressure, buf + index, sizeof(pressure));
    index += sizeof(pressure);
    memcpy(&temperature, buf + index, sizeof(temperature));
    index += sizeof(temperature);
  }
};

class bmp_raw_from_flight_controller_to_ground_station : public MessageBase {
public:
  float_t pressure;
  static_assert((sizeof(pressure) == 4), "invalid size");
  float_t temperature;
  static_assert((sizeof(temperature) == 4), "invalid size");
  uint8_t size = 8;
  enum fc::messages message = fc::messages::bmp_raw;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 81;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_pressure(float_t value) { pressure = value; }
  void set_temperature(float_t value) { temperature = value; }
  float_t get_pressure() { return pressure; }
  float_t get_temperature() { return temperature; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &pressure, sizeof(pressure));
    *index += sizeof(pressure);
    memcpy(buf + *index, &temperature, sizeof(temperature));
    *index += sizeof(temperature);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&pressure, buf + index, sizeof(pressure));
    index += sizeof(pressure);
    memcpy(&temperature, buf + index, sizeof(temperature));
    index += sizeof(temperature);
  }
};

class imu_raw_from_flight_controller_to_ground_station : public MessageBase {
public:
  uint8_t imu_id;
  static_assert((sizeof(imu_id) == 1), "invalid size");
  float_t accel_x;
  static_assert((sizeof(accel_x) == 4), "invalid size");
  float_t accel_y;
  static_assert((sizeof(accel_y) == 4), "invalid size");
  float_t accel_z;
  static_assert((sizeof(accel_z) == 4), "invalid size");
  float_t gyro_x;
  static_assert((sizeof(gyro_x) == 4), "invalid size");
  float_t gyro_y;
  static_assert((sizeof(gyro_y) == 4), "invalid size");
  float_t gyro_z;
  static_assert((sizeof(gyro_z) == 4), "invalid size");
  float_t magnet_x;
  static_assert((sizeof(magnet_x) == 4), "invalid size");
  float_t magnet_y;
  static_assert((sizeof(magnet_y) == 4), "invalid size");
  float_t magnet_z;
  static_assert((sizeof(magnet_z) == 4), "invalid size");
  uint8_t size = 37;
  enum fc::messages message = fc::messages::imu_raw;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 82;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_imu_id(uint8_t value) { imu_id = value; }
  void set_accel_x(float_t value) { accel_x = value; }
  void set_accel_y(float_t value) { accel_y = value; }
  void set_accel_z(float_t value) { accel_z = value; }
  void set_gyro_x(float_t value) { gyro_x = value; }
  void set_gyro_y(float_t value) { gyro_y = value; }
  void set_gyro_z(float_t value) { gyro_z = value; }
  void set_magnet_x(float_t value) { magnet_x = value; }
  void set_magnet_y(float_t value) { magnet_y = value; }
  void set_magnet_z(float_t value) { magnet_z = value; }
  uint8_t get_imu_id() { return imu_id; }
  float_t get_accel_x() { return accel_x; }
  float_t get_accel_y() { return accel_y; }
  float_t get_accel_z() { return accel_z; }
  float_t get_gyro_x() { return gyro_x; }
  float_t get_gyro_y() { return gyro_y; }
  float_t get_gyro_z() { return gyro_z; }
  float_t get_magnet_x() { return magnet_x; }
  float_t get_magnet_y() { return magnet_y; }
  float_t get_magnet_z() { return magnet_z; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &imu_id, sizeof(imu_id));
    *index += sizeof(imu_id);
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
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&imu_id, buf + index, sizeof(imu_id));
    index += sizeof(imu_id);
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

class position_from_flight_controller_to_ground_station : public MessageBase {
public:
  float_t altitude;
  static_assert((sizeof(altitude) == 4), "invalid size");
  float_t longitude;
  static_assert((sizeof(longitude) == 4), "invalid size");
  float_t latitude;
  static_assert((sizeof(latitude) == 4), "invalid size");
  uint8_t size = 12;
  enum fc::messages message = fc::messages::position;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 83;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_altitude(float_t value) { altitude = value; }
  void set_longitude(float_t value) { longitude = value; }
  void set_latitude(float_t value) { latitude = value; }
  float_t get_altitude() { return altitude; }
  float_t get_longitude() { return longitude; }
  float_t get_latitude() { return latitude; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &altitude, sizeof(altitude));
    *index += sizeof(altitude);
    memcpy(buf + *index, &longitude, sizeof(longitude));
    *index += sizeof(longitude);
    memcpy(buf + *index, &latitude, sizeof(latitude));
    *index += sizeof(latitude);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&altitude, buf + index, sizeof(altitude));
    index += sizeof(altitude);
    memcpy(&longitude, buf + index, sizeof(longitude));
    index += sizeof(longitude);
    memcpy(&latitude, buf + index, sizeof(latitude));
    index += sizeof(latitude);
  }
};

class differential_pressure_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  float_t differential_pressure;
  static_assert((sizeof(differential_pressure) == 4), "invalid size");
  uint8_t size = 4;
  enum fc::messages message = fc::messages::differential_pressure;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 84;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_differential_pressure(float_t value) {
    differential_pressure = value;
  }
  float_t get_differential_pressure() { return differential_pressure; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &differential_pressure, sizeof(differential_pressure));
    *index += sizeof(differential_pressure);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&differential_pressure, buf + index, sizeof(differential_pressure));
    index += sizeof(differential_pressure);
  }
};

void rx(local_timestamp_from_local_to_local msg);
void rx(local_timestamp_from_local_to_local msg, void *misc);
void rx(time_sync_from_ground_station_to_flight_controller msg);
void rx(time_sync_from_ground_station_to_flight_controller msg, void *misc);
void rx(set_state_from_ground_station_to_flight_controller msg);
void rx(set_state_from_ground_station_to_flight_controller msg, void *misc);
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
void rx(GNSS_data_from_flight_controller_to_ground_station msg);
void rx(GNSS_data_from_flight_controller_to_ground_station msg, void *misc);
void rx(ms_raw_from_flight_controller_to_ground_station msg);
void rx(ms_raw_from_flight_controller_to_ground_station msg, void *misc);
void rx(bmp_raw_from_flight_controller_to_ground_station msg);
void rx(bmp_raw_from_flight_controller_to_ground_station msg, void *misc);
void rx(imu_raw_from_flight_controller_to_ground_station msg);
void rx(imu_raw_from_flight_controller_to_ground_station msg, void *misc);
void rx(position_from_flight_controller_to_ground_station msg);
void rx(position_from_flight_controller_to_ground_station msg, void *misc);
void rx(differential_pressure_from_flight_controller_to_ground_station msg);
void rx(differential_pressure_from_flight_controller_to_ground_station msg,
        void *misc);
void parse_message(uint8_t id, uint8_t *buf);
void parse_message(uint8_t id, uint8_t *buf, void *misc);
bool is_valid_id(uint8_t id);
uint8_t id_to_len(uint8_t id);
enum nodes id_to_sender(uint8_t id);
enum nodes id_to_receiver(uint8_t id);
enum categories id_to_category(uint8_t id);
} // namespace fc
#endif
