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
  currentMillis = 0,
  currentMicros = 1,
  roundTripTime_us = 2,
  destination_node_id = 3,
  debugMessagesMode = 4,
  debugStatusLedsMode = 5,
  powerMode = 6,
  uptime_ms = 7,
  maxTxQueueSize = 8,
  maxRxQueueSize = 9,
  meanTxQueueSize = 10,
  meanRxQueueSize = 11,
  w = 12,
  e = 13,
  n = 14,
  h = 15,
  o = 16,
  p = 17,
  receiver_node_id = 18,
  messages = 19,
  statusLeds = 20,
  mode = 21,
  timeSpentAwake_ms = 22,
  timeSpentSleeping_us = 23,
  current_amperes = 24,
  voltage_volts = 25,
  power_watts = 26,
  error = 27,
  sensor_index = 28,
  pressure_pascal = 29,
  pressure_millibars = 30,
  coefficient_index = 31,
  coefficient_value = 32,
  sensor_type = 33,
  temperature_celsius = 34,
  resistance_ohms = 35,
  ratio_fraction = 36,
  bus_index = 37,
  type = 38,
  timeForMeasurement_microseconds = 39,
  chip_index = 40,
  truncated_serial = 41,
  family_code = 42,
  crc_code = 43,
  raw_fault_register = 44,
  distance_mm = 45,
  relative_humidity = 46,
  is_heater_on = 47,
  acceleration_x_gforce = 48,
  acceleration_y_gforce = 49,
  acceleration_z_gforce = 50,
  sign = 51,
  result = 52,
  ambientLight_lux = 53,
  length = 54,
  byte0 = 55,
  byte1 = 56,
  byte2 = 57,
  byte3 = 58,
  byte4 = 59,
  byte5 = 60,
  byte6 = 61,
  thread_id = 62,
  taskTime_microseconds = 63,
  truncated_startTime_microseconds = 64,
  loopTime_microseconds = 65,
  power_control_channel_id = 66,
  requested_state = 67,
  circumvent_arming_checks = 68,
  requested_circumvent_arming_checks = 69,
  channel_state = 70,
  gate_state = 71,
  voltage_3v3_volts = 72,
  voltage_input_volts = 73,
  source = 74,
  estimated_current_amperes = 75,
  estimated_power_amperes = 76,
  this_number_must_be_positive_1 = 77,
  this_number_must_be_negative_2 = 78,
  this_number_must_be_positive_4 = 79,
  this_number_must_be_negative_8 = 80,
  this_number_must_be_positive_16 = 81,
  this_number_must_be_negative_32 = 82,
  this_number_must_be_positive_64 = 83,
  this_number_must_be_negative_128 = 84,
};
enum struct messages : uint16_t {
  CurrentTimePing = 0,
  CanLatency = 1,
  CurrentTimePong = 2,
  SayHi = 3,
  Hello = 4,
  CanStatistics = 5,
  WenHop = 6,
  SetDebugModeRequest = 7,
  SetPowerModeRequest = 8,
  GoingToSleep = 9,
  WokeUp = 10,
  RequestReset = 11,
  PowerInputMeasurement = 12,
  PowerInputMeasurementError = 13,
  RawTransducerVoltage = 14,
  TransducerPressure = 15,
  AmbientPressure = 16,
  TransducerError = 17,
  AmbientPressureError = 18,
  AmbientPressureCoefficient = 19,
  ColdSideTemperature = 20,
  PlatinumSensorTemperature = 21,
  PlatinumSensorResistance = 22,
  PlatinumSensorRatio = 23,
  OneWireBusError = 24,
  ThermocoupleTypeKTemperature = 25,
  SensorMeasurementInfo = 26,
  DS28E18QTransactionError = 27,
  CouldNotFindDS28E18Q = 28,
  MAX31850KError = 29,
  MAX31856Error = 30,
  MAX31865Error = 31,
  ValveActuation = 32,
  ValveActuationError = 33,
  Humidity = 34,
  HumidityError = 35,
  Acceleration = 36,
  AccelerationSelfTest = 37,
  AccelerationError = 38,
  AmbientLight = 39,
  AmbientLightError = 40,
  PartialDebugMessage = 41,
  TaskInfo = 42,
  LoopInfo = 43,
  PowerControlNewStateRequest = 44,
  PowerControlNewStateResponse = 45,
  PowerControlGetState = 46,
  PowerControlState = 47,
  PowerControlVoltages = 48,
  PowerControlResistance = 49,
  PowerControlEstimates = 50,
  PowerControlLoadMeasurement = 51,
  PowerControlLoadMeasurementError = 52,
  PowerControlResistanceMeasurementError = 53,
  PerformIgnition = 54,
  IgnitionHappened = 55,
  IgnitionCannotHappen = 56,
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
  Edda_Simulator = 5,
  Ground_Controller = 16,
};
enum struct PowerMode : uint8_t {
  Active = 0,
  Hibernate = 1,
};
enum struct DebugMessagesMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct DebugStatusLedsMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct SensorMeasurementInfo : uint8_t {
  MAX31850K_Conversion = 0,
  MAX31850K_Read = 1,
  DS2482_StatusCheck = 2,
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
};
enum struct LoopType : uint8_t {
  MainLoop = 0,
  ChitchatLoop = 1,
  RGBLoop = 2,
  GenericThreadLoop = 3,
  EddaLoop = 4,
};
enum struct AmbientLightError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CReceiveBufferEmpty = 2,
  I2CAddressNack = 3,
  I2CDataNack = 4,
  I2CTransmitBufferFull = 5,
  None = 6,
  UnexpectedManufacturer = 7,
  UnexpectedPartNumber = 8,
  ReadOldData = 9,
  DataIsInvalid = 10,
  DataWasReadWithWrongGain = 11,
};
enum struct PowerControlChannel : uint8_t {
  MainValveSolenoid = 0,
  VentingSolenoid = 1,
  IgnitionCircuit = 2,
};
enum struct PowerControlChannelStateRequest : uint8_t {
  RequestToArm = 0,
  RequestToDisarm = 1,
  RequestToStartPower = 2,
  RequestToStopPower = 3,
};
enum struct CircumventArmingCheck : uint8_t {
  SafelyUseArmingChecks = 0,
  DangerouslyIgnoreArmingChecks = 1,
};
enum struct PowerControlChannelStateRequestResult : uint8_t {
  Success = 0,
  Failure = 1,
};
enum struct PowerControlChannelState : uint8_t {
  Idle = 0,
  Arming = 1,
  Armed = 2,
  Firing = 3,
};
enum struct owerControlChannelGateState : uint8_t {
  Grounded = 0,
  ResistanceMeasurement = 1,
  High = 2,
};
enum struct AccelerationSelfTestDirection : uint8_t {
  Positive = 0,
  Negative = 1,
};
enum struct AccelerationSelfTestResult : uint8_t {
  Success = 0,
  Failure = 1,
};
enum struct AccelerationError : uint8_t {
  CRCMismatch = 0,
  I2CTransmitBufferFull = 1,
  I2CUnknownError = 2,
  I2CReceiveBufferEmpty = 3,
  I2CAddressNack = 4,
  I2CDataNack = 5,
  LIS331HFailedSelfTestX = 6,
  LIS331HFailedSelfTestY = 7,
  LIS331HFailedSelfTestZ = 8,
  LIS331HInitializationTimeout = 9,
  None = 10,
};
enum struct PowerInputMeasurementError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CAddressNack = 2,
  I2CDataNack = 3,
  I2CTransmitBufferFull = 4,
  UnexpectedManufacturer = 5,
  UnexpectedDie = 6,
  UnexpectedConfiguration = 7,
  UnexpectedMask = 8,
  UnexpectedAlertLimit = 9,
  Unknown = 10,
};
enum struct OneWireBusError : uint8_t {
  NoError = 0,
  BusShortDetected = 1,
  NoDevicesResponded = 2,
  ConfigError = 3,
  WaitOnBusyTimeout = 4,
  ResetFailure = 5,
  WireDataTooLong = 6,
  WireNackOnAddress = 7,
  WireNackOnDataTransmission = 8,
  WireUnknownError = 9,
};
enum struct DS28E18QTransactionError : uint8_t {
  RequestCRCFailure = 0,
  ResponseCRCFailure = 1,
  InvalidLength = 2,
  TransactionFailedSuccessfully = 3,
  UnableToFindDevice = 4,
};
enum struct HumidityError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CReceiveBufferEmpty = 2,
  I2CAddressNack = 3,
  I2CDataNack = 4,
  I2CTransmitBufferFull = 5,
  None = 6,
};
enum struct PowerControlResistanceSource : uint8_t {
  Estimate = 0,
  HighPrecision = 1,
};
enum struct PowerControlLoadMeasurementError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CAddressNack = 2,
  I2CDataNack = 3,
};
enum struct PowerControlResistanceMeasurementError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CAddressNack = 2,
  I2CDataNack = 3,
};
enum struct TransducerError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CAddressNack = 2,
  I2CDataNack = 3,
  Undervoltage = 4,
  Overvoltage = 5,
  Unknown = 6,
};
enum struct AmbientPressureError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CAddressNack = 2,
  I2CDataNack = 3,
  D1BelowBounds = 4,
  D1AboveBounds = 5,
  D2BelowBounds = 6,
  D2AboveBounds = 7,
  Value_dT_BelowBounds = 8,
  Value_dT_AboveBounds = 9,
  Value_TEMP_BelowBounds = 10,
  Value_TEMP_AboveBounds = 11,
  Value_OFF_BelowBounds = 12,
  Value_OFF_AboveBounds = 13,
  Value_SENS_BelowBounds = 14,
  Value_SENS_AboveBounds = 15,
  Value_P_BelowBounds = 16,
  Value_P_AboveBounds = 17,
  Unknown = 18,
};
enum struct ColdSideTemperatureSensorType : uint8_t {
  InternalTemperature = 0,
  PowerRegulator = 1,
  AmbientPressureSensor = 2,
  ThermocoupleColdSide = 3,
  HumiditySensor = 4,
};
enum struct MAX31850KError : uint8_t {
  CRCMismatch = 0,
  OneWireUnknownError = 1,
  SensorShortToVDD = 2,
  SensorShortToGND = 3,
  SensorOpenCircuit = 4,
};
enum struct ValveActuationError : uint8_t {
  CRCMismatch = 0,
  I2CUnknownError = 1,
  I2CAddressNack = 2,
  I2CDataNack = 3,
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
class CurrentTimePing_from_Flight_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePing_from_Flight_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePing_from_Flight_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePing_from_Flight_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePing_from_Flight_Controller_to_Edda_Simulator
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePing;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Simulator;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CanLatency_from_Flight_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t roundTripTime_us;
  static_assert((sizeof(roundTripTime_us) == 4), "invalid size");
  uint8_t destination_node_id;
  static_assert((sizeof(destination_node_id) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_roundTripTime_us(uint32_t value) { roundTripTime_us = value; }
  void set_destination_node_id(uint8_t value) { destination_node_id = value; }
  uint32_t get_roundTripTime_us() { return roundTripTime_us; }
  uint8_t get_destination_node_id() { return destination_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &roundTripTime_us, sizeof(roundTripTime_us));
    *index += sizeof(roundTripTime_us);
    memcpy(buf + *index, &destination_node_id, sizeof(destination_node_id));
    *index += sizeof(destination_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&roundTripTime_us, buf + index, sizeof(roundTripTime_us));
    index += sizeof(roundTripTime_us);
    memcpy(&destination_node_id, buf + index, sizeof(destination_node_id));
    index += sizeof(destination_node_id);
  }
};

class CanLatency_from_Flight_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint32_t roundTripTime_us;
  static_assert((sizeof(roundTripTime_us) == 4), "invalid size");
  uint8_t destination_node_id;
  static_assert((sizeof(destination_node_id) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_roundTripTime_us(uint32_t value) { roundTripTime_us = value; }
  void set_destination_node_id(uint8_t value) { destination_node_id = value; }
  uint32_t get_roundTripTime_us() { return roundTripTime_us; }
  uint8_t get_destination_node_id() { return destination_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &roundTripTime_us, sizeof(roundTripTime_us));
    *index += sizeof(roundTripTime_us);
    memcpy(buf + *index, &destination_node_id, sizeof(destination_node_id));
    *index += sizeof(destination_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&roundTripTime_us, buf + index, sizeof(roundTripTime_us));
    index += sizeof(roundTripTime_us);
    memcpy(&destination_node_id, buf + index, sizeof(destination_node_id));
    index += sizeof(destination_node_id);
  }
};

class CanLatency_from_Flight_Controller_to_Edda_Telemetry : public MessageBase {
public:
  uint32_t roundTripTime_us;
  static_assert((sizeof(roundTripTime_us) == 4), "invalid size");
  uint8_t destination_node_id;
  static_assert((sizeof(destination_node_id) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_roundTripTime_us(uint32_t value) { roundTripTime_us = value; }
  void set_destination_node_id(uint8_t value) { destination_node_id = value; }
  uint32_t get_roundTripTime_us() { return roundTripTime_us; }
  uint8_t get_destination_node_id() { return destination_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &roundTripTime_us, sizeof(roundTripTime_us));
    *index += sizeof(roundTripTime_us);
    memcpy(buf + *index, &destination_node_id, sizeof(destination_node_id));
    *index += sizeof(destination_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&roundTripTime_us, buf + index, sizeof(roundTripTime_us));
    index += sizeof(roundTripTime_us);
    memcpy(&destination_node_id, buf + index, sizeof(destination_node_id));
    index += sizeof(destination_node_id);
  }
};

class CanLatency_from_Flight_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint32_t roundTripTime_us;
  static_assert((sizeof(roundTripTime_us) == 4), "invalid size");
  uint8_t destination_node_id;
  static_assert((sizeof(destination_node_id) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_roundTripTime_us(uint32_t value) { roundTripTime_us = value; }
  void set_destination_node_id(uint8_t value) { destination_node_id = value; }
  uint32_t get_roundTripTime_us() { return roundTripTime_us; }
  uint8_t get_destination_node_id() { return destination_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &roundTripTime_us, sizeof(roundTripTime_us));
    *index += sizeof(roundTripTime_us);
    memcpy(buf + *index, &destination_node_id, sizeof(destination_node_id));
    *index += sizeof(destination_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&roundTripTime_us, buf + index, sizeof(roundTripTime_us));
    index += sizeof(roundTripTime_us);
    memcpy(&destination_node_id, buf + index, sizeof(destination_node_id));
    index += sizeof(destination_node_id);
  }
};

class CanLatency_from_Flight_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint32_t roundTripTime_us;
  static_assert((sizeof(roundTripTime_us) == 4), "invalid size");
  uint8_t destination_node_id;
  static_assert((sizeof(destination_node_id) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_roundTripTime_us(uint32_t value) { roundTripTime_us = value; }
  void set_destination_node_id(uint8_t value) { destination_node_id = value; }
  uint32_t get_roundTripTime_us() { return roundTripTime_us; }
  uint8_t get_destination_node_id() { return destination_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &roundTripTime_us, sizeof(roundTripTime_us));
    *index += sizeof(roundTripTime_us);
    memcpy(buf + *index, &destination_node_id, sizeof(destination_node_id));
    *index += sizeof(destination_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&roundTripTime_us, buf + index, sizeof(roundTripTime_us));
    index += sizeof(roundTripTime_us);
    memcpy(&destination_node_id, buf + index, sizeof(destination_node_id));
    index += sizeof(destination_node_id);
  }
};

class CanLatency_from_Flight_Controller_to_Edda_Simulator : public MessageBase {
public:
  uint32_t roundTripTime_us;
  static_assert((sizeof(roundTripTime_us) == 4), "invalid size");
  uint8_t destination_node_id;
  static_assert((sizeof(destination_node_id) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::CanLatency;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Simulator;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_roundTripTime_us(uint32_t value) { roundTripTime_us = value; }
  void set_destination_node_id(uint8_t value) { destination_node_id = value; }
  uint32_t get_roundTripTime_us() { return roundTripTime_us; }
  uint8_t get_destination_node_id() { return destination_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &roundTripTime_us, sizeof(roundTripTime_us));
    *index += sizeof(roundTripTime_us);
    memcpy(buf + *index, &destination_node_id, sizeof(destination_node_id));
    *index += sizeof(destination_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&roundTripTime_us, buf + index, sizeof(roundTripTime_us));
    index += sizeof(roundTripTime_us);
    memcpy(&destination_node_id, buf + index, sizeof(destination_node_id));
    index += sizeof(destination_node_id);
  }
};

class CurrentTimePong_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 4;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePong_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 5;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePong_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 6;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePong_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 7;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class CurrentTimePong_from_Edda_Simulator_to_Flight_Controller
    : public MessageBase {
public:
  uint32_t currentMillis;
  static_assert((sizeof(currentMillis) == 4), "invalid size");
  uint32_t currentMicros;
  static_assert((sizeof(currentMicros) == 4), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CurrentTimePong;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_currentMillis(uint32_t value) { currentMillis = value; }
  void set_currentMicros(uint32_t value) { currentMicros = value; }
  uint32_t get_currentMillis() { return currentMillis; }
  uint32_t get_currentMicros() { return currentMicros; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &currentMillis, sizeof(currentMillis));
    *index += sizeof(currentMillis);
    memcpy(buf + *index, &currentMicros, sizeof(currentMicros));
    *index += sizeof(currentMicros);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&currentMillis, buf + index, sizeof(currentMillis));
    index += sizeof(currentMillis);
    memcpy(&currentMicros, buf + index, sizeof(currentMicros));
    index += sizeof(currentMicros);
  }
};

class SayHi_from_Flight_Controller_to_Edda_Controller : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Flight_Controller_to_Edda_Telemetry : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Flight_Controller_to_Edda_Pressure_Top : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Flight_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class SayHi_from_Flight_Controller_to_Edda_Simulator : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::SayHi;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Simulator;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class Hello_from_Edda_Controller_to_Flight_Controller : public MessageBase {
public:
  enum DebugMessagesMode debugMessagesMode;
  static_assert((sizeof(debugMessagesMode) == 1), "invalid size");
  enum DebugStatusLedsMode debugStatusLedsMode;
  static_assert((sizeof(debugStatusLedsMode) == 1), "invalid size");
  enum PowerMode powerMode;
  static_assert((sizeof(powerMode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debugMessagesMode(enum DebugMessagesMode value) {
    debugMessagesMode = value;
  }
  void set_debugStatusLedsMode(enum DebugStatusLedsMode value) {
    debugStatusLedsMode = value;
  }
  void set_powerMode(enum PowerMode value) { powerMode = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debugMessagesMode() { return debugMessagesMode; }
  enum DebugStatusLedsMode get_debugStatusLedsMode() {
    return debugStatusLedsMode;
  }
  enum PowerMode get_powerMode() { return powerMode; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debugMessagesMode, sizeof(debugMessagesMode));
    *index += sizeof(debugMessagesMode);
    memcpy(buf + *index, &debugStatusLedsMode, sizeof(debugStatusLedsMode));
    *index += sizeof(debugStatusLedsMode);
    memcpy(buf + *index, &powerMode, sizeof(powerMode));
    *index += sizeof(powerMode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debugMessagesMode, buf + index, sizeof(debugMessagesMode));
    index += sizeof(debugMessagesMode);
    memcpy(&debugStatusLedsMode, buf + index, sizeof(debugStatusLedsMode));
    index += sizeof(debugStatusLedsMode);
    memcpy(&powerMode, buf + index, sizeof(powerMode));
    index += sizeof(powerMode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Telemetry_to_Flight_Controller : public MessageBase {
public:
  enum DebugMessagesMode debugMessagesMode;
  static_assert((sizeof(debugMessagesMode) == 1), "invalid size");
  enum DebugStatusLedsMode debugStatusLedsMode;
  static_assert((sizeof(debugStatusLedsMode) == 1), "invalid size");
  enum PowerMode powerMode;
  static_assert((sizeof(powerMode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debugMessagesMode(enum DebugMessagesMode value) {
    debugMessagesMode = value;
  }
  void set_debugStatusLedsMode(enum DebugStatusLedsMode value) {
    debugStatusLedsMode = value;
  }
  void set_powerMode(enum PowerMode value) { powerMode = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debugMessagesMode() { return debugMessagesMode; }
  enum DebugStatusLedsMode get_debugStatusLedsMode() {
    return debugStatusLedsMode;
  }
  enum PowerMode get_powerMode() { return powerMode; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debugMessagesMode, sizeof(debugMessagesMode));
    *index += sizeof(debugMessagesMode);
    memcpy(buf + *index, &debugStatusLedsMode, sizeof(debugStatusLedsMode));
    *index += sizeof(debugStatusLedsMode);
    memcpy(buf + *index, &powerMode, sizeof(powerMode));
    *index += sizeof(powerMode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debugMessagesMode, buf + index, sizeof(debugMessagesMode));
    index += sizeof(debugMessagesMode);
    memcpy(&debugStatusLedsMode, buf + index, sizeof(debugStatusLedsMode));
    index += sizeof(debugStatusLedsMode);
    memcpy(&powerMode, buf + index, sizeof(powerMode));
    index += sizeof(powerMode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Pressure_Top_to_Flight_Controller : public MessageBase {
public:
  enum DebugMessagesMode debugMessagesMode;
  static_assert((sizeof(debugMessagesMode) == 1), "invalid size");
  enum DebugStatusLedsMode debugStatusLedsMode;
  static_assert((sizeof(debugStatusLedsMode) == 1), "invalid size");
  enum PowerMode powerMode;
  static_assert((sizeof(powerMode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debugMessagesMode(enum DebugMessagesMode value) {
    debugMessagesMode = value;
  }
  void set_debugStatusLedsMode(enum DebugStatusLedsMode value) {
    debugStatusLedsMode = value;
  }
  void set_powerMode(enum PowerMode value) { powerMode = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debugMessagesMode() { return debugMessagesMode; }
  enum DebugStatusLedsMode get_debugStatusLedsMode() {
    return debugStatusLedsMode;
  }
  enum PowerMode get_powerMode() { return powerMode; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debugMessagesMode, sizeof(debugMessagesMode));
    *index += sizeof(debugMessagesMode);
    memcpy(buf + *index, &debugStatusLedsMode, sizeof(debugStatusLedsMode));
    *index += sizeof(debugStatusLedsMode);
    memcpy(buf + *index, &powerMode, sizeof(powerMode));
    *index += sizeof(powerMode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debugMessagesMode, buf + index, sizeof(debugMessagesMode));
    index += sizeof(debugMessagesMode);
    memcpy(&debugStatusLedsMode, buf + index, sizeof(debugStatusLedsMode));
    index += sizeof(debugStatusLedsMode);
    memcpy(&powerMode, buf + index, sizeof(powerMode));
    index += sizeof(powerMode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  enum DebugMessagesMode debugMessagesMode;
  static_assert((sizeof(debugMessagesMode) == 1), "invalid size");
  enum DebugStatusLedsMode debugStatusLedsMode;
  static_assert((sizeof(debugStatusLedsMode) == 1), "invalid size");
  enum PowerMode powerMode;
  static_assert((sizeof(powerMode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debugMessagesMode(enum DebugMessagesMode value) {
    debugMessagesMode = value;
  }
  void set_debugStatusLedsMode(enum DebugStatusLedsMode value) {
    debugStatusLedsMode = value;
  }
  void set_powerMode(enum PowerMode value) { powerMode = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debugMessagesMode() { return debugMessagesMode; }
  enum DebugStatusLedsMode get_debugStatusLedsMode() {
    return debugStatusLedsMode;
  }
  enum PowerMode get_powerMode() { return powerMode; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debugMessagesMode, sizeof(debugMessagesMode));
    *index += sizeof(debugMessagesMode);
    memcpy(buf + *index, &debugStatusLedsMode, sizeof(debugStatusLedsMode));
    *index += sizeof(debugStatusLedsMode);
    memcpy(buf + *index, &powerMode, sizeof(powerMode));
    *index += sizeof(powerMode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debugMessagesMode, buf + index, sizeof(debugMessagesMode));
    index += sizeof(debugMessagesMode);
    memcpy(&debugStatusLedsMode, buf + index, sizeof(debugStatusLedsMode));
    index += sizeof(debugStatusLedsMode);
    memcpy(&powerMode, buf + index, sizeof(powerMode));
    index += sizeof(powerMode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Hello_from_Edda_Simulator_to_Flight_Controller : public MessageBase {
public:
  enum DebugMessagesMode debugMessagesMode;
  static_assert((sizeof(debugMessagesMode) == 1), "invalid size");
  enum DebugStatusLedsMode debugStatusLedsMode;
  static_assert((sizeof(debugStatusLedsMode) == 1), "invalid size");
  enum PowerMode powerMode;
  static_assert((sizeof(powerMode) == 1), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_debugMessagesMode(enum DebugMessagesMode value) {
    debugMessagesMode = value;
  }
  void set_debugStatusLedsMode(enum DebugStatusLedsMode value) {
    debugStatusLedsMode = value;
  }
  void set_powerMode(enum PowerMode value) { powerMode = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  enum DebugMessagesMode get_debugMessagesMode() { return debugMessagesMode; }
  enum DebugStatusLedsMode get_debugStatusLedsMode() {
    return debugStatusLedsMode;
  }
  enum PowerMode get_powerMode() { return powerMode; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &debugMessagesMode, sizeof(debugMessagesMode));
    *index += sizeof(debugMessagesMode);
    memcpy(buf + *index, &debugStatusLedsMode, sizeof(debugStatusLedsMode));
    *index += sizeof(debugStatusLedsMode);
    memcpy(buf + *index, &powerMode, sizeof(powerMode));
    *index += sizeof(powerMode);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&debugMessagesMode, buf + index, sizeof(debugMessagesMode));
    index += sizeof(debugMessagesMode);
    memcpy(&debugStatusLedsMode, buf + index, sizeof(debugStatusLedsMode));
    index += sizeof(debugStatusLedsMode);
    memcpy(&powerMode, buf + index, sizeof(powerMode));
    index += sizeof(powerMode);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class CanStatistics_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t maxTxQueueSize;
  static_assert((sizeof(maxTxQueueSize) == 2), "invalid size");
  uint16_t maxRxQueueSize;
  static_assert((sizeof(maxRxQueueSize) == 2), "invalid size");
  uint16_t meanTxQueueSize;
  static_assert((sizeof(meanTxQueueSize) == 2), "invalid size");
  uint16_t meanRxQueueSize;
  static_assert((sizeof(meanRxQueueSize) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 145;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_maxTxQueueSize(uint16_t value) { maxTxQueueSize = value; }
  void set_maxRxQueueSize(uint16_t value) { maxRxQueueSize = value; }
  void set_meanTxQueueSize(uint16_t value) { meanTxQueueSize = value; }
  void set_meanRxQueueSize(uint16_t value) { meanRxQueueSize = value; }
  uint16_t get_maxTxQueueSize() { return maxTxQueueSize; }
  uint16_t get_maxRxQueueSize() { return maxRxQueueSize; }
  uint16_t get_meanTxQueueSize() { return meanTxQueueSize; }
  uint16_t get_meanRxQueueSize() { return meanRxQueueSize; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &maxTxQueueSize, sizeof(maxTxQueueSize));
    *index += sizeof(maxTxQueueSize);
    memcpy(buf + *index, &maxRxQueueSize, sizeof(maxRxQueueSize));
    *index += sizeof(maxRxQueueSize);
    memcpy(buf + *index, &meanTxQueueSize, sizeof(meanTxQueueSize));
    *index += sizeof(meanTxQueueSize);
    memcpy(buf + *index, &meanRxQueueSize, sizeof(meanRxQueueSize));
    *index += sizeof(meanRxQueueSize);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&maxTxQueueSize, buf + index, sizeof(maxTxQueueSize));
    index += sizeof(maxTxQueueSize);
    memcpy(&maxRxQueueSize, buf + index, sizeof(maxRxQueueSize));
    index += sizeof(maxRxQueueSize);
    memcpy(&meanTxQueueSize, buf + index, sizeof(meanTxQueueSize));
    index += sizeof(meanTxQueueSize);
    memcpy(&meanRxQueueSize, buf + index, sizeof(meanRxQueueSize));
    index += sizeof(meanRxQueueSize);
  }
};

class CanStatistics_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t maxTxQueueSize;
  static_assert((sizeof(maxTxQueueSize) == 2), "invalid size");
  uint16_t maxRxQueueSize;
  static_assert((sizeof(maxRxQueueSize) == 2), "invalid size");
  uint16_t meanTxQueueSize;
  static_assert((sizeof(meanTxQueueSize) == 2), "invalid size");
  uint16_t meanRxQueueSize;
  static_assert((sizeof(meanRxQueueSize) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 146;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_maxTxQueueSize(uint16_t value) { maxTxQueueSize = value; }
  void set_maxRxQueueSize(uint16_t value) { maxRxQueueSize = value; }
  void set_meanTxQueueSize(uint16_t value) { meanTxQueueSize = value; }
  void set_meanRxQueueSize(uint16_t value) { meanRxQueueSize = value; }
  uint16_t get_maxTxQueueSize() { return maxTxQueueSize; }
  uint16_t get_maxRxQueueSize() { return maxRxQueueSize; }
  uint16_t get_meanTxQueueSize() { return meanTxQueueSize; }
  uint16_t get_meanRxQueueSize() { return meanRxQueueSize; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &maxTxQueueSize, sizeof(maxTxQueueSize));
    *index += sizeof(maxTxQueueSize);
    memcpy(buf + *index, &maxRxQueueSize, sizeof(maxRxQueueSize));
    *index += sizeof(maxRxQueueSize);
    memcpy(buf + *index, &meanTxQueueSize, sizeof(meanTxQueueSize));
    *index += sizeof(meanTxQueueSize);
    memcpy(buf + *index, &meanRxQueueSize, sizeof(meanRxQueueSize));
    *index += sizeof(meanRxQueueSize);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&maxTxQueueSize, buf + index, sizeof(maxTxQueueSize));
    index += sizeof(maxTxQueueSize);
    memcpy(&maxRxQueueSize, buf + index, sizeof(maxRxQueueSize));
    index += sizeof(maxRxQueueSize);
    memcpy(&meanTxQueueSize, buf + index, sizeof(meanTxQueueSize));
    index += sizeof(meanTxQueueSize);
    memcpy(&meanRxQueueSize, buf + index, sizeof(meanRxQueueSize));
    index += sizeof(meanRxQueueSize);
  }
};

class CanStatistics_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t maxTxQueueSize;
  static_assert((sizeof(maxTxQueueSize) == 2), "invalid size");
  uint16_t maxRxQueueSize;
  static_assert((sizeof(maxRxQueueSize) == 2), "invalid size");
  uint16_t meanTxQueueSize;
  static_assert((sizeof(meanTxQueueSize) == 2), "invalid size");
  uint16_t meanRxQueueSize;
  static_assert((sizeof(meanRxQueueSize) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 147;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_maxTxQueueSize(uint16_t value) { maxTxQueueSize = value; }
  void set_maxRxQueueSize(uint16_t value) { maxRxQueueSize = value; }
  void set_meanTxQueueSize(uint16_t value) { meanTxQueueSize = value; }
  void set_meanRxQueueSize(uint16_t value) { meanRxQueueSize = value; }
  uint16_t get_maxTxQueueSize() { return maxTxQueueSize; }
  uint16_t get_maxRxQueueSize() { return maxRxQueueSize; }
  uint16_t get_meanTxQueueSize() { return meanTxQueueSize; }
  uint16_t get_meanRxQueueSize() { return meanRxQueueSize; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &maxTxQueueSize, sizeof(maxTxQueueSize));
    *index += sizeof(maxTxQueueSize);
    memcpy(buf + *index, &maxRxQueueSize, sizeof(maxRxQueueSize));
    *index += sizeof(maxRxQueueSize);
    memcpy(buf + *index, &meanTxQueueSize, sizeof(meanTxQueueSize));
    *index += sizeof(meanTxQueueSize);
    memcpy(buf + *index, &meanRxQueueSize, sizeof(meanRxQueueSize));
    *index += sizeof(meanRxQueueSize);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&maxTxQueueSize, buf + index, sizeof(maxTxQueueSize));
    index += sizeof(maxTxQueueSize);
    memcpy(&maxRxQueueSize, buf + index, sizeof(maxRxQueueSize));
    index += sizeof(maxRxQueueSize);
    memcpy(&meanTxQueueSize, buf + index, sizeof(meanTxQueueSize));
    index += sizeof(meanTxQueueSize);
    memcpy(&meanRxQueueSize, buf + index, sizeof(meanRxQueueSize));
    index += sizeof(meanRxQueueSize);
  }
};

class CanStatistics_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t maxTxQueueSize;
  static_assert((sizeof(maxTxQueueSize) == 2), "invalid size");
  uint16_t maxRxQueueSize;
  static_assert((sizeof(maxRxQueueSize) == 2), "invalid size");
  uint16_t meanTxQueueSize;
  static_assert((sizeof(meanTxQueueSize) == 2), "invalid size");
  uint16_t meanRxQueueSize;
  static_assert((sizeof(meanRxQueueSize) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 148;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_maxTxQueueSize(uint16_t value) { maxTxQueueSize = value; }
  void set_maxRxQueueSize(uint16_t value) { maxRxQueueSize = value; }
  void set_meanTxQueueSize(uint16_t value) { meanTxQueueSize = value; }
  void set_meanRxQueueSize(uint16_t value) { meanRxQueueSize = value; }
  uint16_t get_maxTxQueueSize() { return maxTxQueueSize; }
  uint16_t get_maxRxQueueSize() { return maxRxQueueSize; }
  uint16_t get_meanTxQueueSize() { return meanTxQueueSize; }
  uint16_t get_meanRxQueueSize() { return meanRxQueueSize; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &maxTxQueueSize, sizeof(maxTxQueueSize));
    *index += sizeof(maxTxQueueSize);
    memcpy(buf + *index, &maxRxQueueSize, sizeof(maxRxQueueSize));
    *index += sizeof(maxRxQueueSize);
    memcpy(buf + *index, &meanTxQueueSize, sizeof(meanTxQueueSize));
    *index += sizeof(meanTxQueueSize);
    memcpy(buf + *index, &meanRxQueueSize, sizeof(meanRxQueueSize));
    *index += sizeof(meanRxQueueSize);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&maxTxQueueSize, buf + index, sizeof(maxTxQueueSize));
    index += sizeof(maxTxQueueSize);
    memcpy(&maxRxQueueSize, buf + index, sizeof(maxRxQueueSize));
    index += sizeof(maxRxQueueSize);
    memcpy(&meanTxQueueSize, buf + index, sizeof(meanTxQueueSize));
    index += sizeof(meanTxQueueSize);
    memcpy(&meanRxQueueSize, buf + index, sizeof(meanRxQueueSize));
    index += sizeof(meanRxQueueSize);
  }
};

class CanStatistics_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t maxTxQueueSize;
  static_assert((sizeof(maxTxQueueSize) == 2), "invalid size");
  uint16_t maxRxQueueSize;
  static_assert((sizeof(maxRxQueueSize) == 2), "invalid size");
  uint16_t meanTxQueueSize;
  static_assert((sizeof(meanTxQueueSize) == 2), "invalid size");
  uint16_t meanRxQueueSize;
  static_assert((sizeof(meanRxQueueSize) == 2), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::CanStatistics;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 149;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_maxTxQueueSize(uint16_t value) { maxTxQueueSize = value; }
  void set_maxRxQueueSize(uint16_t value) { maxRxQueueSize = value; }
  void set_meanTxQueueSize(uint16_t value) { meanTxQueueSize = value; }
  void set_meanRxQueueSize(uint16_t value) { meanRxQueueSize = value; }
  uint16_t get_maxTxQueueSize() { return maxTxQueueSize; }
  uint16_t get_maxRxQueueSize() { return maxRxQueueSize; }
  uint16_t get_meanTxQueueSize() { return meanTxQueueSize; }
  uint16_t get_meanRxQueueSize() { return meanRxQueueSize; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &maxTxQueueSize, sizeof(maxTxQueueSize));
    *index += sizeof(maxTxQueueSize);
    memcpy(buf + *index, &maxRxQueueSize, sizeof(maxRxQueueSize));
    *index += sizeof(maxRxQueueSize);
    memcpy(buf + *index, &meanTxQueueSize, sizeof(meanTxQueueSize));
    *index += sizeof(meanTxQueueSize);
    memcpy(buf + *index, &meanRxQueueSize, sizeof(meanRxQueueSize));
    *index += sizeof(meanRxQueueSize);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&maxTxQueueSize, buf + index, sizeof(maxTxQueueSize));
    index += sizeof(maxTxQueueSize);
    memcpy(&maxRxQueueSize, buf + index, sizeof(maxRxQueueSize));
    index += sizeof(maxRxQueueSize);
    memcpy(&meanTxQueueSize, buf + index, sizeof(meanTxQueueSize));
    index += sizeof(meanTxQueueSize);
    memcpy(&meanRxQueueSize, buf + index, sizeof(meanRxQueueSize));
    index += sizeof(meanRxQueueSize);
  }
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
  uint8_t id = 153;
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

class WenHop_from_Edda_Simulator_to_Flight_Controller : public MessageBase {
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
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
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

class SetDebugModeRequest_from_Flight_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum DebugMessagesMode messages;
  static_assert((sizeof(messages) == 1), "invalid size");
  enum DebugStatusLedsMode statusLeds;
  static_assert((sizeof(statusLeds) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::SetDebugModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_messages(enum DebugMessagesMode value) { messages = value; }
  void set_statusLeds(enum DebugStatusLedsMode value) { statusLeds = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum DebugMessagesMode get_messages() { return messages; }
  enum DebugStatusLedsMode get_statusLeds() { return statusLeds; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &messages, sizeof(messages));
    *index += sizeof(messages);
    memcpy(buf + *index, &statusLeds, sizeof(statusLeds));
    *index += sizeof(statusLeds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&messages, buf + index, sizeof(messages));
    index += sizeof(messages);
    memcpy(&statusLeds, buf + index, sizeof(statusLeds));
    index += sizeof(statusLeds);
  }
};

class SetDebugModeRequest_from_Flight_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum DebugMessagesMode messages;
  static_assert((sizeof(messages) == 1), "invalid size");
  enum DebugStatusLedsMode statusLeds;
  static_assert((sizeof(statusLeds) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::SetDebugModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_messages(enum DebugMessagesMode value) { messages = value; }
  void set_statusLeds(enum DebugStatusLedsMode value) { statusLeds = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum DebugMessagesMode get_messages() { return messages; }
  enum DebugStatusLedsMode get_statusLeds() { return statusLeds; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &messages, sizeof(messages));
    *index += sizeof(messages);
    memcpy(buf + *index, &statusLeds, sizeof(statusLeds));
    *index += sizeof(statusLeds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&messages, buf + index, sizeof(messages));
    index += sizeof(messages);
    memcpy(&statusLeds, buf + index, sizeof(statusLeds));
    index += sizeof(statusLeds);
  }
};

class SetDebugModeRequest_from_Flight_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum DebugMessagesMode messages;
  static_assert((sizeof(messages) == 1), "invalid size");
  enum DebugStatusLedsMode statusLeds;
  static_assert((sizeof(statusLeds) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::SetDebugModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_messages(enum DebugMessagesMode value) { messages = value; }
  void set_statusLeds(enum DebugStatusLedsMode value) { statusLeds = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum DebugMessagesMode get_messages() { return messages; }
  enum DebugStatusLedsMode get_statusLeds() { return statusLeds; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &messages, sizeof(messages));
    *index += sizeof(messages);
    memcpy(buf + *index, &statusLeds, sizeof(statusLeds));
    *index += sizeof(statusLeds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&messages, buf + index, sizeof(messages));
    index += sizeof(messages);
    memcpy(&statusLeds, buf + index, sizeof(statusLeds));
    index += sizeof(statusLeds);
  }
};

class SetDebugModeRequest_from_Flight_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum DebugMessagesMode messages;
  static_assert((sizeof(messages) == 1), "invalid size");
  enum DebugStatusLedsMode statusLeds;
  static_assert((sizeof(statusLeds) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::SetDebugModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_messages(enum DebugMessagesMode value) { messages = value; }
  void set_statusLeds(enum DebugStatusLedsMode value) { statusLeds = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum DebugMessagesMode get_messages() { return messages; }
  enum DebugStatusLedsMode get_statusLeds() { return statusLeds; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &messages, sizeof(messages));
    *index += sizeof(messages);
    memcpy(buf + *index, &statusLeds, sizeof(statusLeds));
    *index += sizeof(statusLeds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&messages, buf + index, sizeof(messages));
    index += sizeof(messages);
    memcpy(&statusLeds, buf + index, sizeof(statusLeds));
    index += sizeof(statusLeds);
  }
};

class SetDebugModeRequest_from_Flight_Controller_to_Edda_Simulator
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum DebugMessagesMode messages;
  static_assert((sizeof(messages) == 1), "invalid size");
  enum DebugStatusLedsMode statusLeds;
  static_assert((sizeof(statusLeds) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::SetDebugModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Simulator;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_messages(enum DebugMessagesMode value) { messages = value; }
  void set_statusLeds(enum DebugStatusLedsMode value) { statusLeds = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum DebugMessagesMode get_messages() { return messages; }
  enum DebugStatusLedsMode get_statusLeds() { return statusLeds; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &messages, sizeof(messages));
    *index += sizeof(messages);
    memcpy(buf + *index, &statusLeds, sizeof(statusLeds));
    *index += sizeof(statusLeds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&messages, buf + index, sizeof(messages));
    index += sizeof(messages);
    memcpy(&statusLeds, buf + index, sizeof(statusLeds));
    index += sizeof(statusLeds);
  }
};

class SetPowerModeRequest_from_Flight_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum PowerMode mode;
  static_assert((sizeof(mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetPowerModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_mode(enum PowerMode value) { mode = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum PowerMode get_mode() { return mode; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &mode, sizeof(mode));
    *index += sizeof(mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&mode, buf + index, sizeof(mode));
    index += sizeof(mode);
  }
};

class SetPowerModeRequest_from_Flight_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum PowerMode mode;
  static_assert((sizeof(mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetPowerModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_mode(enum PowerMode value) { mode = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum PowerMode get_mode() { return mode; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &mode, sizeof(mode));
    *index += sizeof(mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&mode, buf + index, sizeof(mode));
    index += sizeof(mode);
  }
};

class SetPowerModeRequest_from_Flight_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum PowerMode mode;
  static_assert((sizeof(mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetPowerModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_mode(enum PowerMode value) { mode = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum PowerMode get_mode() { return mode; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &mode, sizeof(mode));
    *index += sizeof(mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&mode, buf + index, sizeof(mode));
    index += sizeof(mode);
  }
};

class SetPowerModeRequest_from_Flight_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum PowerMode mode;
  static_assert((sizeof(mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetPowerModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_mode(enum PowerMode value) { mode = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum PowerMode get_mode() { return mode; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &mode, sizeof(mode));
    *index += sizeof(mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&mode, buf + index, sizeof(mode));
    index += sizeof(mode);
  }
};

class SetPowerModeRequest_from_Flight_Controller_to_Edda_Simulator
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  enum PowerMode mode;
  static_assert((sizeof(mode) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::SetPowerModeRequest;
  enum EDDA::nodes sender = EDDA::nodes::Flight_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Simulator;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  void set_mode(enum PowerMode value) { mode = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  enum PowerMode get_mode() { return mode; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
    memcpy(buf + *index, &mode, sizeof(mode));
    *index += sizeof(mode);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
    memcpy(&mode, buf + index, sizeof(mode));
    index += sizeof(mode);
  }
};

class GoingToSleep_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t timeSpentAwake_ms;
  static_assert((sizeof(timeSpentAwake_ms) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::GoingToSleep;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 64;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentAwake_ms(uint32_t value) { timeSpentAwake_ms = value; }
  uint32_t get_timeSpentAwake_ms() { return timeSpentAwake_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentAwake_ms, sizeof(timeSpentAwake_ms));
    *index += sizeof(timeSpentAwake_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentAwake_ms, buf + index, sizeof(timeSpentAwake_ms));
    index += sizeof(timeSpentAwake_ms);
  }
};

class GoingToSleep_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t timeSpentAwake_ms;
  static_assert((sizeof(timeSpentAwake_ms) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::GoingToSleep;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 65;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentAwake_ms(uint32_t value) { timeSpentAwake_ms = value; }
  uint32_t get_timeSpentAwake_ms() { return timeSpentAwake_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentAwake_ms, sizeof(timeSpentAwake_ms));
    *index += sizeof(timeSpentAwake_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentAwake_ms, buf + index, sizeof(timeSpentAwake_ms));
    index += sizeof(timeSpentAwake_ms);
  }
};

class GoingToSleep_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t timeSpentAwake_ms;
  static_assert((sizeof(timeSpentAwake_ms) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::GoingToSleep;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 66;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentAwake_ms(uint32_t value) { timeSpentAwake_ms = value; }
  uint32_t get_timeSpentAwake_ms() { return timeSpentAwake_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentAwake_ms, sizeof(timeSpentAwake_ms));
    *index += sizeof(timeSpentAwake_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentAwake_ms, buf + index, sizeof(timeSpentAwake_ms));
    index += sizeof(timeSpentAwake_ms);
  }
};

class GoingToSleep_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t timeSpentAwake_ms;
  static_assert((sizeof(timeSpentAwake_ms) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::GoingToSleep;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 67;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentAwake_ms(uint32_t value) { timeSpentAwake_ms = value; }
  uint32_t get_timeSpentAwake_ms() { return timeSpentAwake_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentAwake_ms, sizeof(timeSpentAwake_ms));
    *index += sizeof(timeSpentAwake_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentAwake_ms, buf + index, sizeof(timeSpentAwake_ms));
    index += sizeof(timeSpentAwake_ms);
  }
};

class GoingToSleep_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t timeSpentAwake_ms;
  static_assert((sizeof(timeSpentAwake_ms) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::GoingToSleep;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 68;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentAwake_ms(uint32_t value) { timeSpentAwake_ms = value; }
  uint32_t get_timeSpentAwake_ms() { return timeSpentAwake_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentAwake_ms, sizeof(timeSpentAwake_ms));
    *index += sizeof(timeSpentAwake_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentAwake_ms, buf + index, sizeof(timeSpentAwake_ms));
    index += sizeof(timeSpentAwake_ms);
  }
};

class WokeUp_from_Edda_Telemetry_to_Ground_Controller : public MessageBase {
public:
  uint32_t timeSpentSleeping_us;
  static_assert((sizeof(timeSpentSleeping_us) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::WokeUp;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 69;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentSleeping_us(uint32_t value) {
    timeSpentSleeping_us = value;
  }
  uint32_t get_timeSpentSleeping_us() { return timeSpentSleeping_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentSleeping_us, sizeof(timeSpentSleeping_us));
    *index += sizeof(timeSpentSleeping_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentSleeping_us, buf + index, sizeof(timeSpentSleeping_us));
    index += sizeof(timeSpentSleeping_us);
  }
};

class WokeUp_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  uint32_t timeSpentSleeping_us;
  static_assert((sizeof(timeSpentSleeping_us) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::WokeUp;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 70;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentSleeping_us(uint32_t value) {
    timeSpentSleeping_us = value;
  }
  uint32_t get_timeSpentSleeping_us() { return timeSpentSleeping_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentSleeping_us, sizeof(timeSpentSleeping_us));
    *index += sizeof(timeSpentSleeping_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentSleeping_us, buf + index, sizeof(timeSpentSleeping_us));
    index += sizeof(timeSpentSleeping_us);
  }
};

class WokeUp_from_Edda_Pressure_Top_to_Ground_Controller : public MessageBase {
public:
  uint32_t timeSpentSleeping_us;
  static_assert((sizeof(timeSpentSleeping_us) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::WokeUp;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 71;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentSleeping_us(uint32_t value) {
    timeSpentSleeping_us = value;
  }
  uint32_t get_timeSpentSleeping_us() { return timeSpentSleeping_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentSleeping_us, sizeof(timeSpentSleeping_us));
    *index += sizeof(timeSpentSleeping_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentSleeping_us, buf + index, sizeof(timeSpentSleeping_us));
    index += sizeof(timeSpentSleeping_us);
  }
};

class WokeUp_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint32_t timeSpentSleeping_us;
  static_assert((sizeof(timeSpentSleeping_us) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::WokeUp;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 72;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentSleeping_us(uint32_t value) {
    timeSpentSleeping_us = value;
  }
  uint32_t get_timeSpentSleeping_us() { return timeSpentSleeping_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentSleeping_us, sizeof(timeSpentSleeping_us));
    *index += sizeof(timeSpentSleeping_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentSleeping_us, buf + index, sizeof(timeSpentSleeping_us));
    index += sizeof(timeSpentSleeping_us);
  }
};

class WokeUp_from_Edda_Simulator_to_Ground_Controller : public MessageBase {
public:
  uint32_t timeSpentSleeping_us;
  static_assert((sizeof(timeSpentSleeping_us) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::WokeUp;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 73;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_timeSpentSleeping_us(uint32_t value) {
    timeSpentSleeping_us = value;
  }
  uint32_t get_timeSpentSleeping_us() { return timeSpentSleeping_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &timeSpentSleeping_us, sizeof(timeSpentSleeping_us));
    *index += sizeof(timeSpentSleeping_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&timeSpentSleeping_us, buf + index, sizeof(timeSpentSleeping_us));
    index += sizeof(timeSpentSleeping_us);
  }
};

class RequestReset_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::RequestReset;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
  }
};

class RequestReset_from_Ground_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::RequestReset;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
  }
};

class RequestReset_from_Ground_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::RequestReset;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
  }
};

class RequestReset_from_Ground_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::RequestReset;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
  }
};

class RequestReset_from_Ground_Controller_to_Edda_Simulator
    : public MessageBase {
public:
  uint8_t receiver_node_id;
  static_assert((sizeof(receiver_node_id) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::RequestReset;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Simulator;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_receiver_node_id(uint8_t value) { receiver_node_id = value; }
  uint8_t get_receiver_node_id() { return receiver_node_id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &receiver_node_id, sizeof(receiver_node_id));
    *index += sizeof(receiver_node_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&receiver_node_id, buf + index, sizeof(receiver_node_id));
    index += sizeof(receiver_node_id);
  }
};

class PowerInputMeasurement_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_amperes;
  static_assert((sizeof(current_amperes) == 2), "invalid size");
  uint16_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 2), "invalid size");
  uint16_t power_watts;
  static_assert((sizeof(power_watts) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 155;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_amperes);
  }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volts);
  }
  void set_power_watts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watts);
  }
  EDDA_FLOAT_DEF get_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_amperes, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watts, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_amperes, sizeof(current_amperes));
    *index += sizeof(current_amperes);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
    memcpy(buf + *index, &power_watts, sizeof(power_watts));
    *index += sizeof(power_watts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_amperes, buf + index, sizeof(current_amperes));
    index += sizeof(current_amperes);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
    memcpy(&power_watts, buf + index, sizeof(power_watts));
    index += sizeof(power_watts);
  }
};

class PowerInputMeasurement_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_amperes;
  static_assert((sizeof(current_amperes) == 2), "invalid size");
  uint16_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 2), "invalid size");
  uint16_t power_watts;
  static_assert((sizeof(power_watts) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 156;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_amperes);
  }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volts);
  }
  void set_power_watts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watts);
  }
  EDDA_FLOAT_DEF get_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_amperes, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watts, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_amperes, sizeof(current_amperes));
    *index += sizeof(current_amperes);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
    memcpy(buf + *index, &power_watts, sizeof(power_watts));
    *index += sizeof(power_watts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_amperes, buf + index, sizeof(current_amperes));
    index += sizeof(current_amperes);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
    memcpy(&power_watts, buf + index, sizeof(power_watts));
    index += sizeof(power_watts);
  }
};

class PowerInputMeasurement_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_amperes;
  static_assert((sizeof(current_amperes) == 2), "invalid size");
  uint16_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 2), "invalid size");
  uint16_t power_watts;
  static_assert((sizeof(power_watts) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 157;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_amperes);
  }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volts);
  }
  void set_power_watts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watts);
  }
  EDDA_FLOAT_DEF get_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_amperes, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watts, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_amperes, sizeof(current_amperes));
    *index += sizeof(current_amperes);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
    memcpy(buf + *index, &power_watts, sizeof(power_watts));
    *index += sizeof(power_watts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_amperes, buf + index, sizeof(current_amperes));
    index += sizeof(current_amperes);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
    memcpy(&power_watts, buf + index, sizeof(power_watts));
    index += sizeof(power_watts);
  }
};

class PowerInputMeasurement_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_amperes;
  static_assert((sizeof(current_amperes) == 2), "invalid size");
  uint16_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 2), "invalid size");
  uint16_t power_watts;
  static_assert((sizeof(power_watts) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 158;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_amperes);
  }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volts);
  }
  void set_power_watts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watts);
  }
  EDDA_FLOAT_DEF get_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_amperes, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watts, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_amperes, sizeof(current_amperes));
    *index += sizeof(current_amperes);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
    memcpy(buf + *index, &power_watts, sizeof(power_watts));
    *index += sizeof(power_watts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_amperes, buf + index, sizeof(current_amperes));
    index += sizeof(current_amperes);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
    memcpy(&power_watts, buf + index, sizeof(power_watts));
    index += sizeof(power_watts);
  }
};

class PowerInputMeasurement_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t current_amperes;
  static_assert((sizeof(current_amperes) == 2), "invalid size");
  uint16_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 2), "invalid size");
  uint16_t power_watts;
  static_assert((sizeof(power_watts) == 2), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 159;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &current_amperes);
  }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &voltage_volts);
  }
  void set_power_watts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540, &power_watts);
  }
  EDDA_FLOAT_DEF get_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_amperes, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watts, -540, 540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &current_amperes, sizeof(current_amperes));
    *index += sizeof(current_amperes);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
    memcpy(buf + *index, &power_watts, sizeof(power_watts));
    *index += sizeof(power_watts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&current_amperes, buf + index, sizeof(current_amperes));
    index += sizeof(current_amperes);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
    memcpy(&power_watts, buf + index, sizeof(power_watts));
    index += sizeof(power_watts);
  }
};

class PowerInputMeasurementError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerInputMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 160;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerInputMeasurementError value) { error = value; }
  enum PowerInputMeasurementError get_error() { return error; }
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
  enum PowerInputMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 161;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerInputMeasurementError value) { error = value; }
  enum PowerInputMeasurementError get_error() { return error; }
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
  enum PowerInputMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 162;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerInputMeasurementError value) { error = value; }
  enum PowerInputMeasurementError get_error() { return error; }
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
  enum PowerInputMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 163;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerInputMeasurementError value) { error = value; }
  enum PowerInputMeasurementError get_error() { return error; }
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

class PowerInputMeasurementError_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerInputMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerInputMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 164;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum PowerInputMeasurementError value) { error = value; }
  enum PowerInputMeasurementError get_error() { return error; }
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

class RawTransducerVoltage_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::RawTransducerVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 165;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &voltage_volts);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
  }
};

class RawTransducerVoltage_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::RawTransducerVoltage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 166;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &voltage_volts);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
  }
};

class TransducerPressure_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 167;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000000, &pressure_pascal);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, 0, 10000000, &out);
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

class TransducerPressure_from_Edda_Pressure_Top_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 167;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000000, &pressure_pascal);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, 0, 10000000, &out);
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
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 168;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000000, &pressure_pascal);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, 0, 10000000, &out);
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

class TransducerPressure_from_Edda_Pressure_Bottom_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 168;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000000, &pressure_pascal);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, 0, 10000000, &out);
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

class TransducerPressure_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 169;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000000, &pressure_pascal);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, 0, 10000000, &out);
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

class TransducerPressure_from_Edda_Simulator_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_pascal;
  static_assert((sizeof(pressure_pascal) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TransducerPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 169;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_pascal(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000000, &pressure_pascal);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_pascal() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_pascal, 0, 10000000, &out);
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

class AmbientPressure_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_millibars;
  static_assert((sizeof(pressure_millibars) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::AmbientPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 170;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_millibars(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &pressure_millibars);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_millibars() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_millibars, 0, 10000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &pressure_millibars, sizeof(pressure_millibars));
    *index += sizeof(pressure_millibars);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&pressure_millibars, buf + index, sizeof(pressure_millibars));
    index += sizeof(pressure_millibars);
  }
};

class AmbientPressure_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_millibars;
  static_assert((sizeof(pressure_millibars) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::AmbientPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 171;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_millibars(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &pressure_millibars);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_millibars() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_millibars, 0, 10000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &pressure_millibars, sizeof(pressure_millibars));
    *index += sizeof(pressure_millibars);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&pressure_millibars, buf + index, sizeof(pressure_millibars));
    index += sizeof(pressure_millibars);
  }
};

class AmbientPressure_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t pressure_millibars;
  static_assert((sizeof(pressure_millibars) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::AmbientPressure;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 172;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_pressure_millibars(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &pressure_millibars);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_pressure_millibars() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(pressure_millibars, 0, 10000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &pressure_millibars, sizeof(pressure_millibars));
    *index += sizeof(pressure_millibars);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&pressure_millibars, buf + index, sizeof(pressure_millibars));
    index += sizeof(pressure_millibars);
  }
};

class TransducerError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
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
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum TransducerError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum TransducerError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class TransducerError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
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
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum TransducerError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum TransducerError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class TransducerError_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum TransducerError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::TransducerError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 175;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum TransducerError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum TransducerError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AmbientPressureError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum AmbientPressureError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::AmbientPressureError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 176;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum AmbientPressureError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum AmbientPressureError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AmbientPressureError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum AmbientPressureError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::AmbientPressureError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 177;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum AmbientPressureError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum AmbientPressureError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AmbientPressureError_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum AmbientPressureError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::AmbientPressureError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 178;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum AmbientPressureError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum AmbientPressureError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class AmbientPressureCoefficient_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t coefficient_index;
  static_assert((sizeof(coefficient_index) == 1), "invalid size");
  uint16_t coefficient_value;
  static_assert((sizeof(coefficient_value) == 2), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::AmbientPressureCoefficient;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 179;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_coefficient_index(uint8_t value) { coefficient_index = value; }
  void set_coefficient_value(uint16_t value) { coefficient_value = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint8_t get_coefficient_index() { return coefficient_index; }
  uint16_t get_coefficient_value() { return coefficient_value; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &coefficient_index, sizeof(coefficient_index));
    *index += sizeof(coefficient_index);
    memcpy(buf + *index, &coefficient_value, sizeof(coefficient_value));
    *index += sizeof(coefficient_value);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&coefficient_index, buf + index, sizeof(coefficient_index));
    index += sizeof(coefficient_index);
    memcpy(&coefficient_value, buf + index, sizeof(coefficient_value));
    index += sizeof(coefficient_value);
  }
};

class AmbientPressureCoefficient_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t coefficient_index;
  static_assert((sizeof(coefficient_index) == 1), "invalid size");
  uint16_t coefficient_value;
  static_assert((sizeof(coefficient_value) == 2), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::AmbientPressureCoefficient;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 180;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_coefficient_index(uint8_t value) { coefficient_index = value; }
  void set_coefficient_value(uint16_t value) { coefficient_value = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint8_t get_coefficient_index() { return coefficient_index; }
  uint16_t get_coefficient_value() { return coefficient_value; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &coefficient_index, sizeof(coefficient_index));
    *index += sizeof(coefficient_index);
    memcpy(buf + *index, &coefficient_value, sizeof(coefficient_value));
    *index += sizeof(coefficient_value);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&coefficient_index, buf + index, sizeof(coefficient_index));
    index += sizeof(coefficient_index);
    memcpy(&coefficient_value, buf + index, sizeof(coefficient_value));
    index += sizeof(coefficient_value);
  }
};

class ColdSideTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum ColdSideTemperatureSensorType sensor_type;
  static_assert((sizeof(sensor_type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 181;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_type(enum ColdSideTemperatureSensorType value) {
    sensor_type = value;
  }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum ColdSideTemperatureSensorType get_sensor_type() { return sensor_type; }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_type, sizeof(sensor_type));
    *index += sizeof(sensor_type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_type, buf + index, sizeof(sensor_type));
    index += sizeof(sensor_type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum ColdSideTemperatureSensorType sensor_type;
  static_assert((sizeof(sensor_type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 182;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_type(enum ColdSideTemperatureSensorType value) {
    sensor_type = value;
  }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum ColdSideTemperatureSensorType get_sensor_type() { return sensor_type; }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_type, sizeof(sensor_type));
    *index += sizeof(sensor_type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_type, buf + index, sizeof(sensor_type));
    index += sizeof(sensor_type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum ColdSideTemperatureSensorType sensor_type;
  static_assert((sizeof(sensor_type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 183;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_type(enum ColdSideTemperatureSensorType value) {
    sensor_type = value;
  }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum ColdSideTemperatureSensorType get_sensor_type() { return sensor_type; }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_type, sizeof(sensor_type));
    *index += sizeof(sensor_type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_type, buf + index, sizeof(sensor_type));
    index += sizeof(sensor_type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum ColdSideTemperatureSensorType sensor_type;
  static_assert((sizeof(sensor_type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 184;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_type(enum ColdSideTemperatureSensorType value) {
    sensor_type = value;
  }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum ColdSideTemperatureSensorType get_sensor_type() { return sensor_type; }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_type, sizeof(sensor_type));
    *index += sizeof(sensor_type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_type, buf + index, sizeof(sensor_type));
    index += sizeof(sensor_type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class ColdSideTemperature_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  enum ColdSideTemperatureSensorType sensor_type;
  static_assert((sizeof(sensor_type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ColdSideTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 185;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_type(enum ColdSideTemperatureSensorType value) {
    sensor_type = value;
  }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -55, 125, &temperature_celsius);
  }
  enum ColdSideTemperatureSensorType get_sensor_type() { return sensor_type; }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -55, 125, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_type, sizeof(sensor_type));
    *index += sizeof(sensor_type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &temperature_celsius, sizeof(temperature_celsius));
    *index += sizeof(temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_type, buf + index, sizeof(sensor_type));
    index += sizeof(sensor_type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&temperature_celsius, buf + index, sizeof(temperature_celsius));
    index += sizeof(temperature_celsius);
  }
};

class PlatinumSensorTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PlatinumSensorTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 186;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 850, &temperature_celsius);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -200, 850, &out);
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

class PlatinumSensorResistance_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t resistance_ohms;
  static_assert((sizeof(resistance_ohms) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PlatinumSensorResistance;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 187;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_resistance_ohms(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5000, &resistance_ohms);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_resistance_ohms() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(resistance_ohms, 0, 5000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &resistance_ohms, sizeof(resistance_ohms));
    *index += sizeof(resistance_ohms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&resistance_ohms, buf + index, sizeof(resistance_ohms));
    index += sizeof(resistance_ohms);
  }
};

class PlatinumSensorRatio_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t ratio_fraction;
  static_assert((sizeof(ratio_fraction) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PlatinumSensorRatio;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 188;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_ratio_fraction(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1, &ratio_fraction);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_ratio_fraction() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(ratio_fraction, 0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &ratio_fraction, sizeof(ratio_fraction));
    *index += sizeof(ratio_fraction);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&ratio_fraction, buf + index, sizeof(ratio_fraction));
    index += sizeof(ratio_fraction);
  }
};

class OneWireBusError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t bus_index;
  static_assert((sizeof(bus_index) == 1), "invalid size");
  enum OneWireBusError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::OneWireBusError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 189;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_bus_index(uint8_t value) { bus_index = value; }
  void set_error(enum OneWireBusError value) { error = value; }
  uint8_t get_bus_index() { return bus_index; }
  enum OneWireBusError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &bus_index, sizeof(bus_index));
    *index += sizeof(bus_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&bus_index, buf + index, sizeof(bus_index));
    index += sizeof(bus_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class ThermocoupleTypeKTemperature_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::ThermocoupleTypeKTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 190;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &temperature_celsius);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -200, 1350, &out);
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

class ThermocoupleTypeKTemperature_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t temperature_celsius;
  static_assert((sizeof(temperature_celsius) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::ThermocoupleTypeKTemperature;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 191;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &temperature_celsius);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(temperature_celsius, -200, 1350, &out);
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

class SensorMeasurementInfo_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum SensorMeasurementInfo type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t timeForMeasurement_microseconds;
  static_assert((sizeof(timeForMeasurement_microseconds) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::SensorMeasurementInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 192;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum SensorMeasurementInfo value) { type = value; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_timeForMeasurement_microseconds(uint32_t value) {
    timeForMeasurement_microseconds = value;
  }
  enum SensorMeasurementInfo get_type() { return type; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint32_t get_timeForMeasurement_microseconds() {
    return timeForMeasurement_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &timeForMeasurement_microseconds,
           sizeof(timeForMeasurement_microseconds));
    *index += sizeof(timeForMeasurement_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&timeForMeasurement_microseconds, buf + index,
           sizeof(timeForMeasurement_microseconds));
    index += sizeof(timeForMeasurement_microseconds);
  }
};

class SensorMeasurementInfo_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum SensorMeasurementInfo type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t timeForMeasurement_microseconds;
  static_assert((sizeof(timeForMeasurement_microseconds) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::SensorMeasurementInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 193;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum SensorMeasurementInfo value) { type = value; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_timeForMeasurement_microseconds(uint32_t value) {
    timeForMeasurement_microseconds = value;
  }
  enum SensorMeasurementInfo get_type() { return type; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint32_t get_timeForMeasurement_microseconds() {
    return timeForMeasurement_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &timeForMeasurement_microseconds,
           sizeof(timeForMeasurement_microseconds));
    *index += sizeof(timeForMeasurement_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&timeForMeasurement_microseconds, buf + index,
           sizeof(timeForMeasurement_microseconds));
    index += sizeof(timeForMeasurement_microseconds);
  }
};

class SensorMeasurementInfo_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum SensorMeasurementInfo type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t timeForMeasurement_microseconds;
  static_assert((sizeof(timeForMeasurement_microseconds) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::SensorMeasurementInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 194;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum SensorMeasurementInfo value) { type = value; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_timeForMeasurement_microseconds(uint32_t value) {
    timeForMeasurement_microseconds = value;
  }
  enum SensorMeasurementInfo get_type() { return type; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint32_t get_timeForMeasurement_microseconds() {
    return timeForMeasurement_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &timeForMeasurement_microseconds,
           sizeof(timeForMeasurement_microseconds));
    *index += sizeof(timeForMeasurement_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&timeForMeasurement_microseconds, buf + index,
           sizeof(timeForMeasurement_microseconds));
    index += sizeof(timeForMeasurement_microseconds);
  }
};

class SensorMeasurementInfo_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  enum SensorMeasurementInfo type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t timeForMeasurement_microseconds;
  static_assert((sizeof(timeForMeasurement_microseconds) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::SensorMeasurementInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 195;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum SensorMeasurementInfo value) { type = value; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_timeForMeasurement_microseconds(uint32_t value) {
    timeForMeasurement_microseconds = value;
  }
  enum SensorMeasurementInfo get_type() { return type; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint32_t get_timeForMeasurement_microseconds() {
    return timeForMeasurement_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &timeForMeasurement_microseconds,
           sizeof(timeForMeasurement_microseconds));
    *index += sizeof(timeForMeasurement_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&timeForMeasurement_microseconds, buf + index,
           sizeof(timeForMeasurement_microseconds));
    index += sizeof(timeForMeasurement_microseconds);
  }
};

class DS28E18QTransactionError_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  enum DS28E18QTransactionError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::DS28E18QTransactionError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 196;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_error(enum DS28E18QTransactionError value) { error = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  enum DS28E18QTransactionError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class DS28E18QTransactionError_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  enum DS28E18QTransactionError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::DS28E18QTransactionError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 197;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_error(enum DS28E18QTransactionError value) { error = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  enum DS28E18QTransactionError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class DS28E18QTransactionError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  enum DS28E18QTransactionError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::DS28E18QTransactionError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 198;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_error(enum DS28E18QTransactionError value) { error = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  enum DS28E18QTransactionError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class DS28E18QTransactionError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  enum DS28E18QTransactionError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::DS28E18QTransactionError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 199;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_error(enum DS28E18QTransactionError value) { error = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  enum DS28E18QTransactionError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class CouldNotFindDS28E18Q_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint8_t family_code;
  static_assert((sizeof(family_code) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  uint8_t crc_code;
  static_assert((sizeof(crc_code) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::CouldNotFindDS28E18Q;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 200;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_family_code(uint8_t value) { family_code = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_crc_code(uint8_t value) { crc_code = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint8_t get_family_code() { return family_code; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  uint8_t get_crc_code() { return crc_code; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &family_code, sizeof(family_code));
    *index += sizeof(family_code);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &crc_code, sizeof(crc_code));
    *index += sizeof(crc_code);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&family_code, buf + index, sizeof(family_code));
    index += sizeof(family_code);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&crc_code, buf + index, sizeof(crc_code));
    index += sizeof(crc_code);
  }
};

class CouldNotFindDS28E18Q_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint8_t family_code;
  static_assert((sizeof(family_code) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  uint8_t crc_code;
  static_assert((sizeof(crc_code) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::CouldNotFindDS28E18Q;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 201;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_family_code(uint8_t value) { family_code = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_crc_code(uint8_t value) { crc_code = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint8_t get_family_code() { return family_code; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  uint8_t get_crc_code() { return crc_code; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &family_code, sizeof(family_code));
    *index += sizeof(family_code);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &crc_code, sizeof(crc_code));
    *index += sizeof(crc_code);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&family_code, buf + index, sizeof(family_code));
    index += sizeof(family_code);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&crc_code, buf + index, sizeof(crc_code));
    index += sizeof(crc_code);
  }
};

class CouldNotFindDS28E18Q_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint8_t family_code;
  static_assert((sizeof(family_code) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  uint8_t crc_code;
  static_assert((sizeof(crc_code) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::CouldNotFindDS28E18Q;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 202;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_family_code(uint8_t value) { family_code = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_crc_code(uint8_t value) { crc_code = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint8_t get_family_code() { return family_code; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  uint8_t get_crc_code() { return crc_code; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &family_code, sizeof(family_code));
    *index += sizeof(family_code);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &crc_code, sizeof(crc_code));
    *index += sizeof(crc_code);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&family_code, buf + index, sizeof(family_code));
    index += sizeof(family_code);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&crc_code, buf + index, sizeof(crc_code));
    index += sizeof(crc_code);
  }
};

class CouldNotFindDS28E18Q_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t chip_index;
  static_assert((sizeof(chip_index) == 1), "invalid size");
  uint8_t family_code;
  static_assert((sizeof(family_code) == 1), "invalid size");
  uint32_t truncated_serial;
  static_assert((sizeof(truncated_serial) == 4), "invalid size");
  uint8_t crc_code;
  static_assert((sizeof(crc_code) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::CouldNotFindDS28E18Q;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 203;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_chip_index(uint8_t value) { chip_index = value; }
  void set_family_code(uint8_t value) { family_code = value; }
  void set_truncated_serial(uint32_t value) { truncated_serial = value; }
  void set_crc_code(uint8_t value) { crc_code = value; }
  uint8_t get_chip_index() { return chip_index; }
  uint8_t get_family_code() { return family_code; }
  uint32_t get_truncated_serial() { return truncated_serial; }
  uint8_t get_crc_code() { return crc_code; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &chip_index, sizeof(chip_index));
    *index += sizeof(chip_index);
    memcpy(buf + *index, &family_code, sizeof(family_code));
    *index += sizeof(family_code);
    memcpy(buf + *index, &truncated_serial, sizeof(truncated_serial));
    *index += sizeof(truncated_serial);
    memcpy(buf + *index, &crc_code, sizeof(crc_code));
    *index += sizeof(crc_code);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&chip_index, buf + index, sizeof(chip_index));
    index += sizeof(chip_index);
    memcpy(&family_code, buf + index, sizeof(family_code));
    index += sizeof(family_code);
    memcpy(&truncated_serial, buf + index, sizeof(truncated_serial));
    index += sizeof(truncated_serial);
    memcpy(&crc_code, buf + index, sizeof(crc_code));
    index += sizeof(crc_code);
  }
};

class MAX31850KError_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum MAX31850KError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::MAX31850KError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 204;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum MAX31850KError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum MAX31850KError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class MAX31850KError_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum MAX31850KError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::MAX31850KError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 205;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum MAX31850KError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum MAX31850KError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class MAX31856Error_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t raw_fault_register;
  static_assert((sizeof(raw_fault_register) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::MAX31856Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 206;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_raw_fault_register(uint8_t value) { raw_fault_register = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint8_t get_raw_fault_register() { return raw_fault_register; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &raw_fault_register, sizeof(raw_fault_register));
    *index += sizeof(raw_fault_register);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&raw_fault_register, buf + index, sizeof(raw_fault_register));
    index += sizeof(raw_fault_register);
  }
};

class MAX31865Error_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint8_t raw_fault_register;
  static_assert((sizeof(raw_fault_register) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::MAX31865Error;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 207;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_raw_fault_register(uint8_t value) { raw_fault_register = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  uint8_t get_raw_fault_register() { return raw_fault_register; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &raw_fault_register, sizeof(raw_fault_register));
    *index += sizeof(raw_fault_register);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&raw_fault_register, buf + index, sizeof(raw_fault_register));
    index += sizeof(raw_fault_register);
  }
};

class ValveActuation_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  uint32_t distance_mm;
  static_assert((sizeof(distance_mm) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::ValveActuation;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 208;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_distance_mm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -500, 500, &distance_mm);
  }
  uint8_t get_sensor_index() { return sensor_index; }
  EDDA_FLOAT_DEF get_distance_mm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(distance_mm, -500, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &distance_mm, sizeof(distance_mm));
    *index += sizeof(distance_mm);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&distance_mm, buf + index, sizeof(distance_mm));
    index += sizeof(distance_mm);
  }
};

class ValveActuationError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t sensor_index;
  static_assert((sizeof(sensor_index) == 1), "invalid size");
  enum ValveActuationError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::ValveActuationError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 209;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_sensor_index(uint8_t value) { sensor_index = value; }
  void set_error(enum ValveActuationError value) { error = value; }
  uint8_t get_sensor_index() { return sensor_index; }
  enum ValveActuationError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &sensor_index, sizeof(sensor_index));
    *index += sizeof(sensor_index);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&sensor_index, buf + index, sizeof(sensor_index));
    index += sizeof(sensor_index);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class Humidity_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t relative_humidity;
  static_assert((sizeof(relative_humidity) == 2), "invalid size");
  uint8_t is_heater_on;
  static_assert((sizeof(is_heater_on) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::Humidity;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 210;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_relative_humidity(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100, &relative_humidity);
  }
  void set_is_heater_on(uint8_t value) { is_heater_on = value; }
  EDDA_FLOAT_DEF get_relative_humidity() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(relative_humidity, 0, 100, &out);
    return out;
  }
  uint8_t get_is_heater_on() { return is_heater_on; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &relative_humidity, sizeof(relative_humidity));
    *index += sizeof(relative_humidity);
    memcpy(buf + *index, &is_heater_on, sizeof(is_heater_on));
    *index += sizeof(is_heater_on);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&relative_humidity, buf + index, sizeof(relative_humidity));
    index += sizeof(relative_humidity);
    memcpy(&is_heater_on, buf + index, sizeof(is_heater_on));
    index += sizeof(is_heater_on);
  }
};

class HumidityError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum HumidityError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::HumidityError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 211;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum HumidityError value) { error = value; }
  enum HumidityError get_error() { return error; }
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
  uint8_t id = 212;
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
  uint8_t id = 213;
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

class AccelerationError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum AccelerationError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::AccelerationError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 214;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum AccelerationError value) { error = value; }
  enum AccelerationError get_error() { return error; }
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

class AmbientLight_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  float_t ambientLight_lux;
  static_assert((sizeof(ambientLight_lux) == 4), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::AmbientLight;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 215;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_ambientLight_lux(float_t value) { ambientLight_lux = value; }
  float_t get_ambientLight_lux() { return ambientLight_lux; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &ambientLight_lux, sizeof(ambientLight_lux));
    *index += sizeof(ambientLight_lux);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&ambientLight_lux, buf + index, sizeof(ambientLight_lux));
    index += sizeof(ambientLight_lux);
  }
};

class AmbientLightError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum AmbientLightError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::AmbientLightError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 216;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_error(enum AmbientLightError value) { error = value; }
  enum AmbientLightError get_error() { return error; }
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

class PartialDebugMessage_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 217;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Telemetry_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 217;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 218;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Controller_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 218;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 219;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Pressure_Top_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 219;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 220;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Pressure_Bottom_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 220;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Simulator_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 221;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class PartialDebugMessage_from_Edda_Simulator_to_Flight_Controller
    : public MessageBase {
public:
  uint8_t length;
  static_assert((sizeof(length) == 1), "invalid size");
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
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PartialDebugMessage;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Flight_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 221;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_length(uint8_t value) { length = value; }
  void set_byte0(uint8_t value) { byte0 = value; }
  void set_byte1(uint8_t value) { byte1 = value; }
  void set_byte2(uint8_t value) { byte2 = value; }
  void set_byte3(uint8_t value) { byte3 = value; }
  void set_byte4(uint8_t value) { byte4 = value; }
  void set_byte5(uint8_t value) { byte5 = value; }
  void set_byte6(uint8_t value) { byte6 = value; }
  uint8_t get_length() { return length; }
  uint8_t get_byte0() { return byte0; }
  uint8_t get_byte1() { return byte1; }
  uint8_t get_byte2() { return byte2; }
  uint8_t get_byte3() { return byte3; }
  uint8_t get_byte4() { return byte4; }
  uint8_t get_byte5() { return byte5; }
  uint8_t get_byte6() { return byte6; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &length, sizeof(length));
    *index += sizeof(length);
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
    memcpy(&length, buf + index, sizeof(length));
    index += sizeof(length);
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

class TaskInfo_from_Edda_Telemetry_to_Ground_Controller : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t taskTime_microseconds;
  static_assert((sizeof(taskTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 222;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_taskTime_microseconds(uint32_t value) {
    taskTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum TaskType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_taskTime_microseconds() { return taskTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &taskTime_microseconds, sizeof(taskTime_microseconds));
    *index += sizeof(taskTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&taskTime_microseconds, buf + index, sizeof(taskTime_microseconds));
    index += sizeof(taskTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class TaskInfo_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t taskTime_microseconds;
  static_assert((sizeof(taskTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 223;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_taskTime_microseconds(uint32_t value) {
    taskTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum TaskType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_taskTime_microseconds() { return taskTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &taskTime_microseconds, sizeof(taskTime_microseconds));
    *index += sizeof(taskTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&taskTime_microseconds, buf + index, sizeof(taskTime_microseconds));
    index += sizeof(taskTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class TaskInfo_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t taskTime_microseconds;
  static_assert((sizeof(taskTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 224;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_taskTime_microseconds(uint32_t value) {
    taskTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum TaskType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_taskTime_microseconds() { return taskTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &taskTime_microseconds, sizeof(taskTime_microseconds));
    *index += sizeof(taskTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&taskTime_microseconds, buf + index, sizeof(taskTime_microseconds));
    index += sizeof(taskTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class TaskInfo_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t taskTime_microseconds;
  static_assert((sizeof(taskTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 225;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_taskTime_microseconds(uint32_t value) {
    taskTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum TaskType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_taskTime_microseconds() { return taskTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &taskTime_microseconds, sizeof(taskTime_microseconds));
    *index += sizeof(taskTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&taskTime_microseconds, buf + index, sizeof(taskTime_microseconds));
    index += sizeof(taskTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class TaskInfo_from_Edda_Simulator_to_Ground_Controller : public MessageBase {
public:
  enum TaskType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t taskTime_microseconds;
  static_assert((sizeof(taskTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::TaskInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 226;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum TaskType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_taskTime_microseconds(uint32_t value) {
    taskTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum TaskType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_taskTime_microseconds() { return taskTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &taskTime_microseconds, sizeof(taskTime_microseconds));
    *index += sizeof(taskTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&taskTime_microseconds, buf + index, sizeof(taskTime_microseconds));
    index += sizeof(taskTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class LoopInfo_from_Edda_Telemetry_to_Ground_Controller : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t loopTime_microseconds;
  static_assert((sizeof(loopTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 227;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_loopTime_microseconds(uint32_t value) {
    loopTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum LoopType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_loopTime_microseconds() { return loopTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &loopTime_microseconds, sizeof(loopTime_microseconds));
    *index += sizeof(loopTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&loopTime_microseconds, buf + index, sizeof(loopTime_microseconds));
    index += sizeof(loopTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class LoopInfo_from_Edda_Controller_to_Ground_Controller : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t loopTime_microseconds;
  static_assert((sizeof(loopTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 228;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_loopTime_microseconds(uint32_t value) {
    loopTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum LoopType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_loopTime_microseconds() { return loopTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &loopTime_microseconds, sizeof(loopTime_microseconds));
    *index += sizeof(loopTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&loopTime_microseconds, buf + index, sizeof(loopTime_microseconds));
    index += sizeof(loopTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class LoopInfo_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t loopTime_microseconds;
  static_assert((sizeof(loopTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 229;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_loopTime_microseconds(uint32_t value) {
    loopTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum LoopType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_loopTime_microseconds() { return loopTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &loopTime_microseconds, sizeof(loopTime_microseconds));
    *index += sizeof(loopTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&loopTime_microseconds, buf + index, sizeof(loopTime_microseconds));
    index += sizeof(loopTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class LoopInfo_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t loopTime_microseconds;
  static_assert((sizeof(loopTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 230;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_loopTime_microseconds(uint32_t value) {
    loopTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum LoopType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_loopTime_microseconds() { return loopTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &loopTime_microseconds, sizeof(loopTime_microseconds));
    *index += sizeof(loopTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&loopTime_microseconds, buf + index, sizeof(loopTime_microseconds));
    index += sizeof(loopTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class LoopInfo_from_Edda_Simulator_to_Ground_Controller : public MessageBase {
public:
  enum LoopType type;
  static_assert((sizeof(type) == 1), "invalid size");
  uint8_t thread_id;
  static_assert((sizeof(thread_id) == 1), "invalid size");
  uint32_t loopTime_microseconds;
  static_assert((sizeof(loopTime_microseconds) == 4), "invalid size");
  uint16_t truncated_startTime_microseconds;
  static_assert((sizeof(truncated_startTime_microseconds) == 2),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::LoopInfo;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Simulator;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 231;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_type(enum LoopType value) { type = value; }
  void set_thread_id(uint8_t value) { thread_id = value; }
  void set_loopTime_microseconds(uint32_t value) {
    loopTime_microseconds = value;
  }
  void set_truncated_startTime_microseconds(uint16_t value) {
    truncated_startTime_microseconds = value;
  }
  enum LoopType get_type() { return type; }
  uint8_t get_thread_id() { return thread_id; }
  uint32_t get_loopTime_microseconds() { return loopTime_microseconds; }
  uint16_t get_truncated_startTime_microseconds() {
    return truncated_startTime_microseconds;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &type, sizeof(type));
    *index += sizeof(type);
    memcpy(buf + *index, &thread_id, sizeof(thread_id));
    *index += sizeof(thread_id);
    memcpy(buf + *index, &loopTime_microseconds, sizeof(loopTime_microseconds));
    *index += sizeof(loopTime_microseconds);
    memcpy(buf + *index, &truncated_startTime_microseconds,
           sizeof(truncated_startTime_microseconds));
    *index += sizeof(truncated_startTime_microseconds);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&type, buf + index, sizeof(type));
    index += sizeof(type);
    memcpy(&thread_id, buf + index, sizeof(thread_id));
    index += sizeof(thread_id);
    memcpy(&loopTime_microseconds, buf + index, sizeof(loopTime_microseconds));
    index += sizeof(loopTime_microseconds);
    memcpy(&truncated_startTime_microseconds, buf + index,
           sizeof(truncated_startTime_microseconds));
    index += sizeof(truncated_startTime_microseconds);
  }
};

class PowerControlNewStateRequest_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  enum PowerControlChannelStateRequest requested_state;
  static_assert((sizeof(requested_state) == 1), "invalid size");
  enum CircumventArmingCheck circumvent_arming_checks;
  static_assert((sizeof(circumvent_arming_checks) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PowerControlNewStateRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 51;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_requested_state(enum PowerControlChannelStateRequest value) {
    requested_state = value;
  }
  void set_circumvent_arming_checks(enum CircumventArmingCheck value) {
    circumvent_arming_checks = value;
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  enum PowerControlChannelStateRequest get_requested_state() {
    return requested_state;
  }
  enum CircumventArmingCheck get_circumvent_arming_checks() {
    return circumvent_arming_checks;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &requested_state, sizeof(requested_state));
    *index += sizeof(requested_state);
    memcpy(buf + *index, &circumvent_arming_checks,
           sizeof(circumvent_arming_checks));
    *index += sizeof(circumvent_arming_checks);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&requested_state, buf + index, sizeof(requested_state));
    index += sizeof(requested_state);
    memcpy(&circumvent_arming_checks, buf + index,
           sizeof(circumvent_arming_checks));
    index += sizeof(circumvent_arming_checks);
  }
};

class PowerControlNewStateResponse_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  enum PowerControlChannelStateRequest requested_state;
  static_assert((sizeof(requested_state) == 1), "invalid size");
  enum CircumventArmingCheck requested_circumvent_arming_checks;
  static_assert((sizeof(requested_circumvent_arming_checks) == 1),
                "invalid size");
  enum PowerControlChannelStateRequestResult result;
  static_assert((sizeof(result) == 1), "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message = EDDA::messages::PowerControlNewStateResponse;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 74;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_requested_state(enum PowerControlChannelStateRequest value) {
    requested_state = value;
  }
  void
  set_requested_circumvent_arming_checks(enum CircumventArmingCheck value) {
    requested_circumvent_arming_checks = value;
  }
  void set_result(enum PowerControlChannelStateRequestResult value) {
    result = value;
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  enum PowerControlChannelStateRequest get_requested_state() {
    return requested_state;
  }
  enum CircumventArmingCheck get_requested_circumvent_arming_checks() {
    return requested_circumvent_arming_checks;
  }
  enum PowerControlChannelStateRequestResult get_result() { return result; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &requested_state, sizeof(requested_state));
    *index += sizeof(requested_state);
    memcpy(buf + *index, &requested_circumvent_arming_checks,
           sizeof(requested_circumvent_arming_checks));
    *index += sizeof(requested_circumvent_arming_checks);
    memcpy(buf + *index, &result, sizeof(result));
    *index += sizeof(result);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&requested_state, buf + index, sizeof(requested_state));
    index += sizeof(requested_state);
    memcpy(&requested_circumvent_arming_checks, buf + index,
           sizeof(requested_circumvent_arming_checks));
    index += sizeof(requested_circumvent_arming_checks);
    memcpy(&result, buf + index, sizeof(result));
    index += sizeof(result);
  }
};

class PowerControlGetState_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  uint8_t size = 1;
  enum EDDA::messages message = EDDA::messages::PowerControlGetState;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 52;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
  }
};

class PowerControlState_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  enum PowerControlChannelState channel_state;
  static_assert((sizeof(channel_state) == 1), "invalid size");
  enum owerControlChannelGateState gate_state;
  static_assert((sizeof(gate_state) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::PowerControlState;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 75;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_channel_state(enum PowerControlChannelState value) {
    channel_state = value;
  }
  void set_gate_state(enum owerControlChannelGateState value) {
    gate_state = value;
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  enum PowerControlChannelState get_channel_state() { return channel_state; }
  enum owerControlChannelGateState get_gate_state() { return gate_state; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &channel_state, sizeof(channel_state));
    *index += sizeof(channel_state);
    memcpy(buf + *index, &gate_state, sizeof(gate_state));
    *index += sizeof(gate_state);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&channel_state, buf + index, sizeof(channel_state));
    index += sizeof(channel_state);
    memcpy(&gate_state, buf + index, sizeof(gate_state));
    index += sizeof(gate_state);
  }
};

class PowerControlVoltages_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  uint16_t voltage_3v3_volts;
  static_assert((sizeof(voltage_3v3_volts) == 2), "invalid size");
  uint16_t voltage_input_volts;
  static_assert((sizeof(voltage_input_volts) == 2), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PowerControlVoltages;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 232;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_voltage_3v3_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &voltage_3v3_volts);
  }
  void set_voltage_input_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &voltage_input_volts);
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  EDDA_FLOAT_DEF get_voltage_3v3_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_3v3_volts, 0, 5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_voltage_input_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_input_volts, 0, 30, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &voltage_3v3_volts, sizeof(voltage_3v3_volts));
    *index += sizeof(voltage_3v3_volts);
    memcpy(buf + *index, &voltage_input_volts, sizeof(voltage_input_volts));
    *index += sizeof(voltage_input_volts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&voltage_3v3_volts, buf + index, sizeof(voltage_3v3_volts));
    index += sizeof(voltage_3v3_volts);
    memcpy(&voltage_input_volts, buf + index, sizeof(voltage_input_volts));
    index += sizeof(voltage_input_volts);
  }
};

class PowerControlResistance_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  uint32_t resistance_ohms;
  static_assert((sizeof(resistance_ohms) == 4), "invalid size");
  enum PowerControlResistanceSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::PowerControlResistance;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 233;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_resistance_ohms(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000, &resistance_ohms);
  }
  void set_source(enum PowerControlResistanceSource value) { source = value; }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  EDDA_FLOAT_DEF get_resistance_ohms() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(resistance_ohms, 0, 100000, &out);
    return out;
  }
  enum PowerControlResistanceSource get_source() { return source; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &resistance_ohms, sizeof(resistance_ohms));
    *index += sizeof(resistance_ohms);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&resistance_ohms, buf + index, sizeof(resistance_ohms));
    index += sizeof(resistance_ohms);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
  }
};

class PowerControlEstimates_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  uint16_t estimated_current_amperes;
  static_assert((sizeof(estimated_current_amperes) == 2), "invalid size");
  uint16_t estimated_power_amperes;
  static_assert((sizeof(estimated_power_amperes) == 2), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::PowerControlEstimates;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 234;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_estimated_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100, &estimated_current_amperes);
  }
  void set_estimated_power_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 3000, &estimated_power_amperes);
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  EDDA_FLOAT_DEF get_estimated_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(estimated_current_amperes, 0, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_estimated_power_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(estimated_power_amperes, 0, 3000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &estimated_current_amperes,
           sizeof(estimated_current_amperes));
    *index += sizeof(estimated_current_amperes);
    memcpy(buf + *index, &estimated_power_amperes,
           sizeof(estimated_power_amperes));
    *index += sizeof(estimated_power_amperes);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&estimated_current_amperes, buf + index,
           sizeof(estimated_current_amperes));
    index += sizeof(estimated_current_amperes);
    memcpy(&estimated_power_amperes, buf + index,
           sizeof(estimated_power_amperes));
    index += sizeof(estimated_power_amperes);
  }
};

class PowerControlLoadMeasurement_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  uint16_t voltage_volts;
  static_assert((sizeof(voltage_volts) == 2), "invalid size");
  uint16_t current_amperes;
  static_assert((sizeof(current_amperes) == 2), "invalid size");
  uint16_t power_watts;
  static_assert((sizeof(power_watts) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::PowerControlLoadMeasurement;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 235;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_voltage_volts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &voltage_volts);
  }
  void set_current_amperes(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &current_amperes);
  }
  void set_power_watts(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -450, 450, &power_watts);
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  EDDA_FLOAT_DEF get_voltage_volts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(voltage_volts, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_current_amperes() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(current_amperes, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_power_watts() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(power_watts, -450, 450, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &voltage_volts, sizeof(voltage_volts));
    *index += sizeof(voltage_volts);
    memcpy(buf + *index, &current_amperes, sizeof(current_amperes));
    *index += sizeof(current_amperes);
    memcpy(buf + *index, &power_watts, sizeof(power_watts));
    *index += sizeof(power_watts);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&voltage_volts, buf + index, sizeof(voltage_volts));
    index += sizeof(voltage_volts);
    memcpy(&current_amperes, buf + index, sizeof(current_amperes));
    index += sizeof(current_amperes);
    memcpy(&power_watts, buf + index, sizeof(power_watts));
    index += sizeof(power_watts);
  }
};

class PowerControlLoadMeasurementError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  enum PowerControlLoadMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message =
      EDDA::messages::PowerControlLoadMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 236;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_error(enum PowerControlLoadMeasurementError value) { error = value; }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  enum PowerControlLoadMeasurementError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class
    PowerControlResistanceMeasurementError_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerControlChannel power_control_channel_id;
  static_assert((sizeof(power_control_channel_id) == 1), "invalid size");
  enum PowerControlResistanceMeasurementError error;
  static_assert((sizeof(error) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message =
      EDDA::messages::PowerControlResistanceMeasurementError;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 237;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_power_control_channel_id(enum PowerControlChannel value) {
    power_control_channel_id = value;
  }
  void set_error(enum PowerControlResistanceMeasurementError value) {
    error = value;
  }
  enum PowerControlChannel get_power_control_channel_id() {
    return power_control_channel_id;
  }
  enum PowerControlResistanceMeasurementError get_error() { return error; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &power_control_channel_id,
           sizeof(power_control_channel_id));
    *index += sizeof(power_control_channel_id);
    memcpy(buf + *index, &error, sizeof(error));
    *index += sizeof(error);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&power_control_channel_id, buf + index,
           sizeof(power_control_channel_id));
    index += sizeof(power_control_channel_id);
    memcpy(&error, buf + index, sizeof(error));
    index += sizeof(error);
  }
};

class PerformIgnition_from_Ground_Controller_to_Edda_Controller
    : public MessageBase {
public:
  int8_t this_number_must_be_positive_1;
  static_assert((sizeof(this_number_must_be_positive_1) == 1), "invalid size");
  int8_t this_number_must_be_negative_2;
  static_assert((sizeof(this_number_must_be_negative_2) == 1), "invalid size");
  int8_t this_number_must_be_positive_4;
  static_assert((sizeof(this_number_must_be_positive_4) == 1), "invalid size");
  int8_t this_number_must_be_negative_8;
  static_assert((sizeof(this_number_must_be_negative_8) == 1), "invalid size");
  int8_t this_number_must_be_positive_16;
  static_assert((sizeof(this_number_must_be_positive_16) == 1), "invalid size");
  int8_t this_number_must_be_negative_32;
  static_assert((sizeof(this_number_must_be_negative_32) == 1), "invalid size");
  int8_t this_number_must_be_positive_64;
  static_assert((sizeof(this_number_must_be_positive_64) == 1), "invalid size");
  int8_t this_number_must_be_negative_128;
  static_assert((sizeof(this_number_must_be_negative_128) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::PerformIgnition;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 53;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_this_number_must_be_positive_1(int8_t value) {
    this_number_must_be_positive_1 = value;
  }
  void set_this_number_must_be_negative_2(int8_t value) {
    this_number_must_be_negative_2 = value;
  }
  void set_this_number_must_be_positive_4(int8_t value) {
    this_number_must_be_positive_4 = value;
  }
  void set_this_number_must_be_negative_8(int8_t value) {
    this_number_must_be_negative_8 = value;
  }
  void set_this_number_must_be_positive_16(int8_t value) {
    this_number_must_be_positive_16 = value;
  }
  void set_this_number_must_be_negative_32(int8_t value) {
    this_number_must_be_negative_32 = value;
  }
  void set_this_number_must_be_positive_64(int8_t value) {
    this_number_must_be_positive_64 = value;
  }
  void set_this_number_must_be_negative_128(int8_t value) {
    this_number_must_be_negative_128 = value;
  }
  int8_t get_this_number_must_be_positive_1() {
    return this_number_must_be_positive_1;
  }
  int8_t get_this_number_must_be_negative_2() {
    return this_number_must_be_negative_2;
  }
  int8_t get_this_number_must_be_positive_4() {
    return this_number_must_be_positive_4;
  }
  int8_t get_this_number_must_be_negative_8() {
    return this_number_must_be_negative_8;
  }
  int8_t get_this_number_must_be_positive_16() {
    return this_number_must_be_positive_16;
  }
  int8_t get_this_number_must_be_negative_32() {
    return this_number_must_be_negative_32;
  }
  int8_t get_this_number_must_be_positive_64() {
    return this_number_must_be_positive_64;
  }
  int8_t get_this_number_must_be_negative_128() {
    return this_number_must_be_negative_128;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &this_number_must_be_positive_1,
           sizeof(this_number_must_be_positive_1));
    *index += sizeof(this_number_must_be_positive_1);
    memcpy(buf + *index, &this_number_must_be_negative_2,
           sizeof(this_number_must_be_negative_2));
    *index += sizeof(this_number_must_be_negative_2);
    memcpy(buf + *index, &this_number_must_be_positive_4,
           sizeof(this_number_must_be_positive_4));
    *index += sizeof(this_number_must_be_positive_4);
    memcpy(buf + *index, &this_number_must_be_negative_8,
           sizeof(this_number_must_be_negative_8));
    *index += sizeof(this_number_must_be_negative_8);
    memcpy(buf + *index, &this_number_must_be_positive_16,
           sizeof(this_number_must_be_positive_16));
    *index += sizeof(this_number_must_be_positive_16);
    memcpy(buf + *index, &this_number_must_be_negative_32,
           sizeof(this_number_must_be_negative_32));
    *index += sizeof(this_number_must_be_negative_32);
    memcpy(buf + *index, &this_number_must_be_positive_64,
           sizeof(this_number_must_be_positive_64));
    *index += sizeof(this_number_must_be_positive_64);
    memcpy(buf + *index, &this_number_must_be_negative_128,
           sizeof(this_number_must_be_negative_128));
    *index += sizeof(this_number_must_be_negative_128);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&this_number_must_be_positive_1, buf + index,
           sizeof(this_number_must_be_positive_1));
    index += sizeof(this_number_must_be_positive_1);
    memcpy(&this_number_must_be_negative_2, buf + index,
           sizeof(this_number_must_be_negative_2));
    index += sizeof(this_number_must_be_negative_2);
    memcpy(&this_number_must_be_positive_4, buf + index,
           sizeof(this_number_must_be_positive_4));
    index += sizeof(this_number_must_be_positive_4);
    memcpy(&this_number_must_be_negative_8, buf + index,
           sizeof(this_number_must_be_negative_8));
    index += sizeof(this_number_must_be_negative_8);
    memcpy(&this_number_must_be_positive_16, buf + index,
           sizeof(this_number_must_be_positive_16));
    index += sizeof(this_number_must_be_positive_16);
    memcpy(&this_number_must_be_negative_32, buf + index,
           sizeof(this_number_must_be_negative_32));
    index += sizeof(this_number_must_be_negative_32);
    memcpy(&this_number_must_be_positive_64, buf + index,
           sizeof(this_number_must_be_positive_64));
    index += sizeof(this_number_must_be_positive_64);
    memcpy(&this_number_must_be_negative_128, buf + index,
           sizeof(this_number_must_be_negative_128));
    index += sizeof(this_number_must_be_negative_128);
  }
};

class IgnitionHappened_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::IgnitionHappened;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 76;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class IgnitionHappened_from_Edda_Controller_to_Edda_Telemetry
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::IgnitionHappened;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Telemetry;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 76;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class IgnitionHappened_from_Edda_Controller_to_Edda_Pressure_Top
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::IgnitionHappened;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 76;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class IgnitionHappened_from_Edda_Controller_to_Edda_Pressure_Bottom
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::IgnitionHappened;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 76;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

class IgnitionCannotHappen_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t size = 0;
  enum EDDA::messages message = EDDA::messages::IgnitionCannotHappen;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 77;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void build_buf(uint8_t *buf, uint8_t *index) override {}
  void parse_buf(uint8_t *buf) override {}
};

void rx(CurrentTimePing_from_Flight_Controller_to_Edda_Controller msg);
void rx(CurrentTimePing_from_Flight_Controller_to_Edda_Controller msg,
        void *misc);
void rx(CanLatency_from_Flight_Controller_to_Ground_Controller msg);
void rx(CanLatency_from_Flight_Controller_to_Ground_Controller msg, void *misc);
void rx(CurrentTimePong_from_Edda_Controller_to_Flight_Controller msg);
void rx(CurrentTimePong_from_Edda_Controller_to_Flight_Controller msg,
        void *misc);
void rx(CurrentTimePong_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(CurrentTimePong_from_Edda_Telemetry_to_Flight_Controller msg,
        void *misc);
void rx(CurrentTimePong_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(CurrentTimePong_from_Edda_Pressure_Top_to_Flight_Controller msg,
        void *misc);
void rx(CurrentTimePong_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(CurrentTimePong_from_Edda_Pressure_Bottom_to_Flight_Controller msg,
        void *misc);
void rx(CurrentTimePong_from_Edda_Simulator_to_Flight_Controller msg);
void rx(CurrentTimePong_from_Edda_Simulator_to_Flight_Controller msg,
        void *misc);
void rx(SayHi_from_Flight_Controller_to_Edda_Controller msg);
void rx(SayHi_from_Flight_Controller_to_Edda_Controller msg, void *misc);
void rx(Hello_from_Edda_Controller_to_Flight_Controller msg);
void rx(Hello_from_Edda_Controller_to_Flight_Controller msg, void *misc);
void rx(Hello_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(Hello_from_Edda_Telemetry_to_Flight_Controller msg, void *misc);
void rx(Hello_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(Hello_from_Edda_Pressure_Top_to_Flight_Controller msg, void *misc);
void rx(Hello_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(Hello_from_Edda_Pressure_Bottom_to_Flight_Controller msg, void *misc);
void rx(Hello_from_Edda_Simulator_to_Flight_Controller msg);
void rx(Hello_from_Edda_Simulator_to_Flight_Controller msg, void *misc);
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
void rx(CanStatistics_from_Edda_Simulator_to_Ground_Controller msg);
void rx(CanStatistics_from_Edda_Simulator_to_Ground_Controller msg, void *misc);
void rx(WenHop_from_Edda_Controller_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Controller_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Telemetry_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Telemetry_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Pressure_Top_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Pressure_Top_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Pressure_Bottom_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Pressure_Bottom_to_Flight_Controller msg, void *misc);
void rx(WenHop_from_Edda_Simulator_to_Flight_Controller msg);
void rx(WenHop_from_Edda_Simulator_to_Flight_Controller msg, void *misc);
void rx(SetDebugModeRequest_from_Flight_Controller_to_Edda_Controller msg);
void rx(SetDebugModeRequest_from_Flight_Controller_to_Edda_Controller msg,
        void *misc);
void rx(SetPowerModeRequest_from_Flight_Controller_to_Edda_Controller msg);
void rx(SetPowerModeRequest_from_Flight_Controller_to_Edda_Controller msg,
        void *misc);
void rx(GoingToSleep_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(GoingToSleep_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(GoingToSleep_from_Edda_Controller_to_Ground_Controller msg);
void rx(GoingToSleep_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(GoingToSleep_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(GoingToSleep_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(GoingToSleep_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(GoingToSleep_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(GoingToSleep_from_Edda_Simulator_to_Ground_Controller msg);
void rx(GoingToSleep_from_Edda_Simulator_to_Ground_Controller msg, void *misc);
void rx(WokeUp_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(WokeUp_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(WokeUp_from_Edda_Controller_to_Ground_Controller msg);
void rx(WokeUp_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(WokeUp_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(WokeUp_from_Edda_Pressure_Top_to_Ground_Controller msg, void *misc);
void rx(WokeUp_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(WokeUp_from_Edda_Pressure_Bottom_to_Ground_Controller msg, void *misc);
void rx(WokeUp_from_Edda_Simulator_to_Ground_Controller msg);
void rx(WokeUp_from_Edda_Simulator_to_Ground_Controller msg, void *misc);
void rx(RequestReset_from_Ground_Controller_to_Edda_Controller msg);
void rx(RequestReset_from_Ground_Controller_to_Edda_Controller msg, void *misc);
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
void rx(PowerInputMeasurement_from_Edda_Simulator_to_Ground_Controller msg);
void rx(PowerInputMeasurement_from_Edda_Simulator_to_Ground_Controller msg,
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
void rx(
    PowerInputMeasurementError_from_Edda_Simulator_to_Ground_Controller msg);
void rx(PowerInputMeasurementError_from_Edda_Simulator_to_Ground_Controller msg,
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
void rx(TransducerPressure_from_Edda_Simulator_to_Ground_Controller msg);
void rx(TransducerPressure_from_Edda_Simulator_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressure_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(AmbientPressure_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressure_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(AmbientPressure_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressure_from_Edda_Simulator_to_Ground_Controller msg);
void rx(AmbientPressure_from_Edda_Simulator_to_Ground_Controller msg,
        void *misc);
void rx(TransducerError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TransducerError_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(TransducerError_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TransducerError_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(TransducerError_from_Edda_Simulator_to_Ground_Controller msg);
void rx(TransducerError_from_Edda_Simulator_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressureError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(AmbientPressureError_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    AmbientPressureError_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(AmbientPressureError_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(AmbientPressureError_from_Edda_Simulator_to_Ground_Controller msg);
void rx(AmbientPressureError_from_Edda_Simulator_to_Ground_Controller msg,
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
void rx(ColdSideTemperature_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Controller_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(ColdSideTemperature_from_Edda_Simulator_to_Ground_Controller msg);
void rx(ColdSideTemperature_from_Edda_Simulator_to_Ground_Controller msg,
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
void rx(OneWireBusError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(OneWireBusError_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(
    ThermocoupleTypeKTemperature_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(
    ThermocoupleTypeKTemperature_from_Edda_Telemetry_to_Ground_Controller msg,
    void *misc);
void rx(
    ThermocoupleTypeKTemperature_from_Edda_Simulator_to_Ground_Controller msg);
void rx(
    ThermocoupleTypeKTemperature_from_Edda_Simulator_to_Ground_Controller msg,
    void *misc);
void rx(SensorMeasurementInfo_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(SensorMeasurementInfo_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    SensorMeasurementInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    SensorMeasurementInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(SensorMeasurementInfo_from_Edda_Controller_to_Ground_Controller msg);
void rx(SensorMeasurementInfo_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(SensorMeasurementInfo_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(SensorMeasurementInfo_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(
    DS28E18QTransactionError_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(
    DS28E18QTransactionError_from_Edda_Pressure_Top_to_Ground_Controller msg,
    void *misc);
void rx(DS28E18QTransactionError_from_Edda_Pressure_Bottom_to_Ground_Controller
            msg);
void rx(
    DS28E18QTransactionError_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(DS28E18QTransactionError_from_Edda_Controller_to_Ground_Controller msg);
void rx(DS28E18QTransactionError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(DS28E18QTransactionError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(DS28E18QTransactionError_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(CouldNotFindDS28E18Q_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(CouldNotFindDS28E18Q_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    CouldNotFindDS28E18Q_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(CouldNotFindDS28E18Q_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(CouldNotFindDS28E18Q_from_Edda_Controller_to_Ground_Controller msg);
void rx(CouldNotFindDS28E18Q_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(CouldNotFindDS28E18Q_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(CouldNotFindDS28E18Q_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(MAX31850KError_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(MAX31850KError_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(MAX31850KError_from_Edda_Simulator_to_Ground_Controller msg);
void rx(MAX31850KError_from_Edda_Simulator_to_Ground_Controller msg,
        void *misc);
void rx(MAX31856Error_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(MAX31856Error_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(MAX31865Error_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(MAX31865Error_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(ValveActuation_from_Edda_Controller_to_Ground_Controller msg);
void rx(ValveActuation_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(ValveActuationError_from_Edda_Controller_to_Ground_Controller msg);
void rx(ValveActuationError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Humidity_from_Edda_Controller_to_Ground_Controller msg);
void rx(Humidity_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(HumidityError_from_Edda_Controller_to_Ground_Controller msg);
void rx(HumidityError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Acceleration_from_Edda_Controller_to_Ground_Controller msg);
void rx(Acceleration_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(AccelerationSelfTest_from_Edda_Controller_to_Ground_Controller msg);
void rx(AccelerationSelfTest_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(AccelerationError_from_Edda_Controller_to_Ground_Controller msg);
void rx(AccelerationError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(AmbientLight_from_Edda_Controller_to_Ground_Controller msg);
void rx(AmbientLight_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(AmbientLightError_from_Edda_Controller_to_Ground_Controller msg);
void rx(AmbientLightError_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(PartialDebugMessage_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage_from_Edda_Controller_to_Ground_Controller msg);
void rx(PartialDebugMessage_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(PartialDebugMessage_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(PartialDebugMessage_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(PartialDebugMessage_from_Edda_Simulator_to_Ground_Controller msg);
void rx(PartialDebugMessage_from_Edda_Simulator_to_Ground_Controller msg,
        void *misc);
void rx(TaskInfo_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(TaskInfo_from_Edda_Controller_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(TaskInfo_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Pressure_Top_to_Ground_Controller msg, void *misc);
void rx(TaskInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(TaskInfo_from_Edda_Simulator_to_Ground_Controller msg);
void rx(TaskInfo_from_Edda_Simulator_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Telemetry_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Controller_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Controller_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Pressure_Top_to_Ground_Controller msg, void *misc);
void rx(LoopInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(LoopInfo_from_Edda_Simulator_to_Ground_Controller msg);
void rx(LoopInfo_from_Edda_Simulator_to_Ground_Controller msg, void *misc);
void rx(
    PowerControlNewStateRequest_from_Ground_Controller_to_Edda_Controller msg);
void rx(
    PowerControlNewStateRequest_from_Ground_Controller_to_Edda_Controller msg,
    void *misc);
void rx(
    PowerControlNewStateResponse_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    PowerControlNewStateResponse_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(PowerControlGetState_from_Ground_Controller_to_Edda_Controller msg);
void rx(PowerControlGetState_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(PowerControlState_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerControlState_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerControlVoltages_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerControlVoltages_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerControlResistance_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerControlResistance_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerControlEstimates_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerControlEstimates_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    PowerControlLoadMeasurement_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    PowerControlLoadMeasurement_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(
    PowerControlLoadMeasurementError_from_Edda_Controller_to_Ground_Controller
        msg);
void rx(
    PowerControlLoadMeasurementError_from_Edda_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    PowerControlResistanceMeasurementError_from_Edda_Controller_to_Ground_Controller
        msg);
void rx(
    PowerControlResistanceMeasurementError_from_Edda_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(PerformIgnition_from_Ground_Controller_to_Edda_Controller msg);
void rx(PerformIgnition_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(IgnitionHappened_from_Edda_Controller_to_Ground_Controller msg);
void rx(IgnitionHappened_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(IgnitionCannotHappen_from_Edda_Controller_to_Ground_Controller msg);
void rx(IgnitionCannotHappen_from_Edda_Controller_to_Ground_Controller msg,
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
