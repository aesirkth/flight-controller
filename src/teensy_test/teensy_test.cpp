#include <stdint.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <RH_RF95.h> //THIS IS A MODIFIED LIBRARY WITHOUT ERROR CHECKING
#include <RHHardwareSPI1.h>
#include <stdio.h>
#include <array>
#include <Wire.h>

#include "hardware_definition_teensy.h"
#include "DataProtocol.h"
#include "fc.h"

#define BLUE 0x0000FF  //blue
#define GREEN 0x00FF00 //green
#define RED 0xFF0000   //red
#define PINK 0xFF7070
#define YELLOW 0x00FFFF
#define STATE_LED 1
#define TELECOMMAND_MAX_MSG_LEN 30
#define BACKUP_BUF_LEN 100
#define TELEMETRY_BUF_LEN 100
#define TELECOMMAND_BUF_LEN 100

#define PARACHUTE_ON_TIME 1000

char RELAY_BUFFER[TELECOMMAND_MAX_MSG_LEN];
uint8_t RELAY_BUFFER_LEN = 0; 

// LEDs
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);

// For LoRa Communication
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1);

DataProtocol protocol;
bool armed = false;
bool error = false;
bool rfm_init_success = false;

void showError()
{
    strip.setPixelColor(STATE_LED, RED);
    strip.show();
    digitalWriteFast(LED_BUILTIN, HIGH);
    error = true;
}

void showOk()
{
    if (error)
    {
        return;
    }
    strip.setPixelColor(STATE_LED, GREEN);
    strip.show();
    digitalWriteFast(LED_BUILTIN, LOW);
}

void showNeutral() {
    if (error)
    {
        return;
    }
    strip.setPixelColor(STATE_LED, BLUE);
    strip.show();
    digitalWriteFast(LED_BUILTIN, LOW);
}

void initPins() {
  pinMode(PIN_RFD_DIS, OUTPUT);
  pinMode(PIN_FPV_DIS, OUTPUT);
  pinMode(PIN_RFM_RST, OUTPUT);
  pinMode(PIN_PARA1, OUTPUT);
  pinMode(PIN_PARA2, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  analogWriteFrequency(PIN_BUZZER, BUZZER_FREQ);
  analogWriteRes(8);
  digitalWriteFast(PIN_RFD_DIS, LOW); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_FPV_DIS, HIGH); //HIGH MEANS DISABLED
  digitalWriteFast(PIN_PARA1, LOW); //LOW IS INACTIVE
  digitalWriteFast(PIN_PARA2, LOW); //LOW IS INACTIVE
  SPI1.setMOSI(PIN_MOSI1);
  SPI1.setMISO(PIN_MISO1);
  SPI1.setSCK(PIN_SCK1);
  SPI1.begin();
  SPI.setMOSI(PIN_MOSI0);
  SPI.setMISO(PIN_MISO0);
  SPI.setSCK(PIN_SCK0);
  SPI.begin();
  delay(100);
}

void initRGB()
{
    strip.begin();
    delay(10);
    strip.clear();
    strip.setBrightness(10);
    strip.show();
    delay(100);
    strip.setPixelColor(STATE_LED, BLUE);
    strip.show();
    digitalWriteFast(LED_BUILTIN, LOW);
}
void resetRadio()
{
    digitalWriteFast(PIN_RFM_RST, HIGH);
    delay(100);
    digitalWriteFast(PIN_RFM_RST, LOW);
    delay(100);
    digitalWriteFast(PIN_RFM_RST, HIGH);
    delay(100);
}

void initRadio()
{
    /* Calls init method from RadioHead library and sets frequency and power to values defined in platformio.ini */
    SPI1.setMOSI(PIN_MOSI1);
    SPI1.setMISO(PIN_MISO1);
    SPI1.setSCK(PIN_SCK1);

    resetRadio();
    rfm_init_success = rfm.init();
    Serial.println(rfm_init_success);
    if (rfm_init_success)
    {
        rfm.setFrequency(RFM_FREQ);
        rfm.setTxPower(RFM_TX_POWER);
    }
    else
    {
        showError();
    }
}

void setup()
{
    Serial.begin(115200);
    while(!Serial);
    initRGB();
    showOk();
    initPins();
    Wire.setSCL(PIN_SCL0);
    Wire.setSDA(PIN_SDA0);
    Wire.setClock(120000);
    Wire.begin();

}

void loop()
{
    delay(500);
    Wire.requestFrom(0x28, 2);
    uint16_t pressure;
    pressure = (Wire.read() & 0b00111111) << 8;
    pressure += Wire.read();

    float result = ((float) pressure - 1638.0) * (5.0) / (14745.0 - 1638.0);
    Serial.println(result);
}