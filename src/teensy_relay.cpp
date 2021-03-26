#include <stdint.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <RH_RF95.h> //THIS IS A MODIFIED LIBRARY WITHOUT ERROR CHECKING
#include <RHHardwareSPI1.h>
#include <stdio.h>

#include "hardware_definition_teensy.h"
#include "DataProtocol.h"
#include "fc.h"

#define BLUE 0x0000FF  //blue
#define GREEN 0x00FF00 //green
#define RED 0xFF0000   //red
#define STATE_LED 1
#define TELECOMMAND_MAX_MSG_LEN 30
#define BACKUP_BUF_LEN 100
#define TELEMETRY_BUF_LEN 100
#define TELECOMMAND_BUF_LEN 100

bool rfm_init_success = 0;
bool error = false;

// LEDs
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);

// For LoRa Communication
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), hardware_spi1);

DataProtocol protocol;

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
    initRGB();
    initRadio();
    showOk();
}

void handleDataStreams()
{
    uint8_t buffer[TELECOMMAND_MAX_MSG_LEN];
    uint8_t len = TELECOMMAND_MAX_MSG_LEN;
    while (Serial.available() > 0)
    {
        uint8_t byte = Serial.read();
        rfm.send(byte, sizeof(byte)); 
    }
    if (rfm.recv(buffer, &len))
    {
        Serial.write(buffer, &len); 
    }
}

void loop()
{
    handleDataStreams(); 
}