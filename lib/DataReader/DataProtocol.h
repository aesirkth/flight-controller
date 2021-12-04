#include <stdint.h>
#include <FlexCAN_T4.h>
#include <string.h>
#include "fc.h"
#include "EDDA.h"

#define INIT_FRAME_1 '\n'
#define HEADER_SIZE 3

#define PAYLOAD_BUF_LEN 32

enum receiver_state {
    START1,
    TYPE,
    CHECKSUM,
    PAYLOAD,
};

class DataProtocol {
public:
  DataProtocol();
  DataProtocol(void (*func)(uint8_t id, uint8_t* buf, uint8_t len)){
    callback=func;
  }
  void set_callback(void (*func)(uint8_t id, uint8_t* buf, uint8_t len)){
    callback=func;
  }

  void parse_byte(uint8_t byte);
  void parse_bytes(uint8_t* buf, uint8_t len);
  void parse_CAN_message(CAN_message_t msg);
  
  static void build_header(uint8_t id, uint8_t checksum, uint8_t* buf, uint8_t* index);

  static void build_buf(fc::MessageBase* msg, uint8_t* buf, uint8_t* len) {
    *len = 0;
    buf[(*len)++] = INIT_FRAME_1;
    buf[(*len)++] = msg->get_id();
    buf[(*len)++] = 0x00; //checksum
    msg->build_buf(buf, len);
    buf[2] = get_checksum(buf + 3, msg->get_size());
  }

  static uint8_t build_buf(CAN_message_t msg, uint8_t* buf) {
    uint8_t index = 0;
    buf[index++] = INIT_FRAME_1;
    buf[index++] = msg.id;
    buf[index++] = get_checksum(msg.buf, msg.len);
    memcpy(buf + index, msg.buf, msg.len);
    return index + msg.len;
  }

  static uint8_t get_checksum(uint8_t* buf, uint8_t len) {
    uint8_t checksum = 0;
    for (uint8_t i = 0; i < len; i++) {
      checksum ^= buf[i];
    }
    return checksum;
  }

  static void build_CAN_message(fc::MessageBase* msg, CAN_message_t* can) {
    uint8_t index = 0;
    can->id = msg->get_id();
    can->len = msg->get_size();
    uint8_t buf[can->len];
    msg->build_buf(buf, &index);
    memcpy(can->buf, buf, can->len);
  }

private:
  void (*callback)(uint8_t id, uint8_t* buf, uint8_t len);
  enum receiver_state state = START1;
  uint8_t payload_length;
  uint8_t payload_buf[PAYLOAD_BUF_LEN];
  uint8_t payload_index;
  uint8_t payload_id;
  uint8_t checksum;
};