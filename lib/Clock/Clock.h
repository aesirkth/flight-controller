#include <stdint.h>

#define MS_IN_SECOND 1000
#define MS_IN_MINUTE (1000 * 60)
#define MS_IN_HOUR (1000 * 60 * 60)

class Clock {
  private:
  uint32_t when_updated;
  uint32_t last_time;
  uint32_t get_current_time_raw();

  public:
  void update(uint32_t formatted_time);
  void update(uint8_t hours, uint8_t minutes, uint8_t seconds, uint16_t milliseconds);
  uint32_t get_current_time();
  uint8_t get_hours();
  uint8_t get_minutes();
  uint8_t get_seconds();
  uint16_t get_milliseconds();
};