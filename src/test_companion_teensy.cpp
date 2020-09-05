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

static CAN_message_t msg;

FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX

uint8_t led_state = 0;

void setup() {
  CANbus.begin();

  Serial1.setRX(PIN_RX1);
  Serial1.setTX(PIN_TX1);
  Serial1.begin(SERIAL1_BAUD);

  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);
  Serial2.begin(SERIAL2_BAUD);

  Serial3.setRX(PIN_RX3);
  Serial3.setTX(PIN_TX3);
  Serial3.begin(SERIAL3_BAUD);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (CANbus.available()) {
    CANbus.read(msg);
    msg.buf[0]++;
    CANbus.write(msg);
  }

  if (Serial1.available()) {
    Serial1.write(Serial1.read() + 1);
    led_state = !led_state;
    digitalWrite(LED_BUILTIN, led_state);
  }

  if (Serial2.available()) {
    Serial2.write(Serial2.read() + 1);
    led_state = !led_state;
    digitalWrite(LED_BUILTIN, led_state);
  }

  if (Serial3.available()) {
    Serial3.write(Serial3.read() + 1);
    led_state = !led_state;
    digitalWrite(LED_BUILTIN, led_state);
  }
}