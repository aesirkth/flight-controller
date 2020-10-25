#include "MAX31855.hpp"

///////* PUBLIC METHODS *///////
/*
    Class Constructor
    Takes an SPIClass instance and a SPISettings instance, the SPI bus must be configured
    previously. Also takes the pin for the CS signal connected to the sensor.
*/
Thermocouple::Thermocouple(uint8_t _cs_pin, SPIClass &spi_interface, SPISettings _spi_settings)
{
    this->_cs_pin = _cs_pin;
    this->_spi = &spi_interface;
    this->_spi_settings = _spi_settings;
    pinMode(_cs_pin, OUTPUT);
    csbHigh();

    temperature = 0;
    cold_junction = 0;
}

/*
    Read data from the sensor and updates the values of temperature, cold_junction and fault_byte
*/
uint8_t Thermocouple::update()
{
    readBytes();

    //Bit 16 indicates a Fault, in goes high when one of the error flags is active
    fault_byte = 0;
    if (rcv_data.uint32 & 0x00010000)
    {
        fault_byte = rcv_data.uint32 & 0x00000007;
    }

    // Bits D[31:18] are the signed 14-bit thermocouple temperature value. Is in Q11.2 format
    // Sign extend negative numbers if bit 31 is '1'
    if (rcv_data.uint32 & 0x80000000) 
    { 
      temperature = (int16_t)(0xFFFC0000 | (rcv_data.uint32 >> 18));
      //temperature /= 4; // Discard decimal part
    }
    else 
    {
      temperature = (int16_t)(rcv_data.uint32 >> 18); // Shift off all but the temperature data
      //temperature /= 4; // Discard decimal part
    }
    
    // Bits D[15:4] are the signed 12-bit internal temperature value. Is in Q7.4 format
    // Sign extend negative numbers if bit 31 is '1'
    if (rcv_data.uint32 & 0x00008000)
    { // Sign extend negative numbers
        cold_junction = (int16_t)(0xFFFFF000 | (0x00000FFF & (rcv_data.uint32 >> 4)));
    }
    else
    {
        cold_junction = (int16_t)(0x00000FFF & (rcv_data.uint32 >> 4));
    }

    return fault_byte;
}

/*
    Returns the emperature value of the thermocouple
*/
int16_t Thermocouple::getTemperature()
{
    return temperature;
}

/*
    Returns the temperature value of the Cold Junction compensation sensor
*/
int16_t Thermocouple::getColdJunctionT()
{
    return cold_junction;
}

///////* PRIVATE METHODS *///////
/*
    Pull the CS pin LOW to enable the SPI interface on the chip
*/
void Thermocouple::csbLow() {
  digitalWrite(_cs_pin, LOW);
}

/*
    Pull the CS pin HIGH to disable the SPI interface on the chip
*/
void Thermocouple::csbHigh() {
  digitalWrite(_cs_pin, HIGH);
}

/*
    Reads the output register on the MAX31855
*/
void Thermocouple::readBytes()
{
    _spi->beginTransaction(_spi_settings);
    csbLow();
    rcv_data.bytes[3] = _spi->transfer(0x00);
    rcv_data.bytes[2] = _spi->transfer(0x00);
    rcv_data.bytes[1] = _spi->transfer(0x00);
    rcv_data.bytes[0] = _spi->transfer(0x00);
    csbHigh();
    _spi->endTransaction();
}