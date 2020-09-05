#include <FlexCAN.h>
#include <RHHardwareSPI1.h>  // From Paul's version of RadioHead
#include <RH_RF95.h>         // From RadioHead
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
}