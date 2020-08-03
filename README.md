# Flight Controller

This is the embedded software on the Flight Controller for the project Mjollnir. The Flight Controller is on-board the rocket. The Flight Controller communicates with the ground through a radio link during all phases of the flight

The main functions of the Flight Controller are:

- Measure the flight parameters during the whole flight of the rocket
- Eject the parachutes at the right moment to ensure a smooth descent path of the rocket and a soft touchdown
- Receive telecommands from the ground station
- Forward commands and receive telemetry from the Engine Computer
- Send Telemetry (flight telemetry and engine telemetry) to the ground station

![flight_controller_test](doc/img/flight_controller_test.jpg)