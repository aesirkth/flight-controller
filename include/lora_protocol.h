#ifndef LORA_PROTOCOL_H
#define LORA_PROTOCOL_H

#include <stdint.h>

#define TRUE 	1
#define FALSE 	0

#define INIT_FRAME_1	0x0A
#define INIT_FRAME_2	0x0D

#define ID_EMPTY	(-1)

// GS to FC
#define ID_LORA_GS_TIME_SYNC	0x80	//TODO
#define ID_LORA_GS_POWER		0x81
#define ID_LORA_GS_RADIO		0x82
#define ID_LORA_GS_PARACHUTE	0x83

#define SIZE_LORA_GS_TIME_SYNC	1	//TODO
#define SIZE_LORA_GS_POWER		1
#define SIZE_LORA_GS_RADIO		1
#define SIZE_LORA_GS_PARACHUTE	1

// FC to GS
#define ID_LORA_FC_POWER		0x87
#define ID_LORA_FC_RADIO		0x88
#define ID_LORA_FC_PARACHUTE	0x89
#define ID_LORA_FC_BATTERY		0x8A		
#define ID_LORA_FC_GNSS			0x8B	//TODO
#define ID_LORA_FC_SW_STATE		0x8C	//TODO
#define ID_LORA_FC_HW_STATE		0x8D	//TODO

#define SIZE_LORA_FC_POWER		1
#define SIZE_LORA_FC_RADIO		1
#define SIZE_LORA_FC_PARACHUTE	1
#define SIZE_LORA_FC_BATTERY	4		
#define SIZE_LORA_FC_GNSS		1	//TODO
#define SIZE_LORA_FC_SW_STATE	1	//TODO
#define SIZE_LORA_FC_HW_STATE	1	//TODO

typedef enum parser_modes_t {START0, START1, TYPE, PAYLOAD};

// Build commands to FC and parse received data
class LoraGS
{
	uint8_t fc_power_mode;		uint8_t new_fc_power_mode;
	uint8_t fc_radio_mode;		uint8_t new_fc_radio_mode;
	uint8_t fc_parachute_mode;	uint8_t new_fc_parachute_mode;
	uint16_t fc_battery_1;		uint8_t new_fc_voltage;
	uint16_t fc_battery_2;
	//GNSS
	//SW state
	//HW state

public:
	LoraGS();
	~LoraGS() {};

	void parseData_GS(uint8_t data[]);

	/*Decode specific payloads PRIVATE*/
	void setReceivedFC_PowerMode(uint8_t pay[]);
	void setReceivedFC_RadioMode(uint8_t pay[]);
	void setReceivedFC_ParachuteMode(uint8_t pay[]);
	void setReceivedFC_Battery(uint8_t pay[]);
	//GNSS
	//SW state
	//HW state

	/*Get methods*/
	uint8_t getFC_PowerMode();
	uint8_t getFC_RadioMode();
	uint8_t getFC_ParachuteMode();
	void getFC_Battery(uint16_t * volt1, uint16_t * volt2);
	//GNSS
	//SW state
	//HW state

	/*Check if received data has been updated*/	
	inline uint8_t checkNewFC_PowerMode() {return new_fc_power_mode;}
	inline uint8_t checkNewFC_RadioMode() {return new_fc_radio_mode;}
	inline uint8_t checkNewFC_ParachuteMode() {return new_fc_parachute_mode;}
	inline uint8_t checkNewFC_Battery() {return new_fc_voltage;}
	//GNSS
	//SW state
	//HW state

	/*Send methods. These do not use any variable from the class*/
	//time sync
	void buildGS_PowerMode(uint8_t * data, uint8_t * size_data, uint8_t power_mode);
	void buildGS_RadioMode(uint8_t * data, uint8_t * size_data, uint8_t radio_mode);
	void buildGS_ParachuteMode(uint8_t * data, uint8_t * size_data, uint8_t parachute_mode);
};

class LoraFC
{
	//time sync
	uint8_t gs_power_mode;		uint8_t new_gs_power_mode;
	uint8_t gs_radio_mode;		uint8_t new_gs_radio_mode;
	uint8_t gs_parachute_mode;	uint8_t new_gs_parachute_mode;

public:
	LoraFC();
	~LoraFC() {};

	void parseData_FC(uint8_t data[]);

		/*Decode specific payloads PRIVATE*/
	//time sync
	void setReceivedGS_PowerMode(uint8_t pay[]);
	void setReceivedGS_RadioMode(uint8_t pay[]);
	void setReceivedGS_ParachuteMode(uint8_t pay[]);

	/*Get methods*/
	//time sync
	uint8_t getGS_PowerMode();
	uint8_t getGS_RadioMode();
	uint8_t getGS_ParachuteMode();

	/*Check if received data has been updated*/
	//time sync
	inline uint8_t checkNewGS_PowerMode() {return new_gs_power_mode;}
	inline uint8_t checkNewGS_RadioMode() {return new_gs_radio_mode;}
	inline uint8_t checkNewGS_ParachuteMode() {return new_gs_parachute_mode;}

	/*Send methods. These do not use any variable from the class*/
	void buildFC_PowerMode(uint8_t * data, uint8_t * size_data, uint8_t power_mode);
	void buildFC_RadioMode(uint8_t * data, uint8_t * size_data, uint8_t radio_mode);
	void buildFC_ParachuteMode(uint8_t * data, uint8_t * size_data, uint8_t parachute_mode);
	void buildFC_Battery(uint8_t * data, uint8_t * size_data, uint16_t volt1, uint16_t volt2);
	//GNSS
	//SW state
	//HW state
};

#endif