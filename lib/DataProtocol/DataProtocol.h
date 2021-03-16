#include <stdint.h>
#include <FlexCAN.h>

#define INIT_FRAME_1 0x0A
#define INIT_FRAME_2 0x0D

#define RADIO_MASK 0b11100000000

#define EC_TO_GS_RANGE_START 0x40
#define EC_TO_GS_RANGE_END 0x4F

#define GS_TO_EC_RANGE_START 0x30
#define GS_TO_EC_RANGE_END 0x3F

#define EC_TO_GS_TM_RANGE_START 0x80
#define EC_TO_GS_TM_RANGE_END 0xFF


//to engine
#define ID_SET_POWER_MODE_ENG 0x22
#define ID_SET_ENGINE_STATE 0x23
#define ID_FIRE_ROCKET 0x24

//to engine len
#define LEN_SET_POWER_MODE_ENG 1
#define LEN_SET_ENGINE_STATE 1
#define LEN_FIRE_ROCKET 1

//telecommand
#define ID_TIME_SYNC 0x10
#define ID_SET_POWER_MODE 0x11
#define ID_SET_RADIO_EQUPIMENT 0x12
#define ID_SET_PARACHUTE_OUTPUT 0x13
#define ID_SET_DATA_LOGGING 0x14
#define ID_DUMP_FLASH 0x15
#define ID_HANDSHAKE 0x16

#define ID_RETURN_TIME_SYNC 0x20
#define ID_RETURN_POWER_MODE 0x21
#define ID_RETURN_RADIO_EQUIPMENT 0x22
#define ID_RETURN_PARACHUTE_OUTPUT 0x23
#define ID_ONBOARD_BATTERY_VOLTAGE 0x24
#define ID_GNSS_DATA 0x25
#define ID_FLIGHT_CONTROLLER_STATUS0 0x26
#define ID_RETURN_DATA_LOGGING 0x27
#define ID_RETURN_DUMP_FLASH 0x28
#define ID_RETURN_HANDSHAKE 0x29

//telemetry
#define ID_MS_SINCE_BOOT 0x50
#define ID_US_SINCE_BOOT 0x51
#define ID_CURRENT_TIME 0x52
#define ID_GNSS_DATA_1 0x53
#define ID_GNSS_DATA_2 0x54
#define ID_INSIDE_TEMPERATURE 0x55
#define ID_INSIDE_PRESSURE 0x56
#define ID_IMU_1 0x57
#define ID_IMU_2 0x58
#define ID_EXTERNAL_TEMPERATURE 0x59
#define ID_AIR_SPEED 0x5A
#define ID_ONBOARD_BATTERY_VOLTAGE_TM 0x5B

//telecommand
#define LEN_TIME_SYNC 4
#define LEN_SET_POWER_MODE 1
#define LEN_SET_RADIO_EQUPIMENT 1
#define LEN_SET_PARACHUTE_OUTPUT 1
#define LEN_SET_DATA_LOGGING 1
#define LEN_DUMP_FLASH 1
#define LEN_HANDSHAKE 0

#define FLAG_ENGINE_MESSAGE_AVAILABLE 0x00
#define FLAG_TIME_SYNC 0x1
#define FLAG_SET_POWER_MODE 0x2
#define FLAG_SET_RADIO_TRANSMITTERS 0x3
#define FLAG_SET_PARACHUTE_OUTPUT 0x4
#define FLAG_SET_DATA_LOGGING 0x5
#define FLAG_DUMP_FLASH 0x6
#define FLAG_HANDSHAKE 0x7

#define PAYLOAD_BUF_LEN 32

enum receiver_state {
    START1,
    START2,
    TYPE,
    PAYLOAD,
};

class DataProtocol {
private:
  uint8_t payload_type;
  uint8_t payload_len;
  uint8_t payload_buf[PAYLOAD_BUF_LEN];
  uint8_t payload_buf_index = 0;
  bool decode_payload(uint8_t* payload, uint8_t len, uint8_t id);
  enum receiver_state state = START1;

  uint8_t flags;
  inline void set(uint32_t flag) {flags |= (1 << flag);}
  inline void clear(uint32_t flag) {flags &= !(1 << flag);}

  template<typename T>
  void write_int_to_array(uint8_t* array, uint8_t* index, T num);
  template<typename T>
  void read_array_to_int(uint8_t* array, uint8_t* index, T* num);

  bool decode_time_sync(uint8_t* payload, uint8_t len);
  bool decode_set_power_mode(uint8_t* payload, uint8_t len);
  bool decode_set_radio_equipment(uint8_t* payload, uint8_t len);
  bool decode_set_parachute_output(uint8_t* payload, uint8_t len);
  bool decode_set_data_logging(uint8_t* payload, uint8_t len);
  bool decode_dump_flash(uint8_t* payload, uint8_t len);
  bool decode_handshake(uint8_t* payload, uint8_t len);
public:
  CAN_message_t engine_msg;
  inline bool is_set(uint32_t flag) {return flags & (1 << flag);}
  inline void clear_flags() {flags = 0;}

  bool parse_byte(uint8_t byte);
  bool parse_frame(uint8_t* frame, uint8_t len);

  uint8_t build_return_time_sync(uint8_t* buf);
  uint8_t build_return_power_mode(uint8_t* buf, bool TBD);
  uint8_t build_return_radio_equipment(uint8_t* buf, bool fpv, bool tm);
  uint8_t build_return_parachute_output(
      uint8_t* buf, bool is_parachute_armed, bool is_parachute1_en, bool is_parachut2_en);
  uint8_t build_onboard_battery_voltage(
      uint8_t* buf, uint16_t battery1, uint16_t battery2);
  uint8_t build_GNSS_data(
      uint8_t* buf, uint32_t gnss_time, int32_t latitude, int32_t longitude, uint16_t h_dop, uint8_t n_satellites);
  uint8_t build_return_data_logging(uint8_t* buf, bool enabled);
  uint8_t build_return_dump_flash(uint8_t* buf, bool sd, bool usb);
  uint8_t build_return_handshake(uint8_t* buf);
  uint8_t build_current_time(uint8_t* buf, uint32_t raw_time);
  uint8_t build_ms_since_boot(uint8_t* buf, uint32_t ms);
  
  uint8_t hours, minutes, seconds;
  uint16_t milliseconds;
  uint32_t raw_time;
  bool is_fpv_en, is_tm_en;
  bool is_parachute_armed, is_parachute1_en, is_parachute2_en;
  bool data_logging_en;
  bool dump_sd, dump_usb;
};

template<typename T>
void DataProtocol::write_int_to_array(uint8_t* array, uint8_t* index, T num) {
  for(uint8_t i = 0; i < sizeof(T); i++) {
    array[*index] = num & 0xFF;
    num >>= 8;
    (*index)++;
  }
}

template<typename T>
void DataProtocol::read_array_to_int(uint8_t* array, uint8_t* index, T* num) {
  *num = 0;
  for (uint8_t i = 0; i < sizeof(num); i++) {
    *num += array[*index] << (8 * i);
    (*index)++;
  }
}