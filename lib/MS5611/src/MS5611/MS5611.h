#ifndef _MS5611_H_
#define _MS5611_H_

#include <Arduino.h>
#include <SPI.h>

#define MS5611_RESET 0x1E
#define MS5611_PROM 0xA0
#define MS5611_PRES 0x40
#define MS5611_TEMP 0x50

#define MS5611_OSR_256 0
#define MS5611_OSR_512 2
#define MS5611_OSR_1024 4
#define MS5611_OSR_2048 6
#define MS5611_OSR_4096 8

#define MS5611_MAX_SPI_FREQ 20000000  // 20MHz

// #define MS5611_SKIP_COMP

class MS5611 {
  public:
  MS5611(uint8_t cs_pin, SPIClass &spi_interface);
  MS5611(uint8_t cs_pin, SPIClass &spi_interface, uint32_t spi_freq);
  void begin();
  void update();
  uint8_t setOSR(uint8_t osr);

  // Async functionality
  void updateAsync(); 
  void startSampling();
  void triggerAsync(uint8_t addr); 
  bool sample_available = false; 
  uint8_t last_trigger_time = 0;         // in ms

  int32_t temperature = 0;  // In 0.01°C
  int32_t pressure = 0;     // In 0.01 mbar

#ifndef UNIT_TESTING
 private:
#endif
  void reset();
  void readProm();
  void convertMeasurement(uint32_t D1, uint32_t D2);
  uint32_t readAdc(uint8_t addr);
  uint32_t readAsync(uint8_t addr);
  uint8_t readByte(uint8_t address);
  void readBytes(uint8_t address, uint8_t count, uint8_t *data);
  void csbLow();
  void csbHigh();

  // Initialized at instance creation
  uint8_t _cs_pin;
  SPIClass *_spi;
  uint32_t _spi_freq;

  SPISettings _spi_settings;

  // Initialized with begin()
  uint16_t _c[8];  // Stores the calibration values from the chip

  uint8_t _osr;  // Oversampling Ratio
  uint8_t _del;  // delay for conversion, in ms
};

#endif  // _MS5611_H_