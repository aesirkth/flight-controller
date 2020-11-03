#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <RHHardwareSPI1.h>
#include <RH_RF95.h>
#include <lora_protocol.h>
#include "hardware_definition_teensy.h"

#define COLOR_RED   0xff0000
#define COLOR_GREEN 0x00ff00
#define COLOR_BLUE  0x0000ff

#define LED_STATUS  1
#define LED_GNSS    0

#define SPI_FREQ 1000000  // 1MHz
#define RFM_SPI hardware_spi1

SPISettings spi_settings(SPI_FREQ, MSBFIRST, SPI_MODE0);

Adafruit_NeoPixel led_strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), RFM_SPI);
LoraGS lora_radio;

bool is_lora_init = false;
bool initLoRa();

// platformio run -t upload -e teensy_balloon
void setup()
{
        // Set I/O
        SPI.setMOSI(PIN_MOSI0);
        SPI.setMISO(PIN_MISO0);
        SPI.setSCK(PIN_SCK0);
        SPI.begin();

        SPI1.setMOSI(PIN_MOSI1);
        SPI1.setMISO(PIN_MISO1);
        SPI1.setSCK(PIN_SCK1);
        
        pinMode(PIN_PARA1, OUTPUT);
        pinMode(PIN_PARA2, OUTPUT);
        digitalWrite(PIN_PARA1, LOW);  // LOW means inactive parachute
        digitalWrite(PIN_PARA2, LOW);  // LOW means inactive parachute

        pinMode(PIN_J2_DIS, OUTPUT);
        pinMode(PIN_J4_DIS, OUTPUT);
        digitalWrite(PIN_J2_DIS, LOW);  // LOW means active Telemetry output
        digitalWrite(PIN_J4_DIS, LOW);

        // Initialize status LEDs
        led_strip.begin();
        delay(10);
        led_strip.clear();
        led_strip.setBrightness(20);
        delay(10);
        led_strip.show();

        delay(3000);
        Serial.begin(57600);
        Serial.println("INIT");
        is_lora_init = initLoRa();
        //while(!Serial);

}

void loop()
{

    if (is_lora_init) {
        //int8_t rssi = rfm.lastRssi();
        //Serial.print("Local RSSI: ");
        //Serial.println(rssi);

        //
        led_strip.setPixelColor(LED_STATUS, COLOR_GREEN);
        led_strip.show();
        if (rfm.waitAvailableTimeout(100)) 
        {
            uint8_t rf95_buf[RH_RF95_MAX_MESSAGE_LEN];
            uint8_t rf95_len = sizeof(rf95_buf);
            Serial.println("new message");

            if (rfm.recv(rf95_buf, &rf95_len)) 
            {
                //Serial.write(rf95_buf, rf95_len);
                lora_radio.parseData_GS(rf95_buf);
                rfm.send("Hi",3);
                led_strip.setPixelColor(LED_STATUS, COLOR_BLUE);
                led_strip.show();
            }
        }
        
        if (lora_radio.checkNewFC_PowerMode())
        {
            Serial.print("Power Mode: ");
            Serial.println(lora_radio.getFC_PowerMode());
        }
        if (lora_radio.checkNewFC_RadioMode())
        {
            Serial.print("Radio Mode: ");
            Serial.println(lora_radio.getFC_RadioMode());
        }
        if (lora_radio.checkNewFC_ParachuteMode())
        {
            Serial.print("Parachute Mode: ");
            Serial.println(lora_radio.getFC_ParachuteMode());
        }
        if (lora_radio.checkNewFC_Battery())
        {
            uint16_t v1, v2;
            lora_radio.getFC_Battery(&v1, &v2);
            Serial.print("Battery volt.: ");
            Serial.print(v1);
            Serial.print(" / ");
            Serial.println(v2);
        }
    }

    //delay(1000);
}

bool initLoRa()
{
    pinMode(PIN_RFM_RST, OUTPUT);
    digitalWrite(PIN_RFM_RST, HIGH);
    delay(100);
    digitalWrite(PIN_RFM_RST, LOW);
    delay(10);
    digitalWrite(PIN_RFM_RST, HIGH);
    delay(100);

    bool init_success = rfm.init();
    if (init_success) led_strip.setPixelColor(LED_STATUS, COLOR_GREEN);
    else led_strip.setPixelColor(LED_STATUS, COLOR_RED);
    led_strip.show();

    return init_success;
    // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
}


 
 
