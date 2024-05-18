#include <Arduino.h>
#include <hardware_definition_main.h>

void setup() {
    Serial.begin(115200);
    //init telemetry
    
    TM_SERIAL.setRX(PIN_TM_RX);
    TM_SERIAL.setTX(PIN_TM_TX);
    TM_SERIAL.begin(115200);
}

void loop() {
    while (Serial.available()) {
        TM_SERIAL.write(Serial.read());
    }
    while (TM_SERIAL.available()) {
        Serial.write(TM_SERIAL.read());
    }
}