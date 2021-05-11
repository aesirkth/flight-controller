#include <stdint.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <RH_RF95.h> //THIS IS A MODIFIED LIBRARY WITHOUT ERROR CHECKING
#include <RHHardwareSPI1.h>
#include <stdio.h>
#include <array>

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

char RELAY_BUFFER[TELECOMMAND_MAX_MSG_LEN];
uint8_t RELAY_BUFFER_LEN = 0; 

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

void fc::rx(fc::handshake_from_ground_station_to_flight_controller msg) {
    fc::return_handshake_from_flight_controller_to_ground_station response;
    uint8_t len = response.get_size() + HEADER_SIZE;
    uint8_t buf[len];
    protocol.build_buf(response, buf, &len);
    delay(100);
    Serial.write(buf, len);
    delay(500);
}

void DataProtocolCallback(uint8_t id, uint8_t* buf, uint8_t len) {
    fc::parse_message(id, buf);
}

void setup()
{
    protocol.set_callback(&DataProtocolCallback);
    Serial.begin(115200);
    while(!Serial);
    initRGB();
    initRadio();
    showOk();
}

void handleDataStreams()
{
    uint8_t buffer[TELECOMMAND_MAX_MSG_LEN];
    uint8_t len = TELECOMMAND_MAX_MSG_LEN;
    // Sending from station to FC
    while (Serial.available() > 0) { // Fill up relay buffer
        char byte = Serial.read();
        protocol.parse_byte(byte);
        Serial.print(byte); // Show that character is registered

        if (RELAY_BUFFER_LEN >= TELECOMMAND_MAX_MSG_LEN){
            Serial.println("Message length overridden!!");
        } else {
            RELAY_BUFFER[RELAY_BUFFER_LEN] = uint8_t(byte);
            RELAY_BUFFER_LEN++; 
        }
    }
    if (RELAY_BUFFER_LEN>0) { // Try to send buffer
        // The following conversion should not be necessary..
        uint8_t bytes_formatted[TELECOMMAND_MAX_MSG_LEN];
        for (int i=0; i<TELECOMMAND_MAX_MSG_LEN; i++) { 
            bytes_formatted[i] = uint8_t(RELAY_BUFFER[i]); 
        }
        if (rfm.send(bytes_formatted, RELAY_BUFFER_LEN)) {
            RELAY_BUFFER_LEN = 0; // Reset to buffer is filled with new characters
        }
    }
    // Receiving from FC to ground station
    if (rfm.recv(buffer, &len))
    {
        // Serial.write(buffer, len); 

        for (int i=0; i<len; i++) {
            Serial.print(char(buffer[i]));
        }
    }
}

void loop()
{
    handleDataStreams(); 
}