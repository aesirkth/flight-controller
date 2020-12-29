#include <Arduino.h>

#include "Gps.h"

#define BUF_LEN 100

Gps gps;

void init() {
    Serial.open(115200); //open gps serial
}

void loop() {
    while (Serial.available()) {
        char buf[BUF_LEN];
        Serial.readBytesUntil('\n', buf, BUF_LEN);
        gps.parse_message(buf, BUF_LEN);
    }

    //#####
    //do stuff with the data
    //#####
    gps.clear();
}