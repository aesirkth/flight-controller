#include <stdint.h>
#include <FlexCAN.h>
#include <string.h>
#define INIT_FRAME_1 0x0A
#define INIT_FRAME_2 0x0D

#define HEADER_SIZE 3
#define PAYLOAD_BUF_LEN 32

enum receiver_state {
    START1,
    START2,
    TYPE,
    PAYLOAD,
};

void DataProtocol_callback(uint64_t id, uint8_t* buf, uint8_t len);

class DataProtocol {
public:
  void parse_byte(uint8_t byte);
  void parse_frame(uint8_t* buf, uint8_t len);
  void parse_CAN_message(CAN_message_t msg);
  
  void build_header(uint8_t id, uint8_t* buf, uint8_t* index);
  template <typename T>
  void build_buf(T msg, uint8_t* buf, uint8_t* len) {
    *len = 0;
    buf[(*len)++] = INIT_FRAME_1;
    buf[(*len)++] = INIT_FRAME_2;
    buf[(*len)++] = msg.get_id();
    msg.build_buf(buf, len);
  }

  template <typename T>
  void build_CAN_message(T msg, CAN_message_t can) {
    uint8_t index = 0;
    can.id = msg.get_id();
    can.len = msg.get_size();
    uint8_t buf[can.len];
    msg.build(buf, &index);
    memcpy(can.buf, buf, can.len);
  }

private:
  enum receiver_state state = START1;
  uint8_t payload_length;
  uint8_t payload_buf[PAYLOAD_BUF_LEN];
  uint8_t payload_index;
  uint8_t payload_id;
};