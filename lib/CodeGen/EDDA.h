/*****************************
GENERATED FILE DO NOT EDIT
******************************/

#ifndef _EDDA_H
#define _EDDA_H
// if you want to use floats or doubles
#define EDDA_FLOAT_DEF float

#include <math.h>
#include <stdint.h>
#include <string.h>

namespace EDDA {
enum struct fields : uint16_t {
  current_time_ms = 0,
  current_time_us = 1,
  debug_messages_mode = 2,
  debug_status_leds_mode = 3,
  uptime_ms = 4,
  max_tx_queue_size = 5,
  max_rx_queue_size = 6,
  mean_tx_queue_size = 7,
  mean_rx_queue_size = 8,
  round_trip_time_us = 9,
  destination_node = 10,
  receiver_node = 11,
  debug_mode = 12,
  powercan_channel = 13,
  edda_signature = 14,
  request = 15,
  system_state = 16,
  gate_state = 17,
  response = 18,
  result = 19,
  checks_failed = 20,
  checks_performed = 21,
  total_checks = 22,
  w = 23,
  e = 24,
  n = 25,
  h = 26,
  o = 27,
  p = 28,
  r = 29,
  b = 30,
  i = 31,
  t = 32,
  current_ampere = 33,
  voltage_volt = 34,
  power_watt = 35,
  error = 36,
  sensor_index = 37,
  temperature_celsius = 38,
  measurement_index = 39,
  pressure_pascal = 40,
  pressure_mbar = 41,
  coefficient_number = 42,
  coefficient_value = 43,
  board_index = 44,
  resistance_ohm = 45,
  ratio_fraction = 46,
  relative_humidity_percentage = 47,
  is_heater_on = 48,
  acceleration_x_gforce = 49,
  acceleration_y_gforce = 50,
  acceleration_z_gforce = 51,
  sign = 52,
  ambient_light_lux = 53,
  type = 54,
  thread = 55,
  task_time_us = 56,
  truncated_start_time_us = 57,
  loop_time_us = 58,
  bus = 59,
  position_on_board = 60,
  serial_byte0 = 61,
  serial_byte1 = 62,
  serial_byte2 = 63,
  serial_byte3 = 64,
  serial_byte4 = 65,
  serial_byte5 = 66,
  found_family_code = 67,
  found_crc = 68,
  kind = 69,
  channel = 70,
  measurement_reference = 71,
  failure_reason = 72,
  value = 73,
  threshold = 74,
  validity = 75,
  reference_voltage_volt = 76,
  differential_voltage_volt = 77,
  positive_voltage_volt = 78,
  negative_voltage_volt = 79,
  frequency_hertz = 80,
  found_device_address = 81,
  missing_device_address = 82,
  devices_successfully_found = 83,
  addresses_with_error = 84,
  search_time_us = 85,
  location = 86,
  register_address = 87,
  read_data = 88,
  write_data = 89,
  expected_data = 90,
  scanned_address = 91,
  warning_count = 92,
  error_count = 93,
  bus_index = 94,
  position_on_bus = 95,
  byte0 = 96,
  start_time_ms = 97,
  byte1 = 98,
  searched_family_code = 99,
  devices_insuccessfully_found = 100,
  search_time_ms = 101,
  byte2 = 102,
  raw_fault_register = 103,
  byte3 = 104,
  byte4 = 105,
  byte5 = 106,
  byte6 = 107,
};
enum struct messages : uint16_t {
  CurrentTimePing = 0,
  CurrentTimePong = 1,
  SayHi = 2,
  Hello = 3,
  CanStatistics = 4,
  CanLatency = 5,
  SetDebugStatusLedsModeRequest = 6,
  SetDebugMessagesModeRequest = 7,
  PowerCAN_SetDebugMode = 8,
  PowerCAN_GetState = 9,
  PowerCAN_TransitionRequest = 10,
  PowerCAN_Hello = 11,
  PowerCAN_CurrentState = 12,
  PowerCAN_TransitionResponse = 13,
  PowerCAN_CheckResult = 14,
  WenHop = 15,
  WenOrbit = 16,
  PowerInputMeasurement = 17,
  PowerInputMeasurementError = 18,
  ColdSideTemperature = 19,
  RawTransducerVoltage = 20,
  TransducerPressure = 21,
  TransducerError = 22,
  AmbientPressure = 23,
  AmbientPressureCoefficient = 24,
  AmbientPressureError = 25,
  PlatinumSensorTemperature = 26,
  PlatinumSensorResistance = 27,
  PlatinumSensorRatio = 28,
  ThermocoupleTypeKTemperature = 29,
  ThermocoupleColdsideTemperature = 30,
  Humidity = 31,
  HumidityError = 32,
  Acceleration = 33,
  AccelerationError = 34,
  AccelerationSelfTest = 35,
  AmbientLight = 36,
  AmbientLightError = 37,
  TaskInfo = 38,
  LoopInfo = 39,
  OneWireDevicePairedWithSensor = 40,
  OneWireSearchFamilyMismatch = 41,
  OneWireSearchCRCMismatch = 42,
  OneWireSearchFoundDevice = 43,
  PowerCAN_Temperature = 44,
  PowerCAN_Voltage = 45,
  PowerCAN_ChannelMeasurementPower = 46,
  PowerCAN_ChannelMeasurementVoltage = 47,
  PowerCAN_ChannelMeasurementCurrent = 48,
  PowerCAN_LoadMeasurementResistance = 49,
  PowerCAN_LoadMeasurementVoltage = 50,
  PowerCAN_LoadMeasurementPower = 51,
  PowerCAN_LoadMeasurementCurrent = 52,
  PowerCAN_FailedLoadMeasurementValue = 53,
  PowerCAN_FailedLoadMeasurementThreshold = 54,
  PowerCAN_ResistanceMeasurementResistance = 55,
  PowerCAN_ResistanceMeasurementReferenceVoltage = 56,
  PowerCAN_ResistanceMeasurementDifferentialVoltage = 57,
  PowerCAN_ResistanceMeasurementPositiveVoltage = 58,
  PowerCAN_ResistanceMeasurementNegativeVoltage = 59,
  PowerCAN_I2CBusStarted = 60,
  PowerCAN_I2CSearchStarted = 61,
  PowerCAN_I2CSearchFoundDevice = 62,
  PowerCAN_I2CSearchMissingDevice = 63,
  PowerCAN_I2CSearchEnded = 64,
  PowerCAN_LTC2992Error = 65,
  PowerCAN_ADS122C04Error = 66,
  PowerCAN_I2CSearchError = 67,
  PowerCAN_ErrorStatistics = 68,
  DS2482Error = 69,
  PartialDebugMessage1 = 70,
  OneWireSearchStarted = 71,
  I2CBusStarted = 72,
  DS28E18QError = 73,
  PartialDebugMessage2 = 74,
  OneWireSearchEnded = 75,
  I2CSearchStarted = 76,
  MAX31850KError = 77,
  PartialDebugMessage3 = 78,
  OneWireDeviceStartupSuccess = 79,
  I2CSearchError = 80,
  MAX31856Error = 81,
  PartialDebugMessage4 = 82,
  OneWireDeviceStartupFailure = 83,
  I2CSearchFoundDevice = 84,
  MAX31865Error = 85,
  PartialDebugMessage5 = 86,
  I2CSearchEnded = 87,
  PartialDebugMessage6 = 88,
  PartialDebugMessage7 = 89,
};
enum struct categories : uint16_t {
  none = 0,
};
enum struct nodes : uint8_t {
  Flight_Controller = 0,
  Edda_Controller = 1,
  Edda_Telemetry = 2,
  Edda_Pressure_Top = 3,
  Edda_Pressure_Bottom = 4,
  Edda_Power_Control_Boards = 10,
  Ground_Controller = 16,
};
enum struct AccelerationSelfTestDirection : uint8_t {
  Positive = 0,
  Negative = 1,
};
enum struct AccelerationSelfTestResult : uint8_t {
  Success = 0,
  Failure = 1,
};
enum struct ADS122C04Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
};
enum struct DebugMessagesMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct DebugStatusLedsMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct DS2482Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
  BusShortDetected = 7,
  NoDevicesResponded = 8,
  ConfigError = 9,
  WaitOnBusyTimeout = 10,
  ResetFailure = 11,
};
enum struct DS28E18QError : uint8_t {
  RequestCRCFailure = 0,
  ResponseCRCFailure = 1,
  InvalidRequestLength = 2,
  InvalidResponseLength = 3,
  TransactionFailed = 4,
  ExecutionError = 5,
  PowerOnResetError = 6,
  FailedNackAtCommand = 7,
  InvalidInput = 8,
  InvalidResult = 9,
  InvalidStatusByte = 10,
  Unknown = 11,
};
enum struct I2CBus : uint8_t {
  Wire0 = 0,
  Wire1 = 1,
  Wire2 = 2,
  Unknown = 3,
};
enum struct I2CError : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
};
enum struct INA260Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
  UnexpectedManufacturer = 7,
  UnexpectedDie = 8,
  UnexpectedConfiguration = 9,
  UnexpectedMask = 10,
  UnexpectedAlertLimit = 11,
};
enum struct LIS331Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
  FailedSelfTestX = 7,
  FailedSelfTestY = 8,
  FailedSelfTestZ = 9,
  InitializationTimeout = 10,
};
enum struct LoopType : uint8_t {
  MainLoop = 0,
  ChitchatLoop = 1,
  RGBLoop = 2,
  GenericThreadLoop = 3,
  EddaLoop = 4,
};
enum struct LTR303Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
  UnexpectedManufacturer = 7,
  UnexpectedPartNumber = 8,
  ReadOldData = 9,
  DataIsInvalid = 10,
  DataWasReadWithWrongGain = 11,
};
enum struct MAX31850KError : uint8_t {
  CRCMismatch = 0,
  OneWireUnknownError = 1,
  SensorShortToVDD = 2,
  SensorShortToGND = 3,
  SensorOpenCircuit = 4,
};
enum struct MS5803Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
  D1BelowBounds = 7,
  D1AboveBounds = 8,
  D2BelowBounds = 9,
  D2AboveBounds = 10,
  Value_dT_BelowBounds = 11,
  Value_dT_AboveBounds = 12,
  Value_TEMP_BelowBounds = 13,
  Value_TEMP_AboveBounds = 14,
  Value_OFF_BelowBounds = 15,
  Value_OFF_AboveBounds = 16,
  Value_SENS_BelowBounds = 17,
  Value_SENS_AboveBounds = 18,
  Value_P_BelowBounds = 19,
  Value_P_AboveBounds = 20,
};
enum struct Nodes : uint8_t {
  EddaController = 1,
  EddaTelemetry = 2,
  EddaPressureTop = 3,
  EddaPressureBottom = 4,
  GroundController = 16,
  FlightController = 0,
  EddaPowerControlBoards = 10,
};
enum struct OneWireBus : uint8_t {
  Bus0A = 0,
  Bus0B = 1,
  Bus1A = 2,
  Bus1B = 3,
  Unknown = 4,
};
enum struct PlatinumSensorIndex : uint8_t {
  RTD_0 = 0,
  RTD_1 = 1,
  Unknown = 2,
};
enum struct PowerCAN_ADS122C04Error : uint8_t {
  I2CArbitration = 0,
  I2CBus = 1,
  I2CBusy = 2,
  I2CNack = 3,
  I2CUnknownError = 4,
  RegisterWriteFailed = 5,
  RegisterResetFailed = 6,
};
enum struct PowerCAN_ADS122C04ErrorLocation : uint8_t {
  WriteRegister = 0,
  ReadRegister = 1,
  Reset = 2,
  Start = 3,
  Stop = 4,
  ReadData = 5,
  None = 6,
};
enum struct PowerCAN_CheckResult : uint8_t {
  SomeFailed = 0,
  AllFailed = 1,
  AllPassed = 2,
  NotYetDone = 3,
};
enum struct PowerCAN_DebugMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct PowerCAN_GateState : uint8_t {
  Grounded = 0,
  ResistanceMeasurement = 1,
  High = 2,
};
enum struct PowerCAN_I2CBus : uint8_t {
  Wire0 = 0,
  Wire1 = 1,
  Wire2 = 2,
  Unknown = 3,
};
enum struct PowerCAN_I2CError : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
};
enum struct PowerCAN_LoadMeasurementResult : uint8_t {
  Passed = 0,
  Failed = 1,
  Invalid = 2,
};
enum struct PowerCAN_LTC2992Error : uint8_t {
  I2CArbitration = 0,
  I2CBus = 1,
  I2CBusy = 2,
  I2CNack = 3,
  I2CUnknownError = 4,
  RegisterWriteFailed = 5,
  RegisterResetFailed = 6,
};
enum struct PowerCAN_LTC2992ErrorLocation : uint8_t {
  WriteRegister = 0,
  ReadRegister = 1,
  Reset = 2,
  LoadVoltage = 3,
  BoardVoltage = 4,
  LoadCurrent = 5,
  BoardCurrent = 6,
  LoadPower = 7,
  BoardPower = 8,
  GPIO1 = 9,
  GPIO2 = 10,
  GPIO3 = 11,
  GPIO4 = 12,
  None = 13,
};
enum struct PowerCAN_MeasurementChannel : uint8_t {
  Load = 0,
  Board = 1,
};
enum struct PowerCAN_MeasurementFailureReason : uint8_t {
  PowerAboveMax = 0,
  PowerBelowMin = 1,
  CurrentAboveMax = 2,
  CurrentBelowMin = 3,
  VoltageAboveMax = 4,
  VoltageBelowMin = 5,
  ResistanceAboveMax = 6,
  ResistanceBelowMin = 7,
};
enum struct PowerCAN_MeasurementReference : uint8_t {
  Internal = 0,
  ExternalReference = 1,
  Supply = 2,
};
enum struct PowerCAN_ResistanceMeasurementReference : uint8_t {
  Internal = 0,
  ExternalReference = 1,
  Supply = 2,
};
enum struct PowerCAN_ResistanceMeasurementValidity : uint8_t {
  Valid = 0,
  Invalid = 1,
};
enum struct PowerCAN_SystemState : uint8_t {
  Idle = 0,
  Arming = 1,
  Armed = 2,
  Firing = 3,
};
enum struct PowerCAN_TemperatureKind : uint8_t {
  ADC = 0,
  Gates = 1,
};
enum struct PowerCAN_TransitionRequest : uint8_t {
  Arm = 0,
  Disarm = 1,
  Fire = 2,
  StopFire = 3,
};
enum struct PowerCAN_TransitionResponse : uint8_t {
  Success = 0,
  Failure = 1,
};
enum struct PowerCAN_VoltageKind : uint8_t {
  Board3V3 = 0,
};
enum struct PowerCANChannel : uint8_t {
  Channel0_Unknown = 0,
  Channel1_Ignition = 1,
  Channel2_VentSolenoid = 2,
  Channel3_MainValveSolenoid = 3,
  Channel4_Unknown = 4,
  Channel5_Unknown = 5,
  Channel6_Unknown = 6,
  Channel7_Unknown = 7,
  Channel8_Unknown = 8,
  Channel9_Unknown = 9,
  Channel10_Unknown = 10,
  Channel11_Unknown = 11,
  Channel12_Unknown = 12,
  Channel13_Unknown = 13,
  Channel14_Unknown = 14,
  Channel15_Unknown = 15,
  Unknown = 16,
};
enum struct PressureSensorIndex : uint8_t {
  Transducer_0 = 0,
  Transducer_1 = 1,
  Transducer_2 = 2,
  Transducer_3 = 3,
};
enum struct SHT31Error : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
};
enum struct TaskType : uint8_t {
  Startup = 0,
  CANSetup = 1,
  PeripheralSetup = 2,
  SensorSetup = 3,
  ThreadSetup = 4,
  RGBSetup = 5,
  MainLoop = 6,
  ChitchatLoop = 7,
  RGBLoop = 8,
  GenericThreadLoop = 9,
  EddaLoop = 10,
  Wire0Start = 11,
  Wire1Start = 12,
  Wire2Start = 13,
  StartTemperatureBusA = 14,
  StartTemperatureBusB = 15,
};
enum struct TemperatureBoardIndex : uint8_t {
  Board0 = 0,
  Board1 = 1,
};
enum struct TemperatureSensorIndex : uint8_t {
  InternalTemperature = 0,
  PowerRegulator = 1,
  AmbientPressureSensor = 2,
  HumiditySensor = 3,
  Unknown = 4,
};
enum struct ThermocoupleIndex : uint8_t {
  Therm_0 = 0,
  Therm_1 = 1,
  Therm_2 = 2,
  Therm_3 = 3,
  Therm_4 = 4,
  Therm_5 = 5,
  Therm_6 = 6,
  Therm_7 = 7,
  Therm_8 = 8,
  Therm_9 = 9,
  Unknown = 10,
};
enum struct Thread : uint8_t {
  Thread0 = 0,
  Thread1 = 1,
  Thread2 = 2,
  Thread3 = 3,
  Thread4 = 4,
  Thread5 = 5,
  Thread6 = 6,
  Thread7 = 7,
  Unknown = 8,
};
enum struct TransducerError : uint8_t {
  None = 0,
  CRCMismatch = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  I2CTransmitBufferFull = 6,
  Undervoltage = 7,
  Overvoltage = 8,
};
enum struct TransducerVoltageMeasurementIndex : uint8_t {
  Transducer_0 = 0,
  Transducer_1 = 1,
  Transducer_2 = 2,
  Transducer_3 = 3,
  Voltage_5V = 4,
  Voltage_Ref = 5,
  Unknown = 6,
};
template <typename T>
void scaledFloat_to_uint(EDDA_FLOAT_DEF value, EDDA_FLOAT_DEF scale, T *out) {
  *out = value * scale;
}

template <typename T>
void uint_to_scaledFloat(T value, EDDA_FLOAT_DEF scale, EDDA_FLOAT_DEF *out) {
  *out = value / scale;
}

template <typename T>
void packedFloat_to_uint(EDDA_FLOAT_DEF value, EDDA_FLOAT_DEF minValue,
                         EDDA_FLOAT_DEF maxValue, T *out) {
  T intMax = ~0;
  if (value < minValue) {
    *out = 0;
    return;
  }
  if (value > maxValue) {
    *out = intMax;
    return;
  }
  EDDA_FLOAT_DEF ratio = (value - minValue) / (maxValue - minValue);
  *out = 1 + ((intMax - 2)) * ratio;
}

template <typename T>
void uint_to_packedFloat(T value, EDDA_FLOAT_DEF minValue,
                         EDDA_FLOAT_DEF maxValue, EDDA_FLOAT_DEF *out) {
  T intMax = ~0;
  if (value <= 0) {
    *out = minValue - 1.0;
    return;
  }
  if (value >= intMax) {
    *out = maxValue + 1.0;
    return;
  }
  EDDA_FLOAT_DEF ratio = (value - 1) / (intMax - 2);
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
class CurrentTimePing_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class CurrentTimePong_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class SayHi_from_Ground_Controller_to_Edda_Controller : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 2;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Ground_Controller_to_Edda_Telemetry : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 2;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Ground_Controller_to_Edda_Pressure_Top : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 2;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Ground_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 2;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class Hello_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 3;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Telemetry_to_Ground_Controller : public MessageBase {
public:
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 4;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Pressure_Top_to_Ground_Controller : public MessageBase {
public:
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 5;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 6;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class CanStatistics_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t max_tx_queue_size;
  static_assert((sizeof(max_tx_queue_size) == 2), "invalid size");
  uint16_t max_rx_queue_size;
  static_assert((sizeof(max_rx_queue_size) == 2), "invalid size");
  uint16_t mean_tx_queue_size;
  static_assert((sizeof(mean_tx_queue_size) == 2), "invalid size");
  uint16_t mean_rx_queue_size;
  static_assert((sizeof(mean_rx_queue_size) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 7;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_max_tx_queue_size(uint16_t value) { max_tx_queue_size = value; }
  void set_max_rx_queue_size(uint16_t value) { max_rx_queue_size = value; }
  void set_mean_tx_queue_size(uint16_t value) { mean_tx_queue_size = value; }
  void set_mean_rx_queue_size(uint16_t value) { mean_rx_queue_size = value; }
  uint16_t get_max_tx_queue_size() { return max_tx_queue_size; }
  uint16_t get_max_rx_queue_size() { return max_rx_queue_size; }
  uint16_t get_mean_tx_queue_size() { return mean_tx_queue_size; }
  uint16_t get_mean_rx_queue_size() { return mean_rx_queue_size; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &max_tx_queue_size, sizeof(max_tx_queue_size));
    *index += sizeof(max_tx_queue_size);
    memcpy(buf + *index, &max_rx_queue_size, sizeof(max_rx_queue_size));
    *index += sizeof(max_rx_queue_size);
    memcpy(buf + *index, &mean_tx_queue_size, sizeof(mean_tx_queue_size));
    *index += sizeof(mean_tx_queue_size);
    memcpy(buf + *index, &mean_rx_queue_size, sizeof(mean_rx_queue_size));
    *index += sizeof(mean_rx_queue_size);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&max_tx_queue_size, buf + index, sizeof(max_tx_queue_size));
    index += sizeof(max_tx_queue_size);
    memcpy(&max_rx_queue_size, buf + index, sizeof(max_rx_queue_size));
    index += sizeof(max_rx_queue_size);
    memcpy(&mean_tx_queue_size, buf + index, sizeof(mean_tx_queue_size));
    index += sizeof(mean_tx_queue_size);
    memcpy(&mean_rx_queue_size, buf + index, sizeof(mean_rx_queue_size));
    index += sizeof(mean_rx_queue_size);
  }
};

class CanStatistics_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t max_tx_queue_size;
  static_assert((sizeof(max_tx_queue_size) == 2), "invalid size");
  uint16_t max_rx_queue_size;
  static_assert((sizeof(max_rx_queue_size) == 2), "invalid size");
  uint16_t mean_tx_queue_size;
  static_assert((sizeof(mean_tx_queue_size) == 2), "invalid size");
  uint16_t mean_rx_queue_size;
  static_assert((sizeof(mean_rx_queue_size) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_max_tx_queue_size(uint16_t value) { max_tx_queue_size = value; }
  void set_max_rx_queue_size(uint16_t value) { max_rx_queue_size = value; }
  void set_mean_tx_queue_size(uint16_t value) { mean_tx_queue_size = value; }
  void set_mean_rx_queue_size(uint16_t value) { mean_rx_queue_size = value; }
  uint16_t get_max_tx_queue_size() { return max_tx_queue_size; }
  uint16_t get_max_rx_queue_size() { return max_rx_queue_size; }
  uint16_t get_mean_tx_queue_size() { return mean_tx_queue_size; }
  uint16_t get_mean_rx_queue_size() { return mean_rx_queue_size; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &max_tx_queue_size, sizeof(max_tx_queue_size));
    *index += sizeof(max_tx_queue_size);
    memcpy(buf + *index, &max_rx_queue_size, sizeof(max_rx_queue_size));
    *index += sizeof(max_rx_queue_size);
    memcpy(buf + *index, &mean_tx_queue_size, sizeof(mean_tx_queue_size));
    *index += sizeof(mean_tx_queue_size);
    memcpy(buf + *index, &mean_rx_queue_size, sizeof(mean_rx_queue_size));
    *index += sizeof(mean_rx_queue_size);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&max_tx_queue_size, buf + index, sizeof(max_tx_queue_size));
    index += sizeof(max_tx_queue_size);
    memcpy(&max_rx_queue_size, buf + index, sizeof(max_rx_queue_size));
    index += sizeof(max_rx_queue_size);
    memcpy(&mean_tx_queue_size, buf + index, sizeof(mean_tx_queue_size));
    index += sizeof(mean_tx_queue_size);
    memcpy(&mean_rx_queue_size, buf + index, sizeof(mean_rx_queue_size));
    index += sizeof(mean_rx_queue_size);
  }
};

class CanStatistics_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t max_tx_queue_size;
  static_assert((sizeof(max_tx_queue_size) == 2), "invalid size");
  uint16_t max_rx_queue_size;
  static_assert((sizeof(max_rx_queue_size) == 2), "invalid size");
  uint16_t mean_tx_queue_size;
  static_assert((sizeof(mean_tx_queue_size) == 2), "invalid size");
  uint16_t mean_rx_queue_size;
  static_assert((sizeof(mean_rx_queue_size) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_max_tx_queue_size(uint16_t value) { max_tx_queue_size = value; }
  void set_max_rx_queue_size(uint16_t value) { max_rx_queue_size = value; }
  void set_mean_tx_queue_size(uint16_t value) { mean_tx_queue_size = value; }
  void set_mean_rx_queue_size(uint16_t value) { mean_rx_queue_size = value; }
  uint16_t get_max_tx_queue_size() { return max_tx_queue_size; }
  uint16_t get_max_rx_queue_size() { return max_rx_queue_size; }
  uint16_t get_mean_tx_queue_size() { return mean_tx_queue_size; }
  uint16_t get_mean_rx_queue_size() { return mean_rx_queue_size; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &max_tx_queue_size, sizeof(max_tx_queue_size));
    *index += sizeof(max_tx_queue_size);
    memcpy(buf + *index, &max_rx_queue_size, sizeof(max_rx_queue_size));
    *index += sizeof(max_rx_queue_size);
    memcpy(buf + *index, &mean_tx_queue_size, sizeof(mean_tx_queue_size));
    *index += sizeof(mean_tx_queue_size);
    memcpy(buf + *index, &mean_rx_queue_size, sizeof(mean_rx_queue_size));
    *index += sizeof(mean_rx_queue_size);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&max_tx_queue_size, buf + index, sizeof(max_tx_queue_size));
    index += sizeof(max_tx_queue_size);
    memcpy(&max_rx_queue_size, buf + index, sizeof(max_rx_queue_size));
    index += sizeof(max_rx_queue_size);
    memcpy(&mean_tx_queue_size, buf + index, sizeof(mean_tx_queue_size));
    index += sizeof(mean_tx_queue_size);
    memcpy(&mean_rx_queue_size, buf + index, sizeof(mean_rx_queue_size));
    index += sizeof(mean_rx_queue_size);
  }
};

class CanStatistics_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t max_tx_queue_size;
  static_assert((sizeof(max_tx_queue_size) == 2), "invalid size");
  uint16_t max_rx_queue_size;
  static_assert((sizeof(max_rx_queue_size) == 2), "invalid size");
  uint16_t mean_tx_queue_size;
  static_assert((sizeof(mean_tx_queue_size) == 2), "invalid size");
  uint16_t mean_rx_queue_size;
  static_assert((sizeof(mean_rx_queue_size) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_max_tx_queue_size(uint16_t value) { max_tx_queue_size = value; }
  void set_max_rx_queue_size(uint16_t value) { max_rx_queue_size = value; }
  void set_mean_tx_queue_size(uint16_t value) { mean_tx_queue_size = value; }
  void set_mean_rx_queue_size(uint16_t value) { mean_rx_queue_size = value; }
  uint16_t get_max_tx_queue_size() { return max_tx_queue_size; }
  uint16_t get_max_rx_queue_size() { return max_rx_queue_size; }
  uint16_t get_mean_tx_queue_size() { return mean_tx_queue_size; }
  uint16_t get_mean_rx_queue_size() { return mean_rx_queue_size; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &max_tx_queue_size, sizeof(max_tx_queue_size));
    *index += sizeof(max_tx_queue_size);
    memcpy(buf + *index, &max_rx_queue_size, sizeof(max_rx_queue_size));
    *index += sizeof(max_rx_queue_size);
    memcpy(buf + *index, &mean_tx_queue_size, sizeof(mean_tx_queue_size));
    *index += sizeof(mean_tx_queue_size);
    memcpy(buf + *index, &mean_rx_queue_size, sizeof(mean_rx_queue_size));
    *index += sizeof(mean_rx_queue_size);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&max_tx_queue_size, buf + index, sizeof(max_tx_queue_size));
    index += sizeof(max_tx_queue_size);
    memcpy(&max_rx_queue_size, buf + index, sizeof(max_rx_queue_size));
    index += sizeof(max_rx_queue_size);
    memcpy(&mean_tx_queue_size, buf + index, sizeof(mean_tx_queue_size));
    index += sizeof(mean_tx_queue_size);
    memcpy(&mean_rx_queue_size, buf + index, sizeof(mean_rx_queue_size));
    index += sizeof(mean_rx_queue_size);
  }
};

class CanStatistics_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t max_tx_queue_size;
  static_assert((sizeof(max_tx_queue_size) == 2), "invalid size");
  uint16_t max_rx_queue_size;
  static_assert((sizeof(max_rx_queue_size) == 2), "invalid size");
  uint16_t mean_tx_queue_size;
  static_assert((sizeof(mean_tx_queue_size) == 2), "invalid size");
  uint16_t mean_rx_queue_size;
  static_assert((sizeof(mean_rx_queue_size) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_max_tx_queue_size(uint16_t value) { max_tx_queue_size = value; }
  void set_max_rx_queue_size(uint16_t value) { max_rx_queue_size = value; }
  void set_mean_tx_queue_size(uint16_t value) { mean_tx_queue_size = value; }
  void set_mean_rx_queue_size(uint16_t value) { mean_rx_queue_size = value; }
  uint16_t get_max_tx_queue_size() { return max_tx_queue_size; }
  uint16_t get_max_rx_queue_size() { return max_rx_queue_size; }
  uint16_t get_mean_tx_queue_size() { return mean_tx_queue_size; }
  uint16_t get_mean_rx_queue_size() { return mean_rx_queue_size; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &max_tx_queue_size, sizeof(max_tx_queue_size));
    *index += sizeof(max_tx_queue_size);
    memcpy(buf + *index, &max_rx_queue_size, sizeof(max_rx_queue_size));
    *index += sizeof(max_rx_queue_size);
    memcpy(buf + *index, &mean_tx_queue_size, sizeof(mean_tx_queue_size));
    *index += sizeof(mean_tx_queue_size);
    memcpy(buf + *index, &mean_rx_queue_size, sizeof(mean_rx_queue_size));
    *index += sizeof(mean_rx_queue_size);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&max_tx_queue_size, buf + index, sizeof(max_tx_queue_size));
    index += sizeof(max_tx_queue_size);
    memcpy(&max_rx_queue_size, buf + index, sizeof(max_rx_queue_size));
    index += sizeof(max_rx_queue_size);
    memcpy(&mean_tx_queue_size, buf + index, sizeof(mean_tx_queue_size));
    index += sizeof(mean_tx_queue_size);
    memcpy(&mean_rx_queue_size, buf + index, sizeof(mean_rx_queue_size));
    index += sizeof(mean_rx_queue_size);
  }
};

class CanLatency_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t round_trip_time_us;
  static_assert((sizeof(round_trip_time_us) == 4), "invalid size");
  enum Nodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_round_trip_time_us(uint32_t value) { round_trip_time_us = value; }
  void set_destination_node(enum Nodes value) { destination_node = value; }
  uint32_t get_round_trip_time_us() { return round_trip_time_us; }
  enum Nodes get_destination_node() { return destination_node; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &round_trip_time_us, sizeof(round_trip_time_us));
    *index += sizeof(round_trip_time_us);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&round_trip_time_us, buf + index, sizeof(round_trip_time_us));
    index += sizeof(round_trip_time_us);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
  }
};

class CanLatency_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t round_trip_time_us;
  static_assert((sizeof(round_trip_time_us) == 4), "invalid size");
  enum Nodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_round_trip_time_us(uint32_t value) { round_trip_time_us = value; }
  void set_destination_node(enum Nodes value) { destination_node = value; }
  uint32_t get_round_trip_time_us() { return round_trip_time_us; }
  enum Nodes get_destination_node() { return destination_node; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &round_trip_time_us, sizeof(round_trip_time_us));
    *index += sizeof(round_trip_time_us);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&round_trip_time_us, buf + index, sizeof(round_trip_time_us));
    index += sizeof(round_trip_time_us);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
  }
};

class SetDebugStatusLedsModeRequest_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugStatusLedsModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
  }
};

class SetDebugStatusLedsModeRequest_from_Ground_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugStatusLedsModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
  }
};

class SetDebugStatusLedsModeRequest_from_Ground_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugStatusLedsModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
  }
};

class
    SetDebugStatusLedsModeRequest_from_Ground_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugStatusLedsMode debug_status_leds_mode;
  static_assert((sizeof(debug_status_leds_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugStatusLedsModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_status_leds_mode(enum DebugStatusLedsMode value) {
    debug_status_leds_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugStatusLedsMode get_debug_status_leds_mode() {
    return debug_status_leds_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_status_leds_mode,
           sizeof(debug_status_leds_mode));
    *index += sizeof(debug_status_leds_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_status_leds_mode, buf + index,
           sizeof(debug_status_leds_mode));
    index += sizeof(debug_status_leds_mode);
  }
};

class SetDebugMessagesModeRequest_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugMessagesModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
  }
};

class SetDebugMessagesModeRequest_from_Ground_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugMessagesModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
  }
};

class SetDebugMessagesModeRequest_from_Ground_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugMessagesModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
  }
};

class SetDebugMessagesModeRequest_from_Ground_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  enum Nodes receiver_node;
  static_assert((sizeof(receiver_node) == 1), "invalid size");
  enum DebugMessagesMode debug_messages_mode;
  static_assert((sizeof(debug_messages_mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetDebugMessagesModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node(enum Nodes value) { receiver_node = value; }
  void set_debug_messages_mode(enum DebugMessagesMode value) {
    debug_messages_mode = value;
  }
  enum Nodes get_receiver_node() { return receiver_node; }
  enum DebugMessagesMode get_debug_messages_mode() {
    return debug_messages_mode;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node, sizeof(receiver_node));
    *index += sizeof(receiver_node);
    memcpy(buf + *index, &debug_messages_mode, sizeof(debug_messages_mode));
    *index += sizeof(debug_messages_mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node, buf + index, sizeof(receiver_node));
    index += sizeof(receiver_node);
    memcpy(&debug_messages_mode, buf + index, sizeof(debug_messages_mode));
    index += sizeof(debug_messages_mode);
  }
};

class PowerCAN_SetDebugMode_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  enum PowerCAN_DebugMode debug_mode;
  static_assert((sizeof(debug_mode) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_SetDebugMode;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_mode(enum PowerCAN_DebugMode value) { debug_mode = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_DebugMode get_debug_mode() { return debug_mode; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_mode, sizeof(debug_mode));
    *index += sizeof(debug_mode);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_mode, buf + index, sizeof(debug_mode));
    index += sizeof(debug_mode);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_SetDebugMode_from_Ground_Controller_to_Edda_Power_Control_Boards
    : public MessageBase {
public:
  enum PowerCAN_DebugMode debug_mode;
  static_assert((sizeof(debug_mode) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_SetDebugMode;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_mode(enum PowerCAN_DebugMode value) { debug_mode = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_DebugMode get_debug_mode() { return debug_mode; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_mode, sizeof(debug_mode));
    *index += sizeof(debug_mode);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_mode, buf + index, sizeof(debug_mode));
    index += sizeof(debug_mode);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_GetState_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerCAN_GetState;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 51;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_GetState_from_Ground_Controller_to_Edda_Power_Control_Boards
    : public MessageBase {
public:
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerCAN_GetState;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 51;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_TransitionRequest_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum PowerCAN_TransitionRequest request;
  static_assert((sizeof(request) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PowerCAN_TransitionRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 52;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_request(enum PowerCAN_TransitionRequest value) { request = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  uint16_t get_edda_signature() { return edda_signature; }
  enum PowerCAN_TransitionRequest get_request() { return request; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_TransitionRequest_from_Ground_Controller_to_Edda_Power_Control_Boards
    : public MessageBase {
public:
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum PowerCAN_TransitionRequest request;
  static_assert((sizeof(request) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PowerCAN_TransitionRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 52;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_request(enum PowerCAN_TransitionRequest value) { request = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  uint16_t get_edda_signature() { return edda_signature; }
  enum PowerCAN_TransitionRequest get_request() { return request; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_SetDebugMode_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_DebugMode debug_mode;
  static_assert((sizeof(debug_mode) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_SetDebugMode;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 64;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_mode(enum PowerCAN_DebugMode value) { debug_mode = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_DebugMode get_debug_mode() { return debug_mode; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_mode, sizeof(debug_mode));
    *index += sizeof(debug_mode);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_mode, buf + index, sizeof(debug_mode));
    index += sizeof(debug_mode);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_SetDebugMode_from_Edda_Controller_to_Edda_Power_Control_Boards
    : public MessageBase {
public:
  enum PowerCAN_DebugMode debug_mode;
  static_assert((sizeof(debug_mode) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_SetDebugMode;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 64;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_mode(enum PowerCAN_DebugMode value) { debug_mode = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_DebugMode get_debug_mode() { return debug_mode; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_mode, sizeof(debug_mode));
    *index += sizeof(debug_mode);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_mode, buf + index, sizeof(debug_mode));
    index += sizeof(debug_mode);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_GetState_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerCAN_GetState;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 65;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_GetState_from_Edda_Controller_to_Edda_Power_Control_Boards
    : public MessageBase {
public:
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerCAN_GetState;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 65;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_TransitionRequest_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum PowerCAN_TransitionRequest request;
  static_assert((sizeof(request) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PowerCAN_TransitionRequest;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 66;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_request(enum PowerCAN_TransitionRequest value) { request = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  uint16_t get_edda_signature() { return edda_signature; }
  enum PowerCAN_TransitionRequest get_request() { return request; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_TransitionRequest_from_Edda_Controller_to_Edda_Power_Control_Boards
    : public MessageBase {
public:
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum PowerCAN_TransitionRequest request;
  static_assert((sizeof(request) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PowerCAN_TransitionRequest;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 66;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_request(enum PowerCAN_TransitionRequest value) { request = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  uint16_t get_edda_signature() { return edda_signature; }
  enum PowerCAN_TransitionRequest get_request() { return request; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_Hello_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_DebugMode debug_mode;
  static_assert((sizeof(debug_mode) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 67;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debug_mode(enum PowerCAN_DebugMode value) { debug_mode = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_DebugMode get_debug_mode() { return debug_mode; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debug_mode, sizeof(debug_mode));
    *index += sizeof(debug_mode);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debug_mode, buf + index, sizeof(debug_mode));
    index += sizeof(debug_mode);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_CurrentState_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_SystemState system_state;
  static_assert((sizeof(system_state) == 1), "invalid size");
  enum PowerCAN_GateState gate_state;
  static_assert((sizeof(gate_state) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PowerCAN_CurrentState;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 68;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_system_state(enum PowerCAN_SystemState value) {
    system_state = value;
  }
  void set_gate_state(enum PowerCAN_GateState value) { gate_state = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_SystemState get_system_state() { return system_state; }
  enum PowerCAN_GateState get_gate_state() { return gate_state; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &system_state, sizeof(system_state));
    *index += sizeof(system_state);
    memcpy(buf + *index, &gate_state, sizeof(gate_state));
    *index += sizeof(gate_state);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&system_state, buf + index, sizeof(system_state));
    index += sizeof(system_state);
    memcpy(&gate_state, buf + index, sizeof(gate_state));
    index += sizeof(gate_state);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_TransitionResponse_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_TransitionRequest request;
  static_assert((sizeof(request) == 1), "invalid size");
  enum PowerCAN_TransitionResponse response;
  static_assert((sizeof(response) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PowerCAN_TransitionResponse;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 69;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_request(enum PowerCAN_TransitionRequest value) { request = value; }
  void set_response(enum PowerCAN_TransitionResponse value) {
    response = value;
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_TransitionRequest get_request() { return request; }
  enum PowerCAN_TransitionResponse get_response() { return response; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
    memcpy(buf + *index, &response, sizeof(response));
    *index += sizeof(response);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
    memcpy(&response, buf + index, sizeof(response));
    index += sizeof(response);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_CheckResult_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_CheckResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint8_t checks_failed;
  static_assert((sizeof(checks_failed) == 1), "invalid size");
  uint8_t checks_performed;
  static_assert((sizeof(checks_performed) == 1), "invalid size");
  uint8_t total_checks;
  static_assert((sizeof(total_checks) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PowerCAN_CheckResult;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 70;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_result(enum PowerCAN_CheckResult value) { result = value; }
  void set_checks_failed(uint8_t value) { checks_failed = value; }
  void set_checks_performed(uint8_t value) { checks_performed = value; }
  void set_total_checks(uint8_t value) { total_checks = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_CheckResult get_result() { return result; }
  uint8_t get_checks_failed() { return checks_failed; }
  uint8_t get_checks_performed() { return checks_performed; }
  uint8_t get_total_checks() { return total_checks; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
    memcpy(buf + *index, &checks_failed, sizeof(checks_failed));
    *index += sizeof(checks_failed);
    memcpy(buf + *index, &checks_performed, sizeof(checks_performed));
    *index += sizeof(checks_performed);
    memcpy(buf + *index, &total_checks, sizeof(total_checks));
    *index += sizeof(total_checks);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
    memcpy(&checks_failed, buf + index, sizeof(checks_failed));
    index += sizeof(checks_failed);
    memcpy(&checks_performed, buf + index, sizeof(checks_performed));
    index += sizeof(checks_performed);
    memcpy(&total_checks, buf + index, sizeof(total_checks));
    index += sizeof(total_checks);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class CurrentTimePing_from_Edda_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class CurrentTimePing_from_Edda_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class CurrentTimePing_from_Edda_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class CurrentTimePong_from_Edda_Telemetry_to_Edda_Controller
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 145;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class CurrentTimePong_from_Edda_Pressure_Top_to_Edda_Controller
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 146;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class CurrentTimePong_from_Edda_Pressure_Bottom_to_Edda_Controller
    : public MessageBase {
public:
  uint32_t current_time_ms;
  static_assert((sizeof(current_time_ms) == 4), "invalid size");
  uint32_t current_time_us;
  static_assert((sizeof(current_time_us) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 147;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_time_ms(uint32_t value) { current_time_ms = value; }
  void set_current_time_us(uint32_t value) { current_time_us = value; }
  uint32_t get_current_time_ms() { return current_time_ms; }
  uint32_t get_current_time_us() { return current_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_time_ms, sizeof(current_time_ms));
    *index += sizeof(current_time_ms);
    memcpy(buf + *index, &current_time_us, sizeof(current_time_us));
    *index += sizeof(current_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_time_ms, buf + index, sizeof(current_time_ms));
    index += sizeof(current_time_ms);
    memcpy(&current_time_us, buf + index, sizeof(current_time_us));
    index += sizeof(current_time_us);
  }
};

class SayHi_from_Edda_Controller_to_Edda_Controller : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 148;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Edda_Controller_to_Edda_Telemetry : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 148;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Edda_Controller_to_Edda_Pressure_Top : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 148;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Edda_Controller_to_Edda_Pressure_Bottom : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 148;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class WenHop_from_Edda_Controller_to_Flight_Controller : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t h;
  static_assert((sizeof(h) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t p;
  static_assert((sizeof(p) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::WenHop;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 149;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_h(uint8_t value) { h = value; }
  void set_o(uint8_t value) { o = value; }
  void set_p(uint8_t value) { p = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_h() { return h; }
  uint8_t get_o() { return o; }
  uint8_t get_p() { return p; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &h, sizeof(h));
    *index += sizeof(h);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &p, sizeof(p));
    *index += sizeof(p);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&h, buf + index, sizeof(h));
    index += sizeof(h);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&p, buf + index, sizeof(p));
    index += sizeof(p);
  }
};

class WenHop_from_Edda_Telemetry_to_Flight_Controller : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t h;
  static_assert((sizeof(h) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t p;
  static_assert((sizeof(p) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::WenHop;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 150;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_h(uint8_t value) { h = value; }
  void set_o(uint8_t value) { o = value; }
  void set_p(uint8_t value) { p = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_h() { return h; }
  uint8_t get_o() { return o; }
  uint8_t get_p() { return p; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &h, sizeof(h));
    *index += sizeof(h);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &p, sizeof(p));
    *index += sizeof(p);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&h, buf + index, sizeof(h));
    index += sizeof(h);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&p, buf + index, sizeof(p));
    index += sizeof(p);
  }
};

class WenHop_from_Edda_Pressure_Top_to_Flight_Controller : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t h;
  static_assert((sizeof(h) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t p;
  static_assert((sizeof(p) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::WenHop;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 151;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_h(uint8_t value) { h = value; }
  void set_o(uint8_t value) { o = value; }
  void set_p(uint8_t value) { p = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_h() { return h; }
  uint8_t get_o() { return o; }
  uint8_t get_p() { return p; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &h, sizeof(h));
    *index += sizeof(h);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &p, sizeof(p));
    *index += sizeof(p);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&h, buf + index, sizeof(h));
    index += sizeof(h);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&p, buf + index, sizeof(p));
    index += sizeof(p);
  }
};

class WenHop_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t h;
  static_assert((sizeof(h) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t p;
  static_assert((sizeof(p) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::WenHop;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 152;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_h(uint8_t value) { h = value; }
  void set_o(uint8_t value) { o = value; }
  void set_p(uint8_t value) { p = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_h() { return h; }
  uint8_t get_o() { return o; }
  uint8_t get_p() { return p; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &h, sizeof(h));
    *index += sizeof(h);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &p, sizeof(p));
    *index += sizeof(p);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&h, buf + index, sizeof(h));
    index += sizeof(h);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&p, buf + index, sizeof(p));
    index += sizeof(p);
  }
};

class WenOrbit_from_Edda_Controller_to_Flight_Controller : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t r;
  static_assert((sizeof(r) == 1), "invalid size");
  uint8_t b;
  static_assert((sizeof(b) == 1), "invalid size");
  uint8_t i;
  static_assert((sizeof(i) == 1), "invalid size");
  uint8_t t;
  static_assert((sizeof(t) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::WenOrbit;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 153;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_o(uint8_t value) { o = value; }
  void set_r(uint8_t value) { r = value; }
  void set_b(uint8_t value) { b = value; }
  void set_i(uint8_t value) { i = value; }
  void set_t(uint8_t value) { t = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_o() { return o; }
  uint8_t get_r() { return r; }
  uint8_t get_b() { return b; }
  uint8_t get_i() { return i; }
  uint8_t get_t() { return t; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &r, sizeof(r));
    *index += sizeof(r);
    memcpy(buf + *index, &b, sizeof(b));
    *index += sizeof(b);
    memcpy(buf + *index, &i, sizeof(i));
    *index += sizeof(i);
    memcpy(buf + *index, &t, sizeof(t));
    *index += sizeof(t);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&r, buf + index, sizeof(r));
    index += sizeof(r);
    memcpy(&b, buf + index, sizeof(b));
    index += sizeof(b);
    memcpy(&i, buf + index, sizeof(i));
    index += sizeof(i);
    memcpy(&t, buf + index, sizeof(t));
    index += sizeof(t);
  }
};

class WenOrbit_from_Edda_Telemetry_to_Flight_Controller : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t r;
  static_assert((sizeof(r) == 1), "invalid size");
  uint8_t b;
  static_assert((sizeof(b) == 1), "invalid size");
  uint8_t i;
  static_assert((sizeof(i) == 1), "invalid size");
  uint8_t t;
  static_assert((sizeof(t) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::WenOrbit;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 154;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_o(uint8_t value) { o = value; }
  void set_r(uint8_t value) { r = value; }
  void set_b(uint8_t value) { b = value; }
  void set_i(uint8_t value) { i = value; }
  void set_t(uint8_t value) { t = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_o() { return o; }
  uint8_t get_r() { return r; }
  uint8_t get_b() { return b; }
  uint8_t get_i() { return i; }
  uint8_t get_t() { return t; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &r, sizeof(r));
    *index += sizeof(r);
    memcpy(buf + *index, &b, sizeof(b));
    *index += sizeof(b);
    memcpy(buf + *index, &i, sizeof(i));
    *index += sizeof(i);
    memcpy(buf + *index, &t, sizeof(t));
    *index += sizeof(t);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&r, buf + index, sizeof(r));
    index += sizeof(r);
    memcpy(&b, buf + index, sizeof(b));
    index += sizeof(b);
    memcpy(&i, buf + index, sizeof(i));
    index += sizeof(i);
    memcpy(&t, buf + index, sizeof(t));
    index += sizeof(t);
  }
};

class WenOrbit_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t r;
  static_assert((sizeof(r) == 1), "invalid size");
  uint8_t b;
  static_assert((sizeof(b) == 1), "invalid size");
  uint8_t i;
  static_assert((sizeof(i) == 1), "invalid size");
  uint8_t t;
  static_assert((sizeof(t) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::WenOrbit;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 155;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_o(uint8_t value) { o = value; }
  void set_r(uint8_t value) { r = value; }
  void set_b(uint8_t value) { b = value; }
  void set_i(uint8_t value) { i = value; }
  void set_t(uint8_t value) { t = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_o() { return o; }
  uint8_t get_r() { return r; }
  uint8_t get_b() { return b; }
  uint8_t get_i() { return i; }
  uint8_t get_t() { return t; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &r, sizeof(r));
    *index += sizeof(r);
    memcpy(buf + *index, &b, sizeof(b));
    *index += sizeof(b);
    memcpy(buf + *index, &i, sizeof(i));
    *index += sizeof(i);
    memcpy(buf + *index, &t, sizeof(t));
    *index += sizeof(t);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&r, buf + index, sizeof(r));
    index += sizeof(r);
    memcpy(&b, buf + index, sizeof(b));
    index += sizeof(b);
    memcpy(&i, buf + index, sizeof(i));
    index += sizeof(i);
    memcpy(&t, buf + index, sizeof(t));
    index += sizeof(t);
  }
};

class WenOrbit_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t w;
  static_assert((sizeof(w) == 1), "invalid size");
  uint8_t e;
  static_assert((sizeof(e) == 1), "invalid size");
  uint8_t n;
  static_assert((sizeof(n) == 1), "invalid size");
  uint8_t o;
  static_assert((sizeof(o) == 1), "invalid size");
  uint8_t r;
  static_assert((sizeof(r) == 1), "invalid size");
  uint8_t b;
  static_assert((sizeof(b) == 1), "invalid size");
  uint8_t i;
  static_assert((sizeof(i) == 1), "invalid size");
  uint8_t t;
  static_assert((sizeof(t) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::WenOrbit;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 156;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_w(uint8_t value) { w = value; }
  void set_e(uint8_t value) { e = value; }
  void set_n(uint8_t value) { n = value; }
  void set_o(uint8_t value) { o = value; }
  void set_r(uint8_t value) { r = value; }
  void set_b(uint8_t value) { b = value; }
  void set_i(uint8_t value) { i = value; }
  void set_t(uint8_t value) { t = value; }
  uint8_t get_w() { return w; }
  uint8_t get_e() { return e; }
  uint8_t get_n() { return n; }
  uint8_t get_o() { return o; }
  uint8_t get_r() { return r; }
  uint8_t get_b() { return b; }
  uint8_t get_i() { return i; }
  uint8_t get_t() { return t; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &w, sizeof(w));
    *index += sizeof(w);
    memcpy(buf + *index, &e, sizeof(e));
    *index += sizeof(e);
    memcpy(buf + *index, &n, sizeof(n));
    *index += sizeof(n);
    memcpy(buf + *index, &o, sizeof(o));
    *index += sizeof(o);
    memcpy(buf + *index, &r, sizeof(r));
    *index += sizeof(r);
    memcpy(buf + *index, &b, sizeof(b));
    *index += sizeof(b);
    memcpy(buf + *index, &i, sizeof(i));
    *index += sizeof(i);
    memcpy(buf + *index, &t, sizeof(t));
    *index += sizeof(t);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&w, buf + index, sizeof(w));
    index += sizeof(w);
    memcpy(&e, buf + index, sizeof(e));
    index += sizeof(e);
    memcpy(&n, buf + index, sizeof(n));
    index += sizeof(n);
    memcpy(&o, buf + index, sizeof(o));
    index += sizeof(o);
    memcpy(&r, buf + index, sizeof(r));
    index += sizeof(r);
    memcpy(&b, buf + index, sizeof(b));
    index += sizeof(b);
    memcpy(&i, buf + index, sizeof(i));
    index += sizeof(i);
    memcpy(&t, buf + index, sizeof(t));
    index += sizeof(t);
  }
};

class PowerInputMeasurement_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_ampere;
  static_assert((sizeof(current_ampere) == 2), "invalid size");
  uint16_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 2), "invalid size");
  uint16_t power_watt;
  static_assert((sizeof(power_watt) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 157;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_ampere);
  }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volt);
  }
  void set_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watt);
  }
  EDDA_FLOAT_DEF get_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watt, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_ampere, sizeof(current_ampere));
    *index += sizeof(current_ampere);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &power_watt, sizeof(power_watt));
    *index += sizeof(power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_ampere, buf + index, sizeof(current_ampere));
    index += sizeof(current_ampere);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&power_watt, buf + index, sizeof(power_watt));
    index += sizeof(power_watt);
  }
};

class PowerInputMeasurement_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_ampere;
  static_assert((sizeof(current_ampere) == 2), "invalid size");
  uint16_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 2), "invalid size");
  uint16_t power_watt;
  static_assert((sizeof(power_watt) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 158;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_ampere);
  }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volt);
  }
  void set_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watt);
  }
  EDDA_FLOAT_DEF get_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watt, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_ampere, sizeof(current_ampere));
    *index += sizeof(current_ampere);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &power_watt, sizeof(power_watt));
    *index += sizeof(power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_ampere, buf + index, sizeof(current_ampere));
    index += sizeof(current_ampere);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&power_watt, buf + index, sizeof(power_watt));
    index += sizeof(power_watt);
  }
};

class PowerInputMeasurement_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_ampere;
  static_assert((sizeof(current_ampere) == 2), "invalid size");
  uint16_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 2), "invalid size");
  uint16_t power_watt;
  static_assert((sizeof(power_watt) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 159;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_ampere);
  }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volt);
  }
  void set_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watt);
  }
  EDDA_FLOAT_DEF get_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watt, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_ampere, sizeof(current_ampere));
    *index += sizeof(current_ampere);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &power_watt, sizeof(power_watt));
    *index += sizeof(power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_ampere, buf + index, sizeof(current_ampere));
    index += sizeof(current_ampere);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&power_watt, buf + index, sizeof(power_watt));
    index += sizeof(power_watt);
  }
};

class PowerInputMeasurement_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_ampere;
  static_assert((sizeof(current_ampere) == 2), "invalid size");
  uint16_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 2), "invalid size");
  uint16_t power_watt;
  static_assert((sizeof(power_watt) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 160;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_ampere);
  }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volt);
  }
  void set_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watt);
  }
  EDDA_FLOAT_DEF get_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watt, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_ampere, sizeof(current_ampere));
    *index += sizeof(current_ampere);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &power_watt, sizeof(power_watt));
    *index += sizeof(power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_ampere, buf + index, sizeof(current_ampere));
    index += sizeof(current_ampere);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&power_watt, buf + index, sizeof(power_watt));
    index += sizeof(power_watt);
  }
};

class PowerInputMeasurementError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum INA260Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 161;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum INA260Error value) { error = value; }
  enum INA260Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class PowerInputMeasurementError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum INA260Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 162;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum INA260Error value) { error = value; }
  enum INA260Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class PowerInputMeasurementError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum INA260Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 163;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum INA260Error value) { error = value; }
  enum INA260Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class PowerInputMeasurementError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum INA260Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 164;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum INA260Error value) { error = value; }
  enum INA260Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class ColdSideTemperature_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint16_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 165;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(enum TemperatureSensorIndex value) {
    sensor_index = value;
  }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum TemperatureSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint16_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 166;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(enum TemperatureSensorIndex value) {
    sensor_index = value;
  }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum TemperatureSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint16_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 167;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(enum TemperatureSensorIndex value) {
    sensor_index = value;
  }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum TemperatureSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint16_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 168;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(enum TemperatureSensorIndex value) {
    sensor_index = value;
  }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum TemperatureSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class RawTransducerVoltage_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum TransducerVoltageMeasurementIndex measurement_index;
  static_assert((sizeof(measurement_index) == 1), "invalid size");
  uint32_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::RawTransducerVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 169;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_index(enum TransducerVoltageMeasurementIndex value) {
    measurement_index = value;
  }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.2, 5.2, &voltage_volt);
  }
  enum TransducerVoltageMeasurementIndex get_measurement_index() {
    return measurement_index;
  }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, -0.2, 5.2, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_index, sizeof(measurement_index));
    *index += sizeof(measurement_index);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_index, buf + index, sizeof(measurement_index));
    index += sizeof(measurement_index);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
  }
};

class RawTransducerVoltage_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum TransducerVoltageMeasurementIndex measurement_index;
  static_assert((sizeof(measurement_index) == 1), "invalid size");
  uint32_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::RawTransducerVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 170;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_index(enum TransducerVoltageMeasurementIndex value) {
    measurement_index = value;
  }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.2, 5.2, &voltage_volt);
  }
  enum TransducerVoltageMeasurementIndex get_measurement_index() {
    return measurement_index;
  }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, -0.2, 5.2, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_index, sizeof(measurement_index));
    *index += sizeof(measurement_index);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_index, buf + index, sizeof(measurement_index));
    index += sizeof(measurement_index);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
  }
};

class TransducerPressure_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum PressureSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 171;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(enum PressureSensorIndex value) {
    sensor_index = value;
  }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -1000000, 10000000, &pressure_pascal);
  }
  enum PressureSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, -1000000, 10000000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &pressure_pascal, sizeof(pressure_pascal));
    *index += sizeof(pressure_pascal);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&pressure_pascal, buf + index, sizeof(pressure_pascal));
    index += sizeof(pressure_pascal);
  }
};

class TransducerPressure_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum PressureSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 172;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(enum PressureSensorIndex value) {
    sensor_index = value;
  }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -1000000, 10000000, &pressure_pascal);
  }
  enum PressureSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, -1000000, 10000000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &pressure_pascal, sizeof(pressure_pascal));
    *index += sizeof(pressure_pascal);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&pressure_pascal, buf + index, sizeof(pressure_pascal));
    index += sizeof(pressure_pascal);
  }
};

class TransducerError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum TransducerVoltageMeasurementIndex measurement_index;
  static_assert((sizeof(measurement_index) == 1), "invalid size");
  enum TransducerError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::TransducerError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 173;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_index(enum TransducerVoltageMeasurementIndex value) {
    measurement_index = value;
  }
  void set_error(enum TransducerError value) { error = value; }
  enum TransducerVoltageMeasurementIndex get_measurement_index() {
    return measurement_index;
  }
  enum TransducerError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_index, sizeof(measurement_index));
    *index += sizeof(measurement_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_index, buf + index, sizeof(measurement_index));
    index += sizeof(measurement_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class TransducerError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum TransducerVoltageMeasurementIndex measurement_index;
  static_assert((sizeof(measurement_index) == 1), "invalid size");
  enum TransducerError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::TransducerError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 174;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_index(enum TransducerVoltageMeasurementIndex value) {
    measurement_index = value;
  }
  void set_error(enum TransducerError value) { error = value; }
  enum TransducerVoltageMeasurementIndex get_measurement_index() {
    return measurement_index;
  }
  enum TransducerError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_index, sizeof(measurement_index));
    *index += sizeof(measurement_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_index, buf + index, sizeof(measurement_index));
    index += sizeof(measurement_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AmbientPressure_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t pressure_mbar;
  static_assert((sizeof(pressure_mbar) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::AmbientPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 175;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_pressure_mbar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &pressure_mbar);
  }
  EDDA_FLOAT_DEF get_pressure_mbar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_mbar, 0, 10000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &pressure_mbar, sizeof(pressure_mbar));
    *index += sizeof(pressure_mbar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&pressure_mbar, buf + index, sizeof(pressure_mbar));
    index += sizeof(pressure_mbar);
  }
};

class AmbientPressure_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t pressure_mbar;
  static_assert((sizeof(pressure_mbar) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::AmbientPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 176;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_pressure_mbar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &pressure_mbar);
  }
  EDDA_FLOAT_DEF get_pressure_mbar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_mbar, 0, 10000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &pressure_mbar, sizeof(pressure_mbar));
    *index += sizeof(pressure_mbar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&pressure_mbar, buf + index, sizeof(pressure_mbar));
    index += sizeof(pressure_mbar);
  }
};

class AmbientPressureCoefficient_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t coefficient_number;
  static_assert((sizeof(coefficient_number) == 1), "invalid size");
  uint16_t coefficient_value;
  static_assert((sizeof(coefficient_value) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::AmbientPressureCoefficient;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 177;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_coefficient_number(uint8_t value) { coefficient_number = value; }
  void set_coefficient_value(uint16_t value) { coefficient_value = value; }
  uint8_t get_coefficient_number() { return coefficient_number; }
  uint16_t get_coefficient_value() { return coefficient_value; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &coefficient_number, sizeof(coefficient_number));
    *index += sizeof(coefficient_number);
    memcpy(buf + *index, &coefficient_value, sizeof(coefficient_value));
    *index += sizeof(coefficient_value);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&coefficient_number, buf + index, sizeof(coefficient_number));
    index += sizeof(coefficient_number);
    memcpy(&coefficient_value, buf + index, sizeof(coefficient_value));
    index += sizeof(coefficient_value);
  }
};

class AmbientPressureCoefficient_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t coefficient_number;
  static_assert((sizeof(coefficient_number) == 1), "invalid size");
  uint16_t coefficient_value;
  static_assert((sizeof(coefficient_value) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::AmbientPressureCoefficient;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 178;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_coefficient_number(uint8_t value) { coefficient_number = value; }
  void set_coefficient_value(uint16_t value) { coefficient_value = value; }
  uint8_t get_coefficient_number() { return coefficient_number; }
  uint16_t get_coefficient_value() { return coefficient_value; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &coefficient_number, sizeof(coefficient_number));
    *index += sizeof(coefficient_number);
    memcpy(buf + *index, &coefficient_value, sizeof(coefficient_value));
    *index += sizeof(coefficient_value);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&coefficient_number, buf + index, sizeof(coefficient_number));
    index += sizeof(coefficient_number);
    memcpy(&coefficient_value, buf + index, sizeof(coefficient_value));
    index += sizeof(coefficient_value);
  }
};

class AmbientPressureError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum MS5803Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::AmbientPressureError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 179;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum MS5803Error value) { error = value; }
  enum MS5803Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AmbientPressureError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum MS5803Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::AmbientPressureError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 180;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum MS5803Error value) { error = value; }
  enum MS5803Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class PlatinumSensorTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum PlatinumSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PlatinumSensorTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 181;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum PlatinumSensorIndex value) {
    sensor_index = value;
  }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 850, &temperature_celsius);
  }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum PlatinumSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -200, 850, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class PlatinumSensorResistance_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum PlatinumSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t resistance_ohm;
  static_assert((sizeof(resistance_ohm) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PlatinumSensorResistance;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 182;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum PlatinumSensorIndex value) {
    sensor_index = value;
  }
  void set_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5000, &resistance_ohm);
  }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum PlatinumSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(resistance_ohm, 0, 5000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &resistance_ohm, sizeof(resistance_ohm));
    *index += sizeof(resistance_ohm);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&resistance_ohm, buf + index, sizeof(resistance_ohm));
    index += sizeof(resistance_ohm);
  }
};

class PlatinumSensorRatio_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum PlatinumSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t ratio_fraction;
  static_assert((sizeof(ratio_fraction) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PlatinumSensorRatio;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 183;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum PlatinumSensorIndex value) {
    sensor_index = value;
  }
  void set_ratio_fraction(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1, &ratio_fraction);
  }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum PlatinumSensorIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_ratio_fraction() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(ratio_fraction, 0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &ratio_fraction, sizeof(ratio_fraction));
    *index += sizeof(ratio_fraction);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&ratio_fraction, buf + index, sizeof(ratio_fraction));
    index += sizeof(ratio_fraction);
  }
};

class ThermocoupleTypeKTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum ThermocoupleIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ThermocoupleTypeKTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 184;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum ThermocoupleIndex value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &temperature_celsius);
  }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum ThermocoupleIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ThermocoupleColdsideTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum ThermocoupleIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint16_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 2), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::ThermocoupleColdsideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 185;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum ThermocoupleIndex value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum ThermocoupleIndex get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class Humidity_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t relative_humidity_percentage;
  static_assert((sizeof(relative_humidity_percentage) == 2), "invalid size");
  uint8_t is_heater_on;
  static_assert((sizeof(is_heater_on) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::Humidity;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 187;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_relative_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100, &relative_humidity_percentage);
  }
  void set_is_heater_on(uint8_t value) { is_heater_on = value; }
  EDDA_FLOAT_DEF get_relative_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(relative_humidity_percentage, 0, 100, &out);
    return out;
  }
  uint8_t get_is_heater_on() { return is_heater_on; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &relative_humidity_percentage,
           sizeof(relative_humidity_percentage));
    *index += sizeof(relative_humidity_percentage);
    memcpy(buf + *index, &is_heater_on, sizeof(is_heater_on));
    *index += sizeof(is_heater_on);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&relative_humidity_percentage, buf + index,
           sizeof(relative_humidity_percentage));
    index += sizeof(relative_humidity_percentage);
    memcpy(&is_heater_on, buf + index, sizeof(is_heater_on));
    index += sizeof(is_heater_on);
  }
};

class HumidityError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum SHT31Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::HumidityError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 188;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum SHT31Error value) { error = value; }
  enum SHT31Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class Acceleration_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t acceleration_x_gforce;
  static_assert((sizeof(acceleration_x_gforce) == 2), "invalid size");
  uint16_t acceleration_y_gforce;
  static_assert((sizeof(acceleration_y_gforce) == 2), "invalid size");
  uint32_t acceleration_z_gforce;
  static_assert((sizeof(acceleration_z_gforce) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Acceleration;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 189;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_acceleration_x_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &acceleration_x_gforce);
  }
  void set_acceleration_y_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &acceleration_y_gforce);
  }
  void set_acceleration_z_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &acceleration_z_gforce);
  }
  EDDA_FLOAT_DEF get_acceleration_x_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(acceleration_x_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_acceleration_y_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(acceleration_y_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_acceleration_z_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(acceleration_z_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &acceleration_x_gforce, sizeof(acceleration_x_gforce));
    *index += sizeof(acceleration_x_gforce);
    memcpy(buf + *index, &acceleration_y_gforce, sizeof(acceleration_y_gforce));
    *index += sizeof(acceleration_y_gforce);
    memcpy(buf + *index, &acceleration_z_gforce, sizeof(acceleration_z_gforce));
    *index += sizeof(acceleration_z_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&acceleration_x_gforce, buf + index, sizeof(acceleration_x_gforce));
    index += sizeof(acceleration_x_gforce);
    memcpy(&acceleration_y_gforce, buf + index, sizeof(acceleration_y_gforce));
    index += sizeof(acceleration_y_gforce);
    memcpy(&acceleration_z_gforce, buf + index, sizeof(acceleration_z_gforce));
    index += sizeof(acceleration_z_gforce);
  }
};

class AccelerationError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum LIS331Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::AccelerationError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 190;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum LIS331Error value) { error = value; }
  enum LIS331Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AccelerationSelfTest_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum AccelerationSelfTestDirection sign;
  static_assert((sizeof(sign) == 1), "invalid size");
  enum AccelerationSelfTestResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint16_t acceleration_x_gforce;
  static_assert((sizeof(acceleration_x_gforce) == 2), "invalid size");
  uint16_t acceleration_y_gforce;
  static_assert((sizeof(acceleration_y_gforce) == 2), "invalid size");
  uint16_t acceleration_z_gforce;
  static_assert((sizeof(acceleration_z_gforce) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::AccelerationSelfTest;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 191;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sign(enum AccelerationSelfTestDirection value) { sign = value; }
  void set_result(enum AccelerationSelfTestResult value) { result = value; }
  void set_acceleration_x_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &acceleration_x_gforce);
  }
  void set_acceleration_y_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &acceleration_y_gforce);
  }
  void set_acceleration_z_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &acceleration_z_gforce);
  }
  enum AccelerationSelfTestDirection get_sign() { return sign; }
  enum AccelerationSelfTestResult get_result() { return result; }
  EDDA_FLOAT_DEF get_acceleration_x_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(acceleration_x_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_acceleration_y_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(acceleration_y_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_acceleration_z_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(acceleration_z_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sign, sizeof(sign));
    *index += sizeof(sign);
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
    memcpy(buf + *index, &acceleration_x_gforce, sizeof(acceleration_x_gforce));
    *index += sizeof(acceleration_x_gforce);
    memcpy(buf + *index, &acceleration_y_gforce, sizeof(acceleration_y_gforce));
    *index += sizeof(acceleration_y_gforce);
    memcpy(buf + *index, &acceleration_z_gforce, sizeof(acceleration_z_gforce));
    *index += sizeof(acceleration_z_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sign, buf + index, sizeof(sign));
    index += sizeof(sign);
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
    memcpy(&acceleration_x_gforce, buf + index, sizeof(acceleration_x_gforce));
    index += sizeof(acceleration_x_gforce);
    memcpy(&acceleration_y_gforce, buf + index, sizeof(acceleration_y_gforce));
    index += sizeof(acceleration_y_gforce);
    memcpy(&acceleration_z_gforce, buf + index, sizeof(acceleration_z_gforce));
    index += sizeof(acceleration_z_gforce);
  }
};

class AmbientLight_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  float_t ambient_light_lux;
  static_assert((sizeof(ambient_light_lux) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::AmbientLight;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 192;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_ambient_light_lux(float_t value) { ambient_light_lux = value; }
  float_t get_ambient_light_lux() { return ambient_light_lux; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &ambient_light_lux, sizeof(ambient_light_lux));
    *index += sizeof(ambient_light_lux);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&ambient_light_lux, buf + index, sizeof(ambient_light_lux));
    index += sizeof(ambient_light_lux);
  }
};

class AmbientLightError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum LTR303Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::AmbientLightError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 193;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum LTR303Error value) { error = value; }
  enum LTR303Error get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class TaskInfo_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t task_time_us;
  static_assert((sizeof(task_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 198;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_task_time_us(uint32_t value) { task_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum TaskType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_task_time_us() { return task_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &task_time_us, sizeof(task_time_us));
    *index += sizeof(task_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&task_time_us, buf + index, sizeof(task_time_us));
    index += sizeof(task_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class TaskInfo_from_Edda_Telemetry_to_Ground_Controller : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t task_time_us;
  static_assert((sizeof(task_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 199;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_task_time_us(uint32_t value) { task_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum TaskType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_task_time_us() { return task_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &task_time_us, sizeof(task_time_us));
    *index += sizeof(task_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&task_time_us, buf + index, sizeof(task_time_us));
    index += sizeof(task_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class TaskInfo_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t task_time_us;
  static_assert((sizeof(task_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 200;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_task_time_us(uint32_t value) { task_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum TaskType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_task_time_us() { return task_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &task_time_us, sizeof(task_time_us));
    *index += sizeof(task_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&task_time_us, buf + index, sizeof(task_time_us));
    index += sizeof(task_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class TaskInfo_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t task_time_us;
  static_assert((sizeof(task_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 201;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_task_time_us(uint32_t value) { task_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum TaskType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_task_time_us() { return task_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &task_time_us, sizeof(task_time_us));
    *index += sizeof(task_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&task_time_us, buf + index, sizeof(task_time_us));
    index += sizeof(task_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class LoopInfo_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t loop_time_us;
  static_assert((sizeof(loop_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 202;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_loop_time_us(uint32_t value) { loop_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum LoopType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_loop_time_us() { return loop_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &loop_time_us, sizeof(loop_time_us));
    *index += sizeof(loop_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&loop_time_us, buf + index, sizeof(loop_time_us));
    index += sizeof(loop_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class LoopInfo_from_Edda_Telemetry_to_Ground_Controller : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t loop_time_us;
  static_assert((sizeof(loop_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 203;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_loop_time_us(uint32_t value) { loop_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum LoopType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_loop_time_us() { return loop_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &loop_time_us, sizeof(loop_time_us));
    *index += sizeof(loop_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&loop_time_us, buf + index, sizeof(loop_time_us));
    index += sizeof(loop_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class LoopInfo_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t loop_time_us;
  static_assert((sizeof(loop_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 204;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_loop_time_us(uint32_t value) { loop_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum LoopType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_loop_time_us() { return loop_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &loop_time_us, sizeof(loop_time_us));
    *index += sizeof(loop_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&loop_time_us, buf + index, sizeof(loop_time_us));
    index += sizeof(loop_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class LoopInfo_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  enum Thread thread;
  static_assert((sizeof(thread) == 1), "invalid size");
  uint32_t loop_time_us;
  static_assert((sizeof(loop_time_us) == 4), "invalid size");
  uint16_t truncated_start_time_us;
  static_assert((sizeof(truncated_start_time_us) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 205;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread(enum Thread value) { thread = value; }
  void set_loop_time_us(uint32_t value) { loop_time_us = value; }
  void set_truncated_start_time_us(uint16_t value) {
    truncated_start_time_us = value;
  }
  enum LoopType get_type() { return type; }
  enum Thread get_thread() { return thread; }
  uint32_t get_loop_time_us() { return loop_time_us; }
  uint16_t get_truncated_start_time_us() { return truncated_start_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread, sizeof(thread));
    *index += sizeof(thread);
    memcpy(buf + *index, &loop_time_us, sizeof(loop_time_us));
    *index += sizeof(loop_time_us);
    memcpy(buf + *index, &truncated_start_time_us,
           sizeof(truncated_start_time_us));
    *index += sizeof(truncated_start_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread, buf + index, sizeof(thread));
    index += sizeof(thread);
    memcpy(&loop_time_us, buf + index, sizeof(loop_time_us));
    index += sizeof(loop_time_us);
    memcpy(&truncated_start_time_us, buf + index,
           sizeof(truncated_start_time_us));
    index += sizeof(truncated_start_time_us);
  }
};

class OneWireDevicePairedWithSensor_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t position_on_board;
  static_assert((sizeof(position_on_board) == 1), "invalid size");
  uint8_t serial_byte0;
  static_assert((sizeof(serial_byte0) == 1), "invalid size");
  uint8_t serial_byte1;
  static_assert((sizeof(serial_byte1) == 1), "invalid size");
  uint8_t serial_byte2;
  static_assert((sizeof(serial_byte2) == 1), "invalid size");
  uint8_t serial_byte3;
  static_assert((sizeof(serial_byte3) == 1), "invalid size");
  uint8_t serial_byte4;
  static_assert((sizeof(serial_byte4) == 1), "invalid size");
  uint8_t serial_byte5;
  static_assert((sizeof(serial_byte5) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::OneWireDevicePairedWithSensor;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 207;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_position_on_board(uint8_t value) { position_on_board = value; }
  void set_serial_byte0(uint8_t value) { serial_byte0 = value; }
  void set_serial_byte1(uint8_t value) { serial_byte1 = value; }
  void set_serial_byte2(uint8_t value) { serial_byte2 = value; }
  void set_serial_byte3(uint8_t value) { serial_byte3 = value; }
  void set_serial_byte4(uint8_t value) { serial_byte4 = value; }
  void set_serial_byte5(uint8_t value) { serial_byte5 = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_position_on_board() { return position_on_board; }
  uint8_t get_serial_byte0() { return serial_byte0; }
  uint8_t get_serial_byte1() { return serial_byte1; }
  uint8_t get_serial_byte2() { return serial_byte2; }
  uint8_t get_serial_byte3() { return serial_byte3; }
  uint8_t get_serial_byte4() { return serial_byte4; }
  uint8_t get_serial_byte5() { return serial_byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &position_on_board, sizeof(position_on_board));
    *index += sizeof(position_on_board);
    memcpy(buf + *index, &serial_byte0, sizeof(serial_byte0));
    *index += sizeof(serial_byte0);
    memcpy(buf + *index, &serial_byte1, sizeof(serial_byte1));
    *index += sizeof(serial_byte1);
    memcpy(buf + *index, &serial_byte2, sizeof(serial_byte2));
    *index += sizeof(serial_byte2);
    memcpy(buf + *index, &serial_byte3, sizeof(serial_byte3));
    *index += sizeof(serial_byte3);
    memcpy(buf + *index, &serial_byte4, sizeof(serial_byte4));
    *index += sizeof(serial_byte4);
    memcpy(buf + *index, &serial_byte5, sizeof(serial_byte5));
    *index += sizeof(serial_byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&position_on_board, buf + index, sizeof(position_on_board));
    index += sizeof(position_on_board);
    memcpy(&serial_byte0, buf + index, sizeof(serial_byte0));
    index += sizeof(serial_byte0);
    memcpy(&serial_byte1, buf + index, sizeof(serial_byte1));
    index += sizeof(serial_byte1);
    memcpy(&serial_byte2, buf + index, sizeof(serial_byte2));
    index += sizeof(serial_byte2);
    memcpy(&serial_byte3, buf + index, sizeof(serial_byte3));
    index += sizeof(serial_byte3);
    memcpy(&serial_byte4, buf + index, sizeof(serial_byte4));
    index += sizeof(serial_byte4);
    memcpy(&serial_byte5, buf + index, sizeof(serial_byte5));
    index += sizeof(serial_byte5);
  }
};

class OneWireSearchFamilyMismatch_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t serial_byte0;
  static_assert((sizeof(serial_byte0) == 1), "invalid size");
  uint8_t serial_byte1;
  static_assert((sizeof(serial_byte1) == 1), "invalid size");
  uint8_t serial_byte2;
  static_assert((sizeof(serial_byte2) == 1), "invalid size");
  uint8_t serial_byte3;
  static_assert((sizeof(serial_byte3) == 1), "invalid size");
  uint8_t serial_byte4;
  static_assert((sizeof(serial_byte4) == 1), "invalid size");
  uint8_t serial_byte5;
  static_assert((sizeof(serial_byte5) == 1), "invalid size");
  uint8_t found_family_code;
  static_assert((sizeof(found_family_code) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::OneWireSearchFamilyMismatch;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 208;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_serial_byte0(uint8_t value) { serial_byte0 = value; }
  void set_serial_byte1(uint8_t value) { serial_byte1 = value; }
  void set_serial_byte2(uint8_t value) { serial_byte2 = value; }
  void set_serial_byte3(uint8_t value) { serial_byte3 = value; }
  void set_serial_byte4(uint8_t value) { serial_byte4 = value; }
  void set_serial_byte5(uint8_t value) { serial_byte5 = value; }
  void set_found_family_code(uint8_t value) { found_family_code = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_serial_byte0() { return serial_byte0; }
  uint8_t get_serial_byte1() { return serial_byte1; }
  uint8_t get_serial_byte2() { return serial_byte2; }
  uint8_t get_serial_byte3() { return serial_byte3; }
  uint8_t get_serial_byte4() { return serial_byte4; }
  uint8_t get_serial_byte5() { return serial_byte5; }
  uint8_t get_found_family_code() { return found_family_code; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &serial_byte0, sizeof(serial_byte0));
    *index += sizeof(serial_byte0);
    memcpy(buf + *index, &serial_byte1, sizeof(serial_byte1));
    *index += sizeof(serial_byte1);
    memcpy(buf + *index, &serial_byte2, sizeof(serial_byte2));
    *index += sizeof(serial_byte2);
    memcpy(buf + *index, &serial_byte3, sizeof(serial_byte3));
    *index += sizeof(serial_byte3);
    memcpy(buf + *index, &serial_byte4, sizeof(serial_byte4));
    *index += sizeof(serial_byte4);
    memcpy(buf + *index, &serial_byte5, sizeof(serial_byte5));
    *index += sizeof(serial_byte5);
    memcpy(buf + *index, &found_family_code, sizeof(found_family_code));
    *index += sizeof(found_family_code);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&serial_byte0, buf + index, sizeof(serial_byte0));
    index += sizeof(serial_byte0);
    memcpy(&serial_byte1, buf + index, sizeof(serial_byte1));
    index += sizeof(serial_byte1);
    memcpy(&serial_byte2, buf + index, sizeof(serial_byte2));
    index += sizeof(serial_byte2);
    memcpy(&serial_byte3, buf + index, sizeof(serial_byte3));
    index += sizeof(serial_byte3);
    memcpy(&serial_byte4, buf + index, sizeof(serial_byte4));
    index += sizeof(serial_byte4);
    memcpy(&serial_byte5, buf + index, sizeof(serial_byte5));
    index += sizeof(serial_byte5);
    memcpy(&found_family_code, buf + index, sizeof(found_family_code));
    index += sizeof(found_family_code);
  }
};

class OneWireSearchCRCMismatch_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t serial_byte0;
  static_assert((sizeof(serial_byte0) == 1), "invalid size");
  uint8_t serial_byte1;
  static_assert((sizeof(serial_byte1) == 1), "invalid size");
  uint8_t serial_byte2;
  static_assert((sizeof(serial_byte2) == 1), "invalid size");
  uint8_t serial_byte3;
  static_assert((sizeof(serial_byte3) == 1), "invalid size");
  uint8_t serial_byte4;
  static_assert((sizeof(serial_byte4) == 1), "invalid size");
  uint8_t serial_byte5;
  static_assert((sizeof(serial_byte5) == 1), "invalid size");
  uint8_t found_crc;
  static_assert((sizeof(found_crc) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::OneWireSearchCRCMismatch;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 209;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_serial_byte0(uint8_t value) { serial_byte0 = value; }
  void set_serial_byte1(uint8_t value) { serial_byte1 = value; }
  void set_serial_byte2(uint8_t value) { serial_byte2 = value; }
  void set_serial_byte3(uint8_t value) { serial_byte3 = value; }
  void set_serial_byte4(uint8_t value) { serial_byte4 = value; }
  void set_serial_byte5(uint8_t value) { serial_byte5 = value; }
  void set_found_crc(uint8_t value) { found_crc = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_serial_byte0() { return serial_byte0; }
  uint8_t get_serial_byte1() { return serial_byte1; }
  uint8_t get_serial_byte2() { return serial_byte2; }
  uint8_t get_serial_byte3() { return serial_byte3; }
  uint8_t get_serial_byte4() { return serial_byte4; }
  uint8_t get_serial_byte5() { return serial_byte5; }
  uint8_t get_found_crc() { return found_crc; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &serial_byte0, sizeof(serial_byte0));
    *index += sizeof(serial_byte0);
    memcpy(buf + *index, &serial_byte1, sizeof(serial_byte1));
    *index += sizeof(serial_byte1);
    memcpy(buf + *index, &serial_byte2, sizeof(serial_byte2));
    *index += sizeof(serial_byte2);
    memcpy(buf + *index, &serial_byte3, sizeof(serial_byte3));
    *index += sizeof(serial_byte3);
    memcpy(buf + *index, &serial_byte4, sizeof(serial_byte4));
    *index += sizeof(serial_byte4);
    memcpy(buf + *index, &serial_byte5, sizeof(serial_byte5));
    *index += sizeof(serial_byte5);
    memcpy(buf + *index, &found_crc, sizeof(found_crc));
    *index += sizeof(found_crc);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&serial_byte0, buf + index, sizeof(serial_byte0));
    index += sizeof(serial_byte0);
    memcpy(&serial_byte1, buf + index, sizeof(serial_byte1));
    index += sizeof(serial_byte1);
    memcpy(&serial_byte2, buf + index, sizeof(serial_byte2));
    index += sizeof(serial_byte2);
    memcpy(&serial_byte3, buf + index, sizeof(serial_byte3));
    index += sizeof(serial_byte3);
    memcpy(&serial_byte4, buf + index, sizeof(serial_byte4));
    index += sizeof(serial_byte4);
    memcpy(&serial_byte5, buf + index, sizeof(serial_byte5));
    index += sizeof(serial_byte5);
    memcpy(&found_crc, buf + index, sizeof(found_crc));
    index += sizeof(found_crc);
  }
};

class OneWireSearchFoundDevice_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t serial_byte0;
  static_assert((sizeof(serial_byte0) == 1), "invalid size");
  uint8_t serial_byte1;
  static_assert((sizeof(serial_byte1) == 1), "invalid size");
  uint8_t serial_byte2;
  static_assert((sizeof(serial_byte2) == 1), "invalid size");
  uint8_t serial_byte3;
  static_assert((sizeof(serial_byte3) == 1), "invalid size");
  uint8_t serial_byte4;
  static_assert((sizeof(serial_byte4) == 1), "invalid size");
  uint8_t serial_byte5;
  static_assert((sizeof(serial_byte5) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::OneWireSearchFoundDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 210;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_serial_byte0(uint8_t value) { serial_byte0 = value; }
  void set_serial_byte1(uint8_t value) { serial_byte1 = value; }
  void set_serial_byte2(uint8_t value) { serial_byte2 = value; }
  void set_serial_byte3(uint8_t value) { serial_byte3 = value; }
  void set_serial_byte4(uint8_t value) { serial_byte4 = value; }
  void set_serial_byte5(uint8_t value) { serial_byte5 = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_serial_byte0() { return serial_byte0; }
  uint8_t get_serial_byte1() { return serial_byte1; }
  uint8_t get_serial_byte2() { return serial_byte2; }
  uint8_t get_serial_byte3() { return serial_byte3; }
  uint8_t get_serial_byte4() { return serial_byte4; }
  uint8_t get_serial_byte5() { return serial_byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &serial_byte0, sizeof(serial_byte0));
    *index += sizeof(serial_byte0);
    memcpy(buf + *index, &serial_byte1, sizeof(serial_byte1));
    *index += sizeof(serial_byte1);
    memcpy(buf + *index, &serial_byte2, sizeof(serial_byte2));
    *index += sizeof(serial_byte2);
    memcpy(buf + *index, &serial_byte3, sizeof(serial_byte3));
    *index += sizeof(serial_byte3);
    memcpy(buf + *index, &serial_byte4, sizeof(serial_byte4));
    *index += sizeof(serial_byte4);
    memcpy(buf + *index, &serial_byte5, sizeof(serial_byte5));
    *index += sizeof(serial_byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&serial_byte0, buf + index, sizeof(serial_byte0));
    index += sizeof(serial_byte0);
    memcpy(&serial_byte1, buf + index, sizeof(serial_byte1));
    index += sizeof(serial_byte1);
    memcpy(&serial_byte2, buf + index, sizeof(serial_byte2));
    index += sizeof(serial_byte2);
    memcpy(&serial_byte3, buf + index, sizeof(serial_byte3));
    index += sizeof(serial_byte3);
    memcpy(&serial_byte4, buf + index, sizeof(serial_byte4));
    index += sizeof(serial_byte4);
    memcpy(&serial_byte5, buf + index, sizeof(serial_byte5));
    index += sizeof(serial_byte5);
  }
};

class PowerCAN_Temperature_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_TemperatureKind kind;
  static_assert((sizeof(kind) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerCAN_Temperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 215;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_kind(enum PowerCAN_TemperatureKind value) { kind = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -100, 300, &temperature_celsius);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_TemperatureKind get_kind() { return kind; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -100, 300, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &kind, sizeof(kind));
    *index += sizeof(kind);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&kind, buf + index, sizeof(kind));
    index += sizeof(kind);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_Voltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_VoltageKind kind;
  static_assert((sizeof(kind) == 1), "invalid size");
  uint32_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerCAN_Voltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 216;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_kind(enum PowerCAN_VoltageKind value) { kind = value; }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_VoltageKind get_kind() { return kind; }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, -30, 30, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &kind, sizeof(kind));
    *index += sizeof(kind);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&kind, buf + index, sizeof(kind));
    index += sizeof(kind);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ChannelMeasurementPower_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementChannel channel;
  static_assert((sizeof(channel) == 1), "invalid size");
  uint32_t power_watt;
  static_assert((sizeof(power_watt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ChannelMeasurementPower;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 217;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_channel(enum PowerCAN_MeasurementChannel value) { channel = value; }
  void set_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &power_watt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementChannel get_channel() { return channel; }
  EDDA_FLOAT_DEF get_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watt, 0, 1000, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &channel, sizeof(channel));
    *index += sizeof(channel);
    memcpy(buf + *index, &power_watt, sizeof(power_watt));
    *index += sizeof(power_watt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&channel, buf + index, sizeof(channel));
    index += sizeof(channel);
    memcpy(&power_watt, buf + index, sizeof(power_watt));
    index += sizeof(power_watt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ChannelMeasurementVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementChannel channel;
  static_assert((sizeof(channel) == 1), "invalid size");
  uint32_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ChannelMeasurementVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 218;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_channel(enum PowerCAN_MeasurementChannel value) { channel = value; }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementChannel get_channel() { return channel; }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, -30, 30, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &channel, sizeof(channel));
    *index += sizeof(channel);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&channel, buf + index, sizeof(channel));
    index += sizeof(channel);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ChannelMeasurementCurrent_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementChannel channel;
  static_assert((sizeof(channel) == 1), "invalid size");
  uint32_t current_ampere;
  static_assert((sizeof(current_ampere) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ChannelMeasurementCurrent;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 219;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_channel(enum PowerCAN_MeasurementChannel value) { channel = value; }
  void set_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &current_ampere);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementChannel get_channel() { return channel; }
  EDDA_FLOAT_DEF get_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_ampere, 0, 30, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &channel, sizeof(channel));
    *index += sizeof(channel);
    memcpy(buf + *index, &current_ampere, sizeof(current_ampere));
    *index += sizeof(current_ampere);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&channel, buf + index, sizeof(channel));
    index += sizeof(channel);
    memcpy(&current_ampere, buf + index, sizeof(current_ampere));
    index += sizeof(current_ampere);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_LoadMeasurementResistance_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_LoadMeasurementResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint32_t resistance_ohm;
  static_assert((sizeof(resistance_ohm) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_LoadMeasurementResistance;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 220;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(enum PowerCAN_MeasurementReference value) {
    measurement_reference = value;
  }
  void set_result(enum PowerCAN_LoadMeasurementResult value) { result = value; }
  void set_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000, &resistance_ohm);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_LoadMeasurementResult get_result() { return result; }
  EDDA_FLOAT_DEF get_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(resistance_ohm, 0, 100000, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
    memcpy(buf + *index, &resistance_ohm, sizeof(resistance_ohm));
    *index += sizeof(resistance_ohm);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
    memcpy(&resistance_ohm, buf + index, sizeof(resistance_ohm));
    index += sizeof(resistance_ohm);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_LoadMeasurementVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_LoadMeasurementResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint32_t voltage_volt;
  static_assert((sizeof(voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PowerCAN_LoadMeasurementVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 221;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(enum PowerCAN_MeasurementReference value) {
    measurement_reference = value;
  }
  void set_result(enum PowerCAN_LoadMeasurementResult value) { result = value; }
  void set_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_LoadMeasurementResult get_result() { return result; }
  EDDA_FLOAT_DEF get_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volt, -30, 30, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
    memcpy(buf + *index, &voltage_volt, sizeof(voltage_volt));
    *index += sizeof(voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
    memcpy(&voltage_volt, buf + index, sizeof(voltage_volt));
    index += sizeof(voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_LoadMeasurementPower_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_LoadMeasurementResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint32_t power_watt;
  static_assert((sizeof(power_watt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PowerCAN_LoadMeasurementPower;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 222;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(enum PowerCAN_MeasurementReference value) {
    measurement_reference = value;
  }
  void set_result(enum PowerCAN_LoadMeasurementResult value) { result = value; }
  void set_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &power_watt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_LoadMeasurementResult get_result() { return result; }
  EDDA_FLOAT_DEF get_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watt, 0, 1000, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
    memcpy(buf + *index, &power_watt, sizeof(power_watt));
    *index += sizeof(power_watt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
    memcpy(&power_watt, buf + index, sizeof(power_watt));
    index += sizeof(power_watt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_LoadMeasurementCurrent_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_LoadMeasurementResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint32_t current_ampere;
  static_assert((sizeof(current_ampere) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PowerCAN_LoadMeasurementCurrent;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 223;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(enum PowerCAN_MeasurementReference value) {
    measurement_reference = value;
  }
  void set_result(enum PowerCAN_LoadMeasurementResult value) { result = value; }
  void set_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &current_ampere);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_LoadMeasurementResult get_result() { return result; }
  EDDA_FLOAT_DEF get_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_ampere, 0, 30, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
    memcpy(buf + *index, &current_ampere, sizeof(current_ampere));
    *index += sizeof(current_ampere);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
    memcpy(&current_ampere, buf + index, sizeof(current_ampere));
    index += sizeof(current_ampere);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_FailedLoadMeasurementValue_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_MeasurementFailureReason failure_reason;
  static_assert((sizeof(failure_reason) == 1), "invalid size");
  uint32_t value;
  static_assert((sizeof(value) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_FailedLoadMeasurementValue;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 224;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(enum PowerCAN_MeasurementReference value) {
    measurement_reference = value;
  }
  void set_failure_reason(enum PowerCAN_MeasurementFailureReason value) {
    failure_reason = value;
  }
  void set_value(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000000, &value);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_MeasurementFailureReason get_failure_reason() {
    return failure_reason;
  }
  EDDA_FLOAT_DEF get_value() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(value, 0, 1000000, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &failure_reason, sizeof(failure_reason));
    *index += sizeof(failure_reason);
    memcpy(buf + *index, &value, sizeof(value));
    *index += sizeof(value);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&failure_reason, buf + index, sizeof(failure_reason));
    index += sizeof(failure_reason);
    memcpy(&value, buf + index, sizeof(value));
    index += sizeof(value);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_FailedLoadMeasurementThreshold_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_MeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_MeasurementFailureReason failure_reason;
  static_assert((sizeof(failure_reason) == 1), "invalid size");
  uint32_t threshold;
  static_assert((sizeof(threshold) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_FailedLoadMeasurementThreshold;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 225;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(enum PowerCAN_MeasurementReference value) {
    measurement_reference = value;
  }
  void set_failure_reason(enum PowerCAN_MeasurementFailureReason value) {
    failure_reason = value;
  }
  void set_threshold(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000000, &threshold);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_MeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_MeasurementFailureReason get_failure_reason() {
    return failure_reason;
  }
  EDDA_FLOAT_DEF get_threshold() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(threshold, 0, 1000000, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &failure_reason, sizeof(failure_reason));
    *index += sizeof(failure_reason);
    memcpy(buf + *index, &threshold, sizeof(threshold));
    *index += sizeof(threshold);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&failure_reason, buf + index, sizeof(failure_reason));
    index += sizeof(failure_reason);
    memcpy(&threshold, buf + index, sizeof(threshold));
    index += sizeof(threshold);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ResistanceMeasurementResistance_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_ResistanceMeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_ResistanceMeasurementValidity validity;
  static_assert((sizeof(validity) == 1), "invalid size");
  uint32_t resistance_ohm;
  static_assert((sizeof(resistance_ohm) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ResistanceMeasurementResistance;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 226;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(
      enum PowerCAN_ResistanceMeasurementReference value) {
    measurement_reference = value;
  }
  void set_validity(enum PowerCAN_ResistanceMeasurementValidity value) {
    validity = value;
  }
  void set_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000, &resistance_ohm);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_ResistanceMeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_ResistanceMeasurementValidity get_validity() {
    return validity;
  }
  EDDA_FLOAT_DEF get_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(resistance_ohm, 0, 100000, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &validity, sizeof(validity));
    *index += sizeof(validity);
    memcpy(buf + *index, &resistance_ohm, sizeof(resistance_ohm));
    *index += sizeof(resistance_ohm);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&validity, buf + index, sizeof(validity));
    index += sizeof(validity);
    memcpy(&resistance_ohm, buf + index, sizeof(resistance_ohm));
    index += sizeof(resistance_ohm);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ResistanceMeasurementReferenceVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_ResistanceMeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_ResistanceMeasurementValidity validity;
  static_assert((sizeof(validity) == 1), "invalid size");
  uint32_t reference_voltage_volt;
  static_assert((sizeof(reference_voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ResistanceMeasurementReferenceVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 227;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(
      enum PowerCAN_ResistanceMeasurementReference value) {
    measurement_reference = value;
  }
  void set_validity(enum PowerCAN_ResistanceMeasurementValidity value) {
    validity = value;
  }
  void set_reference_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &reference_voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_ResistanceMeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_ResistanceMeasurementValidity get_validity() {
    return validity;
  }
  EDDA_FLOAT_DEF get_reference_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(reference_voltage_volt, 0, 5, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &validity, sizeof(validity));
    *index += sizeof(validity);
    memcpy(buf + *index, &reference_voltage_volt,
           sizeof(reference_voltage_volt));
    *index += sizeof(reference_voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&validity, buf + index, sizeof(validity));
    index += sizeof(validity);
    memcpy(&reference_voltage_volt, buf + index,
           sizeof(reference_voltage_volt));
    index += sizeof(reference_voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ResistanceMeasurementDifferentialVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_ResistanceMeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_ResistanceMeasurementValidity validity;
  static_assert((sizeof(validity) == 1), "invalid size");
  uint32_t differential_voltage_volt;
  static_assert((sizeof(differential_voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ResistanceMeasurementDifferentialVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 228;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(
      enum PowerCAN_ResistanceMeasurementReference value) {
    measurement_reference = value;
  }
  void set_validity(enum PowerCAN_ResistanceMeasurementValidity value) {
    validity = value;
  }
  void set_differential_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &differential_voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_ResistanceMeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_ResistanceMeasurementValidity get_validity() {
    return validity;
  }
  EDDA_FLOAT_DEF get_differential_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(differential_voltage_volt, 0, 5, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &validity, sizeof(validity));
    *index += sizeof(validity);
    memcpy(buf + *index, &differential_voltage_volt,
           sizeof(differential_voltage_volt));
    *index += sizeof(differential_voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&validity, buf + index, sizeof(validity));
    index += sizeof(validity);
    memcpy(&differential_voltage_volt, buf + index,
           sizeof(differential_voltage_volt));
    index += sizeof(differential_voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ResistanceMeasurementPositiveVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_ResistanceMeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_ResistanceMeasurementValidity validity;
  static_assert((sizeof(validity) == 1), "invalid size");
  uint32_t positive_voltage_volt;
  static_assert((sizeof(positive_voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ResistanceMeasurementPositiveVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 229;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(
      enum PowerCAN_ResistanceMeasurementReference value) {
    measurement_reference = value;
  }
  void set_validity(enum PowerCAN_ResistanceMeasurementValidity value) {
    validity = value;
  }
  void set_positive_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &positive_voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_ResistanceMeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_ResistanceMeasurementValidity get_validity() {
    return validity;
  }
  EDDA_FLOAT_DEF get_positive_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(positive_voltage_volt, 0, 5, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &validity, sizeof(validity));
    *index += sizeof(validity);
    memcpy(buf + *index, &positive_voltage_volt, sizeof(positive_voltage_volt));
    *index += sizeof(positive_voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&validity, buf + index, sizeof(validity));
    index += sizeof(validity);
    memcpy(&positive_voltage_volt, buf + index, sizeof(positive_voltage_volt));
    index += sizeof(positive_voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ResistanceMeasurementNegativeVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_ResistanceMeasurementReference measurement_reference;
  static_assert((sizeof(measurement_reference) == 1), "invalid size");
  enum PowerCAN_ResistanceMeasurementValidity validity;
  static_assert((sizeof(validity) == 1), "invalid size");
  uint32_t negative_voltage_volt;
  static_assert((sizeof(negative_voltage_volt) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::PowerCAN_ResistanceMeasurementNegativeVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 230;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_measurement_reference(
      enum PowerCAN_ResistanceMeasurementReference value) {
    measurement_reference = value;
  }
  void set_validity(enum PowerCAN_ResistanceMeasurementValidity value) {
    validity = value;
  }
  void set_negative_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &negative_voltage_volt);
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_ResistanceMeasurementReference get_measurement_reference() {
    return measurement_reference;
  }
  enum PowerCAN_ResistanceMeasurementValidity get_validity() {
    return validity;
  }
  EDDA_FLOAT_DEF get_negative_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(negative_voltage_volt, 0, 5, &out);
    return out;
  }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &measurement_reference, sizeof(measurement_reference));
    *index += sizeof(measurement_reference);
    memcpy(buf + *index, &validity, sizeof(validity));
    *index += sizeof(validity);
    memcpy(buf + *index, &negative_voltage_volt, sizeof(negative_voltage_volt));
    *index += sizeof(negative_voltage_volt);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&measurement_reference, buf + index, sizeof(measurement_reference));
    index += sizeof(measurement_reference);
    memcpy(&validity, buf + index, sizeof(validity));
    index += sizeof(validity);
    memcpy(&negative_voltage_volt, buf + index, sizeof(negative_voltage_volt));
    index += sizeof(negative_voltage_volt);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_I2CBusStarted_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint32_t frequency_hertz;
  static_assert((sizeof(frequency_hertz) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerCAN_I2CBusStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 231;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum PowerCAN_I2CBus value) { bus = value; }
  void set_frequency_hertz(uint32_t value) { frequency_hertz = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_I2CBus get_bus() { return bus; }
  uint32_t get_frequency_hertz() { return frequency_hertz; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &frequency_hertz, sizeof(frequency_hertz));
    *index += sizeof(frequency_hertz);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&frequency_hertz, buf + index, sizeof(frequency_hertz));
    index += sizeof(frequency_hertz);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_I2CSearchStarted_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_I2CSearchStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 232;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum PowerCAN_I2CBus value) { bus = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_I2CBus get_bus() { return bus; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_I2CSearchFoundDevice_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t found_device_address;
  static_assert((sizeof(found_device_address) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PowerCAN_I2CSearchFoundDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 233;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum PowerCAN_I2CBus value) { bus = value; }
  void set_found_device_address(uint8_t value) { found_device_address = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_I2CBus get_bus() { return bus; }
  uint8_t get_found_device_address() { return found_device_address; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &found_device_address, sizeof(found_device_address));
    *index += sizeof(found_device_address);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&found_device_address, buf + index, sizeof(found_device_address));
    index += sizeof(found_device_address);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_I2CSearchMissingDevice_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t missing_device_address;
  static_assert((sizeof(missing_device_address) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PowerCAN_I2CSearchMissingDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 234;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum PowerCAN_I2CBus value) { bus = value; }
  void set_missing_device_address(uint8_t value) {
    missing_device_address = value;
  }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_I2CBus get_bus() { return bus; }
  uint8_t get_missing_device_address() { return missing_device_address; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &missing_device_address,
           sizeof(missing_device_address));
    *index += sizeof(missing_device_address);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&missing_device_address, buf + index,
           sizeof(missing_device_address));
    index += sizeof(missing_device_address);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_I2CSearchEnded_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t devices_successfully_found;
  static_assert((sizeof(devices_successfully_found) == 1), "invalid size");
  uint8_t addresses_with_error;
  static_assert((sizeof(addresses_with_error) == 1), "invalid size");
  uint32_t search_time_us;
  static_assert((sizeof(search_time_us) == 4), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PowerCAN_I2CSearchEnded;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 235;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum PowerCAN_I2CBus value) { bus = value; }
  void set_devices_successfully_found(uint8_t value) {
    devices_successfully_found = value;
  }
  void set_addresses_with_error(uint8_t value) { addresses_with_error = value; }
  void set_search_time_us(uint32_t value) { search_time_us = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_I2CBus get_bus() { return bus; }
  uint8_t get_devices_successfully_found() {
    return devices_successfully_found;
  }
  uint8_t get_addresses_with_error() { return addresses_with_error; }
  uint32_t get_search_time_us() { return search_time_us; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &devices_successfully_found,
           sizeof(devices_successfully_found));
    *index += sizeof(devices_successfully_found);
    memcpy(buf + *index, &addresses_with_error, sizeof(addresses_with_error));
    *index += sizeof(addresses_with_error);
    memcpy(buf + *index, &search_time_us, sizeof(search_time_us));
    *index += sizeof(search_time_us);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&devices_successfully_found, buf + index,
           sizeof(devices_successfully_found));
    index += sizeof(devices_successfully_found);
    memcpy(&addresses_with_error, buf + index, sizeof(addresses_with_error));
    index += sizeof(addresses_with_error);
    memcpy(&search_time_us, buf + index, sizeof(search_time_us));
    index += sizeof(search_time_us);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class PowerCAN_LTC2992Error_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_LTC2992Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  enum PowerCAN_LTC2992ErrorLocation location;
  static_assert((sizeof(location) == 1), "invalid size");
  uint8_t register_address;
  static_assert((sizeof(register_address) == 1), "invalid size");
  uint8_t read_data;
  static_assert((sizeof(read_data) == 1), "invalid size");
  uint8_t write_data;
  static_assert((sizeof(write_data) == 1), "invalid size");
  uint8_t expected_data;
  static_assert((sizeof(expected_data) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PowerCAN_LTC2992Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 236;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerCAN_LTC2992Error value) { error = value; }
  void set_location(enum PowerCAN_LTC2992ErrorLocation value) {
    location = value;
  }
  void set_register_address(uint8_t value) { register_address = value; }
  void set_read_data(uint8_t value) { read_data = value; }
  void set_write_data(uint8_t value) { write_data = value; }
  void set_expected_data(uint8_t value) { expected_data = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_LTC2992Error get_error() { return error; }
  enum PowerCAN_LTC2992ErrorLocation get_location() { return location; }
  uint8_t get_register_address() { return register_address; }
  uint8_t get_read_data() { return read_data; }
  uint8_t get_write_data() { return write_data; }
  uint8_t get_expected_data() { return expected_data; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &location, sizeof(location));
    *index += sizeof(location);
    memcpy(buf + *index, &register_address, sizeof(register_address));
    *index += sizeof(register_address);
    memcpy(buf + *index, &read_data, sizeof(read_data));
    *index += sizeof(read_data);
    memcpy(buf + *index, &write_data, sizeof(write_data));
    *index += sizeof(write_data);
    memcpy(buf + *index, &expected_data, sizeof(expected_data));
    *index += sizeof(expected_data);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&location, buf + index, sizeof(location));
    index += sizeof(location);
    memcpy(&register_address, buf + index, sizeof(register_address));
    index += sizeof(register_address);
    memcpy(&read_data, buf + index, sizeof(read_data));
    index += sizeof(read_data);
    memcpy(&write_data, buf + index, sizeof(write_data));
    index += sizeof(write_data);
    memcpy(&expected_data, buf + index, sizeof(expected_data));
    index += sizeof(expected_data);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ADS122C04Error_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_ADS122C04Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  enum PowerCAN_ADS122C04ErrorLocation location;
  static_assert((sizeof(location) == 1), "invalid size");
  uint8_t register_address;
  static_assert((sizeof(register_address) == 1), "invalid size");
  uint8_t read_data;
  static_assert((sizeof(read_data) == 1), "invalid size");
  uint8_t write_data;
  static_assert((sizeof(write_data) == 1), "invalid size");
  uint8_t expected_data;
  static_assert((sizeof(expected_data) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PowerCAN_ADS122C04Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 237;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerCAN_ADS122C04Error value) { error = value; }
  void set_location(enum PowerCAN_ADS122C04ErrorLocation value) {
    location = value;
  }
  void set_register_address(uint8_t value) { register_address = value; }
  void set_read_data(uint8_t value) { read_data = value; }
  void set_write_data(uint8_t value) { write_data = value; }
  void set_expected_data(uint8_t value) { expected_data = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_ADS122C04Error get_error() { return error; }
  enum PowerCAN_ADS122C04ErrorLocation get_location() { return location; }
  uint8_t get_register_address() { return register_address; }
  uint8_t get_read_data() { return read_data; }
  uint8_t get_write_data() { return write_data; }
  uint8_t get_expected_data() { return expected_data; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &location, sizeof(location));
    *index += sizeof(location);
    memcpy(buf + *index, &register_address, sizeof(register_address));
    *index += sizeof(register_address);
    memcpy(buf + *index, &read_data, sizeof(read_data));
    *index += sizeof(read_data);
    memcpy(buf + *index, &write_data, sizeof(write_data));
    *index += sizeof(write_data);
    memcpy(buf + *index, &expected_data, sizeof(expected_data));
    *index += sizeof(expected_data);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&location, buf + index, sizeof(location));
    index += sizeof(location);
    memcpy(&register_address, buf + index, sizeof(register_address));
    index += sizeof(register_address);
    memcpy(&read_data, buf + index, sizeof(read_data));
    index += sizeof(read_data);
    memcpy(&write_data, buf + index, sizeof(write_data));
    index += sizeof(write_data);
    memcpy(&expected_data, buf + index, sizeof(expected_data));
    index += sizeof(expected_data);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_I2CSearchError_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  enum PowerCAN_I2CError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t scanned_address;
  static_assert((sizeof(scanned_address) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PowerCAN_I2CSearchError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 238;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum PowerCAN_I2CBus value) { bus = value; }
  void set_error(enum PowerCAN_I2CError value) { error = value; }
  void set_scanned_address(uint8_t value) { scanned_address = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  enum PowerCAN_I2CBus get_bus() { return bus; }
  enum PowerCAN_I2CError get_error() { return error; }
  uint8_t get_scanned_address() { return scanned_address; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &scanned_address, sizeof(scanned_address));
    *index += sizeof(scanned_address);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&scanned_address, buf + index, sizeof(scanned_address));
    index += sizeof(scanned_address);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class
    PowerCAN_ErrorStatistics_from_Edda_Power_Control_Boards_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t warning_count;
  static_assert((sizeof(warning_count) == 2), "invalid size");
  uint16_t error_count;
  static_assert((sizeof(error_count) == 2), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PowerCAN_ErrorStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Power_Control_Boards;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 239;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_warning_count(uint16_t value) { warning_count = value; }
  void set_error_count(uint16_t value) { error_count = value; }
  void set_powercan_channel(enum PowerCANChannel value) {
    powercan_channel = value;
  }
  uint16_t get_warning_count() { return warning_count; }
  uint16_t get_error_count() { return error_count; }
  enum PowerCANChannel get_powercan_channel() { return powercan_channel; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &warning_count, sizeof(warning_count));
    *index += sizeof(warning_count);
    memcpy(buf + *index, &error_count, sizeof(error_count));
    *index += sizeof(error_count);
    memcpy(buf + *index, &powercan_channel, sizeof(powercan_channel));
    *index += sizeof(powercan_channel);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&warning_count, buf + index, sizeof(warning_count));
    index += sizeof(warning_count);
    memcpy(&error_count, buf + index, sizeof(error_count));
    index += sizeof(error_count);
    memcpy(&powercan_channel, buf + index, sizeof(powercan_channel));
    index += sizeof(powercan_channel);
  }
};

class DS2482Error_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum DS2482Error error;
  static_assert((sizeof(error) == 1), "invalid size");
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum OneWireBus bus_index;
  static_assert((sizeof(bus_index) == 1), "invalid size");
  uint8_t position_on_bus;
  static_assert((sizeof(position_on_bus) == 1), "invalid size");
  uint8_t position_on_board;
  static_assert((sizeof(position_on_board) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::DS2482Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 442;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum DS2482Error value) { error = value; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_bus_index(enum OneWireBus value) { bus_index = value; }
  void set_position_on_bus(uint8_t value) { position_on_bus = value; }
  void set_position_on_board(uint8_t value) { position_on_board = value; }
  enum DS2482Error get_error() { return error; }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum OneWireBus get_bus_index() { return bus_index; }
  uint8_t get_position_on_bus() { return position_on_bus; }
  uint8_t get_position_on_board() { return position_on_board; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &bus_index, sizeof(bus_index));
    *index += sizeof(bus_index);
    memcpy(buf + *index, &position_on_bus, sizeof(position_on_bus));
    *index += sizeof(position_on_bus);
    memcpy(buf + *index, &position_on_board, sizeof(position_on_board));
    *index += sizeof(position_on_board);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&bus_index, buf + index, sizeof(bus_index));
    index += sizeof(bus_index);
    memcpy(&position_on_bus, buf + index, sizeof(position_on_bus));
    index += sizeof(position_on_bus);
    memcpy(&position_on_board, buf + index, sizeof(position_on_board));
    index += sizeof(position_on_board);
  }
};

class PartialDebugMessage1_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 450;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  uint8_t get_byte0() { return byte0; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
  }
};

class PartialDebugMessage1_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 451;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  uint8_t get_byte0() { return byte0; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
  }
};

class PartialDebugMessage1_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 452;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  uint8_t get_byte0() { return byte0; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
  }
};

class PartialDebugMessage1_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 453;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  uint8_t get_byte0() { return byte0; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
  }
};

class OneWireSearchStarted_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint32_t start_time_ms;
  static_assert((sizeof(start_time_ms) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::OneWireSearchStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 462;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_start_time_ms(uint32_t value) { start_time_ms = value; }
  enum OneWireBus get_bus() { return bus; }
  uint32_t get_start_time_ms() { return start_time_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &start_time_ms, sizeof(start_time_ms));
    *index += sizeof(start_time_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&start_time_ms, buf + index, sizeof(start_time_ms));
    index += sizeof(start_time_ms);
  }
};

class I2CBusStarted_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint32_t frequency_hertz;
  static_assert((sizeof(frequency_hertz) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::I2CBusStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 467;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_frequency_hertz(uint32_t value) { frequency_hertz = value; }
  enum I2CBus get_bus() { return bus; }
  uint32_t get_frequency_hertz() { return frequency_hertz; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &frequency_hertz, sizeof(frequency_hertz));
    *index += sizeof(frequency_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&frequency_hertz, buf + index, sizeof(frequency_hertz));
    index += sizeof(frequency_hertz);
  }
};

class I2CBusStarted_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint32_t frequency_hertz;
  static_assert((sizeof(frequency_hertz) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::I2CBusStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 468;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_frequency_hertz(uint32_t value) { frequency_hertz = value; }
  enum I2CBus get_bus() { return bus; }
  uint32_t get_frequency_hertz() { return frequency_hertz; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &frequency_hertz, sizeof(frequency_hertz));
    *index += sizeof(frequency_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&frequency_hertz, buf + index, sizeof(frequency_hertz));
    index += sizeof(frequency_hertz);
  }
};

class I2CBusStarted_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint32_t frequency_hertz;
  static_assert((sizeof(frequency_hertz) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::I2CBusStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 469;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_frequency_hertz(uint32_t value) { frequency_hertz = value; }
  enum I2CBus get_bus() { return bus; }
  uint32_t get_frequency_hertz() { return frequency_hertz; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &frequency_hertz, sizeof(frequency_hertz));
    *index += sizeof(frequency_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&frequency_hertz, buf + index, sizeof(frequency_hertz));
    index += sizeof(frequency_hertz);
  }
};

class I2CBusStarted_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint32_t frequency_hertz;
  static_assert((sizeof(frequency_hertz) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::I2CBusStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 470;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_frequency_hertz(uint32_t value) { frequency_hertz = value; }
  enum I2CBus get_bus() { return bus; }
  uint32_t get_frequency_hertz() { return frequency_hertz; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &frequency_hertz, sizeof(frequency_hertz));
    *index += sizeof(frequency_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&frequency_hertz, buf + index, sizeof(frequency_hertz));
    index += sizeof(frequency_hertz);
  }
};

class DS28E18QError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum DS28E18QError error;
  static_assert((sizeof(error) == 1), "invalid size");
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum OneWireBus bus_index;
  static_assert((sizeof(bus_index) == 1), "invalid size");
  uint8_t position_on_bus;
  static_assert((sizeof(position_on_bus) == 1), "invalid size");
  uint8_t position_on_board;
  static_assert((sizeof(position_on_board) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::DS28E18QError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 698;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum DS28E18QError value) { error = value; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_bus_index(enum OneWireBus value) { bus_index = value; }
  void set_position_on_bus(uint8_t value) { position_on_bus = value; }
  void set_position_on_board(uint8_t value) { position_on_board = value; }
  enum DS28E18QError get_error() { return error; }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum OneWireBus get_bus_index() { return bus_index; }
  uint8_t get_position_on_bus() { return position_on_bus; }
  uint8_t get_position_on_board() { return position_on_board; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &bus_index, sizeof(bus_index));
    *index += sizeof(bus_index);
    memcpy(buf + *index, &position_on_bus, sizeof(position_on_bus));
    *index += sizeof(position_on_bus);
    memcpy(buf + *index, &position_on_board, sizeof(position_on_board));
    *index += sizeof(position_on_board);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&bus_index, buf + index, sizeof(bus_index));
    index += sizeof(bus_index);
    memcpy(&position_on_bus, buf + index, sizeof(position_on_bus));
    index += sizeof(position_on_bus);
    memcpy(&position_on_board, buf + index, sizeof(position_on_board));
    index += sizeof(position_on_board);
  }
};

class PartialDebugMessage2_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 706;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
  }
};

class PartialDebugMessage2_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 707;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
  }
};

class PartialDebugMessage2_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 708;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
  }
};

class PartialDebugMessage2_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 709;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
  }
};

class OneWireSearchEnded_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t searched_family_code;
  static_assert((sizeof(searched_family_code) == 1), "invalid size");
  uint8_t devices_successfully_found;
  static_assert((sizeof(devices_successfully_found) == 1), "invalid size");
  uint8_t devices_insuccessfully_found;
  static_assert((sizeof(devices_insuccessfully_found) == 1), "invalid size");
  uint16_t search_time_ms;
  static_assert((sizeof(search_time_ms) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::OneWireSearchEnded;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 718;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_searched_family_code(uint8_t value) { searched_family_code = value; }
  void set_devices_successfully_found(uint8_t value) {
    devices_successfully_found = value;
  }
  void set_devices_insuccessfully_found(uint8_t value) {
    devices_insuccessfully_found = value;
  }
  void set_search_time_ms(uint16_t value) { search_time_ms = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_searched_family_code() { return searched_family_code; }
  uint8_t get_devices_successfully_found() {
    return devices_successfully_found;
  }
  uint8_t get_devices_insuccessfully_found() {
    return devices_insuccessfully_found;
  }
  uint16_t get_search_time_ms() { return search_time_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &searched_family_code, sizeof(searched_family_code));
    *index += sizeof(searched_family_code);
    memcpy(buf + *index, &devices_successfully_found,
           sizeof(devices_successfully_found));
    *index += sizeof(devices_successfully_found);
    memcpy(buf + *index, &devices_insuccessfully_found,
           sizeof(devices_insuccessfully_found));
    *index += sizeof(devices_insuccessfully_found);
    memcpy(buf + *index, &search_time_ms, sizeof(search_time_ms));
    *index += sizeof(search_time_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&searched_family_code, buf + index, sizeof(searched_family_code));
    index += sizeof(searched_family_code);
    memcpy(&devices_successfully_found, buf + index,
           sizeof(devices_successfully_found));
    index += sizeof(devices_successfully_found);
    memcpy(&devices_insuccessfully_found, buf + index,
           sizeof(devices_insuccessfully_found));
    index += sizeof(devices_insuccessfully_found);
    memcpy(&search_time_ms, buf + index, sizeof(search_time_ms));
    index += sizeof(search_time_ms);
  }
};

class I2CSearchStarted_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::I2CSearchStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 723;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  enum I2CBus get_bus() { return bus; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
  }
};

class I2CSearchStarted_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::I2CSearchStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 724;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  enum I2CBus get_bus() { return bus; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
  }
};

class I2CSearchStarted_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::I2CSearchStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 725;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  enum I2CBus get_bus() { return bus; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
  }
};

class I2CSearchStarted_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::I2CSearchStarted;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 726;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  enum I2CBus get_bus() { return bus; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
  }
};

class MAX31850KError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum MAX31850KError error;
  static_assert((sizeof(error) == 1), "invalid size");
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum ThermocoupleIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::MAX31850KError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 954;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum MAX31850KError value) { error = value; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum ThermocoupleIndex value) { sensor_index = value; }
  enum MAX31850KError get_error() { return error; }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum ThermocoupleIndex get_sensor_index() { return sensor_index; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
  }
};

class PartialDebugMessage3_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 962;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
  }
};

class PartialDebugMessage3_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 963;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
  }
};

class PartialDebugMessage3_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 964;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
  }
};

class PartialDebugMessage3_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 965;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
  }
};

class OneWireDeviceStartupSuccess_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t serial_byte0;
  static_assert((sizeof(serial_byte0) == 1), "invalid size");
  uint8_t serial_byte1;
  static_assert((sizeof(serial_byte1) == 1), "invalid size");
  uint8_t serial_byte2;
  static_assert((sizeof(serial_byte2) == 1), "invalid size");
  uint8_t serial_byte3;
  static_assert((sizeof(serial_byte3) == 1), "invalid size");
  uint8_t serial_byte4;
  static_assert((sizeof(serial_byte4) == 1), "invalid size");
  uint8_t serial_byte5;
  static_assert((sizeof(serial_byte5) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::OneWireDeviceStartupSuccess;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 974;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_serial_byte0(uint8_t value) { serial_byte0 = value; }
  void set_serial_byte1(uint8_t value) { serial_byte1 = value; }
  void set_serial_byte2(uint8_t value) { serial_byte2 = value; }
  void set_serial_byte3(uint8_t value) { serial_byte3 = value; }
  void set_serial_byte4(uint8_t value) { serial_byte4 = value; }
  void set_serial_byte5(uint8_t value) { serial_byte5 = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_serial_byte0() { return serial_byte0; }
  uint8_t get_serial_byte1() { return serial_byte1; }
  uint8_t get_serial_byte2() { return serial_byte2; }
  uint8_t get_serial_byte3() { return serial_byte3; }
  uint8_t get_serial_byte4() { return serial_byte4; }
  uint8_t get_serial_byte5() { return serial_byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &serial_byte0, sizeof(serial_byte0));
    *index += sizeof(serial_byte0);
    memcpy(buf + *index, &serial_byte1, sizeof(serial_byte1));
    *index += sizeof(serial_byte1);
    memcpy(buf + *index, &serial_byte2, sizeof(serial_byte2));
    *index += sizeof(serial_byte2);
    memcpy(buf + *index, &serial_byte3, sizeof(serial_byte3));
    *index += sizeof(serial_byte3);
    memcpy(buf + *index, &serial_byte4, sizeof(serial_byte4));
    *index += sizeof(serial_byte4);
    memcpy(buf + *index, &serial_byte5, sizeof(serial_byte5));
    *index += sizeof(serial_byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&serial_byte0, buf + index, sizeof(serial_byte0));
    index += sizeof(serial_byte0);
    memcpy(&serial_byte1, buf + index, sizeof(serial_byte1));
    index += sizeof(serial_byte1);
    memcpy(&serial_byte2, buf + index, sizeof(serial_byte2));
    index += sizeof(serial_byte2);
    memcpy(&serial_byte3, buf + index, sizeof(serial_byte3));
    index += sizeof(serial_byte3);
    memcpy(&serial_byte4, buf + index, sizeof(serial_byte4));
    index += sizeof(serial_byte4);
    memcpy(&serial_byte5, buf + index, sizeof(serial_byte5));
    index += sizeof(serial_byte5);
  }
};

class I2CSearchError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  enum I2CError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t scanned_address;
  static_assert((sizeof(scanned_address) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::I2CSearchError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 979;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_error(enum I2CError value) { error = value; }
  void set_scanned_address(uint8_t value) { scanned_address = value; }
  enum I2CBus get_bus() { return bus; }
  enum I2CError get_error() { return error; }
  uint8_t get_scanned_address() { return scanned_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &scanned_address, sizeof(scanned_address));
    *index += sizeof(scanned_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&scanned_address, buf + index, sizeof(scanned_address));
    index += sizeof(scanned_address);
  }
};

class I2CSearchError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  enum I2CError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t scanned_address;
  static_assert((sizeof(scanned_address) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::I2CSearchError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 980;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_error(enum I2CError value) { error = value; }
  void set_scanned_address(uint8_t value) { scanned_address = value; }
  enum I2CBus get_bus() { return bus; }
  enum I2CError get_error() { return error; }
  uint8_t get_scanned_address() { return scanned_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &scanned_address, sizeof(scanned_address));
    *index += sizeof(scanned_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&scanned_address, buf + index, sizeof(scanned_address));
    index += sizeof(scanned_address);
  }
};

class I2CSearchError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  enum I2CError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t scanned_address;
  static_assert((sizeof(scanned_address) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::I2CSearchError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 981;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_error(enum I2CError value) { error = value; }
  void set_scanned_address(uint8_t value) { scanned_address = value; }
  enum I2CBus get_bus() { return bus; }
  enum I2CError get_error() { return error; }
  uint8_t get_scanned_address() { return scanned_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &scanned_address, sizeof(scanned_address));
    *index += sizeof(scanned_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&scanned_address, buf + index, sizeof(scanned_address));
    index += sizeof(scanned_address);
  }
};

class I2CSearchError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  enum I2CError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t scanned_address;
  static_assert((sizeof(scanned_address) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::I2CSearchError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 982;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_error(enum I2CError value) { error = value; }
  void set_scanned_address(uint8_t value) { scanned_address = value; }
  enum I2CBus get_bus() { return bus; }
  enum I2CError get_error() { return error; }
  uint8_t get_scanned_address() { return scanned_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
    memcpy(buf + *index, &scanned_address, sizeof(scanned_address));
    *index += sizeof(scanned_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
    memcpy(&scanned_address, buf + index, sizeof(scanned_address));
    index += sizeof(scanned_address);
  }
};

class MAX31856Error_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum ThermocoupleIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t raw_fault_register;
  static_assert((sizeof(raw_fault_register) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::MAX31856Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1210;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum ThermocoupleIndex value) { sensor_index = value; }
  void set_raw_fault_register(uint8_t value) { raw_fault_register = value; }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum ThermocoupleIndex get_sensor_index() { return sensor_index; }
  uint8_t get_raw_fault_register() { return raw_fault_register; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &raw_fault_register, sizeof(raw_fault_register));
    *index += sizeof(raw_fault_register);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&raw_fault_register, buf + index, sizeof(raw_fault_register));
    index += sizeof(raw_fault_register);
  }
};

class PartialDebugMessage4_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1218;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
  }
};

class PartialDebugMessage4_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1219;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
  }
};

class PartialDebugMessage4_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1220;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
  }
};

class PartialDebugMessage4_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1221;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
  }
};

class OneWireDeviceStartupFailure_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum OneWireBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t serial_byte0;
  static_assert((sizeof(serial_byte0) == 1), "invalid size");
  uint8_t serial_byte1;
  static_assert((sizeof(serial_byte1) == 1), "invalid size");
  uint8_t serial_byte2;
  static_assert((sizeof(serial_byte2) == 1), "invalid size");
  uint8_t serial_byte3;
  static_assert((sizeof(serial_byte3) == 1), "invalid size");
  uint8_t serial_byte4;
  static_assert((sizeof(serial_byte4) == 1), "invalid size");
  uint8_t serial_byte5;
  static_assert((sizeof(serial_byte5) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::OneWireDeviceStartupFailure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1230;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum OneWireBus value) { bus = value; }
  void set_serial_byte0(uint8_t value) { serial_byte0 = value; }
  void set_serial_byte1(uint8_t value) { serial_byte1 = value; }
  void set_serial_byte2(uint8_t value) { serial_byte2 = value; }
  void set_serial_byte3(uint8_t value) { serial_byte3 = value; }
  void set_serial_byte4(uint8_t value) { serial_byte4 = value; }
  void set_serial_byte5(uint8_t value) { serial_byte5 = value; }
  enum OneWireBus get_bus() { return bus; }
  uint8_t get_serial_byte0() { return serial_byte0; }
  uint8_t get_serial_byte1() { return serial_byte1; }
  uint8_t get_serial_byte2() { return serial_byte2; }
  uint8_t get_serial_byte3() { return serial_byte3; }
  uint8_t get_serial_byte4() { return serial_byte4; }
  uint8_t get_serial_byte5() { return serial_byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &serial_byte0, sizeof(serial_byte0));
    *index += sizeof(serial_byte0);
    memcpy(buf + *index, &serial_byte1, sizeof(serial_byte1));
    *index += sizeof(serial_byte1);
    memcpy(buf + *index, &serial_byte2, sizeof(serial_byte2));
    *index += sizeof(serial_byte2);
    memcpy(buf + *index, &serial_byte3, sizeof(serial_byte3));
    *index += sizeof(serial_byte3);
    memcpy(buf + *index, &serial_byte4, sizeof(serial_byte4));
    *index += sizeof(serial_byte4);
    memcpy(buf + *index, &serial_byte5, sizeof(serial_byte5));
    *index += sizeof(serial_byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&serial_byte0, buf + index, sizeof(serial_byte0));
    index += sizeof(serial_byte0);
    memcpy(&serial_byte1, buf + index, sizeof(serial_byte1));
    index += sizeof(serial_byte1);
    memcpy(&serial_byte2, buf + index, sizeof(serial_byte2));
    index += sizeof(serial_byte2);
    memcpy(&serial_byte3, buf + index, sizeof(serial_byte3));
    index += sizeof(serial_byte3);
    memcpy(&serial_byte4, buf + index, sizeof(serial_byte4));
    index += sizeof(serial_byte4);
    memcpy(&serial_byte5, buf + index, sizeof(serial_byte5));
    index += sizeof(serial_byte5);
  }
};

class I2CSearchFoundDevice_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t found_device_address;
  static_assert((sizeof(found_device_address) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::I2CSearchFoundDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1235;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_found_device_address(uint8_t value) { found_device_address = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_found_device_address() { return found_device_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &found_device_address, sizeof(found_device_address));
    *index += sizeof(found_device_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&found_device_address, buf + index, sizeof(found_device_address));
    index += sizeof(found_device_address);
  }
};

class I2CSearchFoundDevice_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t found_device_address;
  static_assert((sizeof(found_device_address) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::I2CSearchFoundDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1236;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_found_device_address(uint8_t value) { found_device_address = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_found_device_address() { return found_device_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &found_device_address, sizeof(found_device_address));
    *index += sizeof(found_device_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&found_device_address, buf + index, sizeof(found_device_address));
    index += sizeof(found_device_address);
  }
};

class I2CSearchFoundDevice_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t found_device_address;
  static_assert((sizeof(found_device_address) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::I2CSearchFoundDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1237;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_found_device_address(uint8_t value) { found_device_address = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_found_device_address() { return found_device_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &found_device_address, sizeof(found_device_address));
    *index += sizeof(found_device_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&found_device_address, buf + index, sizeof(found_device_address));
    index += sizeof(found_device_address);
  }
};

class I2CSearchFoundDevice_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t found_device_address;
  static_assert((sizeof(found_device_address) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::I2CSearchFoundDevice;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1238;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_found_device_address(uint8_t value) { found_device_address = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_found_device_address() { return found_device_address; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &found_device_address, sizeof(found_device_address));
    *index += sizeof(found_device_address);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&found_device_address, buf + index, sizeof(found_device_address));
    index += sizeof(found_device_address);
  }
};

class MAX31865Error_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum TemperatureBoardIndex board_index;
  static_assert((sizeof(board_index) == 1), "invalid size");
  enum PlatinumSensorIndex sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t raw_fault_register;
  static_assert((sizeof(raw_fault_register) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::MAX31865Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1466;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_board_index(enum TemperatureBoardIndex value) {
    board_index = value;
  }
  void set_sensor_index(enum PlatinumSensorIndex value) {
    sensor_index = value;
  }
  void set_raw_fault_register(uint8_t value) { raw_fault_register = value; }
  enum TemperatureBoardIndex get_board_index() { return board_index; }
  enum PlatinumSensorIndex get_sensor_index() { return sensor_index; }
  uint8_t get_raw_fault_register() { return raw_fault_register; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &board_index, sizeof(board_index));
    *index += sizeof(board_index);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &raw_fault_register, sizeof(raw_fault_register));
    *index += sizeof(raw_fault_register);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&board_index, buf + index, sizeof(board_index));
    index += sizeof(board_index);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&raw_fault_register, buf + index, sizeof(raw_fault_register));
    index += sizeof(raw_fault_register);
  }
};

class PartialDebugMessage5_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1474;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
  }
};

class PartialDebugMessage5_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1475;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
  }
};

class PartialDebugMessage5_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1476;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
  }
};

class PartialDebugMessage5_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1477;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
  }
};

class I2CSearchEnded_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t devices_successfully_found;
  static_assert((sizeof(devices_successfully_found) == 1), "invalid size");
  uint8_t addresses_with_error;
  static_assert((sizeof(addresses_with_error) == 1), "invalid size");
  uint32_t search_time_us;
  static_assert((sizeof(search_time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::I2CSearchEnded;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1491;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_devices_successfully_found(uint8_t value) {
    devices_successfully_found = value;
  }
  void set_addresses_with_error(uint8_t value) { addresses_with_error = value; }
  void set_search_time_us(uint32_t value) { search_time_us = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_devices_successfully_found() {
    return devices_successfully_found;
  }
  uint8_t get_addresses_with_error() { return addresses_with_error; }
  uint32_t get_search_time_us() { return search_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &devices_successfully_found,
           sizeof(devices_successfully_found));
    *index += sizeof(devices_successfully_found);
    memcpy(buf + *index, &addresses_with_error, sizeof(addresses_with_error));
    *index += sizeof(addresses_with_error);
    memcpy(buf + *index, &search_time_us, sizeof(search_time_us));
    *index += sizeof(search_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&devices_successfully_found, buf + index,
           sizeof(devices_successfully_found));
    index += sizeof(devices_successfully_found);
    memcpy(&addresses_with_error, buf + index, sizeof(addresses_with_error));
    index += sizeof(addresses_with_error);
    memcpy(&search_time_us, buf + index, sizeof(search_time_us));
    index += sizeof(search_time_us);
  }
};

class I2CSearchEnded_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t devices_successfully_found;
  static_assert((sizeof(devices_successfully_found) == 1), "invalid size");
  uint8_t addresses_with_error;
  static_assert((sizeof(addresses_with_error) == 1), "invalid size");
  uint32_t search_time_us;
  static_assert((sizeof(search_time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::I2CSearchEnded;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1492;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_devices_successfully_found(uint8_t value) {
    devices_successfully_found = value;
  }
  void set_addresses_with_error(uint8_t value) { addresses_with_error = value; }
  void set_search_time_us(uint32_t value) { search_time_us = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_devices_successfully_found() {
    return devices_successfully_found;
  }
  uint8_t get_addresses_with_error() { return addresses_with_error; }
  uint32_t get_search_time_us() { return search_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &devices_successfully_found,
           sizeof(devices_successfully_found));
    *index += sizeof(devices_successfully_found);
    memcpy(buf + *index, &addresses_with_error, sizeof(addresses_with_error));
    *index += sizeof(addresses_with_error);
    memcpy(buf + *index, &search_time_us, sizeof(search_time_us));
    *index += sizeof(search_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&devices_successfully_found, buf + index,
           sizeof(devices_successfully_found));
    index += sizeof(devices_successfully_found);
    memcpy(&addresses_with_error, buf + index, sizeof(addresses_with_error));
    index += sizeof(addresses_with_error);
    memcpy(&search_time_us, buf + index, sizeof(search_time_us));
    index += sizeof(search_time_us);
  }
};

class I2CSearchEnded_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t devices_successfully_found;
  static_assert((sizeof(devices_successfully_found) == 1), "invalid size");
  uint8_t addresses_with_error;
  static_assert((sizeof(addresses_with_error) == 1), "invalid size");
  uint32_t search_time_us;
  static_assert((sizeof(search_time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::I2CSearchEnded;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1493;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_devices_successfully_found(uint8_t value) {
    devices_successfully_found = value;
  }
  void set_addresses_with_error(uint8_t value) { addresses_with_error = value; }
  void set_search_time_us(uint32_t value) { search_time_us = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_devices_successfully_found() {
    return devices_successfully_found;
  }
  uint8_t get_addresses_with_error() { return addresses_with_error; }
  uint32_t get_search_time_us() { return search_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &devices_successfully_found,
           sizeof(devices_successfully_found));
    *index += sizeof(devices_successfully_found);
    memcpy(buf + *index, &addresses_with_error, sizeof(addresses_with_error));
    *index += sizeof(addresses_with_error);
    memcpy(buf + *index, &search_time_us, sizeof(search_time_us));
    *index += sizeof(search_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&devices_successfully_found, buf + index,
           sizeof(devices_successfully_found));
    index += sizeof(devices_successfully_found);
    memcpy(&addresses_with_error, buf + index, sizeof(addresses_with_error));
    index += sizeof(addresses_with_error);
    memcpy(&search_time_us, buf + index, sizeof(search_time_us));
    index += sizeof(search_time_us);
  }
};

class I2CSearchEnded_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum I2CBus bus;
  static_assert((sizeof(bus) == 1), "invalid size");
  uint8_t devices_successfully_found;
  static_assert((sizeof(devices_successfully_found) == 1), "invalid size");
  uint8_t addresses_with_error;
  static_assert((sizeof(addresses_with_error) == 1), "invalid size");
  uint32_t search_time_us;
  static_assert((sizeof(search_time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::I2CSearchEnded;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1494;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus(enum I2CBus value) { bus = value; }
  void set_devices_successfully_found(uint8_t value) {
    devices_successfully_found = value;
  }
  void set_addresses_with_error(uint8_t value) { addresses_with_error = value; }
  void set_search_time_us(uint32_t value) { search_time_us = value; }
  enum I2CBus get_bus() { return bus; }
  uint8_t get_devices_successfully_found() {
    return devices_successfully_found;
  }
  uint8_t get_addresses_with_error() { return addresses_with_error; }
  uint32_t get_search_time_us() { return search_time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus, sizeof(bus));
    *index += sizeof(bus);
    memcpy(buf + *index, &devices_successfully_found,
           sizeof(devices_successfully_found));
    *index += sizeof(devices_successfully_found);
    memcpy(buf + *index, &addresses_with_error, sizeof(addresses_with_error));
    *index += sizeof(addresses_with_error);
    memcpy(buf + *index, &search_time_us, sizeof(search_time_us));
    *index += sizeof(search_time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus, buf + index, sizeof(bus));
    index += sizeof(bus);
    memcpy(&devices_successfully_found, buf + index,
           sizeof(devices_successfully_found));
    index += sizeof(devices_successfully_found);
    memcpy(&addresses_with_error, buf + index, sizeof(addresses_with_error));
    index += sizeof(addresses_with_error);
    memcpy(&search_time_us, buf + index, sizeof(search_time_us));
    index += sizeof(search_time_us);
  }
};

class PartialDebugMessage6_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1730;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
  }
};

class PartialDebugMessage6_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1731;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
  }
};

class PartialDebugMessage6_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1732;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
  }
};

class PartialDebugMessage6_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1733;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
  }
};

class PartialDebugMessage7_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t byte6;
  static_assert((sizeof(byte6) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1986;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
    memcpy(buf + *index, &byte6, sizeof(byte6));
    *index += sizeof(byte6);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
    memcpy(&byte6, buf + index, sizeof(byte6));
    index += sizeof(byte6);
  }
};

class PartialDebugMessage7_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t byte6;
  static_assert((sizeof(byte6) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1987;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
    memcpy(buf + *index, &byte6, sizeof(byte6));
    *index += sizeof(byte6);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
    memcpy(&byte6, buf + index, sizeof(byte6));
    index += sizeof(byte6);
  }
};

class PartialDebugMessage7_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t byte6;
  static_assert((sizeof(byte6) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1988;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
    memcpy(buf + *index, &byte6, sizeof(byte6));
    *index += sizeof(byte6);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
    memcpy(&byte6, buf + index, sizeof(byte6));
    index += sizeof(byte6);
  }
};

class PartialDebugMessage7_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t byte0;
  static_assert((sizeof(byte0) == 1), "invalid size");
  uint8_t byte1;
  static_assert((sizeof(byte1) == 1), "invalid size");
  uint8_t byte2;
  static_assert((sizeof(byte2) == 1), "invalid size");
  uint8_t byte3;
  static_assert((sizeof(byte3) == 1), "invalid size");
  uint8_t byte4;
  static_assert((sizeof(byte4) == 1), "invalid size");
  uint8_t byte5;
  static_assert((sizeof(byte5) == 1), "invalid size");
  uint8_t byte6;
  static_assert((sizeof(byte6) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1989;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &byte0, sizeof(byte0));
    *index += sizeof(byte0);
    memcpy(buf + *index, &byte1, sizeof(byte1));
    *index += sizeof(byte1);
    memcpy(buf + *index, &byte2, sizeof(byte2));
    *index += sizeof(byte2);
    memcpy(buf + *index, &byte3, sizeof(byte3));
    *index += sizeof(byte3);
    memcpy(buf + *index, &byte4, sizeof(byte4));
    *index += sizeof(byte4);
    memcpy(buf + *index, &byte5, sizeof(byte5));
    *index += sizeof(byte5);
    memcpy(buf + *index, &byte6, sizeof(byte6));
    *index += sizeof(byte6);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&byte0, buf + index, sizeof(byte0));
    index += sizeof(byte0);
    memcpy(&byte1, buf + index, sizeof(byte1));
    index += sizeof(byte1);
    memcpy(&byte2, buf + index, sizeof(byte2));
    index += sizeof(byte2);
    memcpy(&byte3, buf + index, sizeof(byte3));
    index += sizeof(byte3);
    memcpy(&byte4, buf + index, sizeof(byte4));
    index += sizeof(byte4);
    memcpy(&byte5, buf + index, sizeof(byte5));
    index += sizeof(byte5);
    memcpy(&byte6, buf + index, sizeof(byte6));
    index += sizeof(byte6);
  }
};

void rx(CurrentTimePing_from_Ground_Controller_to_Edda_Controller msg);
void rx(CurrentTimePing_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(CurrentTimePong_from_Edda_Controller_to_Ground_Controller msg);
void rx(CurrentTimePong_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(SayHi_from_Ground_Controller_to_Edda_Controller msg);
void rx(SayHi_from_Ground_Controller_to_Edda_Controller msg, void *misc);
void rx(Hello_from_Edda_Controller_to_Ground_Controller msg);
void rx(Hello_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(Hello_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Hello_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(Hello_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Hello_from_Edda_Pressure_Top_to_Ground_Controller msg, void *misc);
void rx(Hello_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(Hello_from_Edda_Pressure_Bottom_to_Ground_Controller msg, void *misc);
void rx(CanStatistics_from_Edda_Controller_to_Ground_Controller msg);
void rx(CanStatistics_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(CanStatistics_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(CanStatistics_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(CanStatistics_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(CanStatistics_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(CanStatistics_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(CanStatistics_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(CanStatistics_from_Ground_Controller_to_Ground_Controller msg);
void rx(CanStatistics_from_Ground_Controller_to_Ground_Controller msg,
        void *misc);
void rx(CanLatency_from_Edda_Controller_to_Ground_Controller msg);
void rx(CanLatency_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(CanLatency_from_Ground_Controller_to_Ground_Controller msg);
void rx(CanLatency_from_Ground_Controller_to_Ground_Controller msg, void *misc);
void rx(SetDebugStatusLedsModeRequest_from_Ground_Controller_to_Edda_Controller
            msg);
void rx(
    SetDebugStatusLedsModeRequest_from_Ground_Controller_to_Edda_Controller msg,
    void *misc);
void rx(
    SetDebugMessagesModeRequest_from_Ground_Controller_to_Edda_Controller msg);
void rx(
    SetDebugMessagesModeRequest_from_Ground_Controller_to_Edda_Controller msg,
    void *misc);
void rx(PowerCAN_SetDebugMode_from_Ground_Controller_to_Edda_Controller msg);
void rx(PowerCAN_SetDebugMode_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(PowerCAN_GetState_from_Ground_Controller_to_Edda_Controller msg);
void rx(PowerCAN_GetState_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(
    PowerCAN_TransitionRequest_from_Ground_Controller_to_Edda_Controller msg);
void rx(
    PowerCAN_TransitionRequest_from_Ground_Controller_to_Edda_Controller msg,
    void *misc);
void rx(PowerCAN_SetDebugMode_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_SetDebugMode_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerCAN_GetState_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_GetState_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    PowerCAN_TransitionRequest_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    PowerCAN_TransitionRequest_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(PowerCAN_Hello_from_Edda_Power_Control_Boards_to_Ground_Controller msg);
void rx(PowerCAN_Hello_from_Edda_Power_Control_Boards_to_Ground_Controller msg,
        void *misc);
void rx(
    PowerCAN_CurrentState_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_CurrentState_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_TransitionResponse_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_TransitionResponse_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(PowerCAN_CheckResult_from_Edda_Power_Control_Boards_to_Ground_Controller
            msg);
void rx(PowerCAN_CheckResult_from_Edda_Power_Control_Boards_to_Ground_Controller
            msg,
        void *misc);
void rx(CurrentTimePing_from_Edda_Controller_to_Edda_Telemetry msg);
void rx(CurrentTimePing_from_Edda_Controller_to_Edda_Telemetry msg, void *misc);
void rx(CurrentTimePong_from_Edda_Telemetry_to_Edda_Controller msg);
void rx(CurrentTimePong_from_Edda_Telemetry_to_Edda_Controller msg, void *misc);
void rx(CurrentTimePong_from_Edda_Pressure_Top_to_Edda_Controller msg);
void rx(CurrentTimePong_from_Edda_Pressure_Top_to_Edda_Controller msg,
        void *misc);
void rx(CurrentTimePong_from_Edda_Pressure_Bottom_to_Edda_Controller msg);
void rx(CurrentTimePong_from_Edda_Pressure_Bottom_to_Edda_Controller msg,
        void *misc);
void rx(SayHi_from_Edda_Controller_to_Edda_Controller msg);
void rx(SayHi_from_Edda_Controller_to_Edda_Controller msg, void *misc);
void rx(WenHop_from_Edda_Controller_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Controller_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Telemetry_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Pressure_Top_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Pressure_Bottom_to_Flight_Controller msg, void *misc);
void rx(WenOrbit_from_Edda_Controller_to_Flight_Controller msg);
void rx(WenOrbit_from_Edda_Controller_to_Flight_Controller msg, void *misc);
void rx(WenOrbit_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(WenOrbit_from_Edda_Telemetry_to_Flight_Controller msg, void *misc);
void rx(WenOrbit_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(WenOrbit_from_Edda_Pressure_Top_to_Flight_Controller msg, void *misc);
void rx(WenOrbit_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(WenOrbit_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(PowerInputMeasurement_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerInputMeasurement_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerInputMeasurement_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(PowerInputMeasurement_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(PowerInputMeasurement_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(PowerInputMeasurement_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    PowerInputMeasurement_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    PowerInputMeasurement_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    PowerInputMeasurementError_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    PowerInputMeasurementError_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(
    PowerInputMeasurementError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(PowerInputMeasurementError_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(
    PowerInputMeasurementError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(
    PowerInputMeasurementError_from_Edda_Pressure_Top_to_Ground_Controller msg,
    void *misc);
void rx(
    PowerInputMeasurementError_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg);
void rx(
    PowerInputMeasurementError_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg,
    void *misc);
void rx(ColdSideTemperature_from_Edda_Controller_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(RawTransducerVoltage_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(RawTransducerVoltage_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    RawTransducerVoltage_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(RawTransducerVoltage_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(TransducerPressure_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TransducerPressure_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(TransducerPressure_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TransducerPressure_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(TransducerError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TransducerError_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(TransducerError_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TransducerError_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressure_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(AmbientPressure_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressure_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(AmbientPressure_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(
    AmbientPressureCoefficient_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(
    AmbientPressureCoefficient_from_Edda_Pressure_Top_to_Ground_Controller msg,
    void *misc);
void rx(
    AmbientPressureCoefficient_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg);
void rx(
    AmbientPressureCoefficient_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg,
    void *misc);
void rx(AmbientPressureError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(AmbientPressureError_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    AmbientPressureError_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(AmbientPressureError_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(PlatinumSensorTemperature_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(PlatinumSensorTemperature_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(PlatinumSensorResistance_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(PlatinumSensorResistance_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(PlatinumSensorRatio_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(PlatinumSensorRatio_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(
    ThermocoupleTypeKTemperature_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(
    ThermocoupleTypeKTemperature_from_Edda_Telemetry_to_Ground_Controller msg,
    void *misc);
void rx(ThermocoupleColdsideTemperature_from_Edda_Telemetry_to_Ground_Controller
            msg);
void rx(ThermocoupleColdsideTemperature_from_Edda_Telemetry_to_Ground_Controller
            msg,
        void *misc);
void rx(Humidity_from_Edda_Controller_to_Ground_Controller msg);
void rx(Humidity_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(HumidityError_from_Edda_Controller_to_Ground_Controller msg);
void rx(HumidityError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Acceleration_from_Edda_Controller_to_Ground_Controller msg);
void rx(Acceleration_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(AccelerationError_from_Edda_Controller_to_Ground_Controller msg);
void rx(AccelerationError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(AccelerationSelfTest_from_Edda_Controller_to_Ground_Controller msg);
void rx(AccelerationSelfTest_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(AmbientLight_from_Edda_Controller_to_Ground_Controller msg);
void rx(AmbientLight_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(AmbientLightError_from_Edda_Controller_to_Ground_Controller msg);
void rx(AmbientLightError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(TaskInfo_from_Edda_Controller_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(TaskInfo_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(TaskInfo_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Pressure_Top_to_Ground_Controller msg, void *misc);
void rx(TaskInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(LoopInfo_from_Edda_Controller_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Pressure_Top_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(
    OneWireDevicePairedWithSensor_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(
    OneWireDevicePairedWithSensor_from_Edda_Telemetry_to_Ground_Controller msg,
    void *misc);
void rx(
    OneWireSearchFamilyMismatch_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(
    OneWireSearchFamilyMismatch_from_Edda_Telemetry_to_Ground_Controller msg,
    void *misc);
void rx(OneWireSearchCRCMismatch_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(OneWireSearchCRCMismatch_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(OneWireSearchFoundDevice_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(OneWireSearchFoundDevice_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(PowerCAN_Temperature_from_Edda_Power_Control_Boards_to_Ground_Controller
            msg);
void rx(PowerCAN_Temperature_from_Edda_Power_Control_Boards_to_Ground_Controller
            msg,
        void *misc);
void rx(
    PowerCAN_Voltage_from_Edda_Power_Control_Boards_to_Ground_Controller msg);
void rx(
    PowerCAN_Voltage_from_Edda_Power_Control_Boards_to_Ground_Controller msg,
    void *misc);
void rx(
    PowerCAN_ChannelMeasurementPower_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ChannelMeasurementPower_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ChannelMeasurementVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ChannelMeasurementVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ChannelMeasurementCurrent_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ChannelMeasurementCurrent_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_LoadMeasurementResistance_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_LoadMeasurementResistance_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_LoadMeasurementVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_LoadMeasurementVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_LoadMeasurementPower_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_LoadMeasurementPower_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_LoadMeasurementCurrent_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_LoadMeasurementCurrent_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_FailedLoadMeasurementValue_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_FailedLoadMeasurementValue_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_FailedLoadMeasurementThreshold_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_FailedLoadMeasurementThreshold_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ResistanceMeasurementResistance_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ResistanceMeasurementResistance_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ResistanceMeasurementReferenceVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ResistanceMeasurementReferenceVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ResistanceMeasurementDifferentialVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ResistanceMeasurementDifferentialVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ResistanceMeasurementPositiveVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ResistanceMeasurementPositiveVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ResistanceMeasurementNegativeVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ResistanceMeasurementNegativeVoltage_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_I2CBusStarted_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_I2CBusStarted_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_I2CSearchStarted_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_I2CSearchStarted_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_I2CSearchFoundDevice_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_I2CSearchFoundDevice_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_I2CSearchMissingDevice_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_I2CSearchMissingDevice_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_I2CSearchEnded_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_I2CSearchEnded_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_LTC2992Error_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_LTC2992Error_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ADS122C04Error_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ADS122C04Error_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_I2CSearchError_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_I2CSearchError_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerCAN_ErrorStatistics_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg);
void rx(
    PowerCAN_ErrorStatistics_from_Edda_Power_Control_Boards_to_Ground_Controller
        msg,
    void *misc);
void rx(DS2482Error_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(DS2482Error_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(PartialDebugMessage1_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage1_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage1_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage1_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage1_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage1_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage1_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage1_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(OneWireSearchStarted_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(OneWireSearchStarted_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(I2CBusStarted_from_Edda_Controller_to_Ground_Controller msg);
void rx(I2CBusStarted_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(I2CBusStarted_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(I2CBusStarted_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(I2CBusStarted_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(I2CBusStarted_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(I2CBusStarted_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(I2CBusStarted_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(DS28E18QError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(DS28E18QError_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(PartialDebugMessage2_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage2_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage2_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage2_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage2_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage2_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage2_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage2_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(OneWireSearchEnded_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(OneWireSearchEnded_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchStarted_from_Edda_Controller_to_Ground_Controller msg);
void rx(I2CSearchStarted_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchStarted_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(I2CSearchStarted_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchStarted_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(I2CSearchStarted_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchStarted_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(I2CSearchStarted_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(MAX31850KError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(MAX31850KError_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage3_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage3_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage3_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage3_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage3_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage3_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage3_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage3_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(
    OneWireDeviceStartupSuccess_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(
    OneWireDeviceStartupSuccess_from_Edda_Telemetry_to_Ground_Controller msg,
    void *misc);
void rx(I2CSearchError_from_Edda_Controller_to_Ground_Controller msg);
void rx(I2CSearchError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(I2CSearchError_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(I2CSearchError_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchError_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(I2CSearchError_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(MAX31856Error_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(MAX31856Error_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(PartialDebugMessage4_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage4_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage4_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage4_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage4_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage4_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage4_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage4_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(
    OneWireDeviceStartupFailure_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(
    OneWireDeviceStartupFailure_from_Edda_Telemetry_to_Ground_Controller msg,
    void *misc);
void rx(I2CSearchFoundDevice_from_Edda_Controller_to_Ground_Controller msg);
void rx(I2CSearchFoundDevice_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchFoundDevice_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(I2CSearchFoundDevice_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchFoundDevice_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(I2CSearchFoundDevice_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    I2CSearchFoundDevice_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(I2CSearchFoundDevice_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(MAX31865Error_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(MAX31865Error_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(PartialDebugMessage5_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage5_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage5_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage5_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage5_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage5_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage5_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage5_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(I2CSearchEnded_from_Edda_Controller_to_Ground_Controller msg);
void rx(I2CSearchEnded_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchEnded_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(I2CSearchEnded_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchEnded_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(I2CSearchEnded_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(I2CSearchEnded_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(I2CSearchEnded_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage6_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage6_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage6_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage6_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage6_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage6_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage6_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage6_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage7_from_Edda_Controller_to_Flight_Controller msg);
void rx(PartialDebugMessage7_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage7_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(PartialDebugMessage7_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(PartialDebugMessage7_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(PartialDebugMessage7_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(
    PartialDebugMessage7_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(PartialDebugMessage7_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void parse_message(uint8_t id, uint8_t *buf);
void parse_message(uint8_t id, uint8_t *buf, void *misc);
bool is_valid_id(uint8_t id);
uint8_t id_to_len(uint8_t id);
enum nodes id_to_sender(uint8_t id);
enum nodes id_to_receiver(uint8_t id);
enum categories id_to_category(uint8_t id);
} // namespace EDDA
#endif
