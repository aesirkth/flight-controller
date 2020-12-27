#include <stdint.h>

#define KNOT_TO_MS 0.51444 

#define FIELD_BUF_LEN 20

#define FLAG_LATITUDE (1 << 0)
#define FLAG_LONGITUDE (1 << 1)
#define FLAG_TIME (1 << 2)
#define FLAG_N_SATELLITES (1 << 3)
#define FLAG_QUALITY (1 << 4)
#define FLAG_HDOP (1 << 5)
#define FLAG_ERROR_MESSAGE (1 << 6)
#define FLAG_POS_MODE (1 << 7)
#define FLAG_ALTITUDE (1 << 8)
#define FLAG_GEOID_SEPARATION (1 << 9)
#define FLAG_DIFF_AGE (1 << 10)
#define FLAG_DIFF_STATION (1 << 11)
#define FLAG_SPEED (1 << 12)
#define FLAG_COURSE_OVER_GROUND (1 << 13)
#define FLAG_DATE (1 << 14)
#define FLAG_MAGNETIC_VARIATION (1 << 15)
#define FLAG_POS_MODE_SINGLE (1 << 16)
#define FLAG_OP_MODE (1 << 17)
#define FLAG_FIX_STATUS (1 << 18)
#define FLAG_PDOP (1 << 19)
#define FLAG_VDOP (1 << 20)

#define NS_COMBINATION 'N'
#define NS_GPS 'P'
#define NS_GALILEO 'A'
#define NS_BEIDOU 'B'
#define NS_GLONASS 'L'
#define NS_QZSS 'Q'

#define POS_MODE_NO_POSITION 'N'
#define POS_MODE_ESTIMATE 'E'
#define POS_MODE_RTK_FLOAT 'F'
#define POS_MODE_RTK_FIXED 'R'
#define POS_MODE_AUTONOMOUS 'A'
#define POS_MODE_DIFFERENTIAL 'D'

#define IS_SET(bytes, flag) (bytes & flag)
#define SET(bytes, flag) (bytes |= flag)
#define CLEAR(bytes, flag) (bytes &= !flag)


class GPS {
public:
  void read();
  void init();
  void clear() {flags = 0;}

  uint32_t get_flags() {return flags;};

  void disable_message(char message_id[]);
  void set_refresh_rate(uint8_t);

  bool parse_message(char message[], uint8_t buf_len);

  uint32_t flags;

  int32_t latitude_degrees; //north positive
  double latitude_minutes;
  int32_t longitude_degrees; //east positive
  double longitude_minutes;
  double altitude;
  double geoid_separation;

  double speed_knot;
  double speed_ms;
  double course_over_ground;

  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
  uint16_t milliseconds;
  uint8_t day;
  uint8_t month;
  uint8_t year;

  uint8_t fix_status; // multi gnss

  char op_mode; // multi gnss

  char gps_pos_mode;
  char glonass_pos_mode;
  char galileo_pos_mode;
  char beidou_pos_mode;
  char pos_mode; //pos_mode from the last message. can be gps, galileo, beidou anything!

  double hdop;
  double pdop;
  double vdop;
  uint8_t n_satellites;
  uint8_t diff_age;
  uint8_t diff_station;

  double magnetic_variation;

private:
  template <class T>
  bool parse_len_to_uint(T* whole, char message[], uint8_t* index, uint8_t len);
  template <class T>
  bool parse_field_to_uint(T* whole, char message[], uint8_t* index);
  bool parse_field_to_double(double* num, char message[], uint8_t* index);

  void parse_gns(char message[]);
  void parse_rmc(char message[]);
  void parse_gsa(char message[]);

  void to_hex(uint8_t num, char buf[]);
  void generate_checksum(char message[], char buf[]);
  bool verify_message(char message[], uint8_t buf_len);
  void send_to_GPS(char message[]);

  uint8_t constellation;
};