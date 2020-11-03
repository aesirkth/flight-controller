#include "../include/lora_protocol.h"

/************** class LoraGS ***************/

LoraGS::LoraGS()
{
	//time sync
	new_fc_power_mode = FALSE;
	new_fc_radio_mode = FALSE;
	new_fc_parachute_mode = FALSE;
	new_fc_voltage = FALSE;
}

void LoraGS::parseData_GS(uint8_t data[])
{
    static uint8_t payload[100];
	uint8_t index = 0;

	if (data[index++] == INIT_FRAME_1)
	{
		if (data[index++] == INIT_FRAME_2)
		{
			switch(data[index++])
			{
				case ID_LORA_FC_POWER:
				{
					payload[0] = data[index];
					setReceivedFC_PowerMode(payload);
					break;
				}
				case ID_LORA_FC_RADIO:
				{
					payload[0] = data[index];
					setReceivedFC_RadioMode(payload);
					break;
				}
				case ID_LORA_FC_PARACHUTE:
				{
					payload[0] = data[index];
					setReceivedFC_ParachuteMode(payload);
					break;
				}
				case ID_LORA_FC_BATTERY:
				{
					payload[0] = data[index++];
					payload[1] = data[index++];
					payload[2] = data[index++];
					payload[3] = data[index];
					setReceivedFC_Battery(payload);
					break;
				}
				case ID_LORA_FC_GNSS:
				{
					//TODO
					break;
				}
				case ID_LORA_FC_SW_STATE:
				{
					//TODO
					break;
				}
				case ID_LORA_FC_HW_STATE:
				{
					//TODO
					break;
				}
				default: {}
			}
		}
    }
}

/*Decode specific payloads PRIVATE*/
void LoraGS::setReceivedFC_PowerMode(uint8_t pay[])
{
	fc_power_mode = pay[0];
	new_fc_power_mode = TRUE;
}

void LoraGS::setReceivedFC_RadioMode(uint8_t pay[])
{
	fc_radio_mode = pay[0];
	new_fc_radio_mode = TRUE;
}

void LoraGS::setReceivedFC_ParachuteMode(uint8_t pay[])
{
	fc_parachute_mode = pay[0];
	new_fc_parachute_mode = TRUE;
}

void LoraGS::setReceivedFC_Battery(uint8_t pay[])
{
	fc_battery_1 = ((uint16_t)pay[0] << 8) | (uint16_t)pay[1];
	fc_battery_2 = ((uint16_t)pay[2] << 8) | (uint16_t)pay[3];
	new_fc_voltage = TRUE;
}
//GNSS
//SW state
//HW state

/*Get methods*/
uint8_t LoraGS::getFC_PowerMode()
{
	new_fc_power_mode = FALSE;
	return fc_power_mode;
}

uint8_t LoraGS::getFC_RadioMode()
{
	new_fc_radio_mode = FALSE;
	return fc_radio_mode;
}

uint8_t LoraGS::getFC_ParachuteMode()
{
	new_fc_parachute_mode = FALSE;
	return fc_parachute_mode;
}

void LoraGS::getFC_Battery(uint16_t * volt1, uint16_t * volt2)
{
	new_fc_voltage = FALSE;
	*volt1 = fc_battery_1;
	*volt2 = fc_battery_2;
}
//GNSS
//SW state
//HW state

/*Send methods. These do not use any variable from the class*/
//time sync
void LoraGS::buildGS_PowerMode(uint8_t * data, uint8_t * size_data, uint8_t power_mode)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_GS_POWER;
	data[3] = power_mode;
	*size_data = 4;
}
void LoraGS::buildGS_RadioMode(uint8_t * data, uint8_t * size_data, uint8_t radio_mode)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_GS_RADIO;
	data[3] = radio_mode;
	*size_data = 4;
}
void LoraGS::buildGS_ParachuteMode(uint8_t * data, uint8_t * size_data, uint8_t parachute_mode)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_GS_PARACHUTE;
	data[3] = parachute_mode;
	*size_data = 4;
}

/************** class LoraGS ***************/

/************** class LoraFC ***************/
LoraFC::LoraFC()
{
	//time sync
	new_gs_power_mode = FALSE;
	new_gs_radio_mode = FALSE;
	new_gs_parachute_mode = FALSE;
}

void LoraFC::parseData_FC(uint8_t data[])
{
	static uint8_t payload[100];
	uint8_t index = 0;

	if (data[index++] == INIT_FRAME_1)
	{
		if (data[index++] == INIT_FRAME_2)
		{
			switch(data[index++])
			{
				case ID_LORA_GS_TIME_SYNC:
				{
					//TODO
					break;
				}
				case ID_LORA_GS_POWER:
				{
					payload[0] = data[index];
					setReceivedGS_PowerMode(payload);
					break;
				}
				case ID_LORA_GS_RADIO:
				{
					payload[0] = data[index];
					setReceivedGS_RadioMode(payload);
					break;
				}
				case ID_LORA_GS_PARACHUTE:
				{
					payload[0] = data[index];
					setReceivedGS_ParachuteMode(payload);
					break;
				}
				default: {}
			}
		}
    }
}

/*Decode specific payloads PRIVATE*/
//time sync
void LoraFC::setReceivedGS_PowerMode(uint8_t pay[])
{
	gs_power_mode = pay[0];
	new_gs_power_mode = TRUE;
}

void LoraFC::setReceivedGS_RadioMode(uint8_t pay[])
{
	gs_radio_mode = pay[0];
	new_gs_radio_mode = TRUE;
}

void LoraFC::setReceivedGS_ParachuteMode(uint8_t pay[])
{
	gs_parachute_mode = pay[0];
	new_gs_parachute_mode = TRUE;
}

/*Get methods*/
//time sync
uint8_t LoraFC::getGS_PowerMode()
{
	new_gs_power_mode = FALSE;
	return gs_power_mode;
}

uint8_t LoraFC::getGS_RadioMode()
{
	new_gs_radio_mode = FALSE;
	return gs_radio_mode;
}

uint8_t LoraFC::getGS_ParachuteMode()
{
	new_gs_parachute_mode = FALSE;
	return gs_parachute_mode;
}

/*Send methods. These do not use any variable from the class*/
void LoraFC::buildFC_PowerMode(uint8_t * data, uint8_t * size_data, uint8_t power_mode)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_FC_POWER;
	data[3] = power_mode;
	*size_data = 4;
}
void LoraFC::buildFC_RadioMode(uint8_t * data, uint8_t * size_data, uint8_t radio_mode)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_FC_RADIO;
	data[3] = radio_mode;
	*size_data = 4;
}
void LoraFC::buildFC_ParachuteMode(uint8_t * data, uint8_t * size_data, uint8_t parachute_mode)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_FC_PARACHUTE;
	data[3] = parachute_mode;
	*size_data = 4;
}
void LoraFC::buildFC_Battery(uint8_t * data, uint8_t * size_data, uint16_t volt1, uint16_t volt2)
{
	data[0] = INIT_FRAME_1;
	data[1] = INIT_FRAME_2;
	data[2] = ID_LORA_FC_BATTERY;
	data[3] = (uint8_t)(volt1 >> 8);
	data[4] = (uint8_t)volt1;
	data[5] = (uint8_t)(volt2 >> 8);
	data[6] = (uint8_t)volt2;
	*size_data = 7;
}
/************** class LoraFC ***************/