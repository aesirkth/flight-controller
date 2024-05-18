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
enum struct nodes : uint8_t {
  flight_controller = 0,
  ground_station = 1,
};
enum struct fields : uint8_t {
  ms_since_boot = 0,
};
enum struct messages : uint8_t {
  ms_since_boot = 0,
  handshake = 1,
  return_handshake = 2,
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
  uint8_t id = 253;
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

class handshake_from_ground_station_to_flight_controller : public MessageBase {
public:
  uint8_t size = 0;
  enum fc::messages message = fc::messages::handshake;
  enum fc::nodes sender = fc::nodes::ground_station;
  enum fc::nodes receiver = fc::nodes::flight_controller;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 254;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class return_handshake_from_flight_controller_to_ground_station
    : public MessageBase {
public:
  uint8_t size = 0;
  enum fc::messages message = fc::messages::return_handshake;
  enum fc::nodes sender = fc::nodes::flight_controller;
  enum fc::nodes receiver = fc::nodes::ground_station;
  enum fc::categories category = fc::categories::none;
  uint8_t id = 255;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

void rx(ms_since_boot_from_flight_controller_to_ground_station msg);
void rx(ms_since_boot_from_flight_controller_to_ground_station msg, void *misc);
void rx(handshake_from_ground_station_to_flight_controller msg);
void rx(handshake_from_ground_station_to_flight_controller msg, void *misc);
void rx(return_handshake_from_flight_controller_to_ground_station msg);
void rx(return_handshake_from_flight_controller_to_ground_station msg,
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
