#include <Arduino.h>
#include "WS2812Serial.h"
#include <SPI.h>

#include "DataProtocol.h"
#include "hardware_definitions_backup.h"
#include "fc.h"

#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010

#define TELEMETRY_BAUD 115200

void sendCallback(uint8_t id, uint8_t* buf, uint8_t len);
void receiveCallback(uint8_t id, uint8_t* buf, uint8_t len);

DataProtocol send_protocol {sendCallback};
DataProtocol receive_protocol {receiveCallback};

byte drawingMemory[3];         //  3 bytes per LED
DMAMEM byte displayMemory[12]; // 12 bytes per LED
WS2812Serial rgb(1, displayMemory, drawingMemory, PIN_RGB_TX, WS2812_RGB);
FlexCAN_T4<CAN2, RX_SIZE_16, TX_SIZE_16> can;

bool error = false;

void sendCallback(uint8_t id, uint8_t* buf, uint8_t len) {
    fc::parse_message(id, buf);
    uint8_t out_buf[HEADER_SIZE];
    uint8_t out_index = 0;
    uint8_t checksum = DataProtocol::get_checksum(buf, len);
    DataProtocol::build_header(id, checksum, out_buf, &out_index);
    Serial3.write(out_buf, out_index);
    Serial3.write(buf, len);
}

void receiveCallback(uint8_t id, uint8_t* buf, uint8_t len) {
    uint8_t out_buf[HEADER_SIZE];
    uint8_t out_index = 0;
    uint8_t checksum = DataProtocol::get_checksum(buf, len);
    DataProtocol::build_header(id, checksum, out_buf, &out_index);
    CAN_message_t can_msg;
    can_msg.id = id;
    can_msg.len = len;
    memcpy(can_msg.buf, buf, len);
    can.write(can_msg);
    Serial.write(out_buf, out_index);
    Serial.write(buf, len);
}

void initPins() {
    pinMode(PIN_RF_CS, OUTPUT);
    pinMode(PIN_BAT_READ, INPUT);
    pinMode(PIN_RF_RST, OUTPUT);
    pinMode(PIN_FLASH_CS, OUTPUT);
    pinMode(PIN_BUZZER, OUTPUT);
    pinMode(PIN_PYRO_ARM, OUTPUT);
    pinMode(PIN_PYRO_1, OUTPUT);
    pinMode(PIN_PYRO_2, OUTPUT);
    pinMode(PIN_PYRO_3, OUTPUT);
    pinMode(PIN_PYRO_4, OUTPUT);
    
    SPI.setMISO(PIN_MISO);
    SPI.setMOSI(PIN_MOSI);
    SPI.setSCK(PIN_SCK);
    SPI.begin();

    digitalWrite(PIN_RF_CS, HIGH);
    digitalWrite(PIN_FLASH_CS, HIGH);
    digitalWrite(PIN_PYRO_ARM, LOW);
    delay(100);
}

void fc::rx(fc::handshake_from_ground_station_to_flight_controller msg) {
    fc::return_handshake_from_flight_controller_to_ground_station response;
    uint8_t out_buf[response.get_size() + HEADER_SIZE];
    uint8_t index = 0;
    DataProtocol::build_buf(&response, out_buf, &index);
    delay(200);
    Serial.write(out_buf, index);
    delay(500);
}

void canIrq(const CAN_message_t &can_msg) {
    send_protocol.parse_CAN_message(can_msg);
}

void setup() {
    Serial.begin(BAUD);
    Serial3.begin(TELEMETRY_BAUD);
    initPins();
    can.begin();
    can.setBaudRate(1000000);
    rgb.begin();

    const uint8_t txBoxes = 8;
    const uint8_t rxBoxes = 56;
    can.setMaxMB(txBoxes + rxBoxes);
    for (int i = 0; i < rxBoxes; i++) {
        can.setMB((FLEXCAN_MAILBOX)i, RX, STD);
    }
    for (int i = rxBoxes; i < (txBoxes + rxBoxes); i++) {
        can.setMB((FLEXCAN_MAILBOX)i, TX, STD);
    }
    for (int i = 0; i < rxBoxes; i++) {
        can.setMBManualFilter((FLEXCAN_MAILBOX)i, 0x00, 0xF00); // Filter with (id & 0xF00) == 0x00
    }
    can.onReceive(canIrq);
    can.enableMBInterrupts();

    if (!error) {
        rgb.setPixel(0, WHITE);
        rgb.show();
    } else {
        rgb.setPixel(0, ORANGE);
        rgb.show();
    }
    DMAMEM static uint8_t tm_tx_buf[4086];
    DMAMEM static uint8_t tm_rx_buf[4086];
    Serial3.addMemoryForWrite(tm_tx_buf, sizeof(tm_tx_buf));
    Serial3.addMemoryForRead(tm_rx_buf, sizeof(tm_rx_buf));
}

void loop() {
    // while (Serial.available()) {
    //     Serial3.write(Serial.read());
    // }
    // while (Serial3.available()) {
    //     Serial.write(Serial3.read());
    // }
    // return;

    // static uint64_t last_spam = 0;
    // if (micros() - last_spam > 1000000 / 1500) {
    //     fc::ms_since_boot_from_flight_controller_to_ground_station msg;
    //     msg.set_ms_since_boot(millis());
    //     CAN_message_t spam_can;
    //     DataProtocol::build_CAN_message(&msg, &spam_can);
    //     can.write(spam_can);
    //     // Serial.println("spam");
    //     last_spam = micros();
    // }
    // return;

    static CAN_message_t can_msg;
    while (Serial.available() > 0) {
        noInterrupts();
        uint8_t byte = Serial.read();
        send_protocol.parse_byte(byte);
        interrupts();
    }
    if (can.read(can_msg)) {
        send_protocol.parse_CAN_message(can_msg);
    }

    while (Serial3.available() > 0) {
        uint8_t byte = Serial3.read();
        receive_protocol.parse_byte(byte);
    }
}