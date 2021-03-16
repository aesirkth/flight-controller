/*****************************
GENERATED FILE DO NOT EDIT
******************************/

template <typename T>
void scaledFloat_to_uint(double value, double scale, T *target) {
  *target = value * scale;
}

template <typename T>
void uint_to_scaledFloat(T value, double scale, double *target) {
  *target = value / scale;
}

template <typename T>
void packedFloat_to_uint(double value, double min, double max, T *target) {
  T max_value = ~0;
  double difference = max - min;
  *target = (value - min) / difference * max_value;
}

template <typename T>
void uint_to_packedFloat(T value, double min, double max, double *target) {
  T max_value = ~0;
  double difference = max - min;
  *target = difference * max_value / value;
}

#define ID_TO_LEN(id, length)                                                  \
  switch (id) {                                                                \
  case 16:                                                                     \
    length = 4;                                                                \
    break;                                                                     \
  case 17:                                                                     \
    length = 0;                                                                \
    break;                                                                     \
  case 18:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 19:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 20:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 21:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 22:                                                                     \
    length = 0;                                                                \
    break;                                                                     \
  case 32:                                                                     \
    length = 0;                                                                \
    break;                                                                     \
  case 33:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 34:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 35:                                                                     \
    length = 4;                                                                \
    break;                                                                     \
  case 36:                                                                     \
    length = 15;                                                               \
    break;                                                                     \
  case 37:                                                                     \
    length = 3;                                                                \
    break;                                                                     \
  case 38:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 39:                                                                     \
    length = 1;                                                                \
    break;                                                                     \
  case 40:                                                                     \
    length = 0;                                                                \
    break;                                                                     \
  }

#define PARSE_MESSAGE(id, callback, buf)                                       \
  switch (id) {                                                                \
  case 16:                                                                     \
    ground_station_time_sync __message;                                        \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 17:                                                                     \
    ground_station_set_power_mode __message;                                   \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 18:                                                                     \
    ground_station_set_radio_equipment __message;                              \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 19:                                                                     \
    ground_station_set_parachute_output __message;                             \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 20:                                                                     \
    ground_station_set_data_logging __message;                                 \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 21:                                                                     \
    ground_station_dump_flash_chip __message;                                  \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 22:                                                                     \
    ground_station_handshake __message;                                        \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 32:                                                                     \
    ground_station_return_time_sync __message;                                 \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 33:                                                                     \
    flight_controller_return_radio_equipment __message;                        \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 34:                                                                     \
    flight_controller_return_parachute_output __message;                       \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 35:                                                                     \
    flight_controller_onboard_battery_voltage __message;                       \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 36:                                                                     \
    flight_controller_gnss_data __message;                                     \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 37:                                                                     \
    flight_controller_flight_controller_status __message;                      \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 38:                                                                     \
    flight_controller_return_data_logging __message;                           \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 39:                                                                     \
    flight_controller_return_dump_flash __message;                             \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  case 40:                                                                     \
    flight_controller_return_handshake __message;                              \
    __message_struct.set_bytes(__message);                                     \
    callback(__message);                                                       \
    break;                                                                     \
  }
