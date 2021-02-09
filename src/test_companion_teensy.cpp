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
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <RHHardwareSPI1.h>
#include <RH_RF95.h>  // RadioHead library  to control the LoRa transceiver

#include "hardware_definition_teensy.h"
#include "utils.h"
#include "test_companion_teensy.h"

#define RFM_SPI hardware_spi1
#define RFM_FREQ 433.0f
#define RFM_TX_POWER 5
#define STARTUP_COLOR 0xFFFFFFFF

static CAN_message_t msg;

FlexCAN CANbus(1000000, 0, 1, 1);  // 1Mbs, CAN0, pins 29&30 for TX&RX

uint8_t led_state = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);

// For LoRa Communication
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), RFM_SPI);

#define SPI_FREQ 1000000  // 1MHz

SPISettings spi_settings(SPI_FREQ, MSBFIRST, SPI_MODE0);

char data[CMD_DATA_LEN];
bool rfm_init_success = 0;

void setup() {
  CANbus.begin();

  pinMode(PIN_CS_FLASH, OUTPUT); // 
  digitalWrite(PIN_CS_FLASH, HIGH);

  initRGB();
  initCommunications();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  if (millis() % 5000 == 0) {
    sendMessage();
    strip.setPixelColor(1, 0x0000ff);
    strip.show();
    delay(20); 
    strip.setPixelColor(1, 0x000000);
    strip.show();
    Serial.println("msg was sent...");
    Serial.println(digitalPinToInterrupt(PIN_RFM_INT));
  }

  if (getCommand(data)) {
    Serial.println("msg was received...");
    Serial.println(data);
  } 

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

void initCommunications() {
  /*  */
  initSerial();
  
  resetRFM();

  initRFM();
  Serial.println("Success?");
  Serial.println(rfm_init_success);
}

void resetRFM() {
  /*  */
  Serial.println("rstRFM:Success!");
  pinMode(PIN_RFM_RST, OUTPUT);
  digitalWrite(PIN_RFM_RST, HIGH);
  delay(100);
  digitalWrite(PIN_RFM_RST, LOW);
  delay(10);
  digitalWrite(PIN_RFM_RST, HIGH);
  delay(100);
}

void initRFM() {
  /* Calls init method from RadioHead library and sets frequency and power to values defined in platformio.ini */
  Serial.println("initRFM:Success!");
  SPI1.setMOSI(PIN_MOSI1);
  SPI1.setMISO(PIN_MISO1);
  SPI1.setSCK(PIN_SCK1);

  rfm_init_success = rfm.init();
  Serial.println(rfm_init_success);
  if (rfm_init_success) {
    rfm.setFrequency(RFM_FREQ);
    rfm.setTxPower(RFM_TX_POWER);
  }
  showStatus();
}

void showStatus() {
  if (not rfm_init_success) {
    strip.setPixelColor(0, 0xff0000);
  } else {
    strip.setPixelColor(0, 0x00ff00);
  }
  strip.show();
}

void initSerial() {
  /*  */
  Serial.begin(9600); 
  while(!Serial);

  Serial.println("initSERIAL:Success!");

  Serial1.setRX(PIN_RX1);
  Serial1.setTX(PIN_TX1);
  Serial1.begin(SERIAL1_BAUD);

  Serial2.setRX(PIN_RX2);
  Serial2.setTX(PIN_TX2);
  Serial2.begin(SERIAL2_BAUD);

  Serial3.setRX(PIN_RX3);
  Serial3.setTX(PIN_TX3);
  Serial3.begin(SERIAL3_BAUD);
}

void initRGB() {
  strip.begin();
  delay(10);
  strip.clear();
  strip.setBrightness(20);
  strip.show();
  delay(100);
  strip.setPixelColor(0, STARTUP_COLOR);
  strip.show();
}

uint8_t getCommand(char* DATA) {
  uint8_t return_val = 0; 

  if (rfm_init_success) {
    if (rfm.waitAvailableTimeout(100)) { 
      uint8_t data_buffer[RH_RF95_MAX_MESSAGE_LEN];
      uint8_t buffer_len = sizeof(data_buffer);

      if (rfm.recv(data_buffer, &buffer_len)) {
        for (uint8_t i=0; i< CMD_DATA_LEN; i++) {
          DATA[i] = data_buffer[i];
          strip.setPixelColor(0, 0xff0000); 
          strip.show();
          delay(30);
          showStatus();
        }
      return_val = 1; 
      }
    }
  } else {
    return_val = 0; 
  }
  return return_val; 
}

void sendMessage() {
  uint8_t m_size = 2;
  uint8_t message[m_size];

  message[0] = 6; 
  message[1] = 23; 

  if (rfm_init_success) {
    strip.setPixelColor(0, 0x0000ff);
    strip.show();
    delay(20);
    rfm.send(message, m_size);
    rfm.waitPacketSent();
    showStatus();
  }
  
  Serial.write(message, m_size);
  Serial.write(0x00);
  // Include a carriage return and a line feed so the receiver can split out frames
  Serial.write(0x0D);
  Serial.write(0x0A);
  
}

