# Tests <!-- omit in toc -->

This repository uses the platformio unit testing engine to test the software and the hardware.

# Table of content <!-- omit in toc -->

- [Hardware test](#hardware-test)
  - [Requirements](#requirements)
  - [Teensy](#teensy)
    - [Setup](#setup)
    - [What is tested ?](#what-is-tested-)
  - [Arduino nano](#arduino-nano)
- [Software test](#software-test)

# Hardware test

The purpose of the hardware test is to make sure that the Flight Controller board performs as intended and that all the chips are 100% working.

Sources :

`test/hardware_test_teensy.cpp` -> used to test all the I/O<br>
`src/test_companion_teensy.cpp` -> used to help test the data links, works on a secondary board

## Requirements

- 2x Flight Controller boards (v1.0) with: 
  - 1x RFM96W LoRa transceivers each
  - 1x 433 MHz SMA antennas each
  - 1x Teensy 3.6 microcontrollers each
  - 1x Arduino nano microcontroller each (not used yet)
  - Two MS5611 / MPU9250 breakout boards on one of them
- 1x JST-GH / JST-GH 8 pins cable (with wire 5 disconnected)
- 1x micro USB to USB cable
- 1x 2S LiPo battery with an XT-30 connector
- 1x 3S LiPo battery with an XT-60 connector

## Teensy

### Setup

Let's call the board to test 'T' and the secondary board 'S'. The MS5611 / MPU9250 breakout must be on 'T'

- Connect 'S' to your computer with the USB cable
- Upload the companion code on 'S' using the platformio shell

```shell
platformio run -t upload -e teensy_test
```

- Disconnect 'S'
- Connect 'S' and 'T' with the JST-GH cable
- Connect the 2S LiPo to 'T'
- Connect the 3S LiPo to 'T'
- Connect 'T' to your computer with the USB cable
- Upload the test code on 'T' using the platformio shell

```shell
platformio test -e teensy_test
```

- Look at the output in the terminal

### What is tested ?

Currently:

- Buzzer
- RGB Leds
- Parachute outputs
- MS5611
- RFM96W
- CAN Bus
- Mosfet for J2 power line (Telemetry modem)
- Mosfet for J4 power line (FPV)

Missing:

- MPU9250
- NEO M9N
- Serial ports
- I²C
- Flash memory
- Interrupts for liftoff detection
- Temperature sensors

## Arduino nano

*TODO: simple tests for the buzzer and the parachute outputs*

# Software test

*TODO: make the embedded software compatible with unit testing and write unit tests for it*