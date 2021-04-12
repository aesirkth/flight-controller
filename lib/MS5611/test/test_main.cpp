#include <Arduino.h>
#include <unity.h>

#define UNIT_TESTING
#include "MS5611.h"

#define PRESSURE_ERROR_MAX 2.0     // 0.02 mbar
#define TEMPERATURE_ERROR_MAX 2.0  // 0.02°C

MS5611 my_sensor(17, SPI, 10000000);

void overrideCalibration() {
  // Calibration values examples from the datasheet
  my_sensor._c[1] = 40127;
  my_sensor._c[2] = 36924;
  my_sensor._c[3] = 23317;
  my_sensor._c[4] = 23282;
  my_sensor._c[5] = 33464;
  my_sensor._c[6] = 28312;
}

void test_pressure____1000mbar__20C() {
  my_sensor.convertMeasurement(9085466, 8569150);
  TEST_ASSERT_FLOAT_WITHIN(PRESSURE_ERROR_MAX, 100009.07, my_sensor.pressure);
}

void test_temperature_1000mbar__20C() {
  my_sensor.convertMeasurement(9085466, 8569150);
  TEST_ASSERT_FLOAT_WITHIN(TEMPERATURE_ERROR_MAX, 2007.99, my_sensor.temperature);
}

void test_pressure_____800mbar_m50C() {
  my_sensor.convertMeasurement(8734466, 6869150);
  TEST_ASSERT_FLOAT_WITHIN(PRESSURE_ERROR_MAX, 77923.45, my_sensor.pressure);
}

void test_temperature__800mbar_m50C() {
  my_sensor.convertMeasurement(8734466, 6869150);
  TEST_ASSERT_FLOAT_WITHIN(TEMPERATURE_ERROR_MAX, -5071.62, my_sensor.temperature);
}

void test_pressure______20mbar__35C() {
  my_sensor.convertMeasurement(3971650, 8995673);
  TEST_ASSERT_FLOAT_WITHIN(PRESSURE_ERROR_MAX, 2022.74, my_sensor.pressure);
}

void test_temperature___20mbar__35C() {
  my_sensor.convertMeasurement(3971650, 8995673);
  TEST_ASSERT_FLOAT_WITHIN(TEMPERATURE_ERROR_MAX, 3447.52, my_sensor.temperature);
}

void test_pressure_____150mbar_m20C() {
  my_sensor.convertMeasurement(4675350, 7518340);
  TEST_ASSERT_FLOAT_WITHIN(PRESSURE_ERROR_MAX, 14823.33, my_sensor.pressure);
}

void test_temperature__150mbar_m20C() {
  my_sensor.convertMeasurement(4675350, 7518340);
  TEST_ASSERT_FLOAT_WITHIN(TEMPERATURE_ERROR_MAX, -2050.43, my_sensor.temperature);
}

void test_pressure_____400mbar___6C() {
  my_sensor.convertMeasurement(6027840, 8190420);
  TEST_ASSERT_FLOAT_WITHIN(PRESSURE_ERROR_MAX, 40517.36, my_sensor.pressure);
}

void test_temperature__400mbar___6C() {
  my_sensor.convertMeasurement(6027840, 8190420);
  TEST_ASSERT_FLOAT_WITHIN(TEMPERATURE_ERROR_MAX, 663.79, my_sensor.temperature);
}

void test_pressure____1200mbar__50C() {
  my_sensor.convertMeasurement(9764720, 9390420);
  TEST_ASSERT_FLOAT_WITHIN(PRESSURE_ERROR_MAX, 119078.47, my_sensor.pressure);
}

void test_temperature_1200mbar__50C() {
  my_sensor.convertMeasurement(9764720, 9390420);
  TEST_ASSERT_FLOAT_WITHIN(TEMPERATURE_ERROR_MAX, 4779.82, my_sensor.temperature);
}

void test_default_oversampling() {
  TEST_ASSERT_EQUAL(MS5611_OSR_256, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(0.6, my_sensor._del);
}

void test_oversampling_settings() {
  my_sensor.setOSR(MS5611_OSR_256);
  TEST_ASSERT_EQUAL(MS5611_OSR_256, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(0.6, my_sensor._del);
  my_sensor.setOSR(MS5611_OSR_512);
  TEST_ASSERT_EQUAL(MS5611_OSR_512, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(1.17, my_sensor._del);
  my_sensor.setOSR(MS5611_OSR_1024);
  TEST_ASSERT_EQUAL(MS5611_OSR_1024, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(2.28, my_sensor._del);
  my_sensor.setOSR(MS5611_OSR_2048);
  TEST_ASSERT_EQUAL(MS5611_OSR_2048, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(4.54, my_sensor._del);
  my_sensor.setOSR(MS5611_OSR_4096);
  TEST_ASSERT_EQUAL(MS5611_OSR_4096, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(9.04, my_sensor._del);
  my_sensor.setOSR(1);  // Forbidden value
  TEST_ASSERT_EQUAL(MS5611_OSR_256, my_sensor._osr);
  TEST_ASSERT_GREATER_OR_EQUAL(0.6, my_sensor._del);
}

void setup() {
  delay(2000);

  my_sensor.begin();

  overrideCalibration();

  UNITY_BEGIN();
  RUN_TEST(test_default_oversampling);
  RUN_TEST(test_oversampling_settings);
  RUN_TEST(test_pressure____1000mbar__20C);
  RUN_TEST(test_temperature_1000mbar__20C);
  RUN_TEST(test_pressure_____800mbar_m50C);
  RUN_TEST(test_temperature__800mbar_m50C);
  RUN_TEST(test_pressure______20mbar__35C);
  RUN_TEST(test_temperature___20mbar__35C);
  RUN_TEST(test_pressure_____150mbar_m20C);
  RUN_TEST(test_temperature__150mbar_m20C);
  RUN_TEST(test_pressure_____400mbar___6C);
  RUN_TEST(test_temperature__400mbar___6C);
  RUN_TEST(test_pressure____1200mbar__50C);
  RUN_TEST(test_temperature_1200mbar__50C);

  UNITY_END();
}

void loop() {
}