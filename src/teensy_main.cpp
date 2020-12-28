#include <Adafruit_NeoPixel.h>  // https://github.com/adafruit/Adafruit_NeoPixel
#include <Arduino.h>
#include <SPI.h>
#include "hardware_definition_teensy.h"
#include "FlashMemory.hpp"

#define WT_PAGE_MSB 0x00
#define WT_PAGE_LSB 0x01

SPISettings settingsFlash(10000000, MSBFIRST, SPI_MODE0); // SPI bus settings to communicate with the Flash IC
Flash memory(&SPI1, settingsFlash, PIN_CS_FLASH, PIN_WP, PIN_HOLD);
uint8_t write_buffer[2048];
uint8_t read_buffer[2048];

uint8_t checkBusyFlash();

void setup()
{
    SPI1.setMOSI(PIN_MOSI1);
    SPI1.setMISO(PIN_MISO1);
    SPI1.setSCK(PIN_SCK1);
    pinMode(PIN_RFM_NSS, OUTPUT);
    digitalWrite(PIN_RFM_NSS, HIGH);
    // Set Flash IC CS, WP, HOLD line to high (this should be done through pullup resistors)

    // Set I/O we don't care about at the moment
    pinMode(PIN_PARA1, OUTPUT);
    pinMode(PIN_PARA2, OUTPUT);
    digitalWrite(PIN_PARA1, LOW);  // LOW means inactive parachute
    digitalWrite(PIN_PARA2, LOW);  // LOW means inactive parachute
    pinMode(PIN_J2_DIS, OUTPUT);
    pinMode(PIN_J4_DIS, OUTPUT);
    digitalWrite(PIN_J2_DIS, LOW);  // LOW means active Telemetry output
    digitalWrite(PIN_J4_DIS, LOW);

    uint8_t count = 0;
    for (int i = 0; i < 2048; i++)
    {
        read_buffer[i] = 0;
        write_buffer[i] = count;
        count++;
        //count--;
    }
    

    delay(3000); //Make sure everything had time to initialize after power up

    SPI1.begin(); // Initialize the SPI bus for the Flash IC
    Serial.begin(57600); // Open Serial port with the PC
/*    for (int i = 0; i < 200; i++)
    {
    Serial.print(write_buffer[i]);
    Serial.print(",");
    }*/
    Serial.println("\nINIT");
}

void loop()
{
    if (memory.test() == RET_SUCCESS)
    {
        Serial.println("JEDEC ID match");
    }
    else
    {
        Serial.println("JEDEC don't match ERROR");
    }

    uint8_t reg_val = 0;
    memory.readStatusRegister(SR_1_ADDR, &reg_val);
    Serial.print("SR-1: ");
    Serial.println(reg_val, BIN);

    memory.checkFactoryBadBlocks();

/*
    uint8_t register_val = 0;
    SPI1.beginTransaction(settingsFlash);

    // Read Status Register SR-1
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xA0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-1: ");
    Serial.println(register_val, BIN);

    // Read Status Register SR-2
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xB0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-2: ");
    Serial.println(register_val, BIN);

    // Read Status Register SR-3
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xC0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-3: ");
    Serial.println(register_val, BIN);

    // Write Status Register SR-1 (Disable Block Protect Bits)
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x1F); // Read Status Register
    SPI1.transfer(0xA0); //Register address
    SPI1.transfer(0x00); // Reset all bits on the register
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Read Status Register SR-1
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xA0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-1: ");
    Serial.println(register_val, BIN);

    // Check Busy flag == 0
    while (checkBusyFlash())
    {
        delay (1);
    }

    // Read Device ID
    uint8_t temp = 0;
    uint8_t manu_id = 0;
    uint16_t ic_id = 0;
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x9F); // Read chip ID
    SPI1.transfer(0xFF); // Dummy
    temp = SPI1.transfer(0xFF); // Get Manufacturer ID
    manu_id = temp;
    temp = SPI1.transfer(0xFF); // Get Device ID 1/2
    ic_id = (uint16_t)temp << 8;
    temp = SPI1.transfer(0xFF); // Get Device ID 2/2
    ic_id |= (uint16_t)temp;
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Print IC info
    Serial.print("Manufacturer ID: ");
    Serial.println(manu_id, HEX);
    Serial.print("Device ID: ");
    Serial.println(ic_id, HEX);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}

uint32_t time_dif = 0;
// Read data from the memory
    time_dif = micros();
    // Load page data into buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x13); // Page Data Read
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    // Page Address (16 bits)
    SPI1.transfer(WT_PAGE_MSB);
    SPI1.transfer(WT_PAGE_LSB);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Page Data Read => ");
    Serial.print(time_dif);
    Serial.println(" us");

    time_dif = micros();
    // Read memory buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x03); // Read Data
    SPI1.transfer(0x00); // Column Address (16-bit)
    SPI1.transfer(0x00);
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    for (int i = 0; i < 2048; i++)
    {
        read_buffer[i] = SPI1.transfer(0xFF); // Read 1 byte of data
    }
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Read Data (2048 Bytes) => ");
    Serial.print(time_dif);
    Serial.println(" us");

// Read data from the memory
Serial.println("READ DATA");
for (int i = 0; i < 200; i++)
{
    Serial.print(read_buffer[i]);
    Serial.print(",");
}
Serial.println("\nREAD DATA \n");

// Write data to the memory
    // Write enable
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x06);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Read Status Register SR-3
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xC0); //Register address
    register_val = SPI1.transfer(0xFF);
    digitalWrite(PIN_CS_FLASH, HIGH);
    // Print register values
    Serial.print("SR-3: ");
    Serial.println(register_val, BIN);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}

    time_dif = micros();
    // Load data into buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x02); // Load Program Data
    SPI1.transfer(0x00); // Column Address (16-bit)
    SPI1.transfer(0x00);
    for (int i = 0; i < 2048; i++)
    {
        SPI1.transfer(write_buffer[i]); // Transfer 1 byte of data
    }
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Load Program Data (2048 Bytes) => ");
    Serial.print(time_dif);
    Serial.println(" us");

    time_dif = micros();
    // Save buffer into memory
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x10); // Program Execute
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    // Page Address (16 bits)
    SPI1.transfer(WT_PAGE_MSB);
    SPI1.transfer(WT_PAGE_LSB);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Program Execute => ");
    Serial.print(time_dif);
    Serial.println(" us");
// Write data to the memory

// Read data from the memory
    time_dif = micros();
    // Load page data into buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x13); // Page Data Read
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    // Page Address (16 bits)
    SPI1.transfer(WT_PAGE_MSB);
    SPI1.transfer(WT_PAGE_LSB);
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Page Data Read => ");
    Serial.print(time_dif);
    Serial.println(" us");

    time_dif = micros();
    // Read memory buffer
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x03); // Read Data
    SPI1.transfer(0x00); // Column Address (16-bit)
    SPI1.transfer(0x00);
    SPI1.transfer(0xFF); // 8 dummy clock cycles
    for (int i = 0; i < 2048; i++)
    {
        read_buffer[i] = SPI1.transfer(0xFF); // Read 1 byte of data
    }
    digitalWrite(PIN_CS_FLASH, HIGH);

    // Check Busy flag == 0
    while (checkBusyFlash()) {delayMicroseconds (1);}
    time_dif = micros() - time_dif;
    Serial.print("Read Data (2048 Bytes) => ");
    Serial.print(time_dif);
    Serial.println(" us");

// Read data from the memory
Serial.println("READ DATA");
for (int i = 0; i < 200; i++)
{
    Serial.print(read_buffer[i]);
    Serial.print(",");
}
Serial.println("\nREAD DATA \n");
*/
    while(1)
    {
        delay(1000);
        Serial.print(".");
    }

}

uint8_t checkBusyFlash()
{
    uint8_t ret_val = 0;
    // Read Status Register SR-3
    digitalWrite(PIN_CS_FLASH, LOW);
    SPI1.transfer(0x0F); // Read Status Register
    SPI1.transfer(0xC0); // SR-3 Address
    ret_val = SPI1.transfer(0xFF) & 0x01; // Read busy it value. If '1' the Flash is busy with some task.
    digitalWrite(PIN_CS_FLASH, HIGH);

    return ret_val;
}