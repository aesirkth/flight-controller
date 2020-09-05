# Hardware description

*This page describes the version 1.0 of the Flight Controller*

<p align="middle">
    <img src="img/flight_controller_pcb_1.jpg" width="450">
    <img src="img/flight_controller_pcb_2.jpg" width="450">
</p>

>Top side and bottom side of the Flight Controller PCB

The schematic of the Flight Controller is here [doc/sources/flight_controller_v1.0.pdf](sources/flight_controller_v1.0.pdf)

Two separate battery inputs are available on the Flight Controller

| Name | Voltage | Role                                                                              | Connector | Connector type |
|------|---------|-----------------------------------------------------------------------------------|-----------|----------------|
| BAT1 | 7.2V    | Power the sensors and low power chips                                             | CON1      | XT30, male     |
| BAT2 | 11.1V   | Power the EEDs for the parachutes, the Engine actuators, and the high power chips | CON2      | XT60, male     |

The Flight Controller has two microcontrollers

| Name              | Device       | Role                                                                                    | Power |
|-------------------|--------------|-----------------------------------------------------------------------------------------|-------|
| Main controller   | Teensy 3.6   | Handle the flight data acquisition, parachute ejection, Engine Computer and radio links | BAT1  |
| Backup controller | Arduino Nano | Eject the parachutes in case the main controller fails                                  | BAT2  |

# Connectors

![connector_placement](diagrams/connector_placement.png)

