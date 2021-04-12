/* BasicPressure.ino

Author: Erwan Caffier

Description:
  Simple sketch to read the pressure and the temperature from a MS5611 barometric
  pressure sensor. SPI is used to communicate with the chip. Tested on Arduino
  nano and Teensy 3.6.

License:
  MIT License

  Copyright (c) 2020 Erwan Caffier

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <Arduino.h>
#include <SPI.h>

#include "MS5611.h"

// Create a MS5611 instance for a chip on SPI0, and with the Chip Select pin connected to pin 17
MS5611 my_sensor(17, SPI);

void setup() {
  Serial.begin(115200);

  // Initialize the instance before use
  // This will reset the chip and read the calibration data from it
  my_sensor.begin();

  // Optional : select the Oversampling Ratio
  //my_sensor.setOSR(MS5611_OSR_256);  // Default
  //my_sensor.setOSR(MS5611_OSR_512);
  //my_sensor.setOSR(MS5611_OSR_1024);
  //my_sensor.setOSR(MS5611_OSR_2048);
  //my_sensor.setOSR(MS5611_OSR_4096);
}

void loop() {
  // Get a measurement from the chip
  my_sensor.update();

  // The update() method updates the 'pressure' and 'temperature' attributes
  // Read them after calling update()
  int32_t temperature = my_sensor.temperature;  // In 0.01°C
  int32_t pressure = my_sensor.pressure;        // In 0.01 mbar

  // Convert temperatureto °C
  float temperature_f = temperature / 100.0f;
  // Convert pressure to mbar
  float pressure_f = pressure / 100.0f;

  Serial.print("Temperature: ");
  Serial.print(temperature_f);
  Serial.print("°C");
  Serial.print("\t\tPressure: ");
  Serial.print(pressure_f);
  Serial.println(" mbar");

  delay(1000);
}