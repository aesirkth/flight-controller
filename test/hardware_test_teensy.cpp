/* hardware_test_teensy.cpp

Author: Erwan Caffier

Version:

Description:
  Unit tests to check the Flight Controller board. Works with the Flight Controller
  v1.0. The tests require a fully assembled board with both batteries connected.
  ALWAYS connect the antenna for the LoRa chip before powering the board.

  A secondary board is required to test the communication buses. Connect a second
  Flight Controller with test_companion_teensy.cpp loaded on it through J6 to test 
  the CAN Bus. Power for the secondary board is provided through J6. Connect a 
  second Flight Controller with test_companion_teensy.cpp loaded on it through J1, 
  J2, or J3 to test the Serial buses. The RX and TX wires must be inverted. Power 
  for the secondary board is provided through J1, J2, or J3.

License:
  MIT License
  Copyright (c) 2020 Association of Engineering Students in Rocketry
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include "hardware_test_teensy.h"

// If using https://github.com/wanysteus/MS5611
// define this to get access to the private objects of MS5611
#define UNIT_TESTING

#include <Adafruit_NeoPixel.h>  // https://github.com/adafruit/Adafruit_NeoPixel
#include <Arduino.h>
#include <FlexCAN.h>         // https://github.com/pawelsky/FlexCAN_Library
#include <MS5611.h>          // https://github.com/wanysteus/MS5611
#include <RHHardwareSPI1.h>  // From Paul's version of RadioHead https://github.com/PaulStoffregen/RadioHead
#include <RH_RF95.h>         // From Paul's version of RadioHead https://github.com/PaulStoffregen/RadioHead
#include <SPI.h>
#include <unity.h>

#include "hardware_definition_teensy.h"

#define RFM_SPI hardware_spi1

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(RGB_LEDS_NUM, RGB_LEDS_PIN, NEO_GRB + NEO_KHZ800); // Seems not to work at 800 kHz
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);

MS5611 ms1(PIN_CS_MS1, PORT_MS1, MS5611_MAX_SPI_FREQ);
MS5611 ms2(PIN_CS_MS2, PORT_MS2, MS5611_MAX_SPI_FREQ);

FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX
static CAN_message_t msg;

RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), RFM_SPI);

void setup() {
  delay(2000);  // Required to make the unit tests work

  // Set custom pins for the buses
  Serial1.setRX(PIN_RX1);
  Serial1.setTX(PIN_TX1);

  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);

  Serial3.setRX(PIN_RX3);
  Serial3.setTX(PIN_TX3);

  SPI.setMOSI(PIN_MOSI0);
  SPI.setMISO(PIN_MISO0);
  SPI.setSCK(PIN_SCK0);

  SPI1.setMOSI(PIN_MOSI1);
  SPI1.setMISO(PIN_MISO1);
  SPI1.setSCK(PIN_SCK1);

  // Set I/O
  pinMode(PIN_PARA1, OUTPUT);
  pinMode(PIN_PARA2, OUTPUT);
  digitalWrite(PIN_PARA1, LOW);  // LOW means inactive parachute
  digitalWrite(PIN_PARA2, LOW);  // LOW means inactive parachute

  pinMode(PIN_RFD_EN, OUTPUT);
  pinMode(PIN_FPV_EN, OUTPUT);
  digitalWrite(PIN_RFD_EN, LOW);  // LOW means active Telemetry output
  digitalWrite(PIN_FPV_EN, LOW);

  UNITY_BEGIN();

  // Automatic tests
  RUN_TEST(test_ms1);
  RUN_TEST(test_ms2);

  RUN_TEST(test_RFM);

  RUN_TEST(test_serial1);
  RUN_TEST(test_serial2);
  RUN_TEST(test_serial3);

  RUN_TEST(test_CAN_bus);

  // Manual tests, check the tests description below
  RUN_TEST(test_buzzer);

  RUN_TEST(test_rgb);

  RUN_TEST(test_parachutes);

  RUN_TEST(test_J2_output);
  RUN_TEST(test_J4_output);

  UNITY_END();
}

void loop() {
}

/* Automatic tests */

/*
  Test the MS5611 pressure sensors on IC1

  Try to read the PROM. 0x0000 or 0xFFFF indicate
  a failure to read. Not bullet proof, should check 
  CRC4 instead in the future
*/
void test_ms1() {
  ms1.begin();
  uint16_t C1 = ms1._c[1];
  TEST_ASSERT_NOT_EQUAL(0x0000, C1);
  TEST_ASSERT_NOT_EQUAL(0xffff, C1);
}

/*
  Test the MS5611 pressure sensors on IC2

  Try to read the PROM. 0x0000 or 0xFFFF indicate
  a failure to read. Not bullet proof, should check 
  CRC4 instead in the future
*/
void test_ms2() {
  ms2.begin();
  uint16_t C1 = ms2._c[1];
  TEST_ASSERT_NOT_EQUAL(0x0000, C1);
  TEST_ASSERT_NOT_EQUAL(0xffff, C1);
}

/*
  Test the RFM96W LoRa chip

  Try to initialize the chip
*/
void test_RFM() {
  // Hard-reset the chip
  pinMode(PIN_RFM_RST, OUTPUT);
  digitalWrite(PIN_RFM_RST, HIGH);
  delay(100);
  digitalWrite(PIN_RFM_RST, LOW);
  delay(10);
  digitalWrite(PIN_RFM_RST, HIGH);
  delay(100);

  TEST_ASSERT_TRUE(rfm.init());
}

/*
  Test the CAN Bus (CAN0)

  Send one byte
  Expect a message with the same ID but with byte+1
  as a payload
*/
void test_CAN_bus() {
  CANbus.begin();

  msg.len = 8;
  msg.id = 0x222;
  msg.buf[0] = 0x42;
  CANbus.write(msg);
  delay(10);
  CANbus.read(msg);
  TEST_ASSERT_EQUAL(0x43, msg.buf[0]);
}

/*
  Test the Serial1 bus on J1

  Send one byte on TX pin
  Expect the same byte + 1 on RX pin
*/
void test_serial1() {
  Serial1.begin(SERIAL1_BAUD);

  Serial1.write(0x42);
  delay(10);
  TEST_ASSERT_EQUAL(0x43, Serial1.read());
}

/*
  Test the Serial2 bus on J2

  Send one byte on TX pin
  Expect the same byte + 1 on RX pin
*/
void test_serial2() {
  Serial2.begin(SERIAL2_BAUD);

  Serial2.write(0x42);
  delay(10);
  TEST_ASSERT_EQUAL(0x43, Serial2.read());
}

/*
  Test the Serial3 bus on J3

  Send one byte on TX pin
  Expect the same byte + 1 on RX pin
*/
void test_serial3() {
  Serial3.begin(SERIAL3_BAUD);

  Serial3.write(0x42);
  delay(10);
  TEST_ASSERT_EQUAL(0x43, Serial3.read());
}

/* Manual tests */

/*
  Test the buzzer (LS1)

  Play short sounds
  The user must pay attention to the test outputs in 
  the serial console and confirm the sounds
*/
void test_buzzer() {
#ifdef SILENT_MODE
  TEST_IGNORE_MESSAGE("Silent mode: skipping buzzer test");
#else
  buzzerShortSound();
  TEST_MESSAGE("Testing the buzzer");
  TEST_MESSAGE("Do you hear it ?");
  delay(1000);
  for (uint8_t i = 0; i < 5; i++) {
    tone(PIN_BUZZER, BUZZER_FREQ, 100);
    delay(200);
  }
  TEST_PASS_MESSAGE("Test passed if you heard it");
#endif
}

/*
  Test the RGB leds

  Display various colors
  The user must pay attention to the test outputs in 
  the serial console and confirm correct led output
*/
void test_rgb() {
  initRGB();
  delay(1000);
  buzzerShortSound();
  TEST_MESSAGE("Testing the RGB leds");
  TEST_MESSAGE("Do you see them flashing ?");
  delay(1000);
  uint32_t color[6] = {
      0xff0000,
      0x00ff00,
      0x0000ff,
      0xcc00ff,
      0xcc9900,
      0x66ccff,
  };

  for (uint8_t i = 0; i < 6; i++) {
    for (uint8_t j = 0; j < NUM_RGB_LEDS; j++) {
      strip.setPixelColor(j, color[i]);
    }
    strip.show();
    delay(500);
  }

  strip.clear();
  strip.show();
  TEST_PASS_MESSAGE("Test passed if saw it");
}

/*
  Test the parachute outputs

  /!\ DO NOT CONNECT EEDs for this test /!\

  Activate each parachute for 1 second
  The user must pay attention to the test outputs in 
  the serial console and confirm correct parachute 
  outputs
*/
void test_parachutes() {
  delay(1000);
  buzzerShortSound();
  TEST_MESSAGE("Testing the parachute outputs");
  TEST_MESSAGE("Do you see them activate/deactivate ?");
  delay(1000);

  digitalWrite(PIN_PARA1, HIGH);
  delay(1000);
  digitalWrite(PIN_PARA2, HIGH);
  delay(1000);
  digitalWrite(PIN_PARA1, LOW);
  delay(1000);
  digitalWrite(PIN_PARA2, LOW);

  TEST_PASS_MESSAGE("Test passed if saw it");
}

/*
  Test the power output to J2

  Cut power to J2 for 1 second
  The user must pay attention to the test outputs in 
  the serial console and confirm voltage at J2
*/
void test_J2_output() {
  delay(1000);
  buzzerShortSound();
  TEST_MESSAGE("Testing J2 output");
  TEST_MESSAGE("It should turn off for 1s, do you see it ?");
  TEST_MESSAGE("(Measure the voltage on the test pad, 5V expected)");
  delay(1000);
  digitalWrite(PIN_RFD_EN, HIGH);
  delay(1000);
  digitalWrite(PIN_RFD_EN, LOW);

  TEST_PASS_MESSAGE("Test passed if saw it");
}

/*
  Test the power output to J4

  Cut power to J4 for 1 second
  The user must pay attention to the test outputs in 
  the serial console and confirm voltage at J4
*/
void test_J4_output() {
  delay(1000);
  buzzerShortSound();
  TEST_MESSAGE("Testing J4 output");
  TEST_MESSAGE("It should turn off for 1s, do you see it ?");
  TEST_MESSAGE("(Measure the voltage on the test pad, 12V expected)");
  delay(1000);
  digitalWrite(PIN_FPV_EN, HIGH);
  delay(1000);
  digitalWrite(PIN_FPV_EN, LOW);

  TEST_PASS_MESSAGE("Test passed if saw it");
}

/* Utils */

void buzzerShortSound() {
#ifndef SILENT_MODE
  tone(PIN_BUZZER, BUZZER_FREQ, 100);
#endif
}

void initRGB() {
  strip.begin();
  delay(10);
  strip.clear();
  strip.setBrightness(20);
  delay(10);
  strip.show();
}