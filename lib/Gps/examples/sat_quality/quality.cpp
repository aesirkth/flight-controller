#include <stdio.h>
#include <cstring>

#include "../../src/Gps.cpp"

GPS gps;

void read_until(FILE* fp, char terminator, char* buf) {
  uint16_t index = 0;
  char byte;
  while (true) {
    byte = fgetc(fp);
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
    printf("---------------\n");
    if (IS_SET(gps.flags, FLAG_TIME)) {
      printf("time: %d%d%d%d\n", gps.hours, gps.minutes, gps.seconds, gps.milliseconds);
    }
    if (IS_SET(gps.flags, FLAG_POS_MODE)) {
      printf("GPS: %c\n", gps.gps_pos_mode);
      printf("GLONASS: %c\n", gps.glonass_pos_mode);
      printf("GALILEO: %c\n", gps.galileo_pos_mode);
      printf("BEIDOU: %c\n", gps.beidou_pos_mode);
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