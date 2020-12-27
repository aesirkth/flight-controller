#include <stdio.h>
#include <cstring>

#include "../../src/Gps.cpp"

GPS gps;

void read_until(FILE* fp, char terminator, char* buf) {
  uint16_t index = 0;
  char byte;
  while (true) {
    byte = fgetc(fp);
    //fprintf(stderr, "ass pissing%c\n", byte);
    if (byte == terminator) break;
    if(byte == -1) continue;
    buf[index] = byte;
    index++;
  }
  buf[++index] = '\0';
}

int main(){
  FILE* fp = fopen("/tmp/stupid", "r");
  while (true) {
    char buf[128];
    for (int i = 0; i < 3; i++) {
      read_until(fp, '\n', buf);
      gps.parse_message(buf, 128);
    }

    if (IS_SET(gps.flags, FLAG_TIME)) {
      printf("time:\n");
      printf("%d\n", gps.hours);
      printf("%d\n", gps.minutes);
      printf("%d\n", gps.seconds);
      printf("%d\n", gps.milliseconds);
    }
    if (IS_SET(gps.flags, FLAG_LATITUDE)) {
      printf("latitude:\n");
      printf("%d\n", gps.latitude_degrees);
      printf("%lf\n", gps.latitude_minutes);
    }
    if (IS_SET(gps.flags, FLAG_LONGITUDE)) {
      printf("longitude:\n");
      printf("%d\n", gps.longitude_degrees);
      printf("%lf\n", gps.longitude_minutes);
    }
    if (IS_SET(gps.flags, FLAG_POS_MODE)) {
      printf("GPS: %c\n", gps.gps_pos_mode);
      printf("GLONASS: %c\n", gps.glonass_pos_mode);
      printf("GALILEO: %c\n", gps.galileo_pos_mode);
      printf("BEIDOU: %c\n", gps.beidou_pos_mode);
    }
    if (IS_SET(gps.flags, FLAG_POS_MODE_SINGLE)) {
      printf("single mode: %c\n", gps.pos_mode);
    }
    if (IS_SET(gps.flags, FLAG_N_SATELLITES)) {
      printf("n_satellites: %d\n", gps.n_satellites);
    }
    if (IS_SET(gps.flags, FLAG_HDOP)) { 
      printf("HDOP: %lf\n", gps.hdop);
    }
    if (IS_SET(gps.flags, FLAG_VDOP)) { 
      printf("VDOP: %lf\n", gps.vdop);
    }
    if (IS_SET(gps.flags, FLAG_PDOP)) { 
      printf("PDOP: %lf\n", gps.pdop);
    }
    if (IS_SET(gps.flags, FLAG_ALTITUDE)) {
      printf("altitude: %lf\n", gps.altitude);
    }
    if (IS_SET(gps.flags, FLAG_GEOID_SEPARATION)) {
      printf("geoid_separation: %lf\n", gps.geoid_separation);
    }
    if (IS_SET(gps.flags, FLAG_MAGNETIC_VARIATION)) {
      printf("magnetic variation: %d\n", gps.magnetic_variation);
    }
    if (IS_SET(gps.flags, FLAG_DATE)) {
      printf("Date:%d%d%d\n", gps.day, gps.month, gps.year);
    }
    if (IS_SET(gps.flags, FLAG_SPEED)) {
      printf("Speed: %lf knots, %lf m/s\n", gps.speed_knot, gps.speed_ms);
    }
    if (IS_SET(gps.flags, FLAG_COURSE_OVER_GROUND)) {
      printf("course over ground: %lf\n", gps.course_over_ground);
    }
    if(IS_SET(gps.flags, FLAG_FIX_STATUS)) {
      printf("fix status: %d\n", gps.fix_status);
    }
    if(IS_SET(gps.flags, FLAG_OP_MODE)) {
      printf("op mode: %c\n", gps.op_mode);
    }
    //zero all the flags, otherwise you can't tell which data is new and old
    gps.clear();
  }
}
