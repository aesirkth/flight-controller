/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#include <math.h>
#include <stdint.h>
#include <string.h>

namespace fc {
enum struct units : uint8_t {
  ground_station = 0,
  flight_controller_tc = 1,
  flight_controller = 2,
  ground_station_tc = 3,
  ground_station_tm = 4,
};
enum struct datatypes : uint8_t {
  time_sync = 0,
  set_power_mode = 1,
  set_radio_equipment = 2,
  set_parachute_output = 3,
  set_data_logging = 4,
  dump_flash_chip = 5,
  handshake = 6,
  return_time_sync = 7,
  return_power_mode = 8,
  return_radio_equipment = 9,
  return_parachute_output = 10,
  onboard_battery_voltage = 11,
  gnss_data = 12,
  flight_controller_status = 13,
  return_data_logging = 14,
  return_dump_flash = 15,
  return_handshake = 16,
  ms_since_boot = 17,
  us_since_boot = 18,
  current_time = 19,
  GNSS_data_1 = 20,
};
template <typename T>
void scaledFloat_to_uint(double value, double scale, T *out) {
  *out = value * scale;
}

template <typename T>
void uint_to_scaledFloat(T value, double scale, double *out) {
  *out = value / scale;
}

template <typename T>
void packedFloat_to_uint(double value, double min, double max, T *out) {
  T max_value = ~0;
  double difference = max - min;
  *out = (value - min) / difference * max_value;
}

template <typename T>
void uint_to_packedFloat(T value, double min, double max, double *out) {
  T max_value = ~0;
  double difference = max - min;
  *out = difference * value / max_value;
}

class time_sync {
public:
  uint32_t system_time;
  static_assert((sizeof(system_time) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&system_time, buf + index, sizeof(system_time));
    index += sizeof(system_time);
  }
  uint32_t get_system_time() { return system_time; }
};

class set_power_mode {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {}
};

class set_radio_equipment {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_is_fpv_en() { return bit_field & (1 << 0); }
  bool get_is_tm_en() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class set_parachute_output {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_is_parachute_armed() { return bit_field & (1 << 0); }
  bool get_is_parachute1_en() { return bit_field & (1 << 1); }
  bool get_is_parachute2_en() { return bit_field & (1 << 2); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class set_data_logging {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_is_logging_en() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class dump_flash_chip {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_dump_sd() { return bit_field & (1 << 0); }
  bool get_dump_usb() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class handshake {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {}
};

class return_time_sync {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {}
};

class return_power_mode {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {}
};

class return_radio_equipment {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_is_fpv_en() { return bit_field & (1 << 0); }
  bool get_is_tm_en() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_parachute_output {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_is_parachute_armed() { return bit_field & (1 << 0); }
  bool get_is_parachute1_en() { return bit_field & (1 << 1); }
  bool get_is_parachute2_en() { return bit_field & (1 << 2); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class onboard_battery_voltage {
public:
  uint16_t battery_1;
  static_assert((sizeof(battery_1) == 2), "invalid size");
  uint16_t battery_2;
  static_assert((sizeof(battery_2) == 2), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&battery_1, buf + index, sizeof(battery_1));
    index += sizeof(battery_1);
    memcpy(&battery_2, buf + index, sizeof(battery_2));
    index += sizeof(battery_2);
  }
  double get_battery_1() {
    double out;
    uint_to_scaledFloat(battery_1, 100, &out);
    return out;
  }
  double get_battery_2() {
    double out;
    uint_to_scaledFloat(battery_2, 100, &out);
    return out;
  }
};

class gnss_data {
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
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
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
  uint32_t get_gnss_time() { return gnss_time; }
  int32_t get_latitude() { return latitude; }
  int32_t get_longitude() { return longitude; }
  double get_h_dop() {
    double out;
    uint_to_scaledFloat(h_dop, 100, &out);
    return out;
  }
  uint8_t get_n_satellites() { return n_satellites; }
};

class flight_controller_status {
public:
  uint8_t HW_state;
  static_assert((sizeof(HW_state) == 1), "invalid size");
  uint8_t SW_state;
  static_assert((sizeof(SW_state) == 1), "invalid size");
  uint8_t mission_state;
  static_assert((sizeof(mission_state) == 1), "invalid size");
  uint8_t size = 3;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&HW_state, buf + index, sizeof(HW_state));
    index += sizeof(HW_state);
    memcpy(&SW_state, buf + index, sizeof(SW_state));
    index += sizeof(SW_state);
    memcpy(&mission_state, buf + index, sizeof(mission_state));
    index += sizeof(mission_state);
  }
  uint8_t get_HW_state() { return HW_state; }
  uint8_t get_SW_state() { return SW_state; }
  uint8_t get_mission_state() { return mission_state; }
};

class return_data_logging {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_is_logging_en() { return bit_field & (1 << 0); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_dump_flash {
public:
  uint8_t bit_field;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  bool get_dump_sd() { return bit_field & (1 << 0); }
  bool get_dump_usb() { return bit_field & (1 << 1); }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&bit_field, buf + index, sizeof(bit_field));
    index += sizeof(bit_field);
  }
};

class return_handshake {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {}
};

class ms_since_boot {
public:
  uint32_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&ms_since_boot, buf + index, sizeof(ms_since_boot));
    index += sizeof(ms_since_boot);
  }
  uint32_t get_ms_since_boot() { return ms_since_boot; }
};

class us_since_boot {
public:
  uint32_t us_since_boot;
  static_assert((sizeof(us_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&us_since_boot, buf + index, sizeof(us_since_boot));
    index += sizeof(us_since_boot);
  }
  uint32_t get_us_since_boot() { return us_since_boot; }
};

class current_time {
public:
  uint32_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&ms_since_boot, buf + index, sizeof(ms_since_boot));
    index += sizeof(ms_since_boot);
  }
  uint32_t get_ms_since_boot() { return ms_since_boot; }
};

class GNSS_data_1 {
public:
  uint32_t gnss_time;
  static_assert((sizeof(gnss_time) == 4), "invalid size");
  int32_t latitude;
  static_assert((sizeof(latitude) == 4), "invalid size");
  int32_t longitude;
  static_assert((sizeof(longitude) == 4), "invalid size");
  uint8_t size = 12;
  uint8_t get_size() { return size; }
  enum units source;
  enum units target;
  uint8_t id;
  enum units get_source() { return source; }
  enum units get_target() { return target; }
  uint8_t get_id() { return id; }
  void set_id(uint8_t value) { id = value; }
  void set_source(enum units value) { source = value; }
  void set_target(enum units value) { target = value; }
  void parse_buf(uint8_t *buf) {
    uint8_t index = 0;
    memcpy(&gnss_time, buf + index, sizeof(gnss_time));
    index += sizeof(gnss_time);
    memcpy(&latitude, buf + index, sizeof(latitude));
    index += sizeof(latitude);
    memcpy(&longitude, buf + index, sizeof(longitude));
    index += sizeof(longitude);
  }
  uint32_t get_gnss_time() { return gnss_time; }
  int32_t get_latitude() { return latitude; }
  int32_t get_longitude() { return longitude; }
};

class time_sync_from_ground_station_to_flight_controller_tc {
public:
  uint32_t system_time;
  static_assert((sizeof(system_time) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  uint8_t id = 16;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &system_time, sizeof(system_time));
    *index += sizeof(system_time);
  }
  void set_system_time(uint32_t value) { system_time = value; }
};

class set_power_mode_from_ground_station_to_flight_controller_tc {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  uint8_t id = 17;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
};

class set_radio_equipment_from_ground_station_to_flight_controller_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_fpv_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  void set_is_tm_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 18;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class set_parachute_output_from_ground_station_to_flight_controller_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_parachute_armed(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  void set_is_parachute1_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  void set_is_parachute2_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 2)) + !value * (bit_field & ~(1 << 2));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 19;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class set_data_logging_from_ground_station_to_flight_controller_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_logging_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 20;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class dump_flash_chip_from_ground_station_to_flight_controller_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_dump_sd(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  void set_dump_usb(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 21;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class handshake_from_ground_station_to_flight_controller_tc {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  uint8_t id = 22;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
};

class return_time_sync_from_flight_controller_to_ground_station_tc {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  uint8_t id = 32;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
};

class return_power_mode_from_flight_controller_to_ground_station_tc {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  uint8_t id = 33;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
};

class return_radio_equipment_from_flight_controller_to_ground_station_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_fpv_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  void set_is_tm_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 34;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class return_parachute_output_from_flight_controller_to_ground_station_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_parachute_armed(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  void set_is_parachute1_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  void set_is_parachute2_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 2)) + !value * (bit_field & ~(1 << 2));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 35;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class onboard_battery_voltage_from_flight_controller_to_ground_station_tc {
public:
  uint16_t battery_1;
  static_assert((sizeof(battery_1) == 2), "invalid size");
  uint16_t battery_2;
  static_assert((sizeof(battery_2) == 2), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  uint8_t id = 36;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &battery_1, sizeof(battery_1));
    *index += sizeof(battery_1);
    memcpy(buf + *index, &battery_2, sizeof(battery_2));
    *index += sizeof(battery_2);
  }
  void set_battery_1(double value) {
    scaledFloat_to_uint(value, 100, &battery_1);
  }
  void set_battery_2(double value) {
    scaledFloat_to_uint(value, 100, &battery_2);
  }
};

class gnss_data_from_flight_controller_to_ground_station_tc {
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
  uint8_t get_size() { return size; }
  uint8_t id = 37;
  uint8_t get_id() { return id; }
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
  void set_gnss_time(uint32_t value) { gnss_time = value; }
  void set_latitude(int32_t value) { latitude = value; }
  void set_longitude(int32_t value) { longitude = value; }
  void set_h_dop(double value) { scaledFloat_to_uint(value, 100, &h_dop); }
  void set_n_satellites(uint8_t value) { n_satellites = value; }
};

class flight_controller_status_from_flight_controller_to_ground_station_tc {
public:
  uint8_t HW_state;
  static_assert((sizeof(HW_state) == 1), "invalid size");
  uint8_t SW_state;
  static_assert((sizeof(SW_state) == 1), "invalid size");
  uint8_t mission_state;
  static_assert((sizeof(mission_state) == 1), "invalid size");
  uint8_t size = 3;
  uint8_t get_size() { return size; }
  uint8_t id = 38;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &HW_state, sizeof(HW_state));
    *index += sizeof(HW_state);
    memcpy(buf + *index, &SW_state, sizeof(SW_state));
    *index += sizeof(SW_state);
    memcpy(buf + *index, &mission_state, sizeof(mission_state));
    *index += sizeof(mission_state);
  }
  void set_HW_state(uint8_t value) { HW_state = value; }
  void set_SW_state(uint8_t value) { SW_state = value; }
  void set_mission_state(uint8_t value) { mission_state = value; }
};

class return_data_logging_from_flight_controller_to_ground_station_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_is_logging_en(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 39;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class return_dump_flash_from_flight_controller_to_ground_station_tc {
public:
  uint8_t bit_field = 0;
  static_assert((sizeof(bit_field) == 1), "invalid size");
  void set_dump_sd(bool value) {
    bit_field =
        value * (bit_field | (1 << 0)) + !value * (bit_field & ~(1 << 0));
  }
  void set_dump_usb(bool value) {
    bit_field =
        value * (bit_field | (1 << 1)) + !value * (bit_field & ~(1 << 1));
  }
  uint8_t size = 1;
  uint8_t get_size() { return size; }
  uint8_t id = 40;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &bit_field, sizeof(bit_field));
    *index += sizeof(bit_field);
  }
};

class return_handshake_from_flight_controller_to_ground_station_tc {
public:
  uint8_t size = 0;
  uint8_t get_size() { return size; }
  uint8_t id = 41;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {}
};

class ms_since_boot_from_flight_controller_to_ground_station_tm {
public:
  uint32_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  uint8_t id = 80;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &ms_since_boot, sizeof(ms_since_boot));
    *index += sizeof(ms_since_boot);
  }
  void set_ms_since_boot(uint32_t value) { ms_since_boot = value; }
};

class us_since_boot_from_flight_controller_to_ground_station_tm {
public:
  uint32_t us_since_boot;
  static_assert((sizeof(us_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  uint8_t id = 81;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &us_since_boot, sizeof(us_since_boot));
    *index += sizeof(us_since_boot);
  }
  void set_us_since_boot(uint32_t value) { us_since_boot = value; }
};

class current_time_from_flight_controller_to_ground_station_tm {
public:
  uint32_t ms_since_boot;
  static_assert((sizeof(ms_since_boot) == 4), "invalid size");
  uint8_t size = 4;
  uint8_t get_size() { return size; }
  uint8_t id = 82;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &ms_since_boot, sizeof(ms_since_boot));
    *index += sizeof(ms_since_boot);
  }
  void set_ms_since_boot(uint32_t value) { ms_since_boot = value; }
};

class GNSS_data_1_from_flight_controller_to_ground_station_tm {
public:
  uint32_t gnss_time;
  static_assert((sizeof(gnss_time) == 4), "invalid size");
  int32_t latitude;
  static_assert((sizeof(latitude) == 4), "invalid size");
  int32_t longitude;
  static_assert((sizeof(longitude) == 4), "invalid size");
  uint8_t size = 12;
  uint8_t get_size() { return size; }
  uint8_t id = 83;
  uint8_t get_id() { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) {
    memcpy(buf + *index, &gnss_time, sizeof(gnss_time));
    *index += sizeof(gnss_time);
    memcpy(buf + *index, &latitude, sizeof(latitude));
    *index += sizeof(latitude);
    memcpy(buf + *index, &longitude, sizeof(longitude));
    *index += sizeof(longitude);
  }
  void set_gnss_time(uint32_t value) { gnss_time = value; }
  void set_latitude(int32_t value) { latitude = value; }
  void set_longitude(int32_t value) { longitude = value; }
};

#define FC_PARSE_MESSAGE(id, buf)                                              \
  switch (id) {                                                                \
  case 16: {                                                                   \
    fc::time_sync __message;                                                   \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(16);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 17: {                                                                   \
    fc::set_power_mode __message;                                              \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(17);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 18: {                                                                   \
    fc::set_radio_equipment __message;                                         \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(18);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 19: {                                                                   \
    fc::set_parachute_output __message;                                        \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(19);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 20: {                                                                   \
    fc::set_data_logging __message;                                            \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(20);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 21: {                                                                   \
    fc::dump_flash_chip __message;                                             \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(21);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 22: {                                                                   \
    fc::handshake __message;                                                   \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::ground_station);                           \
    __message.set_target(fc::units::flight_controller_tc);                     \
    __message.set_id(22);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 32: {                                                                   \
    fc::return_time_sync __message;                                            \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(32);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 33: {                                                                   \
    fc::return_power_mode __message;                                           \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(33);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 34: {                                                                   \
    fc::return_radio_equipment __message;                                      \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(34);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 35: {                                                                   \
    fc::return_parachute_output __message;                                     \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(35);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 36: {                                                                   \
    fc::onboard_battery_voltage __message;                                     \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(36);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 37: {                                                                   \
    fc::gnss_data __message;                                                   \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(37);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 38: {                                                                   \
    fc::flight_controller_status __message;                                    \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(38);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 39: {                                                                   \
    fc::return_data_logging __message;                                         \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(39);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 40: {                                                                   \
    fc::return_dump_flash __message;                                           \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(40);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 41: {                                                                   \
    fc::return_handshake __message;                                            \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tc);                        \
    __message.set_id(41);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 80: {                                                                   \
    fc::ms_since_boot __message;                                               \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tm);                        \
    __message.set_id(80);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 81: {                                                                   \
    fc::us_since_boot __message;                                               \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tm);                        \
    __message.set_id(81);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 82: {                                                                   \
    fc::current_time __message;                                                \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tm);                        \
    __message.set_id(82);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  case 83: {                                                                   \
    fc::GNSS_data_1 __message;                                                 \
    __message.parse_buf(buf);                                                  \
    __message.set_source(fc::units::flight_controller);                        \
    __message.set_target(fc::units::ground_station_tm);                        \
    __message.set_id(83);                                                      \
    fc_rx(__message);                                                          \
    break;                                                                     \
  }                                                                            \
  }

uint8_t id_to_len(uint8_t id);
enum units id_to_source(uint8_t id);
enum units id_to_target(uint8_t id);
enum datatypes id_to_datatype(uint8_t id);
} // namespace fc