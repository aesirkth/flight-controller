
#include "hardware_test_nano.h"

#include <Arduino.h>
#include <unity.h>

#include "hardware_definition_nano.h"

void setup() {
  // Set I/O
  pinMode(PIN_PARA1, OUTPUT);
  pinMode(PIN_PARA2, OUTPUT);
  digitalWrite(PIN_PARA1, LOW);  // LOW means inactive parachute
  digitalWrite(PIN_PARA2, LOW);  // LOW means inactive parachute

  UNITY_BEGIN();

  RUN_TEST(test_buzzer);

  RUN_TEST(test_parachutes);

  UNITY_END();
}

void loop() {
}

/*
  Test the buzzer (LS2)

  Play short sounds
  The user must pay attention to the test outputs in 
  the serial console and confirm the sounds
*/
void test_buzzer() {
#ifdef SILENT_MODE
  TEST_IGNORE_MESSAGE("Silent mode: skipping buzzer test");
#else
  buzzerShortSound();
  TEST_MESSAGE("Testing the buzzer");
  TEST_MESSAGE("Do you hear it ?");
  delay(1000);
  for (uint8_t i = 0; i < 5; i++) {
    tone(PIN_BUZZER, BUZZER_FREQ, 100);
    delay(200);
  }
  TEST_PASS_MESSAGE("Test passed if you heard it");
#endif
}

/*
  Test the parachute outputs

  /!\ DO NOT CONNECT EEDs for this test /!\

  Activate each parachute for 1 second
  The user must pay attention to the test outputs in 
  the serial console and confirm correct parachute 
  outputs
*/
void test_parachutes() {
  delay(1000);
  buzzerShortSound();
  TEST_MESSAGE("Testing the parachute outputs");
  TEST_MESSAGE("Do you see them activate/deactivate ?");
  delay(1000);

  digitalWrite(PIN_PARA1, HIGH);
  delay(1000);
  digitalWrite(PIN_PARA2, HIGH);
  delay(1000);
  digitalWrite(PIN_PARA1, LOW);
  delay(1000);
  digitalWrite(PIN_PARA2, LOW);

  TEST_PASS_MESSAGE("Test passed if saw it");
}

/* Utils */

void buzzerShortSound() {
#ifndef SILENT_MODE
  tone(PIN_BUZZER, BUZZER_FREQ, 100);
#endif
}