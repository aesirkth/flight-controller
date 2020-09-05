# Flight Controller <!-- omit in toc -->

This is the embedded software on the Flight Controller for the project Mjollnir. The Flight Controller is on-board the rocket. The Flight Controller communicates with the ground through a radio link during all phases of the flight

The mission objectives for the Mjollnir project relevant to the electronics are the following:

**Primary objectives**

- **E.PO.1** Monitor the rocket while it is on the launchpad and give a “Go”/”No go” signal
- **E.PO.2** Control the rocket while it is on the launchpad
- **E.PO.3** Trigger the drogue parachute’s ejection after apogee
- **E.PO.4** Trigger the main parachute’s ejection before touchdown
- **E.PO.5** Support rocket recovery operations
- **E.PO.6** Record video footage from the rocket

**Secondary objectives**

- **E.SO.1** Send real-time telemetry from the rocket
- **E.SO.2** Receive & display real-time telemetry from the rocket at the Ground Station as long as the rocket is at a reasonable distance
- **E.SO.3** Send real-time video from the rocket
- **E.SO.4** Receive & display real-time video from the rocket at the Ground Station as long as the rocket is at a reasonable distance
- **E.SO.5** Acquire flight data with more sensors than those deemed “mission-critical”
- **E.SO.6** Store all flight data on-board the rocket for further analysis

All of them apply to some extent to the Flight Controller

![flight_controller_test](doc/img/flight_controller_test.jpg)

# Table of content <!-- omit in toc -->

- [Description](#description)
  - [Hardware](#hardware)
  - [Software](#software)
    - [Installation](#installation)
  - [Tests](#tests)
- [Data protocol](#data-protocol)
- [Folder structure](#folder-structure)

# Description

## Hardware

The Flight Controller is a single PCB with power management, sensors, radio communication, and driver for the actuators used during the flight.

It has the following features:

- Dual microcontroller (main + backup)
- Low power long range LoRa transceiver
- Telemetry output via serial link (x3)
- GNSS support via serial link (x3)
- Compatible with 10 dof breakout board with MS5611 pressure sensors and MPU9250 IMU (2x)
- Compatible with K type thermocouples (2x)
- Flash memory
- EEDs driver for parachute ejection, with ESD protection + visual and audible warning (2x)
- RGB leds to display the board status
- Serial link to FPV transmitter
- CAN Bus

A more detailed description of the hardware is given in [doc/hardware_description.md](doc/hardware_description.md)

## Software

This repository uses [PlatformIO](https://platformio.org/) as the development tool for the two microcontrollers on the Flight Controller.

### Installation

1. Install [PlatformIO Core](https://docs.platformio.org/en/latest/core/index.html) or [PlatformIO IDE](https://platformio.org/install/ide) on your computer
2. Clone this repository
3. [Linux] install [udev](https://docs.platformio.org/en/latest/faq.html?highlight=99#platformio-udev-rules) rules

## Tests

See [test/](test/)

# Data protocol

The protocol to communicate between the Ground Station and the Rocket is detailed in [doc/data-protocol](doc/data-protocol.md)

# Folder structure

```
.
├── doc/
│   ├── img/
│   ├── diagrams/
│   ├── sources
│   |   └── flight_controller_v1.0.pdf
│   ├── data-protocol.md
│   └── hardware_description.md
├── include/
│   ├── hardware_definition_nano.h
│   └── hardware_definition_teensy.h
├── src/                                    // Code folder
│   └── test_companion_teensy.cpp           // Use with hardware_test_teensy
├── test/                                   // Unit tests
│   ├── hardware_test_nano/
│   ├── hardware_test_teensy/
│   └── README.md                           // Documentation for the tests
├── env_nano.ini                            // Extra platformIO config
├── env_teensy.ini                          // Extra platformIO config
├── LICENSE
├── platformio.ini                          // PlatformIO config
└── README.md                               // This file
```