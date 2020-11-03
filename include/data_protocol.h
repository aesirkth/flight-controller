#ifndef DATA_PROTOCOL_H
#define DATA_PROTOCOL_H

#include <stdint.h>
#include <stdio.h>

#define TRUE 	1
#define FALSE 	0

#define INIT_FRAME_1	0x0A
#define INIT_FRAME_2	0x0D

#define ID_EMPTY			(-1)
#define ID_TELE_MILLIS		0x90
#define ID_TELE_MICROS		0x91
#define ID_TELE_GNSS_TIME	0x92
#define ID_TELE_GNSS_DATA	0x93
#define ID_TELE_SW_STATE	0x94
#define ID_TELE_HW_STATE	0x95
#define ID_TELE_PRESS_TEMP	0x96
#define ID_TELE_PRESS_ONLY	0x97
#define ID_TELE_IMU			0x98
#define ID_TELE_MAGNET		0x99
#define ID_TELE_BATTERY		0x9A
#define ID_TELE_AIR_SPEED	0x9B
#define ID_TELE_AIR_TEMP	0X9C

#define SIZE_TELE_MILLIS		4
#define SIZE_TELE_MICROS		8
#define SIZE_TELE_GNSS_TIME		4
#define SIZE_TELE_GNSS_DATA		24
#define SIZE_TELE_SW_STATE		1	//TODO
#define SIZE_TELE_HW_STATE		1
#define SIZE_TELE_PRESS_TEMP	16
#define SIZE_TELE_PRESS_ONLY	8	//TODO
#define SIZE_TELE_IMU			1	//TODO
#define SIZE_TELE_MAGNET		1	//TODO
#define SIZE_TELE_BATTERY		4
#define SIZE_TELE_AIR_SPEED		1	//TODO
#define SIZE_TELE_AIR_TEMP		4

typedef struct 
{
	int32_t latitude;
	int32_t longitude;
	int32_t altitude;
	int16_t heading;
	int16_t speed;
	uint8_t fix_status;
	uint8_t n_satellites;
	uint16_t dop;
	uint16_t h_dop;
	uint16_t v_dop;
} gnss_data_t;

typedef enum parser_modes_t {START0, START1, TYPE, PAYLOAD};

class DataProtocol
{
	uint32_t ms_since_boot;		uint8_t new_ms_since_boot;
	uint64_t us_since_boot;		uint8_t new_us_since_boot;
	uint32_t gnss_time;			uint8_t new_gnss_time;
	gnss_data_t gnss_data;		uint8_t new_gnss_data;
	//software state 	
	uint8_t hw_state;			uint8_t new_hw_state;	
	int32_t pressure_1;			uint8_t new_press_temp;
	int32_t temperature_1;		//uint8_t new_press_only;
	int32_t pressure_2;
	int32_t temperature_2;
	//IMU
	//Magnetometer
	uint16_t voltage_battery_1;	uint8_t new_voltage;
	uint16_t voltage_battery_2;
	//Air speed
	int16_t ext_temp_1;			uint8_t new_ext_temp;
	int16_t ext_temp_2;

public:
	DataProtocol();
	~DataProtocol() {};
	
	void parseData(uint8_t data);
	uint8_t relayData(uint8_t next_byte, uint8_t * data_buffer, uint8_t * data_size);

	/*Decode specific payloads PRIVATE*/
	void setReceived_Millis(uint8_t pay[SIZE_TELE_MILLIS]);
	//void setReceived_Micros(uint8_t pay[SIZE_TELE_MICROS]);	TODO
	void setReceived_GnssTime(uint8_t pay[SIZE_TELE_GNSS_TIME]);
	void setReceived_GnssData(uint8_t pay[SIZE_TELE_GNSS_DATA]);
	//void setReceiced_SwState(uint8_t pay[SIZE_TELE_SW_STATE]);	TODO
	void setReceived_HwState(uint8_t pay[SIZE_TELE_HW_STATE]);
	void setReceived_PressTemp(uint8_t pay[SIZE_TELE_PRESS_TEMP]);
	//void setReceived_PressOnly(uint8_t pay[SIZE_TELE_PRESS_ONLY]);	TODO
	//void setReceived_Imu(uint8_t pay[SIZE_TELE_IMU]);	TODO
	//void setReceived_Magnet(uint8_t pay[SIZE_TELE_COMPASS]);	TODO
	void setReceived_Battery(uint8_t pay[SIZE_TELE_BATTERY]);
	//void setReceived_AirSpeed(uint8_t pay[SIZE_TELE_AIR_SPEED]);	TODO
	void setReceived_AirTemp(uint8_t pay[SIZE_TELE_AIR_TEMP]);

	/*Get methods*/
	uint32_t get_Millis();
	//uint64_t get_Micros(); TODO
	void get_GnssTime(uint8_t * hour, uint8_t * min, uint8_t * sec);
	gnss_data_t get_GnssData();
	//uint8_t get_SwState();
	uint8_t get_HwState();
	void get_PressTemp(int32_t * press1, int32_t * press2, int32_t * temp1, int32_t * temp2);
	//get_PressOnly
	//get_Imu
	//get_Magnet
	void get_Battery(uint16_t * volt1, uint16_t * volt2);
	//get_AirSpeed
	void get_AirTemp(int16_t * temp1, int16_t * temp2);

	/*Check if received data has been updated*/
	inline uint8_t checkNew_Millis() {return new_ms_since_boot;}
	//inline uint8_t checkNew_Micros() {return new_us_since_boot;}
	inline uint8_t checkNew_GnssTime() {return new_gnss_time;}
	inline uint8_t checkNew_GnssData() {return new_gnss_data;}
	//Software state
	inline uint8_t checkNew_HwState() {return new_hw_state;}
	inline uint8_t checkNew_PressTemp() {return new_press_temp;}
	//Press only
	//IMU
	//Magnetometer
	inline uint8_t checkNew_Battery() {return new_voltage;}
	//Air speed
	inline uint8_t checkNew_AirTemp() {return new_ext_temp;}

	/*Build methods. They are data independant of the rest of the class*/
	static void build_Millis(uint8_t * data, uint8_t * size_data, uint32_t ms);
	//static void build_Micros(uint8_t * data, uint8_t * size_data, uint32_t us);
	static void build_GnssTime(uint8_t * data, uint8_t * size_data, uint32_t g_time);
	static void build_GnssData(uint8_t * data, uint8_t * size_data, gnss_data_t g_data);
	//Software state
	static void build_HwState(uint8_t * data, uint8_t * size_data, uint8_t state);
	static void build_PressTemp(uint8_t * data, uint8_t * size_data, int32_t p1, int32_t t1, int32_t p2, int32_t t2);
	//Press only
	//IMU
	//Magnetometer
	static void build_Battery(uint8_t * data, uint8_t * size_data, uint16_t batt1, uint16_t batt2);
	//Air speed
	static void build_AirTemp(uint8_t * data, uint8_t * size_data, int16_t t1, int16_t t2);
};

#endif