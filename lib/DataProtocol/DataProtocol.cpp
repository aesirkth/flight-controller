#include "DataProtocol.h"

bool DataProtocol::decode_payload(uint8_t* payload, uint8_t len, uint8_t id) {
  if (GS_TO_EC_RANGE_START <= id && id <= GS_TO_EC_RANGE_END) {
    engine_msg.id = payload_type;
    memcpy(engine_msg.buf, payload_buf, payload_len);
    engine_msg.len = payload_len;
    set(FLAG_ENGINE_MESSAGE_AVAILABLE);
    return true;
  }
  switch(id) {
    case ID_SET_RADIO_EQUPIMENT:
      return decode_set_radio_equipment(payload, len);
      break;
    case ID_SET_PARACHUTE_OUTPUT:
      return decode_set_parachute_output(payload, len);
      break;
    case ID_SET_POWER_MODE:
      return decode_set_power_mode(payload, len);
      break;
    case ID_TIME_SYNC:
      return decode_time_sync(payload, len);
      break;
    case ID_SET_DATA_LOGGING:
      return decode_set_data_logging(payload, len);
      break;
    case ID_DUMP_FLASH:
      return decode_dump_flash(payload, len);
      break;
    case ID_HANDSHAKE:
      return decode_handshake(payload, len);
      break;
    default:
      return false;
  }
}

bool DataProtocol::parse_byte(uint8_t byte) {
  switch(state) {
    case START1:
      if (byte == INIT_FRAME_1) {
        state = START2;
      }
      break;

    case START2:
      if (byte == INIT_FRAME_2) {
        state = TYPE;
      } else {
        state = START1;
      }
      break;

    case TYPE:
      payload_buf_index = 0;
      payload_type = byte;
      state = PAYLOAD;
      switch(byte) {
        case ID_TIME_SYNC:
          payload_len = LEN_TIME_SYNC;
          break;
        case ID_SET_POWER_MODE:
          payload_len = LEN_SET_POWER_MODE;
          break;
        case ID_SET_PARACHUTE_OUTPUT:
          payload_len = LEN_SET_PARACHUTE_OUTPUT;
          break;
        case ID_SET_RADIO_EQUPIMENT:
          payload_len = LEN_SET_RADIO_EQUPIMENT;
          break;
        case ID_SET_DATA_LOGGING:
          payload_len = LEN_SET_DATA_LOGGING;
          break;
        case ID_DUMP_FLASH:
          payload_len = LEN_DUMP_FLASH;
          break;
        case ID_FIRE_ROCKET:
          payload_len = LEN_FIRE_ROCKET;
          break;
        case ID_SET_POWER_MODE_ENG:
          payload_len = LEN_SET_POWER_MODE_ENG;
          break;
        case ID_SET_ENGINE_STATE:
          payload_len = LEN_SET_ENGINE_STATE;
          break;
        case ID_HANDSHAKE:
          payload_len = LEN_HANDSHAKE;
          break;
        default:
          state = START1;
      }
      //if the payload length is zero fall through to the next case, which will 
      //parse the message
      if (payload_len != 0) {
        break;
      }

    case PAYLOAD:
      if (payload_len != 0) {
        payload_buf[payload_buf_index] = byte;
        payload_buf_index++;
      }
      if (payload_buf_index != payload_len) {
        break;
      }
      state = START1;
      bool result = decode_payload(payload_buf, payload_len, payload_type);
      payload_buf_index = 0;
      return result;
      
  }
  return false;
}

bool DataProtocol::parse_frame(uint8_t* frame, uint8_t len) {
  uint8_t id = frame[0];
  uint8_t* payload = frame + 1;  
  uint8_t payload_len = len - 1;
  return decode_payload(payload, payload_len, id);
}

bool DataProtocol::decode_time_sync(uint8_t* payload, uint8_t len) {
  if (len != LEN_TIME_SYNC) { 
    return false;
  }

  uint8_t index = 0;
  uint64_t raw; 
  read_array_to_int(payload_buf, &index, &raw);
  raw_time = raw;
  milliseconds = raw % 1000;
  raw /= 1000;
  seconds = raw % 100;
  raw /= 100;
  minutes = raw % 100;
  raw /= 100;
  hours = raw % 100;
  set(FLAG_TIME_SYNC);
  return true;
}

bool DataProtocol::decode_set_power_mode(uint8_t* payload, uint8_t len) {
  if (len != LEN_SET_POWER_MODE) {
    return false;
  }
  return true;
}

bool DataProtocol::decode_set_radio_equipment(uint8_t* payload, uint8_t len) {
  if (len != LEN_SET_RADIO_EQUPIMENT) {
    return false;
  }
  is_fpv_en = 0b1 & payload[0];
  is_tm_en = 0b10 & payload[0];
  set(FLAG_SET_RADIO_TRANSMITTERS);
  return true;
}

bool DataProtocol::decode_set_parachute_output(uint8_t* payload, uint8_t len) {
  if (len != LEN_SET_PARACHUTE_OUTPUT) {
    return false;
  }
  is_parachute_armed = 0b1 & payload[0];
  is_parachute1_en = 0b10 & payload[0];
  is_parachute2_en = 0b100 & payload[0];
  set(FLAG_SET_PARACHUTE_OUTPUT);
  return true;
}

bool DataProtocol::decode_set_data_logging(uint8_t* payload, uint8_t len) {
  if (len != LEN_SET_DATA_LOGGING) {
    return false;
  }
  data_logging_en = payload[0] &0b1;
  set(FLAG_SET_DATA_LOGGING);
  return true;
}

bool DataProtocol::decode_dump_flash(uint8_t* payload, uint8_t len) {
  if (len != LEN_DUMP_FLASH) {
    return false;
  }
  dump_sd = payload[0] & 0b1;
  dump_usb = payload[1] & 0b10;
  set(FLAG_DUMP_FLASH);
  return true;
}

bool DataProtocol::decode_handshake(uint8_t* payload, uint8_t len) {
  if (len != LEN_HANDSHAKE) {
    return false;
  }
  set(FLAG_HANDSHAKE);
  return true;
}

uint8_t DataProtocol::build_return_time_sync(uint8_t* buf) {
  buf[0] = INIT_FRAME_1;
  buf[1] = INIT_FRAME_2;
  buf[2] = ID_RETURN_TIME_SYNC;
  return 3;
}

uint8_t DataProtocol::build_return_power_mode(uint8_t* buf, bool TBD) {
  return 0;
}

uint8_t DataProtocol::build_return_radio_equipment(uint8_t* buf, bool is_fpv_en, bool is_tm_en) {
  buf[0] = INIT_FRAME_1;
  buf[1] = INIT_FRAME_2;
  buf[2] = ID_RETURN_RADIO_EQUIPMENT;
  buf[3] = is_fpv_en | (is_tm_en << 1);
  return 4;
}

uint8_t DataProtocol::build_return_parachute_output(uint8_t* buf, bool armed, bool en1, bool en2) {
  buf[0] = INIT_FRAME_1;
  buf[1] = INIT_FRAME_2;
  buf[2] = ID_RETURN_PARACHUTE_OUTPUT;
  buf[3] = armed | (en1 << 1) | (en2 << 2);
  return 4;
}

uint8_t DataProtocol::build_onboard_battery_voltage(uint8_t* buf, uint16_t battery1, uint16_t battery2) {
  uint8_t index = 0;
  buf[index++] = INIT_FRAME_1;
  buf[index++] = INIT_FRAME_2;
  buf[index++] = ID_ONBOARD_BATTERY_VOLTAGE;
  write_int_to_array(buf, &index, battery1 * 100);
  write_int_to_array(buf, &index, battery2 * 100);
  return index;
}

uint8_t DataProtocol::build_GNSS_data(
    uint8_t* buf, uint32_t gnss_time, int32_t latitude, int32_t longitude, uint16_t h_dop, uint8_t n_satellites) {
  
  uint8_t index = 0;
  buf[index++] = INIT_FRAME_1;
  buf[index++] = INIT_FRAME_2;
  buf[index++] = ID_GNSS_DATA;
  write_int_to_array(buf, &index, gnss_time);
  write_int_to_array(buf, &index, latitude);
  write_int_to_array(buf, &index, longitude);
  write_int_to_array(buf, &index, (uint16_t) (h_dop * 100));
  write_int_to_array(buf, &index, n_satellites);
  return index;
}

uint8_t DataProtocol::build_return_data_logging(uint8_t* buf, bool enabled) {
  buf[0] = INIT_FRAME_1;
  buf[1] = INIT_FRAME_2;
  buf[2] = ID_RETURN_DATA_LOGGING;
  buf[3] = enabled;
  return 4;
}

uint8_t DataProtocol::build_return_dump_flash(uint8_t* buf, bool sd, bool usb) {
  buf[0] = INIT_FRAME_1;
  buf[1] = INIT_FRAME_2;
  buf[2] = ID_RETURN_DATA_LOGGING;
  buf[3] = sd | (usb << 1);
  return 4;
}

uint8_t DataProtocol::build_return_handshake(uint8_t* buf) {
  buf[0] = INIT_FRAME_1;
  buf[1] = INIT_FRAME_2;
  buf[2] = ID_RETURN_HANDSHAKE;
  return 3;
}

uint8_t DataProtocol::build_current_time(uint8_t* buf, uint32_t current_time) {
  uint8_t index = 0;
  buf[index++] = INIT_FRAME_1;
  buf[index++] = INIT_FRAME_2;
  buf[index++] = ID_CURRENT_TIME;
  write_int_to_array(buf, &index, current_time);
  return index;
}

uint8_t DataProtocol::build_ms_since_boot(uint8_t* buf, uint32_t ms) {
  uint8_t index = 0;
  buf[index++] = INIT_FRAME_1;
  buf[index++] = INIT_FRAME_2;
  buf[index++] = ID_CURRENT_TIME;
  write_int_to_array(buf, &index, ms);
  return index;
}