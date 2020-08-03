# Flight Controller <!-- omit in toc -->

This is the embedded software on the Flight Controller for the project Mjollnir. The Flight Controller is on-board the rocket. The Flight Controller communicates with the ground through a radio link during all phases of the flight

The main functions of the Flight Controller are:

- Measure the flight parameters during the whole flight of the rocket
- Eject the parachutes at the right moment to ensure a smooth descent path of the rocket and a soft touchdown
- Receive telecommands from the ground station
- Forward commands and receive telemetry from the Engine Computer
- Send Telemetry (flight telemetry and engine telemetry) to the ground station

![flight_controller_test](doc/img/flight_controller_test.jpg)

# Table of content <!-- omit in toc -->

- [Description](#description)

# Description

Two separate power rails are available on the Flight Controller

| Name | Voltage | Role                                                                              | Connector | Connector type |
|------|---------|-----------------------------------------------------------------------------------|-----------|----------------|
| BAT1 | 7.2V    | Power the sensors and low power chips                                             | CON1      | XT30, male     |
| BAT2 | 11.1V   | Power the EEDs for the parachutes, the Engine actuators, and the high power chips | CON2      | XT60, male     |

The Flight Controller has two microcontrollers

| Name              | Device       | Role                                                                                    | Power |
|-------------------|--------------|-----------------------------------------------------------------------------------------|-------|
| Main controller   | Teensy 3.6   | Handle the flight data acquisition, parachute ejection, Engine Computer and radio links | BAT1  |
| Backup controller | Arduino Nano | Eject the parachutes in case the main controller fails                                  | BAT2  |

