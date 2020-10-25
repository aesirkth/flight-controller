#include <Arduino.h>
#include <SPI.h>

#define THERMO_FAULT_SCV 0x04 // Shot-circuit to Vcc
#define THERMO_FAULT_SCG 0x02 // Short circuit to GND
#define THERMO_FAULT_OC  0x01 // Open connection

class Thermocouple
{
// Private variables
private:
    union   // Union makes conversion from 4 uint8_t array to uint32_t easy
    { 
        uint8_t bytes[4];
        uint32_t uint32;
    } rcv_data;

    int16_t temperature;    // Q11.2 format
    int16_t cold_junction;  // Q7.4 format
    uint8_t fault_byte;     // Bit2 is SCV, Bit1 is SCG, Bit0 is OC

    uint8_t _cs_pin;
    SPIClass *_spi;
    SPISettings _spi_settings;

// Public methods
public:
    Thermocouple(uint8_t cs_pin, SPIClass &spi_interface, SPISettings _spi_settings);
    ~Thermocouple() {};

    uint8_t update();
    int16_t getTemperature();
    int16_t getColdJunctionT();

// Private methods
private:
    void csbLow();
    void csbHigh();
    void readBytes();
};