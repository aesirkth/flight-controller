# Hardware description <!-- omit in toc -->

*This page describes the version 1.0 of the Flight Controller*

<p align="middle">
    <img src="img/flight_controller_pcb_1.jpg" width="450">
    <img src="img/flight_controller_pcb_2.jpg" width="450">
</p>

>Top side and bottom side of the Flight Controller PCB

The schematic of the Flight Controller is here [doc/sources/flight_controller_v1.0.pdf](sources/flight_controller_v1.0.pdf)


# Table of contents <!-- omit in toc -->

- [Purpose](#purpose)
- [Microcontrollers](#microcontrollers)
- [Power](#power)
  - [Input](#input)
  - [Output](#output)
  - [Turn on the board](#turn-on-the-board)
  - [Power from USB](#power-from-usb)
- [Sensors](#sensors)
  - [On the board](#on-the-board)
    - [Air pressure](#air-pressure)
    - [Acceleration & angular velocity](#acceleration--angular-velocity)
  - [Off the board](#off-the-board)
    - [Differential air pressure sensor](#differential-air-pressure-sensor)
    - [Temperature sensors](#temperature-sensors)
- [Radio communication](#radio-communication)
- [GNSS receiver](#gnss-receiver)
- [Flash memory](#flash-memory)
- [Visual and audible signals](#visual-and-audible-signals)
  - [RGB leds](#rgb-leds)
  - [Buzzer](#buzzer)
- [Connectors](#connectors)
  - [Signal](#signal)
    - [Pin numbering](#pin-numbering)
    - [[J1] TM/GNSS](#j1-tmgnss)
    - [[J2] TM/GNSS](#j2-tmgnss)
    - [[J3] TM/GNSS](#j3-tmgnss)
    - [[J4] FPV](#j4-fpv)
    - [[J5] Air pressure sensor](#j5-air-pressure-sensor)
    - [[J6] Engine Computer](#j6-engine-computer)
    - [[J7] External temperature](#j7-external-temperature)
    - [[JP1] Liftoff 1](#jp1-liftoff-1)
    - [[JP2] Liftoff 2](#jp2-liftoff-2)
    - [[JP3] Master Switch](#jp3-master-switch)
  - [Power](#power-1)
    - [[CON1] Battery 1 input](#con1-battery-1-input)
    - [[CON2] Battery 2 input](#con2-battery-2-input)
    - [[CON3] Engine Output](#con3-engine-output)
    - [[CON4] Parachute drivers](#con4-parachute-drivers)
  - [Antenna](#antenna)
    - [[ANT] LoRa antenna](#ant-lora-antenna)


# Purpose

- Validate the overall design of the Flight Controller
- Support the first static fire at the end of the summer 2020
- Support the first tests of the parachute system
- Support the beginning of the code development for the future flight hardware


# Microcontrollers

The Flight Controller has two microcontrollers

| Name              | Device       | Role                                                                                    | Power |
| ----------------- | ------------ | --------------------------------------------------------------------------------------- | ----- |
| Main controller   | Teensy 3.6   | Handle the flight data acquisition, parachute ejection, Engine Computer and radio links | BAT1  |
| Backup controller | Arduino Nano | Eject the parachutes in case the main controller fails                                  | BAT2  |


# Power

## Input

Two separate battery inputs are available on the Flight Controller

| Name | Voltage | Role                                                                              | Connector | Connector type |
| ---- | ------- | --------------------------------------------------------------------------------- | --------- | -------------- |
| BAT1 | 7.2V    | Power the sensors and low power chips                                             | CON1      | XT30, male     |
| BAT2 | 11.1V   | Power the EEDs for the parachutes, the Engine actuators, and the high power chips | CON2      | XT60, male     |

## Output

| Voltage      | Role                | Connector | Connector type | Current rating |
| ------------ | ------------------- | --------- | -------------- | -------------- |
| Same as BAT2 | Power to the Engine | CON3      | XT30, female   | Up to 15A      |

## Turn on the board

Both batteries are required to use all the fonctions of the Flight Controller

The Flight Controller is ON when the signal `MS_SWITCH` is not tied to `GND` (internal pull-up).
When `MS_SWITCH` is (strongly) pulled down, all the power rails on the board are turned OFF.
The power output on `CON3` is also turned OFF.

`MS_SWITCH` is available on the following connectors :

- J6
- JP3

## Power from USB

Both microcontrollers have an USB input. Caution is required when using power battery power and the USB connection.

**Teensy 3.6**

The Teensy 3.6 board allows to physically isolate the `VIN` rail and the `VUSB` rail by cutting their respective pads apart.

Make sure to isolate `VIN` from `VUSB` on any Teensy used on the Flight Controller to avoid conflicts between the external supply and the usb supply.

<p align="middle">
    <img src="img/pinout_teensy36_front.png" width="450">
    <img src="img/pinout_teensy36_back.png" width="450" style="padding:50px 0">
</p>

**Arduino Nano**

The Nano board handles the power supply in a way that allows to use external power and USB power simultaneously. No modification is required.


# Sensors

## On the board

### Air pressure

The static air pressure inside the rocket is measured with 2x **MS5611** sensors. The pressure inside the rocket must be equilibrated with the pressure outside the rocket.

A measure of the altitude is derivated from the static pressure

The **MS5611** chips are connected to the SPI bus 0 (`SPI`) of the Teensy.

### Acceleration & angular velocity

The acceleration and angular velocity of the rocket is measured with 2x **MPU9250** sensors. A 3-axis magnetometer is also available on the **MPU9250**.

The measurements from the **MPU9250** are meant to help derive an altitude value and to get the rocket attitude. The performance of the engine can also be recontructed from the acceleration curve during the propulsive phase.

The **MPU9250** are connected to the SPI bus 0 (`SPI`) of the Teensy

## Off the board

### Differential air pressure sensor

Located in the nosecone. ABPDRRT005PG2A5. Used to derive the Mach number

Connected to the I²C bus 0 (`SDA0` & `SCL0`). 5V logic, with level shifter

### Temperature sensors

The board features 2x **MAX31855K** thermocouple-to-digital converters to read the temperature from type_K thermocouples.

The thermocouples will be placed outside the rocket to measure the total air temperature.

The value of the external temperature will be used to derive the air speed during the flight, along with the Mach number

The **MAX31855K** are connected to the SPI bus 0 (`SPI`) of the Teensy


# Radio communication

An **RFM96W** LoRa transceiver at 433 MHz is mounted on the PCB and must always be connected to a 50Ω antenna. It is used as a low power device to receive TC and send the rocket position at low datarates during the flight and after landing.

The **RFM96W** is connected to the SPI bus 1 (`SPI1`) of the Teensy

An **RFD900+** (868MHz) modem can be connected on the **TM/GNSS** connectors of the board

The **RFD900+** is connected on the serial bus corresponding to the number of the connector it is connected to (`Serial1` for J1, `Serial2` for J2, `Serial3` for J3)


# GNSS receiver

A **NEO-M9N** GNSS receiver is used to acquire the rocket position during flight and after landing

The **NEO-M9N** can be used with one of the Serial buses available or over I²C


# Flash memory

A **W25N01GV** flash memory chip (1 Gbit) is available on the Flight Controller to log the flight data

It is connected to the SPI bus 1 (`SPI1`) of the Teensy


# Visual and audible signals

## RGB leds

Two **SK6812** RGB leds are used to display the status of the GNSS signal and the state of the Teensy. The leds are wired in series and are controlled via pin `6` of the Teensy

## Buzzer

The Flight Controller features two CEM-1206S buzzers. One is drived by pin `2` of the Teensy, the other is drived by pin `10` of the Arduino Nano. They work at 2400 Hz.


# Connectors

<p align="middle">
    <img src="diagrams/connector_placement.png" width="600">
</p>

## Signal

### Pin numbering

On all JST-GH connectors, pin 1 is the pin with the small triangle marking on the housing. It is also the pin closest to the small dot on the PCB silkscreen.

On all JST-XH connectors, pin 1 is the pin with the small rectangle or triangle marking on the housing.

### [J1] TM/GNSS

JST-GH, 6 pins

Connect a telemetry modem (low power) or a GNSS receiver

| Pin number | 1   | 2   | 3   | 4    | 5    | 6   |
| ---------- | --- | --- | --- | ---- | ---- | --- |
| Function   | 5V1 | RX1 | TX1 | SCL0 | SDA0 | GND |

3.3V logic

### [J2] TM/GNSS

JST-GH, 6 pins

Connect a telemetry modem (high power, up to 1A) or a GNSS receiver<br>
The power on this pin can be turned ON (OFF) by setting pin `35` of the Teensy LOW (HIGH)

| Pin number | 1   | 2   | 3   | 4    | 5    | 6   |
| ---------- | --- | --- | --- | ---- | ---- | --- |
| Function   | 5V2 | RX2 | TX2 | SCL0 | SDA0 | GND |

3.3V logic

### [J3] TM/GNSS

JST-GH, 6 pins

Connect a telemetry modem (low power) or a GNSS receiver

| Pin number | 1   | 2   | 3   | 4    | 5    | 6   |
| ---------- | --- | --- | --- | ---- | ---- | --- |
| Function   | 5V1 | RX3 | TX3 | SCL0 | SDA0 | GND |

3.3V logic

### [J4] FPV

JST-GH, 3 pins

Connect an FPV module (camera + transmitter)<br>
The power on the pin can be turned ON (OFF) by setting pin `36` of the Teensy LOW (HIGH)

| Pin number | 1    | 2   | 3   |
| ---------- | ---- | --- | --- |
| Function   | BAT2 | TX4 | GND |

3.3V logic

### [J5] Air pressure sensor

JST-GH, 4 pins

Connect a differential pressure sensor

| Pin number | 1   | 2    | 3    | 4   |
| ---------- | --- | ---- | ---- | --- |
| Function   | 5V1 | SCL0 | SDA0 | GND |

5V logic

### [J6] Engine Computer

JST-GH, 8 pins

Connector to the Engine Computer<br>
Can provide 200 mA<br>
Also contains `MS_SWITCH` and `LIFTOFF_2` signals to the bottom of the rocket

| Pin number | 1   | 2   | 3     | 4     | 5         | 6   | 7         | 8   |
| ---------- | --- | --- | ----- | ----- | --------- | --- | --------- | --- |
| Function   | 5V1 | GND | CANH0 | CANL0 | MS_SWITCH | GND | LIFTOFF_2 | GND |

3.3V logic

### [J7] External temperature

JST-GH, 7 pins

Two type-K thermocouples and `LIFTOFF_1` signal

| Pin number | 1   | 2   | 3   | 4   | 5   | 6         | 7   |
| ---------- | --- | --- | --- | --- | --- | --------- | --- |
| Function   | NC  | T1- | T1+ | T2- | T2+ | LIFTOFF_1 | GND |

3.3V logic

### [JP1] Liftoff 1

2.54 mm male pin header

Easy access to the `LIFTOFF_1` signal

| Pin      | left      | right |
| -------- | --------- | ----- |
| Function | LIFTOFF_1 | GND   |

### [JP2] Liftoff 2

2.54 mm male pin header

Easy access to the `LIFTOFF_2` signal

| Pin      | left      | right |
| -------- | --------- | ----- |
| Function | LIFTOFF_2 | GND   |

### [JP3] Master Switch

2.54 mm male pin header

Easy access to the `MS_SWITCH` signal

| Pin      | left      | right |
| -------- | --------- | ----- |
| Function | MS_SWITCH | GND   |

## Power

### [CON1] Battery 1 input

XT-30, male

2S LiPo battery

### [CON2] Battery 2 input

XT-60, male

3S LiPo battery

### [CON3] Engine Output

XT-30, female

Power output to the Engine actuators<br>
From BAT2, max 15A

### [CON4] Parachute drivers

JST-XH, 4 pins

Outputs to the parachutes' EEDs<br>
Rated 12V/3A, can deliver 5A for short periods

| Pin number | 1   | 2           | 3   | 4           |
| ---------- | --- | ----------- | --- | ----------- |
| Function   | GND | PARACHUTE_1 | GND | PARACHUTE_1 |

## Antenna

### [ANT] LoRa antenna

50Ω SMA connector