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