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
  w = 2,
  e = 3,
  n = 4,
  h = 5,
  o = 6,
  p = 7,
  r = 8,
  b = 9,
  i = 10,
  t = 11,
  receiver_node = 12,
  debug_status_leds_mode = 13,
  debug_messages_mode = 14,
  debug_mode = 15,
  powercan_channel = 16,
  edda_signature = 17,
  request = 18,
  system_state = 19,
  gate_state = 20,
  response = 21,
  result = 22,
  checks_failed = 23,
  checks_performed = 24,
  total_checks = 25,
  truncated_frame_number = 26,
  frame_number = 27,
  time_since_boot_ms = 28,
  truncated_time_since_boot_us = 29,
  edda_telemetryboard_powerinput_voltage_volt = 30,
  edda_telemetryboard_powerinput_current_ampere = 31,
  edda_telemetryboard_powerinput_power_watt = 32,
  edda_controllerboard_powerinput_voltage_volt = 33,
  edda_controllerboard_powerinput_current_ampere = 34,
  edda_controllerboard_powerinput_power_watt = 35,
  edda_power1_powerinput_voltage_volt = 36,
  edda_power1_powerinput_current_ampere = 37,
  edda_power1_powerinput_power_watt = 38,
  edda_power2_powerinput_voltage_volt = 39,
  edda_power2_powerinput_current_ampere = 40,
  edda_power2_powerinput_power_watt = 41,
  edda_power3_powerinput_voltage_volt = 42,
  edda_power3_powerinput_current_ampere = 43,
  edda_power3_powerinput_power_watt = 44,
  edda_pressureboard_top_powerinput_voltage_volt = 45,
  edda_pressureboard_top_powerinput_current_ampere = 46,
  edda_pressureboard_top_powerinput_power_watt = 47,
  edda_pressureboard_bottom_powerinput_voltage_volt = 48,
  edda_pressureboard_bottom_powerinput_current_ampere = 49,
  edda_pressureboard_bottom_powerinput_power_watt = 50,
  sindri_electronicsvoltage_24v_volt = 51,
  sindri_electronicsvoltage_12v_volt = 52,
  sindri_electronicsvoltage_7v4_volt = 53,
  edda_power1_electronicsvoltage_3v3_volt = 54,
  edda_power2_electronicsvoltage_3v3_volt = 55,
  edda_power3_electronicsvoltage_3v3_volt = 56,
  sindri_poweroutput_ignition_voltage_volt = 57,
  sindri_poweroutput_ignition_current_ampere = 58,
  sindri_poweroutput_ignition_power_watt = 59,
  sindri_poweroutput_ventsolenoid_voltage_volt = 60,
  sindri_poweroutput_ventsolenoid_current_ampere = 61,
  sindri_poweroutput_ventsolenoid_power_watt = 62,
  sindri_poweroutput_mainvalvesolenoid_voltage_volt = 63,
  sindri_poweroutput_mainvalvesolenoid_current_ampere = 64,
  sindri_poweroutput_mainvalvesolenoid_power_watt = 65,
  edda_power1_electronicstemperature_adc_celsius = 66,
  edda_power1_electronicstemperature_pcb_celsius = 67,
  edda_power2_electronicstemperature_adc_celsius = 68,
  edda_power2_electronicstemperature_pcb_celsius = 69,
  edda_power3_electronicstemperature_adc_celsius = 70,
  edda_power3_electronicstemperature_pcb_celsius = 71,
  edda_controllerboard_electronicstemperature_microcontroller_celsius = 72,
  edda_controllerboard_electronicstemperature_powerregulator_celsius = 73,
  edda_controllerboard_electronicstemperature_humiditysensor_celsius = 74,
  edda_telemetryboard_looptime_main_second = 75,
  edda_telemetryboard_looptime_chitchat_second = 76,
  edda_telemetryboard_looptime_rgb_second = 77,
  edda_telemetryboard_looptime_rgbchitchat_second = 78,
  edda_telemetryboard_looptime_edda_second = 79,
  edda_telemetryboard_looptime_telemetry_second = 80,
  edda_telemetryboard_looptime_main_max_second = 81,
  edda_telemetryboard_looptime_main_min_second = 82,
  edda_telemetryboard_looptime_chitchat_max_second = 83,
  edda_telemetryboard_looptime_chitchat_min_second = 84,
  edda_telemetryboard_looptime_rgb_max_second = 85,
  edda_telemetryboard_looptime_rgb_min_second = 86,
  edda_telemetryboard_looptime_rgbchitchat_max_second = 87,
  edda_telemetryboard_looptime_rgbchitchat_min_second = 88,
  edda_telemetryboard_looptime_edda_max_second = 89,
  edda_telemetryboard_looptime_edda_min_second = 90,
  edda_telemetryboard_looptime_telemetry_max_second = 91,
  edda_telemetryboard_looptime_telemetry_min_second = 92,
  edda_controllerboard_looptime_main_second = 93,
  edda_controllerboard_looptime_chitchat_second = 94,
  edda_controllerboard_looptime_rgb_second = 95,
  edda_controllerboard_looptime_rgbchitchat_second = 96,
  edda_controllerboard_looptime_edda_second = 97,
  edda_controllerboard_looptime_telemetry_second = 98,
  edda_controllerboard_looptime_main_max_second = 99,
  edda_controllerboard_looptime_main_min_second = 100,
  edda_controllerboard_looptime_chitchat_max_second = 101,
  edda_controllerboard_looptime_chitchat_min_second = 102,
  edda_controllerboard_looptime_rgb_max_second = 103,
  edda_controllerboard_looptime_rgb_min_second = 104,
  edda_controllerboard_looptime_rgbchitchat_max_second = 105,
  edda_controllerboard_looptime_rgbchitchat_min_second = 106,
  edda_controllerboard_looptime_edda_max_second = 107,
  edda_controllerboard_looptime_edda_min_second = 108,
  edda_controllerboard_looptime_telemetry_max_second = 109,
  edda_controllerboard_looptime_telemetry_min_second = 110,
  edda_pressureboard_top_looptime_main_second = 111,
  edda_pressureboard_top_looptime_chitchat_second = 112,
  edda_pressureboard_top_looptime_rgb_second = 113,
  edda_pressureboard_top_looptime_rgbchitchat_second = 114,
  edda_pressureboard_top_looptime_edda_second = 115,
  edda_pressureboard_top_looptime_telemetry_second = 116,
  edda_pressureboard_top_looptime_main_max_second = 117,
  edda_pressureboard_top_looptime_main_min_second = 118,
  edda_pressureboard_top_looptime_chitchat_max_second = 119,
  edda_pressureboard_top_looptime_chitchat_min_second = 120,
  edda_pressureboard_top_looptime_rgb_max_second = 121,
  edda_pressureboard_top_looptime_rgb_min_second = 122,
  edda_pressureboard_top_looptime_rgbchitchat_max_second = 123,
  edda_pressureboard_top_looptime_rgbchitchat_min_second = 124,
  edda_pressureboard_top_looptime_edda_max_second = 125,
  edda_pressureboard_top_looptime_edda_min_second = 126,
  edda_pressureboard_top_looptime_telemetry_max_second = 127,
  edda_pressureboard_top_looptime_telemetry_min_second = 128,
  edda_pressureboard_bottom_looptime_main_second = 129,
  edda_pressureboard_bottom_looptime_chitchat_second = 130,
  edda_pressureboard_bottom_looptime_rgb_second = 131,
  edda_pressureboard_bottom_looptime_rgbchitchat_second = 132,
  edda_pressureboard_bottom_looptime_edda_second = 133,
  edda_pressureboard_bottom_looptime_telemetry_second = 134,
  edda_pressureboard_bottom_looptime_main_max_second = 135,
  edda_pressureboard_bottom_looptime_main_min_second = 136,
  edda_pressureboard_bottom_looptime_chitchat_max_second = 137,
  edda_pressureboard_bottom_looptime_chitchat_min_second = 138,
  edda_pressureboard_bottom_looptime_rgb_max_second = 139,
  edda_pressureboard_bottom_looptime_rgb_min_second = 140,
  edda_pressureboard_bottom_looptime_rgbchitchat_max_second = 141,
  edda_pressureboard_bottom_looptime_rgbchitchat_min_second = 142,
  edda_pressureboard_bottom_looptime_edda_max_second = 143,
  edda_pressureboard_bottom_looptime_edda_min_second = 144,
  edda_pressureboard_bottom_looptime_telemetry_max_second = 145,
  edda_pressureboard_bottom_looptime_telemetry_min_second = 146,
  edda_telemetryboard_electronicstemperature_microcontroller_celsius = 147,
  edda_telemetryboard_electronicstemperature_powerregulator_celsius = 148,
  edda_pressureboard_top_electronicstemperature_microcontroller_celsius = 149,
  edda_pressureboard_top_electronicstemperature_powerregulator_celsius = 150,
  edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius =
      151,
  edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius =
      152,
  edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius = 153,
  edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius =
      154,
  sindri_temperature_therm0_celsius = 155,
  sindri_temperature_therm1_celsius = 156,
  sindri_temperature_therm2_celsius = 157,
  sindri_temperature_therm3_celsius = 158,
  sindri_temperature_therm4_celsius = 159,
  sindri_temperature_therm5_celsius = 160,
  sindri_temperature_therm6_celsius = 161,
  sindri_temperature_therm7_celsius = 162,
  sindri_temperature_therm8_celsius = 163,
  sindri_temperature_therm9_celsius = 164,
  sindri_temperature_therm10_celsius = 165,
  sindri_temperature_therm11_celsius = 166,
  sindri_temperature_therm12_celsius = 167,
  sindri_temperature_therm13_celsius = 168,
  sindri_temperature_therm14_celsius = 169,
  sindri_temperature_therm15_celsius = 170,
  sindri_temperature_therm16_celsius = 171,
  sindri_temperature_therm17_celsius = 172,
  sindri_temperature_therm18_celsius = 173,
  sindri_temperature_therm19_celsius = 174,
  sindri_compensatingtemperature_therm0_celsius = 175,
  sindri_compensatingtemperature_therm1_celsius = 176,
  sindri_compensatingtemperature_therm2_celsius = 177,
  sindri_compensatingtemperature_therm3_celsius = 178,
  sindri_compensatingtemperature_therm4_celsius = 179,
  sindri_compensatingtemperature_therm5_celsius = 180,
  sindri_compensatingtemperature_therm6_celsius = 181,
  sindri_compensatingtemperature_therm7_celsius = 182,
  sindri_compensatingtemperature_therm8_celsius = 183,
  sindri_compensatingtemperature_therm9_celsius = 184,
  sindri_compensatingtemperature_therm10_celsius = 185,
  sindri_compensatingtemperature_therm11_celsius = 186,
  sindri_compensatingtemperature_therm12_celsius = 187,
  sindri_compensatingtemperature_therm13_celsius = 188,
  sindri_compensatingtemperature_therm14_celsius = 189,
  sindri_compensatingtemperature_therm15_celsius = 190,
  sindri_compensatingtemperature_therm16_celsius = 191,
  sindri_compensatingtemperature_therm17_celsius = 192,
  sindri_compensatingtemperature_therm18_celsius = 193,
  sindri_compensatingtemperature_therm19_celsius = 194,
  sindri_temperature_rtd0_celsius = 195,
  sindri_temperature_rtd1_celsius = 196,
  sindri_temperature_rtd2_celsius = 197,
  sindri_temperature_rtd3_celsius = 198,
  sindri_temperature_rtd0_ohm = 199,
  sindri_temperature_rtd1_ohm = 200,
  sindri_temperature_rtd2_ohm = 201,
  sindri_temperature_rtd3_ohm = 202,
  sindri_light_ambient_lux = 203,
  sindri_light_humidity_percentage = 204,
  sindri_acceleration_x_gforce = 205,
  sindri_acceleration_y_gforce = 206,
  sindri_acceleration_z_gforce = 207,
  sindri_ambientpressure_top_bar = 208,
  sindri_ambientpressure_bottom_bar = 209,
  sindri_transducerpressure_transducer0_bar = 210,
  sindri_transducerpressure_transducer1_bar = 211,
  sindri_transducerpressure_transducer2_bar = 212,
  sindri_transducerpressure_transducer3_bar = 213,
  sindri_transducerpressure_transducer0_max_bar = 214,
  sindri_transducerpressure_transducer1_max_bar = 215,
  sindri_transducerpressure_transducer2_max_bar = 216,
  sindri_transducerpressure_transducer3_max_bar = 217,
  sindri_transducerpressure_transducer0_min_bar = 218,
  sindri_transducerpressure_transducer1_min_bar = 219,
  sindri_transducerpressure_transducer2_min_bar = 220,
  sindri_transducerpressure_transducer3_min_bar = 221,
  sindri_transducervoltage_transducer0_volt = 222,
  sindri_transducervoltage_transducer1_volt = 223,
  sindri_transducervoltage_transducer2_volt = 224,
  sindri_transducervoltage_transducer3_volt = 225,
  sindri_transducervoltage_transducer0_max_volt = 226,
  sindri_transducervoltage_transducer1_max_volt = 227,
  sindri_transducervoltage_transducer2_max_volt = 228,
  sindri_transducervoltage_transducer3_max_volt = 229,
  sindri_transducervoltage_transducer0_min_volt = 230,
  sindri_transducervoltage_transducer1_min_volt = 231,
  sindri_transducervoltage_transducer2_min_volt = 232,
  sindri_transducervoltage_transducer3_min_volt = 233,
  edda_pressureboard_top_electronicsvoltage_adcref_volt = 234,
  edda_pressureboard_top_electronicsvoltage_adc5v_volt = 235,
  edda_pressureboard_bottom_electronicsvoltage_adcref_volt = 236,
  edda_pressureboard_bottom_electronicsvoltage_adc5v_volt = 237,
};
enum struct messages : uint16_t {
  CurrentTimePing = 0,
  CurrentTimePong = 1,
  SayHi = 2,
  WenHop = 3,
  WenOrbit = 4,
  SetDebugStatusLedsModeRequest = 5,
  SetDebugMessagesModeRequest = 6,
  PowerCAN_SetDebugMode = 7,
  PowerCAN_GetState = 8,
  PowerCAN_TransitionRequest = 9,
  PowerCAN_Hello = 10,
  PowerCAN_CurrentState = 11,
  PowerCAN_TransitionResponse = 12,
  PowerCAN_CheckResult = 13,
  TelemetryMeta_Frame = 14,
  TelemetryMeta_Time = 15,
  Telemetry__PowerInput__1 = 16,
  Telemetry__PowerInput__2 = 17,
  Telemetry__PowerInput__3 = 18,
  Telemetry__PowerInput__4 = 19,
  Telemetry__PowerInput__5 = 20,
  Telemetry__PowerInput__6 = 21,
  Telemetry__PowerInput__7 = 22,
  Telemetry__ElectronicsVoltage__1 = 23,
  Telemetry__ElectronicsVoltage__2 = 24,
  Telemetry__PowerOutput__1 = 25,
  Telemetry__PowerOutput__2 = 26,
  Telemetry__PowerOutput__3 = 27,
  Telemetry__ElectronicsTemperature__1 = 28,
  Telemetry__ElectronicsTemperature__2 = 29,
  Telemetry__LoopTime__1 = 30,
  Telemetry__LoopTime__2 = 31,
  Telemetry__LoopTime__3 = 32,
  Telemetry__LoopTime__4 = 33,
  Telemetry__LoopTime__5 = 34,
  Telemetry__LoopTime__6 = 35,
  Telemetry__LoopTime__7 = 36,
  Telemetry__LoopTime__8 = 37,
  Telemetry__LoopTime__9 = 38,
  Telemetry__LoopTime__a = 39,
  Telemetry__LoopTime__b = 40,
  Telemetry__LoopTime__c = 41,
  Telemetry__LoopTime__d = 42,
  Telemetry__LoopTime__e = 43,
  Telemetry__LoopTime__f = 44,
  Telemetry__LoopTime__10 = 45,
  Telemetry__LoopTime__11 = 46,
  Telemetry__LoopTime__12 = 47,
  Telemetry__LoopTime__13 = 48,
  Telemetry__LoopTime__14 = 49,
  Telemetry__LoopTime__15 = 50,
  Telemetry__LoopTime__16 = 51,
  Telemetry__LoopTime__17 = 52,
  Telemetry__LoopTime__18 = 53,
  Telemetry__ElectronicsTemperature__3 = 54,
  Telemetry__ElectronicsTemperature__4 = 55,
  Telemetry__ElectronicsTemperature__5 = 56,
  Telemetry__Temperature__1 = 57,
  Telemetry__Temperature__2 = 58,
  Telemetry__Temperature__3 = 59,
  Telemetry__Temperature__4 = 60,
  Telemetry__Temperature__5 = 61,
  Telemetry__Temperature__6 = 62,
  Telemetry__Temperature__7 = 63,
  Telemetry__CompensatingTemperature__1 = 64,
  Telemetry__CompensatingTemperature__2 = 65,
  Telemetry__CompensatingTemperature__3 = 66,
  Telemetry__Temperature__8 = 67,
  Telemetry__Temperature__9 = 68,
  Telemetry__Temperature__a = 69,
  Telemetry__Temperature__b = 70,
  Telemetry__Light__1 = 71,
  Telemetry__Light__2 = 72,
  Telemetry__Acceleration__1 = 73,
  Telemetry__AmbientPressure__1 = 74,
  Telemetry__AmbientPressure__2 = 75,
  Telemetry__TransducerPressure__1 = 76,
  Telemetry__TransducerPressure__2 = 77,
  Telemetry__TransducerPressure__3 = 78,
  Telemetry__TransducerPressure__4 = 79,
  Telemetry__TransducerPressure__5 = 80,
  Telemetry__TransducerVoltage__1 = 81,
  Telemetry__TransducerVoltage__2 = 82,
  Telemetry__TransducerVoltage__3 = 83,
  Telemetry__TransducerVoltage__4 = 84,
  Telemetry__TransducerVoltage__5 = 85,
  Telemetry__ElectronicsVoltage__3 = 86,
  Telemetry__ElectronicsVoltage__4 = 87,
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
  Ground_Controller = 16,
};
enum struct Nodes : uint8_t {
  EddaController = 1,
  EddaTelemetry = 2,
  EddaPressureTop = 3,
  EddaPressureBottom = 4,
  GroundController = 16,
  FlightController = 0,
};
enum struct DebugStatusLedsMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct DebugMessagesMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct PowerCAN_DebugMode : uint8_t {
  Enabled = 0,
  Disabled = 1,
};
enum struct PowerCANChannel : uint8_t {
  Channel0_false = 0,
  Channel1_Ignition = 1,
  Channel2_VentSolenoid = 2,
  Channel3_MainValveSolenoid = 3,
  Channel4_false = 4,
  Channel5_false = 5,
  Channel6_false = 6,
  Channel7_false = 7,
  Unknown = 8,
};
enum struct PowerCAN_TransitionRequest : uint8_t {
  Arm = 0,
  Disarm = 1,
  Fire = 2,
  StopFire = 3,
};
enum struct PowerCAN_SystemState : uint8_t {
  Idle = 0,
  Arming = 1,
  Armed = 2,
  Firing = 3,
};
enum struct PowerCAN_GateState : uint8_t {
  Grounded = 0,
  ResistanceMeasurement = 1,
  High = 2,
};
enum struct PowerCAN_TransitionResponse : uint8_t {
  Success = 0,
  Failure = 1,
};
enum struct PowerCAN_CheckResult : uint8_t {
  SomeFailed = 0,
  AllFailed = 1,
  AllPassed = 2,
  NotYetDone = 3,
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
  uint8_t id = 15;
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
  uint8_t id = 15;
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
  uint8_t id = 15;
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
  uint8_t id = 16;
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
  uint8_t id = 17;
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
  uint8_t id = 18;
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
  uint8_t id = 19;
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
  uint8_t id = 19;
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
  uint8_t id = 19;
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
  uint8_t id = 19;
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
  uint8_t id = 20;
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
  uint8_t id = 21;
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
  uint8_t id = 22;
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
  uint8_t id = 23;
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
  uint8_t id = 24;
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
  uint8_t id = 25;
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
  uint8_t id = 26;
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
  uint8_t id = 27;
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
  uint8_t id = 28;
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
  uint8_t id = 28;
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
  uint8_t id = 28;
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
  uint8_t id = 28;
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
  uint8_t id = 29;
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
  uint8_t id = 29;
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
  uint8_t id = 29;
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
  uint8_t id = 29;
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
  uint8_t id = 30;
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
  uint8_t id = 31;
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
  uint8_t id = 32;
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
  uint8_t id = 33;
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
  uint8_t id = 34;
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
  uint8_t id = 35;
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

class PowerCAN_Hello_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  enum PowerCAN_DebugMode debug_mode;
  static_assert((sizeof(debug_mode) == 1), "invalid size");
  enum PowerCANChannel powercan_channel;
  static_assert((sizeof(powercan_channel) == 1), "invalid size");
  uint8_t size = 2;
  enum EDDA::messages message = EDDA::messages::PowerCAN_Hello;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 36;
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

class PowerCAN_CurrentState_from_Edda_Controller_to_Ground_Controller
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
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 37;
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

class PowerCAN_TransitionResponse_from_Edda_Controller_to_Ground_Controller
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
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 38;
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

class PowerCAN_CheckResult_from_Edda_Controller_to_Ground_Controller
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
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 39;
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

class TelemetryMeta_Frame_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Frame;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 40;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMeta_Frame_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Frame;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 41;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMeta_Frame_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Frame;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 42;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMeta_Frame_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Frame;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 43;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMeta_Time_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint16_t truncated_time_since_boot_us;
  static_assert((sizeof(truncated_time_since_boot_us) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Time;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 44;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  void set_truncated_time_since_boot_us(uint16_t value) {
    truncated_time_since_boot_us = value;
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  uint16_t get_truncated_time_since_boot_us() {
    return truncated_time_since_boot_us;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
    memcpy(buf + *index, &truncated_time_since_boot_us,
           sizeof(truncated_time_since_boot_us));
    *index += sizeof(truncated_time_since_boot_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
    memcpy(&truncated_time_since_boot_us, buf + index,
           sizeof(truncated_time_since_boot_us));
    index += sizeof(truncated_time_since_boot_us);
  }
};

class TelemetryMeta_Time_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint16_t truncated_time_since_boot_us;
  static_assert((sizeof(truncated_time_since_boot_us) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Time;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 45;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  void set_truncated_time_since_boot_us(uint16_t value) {
    truncated_time_since_boot_us = value;
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  uint16_t get_truncated_time_since_boot_us() {
    return truncated_time_since_boot_us;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
    memcpy(buf + *index, &truncated_time_since_boot_us,
           sizeof(truncated_time_since_boot_us));
    *index += sizeof(truncated_time_since_boot_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
    memcpy(&truncated_time_since_boot_us, buf + index,
           sizeof(truncated_time_since_boot_us));
    index += sizeof(truncated_time_since_boot_us);
  }
};

class TelemetryMeta_Time_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint16_t truncated_time_since_boot_us;
  static_assert((sizeof(truncated_time_since_boot_us) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Time;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 46;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  void set_truncated_time_since_boot_us(uint16_t value) {
    truncated_time_since_boot_us = value;
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  uint16_t get_truncated_time_since_boot_us() {
    return truncated_time_since_boot_us;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
    memcpy(buf + *index, &truncated_time_since_boot_us,
           sizeof(truncated_time_since_boot_us));
    *index += sizeof(truncated_time_since_boot_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
    memcpy(&truncated_time_since_boot_us, buf + index,
           sizeof(truncated_time_since_boot_us));
    index += sizeof(truncated_time_since_boot_us);
  }
};

class TelemetryMeta_Time_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint16_t truncated_time_since_boot_us;
  static_assert((sizeof(truncated_time_since_boot_us) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMeta_Time;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 47;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  void set_truncated_time_since_boot_us(uint16_t value) {
    truncated_time_since_boot_us = value;
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  uint16_t get_truncated_time_since_boot_us() {
    return truncated_time_since_boot_us;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
    memcpy(buf + *index, &truncated_time_since_boot_us,
           sizeof(truncated_time_since_boot_us));
    *index += sizeof(truncated_time_since_boot_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
    memcpy(&truncated_time_since_boot_us, buf + index,
           sizeof(truncated_time_since_boot_us));
    index += sizeof(truncated_time_since_boot_us);
  }
};

class Telemetry__PowerInput__1_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_powerinput_voltage_volt;
  static_assert((sizeof(edda_telemetryboard_powerinput_voltage_volt) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_powerinput_current_ampere;
  static_assert((sizeof(edda_telemetryboard_powerinput_current_ampere) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_powerinput_power_watt;
  static_assert((sizeof(edda_telemetryboard_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_telemetryboard_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_telemetryboard_powerinput_voltage_volt);
  }
  void set_edda_telemetryboard_powerinput_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_telemetryboard_powerinput_current_ampere);
  }
  void set_edda_telemetryboard_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540,
                        &edda_telemetryboard_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_powerinput_voltage_volt, 0, 36,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_powerinput_current_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_powerinput_power_watt, -540, 540,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_powerinput_voltage_volt,
           sizeof(edda_telemetryboard_powerinput_voltage_volt));
    *index += sizeof(edda_telemetryboard_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_telemetryboard_powerinput_current_ampere,
           sizeof(edda_telemetryboard_powerinput_current_ampere));
    *index += sizeof(edda_telemetryboard_powerinput_current_ampere);
    memcpy(buf + *index, &edda_telemetryboard_powerinput_power_watt,
           sizeof(edda_telemetryboard_powerinput_power_watt));
    *index += sizeof(edda_telemetryboard_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_powerinput_voltage_volt, buf + index,
           sizeof(edda_telemetryboard_powerinput_voltage_volt));
    index += sizeof(edda_telemetryboard_powerinput_voltage_volt);
    memcpy(&edda_telemetryboard_powerinput_current_ampere, buf + index,
           sizeof(edda_telemetryboard_powerinput_current_ampere));
    index += sizeof(edda_telemetryboard_powerinput_current_ampere);
    memcpy(&edda_telemetryboard_powerinput_power_watt, buf + index,
           sizeof(edda_telemetryboard_powerinput_power_watt));
    index += sizeof(edda_telemetryboard_powerinput_power_watt);
  }
};

class Telemetry__PowerInput__2_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_powerinput_voltage_volt;
  static_assert((sizeof(edda_controllerboard_powerinput_voltage_volt) == 2),
                "invalid size");
  uint16_t edda_controllerboard_powerinput_current_ampere;
  static_assert((sizeof(edda_controllerboard_powerinput_current_ampere) == 2),
                "invalid size");
  uint16_t edda_controllerboard_powerinput_power_watt;
  static_assert((sizeof(edda_controllerboard_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controllerboard_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_controllerboard_powerinput_voltage_volt);
  }
  void
  set_edda_controllerboard_powerinput_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_controllerboard_powerinput_current_ampere);
  }
  void set_edda_controllerboard_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540,
                        &edda_controllerboard_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_powerinput_voltage_volt, 0, 36,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_powerinput_current_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_powerinput_power_watt, -540, 540,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_powerinput_voltage_volt,
           sizeof(edda_controllerboard_powerinput_voltage_volt));
    *index += sizeof(edda_controllerboard_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_controllerboard_powerinput_current_ampere,
           sizeof(edda_controllerboard_powerinput_current_ampere));
    *index += sizeof(edda_controllerboard_powerinput_current_ampere);
    memcpy(buf + *index, &edda_controllerboard_powerinput_power_watt,
           sizeof(edda_controllerboard_powerinput_power_watt));
    *index += sizeof(edda_controllerboard_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_powerinput_voltage_volt, buf + index,
           sizeof(edda_controllerboard_powerinput_voltage_volt));
    index += sizeof(edda_controllerboard_powerinput_voltage_volt);
    memcpy(&edda_controllerboard_powerinput_current_ampere, buf + index,
           sizeof(edda_controllerboard_powerinput_current_ampere));
    index += sizeof(edda_controllerboard_powerinput_current_ampere);
    memcpy(&edda_controllerboard_powerinput_power_watt, buf + index,
           sizeof(edda_controllerboard_powerinput_power_watt));
    index += sizeof(edda_controllerboard_powerinput_power_watt);
  }
};

class Telemetry__PowerInput__3_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_power1_powerinput_voltage_volt;
  static_assert((sizeof(edda_power1_powerinput_voltage_volt) == 2),
                "invalid size");
  uint16_t edda_power1_powerinput_current_ampere;
  static_assert((sizeof(edda_power1_powerinput_current_ampere) == 2),
                "invalid size");
  uint16_t edda_power1_powerinput_power_watt;
  static_assert((sizeof(edda_power1_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_power1_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &edda_power1_powerinput_voltage_volt);
  }
  void set_edda_power1_powerinput_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &edda_power1_powerinput_current_ampere);
  }
  void set_edda_power1_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &edda_power1_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_power1_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power1_powerinput_voltage_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power1_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power1_powerinput_current_ampere, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power1_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power1_powerinput_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_power1_powerinput_voltage_volt,
           sizeof(edda_power1_powerinput_voltage_volt));
    *index += sizeof(edda_power1_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_power1_powerinput_current_ampere,
           sizeof(edda_power1_powerinput_current_ampere));
    *index += sizeof(edda_power1_powerinput_current_ampere);
    memcpy(buf + *index, &edda_power1_powerinput_power_watt,
           sizeof(edda_power1_powerinput_power_watt));
    *index += sizeof(edda_power1_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_power1_powerinput_voltage_volt, buf + index,
           sizeof(edda_power1_powerinput_voltage_volt));
    index += sizeof(edda_power1_powerinput_voltage_volt);
    memcpy(&edda_power1_powerinput_current_ampere, buf + index,
           sizeof(edda_power1_powerinput_current_ampere));
    index += sizeof(edda_power1_powerinput_current_ampere);
    memcpy(&edda_power1_powerinput_power_watt, buf + index,
           sizeof(edda_power1_powerinput_power_watt));
    index += sizeof(edda_power1_powerinput_power_watt);
  }
};

class Telemetry__PowerInput__4_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_power2_powerinput_voltage_volt;
  static_assert((sizeof(edda_power2_powerinput_voltage_volt) == 2),
                "invalid size");
  uint16_t edda_power2_powerinput_current_ampere;
  static_assert((sizeof(edda_power2_powerinput_current_ampere) == 2),
                "invalid size");
  uint16_t edda_power2_powerinput_power_watt;
  static_assert((sizeof(edda_power2_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 51;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_power2_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &edda_power2_powerinput_voltage_volt);
  }
  void set_edda_power2_powerinput_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &edda_power2_powerinput_current_ampere);
  }
  void set_edda_power2_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &edda_power2_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_power2_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power2_powerinput_voltage_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power2_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power2_powerinput_current_ampere, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power2_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power2_powerinput_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_power2_powerinput_voltage_volt,
           sizeof(edda_power2_powerinput_voltage_volt));
    *index += sizeof(edda_power2_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_power2_powerinput_current_ampere,
           sizeof(edda_power2_powerinput_current_ampere));
    *index += sizeof(edda_power2_powerinput_current_ampere);
    memcpy(buf + *index, &edda_power2_powerinput_power_watt,
           sizeof(edda_power2_powerinput_power_watt));
    *index += sizeof(edda_power2_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_power2_powerinput_voltage_volt, buf + index,
           sizeof(edda_power2_powerinput_voltage_volt));
    index += sizeof(edda_power2_powerinput_voltage_volt);
    memcpy(&edda_power2_powerinput_current_ampere, buf + index,
           sizeof(edda_power2_powerinput_current_ampere));
    index += sizeof(edda_power2_powerinput_current_ampere);
    memcpy(&edda_power2_powerinput_power_watt, buf + index,
           sizeof(edda_power2_powerinput_power_watt));
    index += sizeof(edda_power2_powerinput_power_watt);
  }
};

class Telemetry__PowerInput__5_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_power3_powerinput_voltage_volt;
  static_assert((sizeof(edda_power3_powerinput_voltage_volt) == 2),
                "invalid size");
  uint16_t edda_power3_powerinput_current_ampere;
  static_assert((sizeof(edda_power3_powerinput_current_ampere) == 2),
                "invalid size");
  uint16_t edda_power3_powerinput_power_watt;
  static_assert((sizeof(edda_power3_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 52;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_power3_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &edda_power3_powerinput_voltage_volt);
  }
  void set_edda_power3_powerinput_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &edda_power3_powerinput_current_ampere);
  }
  void set_edda_power3_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &edda_power3_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_power3_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power3_powerinput_voltage_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power3_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power3_powerinput_current_ampere, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power3_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power3_powerinput_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_power3_powerinput_voltage_volt,
           sizeof(edda_power3_powerinput_voltage_volt));
    *index += sizeof(edda_power3_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_power3_powerinput_current_ampere,
           sizeof(edda_power3_powerinput_current_ampere));
    *index += sizeof(edda_power3_powerinput_current_ampere);
    memcpy(buf + *index, &edda_power3_powerinput_power_watt,
           sizeof(edda_power3_powerinput_power_watt));
    *index += sizeof(edda_power3_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_power3_powerinput_voltage_volt, buf + index,
           sizeof(edda_power3_powerinput_voltage_volt));
    index += sizeof(edda_power3_powerinput_voltage_volt);
    memcpy(&edda_power3_powerinput_current_ampere, buf + index,
           sizeof(edda_power3_powerinput_current_ampere));
    index += sizeof(edda_power3_powerinput_current_ampere);
    memcpy(&edda_power3_powerinput_power_watt, buf + index,
           sizeof(edda_power3_powerinput_power_watt));
    index += sizeof(edda_power3_powerinput_power_watt);
  }
};

class Telemetry__PowerInput__6_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_powerinput_voltage_volt;
  static_assert((sizeof(edda_pressureboard_top_powerinput_voltage_volt) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_powerinput_current_ampere;
  static_assert((sizeof(edda_pressureboard_top_powerinput_current_ampere) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_powerinput_power_watt;
  static_assert((sizeof(edda_pressureboard_top_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 53;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_top_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_pressureboard_top_powerinput_voltage_volt);
  }
  void
  set_edda_pressureboard_top_powerinput_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_pressureboard_top_powerinput_current_ampere);
  }
  void set_edda_pressureboard_top_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540,
                        &edda_pressureboard_top_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_powerinput_voltage_volt, 0, 36,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_powerinput_current_ampere, -15,
                        15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_powerinput_power_watt, -540, 540,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_powerinput_voltage_volt,
           sizeof(edda_pressureboard_top_powerinput_voltage_volt));
    *index += sizeof(edda_pressureboard_top_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_pressureboard_top_powerinput_current_ampere,
           sizeof(edda_pressureboard_top_powerinput_current_ampere));
    *index += sizeof(edda_pressureboard_top_powerinput_current_ampere);
    memcpy(buf + *index, &edda_pressureboard_top_powerinput_power_watt,
           sizeof(edda_pressureboard_top_powerinput_power_watt));
    *index += sizeof(edda_pressureboard_top_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_powerinput_voltage_volt, buf + index,
           sizeof(edda_pressureboard_top_powerinput_voltage_volt));
    index += sizeof(edda_pressureboard_top_powerinput_voltage_volt);
    memcpy(&edda_pressureboard_top_powerinput_current_ampere, buf + index,
           sizeof(edda_pressureboard_top_powerinput_current_ampere));
    index += sizeof(edda_pressureboard_top_powerinput_current_ampere);
    memcpy(&edda_pressureboard_top_powerinput_power_watt, buf + index,
           sizeof(edda_pressureboard_top_powerinput_power_watt));
    index += sizeof(edda_pressureboard_top_powerinput_power_watt);
  }
};

class Telemetry__PowerInput__7_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_powerinput_voltage_volt;
  static_assert((sizeof(edda_pressureboard_bottom_powerinput_voltage_volt) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_powerinput_current_ampere;
  static_assert((sizeof(edda_pressureboard_bottom_powerinput_current_ampere) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_powerinput_power_watt;
  static_assert((sizeof(edda_pressureboard_bottom_powerinput_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerInput__7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 54;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_bottom_powerinput_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_pressureboard_bottom_powerinput_voltage_volt);
  }
  void set_edda_pressureboard_bottom_powerinput_current_ampere(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_pressureboard_bottom_powerinput_current_ampere);
  }
  void
  set_edda_pressureboard_bottom_powerinput_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -540, 540,
                        &edda_pressureboard_bottom_powerinput_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_powerinput_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_powerinput_voltage_volt, 0,
                        36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_powerinput_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_powerinput_current_ampere,
                        -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_powerinput_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_powerinput_power_watt, -540,
                        540, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_bottom_powerinput_voltage_volt,
           sizeof(edda_pressureboard_bottom_powerinput_voltage_volt));
    *index += sizeof(edda_pressureboard_bottom_powerinput_voltage_volt);
    memcpy(buf + *index, &edda_pressureboard_bottom_powerinput_current_ampere,
           sizeof(edda_pressureboard_bottom_powerinput_current_ampere));
    *index += sizeof(edda_pressureboard_bottom_powerinput_current_ampere);
    memcpy(buf + *index, &edda_pressureboard_bottom_powerinput_power_watt,
           sizeof(edda_pressureboard_bottom_powerinput_power_watt));
    *index += sizeof(edda_pressureboard_bottom_powerinput_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_powerinput_voltage_volt, buf + index,
           sizeof(edda_pressureboard_bottom_powerinput_voltage_volt));
    index += sizeof(edda_pressureboard_bottom_powerinput_voltage_volt);
    memcpy(&edda_pressureboard_bottom_powerinput_current_ampere, buf + index,
           sizeof(edda_pressureboard_bottom_powerinput_current_ampere));
    index += sizeof(edda_pressureboard_bottom_powerinput_current_ampere);
    memcpy(&edda_pressureboard_bottom_powerinput_power_watt, buf + index,
           sizeof(edda_pressureboard_bottom_powerinput_power_watt));
    index += sizeof(edda_pressureboard_bottom_powerinput_power_watt);
  }
};

class Telemetry__ElectronicsVoltage__1_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_electronicsvoltage_24v_volt;
  static_assert((sizeof(sindri_electronicsvoltage_24v_volt) == 2),
                "invalid size");
  uint16_t sindri_electronicsvoltage_12v_volt;
  static_assert((sizeof(sindri_electronicsvoltage_12v_volt) == 2),
                "invalid size");
  uint16_t sindri_electronicsvoltage_7v4_volt;
  static_assert((sizeof(sindri_electronicsvoltage_7v4_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsVoltage__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 55;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_electronicsvoltage_24v_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &sindri_electronicsvoltage_24v_volt);
  }
  void set_sindri_electronicsvoltage_12v_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &sindri_electronicsvoltage_12v_volt);
  }
  void set_sindri_electronicsvoltage_7v4_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &sindri_electronicsvoltage_7v4_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_electronicsvoltage_24v_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_electronicsvoltage_24v_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_electronicsvoltage_12v_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_electronicsvoltage_12v_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_electronicsvoltage_7v4_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_electronicsvoltage_7v4_volt, -30, 30, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_electronicsvoltage_24v_volt,
           sizeof(sindri_electronicsvoltage_24v_volt));
    *index += sizeof(sindri_electronicsvoltage_24v_volt);
    memcpy(buf + *index, &sindri_electronicsvoltage_12v_volt,
           sizeof(sindri_electronicsvoltage_12v_volt));
    *index += sizeof(sindri_electronicsvoltage_12v_volt);
    memcpy(buf + *index, &sindri_electronicsvoltage_7v4_volt,
           sizeof(sindri_electronicsvoltage_7v4_volt));
    *index += sizeof(sindri_electronicsvoltage_7v4_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_electronicsvoltage_24v_volt, buf + index,
           sizeof(sindri_electronicsvoltage_24v_volt));
    index += sizeof(sindri_electronicsvoltage_24v_volt);
    memcpy(&sindri_electronicsvoltage_12v_volt, buf + index,
           sizeof(sindri_electronicsvoltage_12v_volt));
    index += sizeof(sindri_electronicsvoltage_12v_volt);
    memcpy(&sindri_electronicsvoltage_7v4_volt, buf + index,
           sizeof(sindri_electronicsvoltage_7v4_volt));
    index += sizeof(sindri_electronicsvoltage_7v4_volt);
  }
};

class Telemetry__ElectronicsVoltage__2_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_power1_electronicsvoltage_3v3_volt;
  static_assert((sizeof(edda_power1_electronicsvoltage_3v3_volt) == 2),
                "invalid size");
  uint16_t edda_power2_electronicsvoltage_3v3_volt;
  static_assert((sizeof(edda_power2_electronicsvoltage_3v3_volt) == 2),
                "invalid size");
  uint16_t edda_power3_electronicsvoltage_3v3_volt;
  static_assert((sizeof(edda_power3_electronicsvoltage_3v3_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsVoltage__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 56;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_power1_electronicsvoltage_3v3_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &edda_power1_electronicsvoltage_3v3_volt);
  }
  void set_edda_power2_electronicsvoltage_3v3_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &edda_power2_electronicsvoltage_3v3_volt);
  }
  void set_edda_power3_electronicsvoltage_3v3_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &edda_power3_electronicsvoltage_3v3_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_power1_electronicsvoltage_3v3_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power1_electronicsvoltage_3v3_volt, 0, 5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power2_electronicsvoltage_3v3_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power2_electronicsvoltage_3v3_volt, 0, 5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power3_electronicsvoltage_3v3_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power3_electronicsvoltage_3v3_volt, 0, 5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_power1_electronicsvoltage_3v3_volt,
           sizeof(edda_power1_electronicsvoltage_3v3_volt));
    *index += sizeof(edda_power1_electronicsvoltage_3v3_volt);
    memcpy(buf + *index, &edda_power2_electronicsvoltage_3v3_volt,
           sizeof(edda_power2_electronicsvoltage_3v3_volt));
    *index += sizeof(edda_power2_electronicsvoltage_3v3_volt);
    memcpy(buf + *index, &edda_power3_electronicsvoltage_3v3_volt,
           sizeof(edda_power3_electronicsvoltage_3v3_volt));
    *index += sizeof(edda_power3_electronicsvoltage_3v3_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_power1_electronicsvoltage_3v3_volt, buf + index,
           sizeof(edda_power1_electronicsvoltage_3v3_volt));
    index += sizeof(edda_power1_electronicsvoltage_3v3_volt);
    memcpy(&edda_power2_electronicsvoltage_3v3_volt, buf + index,
           sizeof(edda_power2_electronicsvoltage_3v3_volt));
    index += sizeof(edda_power2_electronicsvoltage_3v3_volt);
    memcpy(&edda_power3_electronicsvoltage_3v3_volt, buf + index,
           sizeof(edda_power3_electronicsvoltage_3v3_volt));
    index += sizeof(edda_power3_electronicsvoltage_3v3_volt);
  }
};

class Telemetry__PowerOutput__1_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_poweroutput_ignition_voltage_volt;
  static_assert((sizeof(sindri_poweroutput_ignition_voltage_volt) == 2),
                "invalid size");
  uint16_t sindri_poweroutput_ignition_current_ampere;
  static_assert((sizeof(sindri_poweroutput_ignition_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_poweroutput_ignition_power_watt;
  static_assert((sizeof(sindri_poweroutput_ignition_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerOutput__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 57;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_poweroutput_ignition_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30,
                        &sindri_poweroutput_ignition_voltage_volt);
  }
  void set_sindri_poweroutput_ignition_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30,
                        &sindri_poweroutput_ignition_current_ampere);
  }
  void set_sindri_poweroutput_ignition_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_poweroutput_ignition_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_poweroutput_ignition_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_ignition_voltage_volt, -30, 30,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_poweroutput_ignition_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_ignition_current_ampere, 0, 30,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_poweroutput_ignition_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_ignition_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_poweroutput_ignition_voltage_volt,
           sizeof(sindri_poweroutput_ignition_voltage_volt));
    *index += sizeof(sindri_poweroutput_ignition_voltage_volt);
    memcpy(buf + *index, &sindri_poweroutput_ignition_current_ampere,
           sizeof(sindri_poweroutput_ignition_current_ampere));
    *index += sizeof(sindri_poweroutput_ignition_current_ampere);
    memcpy(buf + *index, &sindri_poweroutput_ignition_power_watt,
           sizeof(sindri_poweroutput_ignition_power_watt));
    *index += sizeof(sindri_poweroutput_ignition_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_poweroutput_ignition_voltage_volt, buf + index,
           sizeof(sindri_poweroutput_ignition_voltage_volt));
    index += sizeof(sindri_poweroutput_ignition_voltage_volt);
    memcpy(&sindri_poweroutput_ignition_current_ampere, buf + index,
           sizeof(sindri_poweroutput_ignition_current_ampere));
    index += sizeof(sindri_poweroutput_ignition_current_ampere);
    memcpy(&sindri_poweroutput_ignition_power_watt, buf + index,
           sizeof(sindri_poweroutput_ignition_power_watt));
    index += sizeof(sindri_poweroutput_ignition_power_watt);
  }
};

class Telemetry__PowerOutput__2_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_poweroutput_ventsolenoid_voltage_volt;
  static_assert((sizeof(sindri_poweroutput_ventsolenoid_voltage_volt) == 2),
                "invalid size");
  uint16_t sindri_poweroutput_ventsolenoid_current_ampere;
  static_assert((sizeof(sindri_poweroutput_ventsolenoid_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_poweroutput_ventsolenoid_power_watt;
  static_assert((sizeof(sindri_poweroutput_ventsolenoid_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerOutput__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 58;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_poweroutput_ventsolenoid_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30,
                        &sindri_poweroutput_ventsolenoid_voltage_volt);
  }
  void
  set_sindri_poweroutput_ventsolenoid_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30,
                        &sindri_poweroutput_ventsolenoid_current_ampere);
  }
  void set_sindri_poweroutput_ventsolenoid_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_poweroutput_ventsolenoid_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_poweroutput_ventsolenoid_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_ventsolenoid_voltage_volt, -30, 30,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_poweroutput_ventsolenoid_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_ventsolenoid_current_ampere, 0, 30,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_poweroutput_ventsolenoid_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_ventsolenoid_power_watt, 0, 1000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_poweroutput_ventsolenoid_voltage_volt,
           sizeof(sindri_poweroutput_ventsolenoid_voltage_volt));
    *index += sizeof(sindri_poweroutput_ventsolenoid_voltage_volt);
    memcpy(buf + *index, &sindri_poweroutput_ventsolenoid_current_ampere,
           sizeof(sindri_poweroutput_ventsolenoid_current_ampere));
    *index += sizeof(sindri_poweroutput_ventsolenoid_current_ampere);
    memcpy(buf + *index, &sindri_poweroutput_ventsolenoid_power_watt,
           sizeof(sindri_poweroutput_ventsolenoid_power_watt));
    *index += sizeof(sindri_poweroutput_ventsolenoid_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_poweroutput_ventsolenoid_voltage_volt, buf + index,
           sizeof(sindri_poweroutput_ventsolenoid_voltage_volt));
    index += sizeof(sindri_poweroutput_ventsolenoid_voltage_volt);
    memcpy(&sindri_poweroutput_ventsolenoid_current_ampere, buf + index,
           sizeof(sindri_poweroutput_ventsolenoid_current_ampere));
    index += sizeof(sindri_poweroutput_ventsolenoid_current_ampere);
    memcpy(&sindri_poweroutput_ventsolenoid_power_watt, buf + index,
           sizeof(sindri_poweroutput_ventsolenoid_power_watt));
    index += sizeof(sindri_poweroutput_ventsolenoid_power_watt);
  }
};

class Telemetry__PowerOutput__3_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_poweroutput_mainvalvesolenoid_voltage_volt;
  static_assert((sizeof(sindri_poweroutput_mainvalvesolenoid_voltage_volt) ==
                 2),
                "invalid size");
  uint16_t sindri_poweroutput_mainvalvesolenoid_current_ampere;
  static_assert((sizeof(sindri_poweroutput_mainvalvesolenoid_current_ampere) ==
                 2),
                "invalid size");
  uint16_t sindri_poweroutput_mainvalvesolenoid_power_watt;
  static_assert((sizeof(sindri_poweroutput_mainvalvesolenoid_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__PowerOutput__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 59;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_sindri_poweroutput_mainvalvesolenoid_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30,
                        &sindri_poweroutput_mainvalvesolenoid_voltage_volt);
  }
  void set_sindri_poweroutput_mainvalvesolenoid_current_ampere(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30,
                        &sindri_poweroutput_mainvalvesolenoid_current_ampere);
  }
  void
  set_sindri_poweroutput_mainvalvesolenoid_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_poweroutput_mainvalvesolenoid_power_watt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_poweroutput_mainvalvesolenoid_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_mainvalvesolenoid_voltage_volt, -30,
                        30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_poweroutput_mainvalvesolenoid_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_mainvalvesolenoid_current_ampere, 0,
                        30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_poweroutput_mainvalvesolenoid_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_poweroutput_mainvalvesolenoid_power_watt, 0,
                        1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_poweroutput_mainvalvesolenoid_voltage_volt,
           sizeof(sindri_poweroutput_mainvalvesolenoid_voltage_volt));
    *index += sizeof(sindri_poweroutput_mainvalvesolenoid_voltage_volt);
    memcpy(buf + *index, &sindri_poweroutput_mainvalvesolenoid_current_ampere,
           sizeof(sindri_poweroutput_mainvalvesolenoid_current_ampere));
    *index += sizeof(sindri_poweroutput_mainvalvesolenoid_current_ampere);
    memcpy(buf + *index, &sindri_poweroutput_mainvalvesolenoid_power_watt,
           sizeof(sindri_poweroutput_mainvalvesolenoid_power_watt));
    *index += sizeof(sindri_poweroutput_mainvalvesolenoid_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_poweroutput_mainvalvesolenoid_voltage_volt, buf + index,
           sizeof(sindri_poweroutput_mainvalvesolenoid_voltage_volt));
    index += sizeof(sindri_poweroutput_mainvalvesolenoid_voltage_volt);
    memcpy(&sindri_poweroutput_mainvalvesolenoid_current_ampere, buf + index,
           sizeof(sindri_poweroutput_mainvalvesolenoid_current_ampere));
    index += sizeof(sindri_poweroutput_mainvalvesolenoid_current_ampere);
    memcpy(&sindri_poweroutput_mainvalvesolenoid_power_watt, buf + index,
           sizeof(sindri_poweroutput_mainvalvesolenoid_power_watt));
    index += sizeof(sindri_poweroutput_mainvalvesolenoid_power_watt);
  }
};

class
    Telemetry__ElectronicsTemperature__1_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t edda_power1_electronicstemperature_adc_celsius;
  static_assert((sizeof(edda_power1_electronicstemperature_adc_celsius) == 1),
                "invalid size");
  uint8_t edda_power1_electronicstemperature_pcb_celsius;
  static_assert((sizeof(edda_power1_electronicstemperature_pcb_celsius) == 1),
                "invalid size");
  uint8_t edda_power2_electronicstemperature_adc_celsius;
  static_assert((sizeof(edda_power2_electronicstemperature_adc_celsius) == 1),
                "invalid size");
  uint8_t edda_power2_electronicstemperature_pcb_celsius;
  static_assert((sizeof(edda_power2_electronicstemperature_pcb_celsius) == 1),
                "invalid size");
  uint8_t edda_power3_electronicstemperature_adc_celsius;
  static_assert((sizeof(edda_power3_electronicstemperature_adc_celsius) == 1),
                "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsTemperature__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 60;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_power1_electronicstemperature_adc_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_power1_electronicstemperature_adc_celsius);
  }
  void
  set_edda_power1_electronicstemperature_pcb_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_power1_electronicstemperature_pcb_celsius);
  }
  void
  set_edda_power2_electronicstemperature_adc_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_power2_electronicstemperature_adc_celsius);
  }
  void
  set_edda_power2_electronicstemperature_pcb_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_power2_electronicstemperature_pcb_celsius);
  }
  void
  set_edda_power3_electronicstemperature_adc_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_power3_electronicstemperature_adc_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_power1_electronicstemperature_adc_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power1_electronicstemperature_adc_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power1_electronicstemperature_pcb_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power1_electronicstemperature_pcb_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power2_electronicstemperature_adc_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power2_electronicstemperature_adc_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power2_electronicstemperature_pcb_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power2_electronicstemperature_pcb_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_power3_electronicstemperature_adc_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power3_electronicstemperature_adc_celsius, -20,
                        106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_power1_electronicstemperature_adc_celsius,
           sizeof(edda_power1_electronicstemperature_adc_celsius));
    *index += sizeof(edda_power1_electronicstemperature_adc_celsius);
    memcpy(buf + *index, &edda_power1_electronicstemperature_pcb_celsius,
           sizeof(edda_power1_electronicstemperature_pcb_celsius));
    *index += sizeof(edda_power1_electronicstemperature_pcb_celsius);
    memcpy(buf + *index, &edda_power2_electronicstemperature_adc_celsius,
           sizeof(edda_power2_electronicstemperature_adc_celsius));
    *index += sizeof(edda_power2_electronicstemperature_adc_celsius);
    memcpy(buf + *index, &edda_power2_electronicstemperature_pcb_celsius,
           sizeof(edda_power2_electronicstemperature_pcb_celsius));
    *index += sizeof(edda_power2_electronicstemperature_pcb_celsius);
    memcpy(buf + *index, &edda_power3_electronicstemperature_adc_celsius,
           sizeof(edda_power3_electronicstemperature_adc_celsius));
    *index += sizeof(edda_power3_electronicstemperature_adc_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_power1_electronicstemperature_adc_celsius, buf + index,
           sizeof(edda_power1_electronicstemperature_adc_celsius));
    index += sizeof(edda_power1_electronicstemperature_adc_celsius);
    memcpy(&edda_power1_electronicstemperature_pcb_celsius, buf + index,
           sizeof(edda_power1_electronicstemperature_pcb_celsius));
    index += sizeof(edda_power1_electronicstemperature_pcb_celsius);
    memcpy(&edda_power2_electronicstemperature_adc_celsius, buf + index,
           sizeof(edda_power2_electronicstemperature_adc_celsius));
    index += sizeof(edda_power2_electronicstemperature_adc_celsius);
    memcpy(&edda_power2_electronicstemperature_pcb_celsius, buf + index,
           sizeof(edda_power2_electronicstemperature_pcb_celsius));
    index += sizeof(edda_power2_electronicstemperature_pcb_celsius);
    memcpy(&edda_power3_electronicstemperature_adc_celsius, buf + index,
           sizeof(edda_power3_electronicstemperature_adc_celsius));
    index += sizeof(edda_power3_electronicstemperature_adc_celsius);
  }
};

class
    Telemetry__ElectronicsTemperature__2_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t edda_power3_electronicstemperature_pcb_celsius;
  static_assert((sizeof(edda_power3_electronicstemperature_pcb_celsius) == 1),
                "invalid size");
  uint8_t edda_controllerboard_electronicstemperature_microcontroller_celsius;
  static_assert(
      (sizeof(
           edda_controllerboard_electronicstemperature_microcontroller_celsius) ==
       1),
      "invalid size");
  uint8_t edda_controllerboard_electronicstemperature_powerregulator_celsius;
  static_assert(
      (sizeof(
           edda_controllerboard_electronicstemperature_powerregulator_celsius) ==
       1),
      "invalid size");
  uint8_t edda_controllerboard_electronicstemperature_humiditysensor_celsius;
  static_assert(
      (sizeof(
           edda_controllerboard_electronicstemperature_humiditysensor_celsius) ==
       1),
      "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsTemperature__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 61;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_power3_electronicstemperature_pcb_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_power3_electronicstemperature_pcb_celsius);
  }
  void set_edda_controllerboard_electronicstemperature_microcontroller_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_controllerboard_electronicstemperature_microcontroller_celsius);
  }
  void set_edda_controllerboard_electronicstemperature_powerregulator_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_controllerboard_electronicstemperature_powerregulator_celsius);
  }
  void set_edda_controllerboard_electronicstemperature_humiditysensor_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_controllerboard_electronicstemperature_humiditysensor_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_power3_electronicstemperature_pcb_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_power3_electronicstemperature_pcb_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controllerboard_electronicstemperature_microcontroller_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controllerboard_electronicstemperature_microcontroller_celsius,
        -20, 106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controllerboard_electronicstemperature_powerregulator_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controllerboard_electronicstemperature_powerregulator_celsius, -20,
        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controllerboard_electronicstemperature_humiditysensor_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controllerboard_electronicstemperature_humiditysensor_celsius, -20,
        106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_power3_electronicstemperature_pcb_celsius,
           sizeof(edda_power3_electronicstemperature_pcb_celsius));
    *index += sizeof(edda_power3_electronicstemperature_pcb_celsius);
    memcpy(
        buf + *index,
        &edda_controllerboard_electronicstemperature_microcontroller_celsius,
        sizeof(
            edda_controllerboard_electronicstemperature_microcontroller_celsius));
    *index += sizeof(
        edda_controllerboard_electronicstemperature_microcontroller_celsius);
    memcpy(
        buf + *index,
        &edda_controllerboard_electronicstemperature_powerregulator_celsius,
        sizeof(
            edda_controllerboard_electronicstemperature_powerregulator_celsius));
    *index += sizeof(
        edda_controllerboard_electronicstemperature_powerregulator_celsius);
    memcpy(
        buf + *index,
        &edda_controllerboard_electronicstemperature_humiditysensor_celsius,
        sizeof(
            edda_controllerboard_electronicstemperature_humiditysensor_celsius));
    *index += sizeof(
        edda_controllerboard_electronicstemperature_humiditysensor_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_power3_electronicstemperature_pcb_celsius, buf + index,
           sizeof(edda_power3_electronicstemperature_pcb_celsius));
    index += sizeof(edda_power3_electronicstemperature_pcb_celsius);
    memcpy(
        &edda_controllerboard_electronicstemperature_microcontroller_celsius,
        buf + index,
        sizeof(
            edda_controllerboard_electronicstemperature_microcontroller_celsius));
    index += sizeof(
        edda_controllerboard_electronicstemperature_microcontroller_celsius);
    memcpy(
        &edda_controllerboard_electronicstemperature_powerregulator_celsius,
        buf + index,
        sizeof(
            edda_controllerboard_electronicstemperature_powerregulator_celsius));
    index += sizeof(
        edda_controllerboard_electronicstemperature_powerregulator_celsius);
    memcpy(
        &edda_controllerboard_electronicstemperature_humiditysensor_celsius,
        buf + index,
        sizeof(
            edda_controllerboard_electronicstemperature_humiditysensor_celsius));
    index += sizeof(
        edda_controllerboard_electronicstemperature_humiditysensor_celsius);
  }
};

class Telemetry__LoopTime__1_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_looptime_main_second;
  static_assert((sizeof(edda_telemetryboard_looptime_main_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_chitchat_second;
  static_assert((sizeof(edda_telemetryboard_looptime_chitchat_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_rgb_second;
  static_assert((sizeof(edda_telemetryboard_looptime_rgb_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 62;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_telemetryboard_looptime_main_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1, &edda_telemetryboard_looptime_main_second);
  }
  void set_edda_telemetryboard_looptime_chitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_chitchat_second);
  }
  void set_edda_telemetryboard_looptime_rgb_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1, &edda_telemetryboard_looptime_rgb_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_main_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_main_second, 0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_chitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_chitchat_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_rgb_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_rgb_second, 0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_looptime_main_second,
           sizeof(edda_telemetryboard_looptime_main_second));
    *index += sizeof(edda_telemetryboard_looptime_main_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_chitchat_second,
           sizeof(edda_telemetryboard_looptime_chitchat_second));
    *index += sizeof(edda_telemetryboard_looptime_chitchat_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_rgb_second,
           sizeof(edda_telemetryboard_looptime_rgb_second));
    *index += sizeof(edda_telemetryboard_looptime_rgb_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_looptime_main_second, buf + index,
           sizeof(edda_telemetryboard_looptime_main_second));
    index += sizeof(edda_telemetryboard_looptime_main_second);
    memcpy(&edda_telemetryboard_looptime_chitchat_second, buf + index,
           sizeof(edda_telemetryboard_looptime_chitchat_second));
    index += sizeof(edda_telemetryboard_looptime_chitchat_second);
    memcpy(&edda_telemetryboard_looptime_rgb_second, buf + index,
           sizeof(edda_telemetryboard_looptime_rgb_second));
    index += sizeof(edda_telemetryboard_looptime_rgb_second);
  }
};

class Telemetry__LoopTime__2_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_looptime_rgbchitchat_second;
  static_assert((sizeof(edda_telemetryboard_looptime_rgbchitchat_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_edda_second;
  static_assert((sizeof(edda_telemetryboard_looptime_edda_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_telemetry_second;
  static_assert((sizeof(edda_telemetryboard_looptime_telemetry_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 63;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_telemetryboard_looptime_rgbchitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_rgbchitchat_second);
  }
  void set_edda_telemetryboard_looptime_edda_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1, &edda_telemetryboard_looptime_edda_second);
  }
  void set_edda_telemetryboard_looptime_telemetry_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_telemetry_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_rgbchitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_rgbchitchat_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_edda_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_edda_second, 0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_telemetry_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_telemetry_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_looptime_rgbchitchat_second,
           sizeof(edda_telemetryboard_looptime_rgbchitchat_second));
    *index += sizeof(edda_telemetryboard_looptime_rgbchitchat_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_edda_second,
           sizeof(edda_telemetryboard_looptime_edda_second));
    *index += sizeof(edda_telemetryboard_looptime_edda_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_telemetry_second,
           sizeof(edda_telemetryboard_looptime_telemetry_second));
    *index += sizeof(edda_telemetryboard_looptime_telemetry_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_looptime_rgbchitchat_second, buf + index,
           sizeof(edda_telemetryboard_looptime_rgbchitchat_second));
    index += sizeof(edda_telemetryboard_looptime_rgbchitchat_second);
    memcpy(&edda_telemetryboard_looptime_edda_second, buf + index,
           sizeof(edda_telemetryboard_looptime_edda_second));
    index += sizeof(edda_telemetryboard_looptime_edda_second);
    memcpy(&edda_telemetryboard_looptime_telemetry_second, buf + index,
           sizeof(edda_telemetryboard_looptime_telemetry_second));
    index += sizeof(edda_telemetryboard_looptime_telemetry_second);
  }
};

class Telemetry__LoopTime__3_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_looptime_main_max_second;
  static_assert((sizeof(edda_telemetryboard_looptime_main_max_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_main_min_second;
  static_assert((sizeof(edda_telemetryboard_looptime_main_min_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_chitchat_max_second;
  static_assert((sizeof(edda_telemetryboard_looptime_chitchat_max_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 64;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_telemetryboard_looptime_main_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_main_max_second);
  }
  void set_edda_telemetryboard_looptime_main_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_main_min_second);
  }
  void
  set_edda_telemetryboard_looptime_chitchat_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_chitchat_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_main_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_main_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_main_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_main_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_chitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_chitchat_max_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_looptime_main_max_second,
           sizeof(edda_telemetryboard_looptime_main_max_second));
    *index += sizeof(edda_telemetryboard_looptime_main_max_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_main_min_second,
           sizeof(edda_telemetryboard_looptime_main_min_second));
    *index += sizeof(edda_telemetryboard_looptime_main_min_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_chitchat_max_second,
           sizeof(edda_telemetryboard_looptime_chitchat_max_second));
    *index += sizeof(edda_telemetryboard_looptime_chitchat_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_looptime_main_max_second, buf + index,
           sizeof(edda_telemetryboard_looptime_main_max_second));
    index += sizeof(edda_telemetryboard_looptime_main_max_second);
    memcpy(&edda_telemetryboard_looptime_main_min_second, buf + index,
           sizeof(edda_telemetryboard_looptime_main_min_second));
    index += sizeof(edda_telemetryboard_looptime_main_min_second);
    memcpy(&edda_telemetryboard_looptime_chitchat_max_second, buf + index,
           sizeof(edda_telemetryboard_looptime_chitchat_max_second));
    index += sizeof(edda_telemetryboard_looptime_chitchat_max_second);
  }
};

class Telemetry__LoopTime__4_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_looptime_chitchat_min_second;
  static_assert((sizeof(edda_telemetryboard_looptime_chitchat_min_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_rgb_max_second;
  static_assert((sizeof(edda_telemetryboard_looptime_rgb_max_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_rgb_min_second;
  static_assert((sizeof(edda_telemetryboard_looptime_rgb_min_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 65;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_telemetryboard_looptime_chitchat_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_chitchat_min_second);
  }
  void set_edda_telemetryboard_looptime_rgb_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_rgb_max_second);
  }
  void set_edda_telemetryboard_looptime_rgb_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_rgb_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_chitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_chitchat_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_rgb_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_rgb_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_rgb_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_rgb_min_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_looptime_chitchat_min_second,
           sizeof(edda_telemetryboard_looptime_chitchat_min_second));
    *index += sizeof(edda_telemetryboard_looptime_chitchat_min_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_rgb_max_second,
           sizeof(edda_telemetryboard_looptime_rgb_max_second));
    *index += sizeof(edda_telemetryboard_looptime_rgb_max_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_rgb_min_second,
           sizeof(edda_telemetryboard_looptime_rgb_min_second));
    *index += sizeof(edda_telemetryboard_looptime_rgb_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_looptime_chitchat_min_second, buf + index,
           sizeof(edda_telemetryboard_looptime_chitchat_min_second));
    index += sizeof(edda_telemetryboard_looptime_chitchat_min_second);
    memcpy(&edda_telemetryboard_looptime_rgb_max_second, buf + index,
           sizeof(edda_telemetryboard_looptime_rgb_max_second));
    index += sizeof(edda_telemetryboard_looptime_rgb_max_second);
    memcpy(&edda_telemetryboard_looptime_rgb_min_second, buf + index,
           sizeof(edda_telemetryboard_looptime_rgb_min_second));
    index += sizeof(edda_telemetryboard_looptime_rgb_min_second);
  }
};

class Telemetry__LoopTime__5_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_looptime_rgbchitchat_max_second;
  static_assert((sizeof(edda_telemetryboard_looptime_rgbchitchat_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_rgbchitchat_min_second;
  static_assert((sizeof(edda_telemetryboard_looptime_rgbchitchat_min_second) ==
                 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_edda_max_second;
  static_assert((sizeof(edda_telemetryboard_looptime_edda_max_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 66;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_telemetryboard_looptime_rgbchitchat_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_rgbchitchat_max_second);
  }
  void set_edda_telemetryboard_looptime_rgbchitchat_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_rgbchitchat_min_second);
  }
  void set_edda_telemetryboard_looptime_edda_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_edda_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_rgbchitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_rgbchitchat_max_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_rgbchitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_rgbchitchat_min_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_edda_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_edda_max_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_looptime_rgbchitchat_max_second,
           sizeof(edda_telemetryboard_looptime_rgbchitchat_max_second));
    *index += sizeof(edda_telemetryboard_looptime_rgbchitchat_max_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_rgbchitchat_min_second,
           sizeof(edda_telemetryboard_looptime_rgbchitchat_min_second));
    *index += sizeof(edda_telemetryboard_looptime_rgbchitchat_min_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_edda_max_second,
           sizeof(edda_telemetryboard_looptime_edda_max_second));
    *index += sizeof(edda_telemetryboard_looptime_edda_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_looptime_rgbchitchat_max_second, buf + index,
           sizeof(edda_telemetryboard_looptime_rgbchitchat_max_second));
    index += sizeof(edda_telemetryboard_looptime_rgbchitchat_max_second);
    memcpy(&edda_telemetryboard_looptime_rgbchitchat_min_second, buf + index,
           sizeof(edda_telemetryboard_looptime_rgbchitchat_min_second));
    index += sizeof(edda_telemetryboard_looptime_rgbchitchat_min_second);
    memcpy(&edda_telemetryboard_looptime_edda_max_second, buf + index,
           sizeof(edda_telemetryboard_looptime_edda_max_second));
    index += sizeof(edda_telemetryboard_looptime_edda_max_second);
  }
};

class Telemetry__LoopTime__6_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_telemetryboard_looptime_edda_min_second;
  static_assert((sizeof(edda_telemetryboard_looptime_edda_min_second) == 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_telemetry_max_second;
  static_assert((sizeof(edda_telemetryboard_looptime_telemetry_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_telemetryboard_looptime_telemetry_min_second;
  static_assert((sizeof(edda_telemetryboard_looptime_telemetry_min_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 67;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_telemetryboard_looptime_edda_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_edda_min_second);
  }
  void
  set_edda_telemetryboard_looptime_telemetry_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_telemetry_max_second);
  }
  void
  set_edda_telemetryboard_looptime_telemetry_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_telemetryboard_looptime_telemetry_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_edda_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_edda_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_telemetry_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_telemetry_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_telemetryboard_looptime_telemetry_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_telemetryboard_looptime_telemetry_min_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_telemetryboard_looptime_edda_min_second,
           sizeof(edda_telemetryboard_looptime_edda_min_second));
    *index += sizeof(edda_telemetryboard_looptime_edda_min_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_telemetry_max_second,
           sizeof(edda_telemetryboard_looptime_telemetry_max_second));
    *index += sizeof(edda_telemetryboard_looptime_telemetry_max_second);
    memcpy(buf + *index, &edda_telemetryboard_looptime_telemetry_min_second,
           sizeof(edda_telemetryboard_looptime_telemetry_min_second));
    *index += sizeof(edda_telemetryboard_looptime_telemetry_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_telemetryboard_looptime_edda_min_second, buf + index,
           sizeof(edda_telemetryboard_looptime_edda_min_second));
    index += sizeof(edda_telemetryboard_looptime_edda_min_second);
    memcpy(&edda_telemetryboard_looptime_telemetry_max_second, buf + index,
           sizeof(edda_telemetryboard_looptime_telemetry_max_second));
    index += sizeof(edda_telemetryboard_looptime_telemetry_max_second);
    memcpy(&edda_telemetryboard_looptime_telemetry_min_second, buf + index,
           sizeof(edda_telemetryboard_looptime_telemetry_min_second));
    index += sizeof(edda_telemetryboard_looptime_telemetry_min_second);
  }
};

class Telemetry__LoopTime__7_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_looptime_main_second;
  static_assert((sizeof(edda_controllerboard_looptime_main_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_chitchat_second;
  static_assert((sizeof(edda_controllerboard_looptime_chitchat_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_rgb_second;
  static_assert((sizeof(edda_controllerboard_looptime_rgb_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 68;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controllerboard_looptime_main_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_main_second);
  }
  void set_edda_controllerboard_looptime_chitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_chitchat_second);
  }
  void set_edda_controllerboard_looptime_rgb_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1, &edda_controllerboard_looptime_rgb_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_main_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_main_second, 0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_chitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_chitchat_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_rgb_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_rgb_second, 0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_looptime_main_second,
           sizeof(edda_controllerboard_looptime_main_second));
    *index += sizeof(edda_controllerboard_looptime_main_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_chitchat_second,
           sizeof(edda_controllerboard_looptime_chitchat_second));
    *index += sizeof(edda_controllerboard_looptime_chitchat_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_rgb_second,
           sizeof(edda_controllerboard_looptime_rgb_second));
    *index += sizeof(edda_controllerboard_looptime_rgb_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_looptime_main_second, buf + index,
           sizeof(edda_controllerboard_looptime_main_second));
    index += sizeof(edda_controllerboard_looptime_main_second);
    memcpy(&edda_controllerboard_looptime_chitchat_second, buf + index,
           sizeof(edda_controllerboard_looptime_chitchat_second));
    index += sizeof(edda_controllerboard_looptime_chitchat_second);
    memcpy(&edda_controllerboard_looptime_rgb_second, buf + index,
           sizeof(edda_controllerboard_looptime_rgb_second));
    index += sizeof(edda_controllerboard_looptime_rgb_second);
  }
};

class Telemetry__LoopTime__8_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_looptime_rgbchitchat_second;
  static_assert((sizeof(edda_controllerboard_looptime_rgbchitchat_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_edda_second;
  static_assert((sizeof(edda_controllerboard_looptime_edda_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_telemetry_second;
  static_assert((sizeof(edda_controllerboard_looptime_telemetry_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__8;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 69;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_controllerboard_looptime_rgbchitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_rgbchitchat_second);
  }
  void set_edda_controllerboard_looptime_edda_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_edda_second);
  }
  void
  set_edda_controllerboard_looptime_telemetry_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_telemetry_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_rgbchitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_rgbchitchat_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_edda_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_edda_second, 0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_telemetry_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_telemetry_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_looptime_rgbchitchat_second,
           sizeof(edda_controllerboard_looptime_rgbchitchat_second));
    *index += sizeof(edda_controllerboard_looptime_rgbchitchat_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_edda_second,
           sizeof(edda_controllerboard_looptime_edda_second));
    *index += sizeof(edda_controllerboard_looptime_edda_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_telemetry_second,
           sizeof(edda_controllerboard_looptime_telemetry_second));
    *index += sizeof(edda_controllerboard_looptime_telemetry_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_looptime_rgbchitchat_second, buf + index,
           sizeof(edda_controllerboard_looptime_rgbchitchat_second));
    index += sizeof(edda_controllerboard_looptime_rgbchitchat_second);
    memcpy(&edda_controllerboard_looptime_edda_second, buf + index,
           sizeof(edda_controllerboard_looptime_edda_second));
    index += sizeof(edda_controllerboard_looptime_edda_second);
    memcpy(&edda_controllerboard_looptime_telemetry_second, buf + index,
           sizeof(edda_controllerboard_looptime_telemetry_second));
    index += sizeof(edda_controllerboard_looptime_telemetry_second);
  }
};

class Telemetry__LoopTime__9_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_looptime_main_max_second;
  static_assert((sizeof(edda_controllerboard_looptime_main_max_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_main_min_second;
  static_assert((sizeof(edda_controllerboard_looptime_main_min_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_chitchat_max_second;
  static_assert((sizeof(edda_controllerboard_looptime_chitchat_max_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__9;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 70;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controllerboard_looptime_main_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_main_max_second);
  }
  void set_edda_controllerboard_looptime_main_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_main_min_second);
  }
  void
  set_edda_controllerboard_looptime_chitchat_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_chitchat_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_main_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_main_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_main_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_main_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_chitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_chitchat_max_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_looptime_main_max_second,
           sizeof(edda_controllerboard_looptime_main_max_second));
    *index += sizeof(edda_controllerboard_looptime_main_max_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_main_min_second,
           sizeof(edda_controllerboard_looptime_main_min_second));
    *index += sizeof(edda_controllerboard_looptime_main_min_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_chitchat_max_second,
           sizeof(edda_controllerboard_looptime_chitchat_max_second));
    *index += sizeof(edda_controllerboard_looptime_chitchat_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_looptime_main_max_second, buf + index,
           sizeof(edda_controllerboard_looptime_main_max_second));
    index += sizeof(edda_controllerboard_looptime_main_max_second);
    memcpy(&edda_controllerboard_looptime_main_min_second, buf + index,
           sizeof(edda_controllerboard_looptime_main_min_second));
    index += sizeof(edda_controllerboard_looptime_main_min_second);
    memcpy(&edda_controllerboard_looptime_chitchat_max_second, buf + index,
           sizeof(edda_controllerboard_looptime_chitchat_max_second));
    index += sizeof(edda_controllerboard_looptime_chitchat_max_second);
  }
};

class Telemetry__LoopTime__a_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_looptime_chitchat_min_second;
  static_assert((sizeof(edda_controllerboard_looptime_chitchat_min_second) ==
                 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_rgb_max_second;
  static_assert((sizeof(edda_controllerboard_looptime_rgb_max_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_rgb_min_second;
  static_assert((sizeof(edda_controllerboard_looptime_rgb_min_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__a;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 71;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_controllerboard_looptime_chitchat_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_chitchat_min_second);
  }
  void set_edda_controllerboard_looptime_rgb_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_rgb_max_second);
  }
  void set_edda_controllerboard_looptime_rgb_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_rgb_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_chitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_chitchat_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_rgb_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_rgb_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_rgb_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_rgb_min_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_looptime_chitchat_min_second,
           sizeof(edda_controllerboard_looptime_chitchat_min_second));
    *index += sizeof(edda_controllerboard_looptime_chitchat_min_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_rgb_max_second,
           sizeof(edda_controllerboard_looptime_rgb_max_second));
    *index += sizeof(edda_controllerboard_looptime_rgb_max_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_rgb_min_second,
           sizeof(edda_controllerboard_looptime_rgb_min_second));
    *index += sizeof(edda_controllerboard_looptime_rgb_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_looptime_chitchat_min_second, buf + index,
           sizeof(edda_controllerboard_looptime_chitchat_min_second));
    index += sizeof(edda_controllerboard_looptime_chitchat_min_second);
    memcpy(&edda_controllerboard_looptime_rgb_max_second, buf + index,
           sizeof(edda_controllerboard_looptime_rgb_max_second));
    index += sizeof(edda_controllerboard_looptime_rgb_max_second);
    memcpy(&edda_controllerboard_looptime_rgb_min_second, buf + index,
           sizeof(edda_controllerboard_looptime_rgb_min_second));
    index += sizeof(edda_controllerboard_looptime_rgb_min_second);
  }
};

class Telemetry__LoopTime__b_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_looptime_rgbchitchat_max_second;
  static_assert((sizeof(edda_controllerboard_looptime_rgbchitchat_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_rgbchitchat_min_second;
  static_assert((sizeof(edda_controllerboard_looptime_rgbchitchat_min_second) ==
                 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_edda_max_second;
  static_assert((sizeof(edda_controllerboard_looptime_edda_max_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__b;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 72;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controllerboard_looptime_rgbchitchat_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_rgbchitchat_max_second);
  }
  void set_edda_controllerboard_looptime_rgbchitchat_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_rgbchitchat_min_second);
  }
  void set_edda_controllerboard_looptime_edda_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_edda_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_rgbchitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_rgbchitchat_max_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_rgbchitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_rgbchitchat_min_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_edda_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_edda_max_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_looptime_rgbchitchat_max_second,
           sizeof(edda_controllerboard_looptime_rgbchitchat_max_second));
    *index += sizeof(edda_controllerboard_looptime_rgbchitchat_max_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_rgbchitchat_min_second,
           sizeof(edda_controllerboard_looptime_rgbchitchat_min_second));
    *index += sizeof(edda_controllerboard_looptime_rgbchitchat_min_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_edda_max_second,
           sizeof(edda_controllerboard_looptime_edda_max_second));
    *index += sizeof(edda_controllerboard_looptime_edda_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_looptime_rgbchitchat_max_second, buf + index,
           sizeof(edda_controllerboard_looptime_rgbchitchat_max_second));
    index += sizeof(edda_controllerboard_looptime_rgbchitchat_max_second);
    memcpy(&edda_controllerboard_looptime_rgbchitchat_min_second, buf + index,
           sizeof(edda_controllerboard_looptime_rgbchitchat_min_second));
    index += sizeof(edda_controllerboard_looptime_rgbchitchat_min_second);
    memcpy(&edda_controllerboard_looptime_edda_max_second, buf + index,
           sizeof(edda_controllerboard_looptime_edda_max_second));
    index += sizeof(edda_controllerboard_looptime_edda_max_second);
  }
};

class Telemetry__LoopTime__c_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controllerboard_looptime_edda_min_second;
  static_assert((sizeof(edda_controllerboard_looptime_edda_min_second) == 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_telemetry_max_second;
  static_assert((sizeof(edda_controllerboard_looptime_telemetry_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_controllerboard_looptime_telemetry_min_second;
  static_assert((sizeof(edda_controllerboard_looptime_telemetry_min_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__c;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 73;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controllerboard_looptime_edda_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_edda_min_second);
  }
  void
  set_edda_controllerboard_looptime_telemetry_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_telemetry_max_second);
  }
  void
  set_edda_controllerboard_looptime_telemetry_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_controllerboard_looptime_telemetry_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_edda_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_edda_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_telemetry_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_telemetry_max_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controllerboard_looptime_telemetry_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controllerboard_looptime_telemetry_min_second, 0,
                        1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controllerboard_looptime_edda_min_second,
           sizeof(edda_controllerboard_looptime_edda_min_second));
    *index += sizeof(edda_controllerboard_looptime_edda_min_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_telemetry_max_second,
           sizeof(edda_controllerboard_looptime_telemetry_max_second));
    *index += sizeof(edda_controllerboard_looptime_telemetry_max_second);
    memcpy(buf + *index, &edda_controllerboard_looptime_telemetry_min_second,
           sizeof(edda_controllerboard_looptime_telemetry_min_second));
    *index += sizeof(edda_controllerboard_looptime_telemetry_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controllerboard_looptime_edda_min_second, buf + index,
           sizeof(edda_controllerboard_looptime_edda_min_second));
    index += sizeof(edda_controllerboard_looptime_edda_min_second);
    memcpy(&edda_controllerboard_looptime_telemetry_max_second, buf + index,
           sizeof(edda_controllerboard_looptime_telemetry_max_second));
    index += sizeof(edda_controllerboard_looptime_telemetry_max_second);
    memcpy(&edda_controllerboard_looptime_telemetry_min_second, buf + index,
           sizeof(edda_controllerboard_looptime_telemetry_min_second));
    index += sizeof(edda_controllerboard_looptime_telemetry_min_second);
  }
};

class Telemetry__LoopTime__d_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_looptime_main_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_main_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_chitchat_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_chitchat_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_rgb_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_rgb_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__d;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 74;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_top_looptime_main_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_main_second);
  }
  void
  set_edda_pressureboard_top_looptime_chitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_chitchat_second);
  }
  void set_edda_pressureboard_top_looptime_rgb_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_rgb_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_main_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_main_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_chitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_chitchat_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_rgb_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_rgb_second, 0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_main_second,
           sizeof(edda_pressureboard_top_looptime_main_second));
    *index += sizeof(edda_pressureboard_top_looptime_main_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_chitchat_second,
           sizeof(edda_pressureboard_top_looptime_chitchat_second));
    *index += sizeof(edda_pressureboard_top_looptime_chitchat_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_rgb_second,
           sizeof(edda_pressureboard_top_looptime_rgb_second));
    *index += sizeof(edda_pressureboard_top_looptime_rgb_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_looptime_main_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_main_second));
    index += sizeof(edda_pressureboard_top_looptime_main_second);
    memcpy(&edda_pressureboard_top_looptime_chitchat_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_chitchat_second));
    index += sizeof(edda_pressureboard_top_looptime_chitchat_second);
    memcpy(&edda_pressureboard_top_looptime_rgb_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_rgb_second));
    index += sizeof(edda_pressureboard_top_looptime_rgb_second);
  }
};

class Telemetry__LoopTime__e_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_looptime_rgbchitchat_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_rgbchitchat_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_edda_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_edda_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_telemetry_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_telemetry_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__e;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 75;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_top_looptime_rgbchitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_rgbchitchat_second);
  }
  void set_edda_pressureboard_top_looptime_edda_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_edda_second);
  }
  void
  set_edda_pressureboard_top_looptime_telemetry_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_telemetry_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_rgbchitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_rgbchitchat_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_edda_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_edda_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_telemetry_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_telemetry_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_rgbchitchat_second,
           sizeof(edda_pressureboard_top_looptime_rgbchitchat_second));
    *index += sizeof(edda_pressureboard_top_looptime_rgbchitchat_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_edda_second,
           sizeof(edda_pressureboard_top_looptime_edda_second));
    *index += sizeof(edda_pressureboard_top_looptime_edda_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_telemetry_second,
           sizeof(edda_pressureboard_top_looptime_telemetry_second));
    *index += sizeof(edda_pressureboard_top_looptime_telemetry_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_looptime_rgbchitchat_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_rgbchitchat_second));
    index += sizeof(edda_pressureboard_top_looptime_rgbchitchat_second);
    memcpy(&edda_pressureboard_top_looptime_edda_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_edda_second));
    index += sizeof(edda_pressureboard_top_looptime_edda_second);
    memcpy(&edda_pressureboard_top_looptime_telemetry_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_telemetry_second));
    index += sizeof(edda_pressureboard_top_looptime_telemetry_second);
  }
};

class Telemetry__LoopTime__f_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_looptime_main_max_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_main_max_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_main_min_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_main_min_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_chitchat_max_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_chitchat_max_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__f;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 76;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_top_looptime_main_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_main_max_second);
  }
  void
  set_edda_pressureboard_top_looptime_main_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_main_min_second);
  }
  void set_edda_pressureboard_top_looptime_chitchat_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_chitchat_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_main_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_main_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_main_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_main_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_chitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_chitchat_max_second, 0,
                        1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_main_max_second,
           sizeof(edda_pressureboard_top_looptime_main_max_second));
    *index += sizeof(edda_pressureboard_top_looptime_main_max_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_main_min_second,
           sizeof(edda_pressureboard_top_looptime_main_min_second));
    *index += sizeof(edda_pressureboard_top_looptime_main_min_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_chitchat_max_second,
           sizeof(edda_pressureboard_top_looptime_chitchat_max_second));
    *index += sizeof(edda_pressureboard_top_looptime_chitchat_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_looptime_main_max_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_main_max_second));
    index += sizeof(edda_pressureboard_top_looptime_main_max_second);
    memcpy(&edda_pressureboard_top_looptime_main_min_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_main_min_second));
    index += sizeof(edda_pressureboard_top_looptime_main_min_second);
    memcpy(&edda_pressureboard_top_looptime_chitchat_max_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_chitchat_max_second));
    index += sizeof(edda_pressureboard_top_looptime_chitchat_max_second);
  }
};

class Telemetry__LoopTime__10_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_looptime_chitchat_min_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_chitchat_min_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_rgb_max_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_rgb_max_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_rgb_min_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_rgb_min_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__10;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 77;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_top_looptime_chitchat_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_chitchat_min_second);
  }
  void
  set_edda_pressureboard_top_looptime_rgb_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_rgb_max_second);
  }
  void
  set_edda_pressureboard_top_looptime_rgb_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_rgb_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_chitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_chitchat_min_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_rgb_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_rgb_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_rgb_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_rgb_min_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_chitchat_min_second,
           sizeof(edda_pressureboard_top_looptime_chitchat_min_second));
    *index += sizeof(edda_pressureboard_top_looptime_chitchat_min_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_rgb_max_second,
           sizeof(edda_pressureboard_top_looptime_rgb_max_second));
    *index += sizeof(edda_pressureboard_top_looptime_rgb_max_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_rgb_min_second,
           sizeof(edda_pressureboard_top_looptime_rgb_min_second));
    *index += sizeof(edda_pressureboard_top_looptime_rgb_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_looptime_chitchat_min_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_chitchat_min_second));
    index += sizeof(edda_pressureboard_top_looptime_chitchat_min_second);
    memcpy(&edda_pressureboard_top_looptime_rgb_max_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_rgb_max_second));
    index += sizeof(edda_pressureboard_top_looptime_rgb_max_second);
    memcpy(&edda_pressureboard_top_looptime_rgb_min_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_rgb_min_second));
    index += sizeof(edda_pressureboard_top_looptime_rgb_min_second);
  }
};

class Telemetry__LoopTime__11_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_looptime_rgbchitchat_max_second;
  static_assert(
      (sizeof(edda_pressureboard_top_looptime_rgbchitchat_max_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_top_looptime_rgbchitchat_min_second;
  static_assert(
      (sizeof(edda_pressureboard_top_looptime_rgbchitchat_min_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_top_looptime_edda_max_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_edda_max_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__11;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 78;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_top_looptime_rgbchitchat_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1, &edda_pressureboard_top_looptime_rgbchitchat_max_second);
  }
  void set_edda_pressureboard_top_looptime_rgbchitchat_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1, &edda_pressureboard_top_looptime_rgbchitchat_min_second);
  }
  void
  set_edda_pressureboard_top_looptime_edda_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_edda_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_rgbchitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_rgbchitchat_max_second,
                        0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_rgbchitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_rgbchitchat_min_second,
                        0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_edda_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_edda_max_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_pressureboard_top_looptime_rgbchitchat_max_second,
           sizeof(edda_pressureboard_top_looptime_rgbchitchat_max_second));
    *index += sizeof(edda_pressureboard_top_looptime_rgbchitchat_max_second);
    memcpy(buf + *index,
           &edda_pressureboard_top_looptime_rgbchitchat_min_second,
           sizeof(edda_pressureboard_top_looptime_rgbchitchat_min_second));
    *index += sizeof(edda_pressureboard_top_looptime_rgbchitchat_min_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_edda_max_second,
           sizeof(edda_pressureboard_top_looptime_edda_max_second));
    *index += sizeof(edda_pressureboard_top_looptime_edda_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_looptime_rgbchitchat_max_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_rgbchitchat_max_second));
    index += sizeof(edda_pressureboard_top_looptime_rgbchitchat_max_second);
    memcpy(&edda_pressureboard_top_looptime_rgbchitchat_min_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_rgbchitchat_min_second));
    index += sizeof(edda_pressureboard_top_looptime_rgbchitchat_min_second);
    memcpy(&edda_pressureboard_top_looptime_edda_max_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_edda_max_second));
    index += sizeof(edda_pressureboard_top_looptime_edda_max_second);
  }
};

class Telemetry__LoopTime__12_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_looptime_edda_min_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_edda_min_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_telemetry_max_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_telemetry_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_top_looptime_telemetry_min_second;
  static_assert((sizeof(edda_pressureboard_top_looptime_telemetry_min_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__12;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 79;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_top_looptime_edda_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_edda_min_second);
  }
  void set_edda_pressureboard_top_looptime_telemetry_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_telemetry_max_second);
  }
  void set_edda_pressureboard_top_looptime_telemetry_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_top_looptime_telemetry_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_edda_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_edda_min_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_telemetry_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_telemetry_max_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_looptime_telemetry_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_looptime_telemetry_min_second, 0,
                        1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_edda_min_second,
           sizeof(edda_pressureboard_top_looptime_edda_min_second));
    *index += sizeof(edda_pressureboard_top_looptime_edda_min_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_telemetry_max_second,
           sizeof(edda_pressureboard_top_looptime_telemetry_max_second));
    *index += sizeof(edda_pressureboard_top_looptime_telemetry_max_second);
    memcpy(buf + *index, &edda_pressureboard_top_looptime_telemetry_min_second,
           sizeof(edda_pressureboard_top_looptime_telemetry_min_second));
    *index += sizeof(edda_pressureboard_top_looptime_telemetry_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_looptime_edda_min_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_edda_min_second));
    index += sizeof(edda_pressureboard_top_looptime_edda_min_second);
    memcpy(&edda_pressureboard_top_looptime_telemetry_max_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_telemetry_max_second));
    index += sizeof(edda_pressureboard_top_looptime_telemetry_max_second);
    memcpy(&edda_pressureboard_top_looptime_telemetry_min_second, buf + index,
           sizeof(edda_pressureboard_top_looptime_telemetry_min_second));
    index += sizeof(edda_pressureboard_top_looptime_telemetry_min_second);
  }
};

class Telemetry__LoopTime__13_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_main_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_main_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_chitchat_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_chitchat_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_rgb_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_rgb_second) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__13;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 80;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_bottom_looptime_main_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_main_second);
  }
  void
  set_edda_pressureboard_bottom_looptime_chitchat_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_chitchat_second);
  }
  void set_edda_pressureboard_bottom_looptime_rgb_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_rgb_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_main_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_main_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_chitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_chitchat_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_rgb_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_rgb_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_main_second,
           sizeof(edda_pressureboard_bottom_looptime_main_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_main_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_chitchat_second,
           sizeof(edda_pressureboard_bottom_looptime_chitchat_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_chitchat_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_rgb_second,
           sizeof(edda_pressureboard_bottom_looptime_rgb_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_rgb_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_looptime_main_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_main_second));
    index += sizeof(edda_pressureboard_bottom_looptime_main_second);
    memcpy(&edda_pressureboard_bottom_looptime_chitchat_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_chitchat_second));
    index += sizeof(edda_pressureboard_bottom_looptime_chitchat_second);
    memcpy(&edda_pressureboard_bottom_looptime_rgb_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_rgb_second));
    index += sizeof(edda_pressureboard_bottom_looptime_rgb_second);
  }
};

class Telemetry__LoopTime__14_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_rgbchitchat_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_edda_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_edda_second) == 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_telemetry_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_telemetry_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__14;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 81;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_bottom_looptime_rgbchitchat_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_rgbchitchat_second);
  }
  void
  set_edda_pressureboard_bottom_looptime_edda_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_edda_second);
  }
  void set_edda_pressureboard_bottom_looptime_telemetry_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_telemetry_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_rgbchitchat_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_rgbchitchat_second,
                        0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_edda_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_edda_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_telemetry_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_telemetry_second, 0,
                        1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_rgbchitchat_second,
           sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_edda_second,
           sizeof(edda_pressureboard_bottom_looptime_edda_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_edda_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_telemetry_second,
           sizeof(edda_pressureboard_bottom_looptime_telemetry_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_telemetry_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_looptime_rgbchitchat_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_second));
    index += sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_second);
    memcpy(&edda_pressureboard_bottom_looptime_edda_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_edda_second));
    index += sizeof(edda_pressureboard_bottom_looptime_edda_second);
    memcpy(&edda_pressureboard_bottom_looptime_telemetry_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_telemetry_second));
    index += sizeof(edda_pressureboard_bottom_looptime_telemetry_second);
  }
};

class Telemetry__LoopTime__15_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_main_max_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_main_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_main_min_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_main_min_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_chitchat_max_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_chitchat_max_second) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__15;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 82;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_bottom_looptime_main_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_main_max_second);
  }
  void
  set_edda_pressureboard_bottom_looptime_main_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_main_min_second);
  }
  void set_edda_pressureboard_bottom_looptime_chitchat_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1, &edda_pressureboard_bottom_looptime_chitchat_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_main_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_main_max_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_main_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_main_min_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_chitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_chitchat_max_second,
                        0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_main_max_second,
           sizeof(edda_pressureboard_bottom_looptime_main_max_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_main_max_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_main_min_second,
           sizeof(edda_pressureboard_bottom_looptime_main_min_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_main_min_second);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_looptime_chitchat_max_second,
           sizeof(edda_pressureboard_bottom_looptime_chitchat_max_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_chitchat_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_looptime_main_max_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_main_max_second));
    index += sizeof(edda_pressureboard_bottom_looptime_main_max_second);
    memcpy(&edda_pressureboard_bottom_looptime_main_min_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_main_min_second));
    index += sizeof(edda_pressureboard_bottom_looptime_main_min_second);
    memcpy(&edda_pressureboard_bottom_looptime_chitchat_max_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_chitchat_max_second));
    index += sizeof(edda_pressureboard_bottom_looptime_chitchat_max_second);
  }
};

class Telemetry__LoopTime__16_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_chitchat_min_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_chitchat_min_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_rgb_max_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_rgb_max_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_rgb_min_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_rgb_min_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__16;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 83;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_bottom_looptime_chitchat_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1, &edda_pressureboard_bottom_looptime_chitchat_min_second);
  }
  void
  set_edda_pressureboard_bottom_looptime_rgb_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_rgb_max_second);
  }
  void
  set_edda_pressureboard_bottom_looptime_rgb_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_rgb_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_chitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_chitchat_min_second,
                        0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_rgb_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_rgb_max_second, 0, 1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_rgb_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_rgb_min_second, 0, 1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_looptime_chitchat_min_second,
           sizeof(edda_pressureboard_bottom_looptime_chitchat_min_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_chitchat_min_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_rgb_max_second,
           sizeof(edda_pressureboard_bottom_looptime_rgb_max_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_rgb_max_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_rgb_min_second,
           sizeof(edda_pressureboard_bottom_looptime_rgb_min_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_rgb_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_looptime_chitchat_min_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_chitchat_min_second));
    index += sizeof(edda_pressureboard_bottom_looptime_chitchat_min_second);
    memcpy(&edda_pressureboard_bottom_looptime_rgb_max_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_rgb_max_second));
    index += sizeof(edda_pressureboard_bottom_looptime_rgb_max_second);
    memcpy(&edda_pressureboard_bottom_looptime_rgb_min_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_rgb_min_second));
    index += sizeof(edda_pressureboard_bottom_looptime_rgb_min_second);
  }
};

class Telemetry__LoopTime__17_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_rgbchitchat_max_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_max_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_rgbchitchat_min_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_min_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_edda_max_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_edda_max_second) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__17;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 84;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_bottom_looptime_rgbchitchat_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1,
        &edda_pressureboard_bottom_looptime_rgbchitchat_max_second);
  }
  void set_edda_pressureboard_bottom_looptime_rgbchitchat_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1,
        &edda_pressureboard_bottom_looptime_rgbchitchat_min_second);
  }
  void
  set_edda_pressureboard_bottom_looptime_edda_max_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_edda_max_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_bottom_looptime_rgbchitchat_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_bottom_looptime_rgbchitchat_max_second, 0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_bottom_looptime_rgbchitchat_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_bottom_looptime_rgbchitchat_min_second, 0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_edda_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_edda_max_second, 0,
                        1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_looptime_rgbchitchat_max_second,
           sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_max_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_max_second);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_looptime_rgbchitchat_min_second,
           sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_min_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_min_second);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_edda_max_second,
           sizeof(edda_pressureboard_bottom_looptime_edda_max_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_edda_max_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_looptime_rgbchitchat_max_second,
           buf + index,
           sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_max_second));
    index += sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_max_second);
    memcpy(&edda_pressureboard_bottom_looptime_rgbchitchat_min_second,
           buf + index,
           sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_min_second));
    index += sizeof(edda_pressureboard_bottom_looptime_rgbchitchat_min_second);
    memcpy(&edda_pressureboard_bottom_looptime_edda_max_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_edda_max_second));
    index += sizeof(edda_pressureboard_bottom_looptime_edda_max_second);
  }
};

class Telemetry__LoopTime__18_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_edda_min_second;
  static_assert((sizeof(edda_pressureboard_bottom_looptime_edda_min_second) ==
                 2),
                "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_telemetry_max_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_telemetry_max_second) == 2),
      "invalid size");
  uint16_t edda_pressureboard_bottom_looptime_telemetry_min_second;
  static_assert(
      (sizeof(edda_pressureboard_bottom_looptime_telemetry_min_second) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__LoopTime__18;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 85;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_bottom_looptime_edda_min_second(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1,
                        &edda_pressureboard_bottom_looptime_edda_min_second);
  }
  void set_edda_pressureboard_bottom_looptime_telemetry_max_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1, &edda_pressureboard_bottom_looptime_telemetry_max_second);
  }
  void set_edda_pressureboard_bottom_looptime_telemetry_min_second(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 1, &edda_pressureboard_bottom_looptime_telemetry_min_second);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_edda_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_edda_min_second, 0,
                        1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_telemetry_max_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_telemetry_max_second,
                        0, 1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_looptime_telemetry_min_second() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_looptime_telemetry_min_second,
                        0, 1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_bottom_looptime_edda_min_second,
           sizeof(edda_pressureboard_bottom_looptime_edda_min_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_edda_min_second);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_looptime_telemetry_max_second,
           sizeof(edda_pressureboard_bottom_looptime_telemetry_max_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_telemetry_max_second);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_looptime_telemetry_min_second,
           sizeof(edda_pressureboard_bottom_looptime_telemetry_min_second));
    *index += sizeof(edda_pressureboard_bottom_looptime_telemetry_min_second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_looptime_edda_min_second, buf + index,
           sizeof(edda_pressureboard_bottom_looptime_edda_min_second));
    index += sizeof(edda_pressureboard_bottom_looptime_edda_min_second);
    memcpy(&edda_pressureboard_bottom_looptime_telemetry_max_second,
           buf + index,
           sizeof(edda_pressureboard_bottom_looptime_telemetry_max_second));
    index += sizeof(edda_pressureboard_bottom_looptime_telemetry_max_second);
    memcpy(&edda_pressureboard_bottom_looptime_telemetry_min_second,
           buf + index,
           sizeof(edda_pressureboard_bottom_looptime_telemetry_min_second));
    index += sizeof(edda_pressureboard_bottom_looptime_telemetry_min_second);
  }
};

class
    Telemetry__ElectronicsTemperature__3_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t edda_telemetryboard_electronicstemperature_microcontroller_celsius;
  static_assert(
      (sizeof(
           edda_telemetryboard_electronicstemperature_microcontroller_celsius) ==
       1),
      "invalid size");
  uint8_t edda_telemetryboard_electronicstemperature_powerregulator_celsius;
  static_assert(
      (sizeof(
           edda_telemetryboard_electronicstemperature_powerregulator_celsius) ==
       1),
      "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsTemperature__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 86;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_telemetryboard_electronicstemperature_microcontroller_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_telemetryboard_electronicstemperature_microcontroller_celsius);
  }
  void set_edda_telemetryboard_electronicstemperature_powerregulator_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_telemetryboard_electronicstemperature_powerregulator_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_telemetryboard_electronicstemperature_microcontroller_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_telemetryboard_electronicstemperature_microcontroller_celsius, -20,
        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_telemetryboard_electronicstemperature_powerregulator_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_telemetryboard_electronicstemperature_powerregulator_celsius, -20,
        106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_telemetryboard_electronicstemperature_microcontroller_celsius,
        sizeof(
            edda_telemetryboard_electronicstemperature_microcontroller_celsius));
    *index += sizeof(
        edda_telemetryboard_electronicstemperature_microcontroller_celsius);
    memcpy(
        buf + *index,
        &edda_telemetryboard_electronicstemperature_powerregulator_celsius,
        sizeof(
            edda_telemetryboard_electronicstemperature_powerregulator_celsius));
    *index += sizeof(
        edda_telemetryboard_electronicstemperature_powerregulator_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_telemetryboard_electronicstemperature_microcontroller_celsius,
        buf + index,
        sizeof(
            edda_telemetryboard_electronicstemperature_microcontroller_celsius));
    index += sizeof(
        edda_telemetryboard_electronicstemperature_microcontroller_celsius);
    memcpy(
        &edda_telemetryboard_electronicstemperature_powerregulator_celsius,
        buf + index,
        sizeof(
            edda_telemetryboard_electronicstemperature_powerregulator_celsius));
    index += sizeof(
        edda_telemetryboard_electronicstemperature_powerregulator_celsius);
  }
};

class
    Telemetry__ElectronicsTemperature__4_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t edda_pressureboard_top_electronicstemperature_microcontroller_celsius;
  static_assert(
      (sizeof(
           edda_pressureboard_top_electronicstemperature_microcontroller_celsius) ==
       1),
      "invalid size");
  uint8_t edda_pressureboard_top_electronicstemperature_powerregulator_celsius;
  static_assert(
      (sizeof(
           edda_pressureboard_top_electronicstemperature_powerregulator_celsius) ==
       1),
      "invalid size");
  uint8_t
      edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius;
  static_assert(
      (sizeof(
           edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius) ==
       1),
      "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsTemperature__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 87;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_top_electronicstemperature_microcontroller_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_pressureboard_top_electronicstemperature_microcontroller_celsius);
  }
  void set_edda_pressureboard_top_electronicstemperature_powerregulator_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_pressureboard_top_electronicstemperature_powerregulator_celsius);
  }
  void
  set_edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_top_electronicstemperature_microcontroller_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_top_electronicstemperature_microcontroller_celsius,
        -20, 106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_top_electronicstemperature_powerregulator_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_top_electronicstemperature_powerregulator_celsius,
        -20, 106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius,
        -20, 106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_pressureboard_top_electronicstemperature_microcontroller_celsius,
        sizeof(
            edda_pressureboard_top_electronicstemperature_microcontroller_celsius));
    *index += sizeof(
        edda_pressureboard_top_electronicstemperature_microcontroller_celsius);
    memcpy(
        buf + *index,
        &edda_pressureboard_top_electronicstemperature_powerregulator_celsius,
        sizeof(
            edda_pressureboard_top_electronicstemperature_powerregulator_celsius));
    *index += sizeof(
        edda_pressureboard_top_electronicstemperature_powerregulator_celsius);
    memcpy(
        buf + *index,
        &edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius,
        sizeof(
            edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius));
    *index += sizeof(
        edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_pressureboard_top_electronicstemperature_microcontroller_celsius,
        buf + index,
        sizeof(
            edda_pressureboard_top_electronicstemperature_microcontroller_celsius));
    index += sizeof(
        edda_pressureboard_top_electronicstemperature_microcontroller_celsius);
    memcpy(
        &edda_pressureboard_top_electronicstemperature_powerregulator_celsius,
        buf + index,
        sizeof(
            edda_pressureboard_top_electronicstemperature_powerregulator_celsius));
    index += sizeof(
        edda_pressureboard_top_electronicstemperature_powerregulator_celsius);
    memcpy(
        &edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius,
        buf + index,
        sizeof(
            edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius));
    index += sizeof(
        edda_pressureboard_top_electronicstemperature_ambientpressuresensor_celsius);
  }
};

class
    Telemetry__ElectronicsTemperature__5_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t
      edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius;
  static_assert(
      (sizeof(
           edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius) ==
       1),
      "invalid size");
  uint8_t
      edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius;
  static_assert(
      (sizeof(
           edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius) ==
       1),
      "invalid size");
  uint8_t
      edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius;
  static_assert(
      (sizeof(
           edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius) ==
       1),
      "invalid size");
  uint8_t size = 4;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsTemperature__5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 88;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius);
  }
  void
  set_edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius);
  }
  void
  set_edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 106,
        &edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius,
        -20, 106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius,
        -20, 106, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius,
        -20, 106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius,
        sizeof(
            edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius));
    *index += sizeof(
        edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius);
    memcpy(
        buf + *index,
        &edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius,
        sizeof(
            edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius));
    *index += sizeof(
        edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius);
    memcpy(
        buf + *index,
        &edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius,
        sizeof(
            edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius));
    *index += sizeof(
        edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius,
        buf + index,
        sizeof(
            edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius));
    index += sizeof(
        edda_pressureboard_bottom_electronicstemperature_microcontroller_celsius);
    memcpy(
        &edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius,
        buf + index,
        sizeof(
            edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius));
    index += sizeof(
        edda_pressureboard_bottom_electronicstemperature_powerregulator_celsius);
    memcpy(
        &edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius,
        buf + index,
        sizeof(
            edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius));
    index += sizeof(
        edda_pressureboard_bottom_electronicstemperature_ambientpressuresensor_celsius);
  }
};

class Telemetry__Temperature__1_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm0_celsius;
  static_assert((sizeof(sindri_temperature_therm0_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm1_celsius;
  static_assert((sizeof(sindri_temperature_therm1_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm2_celsius;
  static_assert((sizeof(sindri_temperature_therm2_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 89;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm0_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm0_celsius);
  }
  void set_sindri_temperature_therm1_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm1_celsius);
  }
  void set_sindri_temperature_therm2_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm2_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm0_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm0_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm1_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm1_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm2_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm2_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm0_celsius,
           sizeof(sindri_temperature_therm0_celsius));
    *index += sizeof(sindri_temperature_therm0_celsius);
    memcpy(buf + *index, &sindri_temperature_therm1_celsius,
           sizeof(sindri_temperature_therm1_celsius));
    *index += sizeof(sindri_temperature_therm1_celsius);
    memcpy(buf + *index, &sindri_temperature_therm2_celsius,
           sizeof(sindri_temperature_therm2_celsius));
    *index += sizeof(sindri_temperature_therm2_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm0_celsius, buf + index,
           sizeof(sindri_temperature_therm0_celsius));
    index += sizeof(sindri_temperature_therm0_celsius);
    memcpy(&sindri_temperature_therm1_celsius, buf + index,
           sizeof(sindri_temperature_therm1_celsius));
    index += sizeof(sindri_temperature_therm1_celsius);
    memcpy(&sindri_temperature_therm2_celsius, buf + index,
           sizeof(sindri_temperature_therm2_celsius));
    index += sizeof(sindri_temperature_therm2_celsius);
  }
};

class Telemetry__Temperature__2_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm3_celsius;
  static_assert((sizeof(sindri_temperature_therm3_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm4_celsius;
  static_assert((sizeof(sindri_temperature_therm4_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm5_celsius;
  static_assert((sizeof(sindri_temperature_therm5_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 90;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm3_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm3_celsius);
  }
  void set_sindri_temperature_therm4_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm4_celsius);
  }
  void set_sindri_temperature_therm5_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm5_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm3_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm3_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm4_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm4_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm5_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm5_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm3_celsius,
           sizeof(sindri_temperature_therm3_celsius));
    *index += sizeof(sindri_temperature_therm3_celsius);
    memcpy(buf + *index, &sindri_temperature_therm4_celsius,
           sizeof(sindri_temperature_therm4_celsius));
    *index += sizeof(sindri_temperature_therm4_celsius);
    memcpy(buf + *index, &sindri_temperature_therm5_celsius,
           sizeof(sindri_temperature_therm5_celsius));
    *index += sizeof(sindri_temperature_therm5_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm3_celsius, buf + index,
           sizeof(sindri_temperature_therm3_celsius));
    index += sizeof(sindri_temperature_therm3_celsius);
    memcpy(&sindri_temperature_therm4_celsius, buf + index,
           sizeof(sindri_temperature_therm4_celsius));
    index += sizeof(sindri_temperature_therm4_celsius);
    memcpy(&sindri_temperature_therm5_celsius, buf + index,
           sizeof(sindri_temperature_therm5_celsius));
    index += sizeof(sindri_temperature_therm5_celsius);
  }
};

class Telemetry__Temperature__3_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm6_celsius;
  static_assert((sizeof(sindri_temperature_therm6_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm7_celsius;
  static_assert((sizeof(sindri_temperature_therm7_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm8_celsius;
  static_assert((sizeof(sindri_temperature_therm8_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 91;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm6_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm6_celsius);
  }
  void set_sindri_temperature_therm7_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm7_celsius);
  }
  void set_sindri_temperature_therm8_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm8_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm6_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm6_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm7_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm7_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm8_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm8_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm6_celsius,
           sizeof(sindri_temperature_therm6_celsius));
    *index += sizeof(sindri_temperature_therm6_celsius);
    memcpy(buf + *index, &sindri_temperature_therm7_celsius,
           sizeof(sindri_temperature_therm7_celsius));
    *index += sizeof(sindri_temperature_therm7_celsius);
    memcpy(buf + *index, &sindri_temperature_therm8_celsius,
           sizeof(sindri_temperature_therm8_celsius));
    *index += sizeof(sindri_temperature_therm8_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm6_celsius, buf + index,
           sizeof(sindri_temperature_therm6_celsius));
    index += sizeof(sindri_temperature_therm6_celsius);
    memcpy(&sindri_temperature_therm7_celsius, buf + index,
           sizeof(sindri_temperature_therm7_celsius));
    index += sizeof(sindri_temperature_therm7_celsius);
    memcpy(&sindri_temperature_therm8_celsius, buf + index,
           sizeof(sindri_temperature_therm8_celsius));
    index += sizeof(sindri_temperature_therm8_celsius);
  }
};

class Telemetry__Temperature__4_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm9_celsius;
  static_assert((sizeof(sindri_temperature_therm9_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm10_celsius;
  static_assert((sizeof(sindri_temperature_therm10_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm11_celsius;
  static_assert((sizeof(sindri_temperature_therm11_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 92;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm9_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm9_celsius);
  }
  void set_sindri_temperature_therm10_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm10_celsius);
  }
  void set_sindri_temperature_therm11_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm11_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm9_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm9_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm10_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm10_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm11_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm11_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm9_celsius,
           sizeof(sindri_temperature_therm9_celsius));
    *index += sizeof(sindri_temperature_therm9_celsius);
    memcpy(buf + *index, &sindri_temperature_therm10_celsius,
           sizeof(sindri_temperature_therm10_celsius));
    *index += sizeof(sindri_temperature_therm10_celsius);
    memcpy(buf + *index, &sindri_temperature_therm11_celsius,
           sizeof(sindri_temperature_therm11_celsius));
    *index += sizeof(sindri_temperature_therm11_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm9_celsius, buf + index,
           sizeof(sindri_temperature_therm9_celsius));
    index += sizeof(sindri_temperature_therm9_celsius);
    memcpy(&sindri_temperature_therm10_celsius, buf + index,
           sizeof(sindri_temperature_therm10_celsius));
    index += sizeof(sindri_temperature_therm10_celsius);
    memcpy(&sindri_temperature_therm11_celsius, buf + index,
           sizeof(sindri_temperature_therm11_celsius));
    index += sizeof(sindri_temperature_therm11_celsius);
  }
};

class Telemetry__Temperature__5_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm12_celsius;
  static_assert((sizeof(sindri_temperature_therm12_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm13_celsius;
  static_assert((sizeof(sindri_temperature_therm13_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm14_celsius;
  static_assert((sizeof(sindri_temperature_therm14_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 93;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm12_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm12_celsius);
  }
  void set_sindri_temperature_therm13_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm13_celsius);
  }
  void set_sindri_temperature_therm14_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm14_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm12_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm12_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm13_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm13_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm14_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm14_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm12_celsius,
           sizeof(sindri_temperature_therm12_celsius));
    *index += sizeof(sindri_temperature_therm12_celsius);
    memcpy(buf + *index, &sindri_temperature_therm13_celsius,
           sizeof(sindri_temperature_therm13_celsius));
    *index += sizeof(sindri_temperature_therm13_celsius);
    memcpy(buf + *index, &sindri_temperature_therm14_celsius,
           sizeof(sindri_temperature_therm14_celsius));
    *index += sizeof(sindri_temperature_therm14_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm12_celsius, buf + index,
           sizeof(sindri_temperature_therm12_celsius));
    index += sizeof(sindri_temperature_therm12_celsius);
    memcpy(&sindri_temperature_therm13_celsius, buf + index,
           sizeof(sindri_temperature_therm13_celsius));
    index += sizeof(sindri_temperature_therm13_celsius);
    memcpy(&sindri_temperature_therm14_celsius, buf + index,
           sizeof(sindri_temperature_therm14_celsius));
    index += sizeof(sindri_temperature_therm14_celsius);
  }
};

class Telemetry__Temperature__6_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm15_celsius;
  static_assert((sizeof(sindri_temperature_therm15_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm16_celsius;
  static_assert((sizeof(sindri_temperature_therm16_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm17_celsius;
  static_assert((sizeof(sindri_temperature_therm17_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__6;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 94;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm15_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm15_celsius);
  }
  void set_sindri_temperature_therm16_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm16_celsius);
  }
  void set_sindri_temperature_therm17_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm17_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm15_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm15_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm16_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm16_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm17_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm17_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm15_celsius,
           sizeof(sindri_temperature_therm15_celsius));
    *index += sizeof(sindri_temperature_therm15_celsius);
    memcpy(buf + *index, &sindri_temperature_therm16_celsius,
           sizeof(sindri_temperature_therm16_celsius));
    *index += sizeof(sindri_temperature_therm16_celsius);
    memcpy(buf + *index, &sindri_temperature_therm17_celsius,
           sizeof(sindri_temperature_therm17_celsius));
    *index += sizeof(sindri_temperature_therm17_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm15_celsius, buf + index,
           sizeof(sindri_temperature_therm15_celsius));
    index += sizeof(sindri_temperature_therm15_celsius);
    memcpy(&sindri_temperature_therm16_celsius, buf + index,
           sizeof(sindri_temperature_therm16_celsius));
    index += sizeof(sindri_temperature_therm16_celsius);
    memcpy(&sindri_temperature_therm17_celsius, buf + index,
           sizeof(sindri_temperature_therm17_celsius));
    index += sizeof(sindri_temperature_therm17_celsius);
  }
};

class Telemetry__Temperature__7_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_therm18_celsius;
  static_assert((sizeof(sindri_temperature_therm18_celsius) == 2),
                "invalid size");
  uint16_t sindri_temperature_therm19_celsius;
  static_assert((sizeof(sindri_temperature_therm19_celsius) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__7;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 95;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_therm18_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm18_celsius);
  }
  void set_sindri_temperature_therm19_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1350, &sindri_temperature_therm19_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_therm18_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm18_celsius, -200, 1350, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_therm19_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_therm19_celsius, -200, 1350, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_therm18_celsius,
           sizeof(sindri_temperature_therm18_celsius));
    *index += sizeof(sindri_temperature_therm18_celsius);
    memcpy(buf + *index, &sindri_temperature_therm19_celsius,
           sizeof(sindri_temperature_therm19_celsius));
    *index += sizeof(sindri_temperature_therm19_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_therm18_celsius, buf + index,
           sizeof(sindri_temperature_therm18_celsius));
    index += sizeof(sindri_temperature_therm18_celsius);
    memcpy(&sindri_temperature_therm19_celsius, buf + index,
           sizeof(sindri_temperature_therm19_celsius));
    index += sizeof(sindri_temperature_therm19_celsius);
  }
};

class
    Telemetry__CompensatingTemperature__1_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t sindri_compensatingtemperature_therm0_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm0_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm1_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm1_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm2_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm2_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm3_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm3_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm4_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm4_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm5_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm5_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm6_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm6_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__CompensatingTemperature__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 96;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_compensatingtemperature_therm0_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm0_celsius);
  }
  void set_sindri_compensatingtemperature_therm1_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm1_celsius);
  }
  void set_sindri_compensatingtemperature_therm2_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm2_celsius);
  }
  void set_sindri_compensatingtemperature_therm3_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm3_celsius);
  }
  void set_sindri_compensatingtemperature_therm4_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm4_celsius);
  }
  void set_sindri_compensatingtemperature_therm5_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm5_celsius);
  }
  void set_sindri_compensatingtemperature_therm6_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm6_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm0_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm0_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm1_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm1_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm2_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm2_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm3_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm3_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm4_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm4_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm5_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm5_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm6_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm6_celsius, -20, 106,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm0_celsius,
           sizeof(sindri_compensatingtemperature_therm0_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm0_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm1_celsius,
           sizeof(sindri_compensatingtemperature_therm1_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm1_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm2_celsius,
           sizeof(sindri_compensatingtemperature_therm2_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm2_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm3_celsius,
           sizeof(sindri_compensatingtemperature_therm3_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm3_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm4_celsius,
           sizeof(sindri_compensatingtemperature_therm4_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm4_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm5_celsius,
           sizeof(sindri_compensatingtemperature_therm5_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm5_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm6_celsius,
           sizeof(sindri_compensatingtemperature_therm6_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm6_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_compensatingtemperature_therm0_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm0_celsius));
    index += sizeof(sindri_compensatingtemperature_therm0_celsius);
    memcpy(&sindri_compensatingtemperature_therm1_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm1_celsius));
    index += sizeof(sindri_compensatingtemperature_therm1_celsius);
    memcpy(&sindri_compensatingtemperature_therm2_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm2_celsius));
    index += sizeof(sindri_compensatingtemperature_therm2_celsius);
    memcpy(&sindri_compensatingtemperature_therm3_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm3_celsius));
    index += sizeof(sindri_compensatingtemperature_therm3_celsius);
    memcpy(&sindri_compensatingtemperature_therm4_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm4_celsius));
    index += sizeof(sindri_compensatingtemperature_therm4_celsius);
    memcpy(&sindri_compensatingtemperature_therm5_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm5_celsius));
    index += sizeof(sindri_compensatingtemperature_therm5_celsius);
    memcpy(&sindri_compensatingtemperature_therm6_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm6_celsius));
    index += sizeof(sindri_compensatingtemperature_therm6_celsius);
  }
};

class
    Telemetry__CompensatingTemperature__2_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t sindri_compensatingtemperature_therm7_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm7_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm8_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm8_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm9_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm9_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm10_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm10_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm11_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm11_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm12_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm12_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm13_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm13_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__CompensatingTemperature__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 97;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_compensatingtemperature_therm7_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm7_celsius);
  }
  void set_sindri_compensatingtemperature_therm8_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm8_celsius);
  }
  void set_sindri_compensatingtemperature_therm9_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm9_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm10_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm10_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm11_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm11_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm12_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm12_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm13_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm13_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm7_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm7_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm8_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm8_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm9_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm9_celsius, -20, 106,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm10_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm10_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm11_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm11_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm12_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm12_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm13_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm13_celsius, -20,
                        106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm7_celsius,
           sizeof(sindri_compensatingtemperature_therm7_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm7_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm8_celsius,
           sizeof(sindri_compensatingtemperature_therm8_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm8_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm9_celsius,
           sizeof(sindri_compensatingtemperature_therm9_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm9_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm10_celsius,
           sizeof(sindri_compensatingtemperature_therm10_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm10_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm11_celsius,
           sizeof(sindri_compensatingtemperature_therm11_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm11_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm12_celsius,
           sizeof(sindri_compensatingtemperature_therm12_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm12_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm13_celsius,
           sizeof(sindri_compensatingtemperature_therm13_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm13_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_compensatingtemperature_therm7_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm7_celsius));
    index += sizeof(sindri_compensatingtemperature_therm7_celsius);
    memcpy(&sindri_compensatingtemperature_therm8_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm8_celsius));
    index += sizeof(sindri_compensatingtemperature_therm8_celsius);
    memcpy(&sindri_compensatingtemperature_therm9_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm9_celsius));
    index += sizeof(sindri_compensatingtemperature_therm9_celsius);
    memcpy(&sindri_compensatingtemperature_therm10_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm10_celsius));
    index += sizeof(sindri_compensatingtemperature_therm10_celsius);
    memcpy(&sindri_compensatingtemperature_therm11_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm11_celsius));
    index += sizeof(sindri_compensatingtemperature_therm11_celsius);
    memcpy(&sindri_compensatingtemperature_therm12_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm12_celsius));
    index += sizeof(sindri_compensatingtemperature_therm12_celsius);
    memcpy(&sindri_compensatingtemperature_therm13_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm13_celsius));
    index += sizeof(sindri_compensatingtemperature_therm13_celsius);
  }
};

class
    Telemetry__CompensatingTemperature__3_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint8_t sindri_compensatingtemperature_therm14_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm14_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm15_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm15_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm16_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm16_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm17_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm17_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm18_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm18_celsius) == 1),
                "invalid size");
  uint8_t sindri_compensatingtemperature_therm19_celsius;
  static_assert((sizeof(sindri_compensatingtemperature_therm19_celsius) == 1),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__CompensatingTemperature__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 98;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_sindri_compensatingtemperature_therm14_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm14_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm15_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm15_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm16_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm16_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm17_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm17_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm18_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm18_celsius);
  }
  void
  set_sindri_compensatingtemperature_therm19_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &sindri_compensatingtemperature_therm19_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm14_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm14_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm15_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm15_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm16_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm16_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm17_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm17_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm18_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm18_celsius, -20,
                        106, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_compensatingtemperature_therm19_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_compensatingtemperature_therm19_celsius, -20,
                        106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm14_celsius,
           sizeof(sindri_compensatingtemperature_therm14_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm14_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm15_celsius,
           sizeof(sindri_compensatingtemperature_therm15_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm15_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm16_celsius,
           sizeof(sindri_compensatingtemperature_therm16_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm16_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm17_celsius,
           sizeof(sindri_compensatingtemperature_therm17_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm17_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm18_celsius,
           sizeof(sindri_compensatingtemperature_therm18_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm18_celsius);
    memcpy(buf + *index, &sindri_compensatingtemperature_therm19_celsius,
           sizeof(sindri_compensatingtemperature_therm19_celsius));
    *index += sizeof(sindri_compensatingtemperature_therm19_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_compensatingtemperature_therm14_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm14_celsius));
    index += sizeof(sindri_compensatingtemperature_therm14_celsius);
    memcpy(&sindri_compensatingtemperature_therm15_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm15_celsius));
    index += sizeof(sindri_compensatingtemperature_therm15_celsius);
    memcpy(&sindri_compensatingtemperature_therm16_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm16_celsius));
    index += sizeof(sindri_compensatingtemperature_therm16_celsius);
    memcpy(&sindri_compensatingtemperature_therm17_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm17_celsius));
    index += sizeof(sindri_compensatingtemperature_therm17_celsius);
    memcpy(&sindri_compensatingtemperature_therm18_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm18_celsius));
    index += sizeof(sindri_compensatingtemperature_therm18_celsius);
    memcpy(&sindri_compensatingtemperature_therm19_celsius, buf + index,
           sizeof(sindri_compensatingtemperature_therm19_celsius));
    index += sizeof(sindri_compensatingtemperature_therm19_celsius);
  }
};

class Telemetry__Temperature__8_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_rtd0_celsius;
  static_assert((sizeof(sindri_temperature_rtd0_celsius) == 2), "invalid size");
  uint16_t sindri_temperature_rtd1_celsius;
  static_assert((sizeof(sindri_temperature_rtd1_celsius) == 2), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__8;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 99;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_rtd0_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 850, &sindri_temperature_rtd0_celsius);
  }
  void set_sindri_temperature_rtd1_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 850, &sindri_temperature_rtd1_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd0_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd0_celsius, -200, 850, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd1_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd1_celsius, -200, 850, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_rtd0_celsius,
           sizeof(sindri_temperature_rtd0_celsius));
    *index += sizeof(sindri_temperature_rtd0_celsius);
    memcpy(buf + *index, &sindri_temperature_rtd1_celsius,
           sizeof(sindri_temperature_rtd1_celsius));
    *index += sizeof(sindri_temperature_rtd1_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_rtd0_celsius, buf + index,
           sizeof(sindri_temperature_rtd0_celsius));
    index += sizeof(sindri_temperature_rtd0_celsius);
    memcpy(&sindri_temperature_rtd1_celsius, buf + index,
           sizeof(sindri_temperature_rtd1_celsius));
    index += sizeof(sindri_temperature_rtd1_celsius);
  }
};

class Telemetry__Temperature__9_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_rtd2_celsius;
  static_assert((sizeof(sindri_temperature_rtd2_celsius) == 2), "invalid size");
  uint16_t sindri_temperature_rtd3_celsius;
  static_assert((sizeof(sindri_temperature_rtd3_celsius) == 2), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__9;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 100;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_rtd2_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 850, &sindri_temperature_rtd2_celsius);
  }
  void set_sindri_temperature_rtd3_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 850, &sindri_temperature_rtd3_celsius);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd2_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd2_celsius, -200, 850, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd3_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd3_celsius, -200, 850, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_rtd2_celsius,
           sizeof(sindri_temperature_rtd2_celsius));
    *index += sizeof(sindri_temperature_rtd2_celsius);
    memcpy(buf + *index, &sindri_temperature_rtd3_celsius,
           sizeof(sindri_temperature_rtd3_celsius));
    *index += sizeof(sindri_temperature_rtd3_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_rtd2_celsius, buf + index,
           sizeof(sindri_temperature_rtd2_celsius));
    index += sizeof(sindri_temperature_rtd2_celsius);
    memcpy(&sindri_temperature_rtd3_celsius, buf + index,
           sizeof(sindri_temperature_rtd3_celsius));
    index += sizeof(sindri_temperature_rtd3_celsius);
  }
};

class Telemetry__Temperature__a_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_rtd0_ohm;
  static_assert((sizeof(sindri_temperature_rtd0_ohm) == 2), "invalid size");
  uint16_t sindri_temperature_rtd1_ohm;
  static_assert((sizeof(sindri_temperature_rtd1_ohm) == 2), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__a;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 101;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_rtd0_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5000, &sindri_temperature_rtd0_ohm);
  }
  void set_sindri_temperature_rtd1_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5000, &sindri_temperature_rtd1_ohm);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd0_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd0_ohm, 0, 5000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd1_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd1_ohm, 0, 5000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_rtd0_ohm,
           sizeof(sindri_temperature_rtd0_ohm));
    *index += sizeof(sindri_temperature_rtd0_ohm);
    memcpy(buf + *index, &sindri_temperature_rtd1_ohm,
           sizeof(sindri_temperature_rtd1_ohm));
    *index += sizeof(sindri_temperature_rtd1_ohm);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_rtd0_ohm, buf + index,
           sizeof(sindri_temperature_rtd0_ohm));
    index += sizeof(sindri_temperature_rtd0_ohm);
    memcpy(&sindri_temperature_rtd1_ohm, buf + index,
           sizeof(sindri_temperature_rtd1_ohm));
    index += sizeof(sindri_temperature_rtd1_ohm);
  }
};

class Telemetry__Temperature__b_from_Edda_Telemetry_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_temperature_rtd2_ohm;
  static_assert((sizeof(sindri_temperature_rtd2_ohm) == 2), "invalid size");
  uint16_t sindri_temperature_rtd3_ohm;
  static_assert((sizeof(sindri_temperature_rtd3_ohm) == 2), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__Temperature__b;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Telemetry;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 102;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_temperature_rtd2_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5000, &sindri_temperature_rtd2_ohm);
  }
  void set_sindri_temperature_rtd3_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5000, &sindri_temperature_rtd3_ohm);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd2_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd2_ohm, 0, 5000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_temperature_rtd3_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_temperature_rtd3_ohm, 0, 5000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_temperature_rtd2_ohm,
           sizeof(sindri_temperature_rtd2_ohm));
    *index += sizeof(sindri_temperature_rtd2_ohm);
    memcpy(buf + *index, &sindri_temperature_rtd3_ohm,
           sizeof(sindri_temperature_rtd3_ohm));
    *index += sizeof(sindri_temperature_rtd3_ohm);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_temperature_rtd2_ohm, buf + index,
           sizeof(sindri_temperature_rtd2_ohm));
    index += sizeof(sindri_temperature_rtd2_ohm);
    memcpy(&sindri_temperature_rtd3_ohm, buf + index,
           sizeof(sindri_temperature_rtd3_ohm));
    index += sizeof(sindri_temperature_rtd3_ohm);
  }
};

class Telemetry__Light__1_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t sindri_light_ambient_lux;
  static_assert((sizeof(sindri_light_ambient_lux) == 4), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__Light__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 103;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_light_ambient_lux(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 64000, &sindri_light_ambient_lux);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_light_ambient_lux() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_light_ambient_lux, 0, 64000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_light_ambient_lux,
           sizeof(sindri_light_ambient_lux));
    *index += sizeof(sindri_light_ambient_lux);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_light_ambient_lux, buf + index,
           sizeof(sindri_light_ambient_lux));
    index += sizeof(sindri_light_ambient_lux);
  }
};

class Telemetry__Light__2_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_light_humidity_percentage;
  static_assert((sizeof(sindri_light_humidity_percentage) == 2),
                "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::Telemetry__Light__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 104;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_light_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100, &sindri_light_humidity_percentage);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_light_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_light_humidity_percentage, 0, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_light_humidity_percentage,
           sizeof(sindri_light_humidity_percentage));
    *index += sizeof(sindri_light_humidity_percentage);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_light_humidity_percentage, buf + index,
           sizeof(sindri_light_humidity_percentage));
    index += sizeof(sindri_light_humidity_percentage);
  }
};

class Telemetry__Acceleration__1_from_Edda_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_acceleration_x_gforce;
  static_assert((sizeof(sindri_acceleration_x_gforce) == 2), "invalid size");
  uint16_t sindri_acceleration_y_gforce;
  static_assert((sizeof(sindri_acceleration_y_gforce) == 2), "invalid size");
  uint16_t sindri_acceleration_z_gforce;
  static_assert((sizeof(sindri_acceleration_z_gforce) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__Acceleration__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 105;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_acceleration_x_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &sindri_acceleration_x_gforce);
  }
  void set_sindri_acceleration_y_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &sindri_acceleration_y_gforce);
  }
  void set_sindri_acceleration_z_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &sindri_acceleration_z_gforce);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_acceleration_x_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_acceleration_x_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_acceleration_y_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_acceleration_y_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_acceleration_z_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_acceleration_z_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_acceleration_x_gforce,
           sizeof(sindri_acceleration_x_gforce));
    *index += sizeof(sindri_acceleration_x_gforce);
    memcpy(buf + *index, &sindri_acceleration_y_gforce,
           sizeof(sindri_acceleration_y_gforce));
    *index += sizeof(sindri_acceleration_y_gforce);
    memcpy(buf + *index, &sindri_acceleration_z_gforce,
           sizeof(sindri_acceleration_z_gforce));
    *index += sizeof(sindri_acceleration_z_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_acceleration_x_gforce, buf + index,
           sizeof(sindri_acceleration_x_gforce));
    index += sizeof(sindri_acceleration_x_gforce);
    memcpy(&sindri_acceleration_y_gforce, buf + index,
           sizeof(sindri_acceleration_y_gforce));
    index += sizeof(sindri_acceleration_y_gforce);
    memcpy(&sindri_acceleration_z_gforce, buf + index,
           sizeof(sindri_acceleration_z_gforce));
    index += sizeof(sindri_acceleration_z_gforce);
  }
};

class Telemetry__AmbientPressure__1_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_ambientpressure_top_bar;
  static_assert((sizeof(sindri_ambientpressure_top_bar) == 2), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::Telemetry__AmbientPressure__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 106;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_ambientpressure_top_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5, &sindri_ambientpressure_top_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_ambientpressure_top_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ambientpressure_top_bar, 0, 1.5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_ambientpressure_top_bar,
           sizeof(sindri_ambientpressure_top_bar));
    *index += sizeof(sindri_ambientpressure_top_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_ambientpressure_top_bar, buf + index,
           sizeof(sindri_ambientpressure_top_bar));
    index += sizeof(sindri_ambientpressure_top_bar);
  }
};

class
    Telemetry__AmbientPressure__2_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_ambientpressure_bottom_bar;
  static_assert((sizeof(sindri_ambientpressure_bottom_bar) == 2),
                "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::Telemetry__AmbientPressure__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 107;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_ambientpressure_bottom_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5, &sindri_ambientpressure_bottom_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_ambientpressure_bottom_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ambientpressure_bottom_bar, 0, 1.5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_ambientpressure_bottom_bar,
           sizeof(sindri_ambientpressure_bottom_bar));
    *index += sizeof(sindri_ambientpressure_bottom_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_ambientpressure_bottom_bar, buf + index,
           sizeof(sindri_ambientpressure_bottom_bar));
    index += sizeof(sindri_ambientpressure_bottom_bar);
  }
};

class
    Telemetry__TransducerPressure__1_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducerpressure_transducer0_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer0_bar) == 2),
                "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerPressure__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 108;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducerpressure_transducer0_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer0_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer0_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer0_bar, -10, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducerpressure_transducer0_bar,
           sizeof(sindri_transducerpressure_transducer0_bar));
    *index += sizeof(sindri_transducerpressure_transducer0_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducerpressure_transducer0_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer0_bar));
    index += sizeof(sindri_transducerpressure_transducer0_bar);
  }
};

class
    Telemetry__TransducerPressure__2_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducerpressure_transducer1_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer1_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer2_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer2_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer3_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer3_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerPressure__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 109;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducerpressure_transducer1_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer1_bar);
  }
  void set_sindri_transducerpressure_transducer2_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer2_bar);
  }
  void set_sindri_transducerpressure_transducer3_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer3_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer1_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer1_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer2_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer2_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer3_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer3_bar, -10, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducerpressure_transducer1_bar,
           sizeof(sindri_transducerpressure_transducer1_bar));
    *index += sizeof(sindri_transducerpressure_transducer1_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer2_bar,
           sizeof(sindri_transducerpressure_transducer2_bar));
    *index += sizeof(sindri_transducerpressure_transducer2_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer3_bar,
           sizeof(sindri_transducerpressure_transducer3_bar));
    *index += sizeof(sindri_transducerpressure_transducer3_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducerpressure_transducer1_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer1_bar));
    index += sizeof(sindri_transducerpressure_transducer1_bar);
    memcpy(&sindri_transducerpressure_transducer2_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer2_bar));
    index += sizeof(sindri_transducerpressure_transducer2_bar);
    memcpy(&sindri_transducerpressure_transducer3_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer3_bar));
    index += sizeof(sindri_transducerpressure_transducer3_bar);
  }
};

class
    Telemetry__TransducerPressure__3_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducerpressure_transducer0_max_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer0_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer1_max_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer1_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer2_max_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer2_max_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerPressure__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 110;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducerpressure_transducer0_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer0_max_bar);
  }
  void set_sindri_transducerpressure_transducer1_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer1_max_bar);
  }
  void set_sindri_transducerpressure_transducer2_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer2_max_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer0_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer0_max_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer1_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer1_max_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer2_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer2_max_bar, -10, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducerpressure_transducer0_max_bar,
           sizeof(sindri_transducerpressure_transducer0_max_bar));
    *index += sizeof(sindri_transducerpressure_transducer0_max_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer1_max_bar,
           sizeof(sindri_transducerpressure_transducer1_max_bar));
    *index += sizeof(sindri_transducerpressure_transducer1_max_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer2_max_bar,
           sizeof(sindri_transducerpressure_transducer2_max_bar));
    *index += sizeof(sindri_transducerpressure_transducer2_max_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducerpressure_transducer0_max_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer0_max_bar));
    index += sizeof(sindri_transducerpressure_transducer0_max_bar);
    memcpy(&sindri_transducerpressure_transducer1_max_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer1_max_bar));
    index += sizeof(sindri_transducerpressure_transducer1_max_bar);
    memcpy(&sindri_transducerpressure_transducer2_max_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer2_max_bar));
    index += sizeof(sindri_transducerpressure_transducer2_max_bar);
  }
};

class
    Telemetry__TransducerPressure__4_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducerpressure_transducer3_max_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer3_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer0_min_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer0_min_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer1_min_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer1_min_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerPressure__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 111;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducerpressure_transducer3_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer3_max_bar);
  }
  void set_sindri_transducerpressure_transducer0_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer0_min_bar);
  }
  void set_sindri_transducerpressure_transducer1_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer1_min_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer3_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer3_max_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer0_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer0_min_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer1_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer1_min_bar, -10, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducerpressure_transducer3_max_bar,
           sizeof(sindri_transducerpressure_transducer3_max_bar));
    *index += sizeof(sindri_transducerpressure_transducer3_max_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer0_min_bar,
           sizeof(sindri_transducerpressure_transducer0_min_bar));
    *index += sizeof(sindri_transducerpressure_transducer0_min_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer1_min_bar,
           sizeof(sindri_transducerpressure_transducer1_min_bar));
    *index += sizeof(sindri_transducerpressure_transducer1_min_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducerpressure_transducer3_max_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer3_max_bar));
    index += sizeof(sindri_transducerpressure_transducer3_max_bar);
    memcpy(&sindri_transducerpressure_transducer0_min_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer0_min_bar));
    index += sizeof(sindri_transducerpressure_transducer0_min_bar);
    memcpy(&sindri_transducerpressure_transducer1_min_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer1_min_bar));
    index += sizeof(sindri_transducerpressure_transducer1_min_bar);
  }
};

class
    Telemetry__TransducerPressure__5_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducerpressure_transducer2_min_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer2_min_bar) == 2),
                "invalid size");
  uint16_t sindri_transducerpressure_transducer3_min_bar;
  static_assert((sizeof(sindri_transducerpressure_transducer3_min_bar) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerPressure__5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 112;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducerpressure_transducer2_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer2_min_bar);
  }
  void set_sindri_transducerpressure_transducer3_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducerpressure_transducer3_min_bar);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer2_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer2_min_bar, -10, 100,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducerpressure_transducer3_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducerpressure_transducer3_min_bar, -10, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducerpressure_transducer2_min_bar,
           sizeof(sindri_transducerpressure_transducer2_min_bar));
    *index += sizeof(sindri_transducerpressure_transducer2_min_bar);
    memcpy(buf + *index, &sindri_transducerpressure_transducer3_min_bar,
           sizeof(sindri_transducerpressure_transducer3_min_bar));
    *index += sizeof(sindri_transducerpressure_transducer3_min_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducerpressure_transducer2_min_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer2_min_bar));
    index += sizeof(sindri_transducerpressure_transducer2_min_bar);
    memcpy(&sindri_transducerpressure_transducer3_min_bar, buf + index,
           sizeof(sindri_transducerpressure_transducer3_min_bar));
    index += sizeof(sindri_transducerpressure_transducer3_min_bar);
  }
};

class
    Telemetry__TransducerVoltage__1_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducervoltage_transducer0_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer0_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer1_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer1_volt) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__TransducerVoltage__1;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 113;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducervoltage_transducer0_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer0_volt);
  }
  void set_sindri_transducervoltage_transducer1_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer1_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer0_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer0_volt, -0.1, 5.1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer1_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer1_volt, -0.1, 5.1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducervoltage_transducer0_volt,
           sizeof(sindri_transducervoltage_transducer0_volt));
    *index += sizeof(sindri_transducervoltage_transducer0_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer1_volt,
           sizeof(sindri_transducervoltage_transducer1_volt));
    *index += sizeof(sindri_transducervoltage_transducer1_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducervoltage_transducer0_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer0_volt));
    index += sizeof(sindri_transducervoltage_transducer0_volt);
    memcpy(&sindri_transducervoltage_transducer1_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer1_volt));
    index += sizeof(sindri_transducervoltage_transducer1_volt);
  }
};

class
    Telemetry__TransducerVoltage__2_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducervoltage_transducer2_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer2_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer3_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer3_volt) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__TransducerVoltage__2;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 114;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducervoltage_transducer2_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer2_volt);
  }
  void set_sindri_transducervoltage_transducer3_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer3_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer2_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer2_volt, -0.1, 5.1,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer3_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer3_volt, -0.1, 5.1,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducervoltage_transducer2_volt,
           sizeof(sindri_transducervoltage_transducer2_volt));
    *index += sizeof(sindri_transducervoltage_transducer2_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer3_volt,
           sizeof(sindri_transducervoltage_transducer3_volt));
    *index += sizeof(sindri_transducervoltage_transducer3_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducervoltage_transducer2_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer2_volt));
    index += sizeof(sindri_transducervoltage_transducer2_volt);
    memcpy(&sindri_transducervoltage_transducer3_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer3_volt));
    index += sizeof(sindri_transducervoltage_transducer3_volt);
  }
};

class
    Telemetry__TransducerVoltage__3_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducervoltage_transducer0_max_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer0_max_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer1_max_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer1_max_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer2_max_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer2_max_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__TransducerVoltage__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 115;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducervoltage_transducer0_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer0_max_volt);
  }
  void set_sindri_transducervoltage_transducer1_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer1_max_volt);
  }
  void set_sindri_transducervoltage_transducer2_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer2_max_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer0_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer0_max_volt, -0.1,
                        5.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer1_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer1_max_volt, -0.1,
                        5.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer2_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer2_max_volt, -0.1,
                        5.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducervoltage_transducer0_max_volt,
           sizeof(sindri_transducervoltage_transducer0_max_volt));
    *index += sizeof(sindri_transducervoltage_transducer0_max_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer1_max_volt,
           sizeof(sindri_transducervoltage_transducer1_max_volt));
    *index += sizeof(sindri_transducervoltage_transducer1_max_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer2_max_volt,
           sizeof(sindri_transducervoltage_transducer2_max_volt));
    *index += sizeof(sindri_transducervoltage_transducer2_max_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducervoltage_transducer0_max_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer0_max_volt));
    index += sizeof(sindri_transducervoltage_transducer0_max_volt);
    memcpy(&sindri_transducervoltage_transducer1_max_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer1_max_volt));
    index += sizeof(sindri_transducervoltage_transducer1_max_volt);
    memcpy(&sindri_transducervoltage_transducer2_max_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer2_max_volt));
    index += sizeof(sindri_transducervoltage_transducer2_max_volt);
  }
};

class
    Telemetry__TransducerVoltage__4_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducervoltage_transducer3_max_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer3_max_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer0_min_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer0_min_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer1_min_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer1_min_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Telemetry__TransducerVoltage__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 116;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducervoltage_transducer3_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer3_max_volt);
  }
  void set_sindri_transducervoltage_transducer0_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer0_min_volt);
  }
  void set_sindri_transducervoltage_transducer1_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer1_min_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer3_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer3_max_volt, -0.1,
                        5.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer0_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer0_min_volt, -0.1,
                        5.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer1_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer1_min_volt, -0.1,
                        5.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducervoltage_transducer3_max_volt,
           sizeof(sindri_transducervoltage_transducer3_max_volt));
    *index += sizeof(sindri_transducervoltage_transducer3_max_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer0_min_volt,
           sizeof(sindri_transducervoltage_transducer0_min_volt));
    *index += sizeof(sindri_transducervoltage_transducer0_min_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer1_min_volt,
           sizeof(sindri_transducervoltage_transducer1_min_volt));
    *index += sizeof(sindri_transducervoltage_transducer1_min_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducervoltage_transducer3_max_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer3_max_volt));
    index += sizeof(sindri_transducervoltage_transducer3_max_volt);
    memcpy(&sindri_transducervoltage_transducer0_min_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer0_min_volt));
    index += sizeof(sindri_transducervoltage_transducer0_min_volt);
    memcpy(&sindri_transducervoltage_transducer1_min_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer1_min_volt));
    index += sizeof(sindri_transducervoltage_transducer1_min_volt);
  }
};

class
    Telemetry__TransducerVoltage__5_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducervoltage_transducer2_min_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer2_min_volt) == 2),
                "invalid size");
  uint16_t sindri_transducervoltage_transducer3_min_volt;
  static_assert((sizeof(sindri_transducervoltage_transducer3_min_volt) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::Telemetry__TransducerVoltage__5;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 117;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducervoltage_transducer2_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer2_min_volt);
  }
  void set_sindri_transducervoltage_transducer3_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &sindri_transducervoltage_transducer3_min_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer2_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer2_min_volt, -0.1,
                        5.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducervoltage_transducer3_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducervoltage_transducer3_min_volt, -0.1,
                        5.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducervoltage_transducer2_min_volt,
           sizeof(sindri_transducervoltage_transducer2_min_volt));
    *index += sizeof(sindri_transducervoltage_transducer2_min_volt);
    memcpy(buf + *index, &sindri_transducervoltage_transducer3_min_volt,
           sizeof(sindri_transducervoltage_transducer3_min_volt));
    *index += sizeof(sindri_transducervoltage_transducer3_min_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducervoltage_transducer2_min_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer2_min_volt));
    index += sizeof(sindri_transducervoltage_transducer2_min_volt);
    memcpy(&sindri_transducervoltage_transducer3_min_volt, buf + index,
           sizeof(sindri_transducervoltage_transducer3_min_volt));
    index += sizeof(sindri_transducervoltage_transducer3_min_volt);
  }
};

class
    Telemetry__ElectronicsVoltage__3_from_Edda_Pressure_Top_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_top_electronicsvoltage_adcref_volt;
  static_assert(
      (sizeof(edda_pressureboard_top_electronicsvoltage_adcref_volt) == 2),
      "invalid size");
  uint16_t edda_pressureboard_top_electronicsvoltage_adc5v_volt;
  static_assert((sizeof(edda_pressureboard_top_electronicsvoltage_adc5v_volt) ==
                 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsVoltage__3;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Top;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 118;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_top_electronicsvoltage_adcref_volt(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &edda_pressureboard_top_electronicsvoltage_adcref_volt);
  }
  void set_edda_pressureboard_top_electronicsvoltage_adc5v_volt(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 5.1,
                        &edda_pressureboard_top_electronicsvoltage_adc5v_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_electronicsvoltage_adcref_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_electronicsvoltage_adcref_volt,
                        -0.1, 5.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_top_electronicsvoltage_adc5v_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_top_electronicsvoltage_adc5v_volt,
                        -0.1, 5.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_pressureboard_top_electronicsvoltage_adcref_volt,
           sizeof(edda_pressureboard_top_electronicsvoltage_adcref_volt));
    *index += sizeof(edda_pressureboard_top_electronicsvoltage_adcref_volt);
    memcpy(buf + *index, &edda_pressureboard_top_electronicsvoltage_adc5v_volt,
           sizeof(edda_pressureboard_top_electronicsvoltage_adc5v_volt));
    *index += sizeof(edda_pressureboard_top_electronicsvoltage_adc5v_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_top_electronicsvoltage_adcref_volt, buf + index,
           sizeof(edda_pressureboard_top_electronicsvoltage_adcref_volt));
    index += sizeof(edda_pressureboard_top_electronicsvoltage_adcref_volt);
    memcpy(&edda_pressureboard_top_electronicsvoltage_adc5v_volt, buf + index,
           sizeof(edda_pressureboard_top_electronicsvoltage_adc5v_volt));
    index += sizeof(edda_pressureboard_top_electronicsvoltage_adc5v_volt);
  }
};

class
    Telemetry__ElectronicsVoltage__4_from_Edda_Pressure_Bottom_to_Ground_Controller
    : public MessageBase {
public:
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_pressureboard_bottom_electronicsvoltage_adcref_volt;
  static_assert(
      (sizeof(edda_pressureboard_bottom_electronicsvoltage_adcref_volt) == 2),
      "invalid size");
  uint16_t edda_pressureboard_bottom_electronicsvoltage_adc5v_volt;
  static_assert(
      (sizeof(edda_pressureboard_bottom_electronicsvoltage_adc5v_volt) == 2),
      "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ElectronicsVoltage__4;
  enum EDDA::nodes sender = EDDA::nodes::Edda_Pressure_Bottom;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 119;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_pressureboard_bottom_electronicsvoltage_adcref_volt(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -0.1, 5.1,
        &edda_pressureboard_bottom_electronicsvoltage_adcref_volt);
  }
  void set_edda_pressureboard_bottom_electronicsvoltage_adc5v_volt(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -0.1, 5.1,
        &edda_pressureboard_bottom_electronicsvoltage_adc5v_volt);
  }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_pressureboard_bottom_electronicsvoltage_adcref_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_pressureboard_bottom_electronicsvoltage_adcref_volt, -0.1, 5.1,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_pressureboard_bottom_electronicsvoltage_adc5v_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_pressureboard_bottom_electronicsvoltage_adc5v_volt,
                        -0.1, 5.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_electronicsvoltage_adcref_volt,
           sizeof(edda_pressureboard_bottom_electronicsvoltage_adcref_volt));
    *index += sizeof(edda_pressureboard_bottom_electronicsvoltage_adcref_volt);
    memcpy(buf + *index,
           &edda_pressureboard_bottom_electronicsvoltage_adc5v_volt,
           sizeof(edda_pressureboard_bottom_electronicsvoltage_adc5v_volt));
    *index += sizeof(edda_pressureboard_bottom_electronicsvoltage_adc5v_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_pressureboard_bottom_electronicsvoltage_adcref_volt,
           buf + index,
           sizeof(edda_pressureboard_bottom_electronicsvoltage_adcref_volt));
    index += sizeof(edda_pressureboard_bottom_electronicsvoltage_adcref_volt);
    memcpy(&edda_pressureboard_bottom_electronicsvoltage_adc5v_volt,
           buf + index,
           sizeof(edda_pressureboard_bottom_electronicsvoltage_adc5v_volt));
    index += sizeof(edda_pressureboard_bottom_electronicsvoltage_adc5v_volt);
  }
};

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
void rx(PowerCAN_SetDebugMode_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_SetDebugMode_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerCAN_SetDebugMode_from_Ground_Controller_to_Edda_Controller msg);
void rx(PowerCAN_SetDebugMode_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(PowerCAN_GetState_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_GetState_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerCAN_GetState_from_Ground_Controller_to_Edda_Controller msg);
void rx(PowerCAN_GetState_from_Ground_Controller_to_Edda_Controller msg,
        void *misc);
void rx(
    PowerCAN_TransitionRequest_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    PowerCAN_TransitionRequest_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(
    PowerCAN_TransitionRequest_from_Ground_Controller_to_Edda_Controller msg);
void rx(
    PowerCAN_TransitionRequest_from_Ground_Controller_to_Edda_Controller msg,
    void *misc);
void rx(PowerCAN_Hello_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_Hello_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(PowerCAN_CurrentState_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_CurrentState_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    PowerCAN_TransitionResponse_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    PowerCAN_TransitionResponse_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(PowerCAN_CheckResult_from_Edda_Controller_to_Ground_Controller msg);
void rx(PowerCAN_CheckResult_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Frame_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(TelemetryMeta_Frame_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Frame_from_Edda_Controller_to_Ground_Controller msg);
void rx(TelemetryMeta_Frame_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Frame_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TelemetryMeta_Frame_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Frame_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TelemetryMeta_Frame_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Time_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(TelemetryMeta_Time_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Time_from_Edda_Controller_to_Ground_Controller msg);
void rx(TelemetryMeta_Time_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Time_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(TelemetryMeta_Time_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMeta_Time_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(TelemetryMeta_Time_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__PowerInput__1_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__PowerInput__1_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__PowerInput__2_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerInput__2_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__PowerInput__3_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerInput__3_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__PowerInput__4_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerInput__4_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__PowerInput__5_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerInput__5_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__PowerInput__6_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(
    Telemetry__PowerInput__6_from_Edda_Pressure_Top_to_Ground_Controller msg,
    void *misc);
void rx(Telemetry__PowerInput__7_from_Edda_Pressure_Bottom_to_Ground_Controller
            msg);
void rx(
    Telemetry__PowerInput__7_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__ElectronicsVoltage__1_from_Edda_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsVoltage__1_from_Edda_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ElectronicsVoltage__2_from_Edda_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsVoltage__2_from_Edda_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__PowerOutput__1_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerOutput__1_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__PowerOutput__2_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerOutput__2_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__PowerOutput__3_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__PowerOutput__3_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__ElectronicsTemperature__1_from_Edda_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsTemperature__1_from_Edda_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ElectronicsTemperature__2_from_Edda_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsTemperature__2_from_Edda_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(Telemetry__LoopTime__1_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__1_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__2_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__2_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__3_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__3_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__4_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__4_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__5_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__5_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__6_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__6_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__7_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__7_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__8_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__8_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__9_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__9_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__a_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__a_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__b_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__b_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__c_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__c_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__d_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__d_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__e_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__e_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__LoopTime__f_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__f_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__LoopTime__10_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__10_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__LoopTime__11_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__11_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__LoopTime__12_from_Edda_Pressure_Top_to_Ground_Controller msg);
void rx(Telemetry__LoopTime__12_from_Edda_Pressure_Top_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__LoopTime__13_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    Telemetry__LoopTime__13_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__LoopTime__14_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    Telemetry__LoopTime__14_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__LoopTime__15_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    Telemetry__LoopTime__15_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__LoopTime__16_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    Telemetry__LoopTime__16_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__LoopTime__17_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    Telemetry__LoopTime__17_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__LoopTime__18_from_Edda_Pressure_Bottom_to_Ground_Controller msg);
void rx(
    Telemetry__LoopTime__18_from_Edda_Pressure_Bottom_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__ElectronicsTemperature__3_from_Edda_Telemetry_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsTemperature__3_from_Edda_Telemetry_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ElectronicsTemperature__4_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsTemperature__4_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ElectronicsTemperature__5_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsTemperature__5_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg,
    void *misc);
void rx(Telemetry__Temperature__1_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__1_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__2_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__2_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__3_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__3_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__4_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__4_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__5_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__5_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__6_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__6_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__7_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__7_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__CompensatingTemperature__1_from_Edda_Telemetry_to_Ground_Controller
        msg);
void rx(
    Telemetry__CompensatingTemperature__1_from_Edda_Telemetry_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__CompensatingTemperature__2_from_Edda_Telemetry_to_Ground_Controller
        msg);
void rx(
    Telemetry__CompensatingTemperature__2_from_Edda_Telemetry_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__CompensatingTemperature__3_from_Edda_Telemetry_to_Ground_Controller
        msg);
void rx(
    Telemetry__CompensatingTemperature__3_from_Edda_Telemetry_to_Ground_Controller
        msg,
    void *misc);
void rx(Telemetry__Temperature__8_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__8_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__9_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__9_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__a_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__a_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Temperature__b_from_Edda_Telemetry_to_Ground_Controller msg);
void rx(Telemetry__Temperature__b_from_Edda_Telemetry_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Light__1_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__Light__1_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(Telemetry__Light__2_from_Edda_Controller_to_Ground_Controller msg);
void rx(Telemetry__Light__2_from_Edda_Controller_to_Ground_Controller msg,
        void *misc);
void rx(
    Telemetry__Acceleration__1_from_Edda_Controller_to_Ground_Controller msg);
void rx(
    Telemetry__Acceleration__1_from_Edda_Controller_to_Ground_Controller msg,
    void *misc);
void rx(
    Telemetry__AmbientPressure__1_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__AmbientPressure__1_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__AmbientPressure__2_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg);
void rx(
    Telemetry__AmbientPressure__2_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerPressure__1_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerPressure__1_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerPressure__2_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerPressure__2_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerPressure__3_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerPressure__3_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerPressure__4_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerPressure__4_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerPressure__5_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerPressure__5_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerVoltage__1_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerVoltage__1_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerVoltage__2_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerVoltage__2_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerVoltage__3_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerVoltage__3_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerVoltage__4_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerVoltage__4_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerVoltage__5_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerVoltage__5_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ElectronicsVoltage__3_from_Edda_Pressure_Top_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsVoltage__3_from_Edda_Pressure_Top_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ElectronicsVoltage__4_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg);
void rx(
    Telemetry__ElectronicsVoltage__4_from_Edda_Pressure_Bottom_to_Ground_Controller
        msg,
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
