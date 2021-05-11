#include <map>

#include "main.h"

#define TELECOMMAND_MAX_MSG_LEN 30
#define PARACHUTE_DELAY_US 5000000

struct default_uint8 {
  uint8_t val = 1;
};

std::map<uint8_t, struct default_uint8> can_relay_frequency;
std::map<uint8_t, uint8_t> can_message_count;

void DataProtocolCallback(uint8_t id, uint8_t* buf, uint8_t len) {
  //Serial.print("chungus");
  uint8_t header_buf[HEADER_SIZE];
  uint8_t header_index = 0;
  protocol.build_header(id, header_buf, &header_index);
  add_to_backup_buf(header_buf, header_index); // add header
  add_to_backup_buf(buf, len); // add message
  // parse the message no matter what, nothing will happen if it's invalid
  fc::parse_message(id, buf); 
  //relay gc -> ec messages
  if (GC_TO_EC_TC_START <= id && id <= GC_TO_EC_TC_END) {
    CAN_message_t can_msg;
    can_msg.id = id;
    memcpy(can_msg.buf, buf, len);
    can_msg.len = len;
    CANbus.write(can_msg);
  }
  //relay ec -> telecommand
  if (EC_TO_GC_TC_START <= id && id <= EC_TO_GC_TC_END) {
    add_to_telecommand_buf(header_buf, header_index);
    add_to_telecommand_buf(buf, len);
  }
  //relay ec -> telemetry
  if (EC_TO_GC_TM_START <= id && id <= EC_TO_GC_TM_END) {
    can_message_count[id] = (can_message_count[id] + 1) % can_relay_frequency[id].val;
    if (can_message_count[id] == 0) {
      add_to_telemetry_buf(header_buf, header_index);
      add_to_telemetry_buf(buf, len);
    }
  }
}

void handleDataStreams() {
  uint8_t buf[TELECOMMAND_MAX_MSG_LEN];
  uint8_t len = TELECOMMAND_MAX_MSG_LEN;
  CAN_message_t can_msg;
  
  while (Serial.available() > 0) {
    uint8_t byte = Serial.read();
    protocol.parse_byte(byte);
  }
  if (rfm.recv(buf, &len)) {
    protocol.parse_frame(buf, len);
  }
  if(CANbus.available()) {
    CANbus.read(can_msg);
    protocol.parse_CAN_message(can_msg);
  }
}

void enableParachute1() {
  digitalWriteFast(PIN_PARA1, HIGH);
  analogWrite(PIN_BUZZER, 0);
  para1_timer.end();
}

void enableParachute2() {
  digitalWriteFast(PIN_PARA2, HIGH);
  analogWrite(PIN_BUZZER, 0);
  para2_timer.end();
}

void fc::rx(fc::set_parachute_output_from_ground_station_to_flight_controller msg) {
  bool para1 = parachute_armed && msg.get_is_parachute1_en();
  bool para2 = parachute_armed && msg.get_is_parachute2_en();
  parachute_armed = msg.get_is_parachute_armed();

  if (para1) {
    analogWrite(PIN_BUZZER, 122);
    para1_timer.begin(enableParachute1, PARACHUTE_DELAY_US);
  }
  if (para2) {
    analogWrite(PIN_BUZZER, 122);
    para2_timer.begin(enableParachute1, PARACHUTE_DELAY_US); 
  }
  fc::return_parachute_output_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  response.set_is_parachute1_en(para1);
  response.set_is_parachute2_en(para2);
  response.set_is_parachute_armed(parachute_armed);
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc::rx(fc::set_data_logging_from_ground_station_to_flight_controller msg) {
  data_logging_enabled = msg.get_is_logging_en();
  fc::return_data_logging_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
}

void fc::rx(fc::handshake_from_ground_station_to_flight_controller msg) {
  fc::return_handshake_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
  add_to_backup_buf(buf, len);
  delay(100);
  Serial.write(buf, len);
  delay(500);
}

void fc::rx(fc::time_sync_from_ground_station_to_flight_controller msg) {
  fc::return_time_sync_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  protocol.build_buf(response, buf, &len);
  add_to_telecommand_buf(buf, len);
}