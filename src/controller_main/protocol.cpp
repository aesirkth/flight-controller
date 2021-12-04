#include "main.h"
#include "protocol.h"

#define TELECOMMAND_MAX_MSG_LEN RH_RF95_MAX_MESSAGE_LEN

#define PARACHUTE_ACTIVATE_DELAY_US (5 * 1000 * 1000) //5s
#define PARACHUTE_DEACTIVATE_DELAY_US (0.5 * 1000 * 1000) //500ms

uint8_t previous_length[255] = {0};

struct default_uint8 {
  uint8_t val = 1;
};

struct default_uint8 send_frequency[255];
uint8_t message_count[255] ={0};


/*
send internally - only flash
send telemetry - over radio depending on relay_frequency
send CAN - to CAN
send response - always over radio
send everywhere - can and radio
*/

void sendMessage(fc::MessageBase* msg, enum where target) {
  uint8_t buf[msg->get_size() + HEADER_SIZE];
  uint8_t index = 0;
  uint8_t id = msg->get_size();
  DataProtocol::build_buf(msg, buf, &index);

  switch(target) {
    case where::offline:
      flash_queue.enqueue(buf, index);
      break;
    case where::telemetry:
      message_count[id] = (message_count[id] + 1) % send_frequency[id].val;
      if (message_count[id] == 0) {
        telemetry_queue.enqueue(buf, index);
      }
      flash_queue.enqueue(buf, index);
      break;
    
    case where::important:
      telemetry_queue.enqueue(buf, index, true);
      lora_queue.enqueue(buf, index);
      flash_queue.enqueue(buf, index, true);
      break;
    
    case where::always:
      telemetry_queue.enqueue(buf, index, true);
      flash_queue.enqueue(buf, index, true);
      break;
    
    case where::real_telemetry:
      telemetry_queue.enqueue(buf, index, true);
      break;
  }
}

void DataProtocolCallback(uint8_t id, uint8_t* buf, uint8_t len) {
  uint8_t header_buf[HEADER_SIZE];
  uint8_t header_index = 0;
  uint8_t checksum = DataProtocol::get_checksum(buf, len);
  DataProtocol::build_header(id, checksum, header_buf, &header_index);
  flash_queue.enqueue(header_buf, header_index); //add header
  flash_queue.enqueue(buf, len);  //add message
  // parse the message no matter what, nothing will happen if it's invalid
  fc::parse_message(id, buf);

  if (EDDA::is_valid_id(id)) {
    CAN_message_t can_msg;
    can_msg.id = id;
    can_msg.len = len;
    memcpy(can_msg.buf, buf, len);
    can.write(can_msg); 
  }
}

void handleDataStreams() {
  //each instance tracks their own state
  static DataProtocol telemetry_protocol {DataProtocolCallback}; 
  static DataProtocol usb_protocol {DataProtocolCallback};
  static DataProtocol can_protocol {DataProtocolCallback};

  CAN_message_t can_msg; 
  can_msg.id = 42;
  
  while (Serial.available() > 0) {
    uint8_t byte = Serial.read();
    usb_protocol.parse_byte(byte);
  }

  while (Serial2.available()) {
    uint8_t byte = Serial2.read();
    telemetry_protocol.parse_byte(byte);
  }

  if(can.read(can_msg)) {
    if (not EDDA::is_valid_id(can_msg.id)) {
      return;
    }
    if (can_msg.id & 0x400 != 0x400) {
      return;
    }

    uint8_t buf[can_msg.len + HEADER_SIZE];
    uint8_t len = can_protocol.build_buf(can_msg, buf);
    if (data_logging_enabled) {
      flash_queue.enqueue(buf, len);
    }
    if ((can_msg.id & 0x400) == 0x400) {
      telemetry_queue.enqueue(buf, len);
    }
  }
}

void disableParachute1() {
  digitalWriteFast(PIN_PYRO_1, LOW);
  analogWrite(PIN_BUZZER, 0);
  para1_timer.end();
}

void disableParachute2() {
  digitalWriteFast(PIN_PYRO_2, LOW);
  analogWrite(PIN_BUZZER, 0);
  para2_timer.end();
}

void enableParachute1() {
  digitalWriteFast(PIN_PYRO_1, HIGH);
  para1_timer.end();
  para1_timer.begin(disableParachute1, PARACHUTE_DEACTIVATE_DELAY_US);
}

void enableParachute2() {
  digitalWriteFast(PIN_PYRO_2, HIGH);
  para2_timer.end();
  para2_timer.begin(disableParachute2, PARACHUTE_DEACTIVATE_DELAY_US);
}

void fc::rx(fc::set_parachute_output_from_ground_station_to_flight_controller msg) {
  bool para1 = parachute_armed && msg.get_is_parachute1_en();
  bool para2 = parachute_armed && msg.get_is_parachute2_en();
  parachute_armed = msg.get_is_parachute_armed();

  if (para1) {
    analogWrite(PIN_BUZZER, 122);
    para1_timer.begin(enableParachute1, PARACHUTE_ACTIVATE_DELAY_US);
  }
  if (para2) {
    analogWrite(PIN_BUZZER, 122);
    para2_timer.begin(enableParachute2, PARACHUTE_ACTIVATE_DELAY_US); 
  }
  fc::return_parachute_output_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  response.set_is_parachute1_en(para1);
  response.set_is_parachute2_en(para2);
  response.set_is_parachute_armed(parachute_armed);
  sendMessage(&response, where::always);
}

void fc::rx(fc::set_data_logging_from_ground_station_to_flight_controller msg) {
  data_logging_enabled = msg.get_is_logging_en();
  fc::return_data_logging_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  sendMessage(&response, where::always);
}

void fc::rx(fc::handshake_from_ground_station_to_flight_controller msg) {
  fc::return_handshake_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  DataProtocol::build_buf(&response, buf, &len);
  sendMessage(&response, where::always);
  delay(100);
  Serial.write(buf, len);
  delay(500);
}

void fc::rx(fc::time_sync_from_ground_station_to_flight_controller msg) {
  fc::return_time_sync_from_flight_controller_to_ground_station response;
  uint8_t len = response.get_size() + HEADER_SIZE;
  uint8_t buf[len];
  sendMessage(&response, where::always);
}

void fc::rx(fc::dump_flash_from_ground_station_to_flight_controller msg) {
  if (SD.begin(SdioConfig(FIFO_SDIO))) {
    FsFile file = SD.open(DUMPED_FILE_NAME);
    if (not file.isWritable()) {
      return;
    }
    flash.flush();
    uint8_t buf[2048];
    for (uint16_t i = 0; i < flash.getBufferedAddress(); i++) {
      flash.pageDataRead(i);
      flash.readData(buf, 0);
      file.write(buf, 2048);
    }
  }
}