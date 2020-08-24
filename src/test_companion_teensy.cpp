#include <FlexCAN.h>
#include <RHHardwareSPI1.h>  // From Paul's version of RadioHead
#include <RH_RF95.h>         // From RadioHead
#include <SPI.h>

static CAN_message_t msg;

FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX

void setup() {
  CANbus.begin();
}

void loop() {
  if (CANbus.available()) {
    CANbus.read(msg);
    msg.buf[0]++;
    CANbus.write(msg);
  }
}