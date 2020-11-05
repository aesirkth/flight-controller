#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <MS5611.h>          // https://github.com/wanysteus/MS5611
#include <RHHardwareSPI1.h>
#include <RH_RF95.h>
#include "hardware_definition_teensy.h"
#include "MAX31855.hpp"
//#include <lora_protocol.h>
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
Thermocouple kt1(PIN_CS_TEMP1, SPI, spi_settings);
Thermocouple kt2(PIN_CS_TEMP2, SPI, spi_settings);
MS5611 ms1(PIN_CS_MS1, SPI, SPI_FREQ); // Pressure sensor
MS5611 ms2(PIN_CS_MS2, SPI, SPI_FREQ); // Pressure sensor
TinyGPSPlus gps;
RH_RF95 rfm(PIN_RFM_NSS, digitalPinToInterrupt(PIN_RFM_INT), RFM_SPI);
//LoraFC lora_radio;

uint32_t gps_time = 0;
gnss_data_t gps_data;
uint32_t prev_time = 0;
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

        delay(3000);
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
        ms2.begin();
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
        int32_t int_temp_1, int_temp_2;
        int32_t int_pres_1, int_pres_2;
        int16_t ext_temp_1, ext_temp_2;
        uint32_t ms_since_boot;

        uint8_t buffer[100];
        uint8_t buf_size = 0;
        
        prev_time = millis();
        led_strip.setPixelColor(LED_STATUS, COLOR_BLUE);
        led_strip.show();

        // Get measurements from the batteries
        uint32_t adc1_raw = analogRead(PIN_BAT1);
        uint32_t adc2_raw = analogRead(PIN_BAT2);
        /*
        Serial.print("Raw_1: ");
        Serial.print(adc1_raw);
        Serial.print(" / Raw_2: ");
        Serial.println(adc2_raw);
        */
        uint32_t bat1_raw_mv = (764 * adc1_raw) / 1000;
        uint32_t bat2_raw_mv = (764 * adc2_raw) / 1000;
        /*
        Serial.print("ADC_mv_1: ");
        Serial.print(bat1_raw_mv);
        Serial.print(" / ADC_mv_2: ");
        Serial.println(bat2_raw_mv);
        */
        uint32_t bat1_voltage = (16129 * bat1_raw_mv) / 10000; // 0.01V
        uint32_t bat2_voltage = (25000 * bat2_raw_mv) / 10000; // 0.01V
        /*
        Serial.print("Volt_1: ");
        Serial.print(bat1_voltage);
        Serial.print(" / Volt_2: ");
        Serial.println(bat2_voltage);
        */
        // Get a measurement from the chip
        ms1.update();
        ms2.update();
        kt1.update();
        kt2.update();
        ms_since_boot = millis();

        // The update() method updates the 'pressure' and 'temperature' attributes of MS5611
        // Read them after calling update()
        int_temp_1 = ms1.temperature;  // In 0.01°C
        int_temp_2 = ms2.temperature;  // In 0.01°C
        int_pres_1 = ms1.pressure;     // In 0.01 mbar
        int_pres_2 = ms2.pressure;     // In 0.01 mbar
        /*
        Serial.print("t1: ");
        Serial.print(int_temp_1);
        Serial.print(" / p1: ");
        Serial.println(int_pres_1);
        Serial.print("t2: ");
        Serial.print(int_temp_2);
        Serial.print(" / p2: ");
        Serial.println(int_pres_1);
        */
        // The same goes for the thermocouples
        ext_temp_1 = kt1.getTemperature();
        ext_temp_2 = kt2.getTemperature();

        // Send time since boot in milliseconds
        DataProtocol::build_Millis(buffer, &buf_size, ms_since_boot);
        Serial2.write(buffer, buf_size);

        // Send pressure and temperature data
        DataProtocol::build_PressTemp(buffer, &buf_size, int_pres_1, int_temp_1, int_pres_2, int_temp_2);
        Serial2.write(buffer, buf_size);

        // Send external temperature data
        DataProtocol::build_AirTemp(buffer, &buf_size, ext_temp_1, ext_temp_2);
        Serial2.write(buffer, buf_size);

        // Send batteries data
        DataProtocol::build_Battery(buffer, &buf_size, bat1_voltage, bat2_voltage);
        Serial2.write(buffer, buf_size);

        // Send GNSS acquired time
        DataProtocol::build_GnssTime(buffer, &buf_size, gps_time);
        Serial2.write(buffer, buf_size);

        // Send GNSS acquired navigation data
        DataProtocol::build_GnssData(buffer, &buf_size, gps_data);
        Serial2.write(buffer, buf_size);

        
        
        //    temp_couple = kt1.getColdJunctionT()/16.0;
        //    temp_couple = k_type.getTemperature()/4.0;
        

        if (gps.time.isValid())
        {
            gps_time = gps.time.value();
        }
        else
        {
            gps_time = 0;
        }
        Serial.print("\nNAVIGATION\nTime: ");
        Serial.println(gps_time);

        if (gps.location.isValid())
        {
            gps_data.latitude = gps.location.lat();
            gps_data.longitude = gps.location.lng();
        }
        else
        {
            gps_data.latitude = 0;
            gps_data.longitude = 0;
        }
        Serial.print("Latitude: ");
        Serial.print(gps_data.latitude);
        Serial.print(" / Longitude: ");
        Serial.println(gps_data.longitude);
        
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
        