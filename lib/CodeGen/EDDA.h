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
  checksum = 0,
  channel = 1,
  system_state = 2,
  output_state = 3,
  edda_signature = 4,
  request = 5,
  response = 6,
  source = 7,
  status = 8,
  year = 9,
  month = 10,
  day = 11,
  action = 12,
  engine_state = 13,
  uptime_ms = 14,
  destination_node = 15,
  latency_us = 16,
  time_us = 17,
  truncated_frame_number = 18,
  edda_controller_ambient_pressure_bar = 19,
  edda_controller_can_rx_size_rate_byte = 20,
  edda_controller_can_tx_size_rate_byte = 21,
  edda_controller_latency_edda_ground_time_millisecond = 22,
  edda_controller_latency_edda_temperature_1_time_millisecond = 23,
  edda_controller_latency_edda_temperature_2_time_millisecond = 24,
  edda_controller_latency_edda_transducer_time_millisecond = 25,
  edda_controller_timing_time_freq_hertz = 26,
  edda_controller_timing_time_max_microsecond = 27,
  edda_controller_timing_time_microsecond = 28,
  edda_controller_timing_time_min_microsecond = 29,
  edda_controller_can_rx_time_max_microsecond = 30,
  edda_controller_can_rx_time_microsecond = 31,
  edda_controller_board_temperature_celsius = 32,
  edda_controller_can_rx_time_min_microsecond = 33,
  edda_controller_can_tx_time_max_microsecond = 34,
  edda_controller_humidity_sensor_temperature_celsius = 35,
  edda_controller_can_tx_time_microsecond = 36,
  edda_controller_can_tx_time_min_microsecond = 37,
  edda_controller_imu_temperature_celsius = 38,
  edda_controller_input_current_ampere = 39,
  edda_controller_input_current_max_ampere = 40,
  edda_controller_internal_temperature_celsius = 41,
  edda_controller_input_current_min_ampere = 42,
  edda_controller_input_voltage_max_volt = 43,
  edda_controller_pressure_sensor_temperature_celsius = 44,
  edda_controller_input_voltage_min_volt = 45,
  edda_controller_input_voltage_volt = 46,
  edda_controller_relative_humidity_percentage = 47,
  edda_controller_latency_edda_ground_time_max_millisecond = 48,
  edda_controller_latency_edda_ground_time_min_millisecond = 49,
  edda_controller_latency_edda_temperature_1_time_max_millisecond = 50,
  edda_controller_latency_edda_temperature_1_time_min_millisecond = 51,
  edda_controller_latency_edda_temperature_2_time_max_millisecond = 52,
  edda_controller_latency_edda_temperature_2_time_min_millisecond = 53,
  edda_controller_latency_edda_transducer_time_max_millisecond = 54,
  edda_controller_latency_edda_transducer_time_min_millisecond = 55,
  edda_controller_x_acceleration_gforce = 56,
  edda_controller_x_acceleration_max_gforce = 57,
  edda_controller_x_acceleration_min_gforce = 58,
  edda_controller_y_acceleration_gforce = 59,
  edda_controller_y_acceleration_max_gforce = 60,
  edda_controller_y_acceleration_min_gforce = 61,
  edda_controller_z_acceleration_gforce = 62,
  edda_controller_z_acceleration_max_gforce = 63,
  edda_controller_z_acceleration_min_gforce = 64,
  sindri_bleed_valve_current_ampere = 65,
  sindri_bleed_valve_power_watt = 66,
  sindri_main_valve_actuation_distance_millimeter = 67,
  sindri_bleed_valve_voltage_volt = 68,
  sindri_ignition_current_ampere = 69,
  sindri_ignition_power_watt = 70,
  sindri_ignition_voltage_volt = 71,
  sindri_main_valve_current_ampere = 72,
  sindri_main_valve_power_watt = 73,
  sindri_main_valve_voltage_volt = 74,
  sindri_oxidizer_tank_weight_kilogram = 75,
  sindri_bleed_valve_estimation_current_ampere = 76,
  sindri_bleed_valve_estimation_power_watt = 77,
  sindri_bleed_valve_estimation_resistance_ohm = 78,
  sindri_bleed_valve_estimation_voltage_volt = 79,
  sindri_ignition_estimation_current_ampere = 80,
  sindri_ignition_estimation_power_watt = 81,
  sindri_ignition_estimation_resistance_ohm = 82,
  sindri_ignition_estimation_voltage_volt = 83,
  sindri_main_valve_estimation_current_ampere = 84,
  sindri_main_valve_estimation_power_watt = 85,
  sindri_main_valve_estimation_resistance_ohm = 86,
  sindri_main_valve_estimation_voltage_volt = 87,
  edda_ground_ambient_pressure_bar = 88,
  edda_ground_can_rx_size_rate_byte = 89,
  edda_ground_can_tx_size_rate_byte = 90,
  edda_ground_latency_edda_controller_time_millisecond = 91,
  edda_ground_latency_edda_temperature_1_time_millisecond = 92,
  edda_ground_latency_edda_temperature_2_time_millisecond = 93,
  edda_ground_latency_edda_transducer_time_millisecond = 94,
  edda_ground_timing_time_freq_hertz = 95,
  edda_ground_timing_time_max_microsecond = 96,
  edda_ground_timing_time_microsecond = 97,
  edda_ground_timing_time_min_microsecond = 98,
  edda_ground_gps_latitude_location = 99,
  edda_ground_board_temperature_celsius = 100,
  edda_ground_gps_longitude_location = 101,
  edda_ground_humidity_sensor_temperature_celsius = 102,
  edda_ground_can_rx_time_max_microsecond = 103,
  edda_ground_can_rx_time_microsecond = 104,
  edda_ground_imu_temperature_celsius = 105,
  edda_ground_can_rx_time_min_microsecond = 106,
  edda_ground_can_tx_time_max_microsecond = 107,
  edda_ground_internal_temperature_celsius = 108,
  edda_ground_can_tx_time_microsecond = 109,
  edda_ground_can_tx_time_min_microsecond = 110,
  edda_ground_pressure_sensor_temperature_celsius = 111,
  edda_ground_input_current_ampere = 112,
  edda_ground_input_current_max_ampere = 113,
  edda_ground_relative_humidity_percentage = 114,
  edda_ground_input_current_min_ampere = 115,
  edda_ground_input_voltage_max_volt = 116,
  edda_ground_input_voltage_min_volt = 117,
  edda_ground_input_voltage_volt = 118,
  edda_ground_latency_edda_controller_time_max_millisecond = 119,
  edda_ground_latency_edda_controller_time_min_millisecond = 120,
  edda_ground_latency_edda_temperature_1_time_max_millisecond = 121,
  edda_ground_latency_edda_temperature_1_time_min_millisecond = 122,
  edda_ground_latency_edda_temperature_2_time_max_millisecond = 123,
  edda_ground_latency_edda_temperature_2_time_min_millisecond = 124,
  edda_ground_latency_edda_transducer_time_max_millisecond = 125,
  edda_ground_latency_edda_transducer_time_min_millisecond = 126,
  edda_ground_x_acceleration_gforce = 127,
  edda_ground_x_acceleration_max_gforce = 128,
  edda_ground_x_acceleration_min_gforce = 129,
  edda_ground_y_acceleration_gforce = 130,
  edda_ground_y_acceleration_max_gforce = 131,
  edda_ground_y_acceleration_min_gforce = 132,
  edda_ground_z_acceleration_gforce = 133,
  edda_ground_z_acceleration_max_gforce = 134,
  edda_ground_z_acceleration_min_gforce = 135,
  edda_temperature_1_ambient_pressure_bar = 136,
  edda_temperature_1_can_rx_size_rate_byte = 137,
  edda_temperature_1_compensation_0_temperature_celsius = 138,
  edda_temperature_1_can_tx_size_rate_byte = 139,
  edda_temperature_1_latency_edda_controller_time_millisecond = 140,
  edda_temperature_1_compensation_1_temperature_celsius = 141,
  edda_temperature_1_latency_edda_ground_time_millisecond = 142,
  edda_temperature_1_latency_edda_temperature_2_time_millisecond = 143,
  edda_temperature_1_latency_edda_transducer_time_millisecond = 144,
  edda_temperature_1_timing_time_freq_hertz = 145,
  edda_temperature_1_timing_time_max_microsecond = 146,
  edda_temperature_1_timing_time_microsecond = 147,
  edda_temperature_1_timing_time_min_microsecond = 148,
  edda_temperature_1_can_rx_time_max_microsecond = 149,
  edda_temperature_1_can_rx_time_microsecond = 150,
  edda_temperature_1_board_temperature_celsius = 151,
  edda_temperature_1_can_rx_time_min_microsecond = 152,
  edda_temperature_1_can_tx_time_max_microsecond = 153,
  edda_temperature_1_humidity_sensor_temperature_celsius = 154,
  edda_temperature_1_can_tx_time_microsecond = 155,
  edda_temperature_1_can_tx_time_min_microsecond = 156,
  edda_temperature_1_imu_temperature_celsius = 157,
  edda_temperature_1_input_current_ampere = 158,
  edda_temperature_1_input_current_max_ampere = 159,
  edda_temperature_1_internal_temperature_celsius = 160,
  edda_temperature_1_input_current_min_ampere = 161,
  edda_temperature_1_input_voltage_max_volt = 162,
  edda_temperature_1_pressure_sensor_temperature_celsius = 163,
  edda_temperature_1_input_voltage_min_volt = 164,
  edda_temperature_1_input_voltage_volt = 165,
  edda_temperature_1_relative_humidity_percentage = 166,
  edda_temperature_1_latency_edda_controller_time_max_millisecond = 167,
  edda_temperature_1_latency_edda_controller_time_min_millisecond = 168,
  edda_temperature_1_latency_edda_ground_time_max_millisecond = 169,
  edda_temperature_1_latency_edda_ground_time_min_millisecond = 170,
  edda_temperature_1_latency_edda_temperature_2_time_max_millisecond = 171,
  edda_temperature_1_latency_edda_temperature_2_time_min_millisecond = 172,
  edda_temperature_1_latency_edda_transducer_time_max_millisecond = 173,
  edda_temperature_1_latency_edda_transducer_time_min_millisecond = 174,
  edda_temperature_1_x_acceleration_gforce = 175,
  edda_temperature_1_x_acceleration_max_gforce = 176,
  edda_temperature_1_x_acceleration_min_gforce = 177,
  edda_temperature_1_y_acceleration_gforce = 178,
  edda_temperature_1_y_acceleration_max_gforce = 179,
  edda_temperature_1_y_acceleration_min_gforce = 180,
  edda_temperature_1_z_acceleration_gforce = 181,
  edda_temperature_1_z_acceleration_max_gforce = 182,
  edda_temperature_1_z_acceleration_min_gforce = 183,
  sindri_rtd_01_resistance_ohm = 184,
  sindri_rtd_01_voltage_volt = 185,
  sindri_rtd_02_resistance_ohm = 186,
  sindri_rtd_02_voltage_volt = 187,
  sindri_therm_09_voltage_volt = 188,
  sindri_therm_10_voltage_volt = 189,
  sindri_therm_11_voltage_volt = 190,
  sindri_therm_12_voltage_volt = 191,
  sindri_rtd_01_temperature_celsius = 192,
  sindri_rtd_02_temperature_celsius = 193,
  sindri_therm_09_temperature_celsius = 194,
  sindri_therm_10_temperature_celsius = 195,
  sindri_therm_11_temperature_celsius = 196,
  sindri_therm_12_temperature_celsius = 197,
  edda_temperature_2_ambient_pressure_bar = 198,
  edda_temperature_2_can_rx_size_rate_byte = 199,
  edda_temperature_2_compensation_0_temperature_celsius = 200,
  edda_temperature_2_can_tx_size_rate_byte = 201,
  edda_temperature_2_latency_edda_controller_time_millisecond = 202,
  edda_temperature_2_compensation_1_temperature_celsius = 203,
  edda_temperature_2_latency_edda_ground_time_millisecond = 204,
  edda_temperature_2_latency_edda_temperature_1_time_millisecond = 205,
  edda_temperature_2_latency_edda_transducer_time_millisecond = 206,
  edda_temperature_2_timing_time_freq_hertz = 207,
  edda_temperature_2_timing_time_max_microsecond = 208,
  edda_temperature_2_timing_time_microsecond = 209,
  edda_temperature_2_timing_time_min_microsecond = 210,
  edda_temperature_2_can_rx_time_max_microsecond = 211,
  edda_temperature_2_can_rx_time_microsecond = 212,
  edda_temperature_2_board_temperature_celsius = 213,
  edda_temperature_2_can_rx_time_min_microsecond = 214,
  edda_temperature_2_can_tx_time_max_microsecond = 215,
  edda_temperature_2_humidity_sensor_temperature_celsius = 216,
  edda_temperature_2_can_tx_time_microsecond = 217,
  edda_temperature_2_can_tx_time_min_microsecond = 218,
  edda_temperature_2_imu_temperature_celsius = 219,
  edda_temperature_2_input_current_ampere = 220,
  edda_temperature_2_input_current_max_ampere = 221,
  edda_temperature_2_internal_temperature_celsius = 222,
  edda_temperature_2_input_current_min_ampere = 223,
  edda_temperature_2_input_voltage_max_volt = 224,
  edda_temperature_2_pressure_sensor_temperature_celsius = 225,
  edda_temperature_2_input_voltage_min_volt = 226,
  edda_temperature_2_input_voltage_volt = 227,
  edda_temperature_2_relative_humidity_percentage = 228,
  edda_temperature_2_latency_edda_controller_time_max_millisecond = 229,
  edda_temperature_2_latency_edda_controller_time_min_millisecond = 230,
  edda_temperature_2_latency_edda_ground_time_max_millisecond = 231,
  edda_temperature_2_latency_edda_ground_time_min_millisecond = 232,
  edda_temperature_2_latency_edda_temperature_1_time_max_millisecond = 233,
  edda_temperature_2_latency_edda_temperature_1_time_min_millisecond = 234,
  edda_temperature_2_latency_edda_transducer_time_max_millisecond = 235,
  edda_temperature_2_latency_edda_transducer_time_min_millisecond = 236,
  edda_temperature_2_x_acceleration_gforce = 237,
  edda_temperature_2_x_acceleration_max_gforce = 238,
  edda_temperature_2_x_acceleration_min_gforce = 239,
  edda_temperature_2_y_acceleration_gforce = 240,
  edda_temperature_2_y_acceleration_max_gforce = 241,
  edda_temperature_2_y_acceleration_min_gforce = 242,
  edda_temperature_2_z_acceleration_gforce = 243,
  edda_temperature_2_z_acceleration_max_gforce = 244,
  edda_temperature_2_z_acceleration_min_gforce = 245,
  sindri_therm_01_temperature_celsius = 246,
  sindri_therm_02_temperature_celsius = 247,
  sindri_therm_03_temperature_celsius = 248,
  sindri_therm_04_temperature_celsius = 249,
  sindri_therm_05_temperature_celsius = 250,
  sindri_therm_06_temperature_celsius = 251,
  sindri_therm_07_temperature_celsius = 252,
  sindri_therm_08_temperature_celsius = 253,
  sindri_therm_01_voltage_volt = 254,
  sindri_therm_02_voltage_volt = 255,
  sindri_therm_03_voltage_volt = 256,
  sindri_therm_04_voltage_volt = 257,
  sindri_therm_05_voltage_volt = 258,
  sindri_therm_06_voltage_volt = 259,
  sindri_therm_07_voltage_volt = 260,
  sindri_therm_08_voltage_volt = 261,
  edda_transducer_ambient_pressure_bar = 262,
  edda_transducer_can_rx_size_rate_byte = 263,
  edda_transducer_can_tx_size_rate_byte = 264,
  edda_transducer_latency_edda_controller_time_millisecond = 265,
  edda_transducer_latency_edda_ground_time_millisecond = 266,
  edda_transducer_latency_edda_temperature_1_time_millisecond = 267,
  edda_transducer_latency_edda_temperature_2_time_millisecond = 268,
  edda_transducer_timing_time_freq_hertz = 269,
  edda_transducer_timing_time_max_microsecond = 270,
  edda_transducer_timing_time_microsecond = 271,
  edda_transducer_timing_time_min_microsecond = 272,
  edda_transducer_can_rx_time_max_microsecond = 273,
  edda_transducer_can_rx_time_microsecond = 274,
  edda_transducer_board_temperature_celsius = 275,
  edda_transducer_can_rx_time_min_microsecond = 276,
  edda_transducer_can_tx_time_max_microsecond = 277,
  edda_transducer_humidity_sensor_temperature_celsius = 278,
  edda_transducer_can_tx_time_microsecond = 279,
  edda_transducer_can_tx_time_min_microsecond = 280,
  edda_transducer_imu_temperature_celsius = 281,
  edda_transducer_input_current_ampere = 282,
  edda_transducer_input_current_max_ampere = 283,
  edda_transducer_internal_temperature_celsius = 284,
  edda_transducer_input_current_min_ampere = 285,
  edda_transducer_input_voltage_max_volt = 286,
  edda_transducer_pressure_sensor_temperature_celsius = 287,
  edda_transducer_input_voltage_min_volt = 288,
  edda_transducer_input_voltage_volt = 289,
  edda_transducer_relative_humidity_percentage = 290,
  edda_transducer_latency_edda_controller_time_max_millisecond = 291,
  edda_transducer_latency_edda_controller_time_min_millisecond = 292,
  edda_transducer_latency_edda_ground_time_max_millisecond = 293,
  edda_transducer_latency_edda_ground_time_min_millisecond = 294,
  edda_transducer_latency_edda_temperature_1_time_max_millisecond = 295,
  edda_transducer_latency_edda_temperature_1_time_min_millisecond = 296,
  edda_transducer_latency_edda_temperature_2_time_max_millisecond = 297,
  edda_transducer_latency_edda_temperature_2_time_min_millisecond = 298,
  edda_transducer_x_acceleration_gforce = 299,
  edda_transducer_x_acceleration_max_gforce = 300,
  edda_transducer_x_acceleration_min_gforce = 301,
  edda_transducer_y_acceleration_gforce = 302,
  edda_transducer_y_acceleration_max_gforce = 303,
  edda_transducer_y_acceleration_min_gforce = 304,
  edda_transducer_z_acceleration_gforce = 305,
  edda_transducer_z_acceleration_max_gforce = 306,
  edda_transducer_z_acceleration_min_gforce = 307,
  sindri_transducer_01_pressure_bar = 308,
  sindri_transducer_02_pressure_bar = 309,
  sindri_transducer_03_pressure_bar = 310,
  sindri_transducer_04_pressure_bar = 311,
  sindri_transducer_01_pressure_max_bar = 312,
  sindri_transducer_01_pressure_min_bar = 313,
  sindri_transducer_02_pressure_max_bar = 314,
  sindri_transducer_02_pressure_min_bar = 315,
  sindri_transducer_03_pressure_max_bar = 316,
  sindri_transducer_03_pressure_min_bar = 317,
  sindri_transducer_04_pressure_max_bar = 318,
  sindri_transducer_04_pressure_min_bar = 319,
  sindri_transducer_01_voltage_volt = 320,
  sindri_transducer_02_voltage_volt = 321,
  sindri_transducer_03_voltage_volt = 322,
  sindri_transducer_04_voltage_volt = 323,
  sindri_transducer_12v_voltage_volt = 324,
  sindri_transducer_5v_voltage_volt = 325,
  frame_number = 326,
  time_since_boot_ms = 327,
  hour = 328,
  minute = 329,
  second = 330,
};
enum struct messages : uint16_t {
  ChannelState = 0,
  ChannelTransitionRequest = 1,
  ChannelTransitionResponse = 2,
  Date = 3,
  EngineActionRequest = 4,
  EngineActionResponse = 5,
  EngineState = 6,
  Heartbeat = 7,
  Latency = 8,
  Ping = 9,
  Pong = 10,
  Telemetry__ControllerBoard_edda_controller_00 = 11,
  Telemetry__ControllerBoard_edda_controller_01 = 12,
  Telemetry__ControllerBoard_edda_controller_02 = 13,
  Telemetry__ControllerBoard_edda_controller_03 = 14,
  Telemetry__ControllerBoard_edda_controller_04 = 15,
  Telemetry__ControllerBoard_edda_controller_05 = 16,
  Telemetry__ControllerBoard_edda_controller_06 = 17,
  Telemetry__ControllerBoard_edda_controller_07 = 18,
  Telemetry__ControllerBoard_edda_controller_08 = 19,
  Telemetry__ControllerBoard_edda_controller_09 = 20,
  Telemetry__ControllerBoard_edda_controller_10 = 21,
  Telemetry__ControllerBoard_edda_controller_11 = 22,
  Telemetry__ControllerBoard_edda_controller_12 = 23,
  Telemetry__ControllerBoard_edda_controller_13 = 24,
  Telemetry__ControllerBoard_edda_controller_14 = 25,
  Telemetry__ControllerBoard_edda_controller_15 = 26,
  Telemetry__ControllerBoard_edda_controller_16 = 27,
  Telemetry__ControllerBoard_edda_controller_17 = 28,
  Telemetry__ControllerBoard_edda_controller_18 = 29,
  Telemetry__ControllerBoard_edda_controller_19 = 30,
  Telemetry__ControllerBoard_edda_controller_20 = 31,
  Telemetry__ControllerBoard_sindri_00 = 32,
  Telemetry__ControllerBoard_sindri_01 = 33,
  Telemetry__ControllerBoard_sindri_02 = 34,
  Telemetry__ControllerBoard_sindri_03 = 35,
  Telemetry__ControllerBoard_sindri_04 = 36,
  Telemetry__ControllerBoard_sindri_05 = 37,
  Telemetry__ControllerBoard_sindri_06 = 38,
  Telemetry__ControllerBoard_sindri_07 = 39,
  Telemetry__ControllerBoard_sindri_08 = 40,
  Telemetry__ControllerBoard_sindri_09 = 41,
  Telemetry__ControllerBoard_sindri_10 = 42,
  Telemetry__GroundController_edda_ground_00 = 43,
  Telemetry__GroundController_edda_ground_01 = 44,
  Telemetry__GroundController_edda_ground_02 = 45,
  Telemetry__GroundController_edda_ground_03 = 46,
  Telemetry__GroundController_edda_ground_04 = 47,
  Telemetry__GroundController_edda_ground_05 = 48,
  Telemetry__GroundController_edda_ground_06 = 49,
  Telemetry__GroundController_edda_ground_07 = 50,
  Telemetry__GroundController_edda_ground_08 = 51,
  Telemetry__GroundController_edda_ground_09 = 52,
  Telemetry__GroundController_edda_ground_10 = 53,
  Telemetry__GroundController_edda_ground_11 = 54,
  Telemetry__GroundController_edda_ground_12 = 55,
  Telemetry__GroundController_edda_ground_13 = 56,
  Telemetry__GroundController_edda_ground_14 = 57,
  Telemetry__GroundController_edda_ground_15 = 58,
  Telemetry__GroundController_edda_ground_16 = 59,
  Telemetry__GroundController_edda_ground_17 = 60,
  Telemetry__GroundController_edda_ground_18 = 61,
  Telemetry__GroundController_edda_ground_19 = 62,
  Telemetry__GroundController_edda_ground_20 = 63,
  Telemetry__GroundController_edda_ground_21 = 64,
  Telemetry__GroundController_edda_ground_22 = 65,
  Telemetry__TemperatureBoard1_edda_temperature_1_00 = 66,
  Telemetry__TemperatureBoard1_edda_temperature_1_01 = 67,
  Telemetry__TemperatureBoard1_edda_temperature_1_02 = 68,
  Telemetry__TemperatureBoard1_edda_temperature_1_03 = 69,
  Telemetry__TemperatureBoard1_edda_temperature_1_04 = 70,
  Telemetry__TemperatureBoard1_edda_temperature_1_05 = 71,
  Telemetry__TemperatureBoard1_edda_temperature_1_06 = 72,
  Telemetry__TemperatureBoard1_edda_temperature_1_07 = 73,
  Telemetry__TemperatureBoard1_edda_temperature_1_08 = 74,
  Telemetry__TemperatureBoard1_edda_temperature_1_09 = 75,
  Telemetry__TemperatureBoard1_edda_temperature_1_10 = 76,
  Telemetry__TemperatureBoard1_edda_temperature_1_11 = 77,
  Telemetry__TemperatureBoard1_edda_temperature_1_12 = 78,
  Telemetry__TemperatureBoard1_edda_temperature_1_13 = 79,
  Telemetry__TemperatureBoard1_edda_temperature_1_14 = 80,
  Telemetry__TemperatureBoard1_edda_temperature_1_15 = 81,
  Telemetry__TemperatureBoard1_edda_temperature_1_16 = 82,
  Telemetry__TemperatureBoard1_edda_temperature_1_17 = 83,
  Telemetry__TemperatureBoard1_edda_temperature_1_18 = 84,
  Telemetry__TemperatureBoard1_edda_temperature_1_19 = 85,
  Telemetry__TemperatureBoard1_edda_temperature_1_20 = 86,
  Telemetry__TemperatureBoard1_sindri_00 = 87,
  Telemetry__TemperatureBoard1_sindri_01 = 88,
  Telemetry__TemperatureBoard1_sindri_02 = 89,
  Telemetry__TemperatureBoard1_sindri_03 = 90,
  Telemetry__TemperatureBoard1_sindri_04 = 91,
  Telemetry__TemperatureBoard1_sindri_05 = 92,
  Telemetry__TemperatureBoard1_sindri_06 = 93,
  Telemetry__TemperatureBoard2_edda_temperature_2_00 = 94,
  Telemetry__TemperatureBoard2_edda_temperature_2_01 = 95,
  Telemetry__TemperatureBoard2_edda_temperature_2_02 = 96,
  Telemetry__TemperatureBoard2_edda_temperature_2_03 = 97,
  Telemetry__TemperatureBoard2_edda_temperature_2_04 = 98,
  Telemetry__TemperatureBoard2_edda_temperature_2_05 = 99,
  Telemetry__TemperatureBoard2_edda_temperature_2_06 = 100,
  Telemetry__TemperatureBoard2_edda_temperature_2_07 = 101,
  Telemetry__TemperatureBoard2_edda_temperature_2_08 = 102,
  Telemetry__TemperatureBoard2_edda_temperature_2_09 = 103,
  Telemetry__TemperatureBoard2_edda_temperature_2_10 = 104,
  Telemetry__TemperatureBoard2_edda_temperature_2_11 = 105,
  Telemetry__TemperatureBoard2_edda_temperature_2_12 = 106,
  Telemetry__TemperatureBoard2_edda_temperature_2_13 = 107,
  Telemetry__TemperatureBoard2_edda_temperature_2_14 = 108,
  Telemetry__TemperatureBoard2_edda_temperature_2_15 = 109,
  Telemetry__TemperatureBoard2_edda_temperature_2_16 = 110,
  Telemetry__TemperatureBoard2_edda_temperature_2_17 = 111,
  Telemetry__TemperatureBoard2_edda_temperature_2_18 = 112,
  Telemetry__TemperatureBoard2_edda_temperature_2_19 = 113,
  Telemetry__TemperatureBoard2_edda_temperature_2_20 = 114,
  Telemetry__TemperatureBoard2_sindri_00 = 115,
  Telemetry__TemperatureBoard2_sindri_01 = 116,
  Telemetry__TemperatureBoard2_sindri_02 = 117,
  Telemetry__TemperatureBoard2_sindri_03 = 118,
  Telemetry__TemperatureBoard2_sindri_04 = 119,
  Telemetry__TemperatureBoard2_sindri_05 = 120,
  Telemetry__TemperatureBoard2_sindri_06 = 121,
  Telemetry__TemperatureBoard2_sindri_07 = 122,
  Telemetry__TransducerBoard_edda_transducer_00 = 123,
  Telemetry__TransducerBoard_edda_transducer_01 = 124,
  Telemetry__TransducerBoard_edda_transducer_02 = 125,
  Telemetry__TransducerBoard_edda_transducer_03 = 126,
  Telemetry__TransducerBoard_edda_transducer_04 = 127,
  Telemetry__TransducerBoard_edda_transducer_05 = 128,
  Telemetry__TransducerBoard_edda_transducer_06 = 129,
  Telemetry__TransducerBoard_edda_transducer_07 = 130,
  Telemetry__TransducerBoard_edda_transducer_08 = 131,
  Telemetry__TransducerBoard_edda_transducer_09 = 132,
  Telemetry__TransducerBoard_edda_transducer_10 = 133,
  Telemetry__TransducerBoard_edda_transducer_11 = 134,
  Telemetry__TransducerBoard_edda_transducer_12 = 135,
  Telemetry__TransducerBoard_edda_transducer_13 = 136,
  Telemetry__TransducerBoard_edda_transducer_14 = 137,
  Telemetry__TransducerBoard_edda_transducer_15 = 138,
  Telemetry__TransducerBoard_edda_transducer_16 = 139,
  Telemetry__TransducerBoard_edda_transducer_17 = 140,
  Telemetry__TransducerBoard_edda_transducer_18 = 141,
  Telemetry__TransducerBoard_edda_transducer_19 = 142,
  Telemetry__TransducerBoard_edda_transducer_20 = 143,
  Telemetry__TransducerBoard_sindri_00 = 144,
  Telemetry__TransducerBoard_sindri_01 = 145,
  Telemetry__TransducerBoard_sindri_02 = 146,
  Telemetry__TransducerBoard_sindri_03 = 147,
  Telemetry__TransducerBoard_sindri_04 = 148,
  Telemetry__TransducerBoard_sindri_05 = 149,
  Telemetry__TransducerBoard_sindri_06 = 150,
  Telemetry__TransducerBoard_sindri_07 = 151,
  Telemetry__TransducerBoard_sindri_08 = 152,
  TelemetryMetaFrame = 153,
  TelemetryMetaTime = 154,
  Time = 155,
};
enum struct categories : uint16_t {
  none = 0,
};
enum struct nodes : uint8_t {
  Controller_Board = 48,
  Ground_Controller = 1,
  Temperature_Board_1 = 17,
  Temperature_Board_2 = 18,
  Transducer_Board = 32,
  Power_Channel_1 = 241,
  Power_Channel_2 = 242,
  Power_Channel_3 = 243,
};
enum struct Channel : uint8_t {
  Ignition = 0,
  BleedValve = 1,
  MainValve = 2,
};
enum struct ChannelSystemState : uint8_t {
  Idle = 0,
  Arming = 1,
  Armed = 2,
  Firing = 3,
};
enum struct ChannelOutputState : uint8_t {
  Grounded = 0,
  ResistanceMeasurement = 1,
  High = 2,
};
enum struct ChannelTransition : uint8_t {
  Arm = 0,
  Disarm = 1,
  Fire = 2,
  StopFire = 3,
};
enum struct TransitionResult : uint8_t {
  Success = 0,
  Failure = 1,
};
enum struct TimeSource : uint8_t {
  RTC = 0,
  GPS = 1,
  UNKNOWN = 2,
};
enum struct TimeStatus : uint8_t {
  NOT_SET = 0,
  SET = 1,
  NEEDS_SYNC = 2,
  UNKNOWN = 3,
};
enum struct EngineAction : uint8_t {
  Ignition = 0,
  EnableManualControl = 1,
  DisableManualControl = 2,
};
enum struct EngineState : uint8_t {
  Unknown = 0,
  Idle = 1,
  PartialArmed = 2,
  Armed = 3,
  Firing = 4,
  ManualControl = 5,
};
enum struct EddaNodes : uint8_t {
  ControllerBoard = 48,
  GroundController = 1,
  PowerChannel1 = 241,
  PowerChannel2 = 242,
  PowerChannel3 = 243,
  TemperatureBoard1 = 17,
  TemperatureBoard2 = 18,
  TransducerBoard = 32,
  Undefined = 255,
  XiyaoStuff = 64,
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
class ChannelState_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum Channel channel;
  static_assert((sizeof(channel) == 1), "invalid size");
  enum ChannelSystemState system_state;
  static_assert((sizeof(system_state) == 1), "invalid size");
  enum ChannelOutputState output_state;
  static_assert((sizeof(output_state) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::ChannelState;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 35;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_channel(enum Channel value) { channel = value; }
  void set_system_state(enum ChannelSystemState value) { system_state = value; }
  void set_output_state(enum ChannelOutputState value) { output_state = value; }
  uint16_t get_checksum() { return checksum; }
  enum Channel get_channel() { return channel; }
  enum ChannelSystemState get_system_state() { return system_state; }
  enum ChannelOutputState get_output_state() { return output_state; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &channel, sizeof(channel));
    *index += sizeof(channel);
    memcpy(buf + *index, &system_state, sizeof(system_state));
    *index += sizeof(system_state);
    memcpy(buf + *index, &output_state, sizeof(output_state));
    *index += sizeof(output_state);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&channel, buf + index, sizeof(channel));
    index += sizeof(channel);
    memcpy(&system_state, buf + index, sizeof(system_state));
    index += sizeof(system_state);
    memcpy(&output_state, buf + index, sizeof(output_state));
    index += sizeof(output_state);
  }
};

class ChannelTransitionRequest_from_Ground_Controller_to_Controller_Board
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum Channel channel;
  static_assert((sizeof(channel) == 1), "invalid size");
  enum ChannelTransition request;
  static_assert((sizeof(request) == 1), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::ChannelTransitionRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 33;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_channel(enum Channel value) { channel = value; }
  void set_request(enum ChannelTransition value) { request = value; }
  uint16_t get_checksum() { return checksum; }
  uint16_t get_edda_signature() { return edda_signature; }
  enum Channel get_channel() { return channel; }
  enum ChannelTransition get_request() { return request; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &channel, sizeof(channel));
    *index += sizeof(channel);
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&channel, buf + index, sizeof(channel));
    index += sizeof(channel);
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
  }
};

class ChannelTransitionResponse_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum Channel channel;
  static_assert((sizeof(channel) == 1), "invalid size");
  enum ChannelTransition request;
  static_assert((sizeof(request) == 1), "invalid size");
  enum TransitionResult response;
  static_assert((sizeof(response) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::ChannelTransitionResponse;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 34;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_channel(enum Channel value) { channel = value; }
  void set_request(enum ChannelTransition value) { request = value; }
  void set_response(enum TransitionResult value) { response = value; }
  uint16_t get_checksum() { return checksum; }
  uint16_t get_edda_signature() { return edda_signature; }
  enum Channel get_channel() { return channel; }
  enum ChannelTransition get_request() { return request; }
  enum TransitionResult get_response() { return response; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &channel, sizeof(channel));
    *index += sizeof(channel);
    memcpy(buf + *index, &request, sizeof(request));
    *index += sizeof(request);
    memcpy(buf + *index, &response, sizeof(response));
    *index += sizeof(response);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&channel, buf + index, sizeof(channel));
    index += sizeof(channel);
    memcpy(&request, buf + index, sizeof(request));
    index += sizeof(request);
    memcpy(&response, buf + index, sizeof(response));
    index += sizeof(response);
  }
};

class Date_from_Controller_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 23;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Controller_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 23;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Controller_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 23;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Controller_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 23;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Controller_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 23;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Ground_Controller_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 27;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Ground_Controller_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 27;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Ground_Controller_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 27;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Ground_Controller_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 27;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Ground_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 27;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_1_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 24;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_1_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 24;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_1_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 24;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_1_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 24;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_1_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 24;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_2_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 25;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_2_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 25;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_2_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 25;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_2_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 25;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Temperature_Board_2_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 25;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Transducer_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 26;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Transducer_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 26;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Transducer_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 26;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Transducer_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 26;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class Date_from_Transducer_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint16_t year;
  static_assert((sizeof(year) == 2), "invalid size");
  uint8_t month;
  static_assert((sizeof(month) == 1), "invalid size");
  uint8_t day;
  static_assert((sizeof(day) == 1), "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message = EDDA::messages::Date;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 26;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_year(uint16_t value) { year = value; }
  void set_month(uint8_t value) { month = value; }
  void set_day(uint8_t value) { day = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint16_t get_year() { return year; }
  uint8_t get_month() { return month; }
  uint8_t get_day() { return day; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &year, sizeof(year));
    *index += sizeof(year);
    memcpy(buf + *index, &month, sizeof(month));
    *index += sizeof(month);
    memcpy(buf + *index, &day, sizeof(day));
    *index += sizeof(day);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&year, buf + index, sizeof(year));
    index += sizeof(year);
    memcpy(&month, buf + index, sizeof(month));
    index += sizeof(month);
    memcpy(&day, buf + index, sizeof(day));
    index += sizeof(day);
  }
};

class EngineActionRequest_from_Ground_Controller_to_Controller_Board
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum EngineAction action;
  static_assert((sizeof(action) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::EngineActionRequest;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 37;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_action(enum EngineAction value) { action = value; }
  uint16_t get_checksum() { return checksum; }
  uint16_t get_edda_signature() { return edda_signature; }
  enum EngineAction get_action() { return action; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &action, sizeof(action));
    *index += sizeof(action);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&action, buf + index, sizeof(action));
    index += sizeof(action);
  }
};

class EngineActionResponse_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint16_t edda_signature;
  static_assert((sizeof(edda_signature) == 2), "invalid size");
  enum EngineAction action;
  static_assert((sizeof(action) == 1), "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message = EDDA::messages::EngineActionResponse;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 38;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_edda_signature(uint16_t value) { edda_signature = value; }
  void set_action(enum EngineAction value) { action = value; }
  uint16_t get_checksum() { return checksum; }
  uint16_t get_edda_signature() { return edda_signature; }
  enum EngineAction get_action() { return action; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &edda_signature, sizeof(edda_signature));
    *index += sizeof(edda_signature);
    memcpy(buf + *index, &action, sizeof(action));
    *index += sizeof(action);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&edda_signature, buf + index, sizeof(edda_signature));
    index += sizeof(edda_signature);
    memcpy(&action, buf + index, sizeof(action));
    index += sizeof(action);
  }
};

class EngineState_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EngineState engine_state;
  static_assert((sizeof(engine_state) == 1), "invalid size");
  uint8_t size = 3;
  enum EDDA::messages message = EDDA::messages::EngineState;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 36;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_engine_state(enum EngineState value) { engine_state = value; }
  uint16_t get_checksum() { return checksum; }
  enum EngineState get_engine_state() { return engine_state; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &engine_state, sizeof(engine_state));
    *index += sizeof(engine_state);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&engine_state, buf + index, sizeof(engine_state));
    index += sizeof(engine_state);
  }
};

class Heartbeat_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 0;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 4;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Power_Channel_1_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Power_Channel_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 5;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Power_Channel_2_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Power_Channel_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 6;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Power_Channel_3_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Power_Channel_3;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 7;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 1;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 2;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Heartbeat_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint32_t uptime_ms;
  static_assert((sizeof(uptime_ms) == 4), "invalid size");
  uint8_t size = 6;
  enum EDDA::messages message = EDDA::messages::Heartbeat;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 3;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_uptime_ms(uint32_t value) { uptime_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint32_t get_uptime_ms() { return uptime_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &uptime_ms, sizeof(uptime_ms));
    *index += sizeof(uptime_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&uptime_ms, buf + index, sizeof(uptime_ms));
    index += sizeof(uptime_ms);
  }
};

class Latency_from_Controller_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t latency_us;
  static_assert((sizeof(latency_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Latency;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 18;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_latency_us(uint32_t value) { latency_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_latency_us() { return latency_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &latency_us, sizeof(latency_us));
    *index += sizeof(latency_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&latency_us, buf + index, sizeof(latency_us));
    index += sizeof(latency_us);
  }
};

class Latency_from_Ground_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t latency_us;
  static_assert((sizeof(latency_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Latency;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 22;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_latency_us(uint32_t value) { latency_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_latency_us() { return latency_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &latency_us, sizeof(latency_us));
    *index += sizeof(latency_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&latency_us, buf + index, sizeof(latency_us));
    index += sizeof(latency_us);
  }
};

class Latency_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t latency_us;
  static_assert((sizeof(latency_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Latency;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 19;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_latency_us(uint32_t value) { latency_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_latency_us() { return latency_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &latency_us, sizeof(latency_us));
    *index += sizeof(latency_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&latency_us, buf + index, sizeof(latency_us));
    index += sizeof(latency_us);
  }
};

class Latency_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t latency_us;
  static_assert((sizeof(latency_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Latency;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 20;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_latency_us(uint32_t value) { latency_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_latency_us() { return latency_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &latency_us, sizeof(latency_us));
    *index += sizeof(latency_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&latency_us, buf + index, sizeof(latency_us));
    index += sizeof(latency_us);
  }
};

class Latency_from_Transducer_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t latency_us;
  static_assert((sizeof(latency_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Latency;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 21;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_latency_us(uint32_t value) { latency_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_latency_us() { return latency_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &latency_us, sizeof(latency_us));
    *index += sizeof(latency_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&latency_us, buf + index, sizeof(latency_us));
    index += sizeof(latency_us);
  }
};

class Ping_from_Controller_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Controller_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Controller_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Controller_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Controller_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 8;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Ground_Controller_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Ground_Controller_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Ground_Controller_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Ground_Controller_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Ground_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 12;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_1_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_1_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_1_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_1_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_1_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 9;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_2_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_2_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_2_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_2_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Temperature_Board_2_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 10;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Transducer_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Transducer_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Transducer_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Transducer_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Ping_from_Transducer_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Ping;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 11;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Controller_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Controller_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Controller_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Controller_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Controller_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 13;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Ground_Controller_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 17;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Ground_Controller_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 17;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Ground_Controller_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 17;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Ground_Controller_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 17;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Ground_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 17;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_1_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 14;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_1_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 14;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_1_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 14;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_1_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 14;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_1_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 14;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_2_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 15;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_2_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 15;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_2_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 15;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_2_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 15;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Temperature_Board_2_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 15;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Transducer_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 16;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Transducer_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 16;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Transducer_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 16;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Transducer_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 16;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class Pong_from_Transducer_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum EddaNodes destination_node;
  static_assert((sizeof(destination_node) == 1), "invalid size");
  uint32_t time_us;
  static_assert((sizeof(time_us) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Pong;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 16;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_destination_node(enum EddaNodes value) { destination_node = value; }
  void set_time_us(uint32_t value) { time_us = value; }
  uint16_t get_checksum() { return checksum; }
  enum EddaNodes get_destination_node() { return destination_node; }
  uint32_t get_time_us() { return time_us; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &destination_node, sizeof(destination_node));
    *index += sizeof(destination_node);
    memcpy(buf + *index, &time_us, sizeof(time_us));
    *index += sizeof(time_us);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&destination_node, buf + index, sizeof(destination_node));
    index += sizeof(destination_node);
    memcpy(&time_us, buf + index, sizeof(time_us));
    index += sizeof(time_us);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_00_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_ambient_pressure_bar;
  static_assert((sizeof(edda_controller_ambient_pressure_bar) == 2),
                "invalid size");
  uint16_t edda_controller_can_rx_size_rate_byte;
  static_assert((sizeof(edda_controller_can_rx_size_rate_byte) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_00;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 49;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_ambient_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5, &edda_controller_ambient_pressure_bar);
  }
  void set_edda_controller_can_rx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_controller_can_rx_size_rate_byte);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_ambient_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_ambient_pressure_bar, 0, 1.5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_can_rx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_rx_size_rate_byte, 0, 125000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_ambient_pressure_bar,
           sizeof(edda_controller_ambient_pressure_bar));
    *index += sizeof(edda_controller_ambient_pressure_bar);
    memcpy(buf + *index, &edda_controller_can_rx_size_rate_byte,
           sizeof(edda_controller_can_rx_size_rate_byte));
    *index += sizeof(edda_controller_can_rx_size_rate_byte);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_ambient_pressure_bar, buf + index,
           sizeof(edda_controller_ambient_pressure_bar));
    index += sizeof(edda_controller_ambient_pressure_bar);
    memcpy(&edda_controller_can_rx_size_rate_byte, buf + index,
           sizeof(edda_controller_can_rx_size_rate_byte));
    index += sizeof(edda_controller_can_rx_size_rate_byte);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_01_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_can_tx_size_rate_byte;
  static_assert((sizeof(edda_controller_can_tx_size_rate_byte) == 2),
                "invalid size");
  uint16_t edda_controller_latency_edda_ground_time_millisecond;
  static_assert((sizeof(edda_controller_latency_edda_ground_time_millisecond) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_01;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 50;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_can_tx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_controller_can_tx_size_rate_byte);
  }
  void set_edda_controller_latency_edda_ground_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 500,
                        &edda_controller_latency_edda_ground_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_can_tx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_tx_size_rate_byte, 0, 125000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_latency_edda_ground_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_latency_edda_ground_time_millisecond, 0,
                        500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_can_tx_size_rate_byte,
           sizeof(edda_controller_can_tx_size_rate_byte));
    *index += sizeof(edda_controller_can_tx_size_rate_byte);
    memcpy(buf + *index, &edda_controller_latency_edda_ground_time_millisecond,
           sizeof(edda_controller_latency_edda_ground_time_millisecond));
    *index += sizeof(edda_controller_latency_edda_ground_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_can_tx_size_rate_byte, buf + index,
           sizeof(edda_controller_can_tx_size_rate_byte));
    index += sizeof(edda_controller_can_tx_size_rate_byte);
    memcpy(&edda_controller_latency_edda_ground_time_millisecond, buf + index,
           sizeof(edda_controller_latency_edda_ground_time_millisecond));
    index += sizeof(edda_controller_latency_edda_ground_time_millisecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_02_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_latency_edda_temperature_1_time_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_temperature_1_time_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_controller_latency_edda_temperature_2_time_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_temperature_2_time_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_02;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 51;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_latency_edda_temperature_1_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_temperature_1_time_millisecond);
  }
  void set_edda_controller_latency_edda_temperature_2_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_temperature_2_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_temperature_1_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_temperature_1_time_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_temperature_2_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_temperature_2_time_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_controller_latency_edda_temperature_1_time_millisecond,
           sizeof(edda_controller_latency_edda_temperature_1_time_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_temperature_1_time_millisecond);
    memcpy(buf + *index,
           &edda_controller_latency_edda_temperature_2_time_millisecond,
           sizeof(edda_controller_latency_edda_temperature_2_time_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_temperature_2_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_latency_edda_temperature_1_time_millisecond,
           buf + index,
           sizeof(edda_controller_latency_edda_temperature_1_time_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_temperature_1_time_millisecond);
    memcpy(&edda_controller_latency_edda_temperature_2_time_millisecond,
           buf + index,
           sizeof(edda_controller_latency_edda_temperature_2_time_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_temperature_2_time_millisecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_03_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_latency_edda_transducer_time_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_transducer_time_millisecond) == 2),
      "invalid size");
  uint16_t edda_controller_timing_time_freq_hertz;
  static_assert((sizeof(edda_controller_timing_time_freq_hertz) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_03;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 52;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_latency_edda_transducer_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_transducer_time_millisecond);
  }
  void set_edda_controller_timing_time_freq_hertz(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 2000,
                        &edda_controller_timing_time_freq_hertz);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_transducer_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_transducer_time_millisecond, 0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_timing_time_freq_hertz() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_timing_time_freq_hertz, 0, 2000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_controller_latency_edda_transducer_time_millisecond,
           sizeof(edda_controller_latency_edda_transducer_time_millisecond));
    *index += sizeof(edda_controller_latency_edda_transducer_time_millisecond);
    memcpy(buf + *index, &edda_controller_timing_time_freq_hertz,
           sizeof(edda_controller_timing_time_freq_hertz));
    *index += sizeof(edda_controller_timing_time_freq_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_latency_edda_transducer_time_millisecond,
           buf + index,
           sizeof(edda_controller_latency_edda_transducer_time_millisecond));
    index += sizeof(edda_controller_latency_edda_transducer_time_millisecond);
    memcpy(&edda_controller_timing_time_freq_hertz, buf + index,
           sizeof(edda_controller_timing_time_freq_hertz));
    index += sizeof(edda_controller_timing_time_freq_hertz);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_04_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_timing_time_max_microsecond;
  static_assert((sizeof(edda_controller_timing_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_controller_timing_time_microsecond;
  static_assert((sizeof(edda_controller_timing_time_microsecond) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_04;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 53;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_timing_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_controller_timing_time_max_microsecond);
  }
  void set_edda_controller_timing_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_controller_timing_time_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_timing_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_timing_time_max_microsecond, 0, 100000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_timing_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_timing_time_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_timing_time_max_microsecond,
           sizeof(edda_controller_timing_time_max_microsecond));
    *index += sizeof(edda_controller_timing_time_max_microsecond);
    memcpy(buf + *index, &edda_controller_timing_time_microsecond,
           sizeof(edda_controller_timing_time_microsecond));
    *index += sizeof(edda_controller_timing_time_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_timing_time_max_microsecond, buf + index,
           sizeof(edda_controller_timing_time_max_microsecond));
    index += sizeof(edda_controller_timing_time_max_microsecond);
    memcpy(&edda_controller_timing_time_microsecond, buf + index,
           sizeof(edda_controller_timing_time_microsecond));
    index += sizeof(edda_controller_timing_time_microsecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_05_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_timing_time_min_microsecond;
  static_assert((sizeof(edda_controller_timing_time_min_microsecond) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_05;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 54;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_timing_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_controller_timing_time_min_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_timing_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_timing_time_min_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_timing_time_min_microsecond,
           sizeof(edda_controller_timing_time_min_microsecond));
    *index += sizeof(edda_controller_timing_time_min_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_timing_time_min_microsecond, buf + index,
           sizeof(edda_controller_timing_time_min_microsecond));
    index += sizeof(edda_controller_timing_time_min_microsecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_06_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_can_rx_time_max_microsecond;
  static_assert((sizeof(edda_controller_can_rx_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_controller_can_rx_time_microsecond;
  static_assert((sizeof(edda_controller_can_rx_time_microsecond) == 2),
                "invalid size");
  uint8_t edda_controller_board_temperature_celsius;
  static_assert((sizeof(edda_controller_board_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_06;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 55;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_can_rx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_controller_can_rx_time_max_microsecond);
  }
  void set_edda_controller_can_rx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_controller_can_rx_time_microsecond);
  }
  void set_edda_controller_board_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_controller_board_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_can_rx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_rx_time_max_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_can_rx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_rx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_board_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_board_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_can_rx_time_max_microsecond,
           sizeof(edda_controller_can_rx_time_max_microsecond));
    *index += sizeof(edda_controller_can_rx_time_max_microsecond);
    memcpy(buf + *index, &edda_controller_can_rx_time_microsecond,
           sizeof(edda_controller_can_rx_time_microsecond));
    *index += sizeof(edda_controller_can_rx_time_microsecond);
    memcpy(buf + *index, &edda_controller_board_temperature_celsius,
           sizeof(edda_controller_board_temperature_celsius));
    *index += sizeof(edda_controller_board_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_can_rx_time_max_microsecond, buf + index,
           sizeof(edda_controller_can_rx_time_max_microsecond));
    index += sizeof(edda_controller_can_rx_time_max_microsecond);
    memcpy(&edda_controller_can_rx_time_microsecond, buf + index,
           sizeof(edda_controller_can_rx_time_microsecond));
    index += sizeof(edda_controller_can_rx_time_microsecond);
    memcpy(&edda_controller_board_temperature_celsius, buf + index,
           sizeof(edda_controller_board_temperature_celsius));
    index += sizeof(edda_controller_board_temperature_celsius);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_07_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_can_rx_time_min_microsecond;
  static_assert((sizeof(edda_controller_can_rx_time_min_microsecond) == 2),
                "invalid size");
  uint16_t edda_controller_can_tx_time_max_microsecond;
  static_assert((sizeof(edda_controller_can_tx_time_max_microsecond) == 2),
                "invalid size");
  uint8_t edda_controller_humidity_sensor_temperature_celsius;
  static_assert((sizeof(edda_controller_humidity_sensor_temperature_celsius) ==
                 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_07;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 56;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_can_rx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_controller_can_rx_time_min_microsecond);
  }
  void set_edda_controller_can_tx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_controller_can_tx_time_max_microsecond);
  }
  void set_edda_controller_humidity_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_controller_humidity_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_can_rx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_rx_time_min_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_can_tx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_tx_time_max_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_humidity_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_humidity_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_can_rx_time_min_microsecond,
           sizeof(edda_controller_can_rx_time_min_microsecond));
    *index += sizeof(edda_controller_can_rx_time_min_microsecond);
    memcpy(buf + *index, &edda_controller_can_tx_time_max_microsecond,
           sizeof(edda_controller_can_tx_time_max_microsecond));
    *index += sizeof(edda_controller_can_tx_time_max_microsecond);
    memcpy(buf + *index, &edda_controller_humidity_sensor_temperature_celsius,
           sizeof(edda_controller_humidity_sensor_temperature_celsius));
    *index += sizeof(edda_controller_humidity_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_can_rx_time_min_microsecond, buf + index,
           sizeof(edda_controller_can_rx_time_min_microsecond));
    index += sizeof(edda_controller_can_rx_time_min_microsecond);
    memcpy(&edda_controller_can_tx_time_max_microsecond, buf + index,
           sizeof(edda_controller_can_tx_time_max_microsecond));
    index += sizeof(edda_controller_can_tx_time_max_microsecond);
    memcpy(&edda_controller_humidity_sensor_temperature_celsius, buf + index,
           sizeof(edda_controller_humidity_sensor_temperature_celsius));
    index += sizeof(edda_controller_humidity_sensor_temperature_celsius);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_08_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_can_tx_time_microsecond;
  static_assert((sizeof(edda_controller_can_tx_time_microsecond) == 2),
                "invalid size");
  uint16_t edda_controller_can_tx_time_min_microsecond;
  static_assert((sizeof(edda_controller_can_tx_time_min_microsecond) == 2),
                "invalid size");
  uint8_t edda_controller_imu_temperature_celsius;
  static_assert((sizeof(edda_controller_imu_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_08;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 57;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_can_tx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_controller_can_tx_time_microsecond);
  }
  void set_edda_controller_can_tx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_controller_can_tx_time_min_microsecond);
  }
  void set_edda_controller_imu_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_controller_imu_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_can_tx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_tx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_can_tx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_can_tx_time_min_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_imu_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_imu_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_can_tx_time_microsecond,
           sizeof(edda_controller_can_tx_time_microsecond));
    *index += sizeof(edda_controller_can_tx_time_microsecond);
    memcpy(buf + *index, &edda_controller_can_tx_time_min_microsecond,
           sizeof(edda_controller_can_tx_time_min_microsecond));
    *index += sizeof(edda_controller_can_tx_time_min_microsecond);
    memcpy(buf + *index, &edda_controller_imu_temperature_celsius,
           sizeof(edda_controller_imu_temperature_celsius));
    *index += sizeof(edda_controller_imu_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_can_tx_time_microsecond, buf + index,
           sizeof(edda_controller_can_tx_time_microsecond));
    index += sizeof(edda_controller_can_tx_time_microsecond);
    memcpy(&edda_controller_can_tx_time_min_microsecond, buf + index,
           sizeof(edda_controller_can_tx_time_min_microsecond));
    index += sizeof(edda_controller_can_tx_time_min_microsecond);
    memcpy(&edda_controller_imu_temperature_celsius, buf + index,
           sizeof(edda_controller_imu_temperature_celsius));
    index += sizeof(edda_controller_imu_temperature_celsius);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_09_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_input_current_ampere;
  static_assert((sizeof(edda_controller_input_current_ampere) == 2),
                "invalid size");
  uint16_t edda_controller_input_current_max_ampere;
  static_assert((sizeof(edda_controller_input_current_max_ampere) == 2),
                "invalid size");
  uint8_t edda_controller_internal_temperature_celsius;
  static_assert((sizeof(edda_controller_internal_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_09;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 58;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_input_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &edda_controller_input_current_ampere);
  }
  void set_edda_controller_input_current_max_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_controller_input_current_max_ampere);
  }
  void set_edda_controller_internal_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_controller_internal_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_input_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_input_current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_input_current_max_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_input_current_max_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_internal_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_internal_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_input_current_ampere,
           sizeof(edda_controller_input_current_ampere));
    *index += sizeof(edda_controller_input_current_ampere);
    memcpy(buf + *index, &edda_controller_input_current_max_ampere,
           sizeof(edda_controller_input_current_max_ampere));
    *index += sizeof(edda_controller_input_current_max_ampere);
    memcpy(buf + *index, &edda_controller_internal_temperature_celsius,
           sizeof(edda_controller_internal_temperature_celsius));
    *index += sizeof(edda_controller_internal_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_input_current_ampere, buf + index,
           sizeof(edda_controller_input_current_ampere));
    index += sizeof(edda_controller_input_current_ampere);
    memcpy(&edda_controller_input_current_max_ampere, buf + index,
           sizeof(edda_controller_input_current_max_ampere));
    index += sizeof(edda_controller_input_current_max_ampere);
    memcpy(&edda_controller_internal_temperature_celsius, buf + index,
           sizeof(edda_controller_internal_temperature_celsius));
    index += sizeof(edda_controller_internal_temperature_celsius);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_10_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_input_current_min_ampere;
  static_assert((sizeof(edda_controller_input_current_min_ampere) == 2),
                "invalid size");
  uint16_t edda_controller_input_voltage_max_volt;
  static_assert((sizeof(edda_controller_input_voltage_max_volt) == 2),
                "invalid size");
  uint8_t edda_controller_pressure_sensor_temperature_celsius;
  static_assert((sizeof(edda_controller_pressure_sensor_temperature_celsius) ==
                 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_10;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 59;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_input_current_min_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_controller_input_current_min_ampere);
  }
  void set_edda_controller_input_voltage_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_controller_input_voltage_max_volt);
  }
  void set_edda_controller_pressure_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_controller_pressure_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_input_current_min_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_input_current_min_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_input_voltage_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_input_voltage_max_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_pressure_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_pressure_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_input_current_min_ampere,
           sizeof(edda_controller_input_current_min_ampere));
    *index += sizeof(edda_controller_input_current_min_ampere);
    memcpy(buf + *index, &edda_controller_input_voltage_max_volt,
           sizeof(edda_controller_input_voltage_max_volt));
    *index += sizeof(edda_controller_input_voltage_max_volt);
    memcpy(buf + *index, &edda_controller_pressure_sensor_temperature_celsius,
           sizeof(edda_controller_pressure_sensor_temperature_celsius));
    *index += sizeof(edda_controller_pressure_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_input_current_min_ampere, buf + index,
           sizeof(edda_controller_input_current_min_ampere));
    index += sizeof(edda_controller_input_current_min_ampere);
    memcpy(&edda_controller_input_voltage_max_volt, buf + index,
           sizeof(edda_controller_input_voltage_max_volt));
    index += sizeof(edda_controller_input_voltage_max_volt);
    memcpy(&edda_controller_pressure_sensor_temperature_celsius, buf + index,
           sizeof(edda_controller_pressure_sensor_temperature_celsius));
    index += sizeof(edda_controller_pressure_sensor_temperature_celsius);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_11_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_input_voltage_min_volt;
  static_assert((sizeof(edda_controller_input_voltage_min_volt) == 2),
                "invalid size");
  uint16_t edda_controller_input_voltage_volt;
  static_assert((sizeof(edda_controller_input_voltage_volt) == 2),
                "invalid size");
  uint8_t edda_controller_relative_humidity_percentage;
  static_assert((sizeof(edda_controller_relative_humidity_percentage) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_11;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 60;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_input_voltage_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_controller_input_voltage_min_volt);
  }
  void set_edda_controller_input_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_controller_input_voltage_volt);
  }
  void set_edda_controller_relative_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100,
                        &edda_controller_relative_humidity_percentage);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_input_voltage_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_input_voltage_min_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_input_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_input_voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_relative_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_relative_humidity_percentage, 0, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_input_voltage_min_volt,
           sizeof(edda_controller_input_voltage_min_volt));
    *index += sizeof(edda_controller_input_voltage_min_volt);
    memcpy(buf + *index, &edda_controller_input_voltage_volt,
           sizeof(edda_controller_input_voltage_volt));
    *index += sizeof(edda_controller_input_voltage_volt);
    memcpy(buf + *index, &edda_controller_relative_humidity_percentage,
           sizeof(edda_controller_relative_humidity_percentage));
    *index += sizeof(edda_controller_relative_humidity_percentage);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_input_voltage_min_volt, buf + index,
           sizeof(edda_controller_input_voltage_min_volt));
    index += sizeof(edda_controller_input_voltage_min_volt);
    memcpy(&edda_controller_input_voltage_volt, buf + index,
           sizeof(edda_controller_input_voltage_volt));
    index += sizeof(edda_controller_input_voltage_volt);
    memcpy(&edda_controller_relative_humidity_percentage, buf + index,
           sizeof(edda_controller_relative_humidity_percentage));
    index += sizeof(edda_controller_relative_humidity_percentage);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_12_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_latency_edda_ground_time_max_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_ground_time_max_millisecond) == 2),
      "invalid size");
  uint16_t edda_controller_latency_edda_ground_time_min_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_ground_time_min_millisecond) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_12;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 61;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_latency_edda_ground_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_ground_time_max_millisecond);
  }
  void set_edda_controller_latency_edda_ground_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_ground_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_ground_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_ground_time_max_millisecond, 0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_ground_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_ground_time_min_millisecond, 0, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_controller_latency_edda_ground_time_max_millisecond,
           sizeof(edda_controller_latency_edda_ground_time_max_millisecond));
    *index += sizeof(edda_controller_latency_edda_ground_time_max_millisecond);
    memcpy(buf + *index,
           &edda_controller_latency_edda_ground_time_min_millisecond,
           sizeof(edda_controller_latency_edda_ground_time_min_millisecond));
    *index += sizeof(edda_controller_latency_edda_ground_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_latency_edda_ground_time_max_millisecond,
           buf + index,
           sizeof(edda_controller_latency_edda_ground_time_max_millisecond));
    index += sizeof(edda_controller_latency_edda_ground_time_max_millisecond);
    memcpy(&edda_controller_latency_edda_ground_time_min_millisecond,
           buf + index,
           sizeof(edda_controller_latency_edda_ground_time_min_millisecond));
    index += sizeof(edda_controller_latency_edda_ground_time_min_millisecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_13_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_latency_edda_temperature_1_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_controller_latency_edda_temperature_1_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_controller_latency_edda_temperature_1_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_controller_latency_edda_temperature_1_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_13;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 62;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_latency_edda_temperature_1_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_temperature_1_time_max_millisecond);
  }
  void set_edda_controller_latency_edda_temperature_1_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_temperature_1_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_temperature_1_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_temperature_1_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_temperature_1_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_temperature_1_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_controller_latency_edda_temperature_1_time_max_millisecond,
        sizeof(
            edda_controller_latency_edda_temperature_1_time_max_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_temperature_1_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_controller_latency_edda_temperature_1_time_min_millisecond,
        sizeof(
            edda_controller_latency_edda_temperature_1_time_min_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_temperature_1_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_controller_latency_edda_temperature_1_time_max_millisecond,
        buf + index,
        sizeof(
            edda_controller_latency_edda_temperature_1_time_max_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_temperature_1_time_max_millisecond);
    memcpy(
        &edda_controller_latency_edda_temperature_1_time_min_millisecond,
        buf + index,
        sizeof(
            edda_controller_latency_edda_temperature_1_time_min_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_temperature_1_time_min_millisecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_14_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_latency_edda_temperature_2_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_controller_latency_edda_temperature_2_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_controller_latency_edda_temperature_2_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_controller_latency_edda_temperature_2_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_14;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 63;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_latency_edda_temperature_2_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_temperature_2_time_max_millisecond);
  }
  void set_edda_controller_latency_edda_temperature_2_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_temperature_2_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_temperature_2_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_temperature_2_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_temperature_2_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_temperature_2_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_controller_latency_edda_temperature_2_time_max_millisecond,
        sizeof(
            edda_controller_latency_edda_temperature_2_time_max_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_temperature_2_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_controller_latency_edda_temperature_2_time_min_millisecond,
        sizeof(
            edda_controller_latency_edda_temperature_2_time_min_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_temperature_2_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_controller_latency_edda_temperature_2_time_max_millisecond,
        buf + index,
        sizeof(
            edda_controller_latency_edda_temperature_2_time_max_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_temperature_2_time_max_millisecond);
    memcpy(
        &edda_controller_latency_edda_temperature_2_time_min_millisecond,
        buf + index,
        sizeof(
            edda_controller_latency_edda_temperature_2_time_min_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_temperature_2_time_min_millisecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_15_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_latency_edda_transducer_time_max_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_transducer_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_controller_latency_edda_transducer_time_min_millisecond;
  static_assert(
      (sizeof(edda_controller_latency_edda_transducer_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_15;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 64;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_latency_edda_transducer_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_transducer_time_max_millisecond);
  }
  void set_edda_controller_latency_edda_transducer_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_controller_latency_edda_transducer_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_transducer_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_transducer_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_controller_latency_edda_transducer_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_controller_latency_edda_transducer_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_controller_latency_edda_transducer_time_max_millisecond,
        sizeof(edda_controller_latency_edda_transducer_time_max_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_transducer_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_controller_latency_edda_transducer_time_min_millisecond,
        sizeof(edda_controller_latency_edda_transducer_time_min_millisecond));
    *index +=
        sizeof(edda_controller_latency_edda_transducer_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_controller_latency_edda_transducer_time_max_millisecond,
        buf + index,
        sizeof(edda_controller_latency_edda_transducer_time_max_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_transducer_time_max_millisecond);
    memcpy(
        &edda_controller_latency_edda_transducer_time_min_millisecond,
        buf + index,
        sizeof(edda_controller_latency_edda_transducer_time_min_millisecond));
    index +=
        sizeof(edda_controller_latency_edda_transducer_time_min_millisecond);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_16_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_x_acceleration_gforce;
  static_assert((sizeof(edda_controller_x_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_controller_x_acceleration_max_gforce;
  static_assert((sizeof(edda_controller_x_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_16;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 65;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_x_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_controller_x_acceleration_gforce);
  }
  void set_edda_controller_x_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_controller_x_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_x_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_x_acceleration_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_x_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_x_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_x_acceleration_gforce,
           sizeof(edda_controller_x_acceleration_gforce));
    *index += sizeof(edda_controller_x_acceleration_gforce);
    memcpy(buf + *index, &edda_controller_x_acceleration_max_gforce,
           sizeof(edda_controller_x_acceleration_max_gforce));
    *index += sizeof(edda_controller_x_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_x_acceleration_gforce, buf + index,
           sizeof(edda_controller_x_acceleration_gforce));
    index += sizeof(edda_controller_x_acceleration_gforce);
    memcpy(&edda_controller_x_acceleration_max_gforce, buf + index,
           sizeof(edda_controller_x_acceleration_max_gforce));
    index += sizeof(edda_controller_x_acceleration_max_gforce);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_17_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_x_acceleration_min_gforce;
  static_assert((sizeof(edda_controller_x_acceleration_min_gforce) == 2),
                "invalid size");
  uint16_t edda_controller_y_acceleration_gforce;
  static_assert((sizeof(edda_controller_y_acceleration_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_17;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 66;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_x_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_controller_x_acceleration_min_gforce);
  }
  void set_edda_controller_y_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_controller_y_acceleration_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_x_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_x_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_y_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_y_acceleration_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_x_acceleration_min_gforce,
           sizeof(edda_controller_x_acceleration_min_gforce));
    *index += sizeof(edda_controller_x_acceleration_min_gforce);
    memcpy(buf + *index, &edda_controller_y_acceleration_gforce,
           sizeof(edda_controller_y_acceleration_gforce));
    *index += sizeof(edda_controller_y_acceleration_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_x_acceleration_min_gforce, buf + index,
           sizeof(edda_controller_x_acceleration_min_gforce));
    index += sizeof(edda_controller_x_acceleration_min_gforce);
    memcpy(&edda_controller_y_acceleration_gforce, buf + index,
           sizeof(edda_controller_y_acceleration_gforce));
    index += sizeof(edda_controller_y_acceleration_gforce);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_18_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_y_acceleration_max_gforce;
  static_assert((sizeof(edda_controller_y_acceleration_max_gforce) == 2),
                "invalid size");
  uint16_t edda_controller_y_acceleration_min_gforce;
  static_assert((sizeof(edda_controller_y_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_18;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 67;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_y_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_controller_y_acceleration_max_gforce);
  }
  void set_edda_controller_y_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_controller_y_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_y_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_y_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_y_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_y_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_y_acceleration_max_gforce,
           sizeof(edda_controller_y_acceleration_max_gforce));
    *index += sizeof(edda_controller_y_acceleration_max_gforce);
    memcpy(buf + *index, &edda_controller_y_acceleration_min_gforce,
           sizeof(edda_controller_y_acceleration_min_gforce));
    *index += sizeof(edda_controller_y_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_y_acceleration_max_gforce, buf + index,
           sizeof(edda_controller_y_acceleration_max_gforce));
    index += sizeof(edda_controller_y_acceleration_max_gforce);
    memcpy(&edda_controller_y_acceleration_min_gforce, buf + index,
           sizeof(edda_controller_y_acceleration_min_gforce));
    index += sizeof(edda_controller_y_acceleration_min_gforce);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_19_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_z_acceleration_gforce;
  static_assert((sizeof(edda_controller_z_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_controller_z_acceleration_max_gforce;
  static_assert((sizeof(edda_controller_z_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_19;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 68;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_z_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_controller_z_acceleration_gforce);
  }
  void set_edda_controller_z_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_controller_z_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_z_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_z_acceleration_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_controller_z_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_z_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_z_acceleration_gforce,
           sizeof(edda_controller_z_acceleration_gforce));
    *index += sizeof(edda_controller_z_acceleration_gforce);
    memcpy(buf + *index, &edda_controller_z_acceleration_max_gforce,
           sizeof(edda_controller_z_acceleration_max_gforce));
    *index += sizeof(edda_controller_z_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_z_acceleration_gforce, buf + index,
           sizeof(edda_controller_z_acceleration_gforce));
    index += sizeof(edda_controller_z_acceleration_gforce);
    memcpy(&edda_controller_z_acceleration_max_gforce, buf + index,
           sizeof(edda_controller_z_acceleration_max_gforce));
    index += sizeof(edda_controller_z_acceleration_max_gforce);
  }
};

class
    Telemetry__ControllerBoard_edda_controller_20_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_controller_z_acceleration_min_gforce;
  static_assert((sizeof(edda_controller_z_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_edda_controller_20;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 69;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_controller_z_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_controller_z_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_controller_z_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_controller_z_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_controller_z_acceleration_min_gforce,
           sizeof(edda_controller_z_acceleration_min_gforce));
    *index += sizeof(edda_controller_z_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_controller_z_acceleration_min_gforce, buf + index,
           sizeof(edda_controller_z_acceleration_min_gforce));
    index += sizeof(edda_controller_z_acceleration_min_gforce);
  }
};

class
    Telemetry__ControllerBoard_sindri_00_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_bleed_valve_current_ampere;
  static_assert((sizeof(sindri_bleed_valve_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_bleed_valve_power_watt;
  static_assert((sizeof(sindri_bleed_valve_power_watt) == 2), "invalid size");
  uint8_t sindri_main_valve_actuation_distance_millimeter;
  static_assert((sizeof(sindri_main_valve_actuation_distance_millimeter) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_00;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 156;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_bleed_valve_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &sindri_bleed_valve_current_ampere);
  }
  void set_sindri_bleed_valve_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &sindri_bleed_valve_power_watt);
  }
  void
  set_sindri_main_valve_actuation_distance_millimeter(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100,
                        &sindri_main_valve_actuation_distance_millimeter);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_current_ampere, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_power_watt, 0, 1000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_main_valve_actuation_distance_millimeter() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_actuation_distance_millimeter, 0, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_bleed_valve_current_ampere,
           sizeof(sindri_bleed_valve_current_ampere));
    *index += sizeof(sindri_bleed_valve_current_ampere);
    memcpy(buf + *index, &sindri_bleed_valve_power_watt,
           sizeof(sindri_bleed_valve_power_watt));
    *index += sizeof(sindri_bleed_valve_power_watt);
    memcpy(buf + *index, &sindri_main_valve_actuation_distance_millimeter,
           sizeof(sindri_main_valve_actuation_distance_millimeter));
    *index += sizeof(sindri_main_valve_actuation_distance_millimeter);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_bleed_valve_current_ampere, buf + index,
           sizeof(sindri_bleed_valve_current_ampere));
    index += sizeof(sindri_bleed_valve_current_ampere);
    memcpy(&sindri_bleed_valve_power_watt, buf + index,
           sizeof(sindri_bleed_valve_power_watt));
    index += sizeof(sindri_bleed_valve_power_watt);
    memcpy(&sindri_main_valve_actuation_distance_millimeter, buf + index,
           sizeof(sindri_main_valve_actuation_distance_millimeter));
    index += sizeof(sindri_main_valve_actuation_distance_millimeter);
  }
};

class
    Telemetry__ControllerBoard_sindri_01_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_bleed_valve_voltage_volt;
  static_assert((sizeof(sindri_bleed_valve_voltage_volt) == 2), "invalid size");
  uint16_t sindri_ignition_current_ampere;
  static_assert((sizeof(sindri_ignition_current_ampere) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_01;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 157;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_bleed_valve_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &sindri_bleed_valve_voltage_volt);
  }
  void set_sindri_ignition_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &sindri_ignition_current_ampere);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_voltage_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_ignition_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_current_ampere, 0, 30, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_bleed_valve_voltage_volt,
           sizeof(sindri_bleed_valve_voltage_volt));
    *index += sizeof(sindri_bleed_valve_voltage_volt);
    memcpy(buf + *index, &sindri_ignition_current_ampere,
           sizeof(sindri_ignition_current_ampere));
    *index += sizeof(sindri_ignition_current_ampere);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_bleed_valve_voltage_volt, buf + index,
           sizeof(sindri_bleed_valve_voltage_volt));
    index += sizeof(sindri_bleed_valve_voltage_volt);
    memcpy(&sindri_ignition_current_ampere, buf + index,
           sizeof(sindri_ignition_current_ampere));
    index += sizeof(sindri_ignition_current_ampere);
  }
};

class
    Telemetry__ControllerBoard_sindri_02_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_ignition_power_watt;
  static_assert((sizeof(sindri_ignition_power_watt) == 2), "invalid size");
  uint16_t sindri_ignition_voltage_volt;
  static_assert((sizeof(sindri_ignition_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_02;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 158;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_ignition_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &sindri_ignition_power_watt);
  }
  void set_sindri_ignition_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &sindri_ignition_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_ignition_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_power_watt, 0, 1000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_ignition_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_voltage_volt, -30, 30, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_ignition_power_watt,
           sizeof(sindri_ignition_power_watt));
    *index += sizeof(sindri_ignition_power_watt);
    memcpy(buf + *index, &sindri_ignition_voltage_volt,
           sizeof(sindri_ignition_voltage_volt));
    *index += sizeof(sindri_ignition_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_ignition_power_watt, buf + index,
           sizeof(sindri_ignition_power_watt));
    index += sizeof(sindri_ignition_power_watt);
    memcpy(&sindri_ignition_voltage_volt, buf + index,
           sizeof(sindri_ignition_voltage_volt));
    index += sizeof(sindri_ignition_voltage_volt);
  }
};

class
    Telemetry__ControllerBoard_sindri_03_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_main_valve_current_ampere;
  static_assert((sizeof(sindri_main_valve_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_main_valve_power_watt;
  static_assert((sizeof(sindri_main_valve_power_watt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_03;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 159;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_main_valve_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30, &sindri_main_valve_current_ampere);
  }
  void set_sindri_main_valve_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &sindri_main_valve_power_watt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_main_valve_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_current_ampere, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_main_valve_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_main_valve_current_ampere,
           sizeof(sindri_main_valve_current_ampere));
    *index += sizeof(sindri_main_valve_current_ampere);
    memcpy(buf + *index, &sindri_main_valve_power_watt,
           sizeof(sindri_main_valve_power_watt));
    *index += sizeof(sindri_main_valve_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_main_valve_current_ampere, buf + index,
           sizeof(sindri_main_valve_current_ampere));
    index += sizeof(sindri_main_valve_current_ampere);
    memcpy(&sindri_main_valve_power_watt, buf + index,
           sizeof(sindri_main_valve_power_watt));
    index += sizeof(sindri_main_valve_power_watt);
  }
};

class
    Telemetry__ControllerBoard_sindri_04_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_main_valve_voltage_volt;
  static_assert((sizeof(sindri_main_valve_voltage_volt) == 2), "invalid size");
  uint16_t sindri_oxidizer_tank_weight_kilogram;
  static_assert((sizeof(sindri_oxidizer_tank_weight_kilogram) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_04;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 160;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_main_valve_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30, &sindri_main_valve_voltage_volt);
  }
  void set_sindri_oxidizer_tank_weight_kilogram(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100, &sindri_oxidizer_tank_weight_kilogram);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_main_valve_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_voltage_volt, -30, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_oxidizer_tank_weight_kilogram() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_oxidizer_tank_weight_kilogram, 0, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_main_valve_voltage_volt,
           sizeof(sindri_main_valve_voltage_volt));
    *index += sizeof(sindri_main_valve_voltage_volt);
    memcpy(buf + *index, &sindri_oxidizer_tank_weight_kilogram,
           sizeof(sindri_oxidizer_tank_weight_kilogram));
    *index += sizeof(sindri_oxidizer_tank_weight_kilogram);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_main_valve_voltage_volt, buf + index,
           sizeof(sindri_main_valve_voltage_volt));
    index += sizeof(sindri_main_valve_voltage_volt);
    memcpy(&sindri_oxidizer_tank_weight_kilogram, buf + index,
           sizeof(sindri_oxidizer_tank_weight_kilogram));
    index += sizeof(sindri_oxidizer_tank_weight_kilogram);
  }
};

class
    Telemetry__ControllerBoard_sindri_05_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_bleed_valve_estimation_current_ampere;
  static_assert((sizeof(sindri_bleed_valve_estimation_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_bleed_valve_estimation_power_watt;
  static_assert((sizeof(sindri_bleed_valve_estimation_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_05;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 161;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_bleed_valve_estimation_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30,
                        &sindri_bleed_valve_estimation_current_ampere);
  }
  void set_sindri_bleed_valve_estimation_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_bleed_valve_estimation_power_watt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_estimation_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_estimation_current_ampere, 0, 30,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_estimation_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_estimation_power_watt, 0, 1000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_bleed_valve_estimation_current_ampere,
           sizeof(sindri_bleed_valve_estimation_current_ampere));
    *index += sizeof(sindri_bleed_valve_estimation_current_ampere);
    memcpy(buf + *index, &sindri_bleed_valve_estimation_power_watt,
           sizeof(sindri_bleed_valve_estimation_power_watt));
    *index += sizeof(sindri_bleed_valve_estimation_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_bleed_valve_estimation_current_ampere, buf + index,
           sizeof(sindri_bleed_valve_estimation_current_ampere));
    index += sizeof(sindri_bleed_valve_estimation_current_ampere);
    memcpy(&sindri_bleed_valve_estimation_power_watt, buf + index,
           sizeof(sindri_bleed_valve_estimation_power_watt));
    index += sizeof(sindri_bleed_valve_estimation_power_watt);
  }
};

class
    Telemetry__ControllerBoard_sindri_06_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_bleed_valve_estimation_resistance_ohm;
  static_assert((sizeof(sindri_bleed_valve_estimation_resistance_ohm) == 2),
                "invalid size");
  uint16_t sindri_bleed_valve_estimation_voltage_volt;
  static_assert((sizeof(sindri_bleed_valve_estimation_voltage_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_06;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 162;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_bleed_valve_estimation_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_bleed_valve_estimation_resistance_ohm);
  }
  void set_sindri_bleed_valve_estimation_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30,
                        &sindri_bleed_valve_estimation_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_estimation_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_estimation_resistance_ohm, 0, 1000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_bleed_valve_estimation_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_bleed_valve_estimation_voltage_volt, -30, 30,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_bleed_valve_estimation_resistance_ohm,
           sizeof(sindri_bleed_valve_estimation_resistance_ohm));
    *index += sizeof(sindri_bleed_valve_estimation_resistance_ohm);
    memcpy(buf + *index, &sindri_bleed_valve_estimation_voltage_volt,
           sizeof(sindri_bleed_valve_estimation_voltage_volt));
    *index += sizeof(sindri_bleed_valve_estimation_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_bleed_valve_estimation_resistance_ohm, buf + index,
           sizeof(sindri_bleed_valve_estimation_resistance_ohm));
    index += sizeof(sindri_bleed_valve_estimation_resistance_ohm);
    memcpy(&sindri_bleed_valve_estimation_voltage_volt, buf + index,
           sizeof(sindri_bleed_valve_estimation_voltage_volt));
    index += sizeof(sindri_bleed_valve_estimation_voltage_volt);
  }
};

class
    Telemetry__ControllerBoard_sindri_07_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_ignition_estimation_current_ampere;
  static_assert((sizeof(sindri_ignition_estimation_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_ignition_estimation_power_watt;
  static_assert((sizeof(sindri_ignition_estimation_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_07;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 163;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_ignition_estimation_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30,
                        &sindri_ignition_estimation_current_ampere);
  }
  void set_sindri_ignition_estimation_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000, &sindri_ignition_estimation_power_watt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_ignition_estimation_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_estimation_current_ampere, 0, 30, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_ignition_estimation_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_estimation_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_ignition_estimation_current_ampere,
           sizeof(sindri_ignition_estimation_current_ampere));
    *index += sizeof(sindri_ignition_estimation_current_ampere);
    memcpy(buf + *index, &sindri_ignition_estimation_power_watt,
           sizeof(sindri_ignition_estimation_power_watt));
    *index += sizeof(sindri_ignition_estimation_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_ignition_estimation_current_ampere, buf + index,
           sizeof(sindri_ignition_estimation_current_ampere));
    index += sizeof(sindri_ignition_estimation_current_ampere);
    memcpy(&sindri_ignition_estimation_power_watt, buf + index,
           sizeof(sindri_ignition_estimation_power_watt));
    index += sizeof(sindri_ignition_estimation_power_watt);
  }
};

class
    Telemetry__ControllerBoard_sindri_08_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_ignition_estimation_resistance_ohm;
  static_assert((sizeof(sindri_ignition_estimation_resistance_ohm) == 2),
                "invalid size");
  uint16_t sindri_ignition_estimation_voltage_volt;
  static_assert((sizeof(sindri_ignition_estimation_voltage_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_08;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 164;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_ignition_estimation_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_ignition_estimation_resistance_ohm);
  }
  void set_sindri_ignition_estimation_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30,
                        &sindri_ignition_estimation_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_ignition_estimation_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_estimation_resistance_ohm, 0, 1000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_ignition_estimation_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_ignition_estimation_voltage_volt, -30, 30, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_ignition_estimation_resistance_ohm,
           sizeof(sindri_ignition_estimation_resistance_ohm));
    *index += sizeof(sindri_ignition_estimation_resistance_ohm);
    memcpy(buf + *index, &sindri_ignition_estimation_voltage_volt,
           sizeof(sindri_ignition_estimation_voltage_volt));
    *index += sizeof(sindri_ignition_estimation_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_ignition_estimation_resistance_ohm, buf + index,
           sizeof(sindri_ignition_estimation_resistance_ohm));
    index += sizeof(sindri_ignition_estimation_resistance_ohm);
    memcpy(&sindri_ignition_estimation_voltage_volt, buf + index,
           sizeof(sindri_ignition_estimation_voltage_volt));
    index += sizeof(sindri_ignition_estimation_voltage_volt);
  }
};

class
    Telemetry__ControllerBoard_sindri_09_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_main_valve_estimation_current_ampere;
  static_assert((sizeof(sindri_main_valve_estimation_current_ampere) == 2),
                "invalid size");
  uint16_t sindri_main_valve_estimation_power_watt;
  static_assert((sizeof(sindri_main_valve_estimation_power_watt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_09;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 165;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_main_valve_estimation_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 30,
                        &sindri_main_valve_estimation_current_ampere);
  }
  void set_sindri_main_valve_estimation_power_watt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_main_valve_estimation_power_watt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_main_valve_estimation_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_estimation_current_ampere, 0, 30,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_main_valve_estimation_power_watt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_estimation_power_watt, 0, 1000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_main_valve_estimation_current_ampere,
           sizeof(sindri_main_valve_estimation_current_ampere));
    *index += sizeof(sindri_main_valve_estimation_current_ampere);
    memcpy(buf + *index, &sindri_main_valve_estimation_power_watt,
           sizeof(sindri_main_valve_estimation_power_watt));
    *index += sizeof(sindri_main_valve_estimation_power_watt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_main_valve_estimation_current_ampere, buf + index,
           sizeof(sindri_main_valve_estimation_current_ampere));
    index += sizeof(sindri_main_valve_estimation_current_ampere);
    memcpy(&sindri_main_valve_estimation_power_watt, buf + index,
           sizeof(sindri_main_valve_estimation_power_watt));
    index += sizeof(sindri_main_valve_estimation_power_watt);
  }
};

class
    Telemetry__ControllerBoard_sindri_10_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_main_valve_estimation_resistance_ohm;
  static_assert((sizeof(sindri_main_valve_estimation_resistance_ohm) == 2),
                "invalid size");
  uint16_t sindri_main_valve_estimation_voltage_volt;
  static_assert((sizeof(sindri_main_valve_estimation_voltage_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__ControllerBoard_sindri_10;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 166;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_main_valve_estimation_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1000,
                        &sindri_main_valve_estimation_resistance_ohm);
  }
  void set_sindri_main_valve_estimation_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -30, 30,
                        &sindri_main_valve_estimation_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_main_valve_estimation_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_estimation_resistance_ohm, 0, 1000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_main_valve_estimation_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_main_valve_estimation_voltage_volt, -30, 30,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_main_valve_estimation_resistance_ohm,
           sizeof(sindri_main_valve_estimation_resistance_ohm));
    *index += sizeof(sindri_main_valve_estimation_resistance_ohm);
    memcpy(buf + *index, &sindri_main_valve_estimation_voltage_volt,
           sizeof(sindri_main_valve_estimation_voltage_volt));
    *index += sizeof(sindri_main_valve_estimation_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_main_valve_estimation_resistance_ohm, buf + index,
           sizeof(sindri_main_valve_estimation_resistance_ohm));
    index += sizeof(sindri_main_valve_estimation_resistance_ohm);
    memcpy(&sindri_main_valve_estimation_voltage_volt, buf + index,
           sizeof(sindri_main_valve_estimation_voltage_volt));
    index += sizeof(sindri_main_valve_estimation_voltage_volt);
  }
};

class
    Telemetry__GroundController_edda_ground_00_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_ambient_pressure_bar;
  static_assert((sizeof(edda_ground_ambient_pressure_bar) == 2),
                "invalid size");
  uint16_t edda_ground_can_rx_size_rate_byte;
  static_assert((sizeof(edda_ground_can_rx_size_rate_byte) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_00;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 70;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_ambient_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5, &edda_ground_ambient_pressure_bar);
  }
  void set_edda_ground_can_rx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000, &edda_ground_can_rx_size_rate_byte);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_ambient_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_ambient_pressure_bar, 0, 1.5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_can_rx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_rx_size_rate_byte, 0, 125000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_ambient_pressure_bar,
           sizeof(edda_ground_ambient_pressure_bar));
    *index += sizeof(edda_ground_ambient_pressure_bar);
    memcpy(buf + *index, &edda_ground_can_rx_size_rate_byte,
           sizeof(edda_ground_can_rx_size_rate_byte));
    *index += sizeof(edda_ground_can_rx_size_rate_byte);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_ambient_pressure_bar, buf + index,
           sizeof(edda_ground_ambient_pressure_bar));
    index += sizeof(edda_ground_ambient_pressure_bar);
    memcpy(&edda_ground_can_rx_size_rate_byte, buf + index,
           sizeof(edda_ground_can_rx_size_rate_byte));
    index += sizeof(edda_ground_can_rx_size_rate_byte);
  }
};

class
    Telemetry__GroundController_edda_ground_01_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_can_tx_size_rate_byte;
  static_assert((sizeof(edda_ground_can_tx_size_rate_byte) == 2),
                "invalid size");
  uint16_t edda_ground_latency_edda_controller_time_millisecond;
  static_assert((sizeof(edda_ground_latency_edda_controller_time_millisecond) ==
                 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_01;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 71;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_can_tx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000, &edda_ground_can_tx_size_rate_byte);
  }
  void set_edda_ground_latency_edda_controller_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 500,
                        &edda_ground_latency_edda_controller_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_can_tx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_tx_size_rate_byte, 0, 125000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_latency_edda_controller_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_latency_edda_controller_time_millisecond, 0,
                        500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_can_tx_size_rate_byte,
           sizeof(edda_ground_can_tx_size_rate_byte));
    *index += sizeof(edda_ground_can_tx_size_rate_byte);
    memcpy(buf + *index, &edda_ground_latency_edda_controller_time_millisecond,
           sizeof(edda_ground_latency_edda_controller_time_millisecond));
    *index += sizeof(edda_ground_latency_edda_controller_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_can_tx_size_rate_byte, buf + index,
           sizeof(edda_ground_can_tx_size_rate_byte));
    index += sizeof(edda_ground_can_tx_size_rate_byte);
    memcpy(&edda_ground_latency_edda_controller_time_millisecond, buf + index,
           sizeof(edda_ground_latency_edda_controller_time_millisecond));
    index += sizeof(edda_ground_latency_edda_controller_time_millisecond);
  }
};

class
    Telemetry__GroundController_edda_ground_02_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_latency_edda_temperature_1_time_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_temperature_1_time_millisecond) == 2),
      "invalid size");
  uint16_t edda_ground_latency_edda_temperature_2_time_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_temperature_2_time_millisecond) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_02;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 72;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_latency_edda_temperature_1_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_temperature_1_time_millisecond);
  }
  void set_edda_ground_latency_edda_temperature_2_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_temperature_2_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_latency_edda_temperature_1_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_latency_edda_temperature_1_time_millisecond,
                        0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_latency_edda_temperature_2_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_latency_edda_temperature_2_time_millisecond,
                        0, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_ground_latency_edda_temperature_1_time_millisecond,
           sizeof(edda_ground_latency_edda_temperature_1_time_millisecond));
    *index += sizeof(edda_ground_latency_edda_temperature_1_time_millisecond);
    memcpy(buf + *index,
           &edda_ground_latency_edda_temperature_2_time_millisecond,
           sizeof(edda_ground_latency_edda_temperature_2_time_millisecond));
    *index += sizeof(edda_ground_latency_edda_temperature_2_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_latency_edda_temperature_1_time_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_temperature_1_time_millisecond));
    index += sizeof(edda_ground_latency_edda_temperature_1_time_millisecond);
    memcpy(&edda_ground_latency_edda_temperature_2_time_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_temperature_2_time_millisecond));
    index += sizeof(edda_ground_latency_edda_temperature_2_time_millisecond);
  }
};

class
    Telemetry__GroundController_edda_ground_03_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_latency_edda_transducer_time_millisecond;
  static_assert((sizeof(edda_ground_latency_edda_transducer_time_millisecond) ==
                 2),
                "invalid size");
  uint16_t edda_ground_timing_time_freq_hertz;
  static_assert((sizeof(edda_ground_timing_time_freq_hertz) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_03;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 73;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_latency_edda_transducer_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 500,
                        &edda_ground_latency_edda_transducer_time_millisecond);
  }
  void set_edda_ground_timing_time_freq_hertz(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 2000, &edda_ground_timing_time_freq_hertz);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_latency_edda_transducer_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_latency_edda_transducer_time_millisecond, 0,
                        500, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_timing_time_freq_hertz() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_timing_time_freq_hertz, 0, 2000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_latency_edda_transducer_time_millisecond,
           sizeof(edda_ground_latency_edda_transducer_time_millisecond));
    *index += sizeof(edda_ground_latency_edda_transducer_time_millisecond);
    memcpy(buf + *index, &edda_ground_timing_time_freq_hertz,
           sizeof(edda_ground_timing_time_freq_hertz));
    *index += sizeof(edda_ground_timing_time_freq_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_latency_edda_transducer_time_millisecond, buf + index,
           sizeof(edda_ground_latency_edda_transducer_time_millisecond));
    index += sizeof(edda_ground_latency_edda_transducer_time_millisecond);
    memcpy(&edda_ground_timing_time_freq_hertz, buf + index,
           sizeof(edda_ground_timing_time_freq_hertz));
    index += sizeof(edda_ground_timing_time_freq_hertz);
  }
};

class
    Telemetry__GroundController_edda_ground_04_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_timing_time_max_microsecond;
  static_assert((sizeof(edda_ground_timing_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_ground_timing_time_microsecond;
  static_assert((sizeof(edda_ground_timing_time_microsecond) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_04;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 74;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_timing_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_ground_timing_time_max_microsecond);
  }
  void set_edda_ground_timing_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000, &edda_ground_timing_time_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_timing_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_timing_time_max_microsecond, 0, 100000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_timing_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_timing_time_microsecond, 0, 100000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_timing_time_max_microsecond,
           sizeof(edda_ground_timing_time_max_microsecond));
    *index += sizeof(edda_ground_timing_time_max_microsecond);
    memcpy(buf + *index, &edda_ground_timing_time_microsecond,
           sizeof(edda_ground_timing_time_microsecond));
    *index += sizeof(edda_ground_timing_time_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_timing_time_max_microsecond, buf + index,
           sizeof(edda_ground_timing_time_max_microsecond));
    index += sizeof(edda_ground_timing_time_max_microsecond);
    memcpy(&edda_ground_timing_time_microsecond, buf + index,
           sizeof(edda_ground_timing_time_microsecond));
    index += sizeof(edda_ground_timing_time_microsecond);
  }
};

class
    Telemetry__GroundController_edda_ground_05_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_timing_time_min_microsecond;
  static_assert((sizeof(edda_ground_timing_time_min_microsecond) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_05;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 75;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_timing_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_ground_timing_time_min_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_timing_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_timing_time_min_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_timing_time_min_microsecond,
           sizeof(edda_ground_timing_time_min_microsecond));
    *index += sizeof(edda_ground_timing_time_min_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_timing_time_min_microsecond, buf + index,
           sizeof(edda_ground_timing_time_min_microsecond));
    index += sizeof(edda_ground_timing_time_min_microsecond);
  }
};

class
    Telemetry__GroundController_edda_ground_06_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t edda_ground_gps_latitude_location;
  static_assert((sizeof(edda_ground_gps_latitude_location) == 4),
                "invalid size");
  uint8_t edda_ground_board_temperature_celsius;
  static_assert((sizeof(edda_ground_board_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_06;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 76;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_gps_latitude_location(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -90, 90, &edda_ground_gps_latitude_location);
  }
  void set_edda_ground_board_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_ground_board_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_gps_latitude_location() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_gps_latitude_location, -90, 90, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_board_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_board_temperature_celsius, -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_gps_latitude_location,
           sizeof(edda_ground_gps_latitude_location));
    *index += sizeof(edda_ground_gps_latitude_location);
    memcpy(buf + *index, &edda_ground_board_temperature_celsius,
           sizeof(edda_ground_board_temperature_celsius));
    *index += sizeof(edda_ground_board_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_gps_latitude_location, buf + index,
           sizeof(edda_ground_gps_latitude_location));
    index += sizeof(edda_ground_gps_latitude_location);
    memcpy(&edda_ground_board_temperature_celsius, buf + index,
           sizeof(edda_ground_board_temperature_celsius));
    index += sizeof(edda_ground_board_temperature_celsius);
  }
};

class
    Telemetry__GroundController_edda_ground_07_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t edda_ground_gps_longitude_location;
  static_assert((sizeof(edda_ground_gps_longitude_location) == 4),
                "invalid size");
  uint8_t edda_ground_humidity_sensor_temperature_celsius;
  static_assert((sizeof(edda_ground_humidity_sensor_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_07;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 77;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_gps_longitude_location(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -180, 180, &edda_ground_gps_longitude_location);
  }
  void
  set_edda_ground_humidity_sensor_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_ground_humidity_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_gps_longitude_location() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_gps_longitude_location, -180, 180, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_humidity_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_humidity_sensor_temperature_celsius, -20,
                        100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_gps_longitude_location,
           sizeof(edda_ground_gps_longitude_location));
    *index += sizeof(edda_ground_gps_longitude_location);
    memcpy(buf + *index, &edda_ground_humidity_sensor_temperature_celsius,
           sizeof(edda_ground_humidity_sensor_temperature_celsius));
    *index += sizeof(edda_ground_humidity_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_gps_longitude_location, buf + index,
           sizeof(edda_ground_gps_longitude_location));
    index += sizeof(edda_ground_gps_longitude_location);
    memcpy(&edda_ground_humidity_sensor_temperature_celsius, buf + index,
           sizeof(edda_ground_humidity_sensor_temperature_celsius));
    index += sizeof(edda_ground_humidity_sensor_temperature_celsius);
  }
};

class
    Telemetry__GroundController_edda_ground_08_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_can_rx_time_max_microsecond;
  static_assert((sizeof(edda_ground_can_rx_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_ground_can_rx_time_microsecond;
  static_assert((sizeof(edda_ground_can_rx_time_microsecond) == 2),
                "invalid size");
  uint8_t edda_ground_imu_temperature_celsius;
  static_assert((sizeof(edda_ground_imu_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_08;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 78;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_can_rx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_ground_can_rx_time_max_microsecond);
  }
  void set_edda_ground_can_rx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &edda_ground_can_rx_time_microsecond);
  }
  void set_edda_ground_imu_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100, &edda_ground_imu_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_can_rx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_rx_time_max_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_can_rx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_rx_time_microsecond, 0, 10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_imu_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_imu_temperature_celsius, -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_can_rx_time_max_microsecond,
           sizeof(edda_ground_can_rx_time_max_microsecond));
    *index += sizeof(edda_ground_can_rx_time_max_microsecond);
    memcpy(buf + *index, &edda_ground_can_rx_time_microsecond,
           sizeof(edda_ground_can_rx_time_microsecond));
    *index += sizeof(edda_ground_can_rx_time_microsecond);
    memcpy(buf + *index, &edda_ground_imu_temperature_celsius,
           sizeof(edda_ground_imu_temperature_celsius));
    *index += sizeof(edda_ground_imu_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_can_rx_time_max_microsecond, buf + index,
           sizeof(edda_ground_can_rx_time_max_microsecond));
    index += sizeof(edda_ground_can_rx_time_max_microsecond);
    memcpy(&edda_ground_can_rx_time_microsecond, buf + index,
           sizeof(edda_ground_can_rx_time_microsecond));
    index += sizeof(edda_ground_can_rx_time_microsecond);
    memcpy(&edda_ground_imu_temperature_celsius, buf + index,
           sizeof(edda_ground_imu_temperature_celsius));
    index += sizeof(edda_ground_imu_temperature_celsius);
  }
};

class
    Telemetry__GroundController_edda_ground_09_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_can_rx_time_min_microsecond;
  static_assert((sizeof(edda_ground_can_rx_time_min_microsecond) == 2),
                "invalid size");
  uint16_t edda_ground_can_tx_time_max_microsecond;
  static_assert((sizeof(edda_ground_can_tx_time_max_microsecond) == 2),
                "invalid size");
  uint8_t edda_ground_internal_temperature_celsius;
  static_assert((sizeof(edda_ground_internal_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_09;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 79;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_can_rx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_ground_can_rx_time_min_microsecond);
  }
  void set_edda_ground_can_tx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_ground_can_tx_time_max_microsecond);
  }
  void set_edda_ground_internal_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_ground_internal_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_can_rx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_rx_time_min_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_can_tx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_tx_time_max_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_internal_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_internal_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_can_rx_time_min_microsecond,
           sizeof(edda_ground_can_rx_time_min_microsecond));
    *index += sizeof(edda_ground_can_rx_time_min_microsecond);
    memcpy(buf + *index, &edda_ground_can_tx_time_max_microsecond,
           sizeof(edda_ground_can_tx_time_max_microsecond));
    *index += sizeof(edda_ground_can_tx_time_max_microsecond);
    memcpy(buf + *index, &edda_ground_internal_temperature_celsius,
           sizeof(edda_ground_internal_temperature_celsius));
    *index += sizeof(edda_ground_internal_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_can_rx_time_min_microsecond, buf + index,
           sizeof(edda_ground_can_rx_time_min_microsecond));
    index += sizeof(edda_ground_can_rx_time_min_microsecond);
    memcpy(&edda_ground_can_tx_time_max_microsecond, buf + index,
           sizeof(edda_ground_can_tx_time_max_microsecond));
    index += sizeof(edda_ground_can_tx_time_max_microsecond);
    memcpy(&edda_ground_internal_temperature_celsius, buf + index,
           sizeof(edda_ground_internal_temperature_celsius));
    index += sizeof(edda_ground_internal_temperature_celsius);
  }
};

class
    Telemetry__GroundController_edda_ground_10_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_can_tx_time_microsecond;
  static_assert((sizeof(edda_ground_can_tx_time_microsecond) == 2),
                "invalid size");
  uint16_t edda_ground_can_tx_time_min_microsecond;
  static_assert((sizeof(edda_ground_can_tx_time_min_microsecond) == 2),
                "invalid size");
  uint8_t edda_ground_pressure_sensor_temperature_celsius;
  static_assert((sizeof(edda_ground_pressure_sensor_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_10;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 80;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_can_tx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &edda_ground_can_tx_time_microsecond);
  }
  void set_edda_ground_can_tx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_ground_can_tx_time_min_microsecond);
  }
  void
  set_edda_ground_pressure_sensor_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_ground_pressure_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_can_tx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_tx_time_microsecond, 0, 10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_can_tx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_can_tx_time_min_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_pressure_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_pressure_sensor_temperature_celsius, -20,
                        100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_can_tx_time_microsecond,
           sizeof(edda_ground_can_tx_time_microsecond));
    *index += sizeof(edda_ground_can_tx_time_microsecond);
    memcpy(buf + *index, &edda_ground_can_tx_time_min_microsecond,
           sizeof(edda_ground_can_tx_time_min_microsecond));
    *index += sizeof(edda_ground_can_tx_time_min_microsecond);
    memcpy(buf + *index, &edda_ground_pressure_sensor_temperature_celsius,
           sizeof(edda_ground_pressure_sensor_temperature_celsius));
    *index += sizeof(edda_ground_pressure_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_can_tx_time_microsecond, buf + index,
           sizeof(edda_ground_can_tx_time_microsecond));
    index += sizeof(edda_ground_can_tx_time_microsecond);
    memcpy(&edda_ground_can_tx_time_min_microsecond, buf + index,
           sizeof(edda_ground_can_tx_time_min_microsecond));
    index += sizeof(edda_ground_can_tx_time_min_microsecond);
    memcpy(&edda_ground_pressure_sensor_temperature_celsius, buf + index,
           sizeof(edda_ground_pressure_sensor_temperature_celsius));
    index += sizeof(edda_ground_pressure_sensor_temperature_celsius);
  }
};

class
    Telemetry__GroundController_edda_ground_11_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_input_current_ampere;
  static_assert((sizeof(edda_ground_input_current_ampere) == 2),
                "invalid size");
  uint16_t edda_ground_input_current_max_ampere;
  static_assert((sizeof(edda_ground_input_current_max_ampere) == 2),
                "invalid size");
  uint8_t edda_ground_relative_humidity_percentage;
  static_assert((sizeof(edda_ground_relative_humidity_percentage) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_11;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 81;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_input_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &edda_ground_input_current_ampere);
  }
  void set_edda_ground_input_current_max_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &edda_ground_input_current_max_ampere);
  }
  void set_edda_ground_relative_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100,
                        &edda_ground_relative_humidity_percentage);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_input_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_input_current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_input_current_max_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_input_current_max_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_relative_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_relative_humidity_percentage, 0, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_input_current_ampere,
           sizeof(edda_ground_input_current_ampere));
    *index += sizeof(edda_ground_input_current_ampere);
    memcpy(buf + *index, &edda_ground_input_current_max_ampere,
           sizeof(edda_ground_input_current_max_ampere));
    *index += sizeof(edda_ground_input_current_max_ampere);
    memcpy(buf + *index, &edda_ground_relative_humidity_percentage,
           sizeof(edda_ground_relative_humidity_percentage));
    *index += sizeof(edda_ground_relative_humidity_percentage);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_input_current_ampere, buf + index,
           sizeof(edda_ground_input_current_ampere));
    index += sizeof(edda_ground_input_current_ampere);
    memcpy(&edda_ground_input_current_max_ampere, buf + index,
           sizeof(edda_ground_input_current_max_ampere));
    index += sizeof(edda_ground_input_current_max_ampere);
    memcpy(&edda_ground_relative_humidity_percentage, buf + index,
           sizeof(edda_ground_relative_humidity_percentage));
    index += sizeof(edda_ground_relative_humidity_percentage);
  }
};

class
    Telemetry__GroundController_edda_ground_12_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_input_current_min_ampere;
  static_assert((sizeof(edda_ground_input_current_min_ampere) == 2),
                "invalid size");
  uint16_t edda_ground_input_voltage_max_volt;
  static_assert((sizeof(edda_ground_input_voltage_max_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_12;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 82;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_input_current_min_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &edda_ground_input_current_min_ampere);
  }
  void set_edda_ground_input_voltage_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_ground_input_voltage_max_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_input_current_min_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_input_current_min_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_input_voltage_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_input_voltage_max_volt, 0, 36, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_input_current_min_ampere,
           sizeof(edda_ground_input_current_min_ampere));
    *index += sizeof(edda_ground_input_current_min_ampere);
    memcpy(buf + *index, &edda_ground_input_voltage_max_volt,
           sizeof(edda_ground_input_voltage_max_volt));
    *index += sizeof(edda_ground_input_voltage_max_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_input_current_min_ampere, buf + index,
           sizeof(edda_ground_input_current_min_ampere));
    index += sizeof(edda_ground_input_current_min_ampere);
    memcpy(&edda_ground_input_voltage_max_volt, buf + index,
           sizeof(edda_ground_input_voltage_max_volt));
    index += sizeof(edda_ground_input_voltage_max_volt);
  }
};

class
    Telemetry__GroundController_edda_ground_13_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_input_voltage_min_volt;
  static_assert((sizeof(edda_ground_input_voltage_min_volt) == 2),
                "invalid size");
  uint16_t edda_ground_input_voltage_volt;
  static_assert((sizeof(edda_ground_input_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_13;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 83;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_input_voltage_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_ground_input_voltage_min_volt);
  }
  void set_edda_ground_input_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_ground_input_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_input_voltage_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_input_voltage_min_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_input_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_input_voltage_volt, 0, 36, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_input_voltage_min_volt,
           sizeof(edda_ground_input_voltage_min_volt));
    *index += sizeof(edda_ground_input_voltage_min_volt);
    memcpy(buf + *index, &edda_ground_input_voltage_volt,
           sizeof(edda_ground_input_voltage_volt));
    *index += sizeof(edda_ground_input_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_input_voltage_min_volt, buf + index,
           sizeof(edda_ground_input_voltage_min_volt));
    index += sizeof(edda_ground_input_voltage_min_volt);
    memcpy(&edda_ground_input_voltage_volt, buf + index,
           sizeof(edda_ground_input_voltage_volt));
    index += sizeof(edda_ground_input_voltage_volt);
  }
};

class
    Telemetry__GroundController_edda_ground_14_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_latency_edda_controller_time_max_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_controller_time_max_millisecond) == 2),
      "invalid size");
  uint16_t edda_ground_latency_edda_controller_time_min_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_controller_time_min_millisecond) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_14;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 84;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_latency_edda_controller_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_controller_time_max_millisecond);
  }
  void set_edda_ground_latency_edda_controller_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_controller_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_controller_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_controller_time_max_millisecond, 0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_controller_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_controller_time_min_millisecond, 0, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_ground_latency_edda_controller_time_max_millisecond,
           sizeof(edda_ground_latency_edda_controller_time_max_millisecond));
    *index += sizeof(edda_ground_latency_edda_controller_time_max_millisecond);
    memcpy(buf + *index,
           &edda_ground_latency_edda_controller_time_min_millisecond,
           sizeof(edda_ground_latency_edda_controller_time_min_millisecond));
    *index += sizeof(edda_ground_latency_edda_controller_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_latency_edda_controller_time_max_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_controller_time_max_millisecond));
    index += sizeof(edda_ground_latency_edda_controller_time_max_millisecond);
    memcpy(&edda_ground_latency_edda_controller_time_min_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_controller_time_min_millisecond));
    index += sizeof(edda_ground_latency_edda_controller_time_min_millisecond);
  }
};

class
    Telemetry__GroundController_edda_ground_15_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_latency_edda_temperature_1_time_max_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_temperature_1_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_ground_latency_edda_temperature_1_time_min_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_temperature_1_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_15;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 85;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_latency_edda_temperature_1_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_temperature_1_time_max_millisecond);
  }
  void set_edda_ground_latency_edda_temperature_1_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_temperature_1_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_temperature_1_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_temperature_1_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_temperature_1_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_temperature_1_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_ground_latency_edda_temperature_1_time_max_millisecond,
           sizeof(edda_ground_latency_edda_temperature_1_time_max_millisecond));
    *index +=
        sizeof(edda_ground_latency_edda_temperature_1_time_max_millisecond);
    memcpy(buf + *index,
           &edda_ground_latency_edda_temperature_1_time_min_millisecond,
           sizeof(edda_ground_latency_edda_temperature_1_time_min_millisecond));
    *index +=
        sizeof(edda_ground_latency_edda_temperature_1_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_latency_edda_temperature_1_time_max_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_temperature_1_time_max_millisecond));
    index +=
        sizeof(edda_ground_latency_edda_temperature_1_time_max_millisecond);
    memcpy(&edda_ground_latency_edda_temperature_1_time_min_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_temperature_1_time_min_millisecond));
    index +=
        sizeof(edda_ground_latency_edda_temperature_1_time_min_millisecond);
  }
};

class
    Telemetry__GroundController_edda_ground_16_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_latency_edda_temperature_2_time_max_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_temperature_2_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_ground_latency_edda_temperature_2_time_min_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_temperature_2_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_16;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 86;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_latency_edda_temperature_2_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_temperature_2_time_max_millisecond);
  }
  void set_edda_ground_latency_edda_temperature_2_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_temperature_2_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_temperature_2_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_temperature_2_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_temperature_2_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_temperature_2_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_ground_latency_edda_temperature_2_time_max_millisecond,
           sizeof(edda_ground_latency_edda_temperature_2_time_max_millisecond));
    *index +=
        sizeof(edda_ground_latency_edda_temperature_2_time_max_millisecond);
    memcpy(buf + *index,
           &edda_ground_latency_edda_temperature_2_time_min_millisecond,
           sizeof(edda_ground_latency_edda_temperature_2_time_min_millisecond));
    *index +=
        sizeof(edda_ground_latency_edda_temperature_2_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_latency_edda_temperature_2_time_max_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_temperature_2_time_max_millisecond));
    index +=
        sizeof(edda_ground_latency_edda_temperature_2_time_max_millisecond);
    memcpy(&edda_ground_latency_edda_temperature_2_time_min_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_temperature_2_time_min_millisecond));
    index +=
        sizeof(edda_ground_latency_edda_temperature_2_time_min_millisecond);
  }
};

class
    Telemetry__GroundController_edda_ground_17_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_latency_edda_transducer_time_max_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_transducer_time_max_millisecond) == 2),
      "invalid size");
  uint16_t edda_ground_latency_edda_transducer_time_min_millisecond;
  static_assert(
      (sizeof(edda_ground_latency_edda_transducer_time_min_millisecond) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_17;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 87;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_latency_edda_transducer_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_transducer_time_max_millisecond);
  }
  void set_edda_ground_latency_edda_transducer_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_ground_latency_edda_transducer_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_transducer_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_transducer_time_max_millisecond, 0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_ground_latency_edda_transducer_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_ground_latency_edda_transducer_time_min_millisecond, 0, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_ground_latency_edda_transducer_time_max_millisecond,
           sizeof(edda_ground_latency_edda_transducer_time_max_millisecond));
    *index += sizeof(edda_ground_latency_edda_transducer_time_max_millisecond);
    memcpy(buf + *index,
           &edda_ground_latency_edda_transducer_time_min_millisecond,
           sizeof(edda_ground_latency_edda_transducer_time_min_millisecond));
    *index += sizeof(edda_ground_latency_edda_transducer_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_latency_edda_transducer_time_max_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_transducer_time_max_millisecond));
    index += sizeof(edda_ground_latency_edda_transducer_time_max_millisecond);
    memcpy(&edda_ground_latency_edda_transducer_time_min_millisecond,
           buf + index,
           sizeof(edda_ground_latency_edda_transducer_time_min_millisecond));
    index += sizeof(edda_ground_latency_edda_transducer_time_min_millisecond);
  }
};

class
    Telemetry__GroundController_edda_ground_18_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_x_acceleration_gforce;
  static_assert((sizeof(edda_ground_x_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_ground_x_acceleration_max_gforce;
  static_assert((sizeof(edda_ground_x_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_18;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 88;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_x_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_x_acceleration_gforce);
  }
  void set_edda_ground_x_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_x_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_x_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_x_acceleration_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_x_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_x_acceleration_max_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_x_acceleration_gforce,
           sizeof(edda_ground_x_acceleration_gforce));
    *index += sizeof(edda_ground_x_acceleration_gforce);
    memcpy(buf + *index, &edda_ground_x_acceleration_max_gforce,
           sizeof(edda_ground_x_acceleration_max_gforce));
    *index += sizeof(edda_ground_x_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_x_acceleration_gforce, buf + index,
           sizeof(edda_ground_x_acceleration_gforce));
    index += sizeof(edda_ground_x_acceleration_gforce);
    memcpy(&edda_ground_x_acceleration_max_gforce, buf + index,
           sizeof(edda_ground_x_acceleration_max_gforce));
    index += sizeof(edda_ground_x_acceleration_max_gforce);
  }
};

class
    Telemetry__GroundController_edda_ground_19_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_x_acceleration_min_gforce;
  static_assert((sizeof(edda_ground_x_acceleration_min_gforce) == 2),
                "invalid size");
  uint16_t edda_ground_y_acceleration_gforce;
  static_assert((sizeof(edda_ground_y_acceleration_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_19;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 89;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_x_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_x_acceleration_min_gforce);
  }
  void set_edda_ground_y_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_y_acceleration_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_x_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_x_acceleration_min_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_y_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_y_acceleration_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_x_acceleration_min_gforce,
           sizeof(edda_ground_x_acceleration_min_gforce));
    *index += sizeof(edda_ground_x_acceleration_min_gforce);
    memcpy(buf + *index, &edda_ground_y_acceleration_gforce,
           sizeof(edda_ground_y_acceleration_gforce));
    *index += sizeof(edda_ground_y_acceleration_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_x_acceleration_min_gforce, buf + index,
           sizeof(edda_ground_x_acceleration_min_gforce));
    index += sizeof(edda_ground_x_acceleration_min_gforce);
    memcpy(&edda_ground_y_acceleration_gforce, buf + index,
           sizeof(edda_ground_y_acceleration_gforce));
    index += sizeof(edda_ground_y_acceleration_gforce);
  }
};

class
    Telemetry__GroundController_edda_ground_20_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_y_acceleration_max_gforce;
  static_assert((sizeof(edda_ground_y_acceleration_max_gforce) == 2),
                "invalid size");
  uint16_t edda_ground_y_acceleration_min_gforce;
  static_assert((sizeof(edda_ground_y_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_20;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 90;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_y_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_y_acceleration_max_gforce);
  }
  void set_edda_ground_y_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_y_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_y_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_y_acceleration_max_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_y_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_y_acceleration_min_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_y_acceleration_max_gforce,
           sizeof(edda_ground_y_acceleration_max_gforce));
    *index += sizeof(edda_ground_y_acceleration_max_gforce);
    memcpy(buf + *index, &edda_ground_y_acceleration_min_gforce,
           sizeof(edda_ground_y_acceleration_min_gforce));
    *index += sizeof(edda_ground_y_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_y_acceleration_max_gforce, buf + index,
           sizeof(edda_ground_y_acceleration_max_gforce));
    index += sizeof(edda_ground_y_acceleration_max_gforce);
    memcpy(&edda_ground_y_acceleration_min_gforce, buf + index,
           sizeof(edda_ground_y_acceleration_min_gforce));
    index += sizeof(edda_ground_y_acceleration_min_gforce);
  }
};

class
    Telemetry__GroundController_edda_ground_21_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_z_acceleration_gforce;
  static_assert((sizeof(edda_ground_z_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_ground_z_acceleration_max_gforce;
  static_assert((sizeof(edda_ground_z_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_21;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 91;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_z_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_z_acceleration_gforce);
  }
  void set_edda_ground_z_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_z_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_z_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_z_acceleration_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_ground_z_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_z_acceleration_max_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_z_acceleration_gforce,
           sizeof(edda_ground_z_acceleration_gforce));
    *index += sizeof(edda_ground_z_acceleration_gforce);
    memcpy(buf + *index, &edda_ground_z_acceleration_max_gforce,
           sizeof(edda_ground_z_acceleration_max_gforce));
    *index += sizeof(edda_ground_z_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_z_acceleration_gforce, buf + index,
           sizeof(edda_ground_z_acceleration_gforce));
    index += sizeof(edda_ground_z_acceleration_gforce);
    memcpy(&edda_ground_z_acceleration_max_gforce, buf + index,
           sizeof(edda_ground_z_acceleration_max_gforce));
    index += sizeof(edda_ground_z_acceleration_max_gforce);
  }
};

class
    Telemetry__GroundController_edda_ground_22_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_ground_z_acceleration_min_gforce;
  static_assert((sizeof(edda_ground_z_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__GroundController_edda_ground_22;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 92;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_ground_z_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_ground_z_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_ground_z_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_ground_z_acceleration_min_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_ground_z_acceleration_min_gforce,
           sizeof(edda_ground_z_acceleration_min_gforce));
    *index += sizeof(edda_ground_z_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_ground_z_acceleration_min_gforce, buf + index,
           sizeof(edda_ground_z_acceleration_min_gforce));
    index += sizeof(edda_ground_z_acceleration_min_gforce);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_00_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_ambient_pressure_bar;
  static_assert((sizeof(edda_temperature_1_ambient_pressure_bar) == 2),
                "invalid size");
  uint16_t edda_temperature_1_can_rx_size_rate_byte;
  static_assert((sizeof(edda_temperature_1_can_rx_size_rate_byte) == 2),
                "invalid size");
  uint8_t edda_temperature_1_compensation_0_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_1_compensation_0_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_00;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 93;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_ambient_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5,
                        &edda_temperature_1_ambient_pressure_bar);
  }
  void set_edda_temperature_1_can_rx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_temperature_1_can_rx_size_rate_byte);
  }
  void set_edda_temperature_1_compensation_0_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_temperature_1_compensation_0_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_ambient_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_ambient_pressure_bar, 0, 1.5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_rx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_rx_size_rate_byte, 0, 125000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_compensation_0_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_compensation_0_temperature_celsius,
                        -20, 106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_ambient_pressure_bar,
           sizeof(edda_temperature_1_ambient_pressure_bar));
    *index += sizeof(edda_temperature_1_ambient_pressure_bar);
    memcpy(buf + *index, &edda_temperature_1_can_rx_size_rate_byte,
           sizeof(edda_temperature_1_can_rx_size_rate_byte));
    *index += sizeof(edda_temperature_1_can_rx_size_rate_byte);
    memcpy(buf + *index, &edda_temperature_1_compensation_0_temperature_celsius,
           sizeof(edda_temperature_1_compensation_0_temperature_celsius));
    *index += sizeof(edda_temperature_1_compensation_0_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_ambient_pressure_bar, buf + index,
           sizeof(edda_temperature_1_ambient_pressure_bar));
    index += sizeof(edda_temperature_1_ambient_pressure_bar);
    memcpy(&edda_temperature_1_can_rx_size_rate_byte, buf + index,
           sizeof(edda_temperature_1_can_rx_size_rate_byte));
    index += sizeof(edda_temperature_1_can_rx_size_rate_byte);
    memcpy(&edda_temperature_1_compensation_0_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_compensation_0_temperature_celsius));
    index += sizeof(edda_temperature_1_compensation_0_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_01_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_can_tx_size_rate_byte;
  static_assert((sizeof(edda_temperature_1_can_tx_size_rate_byte) == 2),
                "invalid size");
  uint16_t edda_temperature_1_latency_edda_controller_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_1_latency_edda_controller_time_millisecond) ==
       2),
      "invalid size");
  uint8_t edda_temperature_1_compensation_1_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_1_compensation_1_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_01;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 94;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_can_tx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_temperature_1_can_tx_size_rate_byte);
  }
  void set_edda_temperature_1_latency_edda_controller_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_controller_time_millisecond);
  }
  void set_edda_temperature_1_compensation_1_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_temperature_1_compensation_1_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_tx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_tx_size_rate_byte, 0, 125000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_controller_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_controller_time_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_compensation_1_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_compensation_1_temperature_celsius,
                        -20, 106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_can_tx_size_rate_byte,
           sizeof(edda_temperature_1_can_tx_size_rate_byte));
    *index += sizeof(edda_temperature_1_can_tx_size_rate_byte);
    memcpy(buf + *index,
           &edda_temperature_1_latency_edda_controller_time_millisecond,
           sizeof(edda_temperature_1_latency_edda_controller_time_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_controller_time_millisecond);
    memcpy(buf + *index, &edda_temperature_1_compensation_1_temperature_celsius,
           sizeof(edda_temperature_1_compensation_1_temperature_celsius));
    *index += sizeof(edda_temperature_1_compensation_1_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_can_tx_size_rate_byte, buf + index,
           sizeof(edda_temperature_1_can_tx_size_rate_byte));
    index += sizeof(edda_temperature_1_can_tx_size_rate_byte);
    memcpy(&edda_temperature_1_latency_edda_controller_time_millisecond,
           buf + index,
           sizeof(edda_temperature_1_latency_edda_controller_time_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_controller_time_millisecond);
    memcpy(&edda_temperature_1_compensation_1_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_compensation_1_temperature_celsius));
    index += sizeof(edda_temperature_1_compensation_1_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_02_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_latency_edda_ground_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_1_latency_edda_ground_time_millisecond) == 2),
      "invalid size");
  uint16_t edda_temperature_1_latency_edda_temperature_2_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_1_latency_edda_temperature_2_time_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_02;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 95;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_latency_edda_ground_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_ground_time_millisecond);
  }
  void set_edda_temperature_1_latency_edda_temperature_2_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_temperature_2_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_latency_edda_ground_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_latency_edda_ground_time_millisecond,
                        0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_temperature_2_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_temperature_2_time_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_temperature_1_latency_edda_ground_time_millisecond,
           sizeof(edda_temperature_1_latency_edda_ground_time_millisecond));
    *index += sizeof(edda_temperature_1_latency_edda_ground_time_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_temperature_2_time_millisecond,
        sizeof(edda_temperature_1_latency_edda_temperature_2_time_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_temperature_2_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_latency_edda_ground_time_millisecond,
           buf + index,
           sizeof(edda_temperature_1_latency_edda_ground_time_millisecond));
    index += sizeof(edda_temperature_1_latency_edda_ground_time_millisecond);
    memcpy(
        &edda_temperature_1_latency_edda_temperature_2_time_millisecond,
        buf + index,
        sizeof(edda_temperature_1_latency_edda_temperature_2_time_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_temperature_2_time_millisecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_03_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_latency_edda_transducer_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_1_latency_edda_transducer_time_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_1_timing_time_freq_hertz;
  static_assert((sizeof(edda_temperature_1_timing_time_freq_hertz) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_03;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 96;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_latency_edda_transducer_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_transducer_time_millisecond);
  }
  void set_edda_temperature_1_timing_time_freq_hertz(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 2000,
                        &edda_temperature_1_timing_time_freq_hertz);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_transducer_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_transducer_time_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_timing_time_freq_hertz() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_timing_time_freq_hertz, 0, 2000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_temperature_1_latency_edda_transducer_time_millisecond,
           sizeof(edda_temperature_1_latency_edda_transducer_time_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_transducer_time_millisecond);
    memcpy(buf + *index, &edda_temperature_1_timing_time_freq_hertz,
           sizeof(edda_temperature_1_timing_time_freq_hertz));
    *index += sizeof(edda_temperature_1_timing_time_freq_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_latency_edda_transducer_time_millisecond,
           buf + index,
           sizeof(edda_temperature_1_latency_edda_transducer_time_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_transducer_time_millisecond);
    memcpy(&edda_temperature_1_timing_time_freq_hertz, buf + index,
           sizeof(edda_temperature_1_timing_time_freq_hertz));
    index += sizeof(edda_temperature_1_timing_time_freq_hertz);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_04_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_timing_time_max_microsecond;
  static_assert((sizeof(edda_temperature_1_timing_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_1_timing_time_microsecond;
  static_assert((sizeof(edda_temperature_1_timing_time_microsecond) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_04;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 97;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_1_timing_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_temperature_1_timing_time_max_microsecond);
  }
  void set_edda_temperature_1_timing_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_temperature_1_timing_time_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_timing_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_timing_time_max_microsecond, 0,
                        100000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_timing_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_timing_time_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_timing_time_max_microsecond,
           sizeof(edda_temperature_1_timing_time_max_microsecond));
    *index += sizeof(edda_temperature_1_timing_time_max_microsecond);
    memcpy(buf + *index, &edda_temperature_1_timing_time_microsecond,
           sizeof(edda_temperature_1_timing_time_microsecond));
    *index += sizeof(edda_temperature_1_timing_time_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_timing_time_max_microsecond, buf + index,
           sizeof(edda_temperature_1_timing_time_max_microsecond));
    index += sizeof(edda_temperature_1_timing_time_max_microsecond);
    memcpy(&edda_temperature_1_timing_time_microsecond, buf + index,
           sizeof(edda_temperature_1_timing_time_microsecond));
    index += sizeof(edda_temperature_1_timing_time_microsecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_05_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_timing_time_min_microsecond;
  static_assert((sizeof(edda_temperature_1_timing_time_min_microsecond) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_05;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 98;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_1_timing_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_temperature_1_timing_time_min_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_timing_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_timing_time_min_microsecond, 0,
                        100000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_timing_time_min_microsecond,
           sizeof(edda_temperature_1_timing_time_min_microsecond));
    *index += sizeof(edda_temperature_1_timing_time_min_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_timing_time_min_microsecond, buf + index,
           sizeof(edda_temperature_1_timing_time_min_microsecond));
    index += sizeof(edda_temperature_1_timing_time_min_microsecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_06_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_can_rx_time_max_microsecond;
  static_assert((sizeof(edda_temperature_1_can_rx_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_1_can_rx_time_microsecond;
  static_assert((sizeof(edda_temperature_1_can_rx_time_microsecond) == 2),
                "invalid size");
  uint8_t edda_temperature_1_board_temperature_celsius;
  static_assert((sizeof(edda_temperature_1_board_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_06;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 99;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_1_can_rx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_1_can_rx_time_max_microsecond);
  }
  void set_edda_temperature_1_can_rx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_1_can_rx_time_microsecond);
  }
  void set_edda_temperature_1_board_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_temperature_1_board_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_rx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_rx_time_max_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_rx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_rx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_board_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_board_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_can_rx_time_max_microsecond,
           sizeof(edda_temperature_1_can_rx_time_max_microsecond));
    *index += sizeof(edda_temperature_1_can_rx_time_max_microsecond);
    memcpy(buf + *index, &edda_temperature_1_can_rx_time_microsecond,
           sizeof(edda_temperature_1_can_rx_time_microsecond));
    *index += sizeof(edda_temperature_1_can_rx_time_microsecond);
    memcpy(buf + *index, &edda_temperature_1_board_temperature_celsius,
           sizeof(edda_temperature_1_board_temperature_celsius));
    *index += sizeof(edda_temperature_1_board_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_can_rx_time_max_microsecond, buf + index,
           sizeof(edda_temperature_1_can_rx_time_max_microsecond));
    index += sizeof(edda_temperature_1_can_rx_time_max_microsecond);
    memcpy(&edda_temperature_1_can_rx_time_microsecond, buf + index,
           sizeof(edda_temperature_1_can_rx_time_microsecond));
    index += sizeof(edda_temperature_1_can_rx_time_microsecond);
    memcpy(&edda_temperature_1_board_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_board_temperature_celsius));
    index += sizeof(edda_temperature_1_board_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_07_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_can_rx_time_min_microsecond;
  static_assert((sizeof(edda_temperature_1_can_rx_time_min_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_1_can_tx_time_max_microsecond;
  static_assert((sizeof(edda_temperature_1_can_tx_time_max_microsecond) == 2),
                "invalid size");
  uint8_t edda_temperature_1_humidity_sensor_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_1_humidity_sensor_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_07;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 100;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_1_can_rx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_1_can_rx_time_min_microsecond);
  }
  void
  set_edda_temperature_1_can_tx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_1_can_tx_time_max_microsecond);
  }
  void set_edda_temperature_1_humidity_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 100,
        &edda_temperature_1_humidity_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_rx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_rx_time_min_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_tx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_tx_time_max_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_humidity_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_humidity_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_can_rx_time_min_microsecond,
           sizeof(edda_temperature_1_can_rx_time_min_microsecond));
    *index += sizeof(edda_temperature_1_can_rx_time_min_microsecond);
    memcpy(buf + *index, &edda_temperature_1_can_tx_time_max_microsecond,
           sizeof(edda_temperature_1_can_tx_time_max_microsecond));
    *index += sizeof(edda_temperature_1_can_tx_time_max_microsecond);
    memcpy(buf + *index,
           &edda_temperature_1_humidity_sensor_temperature_celsius,
           sizeof(edda_temperature_1_humidity_sensor_temperature_celsius));
    *index += sizeof(edda_temperature_1_humidity_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_can_rx_time_min_microsecond, buf + index,
           sizeof(edda_temperature_1_can_rx_time_min_microsecond));
    index += sizeof(edda_temperature_1_can_rx_time_min_microsecond);
    memcpy(&edda_temperature_1_can_tx_time_max_microsecond, buf + index,
           sizeof(edda_temperature_1_can_tx_time_max_microsecond));
    index += sizeof(edda_temperature_1_can_tx_time_max_microsecond);
    memcpy(&edda_temperature_1_humidity_sensor_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_humidity_sensor_temperature_celsius));
    index += sizeof(edda_temperature_1_humidity_sensor_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_08_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_can_tx_time_microsecond;
  static_assert((sizeof(edda_temperature_1_can_tx_time_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_1_can_tx_time_min_microsecond;
  static_assert((sizeof(edda_temperature_1_can_tx_time_min_microsecond) == 2),
                "invalid size");
  uint8_t edda_temperature_1_imu_temperature_celsius;
  static_assert((sizeof(edda_temperature_1_imu_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_08;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 101;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_can_tx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_1_can_tx_time_microsecond);
  }
  void
  set_edda_temperature_1_can_tx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_1_can_tx_time_min_microsecond);
  }
  void set_edda_temperature_1_imu_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_temperature_1_imu_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_tx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_tx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_can_tx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_can_tx_time_min_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_imu_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_imu_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_can_tx_time_microsecond,
           sizeof(edda_temperature_1_can_tx_time_microsecond));
    *index += sizeof(edda_temperature_1_can_tx_time_microsecond);
    memcpy(buf + *index, &edda_temperature_1_can_tx_time_min_microsecond,
           sizeof(edda_temperature_1_can_tx_time_min_microsecond));
    *index += sizeof(edda_temperature_1_can_tx_time_min_microsecond);
    memcpy(buf + *index, &edda_temperature_1_imu_temperature_celsius,
           sizeof(edda_temperature_1_imu_temperature_celsius));
    *index += sizeof(edda_temperature_1_imu_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_can_tx_time_microsecond, buf + index,
           sizeof(edda_temperature_1_can_tx_time_microsecond));
    index += sizeof(edda_temperature_1_can_tx_time_microsecond);
    memcpy(&edda_temperature_1_can_tx_time_min_microsecond, buf + index,
           sizeof(edda_temperature_1_can_tx_time_min_microsecond));
    index += sizeof(edda_temperature_1_can_tx_time_min_microsecond);
    memcpy(&edda_temperature_1_imu_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_imu_temperature_celsius));
    index += sizeof(edda_temperature_1_imu_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_09_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_input_current_ampere;
  static_assert((sizeof(edda_temperature_1_input_current_ampere) == 2),
                "invalid size");
  uint16_t edda_temperature_1_input_current_max_ampere;
  static_assert((sizeof(edda_temperature_1_input_current_max_ampere) == 2),
                "invalid size");
  uint8_t edda_temperature_1_internal_temperature_celsius;
  static_assert((sizeof(edda_temperature_1_internal_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_09;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 102;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_input_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_temperature_1_input_current_ampere);
  }
  void set_edda_temperature_1_input_current_max_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_temperature_1_input_current_max_ampere);
  }
  void
  set_edda_temperature_1_internal_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_temperature_1_internal_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_input_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_input_current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_input_current_max_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_input_current_max_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_internal_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_internal_temperature_celsius, -20,
                        100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_input_current_ampere,
           sizeof(edda_temperature_1_input_current_ampere));
    *index += sizeof(edda_temperature_1_input_current_ampere);
    memcpy(buf + *index, &edda_temperature_1_input_current_max_ampere,
           sizeof(edda_temperature_1_input_current_max_ampere));
    *index += sizeof(edda_temperature_1_input_current_max_ampere);
    memcpy(buf + *index, &edda_temperature_1_internal_temperature_celsius,
           sizeof(edda_temperature_1_internal_temperature_celsius));
    *index += sizeof(edda_temperature_1_internal_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_input_current_ampere, buf + index,
           sizeof(edda_temperature_1_input_current_ampere));
    index += sizeof(edda_temperature_1_input_current_ampere);
    memcpy(&edda_temperature_1_input_current_max_ampere, buf + index,
           sizeof(edda_temperature_1_input_current_max_ampere));
    index += sizeof(edda_temperature_1_input_current_max_ampere);
    memcpy(&edda_temperature_1_internal_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_internal_temperature_celsius));
    index += sizeof(edda_temperature_1_internal_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_10_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_input_current_min_ampere;
  static_assert((sizeof(edda_temperature_1_input_current_min_ampere) == 2),
                "invalid size");
  uint16_t edda_temperature_1_input_voltage_max_volt;
  static_assert((sizeof(edda_temperature_1_input_voltage_max_volt) == 2),
                "invalid size");
  uint8_t edda_temperature_1_pressure_sensor_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_1_pressure_sensor_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_10;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 103;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_input_current_min_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_temperature_1_input_current_min_ampere);
  }
  void set_edda_temperature_1_input_voltage_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_temperature_1_input_voltage_max_volt);
  }
  void set_edda_temperature_1_pressure_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 100,
        &edda_temperature_1_pressure_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_input_current_min_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_input_current_min_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_input_voltage_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_input_voltage_max_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_pressure_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_pressure_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_input_current_min_ampere,
           sizeof(edda_temperature_1_input_current_min_ampere));
    *index += sizeof(edda_temperature_1_input_current_min_ampere);
    memcpy(buf + *index, &edda_temperature_1_input_voltage_max_volt,
           sizeof(edda_temperature_1_input_voltage_max_volt));
    *index += sizeof(edda_temperature_1_input_voltage_max_volt);
    memcpy(buf + *index,
           &edda_temperature_1_pressure_sensor_temperature_celsius,
           sizeof(edda_temperature_1_pressure_sensor_temperature_celsius));
    *index += sizeof(edda_temperature_1_pressure_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_input_current_min_ampere, buf + index,
           sizeof(edda_temperature_1_input_current_min_ampere));
    index += sizeof(edda_temperature_1_input_current_min_ampere);
    memcpy(&edda_temperature_1_input_voltage_max_volt, buf + index,
           sizeof(edda_temperature_1_input_voltage_max_volt));
    index += sizeof(edda_temperature_1_input_voltage_max_volt);
    memcpy(&edda_temperature_1_pressure_sensor_temperature_celsius, buf + index,
           sizeof(edda_temperature_1_pressure_sensor_temperature_celsius));
    index += sizeof(edda_temperature_1_pressure_sensor_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_11_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_input_voltage_min_volt;
  static_assert((sizeof(edda_temperature_1_input_voltage_min_volt) == 2),
                "invalid size");
  uint16_t edda_temperature_1_input_voltage_volt;
  static_assert((sizeof(edda_temperature_1_input_voltage_volt) == 2),
                "invalid size");
  uint8_t edda_temperature_1_relative_humidity_percentage;
  static_assert((sizeof(edda_temperature_1_relative_humidity_percentage) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_11;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 104;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_input_voltage_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_temperature_1_input_voltage_min_volt);
  }
  void set_edda_temperature_1_input_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_temperature_1_input_voltage_volt);
  }
  void
  set_edda_temperature_1_relative_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100,
                        &edda_temperature_1_relative_humidity_percentage);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_input_voltage_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_input_voltage_min_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_input_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_input_voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_relative_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_relative_humidity_percentage, 0, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_input_voltage_min_volt,
           sizeof(edda_temperature_1_input_voltage_min_volt));
    *index += sizeof(edda_temperature_1_input_voltage_min_volt);
    memcpy(buf + *index, &edda_temperature_1_input_voltage_volt,
           sizeof(edda_temperature_1_input_voltage_volt));
    *index += sizeof(edda_temperature_1_input_voltage_volt);
    memcpy(buf + *index, &edda_temperature_1_relative_humidity_percentage,
           sizeof(edda_temperature_1_relative_humidity_percentage));
    *index += sizeof(edda_temperature_1_relative_humidity_percentage);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_input_voltage_min_volt, buf + index,
           sizeof(edda_temperature_1_input_voltage_min_volt));
    index += sizeof(edda_temperature_1_input_voltage_min_volt);
    memcpy(&edda_temperature_1_input_voltage_volt, buf + index,
           sizeof(edda_temperature_1_input_voltage_volt));
    index += sizeof(edda_temperature_1_input_voltage_volt);
    memcpy(&edda_temperature_1_relative_humidity_percentage, buf + index,
           sizeof(edda_temperature_1_relative_humidity_percentage));
    index += sizeof(edda_temperature_1_relative_humidity_percentage);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_12_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_latency_edda_controller_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_1_latency_edda_controller_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_1_latency_edda_controller_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_1_latency_edda_controller_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_12;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 105;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_latency_edda_controller_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_controller_time_max_millisecond);
  }
  void set_edda_temperature_1_latency_edda_controller_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_controller_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_controller_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_controller_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_controller_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_controller_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_controller_time_max_millisecond,
        sizeof(
            edda_temperature_1_latency_edda_controller_time_max_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_controller_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_controller_time_min_millisecond,
        sizeof(
            edda_temperature_1_latency_edda_controller_time_min_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_controller_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_temperature_1_latency_edda_controller_time_max_millisecond,
        buf + index,
        sizeof(
            edda_temperature_1_latency_edda_controller_time_max_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_controller_time_max_millisecond);
    memcpy(
        &edda_temperature_1_latency_edda_controller_time_min_millisecond,
        buf + index,
        sizeof(
            edda_temperature_1_latency_edda_controller_time_min_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_controller_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_13_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_latency_edda_ground_time_max_millisecond;
  static_assert(
      (sizeof(edda_temperature_1_latency_edda_ground_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_1_latency_edda_ground_time_min_millisecond;
  static_assert(
      (sizeof(edda_temperature_1_latency_edda_ground_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_13;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 106;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_latency_edda_ground_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_ground_time_max_millisecond);
  }
  void set_edda_temperature_1_latency_edda_ground_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_ground_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_ground_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_ground_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_ground_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_ground_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_temperature_1_latency_edda_ground_time_max_millisecond,
           sizeof(edda_temperature_1_latency_edda_ground_time_max_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_ground_time_max_millisecond);
    memcpy(buf + *index,
           &edda_temperature_1_latency_edda_ground_time_min_millisecond,
           sizeof(edda_temperature_1_latency_edda_ground_time_min_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_ground_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_latency_edda_ground_time_max_millisecond,
           buf + index,
           sizeof(edda_temperature_1_latency_edda_ground_time_max_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_ground_time_max_millisecond);
    memcpy(&edda_temperature_1_latency_edda_ground_time_min_millisecond,
           buf + index,
           sizeof(edda_temperature_1_latency_edda_ground_time_min_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_ground_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_14_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_latency_edda_temperature_2_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_1_latency_edda_temperature_2_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_1_latency_edda_temperature_2_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_1_latency_edda_temperature_2_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_14;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 107;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_latency_edda_temperature_2_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_temperature_2_time_max_millisecond);
  }
  void set_edda_temperature_1_latency_edda_temperature_2_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_temperature_2_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_temperature_2_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_temperature_2_time_max_millisecond, 0,
        500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_temperature_2_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_temperature_2_time_min_millisecond, 0,
        500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_temperature_2_time_max_millisecond,
        sizeof(
            edda_temperature_1_latency_edda_temperature_2_time_max_millisecond));
    *index += sizeof(
        edda_temperature_1_latency_edda_temperature_2_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_temperature_2_time_min_millisecond,
        sizeof(
            edda_temperature_1_latency_edda_temperature_2_time_min_millisecond));
    *index += sizeof(
        edda_temperature_1_latency_edda_temperature_2_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_temperature_1_latency_edda_temperature_2_time_max_millisecond,
        buf + index,
        sizeof(
            edda_temperature_1_latency_edda_temperature_2_time_max_millisecond));
    index += sizeof(
        edda_temperature_1_latency_edda_temperature_2_time_max_millisecond);
    memcpy(
        &edda_temperature_1_latency_edda_temperature_2_time_min_millisecond,
        buf + index,
        sizeof(
            edda_temperature_1_latency_edda_temperature_2_time_min_millisecond));
    index += sizeof(
        edda_temperature_1_latency_edda_temperature_2_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_15_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_latency_edda_transducer_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_1_latency_edda_transducer_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_1_latency_edda_transducer_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_1_latency_edda_transducer_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_15;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 108;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_latency_edda_transducer_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_transducer_time_max_millisecond);
  }
  void set_edda_temperature_1_latency_edda_transducer_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_1_latency_edda_transducer_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_transducer_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_transducer_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_1_latency_edda_transducer_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_1_latency_edda_transducer_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_transducer_time_max_millisecond,
        sizeof(
            edda_temperature_1_latency_edda_transducer_time_max_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_transducer_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_1_latency_edda_transducer_time_min_millisecond,
        sizeof(
            edda_temperature_1_latency_edda_transducer_time_min_millisecond));
    *index +=
        sizeof(edda_temperature_1_latency_edda_transducer_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_temperature_1_latency_edda_transducer_time_max_millisecond,
        buf + index,
        sizeof(
            edda_temperature_1_latency_edda_transducer_time_max_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_transducer_time_max_millisecond);
    memcpy(
        &edda_temperature_1_latency_edda_transducer_time_min_millisecond,
        buf + index,
        sizeof(
            edda_temperature_1_latency_edda_transducer_time_min_millisecond));
    index +=
        sizeof(edda_temperature_1_latency_edda_transducer_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_16_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_x_acceleration_gforce;
  static_assert((sizeof(edda_temperature_1_x_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_1_x_acceleration_max_gforce;
  static_assert((sizeof(edda_temperature_1_x_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_16;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 109;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_x_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_x_acceleration_gforce);
  }
  void set_edda_temperature_1_x_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_x_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_x_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_x_acceleration_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_x_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_x_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_x_acceleration_gforce,
           sizeof(edda_temperature_1_x_acceleration_gforce));
    *index += sizeof(edda_temperature_1_x_acceleration_gforce);
    memcpy(buf + *index, &edda_temperature_1_x_acceleration_max_gforce,
           sizeof(edda_temperature_1_x_acceleration_max_gforce));
    *index += sizeof(edda_temperature_1_x_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_x_acceleration_gforce, buf + index,
           sizeof(edda_temperature_1_x_acceleration_gforce));
    index += sizeof(edda_temperature_1_x_acceleration_gforce);
    memcpy(&edda_temperature_1_x_acceleration_max_gforce, buf + index,
           sizeof(edda_temperature_1_x_acceleration_max_gforce));
    index += sizeof(edda_temperature_1_x_acceleration_max_gforce);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_17_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_x_acceleration_min_gforce;
  static_assert((sizeof(edda_temperature_1_x_acceleration_min_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_1_y_acceleration_gforce;
  static_assert((sizeof(edda_temperature_1_y_acceleration_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_17;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 110;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_x_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_x_acceleration_min_gforce);
  }
  void set_edda_temperature_1_y_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_y_acceleration_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_x_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_x_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_y_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_y_acceleration_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_x_acceleration_min_gforce,
           sizeof(edda_temperature_1_x_acceleration_min_gforce));
    *index += sizeof(edda_temperature_1_x_acceleration_min_gforce);
    memcpy(buf + *index, &edda_temperature_1_y_acceleration_gforce,
           sizeof(edda_temperature_1_y_acceleration_gforce));
    *index += sizeof(edda_temperature_1_y_acceleration_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_x_acceleration_min_gforce, buf + index,
           sizeof(edda_temperature_1_x_acceleration_min_gforce));
    index += sizeof(edda_temperature_1_x_acceleration_min_gforce);
    memcpy(&edda_temperature_1_y_acceleration_gforce, buf + index,
           sizeof(edda_temperature_1_y_acceleration_gforce));
    index += sizeof(edda_temperature_1_y_acceleration_gforce);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_18_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_y_acceleration_max_gforce;
  static_assert((sizeof(edda_temperature_1_y_acceleration_max_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_1_y_acceleration_min_gforce;
  static_assert((sizeof(edda_temperature_1_y_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_18;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 111;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_y_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_y_acceleration_max_gforce);
  }
  void set_edda_temperature_1_y_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_y_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_y_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_y_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_y_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_y_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_y_acceleration_max_gforce,
           sizeof(edda_temperature_1_y_acceleration_max_gforce));
    *index += sizeof(edda_temperature_1_y_acceleration_max_gforce);
    memcpy(buf + *index, &edda_temperature_1_y_acceleration_min_gforce,
           sizeof(edda_temperature_1_y_acceleration_min_gforce));
    *index += sizeof(edda_temperature_1_y_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_y_acceleration_max_gforce, buf + index,
           sizeof(edda_temperature_1_y_acceleration_max_gforce));
    index += sizeof(edda_temperature_1_y_acceleration_max_gforce);
    memcpy(&edda_temperature_1_y_acceleration_min_gforce, buf + index,
           sizeof(edda_temperature_1_y_acceleration_min_gforce));
    index += sizeof(edda_temperature_1_y_acceleration_min_gforce);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_19_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_z_acceleration_gforce;
  static_assert((sizeof(edda_temperature_1_z_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_1_z_acceleration_max_gforce;
  static_assert((sizeof(edda_temperature_1_z_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_19;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 112;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_z_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_z_acceleration_gforce);
  }
  void set_edda_temperature_1_z_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_z_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_z_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_z_acceleration_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_1_z_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_z_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_z_acceleration_gforce,
           sizeof(edda_temperature_1_z_acceleration_gforce));
    *index += sizeof(edda_temperature_1_z_acceleration_gforce);
    memcpy(buf + *index, &edda_temperature_1_z_acceleration_max_gforce,
           sizeof(edda_temperature_1_z_acceleration_max_gforce));
    *index += sizeof(edda_temperature_1_z_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_z_acceleration_gforce, buf + index,
           sizeof(edda_temperature_1_z_acceleration_gforce));
    index += sizeof(edda_temperature_1_z_acceleration_gforce);
    memcpy(&edda_temperature_1_z_acceleration_max_gforce, buf + index,
           sizeof(edda_temperature_1_z_acceleration_max_gforce));
    index += sizeof(edda_temperature_1_z_acceleration_max_gforce);
  }
};

class
    Telemetry__TemperatureBoard1_edda_temperature_1_20_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_1_z_acceleration_min_gforce;
  static_assert((sizeof(edda_temperature_1_z_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_edda_temperature_1_20;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 113;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_1_z_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_1_z_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_1_z_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_1_z_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_1_z_acceleration_min_gforce,
           sizeof(edda_temperature_1_z_acceleration_min_gforce));
    *index += sizeof(edda_temperature_1_z_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_1_z_acceleration_min_gforce, buf + index,
           sizeof(edda_temperature_1_z_acceleration_min_gforce));
    index += sizeof(edda_temperature_1_z_acceleration_min_gforce);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_00_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_rtd_01_resistance_ohm;
  static_assert((sizeof(sindri_rtd_01_resistance_ohm) == 2), "invalid size");
  uint16_t sindri_rtd_01_voltage_volt;
  static_assert((sizeof(sindri_rtd_01_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_00;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 167;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_rtd_01_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &sindri_rtd_01_resistance_ohm);
  }
  void set_sindri_rtd_01_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &sindri_rtd_01_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_rtd_01_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_rtd_01_resistance_ohm, 0, 10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_rtd_01_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_rtd_01_voltage_volt, 0, 5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_rtd_01_resistance_ohm,
           sizeof(sindri_rtd_01_resistance_ohm));
    *index += sizeof(sindri_rtd_01_resistance_ohm);
    memcpy(buf + *index, &sindri_rtd_01_voltage_volt,
           sizeof(sindri_rtd_01_voltage_volt));
    *index += sizeof(sindri_rtd_01_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_rtd_01_resistance_ohm, buf + index,
           sizeof(sindri_rtd_01_resistance_ohm));
    index += sizeof(sindri_rtd_01_resistance_ohm);
    memcpy(&sindri_rtd_01_voltage_volt, buf + index,
           sizeof(sindri_rtd_01_voltage_volt));
    index += sizeof(sindri_rtd_01_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_01_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_rtd_02_resistance_ohm;
  static_assert((sizeof(sindri_rtd_02_resistance_ohm) == 2), "invalid size");
  uint16_t sindri_rtd_02_voltage_volt;
  static_assert((sizeof(sindri_rtd_02_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_01;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 168;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_rtd_02_resistance_ohm(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000, &sindri_rtd_02_resistance_ohm);
  }
  void set_sindri_rtd_02_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 5, &sindri_rtd_02_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_rtd_02_resistance_ohm() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_rtd_02_resistance_ohm, 0, 10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_rtd_02_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_rtd_02_voltage_volt, 0, 5, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_rtd_02_resistance_ohm,
           sizeof(sindri_rtd_02_resistance_ohm));
    *index += sizeof(sindri_rtd_02_resistance_ohm);
    memcpy(buf + *index, &sindri_rtd_02_voltage_volt,
           sizeof(sindri_rtd_02_voltage_volt));
    *index += sizeof(sindri_rtd_02_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_rtd_02_resistance_ohm, buf + index,
           sizeof(sindri_rtd_02_resistance_ohm));
    index += sizeof(sindri_rtd_02_resistance_ohm);
    memcpy(&sindri_rtd_02_voltage_volt, buf + index,
           sizeof(sindri_rtd_02_voltage_volt));
    index += sizeof(sindri_rtd_02_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_02_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_09_voltage_volt;
  static_assert((sizeof(sindri_therm_09_voltage_volt) == 2), "invalid size");
  uint16_t sindri_therm_10_voltage_volt;
  static_assert((sizeof(sindri_therm_10_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_02;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 169;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_09_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_09_voltage_volt);
  }
  void set_sindri_therm_10_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_10_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_09_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_09_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_10_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_10_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_09_voltage_volt,
           sizeof(sindri_therm_09_voltage_volt));
    *index += sizeof(sindri_therm_09_voltage_volt);
    memcpy(buf + *index, &sindri_therm_10_voltage_volt,
           sizeof(sindri_therm_10_voltage_volt));
    *index += sizeof(sindri_therm_10_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_09_voltage_volt, buf + index,
           sizeof(sindri_therm_09_voltage_volt));
    index += sizeof(sindri_therm_09_voltage_volt);
    memcpy(&sindri_therm_10_voltage_volt, buf + index,
           sizeof(sindri_therm_10_voltage_volt));
    index += sizeof(sindri_therm_10_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_03_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_11_voltage_volt;
  static_assert((sizeof(sindri_therm_11_voltage_volt) == 2), "invalid size");
  uint16_t sindri_therm_12_voltage_volt;
  static_assert((sizeof(sindri_therm_12_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_03;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 170;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_11_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_11_voltage_volt);
  }
  void set_sindri_therm_12_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_12_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_11_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_11_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_12_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_12_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_11_voltage_volt,
           sizeof(sindri_therm_11_voltage_volt));
    *index += sizeof(sindri_therm_11_voltage_volt);
    memcpy(buf + *index, &sindri_therm_12_voltage_volt,
           sizeof(sindri_therm_12_voltage_volt));
    *index += sizeof(sindri_therm_12_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_11_voltage_volt, buf + index,
           sizeof(sindri_therm_11_voltage_volt));
    index += sizeof(sindri_therm_11_voltage_volt);
    memcpy(&sindri_therm_12_voltage_volt, buf + index,
           sizeof(sindri_therm_12_voltage_volt));
    index += sizeof(sindri_therm_12_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_04_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_rtd_01_temperature_celsius;
  static_assert((sizeof(sindri_rtd_01_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_rtd_02_temperature_celsius;
  static_assert((sizeof(sindri_rtd_02_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_04;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 171;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_rtd_01_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300, &sindri_rtd_01_temperature_celsius);
  }
  void set_sindri_rtd_02_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300, &sindri_rtd_02_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_rtd_01_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_rtd_01_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_rtd_02_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_rtd_02_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_rtd_01_temperature_celsius,
           sizeof(sindri_rtd_01_temperature_celsius));
    *index += sizeof(sindri_rtd_01_temperature_celsius);
    memcpy(buf + *index, &sindri_rtd_02_temperature_celsius,
           sizeof(sindri_rtd_02_temperature_celsius));
    *index += sizeof(sindri_rtd_02_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_rtd_01_temperature_celsius, buf + index,
           sizeof(sindri_rtd_01_temperature_celsius));
    index += sizeof(sindri_rtd_01_temperature_celsius);
    memcpy(&sindri_rtd_02_temperature_celsius, buf + index,
           sizeof(sindri_rtd_02_temperature_celsius));
    index += sizeof(sindri_rtd_02_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_05_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_09_temperature_celsius;
  static_assert((sizeof(sindri_therm_09_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_therm_10_temperature_celsius;
  static_assert((sizeof(sindri_therm_10_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_05;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 172;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_09_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_09_temperature_celsius);
  }
  void set_sindri_therm_10_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_10_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_09_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_09_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_10_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_10_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_09_temperature_celsius,
           sizeof(sindri_therm_09_temperature_celsius));
    *index += sizeof(sindri_therm_09_temperature_celsius);
    memcpy(buf + *index, &sindri_therm_10_temperature_celsius,
           sizeof(sindri_therm_10_temperature_celsius));
    *index += sizeof(sindri_therm_10_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_09_temperature_celsius, buf + index,
           sizeof(sindri_therm_09_temperature_celsius));
    index += sizeof(sindri_therm_09_temperature_celsius);
    memcpy(&sindri_therm_10_temperature_celsius, buf + index,
           sizeof(sindri_therm_10_temperature_celsius));
    index += sizeof(sindri_therm_10_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard1_sindri_06_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_11_temperature_celsius;
  static_assert((sizeof(sindri_therm_11_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_therm_12_temperature_celsius;
  static_assert((sizeof(sindri_therm_12_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard1_sindri_06;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 173;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_11_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_11_temperature_celsius);
  }
  void set_sindri_therm_12_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_12_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_11_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_11_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_12_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_12_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_11_temperature_celsius,
           sizeof(sindri_therm_11_temperature_celsius));
    *index += sizeof(sindri_therm_11_temperature_celsius);
    memcpy(buf + *index, &sindri_therm_12_temperature_celsius,
           sizeof(sindri_therm_12_temperature_celsius));
    *index += sizeof(sindri_therm_12_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_11_temperature_celsius, buf + index,
           sizeof(sindri_therm_11_temperature_celsius));
    index += sizeof(sindri_therm_11_temperature_celsius);
    memcpy(&sindri_therm_12_temperature_celsius, buf + index,
           sizeof(sindri_therm_12_temperature_celsius));
    index += sizeof(sindri_therm_12_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_00_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_ambient_pressure_bar;
  static_assert((sizeof(edda_temperature_2_ambient_pressure_bar) == 2),
                "invalid size");
  uint16_t edda_temperature_2_can_rx_size_rate_byte;
  static_assert((sizeof(edda_temperature_2_can_rx_size_rate_byte) == 2),
                "invalid size");
  uint8_t edda_temperature_2_compensation_0_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_2_compensation_0_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_00;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 114;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_ambient_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5,
                        &edda_temperature_2_ambient_pressure_bar);
  }
  void set_edda_temperature_2_can_rx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_temperature_2_can_rx_size_rate_byte);
  }
  void set_edda_temperature_2_compensation_0_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_temperature_2_compensation_0_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_ambient_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_ambient_pressure_bar, 0, 1.5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_rx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_rx_size_rate_byte, 0, 125000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_compensation_0_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_compensation_0_temperature_celsius,
                        -20, 106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_ambient_pressure_bar,
           sizeof(edda_temperature_2_ambient_pressure_bar));
    *index += sizeof(edda_temperature_2_ambient_pressure_bar);
    memcpy(buf + *index, &edda_temperature_2_can_rx_size_rate_byte,
           sizeof(edda_temperature_2_can_rx_size_rate_byte));
    *index += sizeof(edda_temperature_2_can_rx_size_rate_byte);
    memcpy(buf + *index, &edda_temperature_2_compensation_0_temperature_celsius,
           sizeof(edda_temperature_2_compensation_0_temperature_celsius));
    *index += sizeof(edda_temperature_2_compensation_0_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_ambient_pressure_bar, buf + index,
           sizeof(edda_temperature_2_ambient_pressure_bar));
    index += sizeof(edda_temperature_2_ambient_pressure_bar);
    memcpy(&edda_temperature_2_can_rx_size_rate_byte, buf + index,
           sizeof(edda_temperature_2_can_rx_size_rate_byte));
    index += sizeof(edda_temperature_2_can_rx_size_rate_byte);
    memcpy(&edda_temperature_2_compensation_0_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_compensation_0_temperature_celsius));
    index += sizeof(edda_temperature_2_compensation_0_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_01_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_can_tx_size_rate_byte;
  static_assert((sizeof(edda_temperature_2_can_tx_size_rate_byte) == 2),
                "invalid size");
  uint16_t edda_temperature_2_latency_edda_controller_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_2_latency_edda_controller_time_millisecond) ==
       2),
      "invalid size");
  uint8_t edda_temperature_2_compensation_1_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_2_compensation_1_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_01;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 115;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_can_tx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_temperature_2_can_tx_size_rate_byte);
  }
  void set_edda_temperature_2_latency_edda_controller_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_controller_time_millisecond);
  }
  void set_edda_temperature_2_compensation_1_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 106,
                        &edda_temperature_2_compensation_1_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_tx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_tx_size_rate_byte, 0, 125000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_controller_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_controller_time_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_compensation_1_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_compensation_1_temperature_celsius,
                        -20, 106, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_can_tx_size_rate_byte,
           sizeof(edda_temperature_2_can_tx_size_rate_byte));
    *index += sizeof(edda_temperature_2_can_tx_size_rate_byte);
    memcpy(buf + *index,
           &edda_temperature_2_latency_edda_controller_time_millisecond,
           sizeof(edda_temperature_2_latency_edda_controller_time_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_controller_time_millisecond);
    memcpy(buf + *index, &edda_temperature_2_compensation_1_temperature_celsius,
           sizeof(edda_temperature_2_compensation_1_temperature_celsius));
    *index += sizeof(edda_temperature_2_compensation_1_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_can_tx_size_rate_byte, buf + index,
           sizeof(edda_temperature_2_can_tx_size_rate_byte));
    index += sizeof(edda_temperature_2_can_tx_size_rate_byte);
    memcpy(&edda_temperature_2_latency_edda_controller_time_millisecond,
           buf + index,
           sizeof(edda_temperature_2_latency_edda_controller_time_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_controller_time_millisecond);
    memcpy(&edda_temperature_2_compensation_1_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_compensation_1_temperature_celsius));
    index += sizeof(edda_temperature_2_compensation_1_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_02_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_latency_edda_ground_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_2_latency_edda_ground_time_millisecond) == 2),
      "invalid size");
  uint16_t edda_temperature_2_latency_edda_temperature_1_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_2_latency_edda_temperature_1_time_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_02;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 116;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_latency_edda_ground_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_ground_time_millisecond);
  }
  void set_edda_temperature_2_latency_edda_temperature_1_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_temperature_1_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_latency_edda_ground_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_latency_edda_ground_time_millisecond,
                        0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_temperature_1_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_temperature_1_time_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_temperature_2_latency_edda_ground_time_millisecond,
           sizeof(edda_temperature_2_latency_edda_ground_time_millisecond));
    *index += sizeof(edda_temperature_2_latency_edda_ground_time_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_temperature_1_time_millisecond,
        sizeof(edda_temperature_2_latency_edda_temperature_1_time_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_temperature_1_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_latency_edda_ground_time_millisecond,
           buf + index,
           sizeof(edda_temperature_2_latency_edda_ground_time_millisecond));
    index += sizeof(edda_temperature_2_latency_edda_ground_time_millisecond);
    memcpy(
        &edda_temperature_2_latency_edda_temperature_1_time_millisecond,
        buf + index,
        sizeof(edda_temperature_2_latency_edda_temperature_1_time_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_temperature_1_time_millisecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_03_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_latency_edda_transducer_time_millisecond;
  static_assert(
      (sizeof(edda_temperature_2_latency_edda_transducer_time_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_2_timing_time_freq_hertz;
  static_assert((sizeof(edda_temperature_2_timing_time_freq_hertz) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_03;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 117;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_latency_edda_transducer_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_transducer_time_millisecond);
  }
  void set_edda_temperature_2_timing_time_freq_hertz(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 2000,
                        &edda_temperature_2_timing_time_freq_hertz);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_transducer_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_transducer_time_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_timing_time_freq_hertz() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_timing_time_freq_hertz, 0, 2000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_temperature_2_latency_edda_transducer_time_millisecond,
           sizeof(edda_temperature_2_latency_edda_transducer_time_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_transducer_time_millisecond);
    memcpy(buf + *index, &edda_temperature_2_timing_time_freq_hertz,
           sizeof(edda_temperature_2_timing_time_freq_hertz));
    *index += sizeof(edda_temperature_2_timing_time_freq_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_latency_edda_transducer_time_millisecond,
           buf + index,
           sizeof(edda_temperature_2_latency_edda_transducer_time_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_transducer_time_millisecond);
    memcpy(&edda_temperature_2_timing_time_freq_hertz, buf + index,
           sizeof(edda_temperature_2_timing_time_freq_hertz));
    index += sizeof(edda_temperature_2_timing_time_freq_hertz);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_04_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_timing_time_max_microsecond;
  static_assert((sizeof(edda_temperature_2_timing_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_2_timing_time_microsecond;
  static_assert((sizeof(edda_temperature_2_timing_time_microsecond) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_04;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 118;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_2_timing_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_temperature_2_timing_time_max_microsecond);
  }
  void set_edda_temperature_2_timing_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_temperature_2_timing_time_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_timing_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_timing_time_max_microsecond, 0,
                        100000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_timing_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_timing_time_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_timing_time_max_microsecond,
           sizeof(edda_temperature_2_timing_time_max_microsecond));
    *index += sizeof(edda_temperature_2_timing_time_max_microsecond);
    memcpy(buf + *index, &edda_temperature_2_timing_time_microsecond,
           sizeof(edda_temperature_2_timing_time_microsecond));
    *index += sizeof(edda_temperature_2_timing_time_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_timing_time_max_microsecond, buf + index,
           sizeof(edda_temperature_2_timing_time_max_microsecond));
    index += sizeof(edda_temperature_2_timing_time_max_microsecond);
    memcpy(&edda_temperature_2_timing_time_microsecond, buf + index,
           sizeof(edda_temperature_2_timing_time_microsecond));
    index += sizeof(edda_temperature_2_timing_time_microsecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_05_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_timing_time_min_microsecond;
  static_assert((sizeof(edda_temperature_2_timing_time_min_microsecond) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_05;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 119;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_2_timing_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_temperature_2_timing_time_min_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_timing_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_timing_time_min_microsecond, 0,
                        100000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_timing_time_min_microsecond,
           sizeof(edda_temperature_2_timing_time_min_microsecond));
    *index += sizeof(edda_temperature_2_timing_time_min_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_timing_time_min_microsecond, buf + index,
           sizeof(edda_temperature_2_timing_time_min_microsecond));
    index += sizeof(edda_temperature_2_timing_time_min_microsecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_06_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_can_rx_time_max_microsecond;
  static_assert((sizeof(edda_temperature_2_can_rx_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_2_can_rx_time_microsecond;
  static_assert((sizeof(edda_temperature_2_can_rx_time_microsecond) == 2),
                "invalid size");
  uint8_t edda_temperature_2_board_temperature_celsius;
  static_assert((sizeof(edda_temperature_2_board_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_06;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 120;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_2_can_rx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_2_can_rx_time_max_microsecond);
  }
  void set_edda_temperature_2_can_rx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_2_can_rx_time_microsecond);
  }
  void set_edda_temperature_2_board_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_temperature_2_board_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_rx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_rx_time_max_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_rx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_rx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_board_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_board_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_can_rx_time_max_microsecond,
           sizeof(edda_temperature_2_can_rx_time_max_microsecond));
    *index += sizeof(edda_temperature_2_can_rx_time_max_microsecond);
    memcpy(buf + *index, &edda_temperature_2_can_rx_time_microsecond,
           sizeof(edda_temperature_2_can_rx_time_microsecond));
    *index += sizeof(edda_temperature_2_can_rx_time_microsecond);
    memcpy(buf + *index, &edda_temperature_2_board_temperature_celsius,
           sizeof(edda_temperature_2_board_temperature_celsius));
    *index += sizeof(edda_temperature_2_board_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_can_rx_time_max_microsecond, buf + index,
           sizeof(edda_temperature_2_can_rx_time_max_microsecond));
    index += sizeof(edda_temperature_2_can_rx_time_max_microsecond);
    memcpy(&edda_temperature_2_can_rx_time_microsecond, buf + index,
           sizeof(edda_temperature_2_can_rx_time_microsecond));
    index += sizeof(edda_temperature_2_can_rx_time_microsecond);
    memcpy(&edda_temperature_2_board_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_board_temperature_celsius));
    index += sizeof(edda_temperature_2_board_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_07_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_can_rx_time_min_microsecond;
  static_assert((sizeof(edda_temperature_2_can_rx_time_min_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_2_can_tx_time_max_microsecond;
  static_assert((sizeof(edda_temperature_2_can_tx_time_max_microsecond) == 2),
                "invalid size");
  uint8_t edda_temperature_2_humidity_sensor_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_2_humidity_sensor_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_07;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 121;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void
  set_edda_temperature_2_can_rx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_2_can_rx_time_min_microsecond);
  }
  void
  set_edda_temperature_2_can_tx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_2_can_tx_time_max_microsecond);
  }
  void set_edda_temperature_2_humidity_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 100,
        &edda_temperature_2_humidity_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_rx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_rx_time_min_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_tx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_tx_time_max_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_humidity_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_humidity_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_can_rx_time_min_microsecond,
           sizeof(edda_temperature_2_can_rx_time_min_microsecond));
    *index += sizeof(edda_temperature_2_can_rx_time_min_microsecond);
    memcpy(buf + *index, &edda_temperature_2_can_tx_time_max_microsecond,
           sizeof(edda_temperature_2_can_tx_time_max_microsecond));
    *index += sizeof(edda_temperature_2_can_tx_time_max_microsecond);
    memcpy(buf + *index,
           &edda_temperature_2_humidity_sensor_temperature_celsius,
           sizeof(edda_temperature_2_humidity_sensor_temperature_celsius));
    *index += sizeof(edda_temperature_2_humidity_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_can_rx_time_min_microsecond, buf + index,
           sizeof(edda_temperature_2_can_rx_time_min_microsecond));
    index += sizeof(edda_temperature_2_can_rx_time_min_microsecond);
    memcpy(&edda_temperature_2_can_tx_time_max_microsecond, buf + index,
           sizeof(edda_temperature_2_can_tx_time_max_microsecond));
    index += sizeof(edda_temperature_2_can_tx_time_max_microsecond);
    memcpy(&edda_temperature_2_humidity_sensor_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_humidity_sensor_temperature_celsius));
    index += sizeof(edda_temperature_2_humidity_sensor_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_08_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_can_tx_time_microsecond;
  static_assert((sizeof(edda_temperature_2_can_tx_time_microsecond) == 2),
                "invalid size");
  uint16_t edda_temperature_2_can_tx_time_min_microsecond;
  static_assert((sizeof(edda_temperature_2_can_tx_time_min_microsecond) == 2),
                "invalid size");
  uint8_t edda_temperature_2_imu_temperature_celsius;
  static_assert((sizeof(edda_temperature_2_imu_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_08;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 122;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_can_tx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_2_can_tx_time_microsecond);
  }
  void
  set_edda_temperature_2_can_tx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_temperature_2_can_tx_time_min_microsecond);
  }
  void set_edda_temperature_2_imu_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_temperature_2_imu_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_tx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_tx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_can_tx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_can_tx_time_min_microsecond, 0,
                        10000, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_imu_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_imu_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_can_tx_time_microsecond,
           sizeof(edda_temperature_2_can_tx_time_microsecond));
    *index += sizeof(edda_temperature_2_can_tx_time_microsecond);
    memcpy(buf + *index, &edda_temperature_2_can_tx_time_min_microsecond,
           sizeof(edda_temperature_2_can_tx_time_min_microsecond));
    *index += sizeof(edda_temperature_2_can_tx_time_min_microsecond);
    memcpy(buf + *index, &edda_temperature_2_imu_temperature_celsius,
           sizeof(edda_temperature_2_imu_temperature_celsius));
    *index += sizeof(edda_temperature_2_imu_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_can_tx_time_microsecond, buf + index,
           sizeof(edda_temperature_2_can_tx_time_microsecond));
    index += sizeof(edda_temperature_2_can_tx_time_microsecond);
    memcpy(&edda_temperature_2_can_tx_time_min_microsecond, buf + index,
           sizeof(edda_temperature_2_can_tx_time_min_microsecond));
    index += sizeof(edda_temperature_2_can_tx_time_min_microsecond);
    memcpy(&edda_temperature_2_imu_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_imu_temperature_celsius));
    index += sizeof(edda_temperature_2_imu_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_09_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_input_current_ampere;
  static_assert((sizeof(edda_temperature_2_input_current_ampere) == 2),
                "invalid size");
  uint16_t edda_temperature_2_input_current_max_ampere;
  static_assert((sizeof(edda_temperature_2_input_current_max_ampere) == 2),
                "invalid size");
  uint8_t edda_temperature_2_internal_temperature_celsius;
  static_assert((sizeof(edda_temperature_2_internal_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_09;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 123;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_input_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_temperature_2_input_current_ampere);
  }
  void set_edda_temperature_2_input_current_max_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_temperature_2_input_current_max_ampere);
  }
  void
  set_edda_temperature_2_internal_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_temperature_2_internal_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_input_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_input_current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_input_current_max_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_input_current_max_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_internal_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_internal_temperature_celsius, -20,
                        100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_input_current_ampere,
           sizeof(edda_temperature_2_input_current_ampere));
    *index += sizeof(edda_temperature_2_input_current_ampere);
    memcpy(buf + *index, &edda_temperature_2_input_current_max_ampere,
           sizeof(edda_temperature_2_input_current_max_ampere));
    *index += sizeof(edda_temperature_2_input_current_max_ampere);
    memcpy(buf + *index, &edda_temperature_2_internal_temperature_celsius,
           sizeof(edda_temperature_2_internal_temperature_celsius));
    *index += sizeof(edda_temperature_2_internal_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_input_current_ampere, buf + index,
           sizeof(edda_temperature_2_input_current_ampere));
    index += sizeof(edda_temperature_2_input_current_ampere);
    memcpy(&edda_temperature_2_input_current_max_ampere, buf + index,
           sizeof(edda_temperature_2_input_current_max_ampere));
    index += sizeof(edda_temperature_2_input_current_max_ampere);
    memcpy(&edda_temperature_2_internal_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_internal_temperature_celsius));
    index += sizeof(edda_temperature_2_internal_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_10_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_input_current_min_ampere;
  static_assert((sizeof(edda_temperature_2_input_current_min_ampere) == 2),
                "invalid size");
  uint16_t edda_temperature_2_input_voltage_max_volt;
  static_assert((sizeof(edda_temperature_2_input_voltage_max_volt) == 2),
                "invalid size");
  uint8_t edda_temperature_2_pressure_sensor_temperature_celsius;
  static_assert(
      (sizeof(edda_temperature_2_pressure_sensor_temperature_celsius) == 1),
      "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_10;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 124;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_input_current_min_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_temperature_2_input_current_min_ampere);
  }
  void set_edda_temperature_2_input_voltage_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_temperature_2_input_voltage_max_volt);
  }
  void set_edda_temperature_2_pressure_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, -20, 100,
        &edda_temperature_2_pressure_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_input_current_min_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_input_current_min_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_input_voltage_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_input_voltage_max_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_pressure_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_pressure_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_input_current_min_ampere,
           sizeof(edda_temperature_2_input_current_min_ampere));
    *index += sizeof(edda_temperature_2_input_current_min_ampere);
    memcpy(buf + *index, &edda_temperature_2_input_voltage_max_volt,
           sizeof(edda_temperature_2_input_voltage_max_volt));
    *index += sizeof(edda_temperature_2_input_voltage_max_volt);
    memcpy(buf + *index,
           &edda_temperature_2_pressure_sensor_temperature_celsius,
           sizeof(edda_temperature_2_pressure_sensor_temperature_celsius));
    *index += sizeof(edda_temperature_2_pressure_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_input_current_min_ampere, buf + index,
           sizeof(edda_temperature_2_input_current_min_ampere));
    index += sizeof(edda_temperature_2_input_current_min_ampere);
    memcpy(&edda_temperature_2_input_voltage_max_volt, buf + index,
           sizeof(edda_temperature_2_input_voltage_max_volt));
    index += sizeof(edda_temperature_2_input_voltage_max_volt);
    memcpy(&edda_temperature_2_pressure_sensor_temperature_celsius, buf + index,
           sizeof(edda_temperature_2_pressure_sensor_temperature_celsius));
    index += sizeof(edda_temperature_2_pressure_sensor_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_11_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_input_voltage_min_volt;
  static_assert((sizeof(edda_temperature_2_input_voltage_min_volt) == 2),
                "invalid size");
  uint16_t edda_temperature_2_input_voltage_volt;
  static_assert((sizeof(edda_temperature_2_input_voltage_volt) == 2),
                "invalid size");
  uint8_t edda_temperature_2_relative_humidity_percentage;
  static_assert((sizeof(edda_temperature_2_relative_humidity_percentage) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_11;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 125;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_input_voltage_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36,
                        &edda_temperature_2_input_voltage_min_volt);
  }
  void set_edda_temperature_2_input_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_temperature_2_input_voltage_volt);
  }
  void
  set_edda_temperature_2_relative_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100,
                        &edda_temperature_2_relative_humidity_percentage);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_input_voltage_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_input_voltage_min_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_input_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_input_voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_relative_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_relative_humidity_percentage, 0, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_input_voltage_min_volt,
           sizeof(edda_temperature_2_input_voltage_min_volt));
    *index += sizeof(edda_temperature_2_input_voltage_min_volt);
    memcpy(buf + *index, &edda_temperature_2_input_voltage_volt,
           sizeof(edda_temperature_2_input_voltage_volt));
    *index += sizeof(edda_temperature_2_input_voltage_volt);
    memcpy(buf + *index, &edda_temperature_2_relative_humidity_percentage,
           sizeof(edda_temperature_2_relative_humidity_percentage));
    *index += sizeof(edda_temperature_2_relative_humidity_percentage);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_input_voltage_min_volt, buf + index,
           sizeof(edda_temperature_2_input_voltage_min_volt));
    index += sizeof(edda_temperature_2_input_voltage_min_volt);
    memcpy(&edda_temperature_2_input_voltage_volt, buf + index,
           sizeof(edda_temperature_2_input_voltage_volt));
    index += sizeof(edda_temperature_2_input_voltage_volt);
    memcpy(&edda_temperature_2_relative_humidity_percentage, buf + index,
           sizeof(edda_temperature_2_relative_humidity_percentage));
    index += sizeof(edda_temperature_2_relative_humidity_percentage);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_12_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_latency_edda_controller_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_2_latency_edda_controller_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_2_latency_edda_controller_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_2_latency_edda_controller_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_12;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 126;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_latency_edda_controller_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_controller_time_max_millisecond);
  }
  void set_edda_temperature_2_latency_edda_controller_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_controller_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_controller_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_controller_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_controller_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_controller_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_controller_time_max_millisecond,
        sizeof(
            edda_temperature_2_latency_edda_controller_time_max_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_controller_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_controller_time_min_millisecond,
        sizeof(
            edda_temperature_2_latency_edda_controller_time_min_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_controller_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_temperature_2_latency_edda_controller_time_max_millisecond,
        buf + index,
        sizeof(
            edda_temperature_2_latency_edda_controller_time_max_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_controller_time_max_millisecond);
    memcpy(
        &edda_temperature_2_latency_edda_controller_time_min_millisecond,
        buf + index,
        sizeof(
            edda_temperature_2_latency_edda_controller_time_min_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_controller_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_13_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_latency_edda_ground_time_max_millisecond;
  static_assert(
      (sizeof(edda_temperature_2_latency_edda_ground_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_2_latency_edda_ground_time_min_millisecond;
  static_assert(
      (sizeof(edda_temperature_2_latency_edda_ground_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_13;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 127;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_latency_edda_ground_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_ground_time_max_millisecond);
  }
  void set_edda_temperature_2_latency_edda_ground_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_ground_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_ground_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_ground_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_ground_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_ground_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_temperature_2_latency_edda_ground_time_max_millisecond,
           sizeof(edda_temperature_2_latency_edda_ground_time_max_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_ground_time_max_millisecond);
    memcpy(buf + *index,
           &edda_temperature_2_latency_edda_ground_time_min_millisecond,
           sizeof(edda_temperature_2_latency_edda_ground_time_min_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_ground_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_latency_edda_ground_time_max_millisecond,
           buf + index,
           sizeof(edda_temperature_2_latency_edda_ground_time_max_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_ground_time_max_millisecond);
    memcpy(&edda_temperature_2_latency_edda_ground_time_min_millisecond,
           buf + index,
           sizeof(edda_temperature_2_latency_edda_ground_time_min_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_ground_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_14_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_latency_edda_temperature_1_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_2_latency_edda_temperature_1_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_2_latency_edda_temperature_1_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_2_latency_edda_temperature_1_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_14;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 128;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_latency_edda_temperature_1_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_temperature_1_time_max_millisecond);
  }
  void set_edda_temperature_2_latency_edda_temperature_1_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_temperature_1_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_temperature_1_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_temperature_1_time_max_millisecond, 0,
        500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_temperature_1_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_temperature_1_time_min_millisecond, 0,
        500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_temperature_1_time_max_millisecond,
        sizeof(
            edda_temperature_2_latency_edda_temperature_1_time_max_millisecond));
    *index += sizeof(
        edda_temperature_2_latency_edda_temperature_1_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_temperature_1_time_min_millisecond,
        sizeof(
            edda_temperature_2_latency_edda_temperature_1_time_min_millisecond));
    *index += sizeof(
        edda_temperature_2_latency_edda_temperature_1_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_temperature_2_latency_edda_temperature_1_time_max_millisecond,
        buf + index,
        sizeof(
            edda_temperature_2_latency_edda_temperature_1_time_max_millisecond));
    index += sizeof(
        edda_temperature_2_latency_edda_temperature_1_time_max_millisecond);
    memcpy(
        &edda_temperature_2_latency_edda_temperature_1_time_min_millisecond,
        buf + index,
        sizeof(
            edda_temperature_2_latency_edda_temperature_1_time_min_millisecond));
    index += sizeof(
        edda_temperature_2_latency_edda_temperature_1_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_15_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_latency_edda_transducer_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_2_latency_edda_transducer_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_temperature_2_latency_edda_transducer_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_temperature_2_latency_edda_transducer_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_15;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 129;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_latency_edda_transducer_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_transducer_time_max_millisecond);
  }
  void set_edda_temperature_2_latency_edda_transducer_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_temperature_2_latency_edda_transducer_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_transducer_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_transducer_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_temperature_2_latency_edda_transducer_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_temperature_2_latency_edda_transducer_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_transducer_time_max_millisecond,
        sizeof(
            edda_temperature_2_latency_edda_transducer_time_max_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_transducer_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_temperature_2_latency_edda_transducer_time_min_millisecond,
        sizeof(
            edda_temperature_2_latency_edda_transducer_time_min_millisecond));
    *index +=
        sizeof(edda_temperature_2_latency_edda_transducer_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_temperature_2_latency_edda_transducer_time_max_millisecond,
        buf + index,
        sizeof(
            edda_temperature_2_latency_edda_transducer_time_max_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_transducer_time_max_millisecond);
    memcpy(
        &edda_temperature_2_latency_edda_transducer_time_min_millisecond,
        buf + index,
        sizeof(
            edda_temperature_2_latency_edda_transducer_time_min_millisecond));
    index +=
        sizeof(edda_temperature_2_latency_edda_transducer_time_min_millisecond);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_16_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_x_acceleration_gforce;
  static_assert((sizeof(edda_temperature_2_x_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_2_x_acceleration_max_gforce;
  static_assert((sizeof(edda_temperature_2_x_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_16;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 130;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_x_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_x_acceleration_gforce);
  }
  void set_edda_temperature_2_x_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_x_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_x_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_x_acceleration_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_x_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_x_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_x_acceleration_gforce,
           sizeof(edda_temperature_2_x_acceleration_gforce));
    *index += sizeof(edda_temperature_2_x_acceleration_gforce);
    memcpy(buf + *index, &edda_temperature_2_x_acceleration_max_gforce,
           sizeof(edda_temperature_2_x_acceleration_max_gforce));
    *index += sizeof(edda_temperature_2_x_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_x_acceleration_gforce, buf + index,
           sizeof(edda_temperature_2_x_acceleration_gforce));
    index += sizeof(edda_temperature_2_x_acceleration_gforce);
    memcpy(&edda_temperature_2_x_acceleration_max_gforce, buf + index,
           sizeof(edda_temperature_2_x_acceleration_max_gforce));
    index += sizeof(edda_temperature_2_x_acceleration_max_gforce);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_17_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_x_acceleration_min_gforce;
  static_assert((sizeof(edda_temperature_2_x_acceleration_min_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_2_y_acceleration_gforce;
  static_assert((sizeof(edda_temperature_2_y_acceleration_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_17;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 131;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_x_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_x_acceleration_min_gforce);
  }
  void set_edda_temperature_2_y_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_y_acceleration_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_x_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_x_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_y_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_y_acceleration_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_x_acceleration_min_gforce,
           sizeof(edda_temperature_2_x_acceleration_min_gforce));
    *index += sizeof(edda_temperature_2_x_acceleration_min_gforce);
    memcpy(buf + *index, &edda_temperature_2_y_acceleration_gforce,
           sizeof(edda_temperature_2_y_acceleration_gforce));
    *index += sizeof(edda_temperature_2_y_acceleration_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_x_acceleration_min_gforce, buf + index,
           sizeof(edda_temperature_2_x_acceleration_min_gforce));
    index += sizeof(edda_temperature_2_x_acceleration_min_gforce);
    memcpy(&edda_temperature_2_y_acceleration_gforce, buf + index,
           sizeof(edda_temperature_2_y_acceleration_gforce));
    index += sizeof(edda_temperature_2_y_acceleration_gforce);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_18_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_y_acceleration_max_gforce;
  static_assert((sizeof(edda_temperature_2_y_acceleration_max_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_2_y_acceleration_min_gforce;
  static_assert((sizeof(edda_temperature_2_y_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_18;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 132;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_y_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_y_acceleration_max_gforce);
  }
  void set_edda_temperature_2_y_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_y_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_y_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_y_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_y_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_y_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_y_acceleration_max_gforce,
           sizeof(edda_temperature_2_y_acceleration_max_gforce));
    *index += sizeof(edda_temperature_2_y_acceleration_max_gforce);
    memcpy(buf + *index, &edda_temperature_2_y_acceleration_min_gforce,
           sizeof(edda_temperature_2_y_acceleration_min_gforce));
    *index += sizeof(edda_temperature_2_y_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_y_acceleration_max_gforce, buf + index,
           sizeof(edda_temperature_2_y_acceleration_max_gforce));
    index += sizeof(edda_temperature_2_y_acceleration_max_gforce);
    memcpy(&edda_temperature_2_y_acceleration_min_gforce, buf + index,
           sizeof(edda_temperature_2_y_acceleration_min_gforce));
    index += sizeof(edda_temperature_2_y_acceleration_min_gforce);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_19_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_z_acceleration_gforce;
  static_assert((sizeof(edda_temperature_2_z_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_temperature_2_z_acceleration_max_gforce;
  static_assert((sizeof(edda_temperature_2_z_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_19;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 133;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_z_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_z_acceleration_gforce);
  }
  void set_edda_temperature_2_z_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_z_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_z_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_z_acceleration_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_temperature_2_z_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_z_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_z_acceleration_gforce,
           sizeof(edda_temperature_2_z_acceleration_gforce));
    *index += sizeof(edda_temperature_2_z_acceleration_gforce);
    memcpy(buf + *index, &edda_temperature_2_z_acceleration_max_gforce,
           sizeof(edda_temperature_2_z_acceleration_max_gforce));
    *index += sizeof(edda_temperature_2_z_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_z_acceleration_gforce, buf + index,
           sizeof(edda_temperature_2_z_acceleration_gforce));
    index += sizeof(edda_temperature_2_z_acceleration_gforce);
    memcpy(&edda_temperature_2_z_acceleration_max_gforce, buf + index,
           sizeof(edda_temperature_2_z_acceleration_max_gforce));
    index += sizeof(edda_temperature_2_z_acceleration_max_gforce);
  }
};

class
    Telemetry__TemperatureBoard2_edda_temperature_2_20_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_temperature_2_z_acceleration_min_gforce;
  static_assert((sizeof(edda_temperature_2_z_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_edda_temperature_2_20;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 134;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_temperature_2_z_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_temperature_2_z_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_temperature_2_z_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_temperature_2_z_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_temperature_2_z_acceleration_min_gforce,
           sizeof(edda_temperature_2_z_acceleration_min_gforce));
    *index += sizeof(edda_temperature_2_z_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_temperature_2_z_acceleration_min_gforce, buf + index,
           sizeof(edda_temperature_2_z_acceleration_min_gforce));
    index += sizeof(edda_temperature_2_z_acceleration_min_gforce);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_00_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_01_temperature_celsius;
  static_assert((sizeof(sindri_therm_01_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_therm_02_temperature_celsius;
  static_assert((sizeof(sindri_therm_02_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_00;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 174;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_01_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_01_temperature_celsius);
  }
  void set_sindri_therm_02_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_02_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_01_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_01_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_02_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_02_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_01_temperature_celsius,
           sizeof(sindri_therm_01_temperature_celsius));
    *index += sizeof(sindri_therm_01_temperature_celsius);
    memcpy(buf + *index, &sindri_therm_02_temperature_celsius,
           sizeof(sindri_therm_02_temperature_celsius));
    *index += sizeof(sindri_therm_02_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_01_temperature_celsius, buf + index,
           sizeof(sindri_therm_01_temperature_celsius));
    index += sizeof(sindri_therm_01_temperature_celsius);
    memcpy(&sindri_therm_02_temperature_celsius, buf + index,
           sizeof(sindri_therm_02_temperature_celsius));
    index += sizeof(sindri_therm_02_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_01_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_03_temperature_celsius;
  static_assert((sizeof(sindri_therm_03_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_therm_04_temperature_celsius;
  static_assert((sizeof(sindri_therm_04_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_01;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 175;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_03_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_03_temperature_celsius);
  }
  void set_sindri_therm_04_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_04_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_03_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_03_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_04_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_04_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_03_temperature_celsius,
           sizeof(sindri_therm_03_temperature_celsius));
    *index += sizeof(sindri_therm_03_temperature_celsius);
    memcpy(buf + *index, &sindri_therm_04_temperature_celsius,
           sizeof(sindri_therm_04_temperature_celsius));
    *index += sizeof(sindri_therm_04_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_03_temperature_celsius, buf + index,
           sizeof(sindri_therm_03_temperature_celsius));
    index += sizeof(sindri_therm_03_temperature_celsius);
    memcpy(&sindri_therm_04_temperature_celsius, buf + index,
           sizeof(sindri_therm_04_temperature_celsius));
    index += sizeof(sindri_therm_04_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_02_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_05_temperature_celsius;
  static_assert((sizeof(sindri_therm_05_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_therm_06_temperature_celsius;
  static_assert((sizeof(sindri_therm_06_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_02;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 176;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_05_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_05_temperature_celsius);
  }
  void set_sindri_therm_06_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_06_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_05_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_05_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_06_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_06_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_05_temperature_celsius,
           sizeof(sindri_therm_05_temperature_celsius));
    *index += sizeof(sindri_therm_05_temperature_celsius);
    memcpy(buf + *index, &sindri_therm_06_temperature_celsius,
           sizeof(sindri_therm_06_temperature_celsius));
    *index += sizeof(sindri_therm_06_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_05_temperature_celsius, buf + index,
           sizeof(sindri_therm_05_temperature_celsius));
    index += sizeof(sindri_therm_05_temperature_celsius);
    memcpy(&sindri_therm_06_temperature_celsius, buf + index,
           sizeof(sindri_therm_06_temperature_celsius));
    index += sizeof(sindri_therm_06_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_03_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_07_temperature_celsius;
  static_assert((sizeof(sindri_therm_07_temperature_celsius) == 2),
                "invalid size");
  uint16_t sindri_therm_08_temperature_celsius;
  static_assert((sizeof(sindri_therm_08_temperature_celsius) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_03;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 177;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_07_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_07_temperature_celsius);
  }
  void set_sindri_therm_08_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -200, 1300,
                        &sindri_therm_08_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_07_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_07_temperature_celsius, -200, 1300, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_08_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_08_temperature_celsius, -200, 1300, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_07_temperature_celsius,
           sizeof(sindri_therm_07_temperature_celsius));
    *index += sizeof(sindri_therm_07_temperature_celsius);
    memcpy(buf + *index, &sindri_therm_08_temperature_celsius,
           sizeof(sindri_therm_08_temperature_celsius));
    *index += sizeof(sindri_therm_08_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_07_temperature_celsius, buf + index,
           sizeof(sindri_therm_07_temperature_celsius));
    index += sizeof(sindri_therm_07_temperature_celsius);
    memcpy(&sindri_therm_08_temperature_celsius, buf + index,
           sizeof(sindri_therm_08_temperature_celsius));
    index += sizeof(sindri_therm_08_temperature_celsius);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_04_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_01_voltage_volt;
  static_assert((sizeof(sindri_therm_01_voltage_volt) == 2), "invalid size");
  uint16_t sindri_therm_02_voltage_volt;
  static_assert((sizeof(sindri_therm_02_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_04;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 178;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_01_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_01_voltage_volt);
  }
  void set_sindri_therm_02_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_02_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_01_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_01_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_02_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_02_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_01_voltage_volt,
           sizeof(sindri_therm_01_voltage_volt));
    *index += sizeof(sindri_therm_01_voltage_volt);
    memcpy(buf + *index, &sindri_therm_02_voltage_volt,
           sizeof(sindri_therm_02_voltage_volt));
    *index += sizeof(sindri_therm_02_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_01_voltage_volt, buf + index,
           sizeof(sindri_therm_01_voltage_volt));
    index += sizeof(sindri_therm_01_voltage_volt);
    memcpy(&sindri_therm_02_voltage_volt, buf + index,
           sizeof(sindri_therm_02_voltage_volt));
    index += sizeof(sindri_therm_02_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_05_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_03_voltage_volt;
  static_assert((sizeof(sindri_therm_03_voltage_volt) == 2), "invalid size");
  uint16_t sindri_therm_04_voltage_volt;
  static_assert((sizeof(sindri_therm_04_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_05;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 179;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_03_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_03_voltage_volt);
  }
  void set_sindri_therm_04_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_04_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_03_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_03_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_04_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_04_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_03_voltage_volt,
           sizeof(sindri_therm_03_voltage_volt));
    *index += sizeof(sindri_therm_03_voltage_volt);
    memcpy(buf + *index, &sindri_therm_04_voltage_volt,
           sizeof(sindri_therm_04_voltage_volt));
    *index += sizeof(sindri_therm_04_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_03_voltage_volt, buf + index,
           sizeof(sindri_therm_03_voltage_volt));
    index += sizeof(sindri_therm_03_voltage_volt);
    memcpy(&sindri_therm_04_voltage_volt, buf + index,
           sizeof(sindri_therm_04_voltage_volt));
    index += sizeof(sindri_therm_04_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_06_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_05_voltage_volt;
  static_assert((sizeof(sindri_therm_05_voltage_volt) == 2), "invalid size");
  uint16_t sindri_therm_06_voltage_volt;
  static_assert((sizeof(sindri_therm_06_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_06;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 180;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_05_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_05_voltage_volt);
  }
  void set_sindri_therm_06_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_06_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_05_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_05_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_06_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_06_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_05_voltage_volt,
           sizeof(sindri_therm_05_voltage_volt));
    *index += sizeof(sindri_therm_05_voltage_volt);
    memcpy(buf + *index, &sindri_therm_06_voltage_volt,
           sizeof(sindri_therm_06_voltage_volt));
    *index += sizeof(sindri_therm_06_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_05_voltage_volt, buf + index,
           sizeof(sindri_therm_05_voltage_volt));
    index += sizeof(sindri_therm_05_voltage_volt);
    memcpy(&sindri_therm_06_voltage_volt, buf + index,
           sizeof(sindri_therm_06_voltage_volt));
    index += sizeof(sindri_therm_06_voltage_volt);
  }
};

class
    Telemetry__TemperatureBoard2_sindri_07_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_therm_07_voltage_volt;
  static_assert((sizeof(sindri_therm_07_voltage_volt) == 2), "invalid size");
  uint16_t sindri_therm_08_voltage_volt;
  static_assert((sizeof(sindri_therm_08_voltage_volt) == 2), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TemperatureBoard2_sindri_07;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 181;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_therm_07_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_07_voltage_volt);
  }
  void set_sindri_therm_08_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -0.1, 0.1, &sindri_therm_08_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_therm_07_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_07_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_therm_08_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_therm_08_voltage_volt, -0.1, 0.1, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_therm_07_voltage_volt,
           sizeof(sindri_therm_07_voltage_volt));
    *index += sizeof(sindri_therm_07_voltage_volt);
    memcpy(buf + *index, &sindri_therm_08_voltage_volt,
           sizeof(sindri_therm_08_voltage_volt));
    *index += sizeof(sindri_therm_08_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_therm_07_voltage_volt, buf + index,
           sizeof(sindri_therm_07_voltage_volt));
    index += sizeof(sindri_therm_07_voltage_volt);
    memcpy(&sindri_therm_08_voltage_volt, buf + index,
           sizeof(sindri_therm_08_voltage_volt));
    index += sizeof(sindri_therm_08_voltage_volt);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_00_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_ambient_pressure_bar;
  static_assert((sizeof(edda_transducer_ambient_pressure_bar) == 2),
                "invalid size");
  uint16_t edda_transducer_can_rx_size_rate_byte;
  static_assert((sizeof(edda_transducer_can_rx_size_rate_byte) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_00;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 135;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_ambient_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 1.5, &edda_transducer_ambient_pressure_bar);
  }
  void set_edda_transducer_can_rx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_transducer_can_rx_size_rate_byte);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_ambient_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_ambient_pressure_bar, 0, 1.5, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_can_rx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_rx_size_rate_byte, 0, 125000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_ambient_pressure_bar,
           sizeof(edda_transducer_ambient_pressure_bar));
    *index += sizeof(edda_transducer_ambient_pressure_bar);
    memcpy(buf + *index, &edda_transducer_can_rx_size_rate_byte,
           sizeof(edda_transducer_can_rx_size_rate_byte));
    *index += sizeof(edda_transducer_can_rx_size_rate_byte);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_ambient_pressure_bar, buf + index,
           sizeof(edda_transducer_ambient_pressure_bar));
    index += sizeof(edda_transducer_ambient_pressure_bar);
    memcpy(&edda_transducer_can_rx_size_rate_byte, buf + index,
           sizeof(edda_transducer_can_rx_size_rate_byte));
    index += sizeof(edda_transducer_can_rx_size_rate_byte);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_01_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_can_tx_size_rate_byte;
  static_assert((sizeof(edda_transducer_can_tx_size_rate_byte) == 2),
                "invalid size");
  uint16_t edda_transducer_latency_edda_controller_time_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_controller_time_millisecond) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_01;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 136;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_can_tx_size_rate_byte(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 125000,
                        &edda_transducer_can_tx_size_rate_byte);
  }
  void set_edda_transducer_latency_edda_controller_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_controller_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_can_tx_size_rate_byte() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_tx_size_rate_byte, 0, 125000, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_controller_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_controller_time_millisecond, 0, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_can_tx_size_rate_byte,
           sizeof(edda_transducer_can_tx_size_rate_byte));
    *index += sizeof(edda_transducer_can_tx_size_rate_byte);
    memcpy(buf + *index,
           &edda_transducer_latency_edda_controller_time_millisecond,
           sizeof(edda_transducer_latency_edda_controller_time_millisecond));
    *index += sizeof(edda_transducer_latency_edda_controller_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_can_tx_size_rate_byte, buf + index,
           sizeof(edda_transducer_can_tx_size_rate_byte));
    index += sizeof(edda_transducer_can_tx_size_rate_byte);
    memcpy(&edda_transducer_latency_edda_controller_time_millisecond,
           buf + index,
           sizeof(edda_transducer_latency_edda_controller_time_millisecond));
    index += sizeof(edda_transducer_latency_edda_controller_time_millisecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_02_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_latency_edda_ground_time_millisecond;
  static_assert((sizeof(edda_transducer_latency_edda_ground_time_millisecond) ==
                 2),
                "invalid size");
  uint16_t edda_transducer_latency_edda_temperature_1_time_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_temperature_1_time_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_02;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 137;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_latency_edda_ground_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 500,
                        &edda_transducer_latency_edda_ground_time_millisecond);
  }
  void set_edda_transducer_latency_edda_temperature_1_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_temperature_1_time_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_latency_edda_ground_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_latency_edda_ground_time_millisecond, 0,
                        500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_temperature_1_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_temperature_1_time_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_latency_edda_ground_time_millisecond,
           sizeof(edda_transducer_latency_edda_ground_time_millisecond));
    *index += sizeof(edda_transducer_latency_edda_ground_time_millisecond);
    memcpy(buf + *index,
           &edda_transducer_latency_edda_temperature_1_time_millisecond,
           sizeof(edda_transducer_latency_edda_temperature_1_time_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_temperature_1_time_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_latency_edda_ground_time_millisecond, buf + index,
           sizeof(edda_transducer_latency_edda_ground_time_millisecond));
    index += sizeof(edda_transducer_latency_edda_ground_time_millisecond);
    memcpy(&edda_transducer_latency_edda_temperature_1_time_millisecond,
           buf + index,
           sizeof(edda_transducer_latency_edda_temperature_1_time_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_temperature_1_time_millisecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_03_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_latency_edda_temperature_2_time_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_temperature_2_time_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_transducer_timing_time_freq_hertz;
  static_assert((sizeof(edda_transducer_timing_time_freq_hertz) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_03;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 138;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_latency_edda_temperature_2_time_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_temperature_2_time_millisecond);
  }
  void set_edda_transducer_timing_time_freq_hertz(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 2000,
                        &edda_transducer_timing_time_freq_hertz);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_temperature_2_time_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_temperature_2_time_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_timing_time_freq_hertz() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_timing_time_freq_hertz, 0, 2000, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_transducer_latency_edda_temperature_2_time_millisecond,
           sizeof(edda_transducer_latency_edda_temperature_2_time_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_temperature_2_time_millisecond);
    memcpy(buf + *index, &edda_transducer_timing_time_freq_hertz,
           sizeof(edda_transducer_timing_time_freq_hertz));
    *index += sizeof(edda_transducer_timing_time_freq_hertz);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_latency_edda_temperature_2_time_millisecond,
           buf + index,
           sizeof(edda_transducer_latency_edda_temperature_2_time_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_temperature_2_time_millisecond);
    memcpy(&edda_transducer_timing_time_freq_hertz, buf + index,
           sizeof(edda_transducer_timing_time_freq_hertz));
    index += sizeof(edda_transducer_timing_time_freq_hertz);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_04_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_timing_time_max_microsecond;
  static_assert((sizeof(edda_transducer_timing_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_transducer_timing_time_microsecond;
  static_assert((sizeof(edda_transducer_timing_time_microsecond) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_04;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 139;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_timing_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_transducer_timing_time_max_microsecond);
  }
  void set_edda_transducer_timing_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_transducer_timing_time_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_timing_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_timing_time_max_microsecond, 0, 100000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_timing_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_timing_time_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_timing_time_max_microsecond,
           sizeof(edda_transducer_timing_time_max_microsecond));
    *index += sizeof(edda_transducer_timing_time_max_microsecond);
    memcpy(buf + *index, &edda_transducer_timing_time_microsecond,
           sizeof(edda_transducer_timing_time_microsecond));
    *index += sizeof(edda_transducer_timing_time_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_timing_time_max_microsecond, buf + index,
           sizeof(edda_transducer_timing_time_max_microsecond));
    index += sizeof(edda_transducer_timing_time_max_microsecond);
    memcpy(&edda_transducer_timing_time_microsecond, buf + index,
           sizeof(edda_transducer_timing_time_microsecond));
    index += sizeof(edda_transducer_timing_time_microsecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_05_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_timing_time_min_microsecond;
  static_assert((sizeof(edda_transducer_timing_time_min_microsecond) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_05;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 140;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_timing_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100000,
                        &edda_transducer_timing_time_min_microsecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_timing_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_timing_time_min_microsecond, 0, 100000,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_timing_time_min_microsecond,
           sizeof(edda_transducer_timing_time_min_microsecond));
    *index += sizeof(edda_transducer_timing_time_min_microsecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_timing_time_min_microsecond, buf + index,
           sizeof(edda_transducer_timing_time_min_microsecond));
    index += sizeof(edda_transducer_timing_time_min_microsecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_06_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_can_rx_time_max_microsecond;
  static_assert((sizeof(edda_transducer_can_rx_time_max_microsecond) == 2),
                "invalid size");
  uint16_t edda_transducer_can_rx_time_microsecond;
  static_assert((sizeof(edda_transducer_can_rx_time_microsecond) == 2),
                "invalid size");
  uint8_t edda_transducer_board_temperature_celsius;
  static_assert((sizeof(edda_transducer_board_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_06;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 141;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_can_rx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_transducer_can_rx_time_max_microsecond);
  }
  void set_edda_transducer_can_rx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_transducer_can_rx_time_microsecond);
  }
  void set_edda_transducer_board_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_transducer_board_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_can_rx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_rx_time_max_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_can_rx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_rx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_board_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_board_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_can_rx_time_max_microsecond,
           sizeof(edda_transducer_can_rx_time_max_microsecond));
    *index += sizeof(edda_transducer_can_rx_time_max_microsecond);
    memcpy(buf + *index, &edda_transducer_can_rx_time_microsecond,
           sizeof(edda_transducer_can_rx_time_microsecond));
    *index += sizeof(edda_transducer_can_rx_time_microsecond);
    memcpy(buf + *index, &edda_transducer_board_temperature_celsius,
           sizeof(edda_transducer_board_temperature_celsius));
    *index += sizeof(edda_transducer_board_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_can_rx_time_max_microsecond, buf + index,
           sizeof(edda_transducer_can_rx_time_max_microsecond));
    index += sizeof(edda_transducer_can_rx_time_max_microsecond);
    memcpy(&edda_transducer_can_rx_time_microsecond, buf + index,
           sizeof(edda_transducer_can_rx_time_microsecond));
    index += sizeof(edda_transducer_can_rx_time_microsecond);
    memcpy(&edda_transducer_board_temperature_celsius, buf + index,
           sizeof(edda_transducer_board_temperature_celsius));
    index += sizeof(edda_transducer_board_temperature_celsius);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_07_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_can_rx_time_min_microsecond;
  static_assert((sizeof(edda_transducer_can_rx_time_min_microsecond) == 2),
                "invalid size");
  uint16_t edda_transducer_can_tx_time_max_microsecond;
  static_assert((sizeof(edda_transducer_can_tx_time_max_microsecond) == 2),
                "invalid size");
  uint8_t edda_transducer_humidity_sensor_temperature_celsius;
  static_assert((sizeof(edda_transducer_humidity_sensor_temperature_celsius) ==
                 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_07;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 142;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_can_rx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_transducer_can_rx_time_min_microsecond);
  }
  void set_edda_transducer_can_tx_time_max_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_transducer_can_tx_time_max_microsecond);
  }
  void set_edda_transducer_humidity_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_transducer_humidity_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_can_rx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_rx_time_min_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_can_tx_time_max_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_tx_time_max_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_humidity_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_humidity_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_can_rx_time_min_microsecond,
           sizeof(edda_transducer_can_rx_time_min_microsecond));
    *index += sizeof(edda_transducer_can_rx_time_min_microsecond);
    memcpy(buf + *index, &edda_transducer_can_tx_time_max_microsecond,
           sizeof(edda_transducer_can_tx_time_max_microsecond));
    *index += sizeof(edda_transducer_can_tx_time_max_microsecond);
    memcpy(buf + *index, &edda_transducer_humidity_sensor_temperature_celsius,
           sizeof(edda_transducer_humidity_sensor_temperature_celsius));
    *index += sizeof(edda_transducer_humidity_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_can_rx_time_min_microsecond, buf + index,
           sizeof(edda_transducer_can_rx_time_min_microsecond));
    index += sizeof(edda_transducer_can_rx_time_min_microsecond);
    memcpy(&edda_transducer_can_tx_time_max_microsecond, buf + index,
           sizeof(edda_transducer_can_tx_time_max_microsecond));
    index += sizeof(edda_transducer_can_tx_time_max_microsecond);
    memcpy(&edda_transducer_humidity_sensor_temperature_celsius, buf + index,
           sizeof(edda_transducer_humidity_sensor_temperature_celsius));
    index += sizeof(edda_transducer_humidity_sensor_temperature_celsius);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_08_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_can_tx_time_microsecond;
  static_assert((sizeof(edda_transducer_can_tx_time_microsecond) == 2),
                "invalid size");
  uint16_t edda_transducer_can_tx_time_min_microsecond;
  static_assert((sizeof(edda_transducer_can_tx_time_min_microsecond) == 2),
                "invalid size");
  uint8_t edda_transducer_imu_temperature_celsius;
  static_assert((sizeof(edda_transducer_imu_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_08;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 143;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_can_tx_time_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_transducer_can_tx_time_microsecond);
  }
  void set_edda_transducer_can_tx_time_min_microsecond(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10000,
                        &edda_transducer_can_tx_time_min_microsecond);
  }
  void set_edda_transducer_imu_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_transducer_imu_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_can_tx_time_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_tx_time_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_can_tx_time_min_microsecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_can_tx_time_min_microsecond, 0, 10000,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_imu_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_imu_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_can_tx_time_microsecond,
           sizeof(edda_transducer_can_tx_time_microsecond));
    *index += sizeof(edda_transducer_can_tx_time_microsecond);
    memcpy(buf + *index, &edda_transducer_can_tx_time_min_microsecond,
           sizeof(edda_transducer_can_tx_time_min_microsecond));
    *index += sizeof(edda_transducer_can_tx_time_min_microsecond);
    memcpy(buf + *index, &edda_transducer_imu_temperature_celsius,
           sizeof(edda_transducer_imu_temperature_celsius));
    *index += sizeof(edda_transducer_imu_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_can_tx_time_microsecond, buf + index,
           sizeof(edda_transducer_can_tx_time_microsecond));
    index += sizeof(edda_transducer_can_tx_time_microsecond);
    memcpy(&edda_transducer_can_tx_time_min_microsecond, buf + index,
           sizeof(edda_transducer_can_tx_time_min_microsecond));
    index += sizeof(edda_transducer_can_tx_time_min_microsecond);
    memcpy(&edda_transducer_imu_temperature_celsius, buf + index,
           sizeof(edda_transducer_imu_temperature_celsius));
    index += sizeof(edda_transducer_imu_temperature_celsius);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_09_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_input_current_ampere;
  static_assert((sizeof(edda_transducer_input_current_ampere) == 2),
                "invalid size");
  uint16_t edda_transducer_input_current_max_ampere;
  static_assert((sizeof(edda_transducer_input_current_max_ampere) == 2),
                "invalid size");
  uint8_t edda_transducer_internal_temperature_celsius;
  static_assert((sizeof(edda_transducer_internal_temperature_celsius) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_09;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 144;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_input_current_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15, &edda_transducer_input_current_ampere);
  }
  void set_edda_transducer_input_current_max_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_transducer_input_current_max_ampere);
  }
  void set_edda_transducer_internal_temperature_celsius(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_transducer_internal_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_input_current_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_input_current_ampere, -15, 15, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_input_current_max_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_input_current_max_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_internal_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_internal_temperature_celsius, -20, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_input_current_ampere,
           sizeof(edda_transducer_input_current_ampere));
    *index += sizeof(edda_transducer_input_current_ampere);
    memcpy(buf + *index, &edda_transducer_input_current_max_ampere,
           sizeof(edda_transducer_input_current_max_ampere));
    *index += sizeof(edda_transducer_input_current_max_ampere);
    memcpy(buf + *index, &edda_transducer_internal_temperature_celsius,
           sizeof(edda_transducer_internal_temperature_celsius));
    *index += sizeof(edda_transducer_internal_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_input_current_ampere, buf + index,
           sizeof(edda_transducer_input_current_ampere));
    index += sizeof(edda_transducer_input_current_ampere);
    memcpy(&edda_transducer_input_current_max_ampere, buf + index,
           sizeof(edda_transducer_input_current_max_ampere));
    index += sizeof(edda_transducer_input_current_max_ampere);
    memcpy(&edda_transducer_internal_temperature_celsius, buf + index,
           sizeof(edda_transducer_internal_temperature_celsius));
    index += sizeof(edda_transducer_internal_temperature_celsius);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_10_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_input_current_min_ampere;
  static_assert((sizeof(edda_transducer_input_current_min_ampere) == 2),
                "invalid size");
  uint16_t edda_transducer_input_voltage_max_volt;
  static_assert((sizeof(edda_transducer_input_voltage_max_volt) == 2),
                "invalid size");
  uint8_t edda_transducer_pressure_sensor_temperature_celsius;
  static_assert((sizeof(edda_transducer_pressure_sensor_temperature_celsius) ==
                 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_10;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 145;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_input_current_min_ampere(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -15, 15,
                        &edda_transducer_input_current_min_ampere);
  }
  void set_edda_transducer_input_voltage_max_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_transducer_input_voltage_max_volt);
  }
  void set_edda_transducer_pressure_sensor_temperature_celsius(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 100,
                        &edda_transducer_pressure_sensor_temperature_celsius);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_input_current_min_ampere() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_input_current_min_ampere, -15, 15,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_input_voltage_max_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_input_voltage_max_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_pressure_sensor_temperature_celsius() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_pressure_sensor_temperature_celsius,
                        -20, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_input_current_min_ampere,
           sizeof(edda_transducer_input_current_min_ampere));
    *index += sizeof(edda_transducer_input_current_min_ampere);
    memcpy(buf + *index, &edda_transducer_input_voltage_max_volt,
           sizeof(edda_transducer_input_voltage_max_volt));
    *index += sizeof(edda_transducer_input_voltage_max_volt);
    memcpy(buf + *index, &edda_transducer_pressure_sensor_temperature_celsius,
           sizeof(edda_transducer_pressure_sensor_temperature_celsius));
    *index += sizeof(edda_transducer_pressure_sensor_temperature_celsius);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_input_current_min_ampere, buf + index,
           sizeof(edda_transducer_input_current_min_ampere));
    index += sizeof(edda_transducer_input_current_min_ampere);
    memcpy(&edda_transducer_input_voltage_max_volt, buf + index,
           sizeof(edda_transducer_input_voltage_max_volt));
    index += sizeof(edda_transducer_input_voltage_max_volt);
    memcpy(&edda_transducer_pressure_sensor_temperature_celsius, buf + index,
           sizeof(edda_transducer_pressure_sensor_temperature_celsius));
    index += sizeof(edda_transducer_pressure_sensor_temperature_celsius);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_11_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_input_voltage_min_volt;
  static_assert((sizeof(edda_transducer_input_voltage_min_volt) == 2),
                "invalid size");
  uint16_t edda_transducer_input_voltage_volt;
  static_assert((sizeof(edda_transducer_input_voltage_volt) == 2),
                "invalid size");
  uint8_t edda_transducer_relative_humidity_percentage;
  static_assert((sizeof(edda_transducer_relative_humidity_percentage) == 1),
                "invalid size");
  uint8_t size = 8;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_11;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 146;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_input_voltage_min_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_transducer_input_voltage_min_volt);
  }
  void set_edda_transducer_input_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 36, &edda_transducer_input_voltage_volt);
  }
  void set_edda_transducer_relative_humidity_percentage(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 100,
                        &edda_transducer_relative_humidity_percentage);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_input_voltage_min_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_input_voltage_min_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_input_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_input_voltage_volt, 0, 36, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_relative_humidity_percentage() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_relative_humidity_percentage, 0, 100,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_input_voltage_min_volt,
           sizeof(edda_transducer_input_voltage_min_volt));
    *index += sizeof(edda_transducer_input_voltage_min_volt);
    memcpy(buf + *index, &edda_transducer_input_voltage_volt,
           sizeof(edda_transducer_input_voltage_volt));
    *index += sizeof(edda_transducer_input_voltage_volt);
    memcpy(buf + *index, &edda_transducer_relative_humidity_percentage,
           sizeof(edda_transducer_relative_humidity_percentage));
    *index += sizeof(edda_transducer_relative_humidity_percentage);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_input_voltage_min_volt, buf + index,
           sizeof(edda_transducer_input_voltage_min_volt));
    index += sizeof(edda_transducer_input_voltage_min_volt);
    memcpy(&edda_transducer_input_voltage_volt, buf + index,
           sizeof(edda_transducer_input_voltage_volt));
    index += sizeof(edda_transducer_input_voltage_volt);
    memcpy(&edda_transducer_relative_humidity_percentage, buf + index,
           sizeof(edda_transducer_relative_humidity_percentage));
    index += sizeof(edda_transducer_relative_humidity_percentage);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_12_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_latency_edda_controller_time_max_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_controller_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_transducer_latency_edda_controller_time_min_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_controller_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_12;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 147;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_latency_edda_controller_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_controller_time_max_millisecond);
  }
  void set_edda_transducer_latency_edda_controller_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_controller_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_controller_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_controller_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_controller_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_controller_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_transducer_latency_edda_controller_time_max_millisecond,
        sizeof(edda_transducer_latency_edda_controller_time_max_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_controller_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_transducer_latency_edda_controller_time_min_millisecond,
        sizeof(edda_transducer_latency_edda_controller_time_min_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_controller_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_transducer_latency_edda_controller_time_max_millisecond,
        buf + index,
        sizeof(edda_transducer_latency_edda_controller_time_max_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_controller_time_max_millisecond);
    memcpy(
        &edda_transducer_latency_edda_controller_time_min_millisecond,
        buf + index,
        sizeof(edda_transducer_latency_edda_controller_time_min_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_controller_time_min_millisecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_13_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_latency_edda_ground_time_max_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_ground_time_max_millisecond) == 2),
      "invalid size");
  uint16_t edda_transducer_latency_edda_ground_time_min_millisecond;
  static_assert(
      (sizeof(edda_transducer_latency_edda_ground_time_min_millisecond) == 2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_13;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 148;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_latency_edda_ground_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_ground_time_max_millisecond);
  }
  void set_edda_transducer_latency_edda_ground_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_ground_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_ground_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_ground_time_max_millisecond, 0, 500, &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_ground_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_ground_time_min_millisecond, 0, 500, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index,
           &edda_transducer_latency_edda_ground_time_max_millisecond,
           sizeof(edda_transducer_latency_edda_ground_time_max_millisecond));
    *index += sizeof(edda_transducer_latency_edda_ground_time_max_millisecond);
    memcpy(buf + *index,
           &edda_transducer_latency_edda_ground_time_min_millisecond,
           sizeof(edda_transducer_latency_edda_ground_time_min_millisecond));
    *index += sizeof(edda_transducer_latency_edda_ground_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_latency_edda_ground_time_max_millisecond,
           buf + index,
           sizeof(edda_transducer_latency_edda_ground_time_max_millisecond));
    index += sizeof(edda_transducer_latency_edda_ground_time_max_millisecond);
    memcpy(&edda_transducer_latency_edda_ground_time_min_millisecond,
           buf + index,
           sizeof(edda_transducer_latency_edda_ground_time_min_millisecond));
    index += sizeof(edda_transducer_latency_edda_ground_time_min_millisecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_14_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_latency_edda_temperature_1_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_transducer_latency_edda_temperature_1_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_transducer_latency_edda_temperature_1_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_transducer_latency_edda_temperature_1_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_14;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 149;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_latency_edda_temperature_1_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_temperature_1_time_max_millisecond);
  }
  void set_edda_transducer_latency_edda_temperature_1_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_temperature_1_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_temperature_1_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_temperature_1_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_temperature_1_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_temperature_1_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_transducer_latency_edda_temperature_1_time_max_millisecond,
        sizeof(
            edda_transducer_latency_edda_temperature_1_time_max_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_temperature_1_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_transducer_latency_edda_temperature_1_time_min_millisecond,
        sizeof(
            edda_transducer_latency_edda_temperature_1_time_min_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_temperature_1_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_transducer_latency_edda_temperature_1_time_max_millisecond,
        buf + index,
        sizeof(
            edda_transducer_latency_edda_temperature_1_time_max_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_temperature_1_time_max_millisecond);
    memcpy(
        &edda_transducer_latency_edda_temperature_1_time_min_millisecond,
        buf + index,
        sizeof(
            edda_transducer_latency_edda_temperature_1_time_min_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_temperature_1_time_min_millisecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_15_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_latency_edda_temperature_2_time_max_millisecond;
  static_assert(
      (sizeof(
           edda_transducer_latency_edda_temperature_2_time_max_millisecond) ==
       2),
      "invalid size");
  uint16_t edda_transducer_latency_edda_temperature_2_time_min_millisecond;
  static_assert(
      (sizeof(
           edda_transducer_latency_edda_temperature_2_time_min_millisecond) ==
       2),
      "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_15;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 150;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_latency_edda_temperature_2_time_max_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_temperature_2_time_max_millisecond);
  }
  void set_edda_transducer_latency_edda_temperature_2_time_min_millisecond(
      EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(
        value, 0, 500,
        &edda_transducer_latency_edda_temperature_2_time_min_millisecond);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_temperature_2_time_max_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_temperature_2_time_max_millisecond, 0, 500,
        &out);
    return out;
  }
  EDDA_FLOAT_DEF
  get_edda_transducer_latency_edda_temperature_2_time_min_millisecond() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(
        edda_transducer_latency_edda_temperature_2_time_min_millisecond, 0, 500,
        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(
        buf + *index,
        &edda_transducer_latency_edda_temperature_2_time_max_millisecond,
        sizeof(
            edda_transducer_latency_edda_temperature_2_time_max_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_temperature_2_time_max_millisecond);
    memcpy(
        buf + *index,
        &edda_transducer_latency_edda_temperature_2_time_min_millisecond,
        sizeof(
            edda_transducer_latency_edda_temperature_2_time_min_millisecond));
    *index +=
        sizeof(edda_transducer_latency_edda_temperature_2_time_min_millisecond);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(
        &edda_transducer_latency_edda_temperature_2_time_max_millisecond,
        buf + index,
        sizeof(
            edda_transducer_latency_edda_temperature_2_time_max_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_temperature_2_time_max_millisecond);
    memcpy(
        &edda_transducer_latency_edda_temperature_2_time_min_millisecond,
        buf + index,
        sizeof(
            edda_transducer_latency_edda_temperature_2_time_min_millisecond));
    index +=
        sizeof(edda_transducer_latency_edda_temperature_2_time_min_millisecond);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_16_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_x_acceleration_gforce;
  static_assert((sizeof(edda_transducer_x_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_transducer_x_acceleration_max_gforce;
  static_assert((sizeof(edda_transducer_x_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_16;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 151;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_x_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_transducer_x_acceleration_gforce);
  }
  void set_edda_transducer_x_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_transducer_x_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_x_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_x_acceleration_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_x_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_x_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_x_acceleration_gforce,
           sizeof(edda_transducer_x_acceleration_gforce));
    *index += sizeof(edda_transducer_x_acceleration_gforce);
    memcpy(buf + *index, &edda_transducer_x_acceleration_max_gforce,
           sizeof(edda_transducer_x_acceleration_max_gforce));
    *index += sizeof(edda_transducer_x_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_x_acceleration_gforce, buf + index,
           sizeof(edda_transducer_x_acceleration_gforce));
    index += sizeof(edda_transducer_x_acceleration_gforce);
    memcpy(&edda_transducer_x_acceleration_max_gforce, buf + index,
           sizeof(edda_transducer_x_acceleration_max_gforce));
    index += sizeof(edda_transducer_x_acceleration_max_gforce);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_17_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_x_acceleration_min_gforce;
  static_assert((sizeof(edda_transducer_x_acceleration_min_gforce) == 2),
                "invalid size");
  uint16_t edda_transducer_y_acceleration_gforce;
  static_assert((sizeof(edda_transducer_y_acceleration_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_17;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 152;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_x_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_transducer_x_acceleration_min_gforce);
  }
  void set_edda_transducer_y_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_transducer_y_acceleration_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_x_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_x_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_y_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_y_acceleration_gforce, -20, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_x_acceleration_min_gforce,
           sizeof(edda_transducer_x_acceleration_min_gforce));
    *index += sizeof(edda_transducer_x_acceleration_min_gforce);
    memcpy(buf + *index, &edda_transducer_y_acceleration_gforce,
           sizeof(edda_transducer_y_acceleration_gforce));
    *index += sizeof(edda_transducer_y_acceleration_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_x_acceleration_min_gforce, buf + index,
           sizeof(edda_transducer_x_acceleration_min_gforce));
    index += sizeof(edda_transducer_x_acceleration_min_gforce);
    memcpy(&edda_transducer_y_acceleration_gforce, buf + index,
           sizeof(edda_transducer_y_acceleration_gforce));
    index += sizeof(edda_transducer_y_acceleration_gforce);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_18_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_y_acceleration_max_gforce;
  static_assert((sizeof(edda_transducer_y_acceleration_max_gforce) == 2),
                "invalid size");
  uint16_t edda_transducer_y_acceleration_min_gforce;
  static_assert((sizeof(edda_transducer_y_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_18;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 153;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_y_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_transducer_y_acceleration_max_gforce);
  }
  void set_edda_transducer_y_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_transducer_y_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_y_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_y_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_y_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_y_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_y_acceleration_max_gforce,
           sizeof(edda_transducer_y_acceleration_max_gforce));
    *index += sizeof(edda_transducer_y_acceleration_max_gforce);
    memcpy(buf + *index, &edda_transducer_y_acceleration_min_gforce,
           sizeof(edda_transducer_y_acceleration_min_gforce));
    *index += sizeof(edda_transducer_y_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_y_acceleration_max_gforce, buf + index,
           sizeof(edda_transducer_y_acceleration_max_gforce));
    index += sizeof(edda_transducer_y_acceleration_max_gforce);
    memcpy(&edda_transducer_y_acceleration_min_gforce, buf + index,
           sizeof(edda_transducer_y_acceleration_min_gforce));
    index += sizeof(edda_transducer_y_acceleration_min_gforce);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_19_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_z_acceleration_gforce;
  static_assert((sizeof(edda_transducer_z_acceleration_gforce) == 2),
                "invalid size");
  uint16_t edda_transducer_z_acceleration_max_gforce;
  static_assert((sizeof(edda_transducer_z_acceleration_max_gforce) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_19;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 154;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_z_acceleration_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20, &edda_transducer_z_acceleration_gforce);
  }
  void set_edda_transducer_z_acceleration_max_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_transducer_z_acceleration_max_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_z_acceleration_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_z_acceleration_gforce, -20, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_edda_transducer_z_acceleration_max_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_z_acceleration_max_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_z_acceleration_gforce,
           sizeof(edda_transducer_z_acceleration_gforce));
    *index += sizeof(edda_transducer_z_acceleration_gforce);
    memcpy(buf + *index, &edda_transducer_z_acceleration_max_gforce,
           sizeof(edda_transducer_z_acceleration_max_gforce));
    *index += sizeof(edda_transducer_z_acceleration_max_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_z_acceleration_gforce, buf + index,
           sizeof(edda_transducer_z_acceleration_gforce));
    index += sizeof(edda_transducer_z_acceleration_gforce);
    memcpy(&edda_transducer_z_acceleration_max_gforce, buf + index,
           sizeof(edda_transducer_z_acceleration_max_gforce));
    index += sizeof(edda_transducer_z_acceleration_max_gforce);
  }
};

class
    Telemetry__TransducerBoard_edda_transducer_20_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t edda_transducer_z_acceleration_min_gforce;
  static_assert((sizeof(edda_transducer_z_acceleration_min_gforce) == 2),
                "invalid size");
  uint8_t size = 5;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_edda_transducer_20;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 155;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_edda_transducer_z_acceleration_min_gforce(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -20, 20,
                        &edda_transducer_z_acceleration_min_gforce);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_edda_transducer_z_acceleration_min_gforce() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(edda_transducer_z_acceleration_min_gforce, -20, 20,
                        &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &edda_transducer_z_acceleration_min_gforce,
           sizeof(edda_transducer_z_acceleration_min_gforce));
    *index += sizeof(edda_transducer_z_acceleration_min_gforce);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&edda_transducer_z_acceleration_min_gforce, buf + index,
           sizeof(edda_transducer_z_acceleration_min_gforce));
    index += sizeof(edda_transducer_z_acceleration_min_gforce);
  }
};

class
    Telemetry__TransducerBoard_sindri_00_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_01_pressure_bar;
  static_assert((sizeof(sindri_transducer_01_pressure_bar) == 2),
                "invalid size");
  uint16_t sindri_transducer_02_pressure_bar;
  static_assert((sizeof(sindri_transducer_02_pressure_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_00;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 182;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_01_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100, &sindri_transducer_01_pressure_bar);
  }
  void set_sindri_transducer_02_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100, &sindri_transducer_02_pressure_bar);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_01_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_01_pressure_bar, -10, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_02_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_02_pressure_bar, -10, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_01_pressure_bar,
           sizeof(sindri_transducer_01_pressure_bar));
    *index += sizeof(sindri_transducer_01_pressure_bar);
    memcpy(buf + *index, &sindri_transducer_02_pressure_bar,
           sizeof(sindri_transducer_02_pressure_bar));
    *index += sizeof(sindri_transducer_02_pressure_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_01_pressure_bar, buf + index,
           sizeof(sindri_transducer_01_pressure_bar));
    index += sizeof(sindri_transducer_01_pressure_bar);
    memcpy(&sindri_transducer_02_pressure_bar, buf + index,
           sizeof(sindri_transducer_02_pressure_bar));
    index += sizeof(sindri_transducer_02_pressure_bar);
  }
};

class
    Telemetry__TransducerBoard_sindri_01_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_03_pressure_bar;
  static_assert((sizeof(sindri_transducer_03_pressure_bar) == 2),
                "invalid size");
  uint16_t sindri_transducer_04_pressure_bar;
  static_assert((sizeof(sindri_transducer_04_pressure_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_01;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 183;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_03_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100, &sindri_transducer_03_pressure_bar);
  }
  void set_sindri_transducer_04_pressure_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100, &sindri_transducer_04_pressure_bar);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_03_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_03_pressure_bar, -10, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_04_pressure_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_04_pressure_bar, -10, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_03_pressure_bar,
           sizeof(sindri_transducer_03_pressure_bar));
    *index += sizeof(sindri_transducer_03_pressure_bar);
    memcpy(buf + *index, &sindri_transducer_04_pressure_bar,
           sizeof(sindri_transducer_04_pressure_bar));
    *index += sizeof(sindri_transducer_04_pressure_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_03_pressure_bar, buf + index,
           sizeof(sindri_transducer_03_pressure_bar));
    index += sizeof(sindri_transducer_03_pressure_bar);
    memcpy(&sindri_transducer_04_pressure_bar, buf + index,
           sizeof(sindri_transducer_04_pressure_bar));
    index += sizeof(sindri_transducer_04_pressure_bar);
  }
};

class
    Telemetry__TransducerBoard_sindri_02_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_01_pressure_max_bar;
  static_assert((sizeof(sindri_transducer_01_pressure_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducer_01_pressure_min_bar;
  static_assert((sizeof(sindri_transducer_01_pressure_min_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_02;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 184;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_01_pressure_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_01_pressure_max_bar);
  }
  void set_sindri_transducer_01_pressure_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_01_pressure_min_bar);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_01_pressure_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_01_pressure_max_bar, -10, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_01_pressure_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_01_pressure_min_bar, -10, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_01_pressure_max_bar,
           sizeof(sindri_transducer_01_pressure_max_bar));
    *index += sizeof(sindri_transducer_01_pressure_max_bar);
    memcpy(buf + *index, &sindri_transducer_01_pressure_min_bar,
           sizeof(sindri_transducer_01_pressure_min_bar));
    *index += sizeof(sindri_transducer_01_pressure_min_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_01_pressure_max_bar, buf + index,
           sizeof(sindri_transducer_01_pressure_max_bar));
    index += sizeof(sindri_transducer_01_pressure_max_bar);
    memcpy(&sindri_transducer_01_pressure_min_bar, buf + index,
           sizeof(sindri_transducer_01_pressure_min_bar));
    index += sizeof(sindri_transducer_01_pressure_min_bar);
  }
};

class
    Telemetry__TransducerBoard_sindri_03_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_02_pressure_max_bar;
  static_assert((sizeof(sindri_transducer_02_pressure_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducer_02_pressure_min_bar;
  static_assert((sizeof(sindri_transducer_02_pressure_min_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_03;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 185;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_02_pressure_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_02_pressure_max_bar);
  }
  void set_sindri_transducer_02_pressure_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_02_pressure_min_bar);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_02_pressure_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_02_pressure_max_bar, -10, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_02_pressure_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_02_pressure_min_bar, -10, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_02_pressure_max_bar,
           sizeof(sindri_transducer_02_pressure_max_bar));
    *index += sizeof(sindri_transducer_02_pressure_max_bar);
    memcpy(buf + *index, &sindri_transducer_02_pressure_min_bar,
           sizeof(sindri_transducer_02_pressure_min_bar));
    *index += sizeof(sindri_transducer_02_pressure_min_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_02_pressure_max_bar, buf + index,
           sizeof(sindri_transducer_02_pressure_max_bar));
    index += sizeof(sindri_transducer_02_pressure_max_bar);
    memcpy(&sindri_transducer_02_pressure_min_bar, buf + index,
           sizeof(sindri_transducer_02_pressure_min_bar));
    index += sizeof(sindri_transducer_02_pressure_min_bar);
  }
};

class
    Telemetry__TransducerBoard_sindri_04_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_03_pressure_max_bar;
  static_assert((sizeof(sindri_transducer_03_pressure_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducer_03_pressure_min_bar;
  static_assert((sizeof(sindri_transducer_03_pressure_min_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_04;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 186;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_03_pressure_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_03_pressure_max_bar);
  }
  void set_sindri_transducer_03_pressure_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_03_pressure_min_bar);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_03_pressure_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_03_pressure_max_bar, -10, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_03_pressure_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_03_pressure_min_bar, -10, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_03_pressure_max_bar,
           sizeof(sindri_transducer_03_pressure_max_bar));
    *index += sizeof(sindri_transducer_03_pressure_max_bar);
    memcpy(buf + *index, &sindri_transducer_03_pressure_min_bar,
           sizeof(sindri_transducer_03_pressure_min_bar));
    *index += sizeof(sindri_transducer_03_pressure_min_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_03_pressure_max_bar, buf + index,
           sizeof(sindri_transducer_03_pressure_max_bar));
    index += sizeof(sindri_transducer_03_pressure_max_bar);
    memcpy(&sindri_transducer_03_pressure_min_bar, buf + index,
           sizeof(sindri_transducer_03_pressure_min_bar));
    index += sizeof(sindri_transducer_03_pressure_min_bar);
  }
};

class
    Telemetry__TransducerBoard_sindri_05_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_04_pressure_max_bar;
  static_assert((sizeof(sindri_transducer_04_pressure_max_bar) == 2),
                "invalid size");
  uint16_t sindri_transducer_04_pressure_min_bar;
  static_assert((sizeof(sindri_transducer_04_pressure_min_bar) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_05;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 187;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_04_pressure_max_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_04_pressure_max_bar);
  }
  void set_sindri_transducer_04_pressure_min_bar(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, -10, 100,
                        &sindri_transducer_04_pressure_min_bar);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_04_pressure_max_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_04_pressure_max_bar, -10, 100, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_04_pressure_min_bar() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_04_pressure_min_bar, -10, 100, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_04_pressure_max_bar,
           sizeof(sindri_transducer_04_pressure_max_bar));
    *index += sizeof(sindri_transducer_04_pressure_max_bar);
    memcpy(buf + *index, &sindri_transducer_04_pressure_min_bar,
           sizeof(sindri_transducer_04_pressure_min_bar));
    *index += sizeof(sindri_transducer_04_pressure_min_bar);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_04_pressure_max_bar, buf + index,
           sizeof(sindri_transducer_04_pressure_max_bar));
    index += sizeof(sindri_transducer_04_pressure_max_bar);
    memcpy(&sindri_transducer_04_pressure_min_bar, buf + index,
           sizeof(sindri_transducer_04_pressure_min_bar));
    index += sizeof(sindri_transducer_04_pressure_min_bar);
  }
};

class
    Telemetry__TransducerBoard_sindri_06_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_01_voltage_volt;
  static_assert((sizeof(sindri_transducer_01_voltage_volt) == 2),
                "invalid size");
  uint16_t sindri_transducer_02_voltage_volt;
  static_assert((sizeof(sindri_transducer_02_voltage_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_06;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 188;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_01_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10, &sindri_transducer_01_voltage_volt);
  }
  void set_sindri_transducer_02_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10, &sindri_transducer_02_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_01_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_01_voltage_volt, 0, 10, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_02_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_02_voltage_volt, 0, 10, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_01_voltage_volt,
           sizeof(sindri_transducer_01_voltage_volt));
    *index += sizeof(sindri_transducer_01_voltage_volt);
    memcpy(buf + *index, &sindri_transducer_02_voltage_volt,
           sizeof(sindri_transducer_02_voltage_volt));
    *index += sizeof(sindri_transducer_02_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_01_voltage_volt, buf + index,
           sizeof(sindri_transducer_01_voltage_volt));
    index += sizeof(sindri_transducer_01_voltage_volt);
    memcpy(&sindri_transducer_02_voltage_volt, buf + index,
           sizeof(sindri_transducer_02_voltage_volt));
    index += sizeof(sindri_transducer_02_voltage_volt);
  }
};

class
    Telemetry__TransducerBoard_sindri_07_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_03_voltage_volt;
  static_assert((sizeof(sindri_transducer_03_voltage_volt) == 2),
                "invalid size");
  uint16_t sindri_transducer_04_voltage_volt;
  static_assert((sizeof(sindri_transducer_04_voltage_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_07;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 189;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_03_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10, &sindri_transducer_03_voltage_volt);
  }
  void set_sindri_transducer_04_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 10, &sindri_transducer_04_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_03_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_03_voltage_volt, 0, 10, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_04_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_04_voltage_volt, 0, 10, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_03_voltage_volt,
           sizeof(sindri_transducer_03_voltage_volt));
    *index += sizeof(sindri_transducer_03_voltage_volt);
    memcpy(buf + *index, &sindri_transducer_04_voltage_volt,
           sizeof(sindri_transducer_04_voltage_volt));
    *index += sizeof(sindri_transducer_04_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_03_voltage_volt, buf + index,
           sizeof(sindri_transducer_03_voltage_volt));
    index += sizeof(sindri_transducer_03_voltage_volt);
    memcpy(&sindri_transducer_04_voltage_volt, buf + index,
           sizeof(sindri_transducer_04_voltage_volt));
    index += sizeof(sindri_transducer_04_voltage_volt);
  }
};

class
    Telemetry__TransducerBoard_sindri_08_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint16_t sindri_transducer_12v_voltage_volt;
  static_assert((sizeof(sindri_transducer_12v_voltage_volt) == 2),
                "invalid size");
  uint16_t sindri_transducer_5v_voltage_volt;
  static_assert((sizeof(sindri_transducer_5v_voltage_volt) == 2),
                "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message =
      EDDA::messages::Telemetry__TransducerBoard_sindri_08;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 190;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_sindri_transducer_12v_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 20, &sindri_transducer_12v_voltage_volt);
  }
  void set_sindri_transducer_5v_voltage_volt(EDDA_FLOAT_DEF value) {
    packedFloat_to_uint(value, 0, 20, &sindri_transducer_5v_voltage_volt);
  }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  EDDA_FLOAT_DEF get_sindri_transducer_12v_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_12v_voltage_volt, 0, 20, &out);
    return out;
  }
  EDDA_FLOAT_DEF get_sindri_transducer_5v_voltage_volt() {
    EDDA_FLOAT_DEF out;
    uint_to_packedFloat(sindri_transducer_5v_voltage_volt, 0, 20, &out);
    return out;
  }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &sindri_transducer_12v_voltage_volt,
           sizeof(sindri_transducer_12v_voltage_volt));
    *index += sizeof(sindri_transducer_12v_voltage_volt);
    memcpy(buf + *index, &sindri_transducer_5v_voltage_volt,
           sizeof(sindri_transducer_5v_voltage_volt));
    *index += sizeof(sindri_transducer_5v_voltage_volt);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&sindri_transducer_12v_voltage_volt, buf + index,
           sizeof(sindri_transducer_12v_voltage_volt));
    index += sizeof(sindri_transducer_12v_voltage_volt);
    memcpy(&sindri_transducer_5v_voltage_volt, buf + index,
           sizeof(sindri_transducer_5v_voltage_volt));
    index += sizeof(sindri_transducer_5v_voltage_volt);
  }
};

class TelemetryMetaFrame_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaFrame;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 41;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMetaFrame_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaFrame;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 39;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMetaFrame_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaFrame;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 45;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMetaFrame_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaFrame;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 47;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMetaFrame_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t frame_number;
  static_assert((sizeof(frame_number) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaFrame;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 43;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_frame_number(uint32_t value) { frame_number = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_frame_number() { return frame_number; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &frame_number, sizeof(frame_number));
    *index += sizeof(frame_number);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&frame_number, buf + index, sizeof(frame_number));
    index += sizeof(frame_number);
  }
};

class TelemetryMetaTime_from_Controller_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaTime;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 42;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
  }
};

class TelemetryMetaTime_from_Ground_Controller_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaTime;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 40;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
  }
};

class TelemetryMetaTime_from_Temperature_Board_1_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaTime;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 46;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
  }
};

class TelemetryMetaTime_from_Temperature_Board_2_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaTime;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 48;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
  }
};

class TelemetryMetaTime_from_Transducer_Board_to_Ground_Controller
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  uint8_t truncated_frame_number;
  static_assert((sizeof(truncated_frame_number) == 1), "invalid size");
  uint32_t time_since_boot_ms;
  static_assert((sizeof(time_since_boot_ms) == 4), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::TelemetryMetaTime;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 44;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_truncated_frame_number(uint8_t value) {
    truncated_frame_number = value;
  }
  void set_time_since_boot_ms(uint32_t value) { time_since_boot_ms = value; }
  uint16_t get_checksum() { return checksum; }
  uint8_t get_truncated_frame_number() { return truncated_frame_number; }
  uint32_t get_time_since_boot_ms() { return time_since_boot_ms; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &truncated_frame_number,
           sizeof(truncated_frame_number));
    *index += sizeof(truncated_frame_number);
    memcpy(buf + *index, &time_since_boot_ms, sizeof(time_since_boot_ms));
    *index += sizeof(time_since_boot_ms);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&truncated_frame_number, buf + index,
           sizeof(truncated_frame_number));
    index += sizeof(truncated_frame_number);
    memcpy(&time_since_boot_ms, buf + index, sizeof(time_since_boot_ms));
    index += sizeof(time_since_boot_ms);
  }
};

class Time_from_Controller_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 28;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Controller_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 28;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Controller_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 28;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Controller_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 28;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Controller_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Controller_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 28;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Ground_Controller_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 32;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Ground_Controller_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 32;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Ground_Controller_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 32;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Ground_Controller_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 32;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Ground_Controller_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Ground_Controller;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 32;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_1_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 29;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_1_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 29;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_1_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 29;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_1_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 29;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_1_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_1;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 29;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_2_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 30;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_2_to_Temperature_Board_1
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 30;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_2_to_Temperature_Board_2
    : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 30;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_2_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 30;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Temperature_Board_2_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Temperature_Board_2;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 30;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Transducer_Board_to_Controller_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Controller_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 31;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Transducer_Board_to_Temperature_Board_1 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_1;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 31;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Transducer_Board_to_Temperature_Board_2 : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Temperature_Board_2;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 31;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Transducer_Board_to_Transducer_Board : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Transducer_Board;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 31;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

class Time_from_Transducer_Board_to_Ground_Controller : public MessageBase {
public:
  uint16_t checksum;
  static_assert((sizeof(checksum) == 2), "invalid size");
  enum TimeSource source;
  static_assert((sizeof(source) == 1), "invalid size");
  enum TimeStatus status;
  static_assert((sizeof(status) == 1), "invalid size");
  uint8_t hour;
  static_assert((sizeof(hour) == 1), "invalid size");
  uint8_t minute;
  static_assert((sizeof(minute) == 1), "invalid size");
  uint8_t second;
  static_assert((sizeof(second) == 1), "invalid size");
  uint8_t size = 7;
  enum EDDA::messages message = EDDA::messages::Time;
  enum EDDA::nodes sender = EDDA::nodes::Transducer_Board;
  enum EDDA::nodes receiver = EDDA::nodes::Ground_Controller;
  enum EDDA::categories category = EDDA::categories::none;
  uint8_t id = 31;
  enum categories get_category() override { return category; }
  uint8_t get_size() override { return size; }
  enum nodes get_sender() override { return sender; }
  enum nodes get_receiver() override { return receiver; }
  uint8_t get_id() override { return id; }
  void set_checksum(uint16_t value) { checksum = value; }
  void set_source(enum TimeSource value) { source = value; }
  void set_status(enum TimeStatus value) { status = value; }
  void set_hour(uint8_t value) { hour = value; }
  void set_minute(uint8_t value) { minute = value; }
  void set_second(uint8_t value) { second = value; }
  uint16_t get_checksum() { return checksum; }
  enum TimeSource get_source() { return source; }
  enum TimeStatus get_status() { return status; }
  uint8_t get_hour() { return hour; }
  uint8_t get_minute() { return minute; }
  uint8_t get_second() { return second; }
  void build_buf(uint8_t *buf, uint8_t *index) override {
    memcpy(buf + *index, &checksum, sizeof(checksum));
    *index += sizeof(checksum);
    memcpy(buf + *index, &source, sizeof(source));
    *index += sizeof(source);
    memcpy(buf + *index, &status, sizeof(status));
    *index += sizeof(status);
    memcpy(buf + *index, &hour, sizeof(hour));
    *index += sizeof(hour);
    memcpy(buf + *index, &minute, sizeof(minute));
    *index += sizeof(minute);
    memcpy(buf + *index, &second, sizeof(second));
    *index += sizeof(second);
  }
  void parse_buf(uint8_t *buf) override {
    uint8_t index = 0;
    memcpy(&checksum, buf + index, sizeof(checksum));
    index += sizeof(checksum);
    memcpy(&source, buf + index, sizeof(source));
    index += sizeof(source);
    memcpy(&status, buf + index, sizeof(status));
    index += sizeof(status);
    memcpy(&hour, buf + index, sizeof(hour));
    index += sizeof(hour);
    memcpy(&minute, buf + index, sizeof(minute));
    index += sizeof(minute);
    memcpy(&second, buf + index, sizeof(second));
    index += sizeof(second);
  }
};

void rx(ChannelState_from_Controller_Board_to_Ground_Controller msg);
void rx(ChannelState_from_Controller_Board_to_Ground_Controller msg,
        void *misc);
void rx(
    ChannelTransitionRequest_from_Ground_Controller_to_Controller_Board msg);
void rx(ChannelTransitionRequest_from_Ground_Controller_to_Controller_Board msg,
        void *misc);
void rx(
    ChannelTransitionResponse_from_Controller_Board_to_Ground_Controller msg);
void rx(
    ChannelTransitionResponse_from_Controller_Board_to_Ground_Controller msg,
    void *misc);
void rx(Date_from_Controller_Board_to_Controller_Board msg);
void rx(Date_from_Controller_Board_to_Controller_Board msg, void *misc);
void rx(Date_from_Ground_Controller_to_Controller_Board msg);
void rx(Date_from_Ground_Controller_to_Controller_Board msg, void *misc);
void rx(Date_from_Temperature_Board_1_to_Controller_Board msg);
void rx(Date_from_Temperature_Board_1_to_Controller_Board msg, void *misc);
void rx(Date_from_Temperature_Board_2_to_Controller_Board msg);
void rx(Date_from_Temperature_Board_2_to_Controller_Board msg, void *misc);
void rx(Date_from_Transducer_Board_to_Controller_Board msg);
void rx(Date_from_Transducer_Board_to_Controller_Board msg, void *misc);
void rx(EngineActionRequest_from_Ground_Controller_to_Controller_Board msg);
void rx(EngineActionRequest_from_Ground_Controller_to_Controller_Board msg,
        void *misc);
void rx(EngineActionResponse_from_Controller_Board_to_Ground_Controller msg);
void rx(EngineActionResponse_from_Controller_Board_to_Ground_Controller msg,
        void *misc);
void rx(EngineState_from_Controller_Board_to_Ground_Controller msg);
void rx(EngineState_from_Controller_Board_to_Ground_Controller msg, void *misc);
void rx(Heartbeat_from_Controller_Board_to_Ground_Controller msg);
void rx(Heartbeat_from_Controller_Board_to_Ground_Controller msg, void *misc);
void rx(Heartbeat_from_Ground_Controller_to_Ground_Controller msg);
void rx(Heartbeat_from_Ground_Controller_to_Ground_Controller msg, void *misc);
void rx(Heartbeat_from_Power_Channel_1_to_Ground_Controller msg);
void rx(Heartbeat_from_Power_Channel_1_to_Ground_Controller msg, void *misc);
void rx(Heartbeat_from_Power_Channel_2_to_Ground_Controller msg);
void rx(Heartbeat_from_Power_Channel_2_to_Ground_Controller msg, void *misc);
void rx(Heartbeat_from_Power_Channel_3_to_Ground_Controller msg);
void rx(Heartbeat_from_Power_Channel_3_to_Ground_Controller msg, void *misc);
void rx(Heartbeat_from_Temperature_Board_1_to_Ground_Controller msg);
void rx(Heartbeat_from_Temperature_Board_1_to_Ground_Controller msg,
        void *misc);
void rx(Heartbeat_from_Temperature_Board_2_to_Ground_Controller msg);
void rx(Heartbeat_from_Temperature_Board_2_to_Ground_Controller msg,
        void *misc);
void rx(Heartbeat_from_Transducer_Board_to_Ground_Controller msg);
void rx(Heartbeat_from_Transducer_Board_to_Ground_Controller msg, void *misc);
void rx(Latency_from_Controller_Board_to_Ground_Controller msg);
void rx(Latency_from_Controller_Board_to_Ground_Controller msg, void *misc);
void rx(Latency_from_Ground_Controller_to_Ground_Controller msg);
void rx(Latency_from_Ground_Controller_to_Ground_Controller msg, void *misc);
void rx(Latency_from_Temperature_Board_1_to_Ground_Controller msg);
void rx(Latency_from_Temperature_Board_1_to_Ground_Controller msg, void *misc);
void rx(Latency_from_Temperature_Board_2_to_Ground_Controller msg);
void rx(Latency_from_Temperature_Board_2_to_Ground_Controller msg, void *misc);
void rx(Latency_from_Transducer_Board_to_Ground_Controller msg);
void rx(Latency_from_Transducer_Board_to_Ground_Controller msg, void *misc);
void rx(Ping_from_Controller_Board_to_Controller_Board msg);
void rx(Ping_from_Controller_Board_to_Controller_Board msg, void *misc);
void rx(Ping_from_Ground_Controller_to_Controller_Board msg);
void rx(Ping_from_Ground_Controller_to_Controller_Board msg, void *misc);
void rx(Ping_from_Temperature_Board_1_to_Controller_Board msg);
void rx(Ping_from_Temperature_Board_1_to_Controller_Board msg, void *misc);
void rx(Ping_from_Temperature_Board_2_to_Controller_Board msg);
void rx(Ping_from_Temperature_Board_2_to_Controller_Board msg, void *misc);
void rx(Ping_from_Transducer_Board_to_Controller_Board msg);
void rx(Ping_from_Transducer_Board_to_Controller_Board msg, void *misc);
void rx(Pong_from_Controller_Board_to_Controller_Board msg);
void rx(Pong_from_Controller_Board_to_Controller_Board msg, void *misc);
void rx(Pong_from_Ground_Controller_to_Controller_Board msg);
void rx(Pong_from_Ground_Controller_to_Controller_Board msg, void *misc);
void rx(Pong_from_Temperature_Board_1_to_Controller_Board msg);
void rx(Pong_from_Temperature_Board_1_to_Controller_Board msg, void *misc);
void rx(Pong_from_Temperature_Board_2_to_Controller_Board msg);
void rx(Pong_from_Temperature_Board_2_to_Controller_Board msg, void *misc);
void rx(Pong_from_Transducer_Board_to_Controller_Board msg);
void rx(Pong_from_Transducer_Board_to_Controller_Board msg, void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_00_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_00_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_01_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_01_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_02_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_02_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_03_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_03_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_04_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_04_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_05_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_05_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_06_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_06_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_07_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_07_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_08_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_08_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_09_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_09_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_10_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_10_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_11_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_11_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_12_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_12_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_13_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_13_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_14_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_14_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_15_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_15_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_16_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_16_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_17_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_17_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_18_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_18_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_19_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_19_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_edda_controller_20_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_edda_controller_20_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_00_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_00_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_01_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_01_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_02_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_02_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_03_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_03_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_04_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_04_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_05_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_05_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_06_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_06_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_07_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_07_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_08_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_08_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_09_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_09_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__ControllerBoard_sindri_10_from_Controller_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__ControllerBoard_sindri_10_from_Controller_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_00_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_00_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_01_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_01_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_02_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_02_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_03_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_03_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_04_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_04_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_05_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_05_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_06_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_06_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_07_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_07_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_08_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_08_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_09_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_09_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_10_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_10_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_11_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_11_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_12_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_12_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_13_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_13_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_14_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_14_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_15_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_15_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_16_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_16_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_17_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_17_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_18_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_18_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_19_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_19_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_20_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_20_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_21_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_21_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__GroundController_edda_ground_22_from_Ground_Controller_to_Ground_Controller
        msg);
void rx(
    Telemetry__GroundController_edda_ground_22_from_Ground_Controller_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_00_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_00_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_01_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_01_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_02_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_02_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_03_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_03_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_04_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_04_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_05_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_05_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_06_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_06_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_07_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_07_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_08_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_08_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_09_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_09_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_10_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_10_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_11_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_11_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_12_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_12_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_13_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_13_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_14_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_14_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_15_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_15_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_16_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_16_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_17_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_17_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_18_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_18_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_19_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_19_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_20_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_edda_temperature_1_20_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_00_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_00_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_01_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_01_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_02_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_02_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_03_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_03_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_04_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_04_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_05_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_05_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard1_sindri_06_from_Temperature_Board_1_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard1_sindri_06_from_Temperature_Board_1_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_00_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_00_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_01_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_01_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_02_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_02_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_03_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_03_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_04_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_04_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_05_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_05_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_06_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_06_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_07_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_07_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_08_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_08_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_09_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_09_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_10_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_10_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_11_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_11_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_12_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_12_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_13_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_13_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_14_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_14_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_15_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_15_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_16_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_16_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_17_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_17_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_18_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_18_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_19_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_19_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_20_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_edda_temperature_2_20_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_00_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_00_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_01_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_01_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_02_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_02_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_03_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_03_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_04_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_04_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_05_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_05_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_06_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_06_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TemperatureBoard2_sindri_07_from_Temperature_Board_2_to_Ground_Controller
        msg);
void rx(
    Telemetry__TemperatureBoard2_sindri_07_from_Temperature_Board_2_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_00_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_00_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_01_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_01_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_02_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_02_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_03_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_03_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_04_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_04_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_05_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_05_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_06_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_06_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_07_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_07_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_08_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_08_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_09_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_09_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_10_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_10_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_11_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_11_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_12_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_12_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_13_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_13_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_14_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_14_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_15_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_15_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_16_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_16_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_17_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_17_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_18_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_18_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_19_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_19_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_edda_transducer_20_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_edda_transducer_20_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_00_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_00_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_01_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_01_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_02_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_02_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_03_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_03_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_04_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_04_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_05_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_05_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_06_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_06_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_07_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_07_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(
    Telemetry__TransducerBoard_sindri_08_from_Transducer_Board_to_Ground_Controller
        msg);
void rx(
    Telemetry__TransducerBoard_sindri_08_from_Transducer_Board_to_Ground_Controller
        msg,
    void *misc);
void rx(TelemetryMetaFrame_from_Controller_Board_to_Ground_Controller msg);
void rx(TelemetryMetaFrame_from_Controller_Board_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaFrame_from_Ground_Controller_to_Ground_Controller msg);
void rx(TelemetryMetaFrame_from_Ground_Controller_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaFrame_from_Temperature_Board_1_to_Ground_Controller msg);
void rx(TelemetryMetaFrame_from_Temperature_Board_1_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaFrame_from_Temperature_Board_2_to_Ground_Controller msg);
void rx(TelemetryMetaFrame_from_Temperature_Board_2_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaFrame_from_Transducer_Board_to_Ground_Controller msg);
void rx(TelemetryMetaFrame_from_Transducer_Board_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaTime_from_Controller_Board_to_Ground_Controller msg);
void rx(TelemetryMetaTime_from_Controller_Board_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaTime_from_Ground_Controller_to_Ground_Controller msg);
void rx(TelemetryMetaTime_from_Ground_Controller_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaTime_from_Temperature_Board_1_to_Ground_Controller msg);
void rx(TelemetryMetaTime_from_Temperature_Board_1_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaTime_from_Temperature_Board_2_to_Ground_Controller msg);
void rx(TelemetryMetaTime_from_Temperature_Board_2_to_Ground_Controller msg,
        void *misc);
void rx(TelemetryMetaTime_from_Transducer_Board_to_Ground_Controller msg);
void rx(TelemetryMetaTime_from_Transducer_Board_to_Ground_Controller msg,
        void *misc);
void rx(Time_from_Controller_Board_to_Controller_Board msg);
void rx(Time_from_Controller_Board_to_Controller_Board msg, void *misc);
void rx(Time_from_Ground_Controller_to_Controller_Board msg);
void rx(Time_from_Ground_Controller_to_Controller_Board msg, void *misc);
void rx(Time_from_Temperature_Board_1_to_Controller_Board msg);
void rx(Time_from_Temperature_Board_1_to_Controller_Board msg, void *misc);
void rx(Time_from_Temperature_Board_2_to_Controller_Board msg);
void rx(Time_from_Temperature_Board_2_to_Controller_Board msg, void *misc);
void rx(Time_from_Transducer_Board_to_Controller_Board msg);
void rx(Time_from_Transducer_Board_to_Controller_Board msg, void *misc);
void parse_message(uint8_t id, uint8_t *buf);
void parse_message(uint8_t id, uint8_t *buf, void *misc);
bool is_valid_id(uint8_t id);
uint8_t id_to_len(uint8_t id);
enum nodes id_to_sender(uint8_t id);
enum nodes id_to_receiver(uint8_t id);
enum categories id_to_category(uint8_t id);
} // namespace EDDA
#endif
