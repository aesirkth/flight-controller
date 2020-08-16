# Data Protocol <!-- omit in toc -->

Here is a description of the data protocol between the Rocket and the Ground Station for the Mjollnir project

# Table of contents <!-- omit in toc -->

- [Overview](#overview)
- [Development plan](#development-plan)
  - [Static Fire](#static-fire)
  - [Launch](#launch)
- [Serial links](#serial-links)
- [CAN Bus](#can-bus)
- [Data protocol](#data-protocol)
  - [Telecommand](#telecommand)
    - [Communication sequence](#communication-sequence)
    - [Commands description](#commands-description)
      - [Engine Controller](#engine-controller)
      - [Flight Controller](#flight-controller)
  - [Telemetry](#telemetry)
    - [Communication sequence](#communication-sequence-1)
    - [Data description](#data-description)
      - [Engine Controller](#engine-controller-1)
      - [Flight Controller](#flight-controller-1)
      - [About time stamps](#about-time-stamps)
      - [About lost frames](#about-lost-frames)

# Overview

![buses](diagrams/data-buses.png)
>Overview of the data buses between the Ground Station and the Rocket<br>
The source file can be found in [doc/diagrams/data-buses.xml](diagrams/data-buses.xml)

The Gateway is connected to the Control computer through the USB connector of the Flight Controller<br>
The RFD900+ on the Ground Station side is connected to the Dashboard computer through an FTDI USB cable

The Flight Controller on the Ground Station 'Gateway' is a preliminary solution to have the Control computer talk to the Rocket's Flight Controller during the first static fire

# Development plan

The work on this data protocol is still preliminary. The development will be iterative and the first milestone is the static fire planned for the end of the summer 2020. The protocol will be refined later on to better allocate the telemetry sent back to the Ground Station.

## Static Fire

Drivers:

- Send commands to the Rocket and have the relevant ones forwarded to the Engine Computer
- Send back Telemetry to the Ground Station, mainly comprised of measurement samples from the Engine Computer
- No logic on the Flight Controller for the Telemetry packets, the packets are simply forwarded to the Ground Station

## Launch

Drivers:

- Maximize the amount of data downlinked from the Rocket, by optimizing how the data packets are processed by the Flight Controller and maybe also the Ground Station
- Be more resilient to loss of frames

# Serial links

All serial links share the same configuration. The baud rate is `57600`.

A frame on the serial links looks like this:

| Byte number | Description             |
| ----------- | ----------------------- |
| 0           | Frame separator: `0x0A` |
| 1           | Frame separator: `0x0D` |
| 2           | Frame ID                |
| 3           | Data byte 0             |
| 4           | Data byte 1             |
| [...]       | [...]                   |
| N+3         | Data byte N             |

The length of the data field is variable

# CAN Bus

> **Note:** the CAN bus between the Engine Computer and the Flight Controller can be extended to additional boards in future developments

CAN bus: CAN2.0 (FlexCAN) @1Mbit/s with termination 120$\Omega$ resistors on the Flight Controller side and on the Engine Computer side

Base frame format (11 identifier bits)

# Data protocol

The term `ID` is used below to denote `identifier field` of the CAN Bus and byte 2 (`Frame ID`) of a frame over the serial links

The `identifier field` is an 11 bits field but only the 8 lower bits are used to make the data on the CAN Bus as similar as possible to the data on the serial buses.

Each message on the Telecommand link and the Telemetry link has a unique ID

| ID              | Frame type | From              | To                |
|-----------------|------------|-------------------|-------------------|
| `0x00` - `0x0F` | TC         | Ground            | Engine Computer   |
| `0x10` - `0x7F` | TM         | Engine Computer   | Ground            |
| `0x80` - `0x8F` | TC         | Ground            | Flight Controller |
| `0x90` - `0xEF` | TM         | Flight Controller | Ground            |
| `0xF0` - `0xFF` | N/A        | N/A               | N/A               |

The `ID` values `0xF0` - `0xFF` are left unused and will be used if new devices are added to the on-board CAN Bus

## Telecommand

The Telecommand link is a low data rate radio link over LoRa at 433 MHz.

### Communication sequence

![commands-sequence-no-ec](diagrams/command-sequence-no-ec.png)
>Command sequence to the Rocket. Command addressed to the Flight Controller<br>
The source file can be found in [doc/diagrams/command-sequence.xml](diagrams/command-sequence.xml)

![commands-sequence-no-ec](diagrams/command-sequence-ec.png)
>Command sequence to the Rocket. Command addressed to the Engine Controller<br>
The source file can be found in [doc/diagrams/command-sequence.xml](diagrams/command-sequence.xml)

### Commands description

#### Engine Controller

<table>
<thead>
  <tr>
    <th>ID</th>
    <th>Description</th>
    <th>Data size</th>
    <th>Data</th>
    <th>Comment</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>0x00</td>
    <td>Time sync<br>Can be sent by FC</td>
    <td>-</td>
    <td>-</td>
    <td></td>
  </tr>
</tbody>
</table>

>**Note:** The LoRa link adds a sizeable delay in the transmission of the commands. This delay makes the "Time sync" frame (`0x00`) inaccurate. This frame is intended to be sent from the Ground Station for testing purposes and in the absence of GNSS receiver connected to the Flight Controller. When a GNSS receiver is connected to the Flight Controller, the Flight Controller sends a "Time sync" frame based on GNSS time to the Engine Computer over the CAN Bus

#### Flight Controller

Commands from the Ground Station to the Flight Controller

<table>
<thead>
  <tr>
    <th>ID</th>
    <th>Description</th>
    <th>Data size</th>
    <th>Data</th>
    <th>Comment</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>0x80</td>
    <td>Time sync</td>
    <td>-</td>
    <td>-</td>
    <td></td>
  </tr>
  <tr>
    <td>0x81</td>
    <td>Set sleeping mode</td>
    <td>1 Byte</td>
    <td>bit0: is_fc_sleeping</td>
    <td>Default state is 0</td>
  </tr>
  <tr>
    <td>0x82</td>
    <td>Enable radios emitters</td>
    <td>1 Byte</td>
    <td>bit0: is_fpv_en<br>bit1: N/C<br>bit2: is_tm_en</td>
    <td>Default state is 0</td>
  </tr>
  <tr>
    <td>0x83</td>
    <td>Enable parachute output<br>Used for testing only</td>
    <td>1 Byte</td>
    <td>bit0: is_armed<br>bit1: is_par1_en <br>bit2: is_par2_en</td>
    <td>Default state is 0 <br>Must set is_armed to 1 before<br>a parachute can be enabled</td>
  </tr>
</tbody>
</table>

Returned data

<table>
<thead>
  <tr>
    <th>ID</th>
    <th>Description</th>
    <th>Data size</th>
    <th>Data</th>
    <th>Comment</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>0x87</td>
    <td>Sleep mode<br>Returned after 0x81</td>
    <td>1 Byte</td>
    <td>bit0: is_fc_sleeping</td>
    <td></td>
  </tr>
  <tr>
    <td>0x88</td>
    <td>Radio emitters state<br>Returned after 0x82</td>
    <td>1 Byte</td>
    <td>bit0: is_fpv_en<br>bit1: N/C<br>bit2: is_tm_en</td>
    <td></td>
  </tr>
  <tr>
    <td>0x89</td>
    <td>Parachute outputs state<br>Returned after 0x83</td>
    <td>1 Byte</td>
    <td>bit0: is_armed<br>bit1: is_par1_en<br>bit2: is_par2_en</td>
    <td></td>
  </tr>
  <tr>
    <td rowspan="4">0x8A</td>
    <td rowspan="4">On-board battery voltage<br>Sent every X seconds</td>
    <td rowspan="4">4 Bytes</td>
    <td>byte0: bat1_msb</td>
    <td rowspan="2">uint16_t, in 0.01V</td>
  </tr>
  <tr>
    <td>byte1: bat1_lsb</td>
  </tr>
  <tr>
    <td>byte2: bat2_msb</td>
    <td rowspan="2">uint16_t, in 0.01V</td>
  </tr>
  <tr>
    <td>byte3: bat2_lsb</td>
  </tr>
  <tr>
    <td>0x8B</td>
    <td>GNSS data</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td>0x8C</td>
    <td>Software state</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
</tbody>
</table>

## Telemetry

The Telemetry link is a high data rate radio link over FHSS at 868 MHz. It is technicaly bi-directional but only the downlink capability is used.

### Communication sequence

![telemetry-sequence-no-ec](diagrams/telemetry-sequence-no-ec.png)
>Telemetry sequence to the Rocket. Telemetry from the Flight Controller<br>
The source file can be found in [doc/diagrams/telemetry-sequence.xml](diagrams/telemetry-sequence.xml)

![telemetry-sequence-no-ec](diagrams/telemetry-sequence-ec.png)
>Telemetry sequence to the Rocket. Telemetry from the Engine Controller<br>
The source file can be found in [doc/diagrams/telemetry-sequence.xml](diagrams/telemetry-sequence.xml)

### Data description

#### Engine Controller

<table>
<thead>
  <tr>
    <th>ID</th>
    <th>Description</th>
    <th>Data size</th>
    <th>Data</th>
    <th>Comment</th>
    <th>Rate</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>0x80</td>
    <td>Time since boot - millis</td>
    <td>4 Bytes</td>
    <td>ms_since_boot</td>
    <td>uint32_t, little-endian, in ms</td>
    <td></td>
  </tr>
  <tr>
    <td>0x81</td>
    <td>Time since boot - micros</td>
    <td>8 Bytes</td>
    <td>us_since_boot</td>
    <td>uint64_t, little-endian, in us</td>
    <td></td>
  </tr>
</tbody>
</table>

#### Flight Controller

<table>
<thead>
  <tr>
    <th>ID</th>
    <th>Description</th>
    <th>Data size</th>
    <th>Data</th>
    <th>Comment</th>
    <th>Rate</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>0x80</td>
    <td>Time since boot - millis</td>
    <td>4 Bytes</td>
    <td>ms_since_boot</td>
    <td>uint32_t, little-endian, in ms</td>
    <td></td>
  </tr>
  <tr>
    <td>0x81</td>
    <td>Time since boot - micros</td>
    <td>8 Bytes</td>
    <td>us_since_boot</td>
    <td>uint64_t, little-endian, in us</td>
    <td></td>
  </tr>
  <tr>
    <td>0x82</td>
    <td>GNSS time</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td></td>
    <td>Software state</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td></td>
    <td>Hardware state</td>
    <td>1 Byte<br></td>
    <td>bit0: is_parachute_armed<br>bit1: is_parachute1_en<br>bit2: is_parachute2_en<br>bit3: is_fpv_en<br>bit4: is_telemetry_en</td>
    <td>uint8_t</td>
    <td>1 Hz</td>
  </tr>
  <tr>
    <td rowspan="4"></td>
    <td rowspan="4">Static pressure</td>
    <td rowspan="4">16 Bytes</td>
    <td>pressure_1</td>
    <td>int32_t, little-endian, in 0.01 mbar</td>
    <td rowspan="4">1 Hz</td>
  </tr>
  <tr>
    <td>temperature_1</td>
    <td>int32_t, little-endian, in 0.01°C</td>
  </tr>
  <tr>
    <td>pressure_2</td>
    <td>int32_t, little-endian, in 0.01 mbar</td>
  </tr>
  <tr>
    <td>temperature_2</td>
    <td>int32_t, little-endian, in 0.01°C</td>
  </tr>
  <tr>
    <td rowspan="2"></td>
    <td rowspan="2">Static pressure - no temp</td>
    <td rowspan="2">8 bytes</td>
    <td>pressure_1</td>
    <td>int32_t, little-endian, in 0.01 mbar</td>
    <td rowspan="2">10 Hz</td>
  </tr>
  <tr>
    <td>pressure_2</td>
    <td>int32_t, little-endian, in 0.01 mbar</td>
  </tr>
  <tr>
    <td></td>
    <td>IMU</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>50 Hz</td>
  </tr>
  <tr>
    <td></td>
    <td>Magnetometer</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td rowspan="2"></td>
    <td rowspan="2">On-board battery voltage</td>
    <td rowspan="2">4 Bytes</td>
    <td>battery_1</td>
    <td>uint16_t, little-endian, in 0.01V</td>
    <td rowspan="2">1 Hz</td>
  </tr>
  <tr>
    <td>battery_2</td>
    <td>uint16_t, little-endian, in 0.01V</td>
  </tr>
  <tr>
    <td></td>
    <td>GNSS data</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td></td>
    <td>Air speed</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td></td>
    <td>Air temperature</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
</tbody>
</table>

#### About time stamps

The data acquisition process is the following:

1. Record the current time
1. Take a sample from each sensor
1. Send the acquisition time
1. Send all the samples in their corresponding frame
1. The time of acquisition is reconstructed on the Ground Station from the acquisition time

This allows to reduce the overhead on the Telemetry link by only sending one time stamp for all the data acquired in one loop.
The error in acquisition time is acceptable as the sampling loop is assumed to be short with respect to the measured phenomena.
All the sensors may not be sampled in every loop or may be sampled without sending the samples to the ground. The sensors that require low sampling rates can simply be sampled and sent every **X** loop

>**Note:** the exact time of acquisition for each sample can still be recorded and stored on the on-board memory

#### About lost frames

Some cases might exist where the time frame is not received on the Ground Station.

On Sigmundr launch (2019), the telemetry frames were ~100 bytes long. It was noticed that when a failure occured, the whole frame was lost instead of just small bits at the beginning or so. This has to do with how the RFD900+ modems handle the data transmission and should be further investigated.

Possible mitigations for early uses of this protocol can be:

- Time stamp all packets at reception time and compare this time with the time frame
- Assume no packet loss (realistic at close range, < 1km with line of sight)
- Group the frames in a big packet (wait and send all at once) like was done on Sigmundr and hope for a pass / fail for one hole sampling loop