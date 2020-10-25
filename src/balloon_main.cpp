#include <Arduino.h>
#include <SPI.h>
#include <MS5611.h>          // https://github.com/wanysteus/MS5611
#include <RHHardwareSPI1.h>
#include <RH_RF95.h>
#include "hardware_definition_teensy.h"
#include "MAX31855.hpp"

#define SPI_FREQ 1000000  // 1MHz
#define RFM_SPI hardware_spi1

SPISettings spi_settings(SPI_FREQ, MSBFIRST, SPI_MODE0);

Thermocouple k_type(PIN_CS_TEMP2, SPI, spi_settings);
MS5611 ms1(PIN_CS_MS1, SPI, SPI_FREQ); // Pressure sensor
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), RFM_SPI);

bool lora_success = false;
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

        ms1.begin();
        Serial.begin(57600);
        lora_success = initLoRa();
        //while(!Serial);

}

void loop()
{
        // Get measurements from the batteries
        uint32_t bat1_raw_mv = analogRead(PIN_BAT1);
        uint32_t bat2_raw_mv = analogRead(PIN_BAT2);
        //uint32_t bat1_raw_mv = (3223 * analogRead(PIN_BAT1)) / 1000;
        //uint32_t bat2_raw_mv = (3223 * analogRead(PIN_BAT2)) / 1000;
        uint32_t bat1_voltage = (5263 * bat1_raw_mv) / 10000; // 0.01V
        uint32_t bat2_voltage = (3125 * bat2_raw_mv) / 10000; // 0.01V
        // Get a measurement from the chip
        ms1.update();
        k_type.update();

        // The update() method updates the 'pressure' and 'temperature' attributes
        // Read them after calling update()
        int32_t temperature = ms1.temperature;  // In 0.01°C
        int32_t pressure = ms1.pressure;        // In 0.01 mbar

        uint8_t buffer[20];
        uint8_t buf_size = 0;

        // Send time since boot in milliseconds
        uint32_t ms_since_boot = millis();
        buffer[0] = 0x0A;
        buffer[1] = 0x0D;
        buffer[2] = 0x90;
        buffer[3] = (uint8_t)(ms_since_boot >> 24);
        buffer[4] = (uint8_t)(ms_since_boot >> 16);
        buffer[5] = (uint8_t)(ms_since_boot >> 8);
        buffer[6] = (uint8_t)ms_since_boot;
        buf_size = 7;
        //Serial.write(buffer, buf_size);

        // Send pressure and temperature data
        buffer[0] = 0x0A;
        buffer[1] = 0x0D;
        buffer[2] = 0x95;
        buffer[3] = (uint8_t)(temperature >> 24);
        buffer[4] = (uint8_t)(temperature >> 16);
        buffer[5] = (uint8_t)(temperature >> 8);
        buffer[6] = (uint8_t)temperature;
        buffer[7] = (uint8_t)(pressure >> 24);
        buffer[8] = (uint8_t)(pressure >> 16);
        buffer[9] = (uint8_t)(pressure >> 8);
        buffer[10] = (uint8_t)pressure;
        buf_size = 11;
        //Serial.write(buffer, buf_size);

        // Send batteries data
        buffer[0] = 0x0A;
        buffer[1] = 0x0D;
        buffer[2] = 0x96;
        buffer[3] = (uint8_t)(bat1_raw_mv >> 8);
        buffer[4] = (uint8_t)bat1_raw_mv;
        buffer[5] = (uint8_t)(bat2_raw_mv >> 8);
        buffer[6] = (uint8_t)bat2_raw_mv;
        buf_size = 7;
        //Serial.write(buffer, buf_size);

        // Read the temperature in Celsius
        float temp_couple = 0;
        //if (!isnan(temp_couple)) {
            temp_couple = k_type.getColdJunctionT()/16.0;
            Serial.print("CJ[C] = ");
            Serial.print(temp_couple);
            temp_couple = k_type.getTemperature()/4.0;
            Serial.print("  //  Temp[C] = ");
            Serial.println(temp_couple);
        //}

        if (lora_success) {
            int8_t rssi = rfm.lastRssi();
            Serial.print("Local RSSI: ");
            Serial.println(rssi);

            rfm.send("Hello World", 12);

            //
            if (rfm.waitAvailableTimeout(100)) 
            {
                uint8_t rf95_buf[RH_RF95_MAX_MESSAGE_LEN];
                uint8_t rf95_len = sizeof(rf95_buf);

                if (rfm.recv(rf95_buf, &rf95_len)) 
                {
                    Serial.print("Rx: ");
                    Serial.write(rf95_buf,rf95_len);
                }
            }
        }

        delay(1000);
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
    if (init_success) Serial.println("[LoRa] Successful initialization");
    else Serial.println("[LoRa] Init ERROR");

    return init_success;
    // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
}


 
 
