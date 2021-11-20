#include "DataProtocol.h"
#include "fc.h"
#include "EDDA.h"
#include <FlexCAN_T4.h>

//Can only read messages defined by the flight controller protocol
void DataProtocol::parse_byte(uint8_t byte) {
  switch(state) {
    case START1:
      if (byte == INIT_FRAME_1) {
        state = TYPE;
      }
      Serial.println(byte);
      Serial.println("start1");
      break;

    case TYPE:
      Serial.println("type");
      if (not (fc::is_valid_id(byte) || EDDA::is_valid_id(byte))) {
        state = START1;
        break;
      }
      payload_length = fc::is_valid_id(byte) ? fc::id_to_len(byte) : EDDA::id_to_len(byte);
      payload_id = byte;
      state = CHECKSUM;
      payload_index = 0;
      break;
    
    case CHECKSUM:
      Serial.println("checksum");
      checksum = byte;
      state = PAYLOAD;
      break;

    case PAYLOAD:
      Serial.println("payload");
      payload_buf[payload_index] = byte;
      payload_index++;
      break;
  }

  if (payload_index == payload_length && state == PAYLOAD) {
    Serial.println("end");
    state = START1;
    payload_index = 0;
    if (checksum == get_checksum(payload_buf, payload_length)) {
      (*callback)(payload_id, payload_buf, payload_length);
    }
  }
}

void DataProtocol::parse_bytes(uint8_t* buf, uint8_t len) {
  for (uint8_t i = 0; i < len; i++) {
    parse_byte(buf[i]);
  }
}

void DataProtocol::parse_CAN_message(CAN_message_t msg) {
  uint8_t len = fc::is_valid_id(msg.id) ? fc::id_to_len(msg.id) : EDDA::id_to_len(msg.id);
  if (not (fc::is_valid_id(msg.id) || EDDA::is_valid_id(msg.id))) {
    return;
  }
  (*callback)(msg.id, msg.buf, len);
}

void DataProtocol::build_header(uint8_t id, uint8_t checksum, uint8_t* buf, uint8_t* index) {
  *index = 0;
  buf[(*index)++] = INIT_FRAME_1;
  buf[(*index)++] = id;
  buf[(*index)++] = checksum;
}