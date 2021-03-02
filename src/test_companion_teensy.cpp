/* test_companion_teensy.cpp

Author: Erwan Caffier

Version:

Description:
  Helper code to test the Flight Controller. Must be uploaded on a secondary
  Flight Controller while testing another Flight Controller board. See
  hardware_test_teensy.cpp for instructions

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

#include <FlexCAN.h>  // https://github.com/pawelsky/FlexCAN_Library
#include <SPI.h>

#include "hardware_definition_teensy.h"
#include "Gps.h"

#define GPS_MAX_LEN 100
#define GPS_BAUD 38400

static CAN_message_t msg;

FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX


GPS gps1;
GPS gps2;

uint8_t led_state = 0;

void init_gps() {
  //GPS 1
  Serial1.setRX(PIN_RX1);
  Serial1.setTX(PIN_TX1);
  Serial1.begin(GPS_BAUD);

  //GPS 2
  Serial3.setRX(PIN_RX3);
  Serial3.setTX(PIN_TX3);
  Serial3.begin(GPS_BAUD);
}


void update_gps() {
  //gps 1
  if (Serial1.available() > 0) {
    char buf[GPS_MAX_LEN];
    uint8_t len = Serial1.readBytesUntil('\n', buf, GPS_MAX_LEN);
    gps1.parse_message((uint8_t*) buf, len);
  }

  //gps 2
  if (Serial3.available() > 0) {
    char buf[GPS_MAX_LEN];
    uint8_t len = Serial3.readBytesUntil('\n', buf, GPS_MAX_LEN);
    gps2.parse_message((uint8_t*) buf, len);
  }
}

void setup() {
  CANbus.begin();

  Serial.begin(115200);
  while (!Serial){}

  init_gps();

  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);
  Serial2.begin(SERIAL2_BAUD);


  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (CANbus.available()) {
    CANbus.read(msg);
    msg.buf[0]++;
    CANbus.write(msg);
  }

  if (Serial2.available()) {
    Serial2.write(Serial2.read() + 1);
    led_state = !led_state;
    digitalWrite(LED_BUILTIN, led_state);
  }

  update_gps();
  if (gps1.is_set(FLAG_N_SATELLITES)) {
    Serial.print("gps1 satellites: ");
    Serial.println(gps1.n_satellites);
    gps1.clear_flags();
  }

  if (gps2.is_set(FLAG_N_SATELLITES)) {
    Serial.print("gps2 satellites: ");
    Serial.println(gps2.n_satellites);
    gps2.clear_flags();
  }
}