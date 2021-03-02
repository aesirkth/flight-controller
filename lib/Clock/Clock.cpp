#include <Arduino.h>
#include "Clock.h"

void Clock::update(uint32_t formatted_time) {
  uint16_t milliseconds = formatted_time % 1000;
  formatted_time /= 1000;
  uint8_t seconds = formatted_time % 100;
  formatted_time /= 100;
  uint8_t minutes = formatted_time % 100;
  formatted_time /= 100;
  uint8_t hours = formatted_time % 100;

  last_time = hours * MS_IN_HOUR + minutes * MS_IN_MINUTE + 
              seconds * MS_IN_SECOND + milliseconds;   
  when_updated = millis();
}

void Clock::update(uint8_t hours, uint8_t minutes, uint8_t seconds, uint16_t milliseconds) {
  last_time = hours * MS_IN_HOUR + minutes * MS_IN_MINUTE + 
              seconds * MS_IN_SECOND + milliseconds;   
  when_updated = millis();
}


uint32_t Clock::get_current_time_raw() {
  return last_time + millis() - when_updated;
}
uint8_t Clock::get_hours() {
  return get_current_time_raw() / MS_IN_HOUR;
}
uint8_t Clock::get_minutes() {
  return (get_current_time_raw() / MS_IN_MINUTE) % 60; 
}
uint8_t Clock::get_seconds() {
  return (get_current_time_raw() / MS_IN_SECOND) % 60; 
}
uint16_t Clock::get_milliseconds() {
  return get_current_time_raw() % 1000;
}
uint32_t Clock::get_current_time() {
  return get_milliseconds() + get_seconds() * 1000 + get_minutes() * 1000 * 100 + 
         get_hours() * 1000 * 100 * 100;
}