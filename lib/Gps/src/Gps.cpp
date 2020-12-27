#include <cstring>
#include <math.h>

#include "Gps.h"

template <class T>
bool GPS::parse_field_to_uint(T* result, char message[], uint8_t* msg_index) {
  char buf[FIELD_BUF_LEN];
  uint8_t buf_index = 0;
  while (buf_index < FIELD_BUF_LEN) {
    if (message[*msg_index] < '0' || message[*msg_index] > '9') {
      break;
    } 
    buf[buf_index++] = message[(*msg_index)++];
  }
  (*msg_index)++; //skip the ','

  //empty field
  if (buf_index == 0) {
    *result = 0;
    return false;
  }
  buf[++buf_index] = '\0'; //terminate string
  *result = atoi(buf);
  return true;
}

template <class T>
bool GPS::parse_len_to_uint(T* result, char message[], uint8_t* index, uint8_t len) {
  *result = 0;
  
  for (uint8_t i = 0; i < len; i++) {
    *result *= 10;
    *result += message[(*index)++] - '0';
  }
  return true;
}

bool GPS::parse_field_to_double(double* result, char message[], uint8_t* msg_index) {
  char buf[FIELD_BUF_LEN];
  uint8_t buf_index = 0;
  
  while (buf_index < FIELD_BUF_LEN) {
    if ((message[*msg_index] < '0' || message[*msg_index] > '9') && 
        message[*msg_index] != '.') {
      break;
    }
    buf[buf_index++] = message[(*msg_index)++];
  }
  (*msg_index)++; //skip ,

  //empty field
  if (buf_index == 0) {
    return false;
  }
  buf[buf_index] = '\0'; //terminate string
  *result = atof(buf);
  return true; 
}


void GPS::generate_checksum(char message[], char buf[]) {
  uint8_t index = 1; //1 to skip $
  uint8_t checksum = 0;
  while (true) {
    checksum ^= message[index];
    index++;
    if (message[index] == '*') {
      break;
    }
  }
  to_hex(checksum, buf);
}


bool GPS::verify_message(char message[], uint8_t msg_len) {
  char checksum[2];
  uint8_t index = 0;
  while (true) {
    index++;
    if (message[index] == '*') {
      break; 
    }
    //if there is no checksum it't can be wrong!
    if (message[index] == '\r') {
      return true;
    }
    if (index == msg_len) {
      return false;
    }
  }
  generate_checksum(message, checksum);
  return memcmp(checksum, &message[++index], 2) == 0;
}


void GPS::to_hex(uint8_t num, char buf[]) {
  const char* chars = "0123456789ABCDEF";
  buf[1] = chars[num & 0x0F];
  buf[0] = chars[(num & 0xF0) >> 4];
}


bool GPS::parse_message(char message[], uint8_t buf_len) {
  if (!verify_message(message, buf_len)) {
    SET(flags, FLAG_ERROR_MESSAGE);
    return false;
  }

  //switch on talker id
  constellation = message[2];

  //only care about the multi constellation messages for now
  if (constellation != NS_COMBINATION) {
    return true;
  }
  
  //switch on message type
  char* type_pos = &message[3];
  
  //GNS is basically GGA 2.0
  if (memcmp(type_pos, "GNS", 3) == 0) {
    parse_gns(type_pos + 4);
  }
  if (memcmp(type_pos, "GSA", 3) == 0) {
    parse_gsa(type_pos + 4);
  } else 
  if (memcmp(type_pos, "RMC", 3) == 0) {
    parse_rmc(type_pos + 4);
  }
  return true;
}

void GPS::parse_gns(char message[]) {
  uint32_t whole;
  double number;
  uint8_t index = 0;

  //decode time
  if (message[index] != ',') {
    SET(flags, FLAG_TIME);
    parse_len_to_uint(&hours, message, &index, 2);
    parse_len_to_uint(&minutes, message, &index, 2);
    parse_len_to_uint(&seconds, message, &index, 2);
    index++; //skip '.'
    uint8_t start = index;
    parse_field_to_uint(&milliseconds, message, &index);
    milliseconds *= pow(10, 4 - index + start);
  } //end time

  //decode latitude
  if (message[index] != ',') {
    SET(flags, FLAG_LATITUDE);
    parse_len_to_uint(&latitude_degrees, message, &index, 2);
    parse_field_to_double(&latitude_minutes, message, &index);
  } else {
    index++;
  }

  //NS
  if (message[index] != ',') {
    if (message[index] == 'S') {
      latitude_degrees *= -1;
    }
    index++;
  }
  index++;

  //longitude
  if (message[index] != ',') {
    SET(flags, FLAG_LONGITUDE);
    parse_len_to_uint(&longitude_degrees, message, &index, 3);
    parse_field_to_double(&longitude_minutes, message, &index);
  } else {
    index++;
  }

  //EW
  if (message[index] != ',') {
    if (message[index] == 'W') {
      latitude_degrees *= -1;
    }
    index++;
  }
  index++;

  //constellation information
  if (message[index] != ',') {
    SET(flags, FLAG_POS_MODE);
    gps_pos_mode = message[index++];
    glonass_pos_mode = message[index++];
    galileo_pos_mode = message[index++];
    beidou_pos_mode = message[index++];
  }
  index++;

  //n_satellites
  if (parse_field_to_uint(&n_satellites, message, &index)) {
    SET(flags, FLAG_N_SATELLITES);
  }
  //hdop
  if (parse_field_to_double(&hdop, message, &index)) {
    SET(flags, FLAG_HDOP);
  }
  //altitude
  if (parse_field_to_double(&altitude, message, &index)) {
    SET(flags, FLAG_ALTITUDE);
  }
  //geoid_separation
  if (parse_field_to_double(&geoid_separation, message, &index)) {
    SET(flags, FLAG_GEOID_SEPARATION);
  }
  //diff_age
  if (parse_field_to_uint(&diff_age, message, &index)) {
    SET(flags, FLAG_DIFF_AGE);
  } 
  //diff_station
  if (parse_field_to_uint(&diff_station, message, &index)) {
    SET(flags, FLAG_DIFF_STATION);
  }
}

void GPS::parse_rmc(char* message) {
  uint32_t whole;
  double number;
  uint8_t index = 0;

  //decode time
  if (message[index] != ',') {
    SET(flags, FLAG_TIME);
    parse_len_to_uint(&hours, message, &index, 2);
    parse_len_to_uint(&minutes, message, &index, 2);
    parse_len_to_uint(&seconds, message, &index, 2);
    index++; //skip '.'
    uint8_t start = index;
    parse_field_to_uint(&milliseconds, message, &index);
    milliseconds *= pow(10, 4 - index + start);
  } //end time

  //status is just posmode light
  //this is pretty useless
  if (message[index] != ',') {
    index++;
  }
  index++;

  //decode latitude
  if (message[index] != ',') {
    SET(flags, FLAG_LATITUDE);
    parse_len_to_uint(&latitude_degrees, message, &index, 2);
    parse_field_to_double(&latitude_minutes, message, &index);
  } else {
    index++;
  }

  //NS
  if (message[index] != ',') {
    if (message[index] == 'S') {
      latitude_degrees *= -1;
    }
    index++;
  }
  index++;

  //longitude
  if (message[index] != ',') {
    SET(flags, FLAG_LONGITUDE);
    parse_len_to_uint(&longitude_degrees, message, &index, 3);
    parse_field_to_double(&longitude_minutes, message, &index);
  } else {
    index++;
  }

  //EW
  if (message[index] != ',') {
    if (message[index] == 'W') {
      longitude_degrees *= -1;
    }
    index++;
  }
  index++;

  //speed
  if (parse_field_to_double(&speed_knot, message, &index)) {
    SET(flags, FLAG_SPEED);
    speed_ms = speed_knot * KNOT_TO_MS;
  }

  //course over ground
  if (parse_field_to_double(&course_over_ground, message, &index)) {
    SET(flags, FLAG_COURSE_OVER_GROUND);
  }

  //date
  if (message[index] != ',') {
    SET(flags, FLAG_DATE);
    parse_len_to_uint(&day, message, &index, 2);
    parse_len_to_uint(&month, message, &index, 2);
    parse_len_to_uint(&year, message, &index, 2);
  }
  index++;

  //magnetic variation
  if (parse_field_to_double(&magnetic_variation, message, &index)) {
    SET(flags, FLAG_MAGNETIC_VARIATION);
  } 
  if (message[index] != ',') {
    if (message[index] == 'W') {
      magnetic_variation *= -1;
    }
    index++;
  }
  index++;
  
  //posmode, the one from gns is better 
  if (message[index] != ',') {
    SET(flags, FLAG_POS_MODE_SINGLE);
    pos_mode = message[index];
  }
}

//This is a todo, i don't know if we will need all that satellite info.
void GPS::parse_gsa(char* message) {
  uint8_t index = 0;
  double waste;

  if(message[index] != ',') {
    SET(flags, FLAG_OP_MODE);
    op_mode = message[index];
    index++;
  }
  index++;

  if(parse_field_to_uint(&fix_status, message, &index)) {
    SET(flags, FLAG_FIX_STATUS);
  }

  //12 fields of satellite IDs, this is pretty useless informaiton so i throw it away
  for (uint8_t i = 0; i < 12; i++) {
    parse_field_to_double(&waste, message, &index);
  }

  if(parse_field_to_double(&pdop, message, &index)) {
    SET(flags, FLAG_PDOP);
  }
  if(parse_field_to_double(&hdop, message, &index)) {
    SET(flags, FLAG_HDOP);
  }
  if(parse_field_to_double(&vdop, message, &index)) {
    SET(flags, FLAG_VDOP);
  }
}