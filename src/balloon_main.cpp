#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <MS5611.h>          // https://github.com/wanysteus/MS5611
#include <RHHardwareSPI1.h>
#include <RH_RF95.h>
#include "hardware_definition_teensy.h"
#include "MAX31855.hpp"
#include <lora_protocol.h>
#include <data_protocol.h>
#include <TinyGPS++.h>

#define COLOR_RED   0xff0000
#define COLOR_GREEN 0x00ff00
#define COLOR_BLUE  0x0000ff

#define LED_STATUS  1
#define LED_GNSS    0
#define SEND_INTERVAL 1000

#define SPI_FREQ 1000000  // 1MHz
#define RFM_SPI hardware_spi1

SPISettings spi_settings(SPI_FREQ, MSBFIRST, SPI_MODE0);

Adafruit_NeoPixel led_strip = Adafruit_NeoPixel(NUM_RGB_LEDS, PIN_LED_CTRL, NEO_GRB + NEO_KHZ400);
Thermocouple k_type(PIN_CS_TEMP2, SPI, spi_settings);
MS5611 ms1(PIN_CS_MS1, SPI, SPI_FREQ); // Pressure sensor
TinyGPSPlus gps;
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), RFM_SPI);
//LoraFC lora_radio;


uint32_t prev_time = 0;
bool is_lora_init = false;
bool initLoRa();

uint32_t gps_time = 0;
gnss_data_t gps_data;

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

        //delay(3000);
        // Initialize status LEDs
        led_strip.begin();
        delay(10);
        led_strip.clear();
        led_strip.setBrightness(20);
        delay(10);
        led_strip.show();

        Serial.begin(57600);
        Serial.println("INIT");
        Serial2.begin(57600);   //Telemetry link
        Serial3.begin(38400);   //GNSS link
        ms1.begin();
        is_lora_init = initLoRa();
        //while(!Serial);
        prev_time = millis();

}

void loop()
{
    // Decode GNSS received data
    while (Serial3.available() > 0)
    {
        gps.encode(Serial3.read());
    }

    // Each SEND_INTERVAL milliseconds take a sample of each sensor and transmit it
    if (SEND_INTERVAL < (millis() - prev_time))
    {
        int32_t temperature, pressure;
        uint32_t ms_since_boot;
        uint8_t buffer[50];
        uint8_t buf_size = 0;
        
        prev_time = millis();
        led_strip.setPixelColor(LED_STATUS, COLOR_BLUE);
        led_strip.show();
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
        ms_since_boot = millis();

        // The update() method updates the 'pressure' and 'temperature' attributes
        // Read them after calling update()
        temperature = ms1.temperature;  // In 0.01°C
        pressure = ms1.pressure;        // In 0.01 mbar

      
        // Send time since boot in milliseconds
        DataProtocol::build_Millis(buffer, &buf_size, ms_since_boot);
        /*
        buffer[0] = 0x0A;
        buffer[1] = 0x0D;
        buffer[2] = 0x90;
        buffer[3] = (uint8_t)(ms_since_boot >> 24);
        buffer[4] = (uint8_t)(ms_since_boot >> 16);
        buffer[5] = (uint8_t)(ms_since_boot >> 8);
        buffer[6] = (uint8_t)ms_since_boot;
        buf_size = 7;
        */
        Serial2.write(buffer, buf_size);

        // Send pressure and temperature data
        DataProtocol::build_PressTemp(buffer, &buf_size, pressure, temperature, pressure, temperature);
        /*
        buffer[0] = 0x0A;
        buffer[1] = 0x0D;
        buffer[2] = 0x96;
        buffer[3] = (uint8_t)(temperature >> 24);
        buffer[4] = (uint8_t)(temperature >> 16);
        buffer[5] = (uint8_t)(temperature >> 8);
        buffer[6] = (uint8_t)temperature;
        buffer[7] = (uint8_t)(pressure >> 24);
        buffer[8] = (uint8_t)(pressure >> 16);
        buffer[9] = (uint8_t)(pressure >> 8);
        buffer[10] = (uint8_t)pressure;
        buffer[11] = (uint8_t)(temperature >> 24);
        buffer[12] = (uint8_t)(temperature >> 16);
        buffer[13] = (uint8_t)(temperature >> 8);
        buffer[14] = (uint8_t)temperature;
        buffer[15] = (uint8_t)(pressure >> 24);
        buffer[16] = (uint8_t)(pressure >> 16);
        buffer[17] = (uint8_t)(pressure >> 8);
        buffer[18] = (uint8_t)pressure;
        buf_size = 19;
        */
        Serial2.write(buffer, buf_size);

        // Send batteries data
        DataProtocol::build_Battery(buffer, &buf_size, bat1_raw_mv, bat2_raw_mv);
        /*
        buffer[0] = 0x0A;
        buffer[1] = 0x0D;
        buffer[2] = 0x9A;
        buffer[3] = (uint8_t)(bat1_raw_mv >> 8);
        buffer[4] = (uint8_t)bat1_raw_mv;
        buffer[5] = (uint8_t)(bat2_raw_mv >> 8);
        buffer[6] = (uint8_t)bat2_raw_mv;
        buf_size = 7;
        */
        Serial2.write(buffer, buf_size);

        /*
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
        */

        if (gps.time.isValid())
        {
            gps_time = gps.time.value();
        }
        else
        {
            gps_time = 0;
        }
        Serial.print("Time: ");
        Serial.println(gps_time);

        RawDegrees lat, lon;
        if (gps.location.isValid())
        {
            lat = gps.location.rawLat();
            lon = gps.location.rawLng();
        }
        else
        {
            //gps_data.latitude = 0;
            //gps_data.longitude = 0;
        }
        Serial.print("Latitude: ");
        Serial.print(lat.deg);
        Serial.print(".");
        Serial.println(lat.billionths);
        Serial.print("Longitude: ");
        Serial.print(lon.deg);
        Serial.print(".");
        Serial.println(lon.billionths);
        
        if (gps.speed.isValid())
        {
            gps_data.speed = gps.speed.value();
        }
        else
        {
            gps_data.speed = 0;
        }
        Serial.print("Speed: ");
        Serial.println(gps_data.speed);

        if (gps.course.isValid())
        {
            gps_data.heading = gps.course.value();
        }
        else
        {
            gps_data.speed = 0;
        }
        Serial.print("Course: ");
        Serial.println(gps_data.heading);

        if (gps.altitude.isValid())
        {
            gps_data.altitude = gps.altitude.value();
        }
        else
        {
            gps_data.altitude = 0;
        }
        Serial.print("Altitude: ");
        Serial.println(gps_data.altitude);

        if (gps.satellites.isValid())
        {
            gps_data.n_satellites = gps.satellites.value();
        }
        else
        {
            gps_data.n_satellites = 0;
        }
        Serial.print("Satellites: ");
        Serial.println(gps_data.n_satellites);

        if (gps.hdop.isValid())
        {
            gps_data.h_dop = gps.hdop.value();
        }
        else
        {
            gps_data.h_dop = 0;
        }
        Serial.print("H DoP: ");
        Serial.println(gps_data.h_dop);

        
        delay(50);
        led_strip.setPixelColor(LED_STATUS, COLOR_GREEN);
        led_strip.show();
    }
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


 
 
/*
        Serial.println("pre_lora");
        if (is_lora_init) {
            //int8_t rssi = rfm.lastRssi();
            //Serial.print("Local RSSI: ");
            //Serial.println(rssi);
            uint8_t out_buf[RH_RF95_MAX_MESSAGE_LEN];
            uint8_t out_buf_len = 0;
            Serial.println("in_lora");

            led_strip.setPixelColor(LED_STATUS, COLOR_BLUE);
            led_strip.show();
            
            lora_radio.buildFC_PowerMode(out_buf, &out_buf_len, 0);
            rfm.send(out_buf, out_buf_len);
            rfm.waitPacketSent();
            rfm.waitAvailableTimeout(10);
            out_buf_len = sizeof(out_buf);
            if (rfm.recv(out_buf, &out_buf_len)) 
            {
                Serial.println("1");
            }
            
            lora_radio.buildFC_ParachuteMode(out_buf, &out_buf_len, 3);
            rfm.send(out_buf, out_buf_len);
            rfm.waitAvailableTimeout(10);
            out_buf_len = sizeof(out_buf);
            if (rfm.recv(out_buf, &out_buf_len)) 
            {
                Serial.println("2");
            }
            lora_radio.buildFC_RadioMode(out_buf, &out_buf_len, 2);
            rfm.send(out_buf, out_buf_len);
            rfm.waitAvailableTimeout(10);
            out_buf_len = sizeof(out_buf);
            if (rfm.recv(out_buf, &out_buf_len)) 
            {
                Serial.println("3");
            }
            
            lora_radio.buildFC_Battery(out_buf, &out_buf_len, (uint16_t)bat1_raw_mv, (uint16_t)bat2_raw_mv);
            rfm.send(out_buf, out_buf_len);
            rfm.waitAvailableTimeout(10);
            out_buf_len = sizeof(out_buf);
            if (rfm.recv(out_buf, &out_buf_len)) 
            {
                Serial.println("4");
            }
            
            
        }
        Serial.println("post_lora");
        */
        