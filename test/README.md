# Tests <!-- omit in toc -->

This repository uses the platformio unit testing engine to test the software and the hardware.

# Table of content <!-- omit in toc -->

- [Hardware test](#hardware-test)
  - [Requirements](#requirements)
  - [Teensy](#teensy)
    - [Setup](#setup)
    - [What is tested ?](#what-is-tested-)
  - [Arduino nano](#arduino-nano)
    - [Setup](#setup-1)
    - [What is tested ?](#what-is-tested--1)
- [Software test](#software-test)

# Hardware test

The purpose of the hardware test is to make sure that the Flight Controller board performs as intended and that all the chips are 100% working.

## Requirements

- 2x Flight Controller boards (v1.0) with:
  - T:
    - 1x RFM96W LoRa transceiver
    - 1x 433 MHz SMA antenna
    - 1x Teensy 3.6 microcontroller with `5V` & `VUSB` isolated
    - 1x Arduino nano microcontroller (not used yet)
    - Two MS5611 / MPU9250 breakout boards
  - S:
    - 1x Teensy 3.6 microcontroller
- 1x JST-GH / JST-GH 8 pins cable (with wire 5 disconnected)
- 1x JST-GH / JST-GH 6 pins cable (with wires 2&3 inverted)
- 1x micro USB to USB cable
- 1x mini USB to USB cable
- 1x 2S LiPo battery with an XT-30 connector
- 1x 3S LiPo battery with an XT-60 connector

**ALWAYS connect an antenna on all boards that have a Lora chip (U3)**

## Teensy

Sources :

`test/hardware_test_teensy/` -> used to test all the I/O<br>
`src/test_companion_teensy.cpp` -> used to help test the data links, works on a secondary board

### Setup

Let's call the board to test 'T' and the secondary board 'S'

- Connect 'S' to your computer with the micro USB cable
- Upload the companion code on 'S' using the platformio shell

```sh
platformio run -t upload -e teensy_test
```

- Disconnect the micro USB cable from 'S'
- Connect 'S' and 'T' (only one at a time):
  -  with the JST-GH 8 pins cable on J6 [to test the CAN bus]
  -  with the JST-GH 6 pins cable on J1, J2, or J3 [to test the Serial ports]
- Connect the 2S LiPo to 'T'
- Connect the 3S LiPo to 'T'
- Connect 'T' to your computer with the micro USB cable
- Upload the test code on 'T' using the platformio shell

```sh
platformio test -e teensy_test -f hardware_test_teensy
# or
platformio test -e teensy_test_silent -f hardware_test_teensy # no buzzer sound
```

- Look at the output in the terminal

### What is tested ?

Currently:

- MS5611
- RFM96W
- CAN Bus
- Serial ports
- Buzzer
- RGB Leds
- Parachute outputs
- Mosfet for J2 power line (Telemetry modem)
- Mosfet for J4 power line (FPV)

Missing:

- MPU9250
- NEO M9N
- I²C
- Flash memory
- Interrupts for liftoff detection
- Temperature sensors

## Arduino nano

Sources :

`test/hardware_test_nano/` -> used to test all the I/O<br>

### Setup

Only one board ('T') is needed

- Connect the 2S LiPo to 'T'
- Connect the 3S LiPo to 'T'
- Connect 'T' to your computer with the mini USB cable
- Upload the test code on 'T' using the platformio shell

```sh
platformio test -e nano_test -f hardware_test_nano
```

- Look at the output in the terminal

### What is tested ?

- Buzzer
- Parachute outputs

# Software test

*TODO: make the embedded software compatible with unit testing and write unit tests for it*