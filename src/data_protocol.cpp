#include "../include/data_protocol.h"

DataProtocol::DataProtocol()
{
	new_ms_since_boot = FALSE;
	new_us_since_boot = FALSE;
	new_gnss_time = FALSE;
	new_gnss_data = FALSE;
	//
	new_hw_state = FALSE;
	new_press_temp = FALSE;
	//
	//
	//
	new_voltage = FALSE;
	//
	new_ext_temp = FALSE;
}

//
void DataProtocol::parseData(uint8_t data)
{
	static parser_modes_t parser_state = START0;
    static int16_t data_type = ID_EMPTY;
    static uint8_t parse_count = 0;
    static uint8_t size_pay = 0;
    static uint8_t payload[100];

    switch(parser_state)
    {
        case START0:
        {
            if (data == 0x0A) parser_state = START1;
            break;
        }
        case START1:
        {
            if (data == 0x0D) parser_state = TYPE;
            else parser_state = START0;
            break;
        }
        case TYPE:
        {
        	parser_state = PAYLOAD;
        	size_pay = 0;
        	
            switch(data) // Set the ID and SIZE of the payload to be parsed
            {
                case ID_TELE_MILLIS:
                {
                    data_type = ID_TELE_MILLIS;
                    parse_count = SIZE_TELE_MILLIS;
                    break;
                }
                case ID_TELE_MICROS:
                {
                    data_type = ID_TELE_MICROS;
                    parse_count = SIZE_TELE_MICROS;
                    break;
                }
                case ID_TELE_GNSS_TIME:
                {
                    data_type = ID_TELE_GNSS_TIME;
                    parse_count = SIZE_TELE_GNSS_TIME;
                    break;
                }
                case ID_TELE_GNSS_DATA:
                {
                    data_type = ID_TELE_GNSS_DATA;
                    parse_count = SIZE_TELE_GNSS_DATA;
                    break;
                }
                case ID_TELE_SW_STATE:
                {
                    data_type = ID_TELE_SW_STATE;
                    parse_count = SIZE_TELE_SW_STATE;
                    break;
                }
                case ID_TELE_HW_STATE:
                {
                    data_type = ID_TELE_HW_STATE;
                    parse_count = SIZE_TELE_HW_STATE;
                    break;
                }
                case ID_TELE_PRESS_TEMP:
                {
                    data_type = ID_TELE_PRESS_TEMP;
                    parse_count = SIZE_TELE_PRESS_TEMP;
                    break;
                }
                case ID_TELE_PRESS_ONLY:
                {
                    data_type = ID_TELE_PRESS_ONLY;
                    parse_count = SIZE_TELE_PRESS_ONLY;
                    break;
                }
                case ID_TELE_IMU:
                {
                    data_type = ID_TELE_IMU;
                    parse_count = SIZE_TELE_IMU;
                    break;
                }
                case ID_TELE_MAGNET:
                {
                    data_type = ID_TELE_MAGNET;
                    parse_count = SIZE_TELE_MAGNET;
                    break;
                }
                case ID_TELE_BATTERY:
                {
                    data_type = ID_TELE_BATTERY;
                    parse_count = SIZE_TELE_BATTERY;
                    break;
                }
                case ID_TELE_AIR_SPEED:
                {
                    data_type = ID_TELE_AIR_SPEED;
                    parse_count = SIZE_TELE_AIR_SPEED;
                    break;
                }
                case ID_TELE_AIR_TEMP:
                {
                    data_type = ID_TELE_AIR_TEMP;
                    parse_count = SIZE_TELE_AIR_TEMP;
                    break;
                }
                default:
                {
                	data_type = ID_EMPTY;
                	parse_count = 0;

                    parser_state = START0;
                }
            }
            break;
        }
        case PAYLOAD:
        {
            if (size_pay < parse_count) // Fill payload with new data until size_apy reachs parse_count
            {
                payload[size_pay] = data;
                size_pay++;
            }
            if (size_pay == parse_count)
            {
            	switch(data_type) // Update and set new value for the variables corresponding to ID
	            {
	                case ID_TELE_MILLIS:
	                {
	                	setReceived_Millis(payload);
	                    break;
	                }
	                case ID_TELE_MICROS:
	                {
	                	//setReceived_Micros(payload);
	                    break;
	                }
	                case ID_TELE_GNSS_TIME:
	                {
	                	setReceived_GnssTime(payload);
	                    break;
	                }
	                case ID_TELE_GNSS_DATA:
	                {
	                	setReceived_GnssData(payload);
	                    break;
	                }
	                case ID_TELE_SW_STATE:
	                {
	                	//setReceived_SwState(payload);
	                    break;
	                }
	                case ID_TELE_HW_STATE:
	                {
	                	setReceived_HwState(payload);
	                    break;
	                }
	                case ID_TELE_PRESS_TEMP:
	                {
	                	setReceived_PressTemp(payload);
	                    break;
	                }
	                case ID_TELE_PRESS_ONLY:
	                {
	                	//setReceived_PressOnly(payload);
	                    break;
	                }
	                case ID_TELE_IMU:
	                {
	                	//setReceived_Imu(payload);
	                    break;
	                }
	                case ID_TELE_MAGNET:
	                {
	                	//setReceived_Magnet(payload);
	                    break;
	                }
	                case ID_TELE_BATTERY:
	                {
	                	setReceived_Battery(payload);
	                    break;
	                }
	                case ID_TELE_AIR_SPEED:
	                {
	                	//setReceived_AirSpeed(payload);
	                    break;
	                }
	                case ID_TELE_AIR_TEMP:
	                {
	                	setReceived_AirTemp(payload);
	                    break;
	                }
	                default: {}
	            }

                parser_state = START0;
            }
            break;
        }
        default: {}
    }
}
//

//
uint8_t DataProtocol::relayData(uint8_t next_byte, uint8_t * data_buffer, uint8_t * data_size)
{
	static parser_modes_t parser_state = START0;
    static int16_t data_type = ID_EMPTY;
    static uint8_t parse_count = 0;
    static uint8_t size_pay = 0;
    uint8_t ret_val = 0;
    static uint8_t size_of_buffer = 0;

	switch(parser_state)
	{
		case START0:
		{
			size_of_buffer = 0;
			if (next_byte == 0x0A) parser_state = START1;
			break;
		}
		case START1:
		{
			if (next_byte == 0x0D) parser_state = TYPE;
			else parser_state = START0;
			break;
		}
		case TYPE:
        {
        	parser_state = PAYLOAD;
        	size_pay = 0;
        	
            switch(next_byte) // Set the ID and SIZE of the payload to be parsed
            {
                case ID_TELE_MILLIS:
                {
                    data_type = ID_TELE_MILLIS;
                    parse_count = SIZE_TELE_MILLIS;
                    break;
                }
                case ID_TELE_MICROS:
                {
                    data_type = ID_TELE_MICROS;
                    parse_count = SIZE_TELE_MICROS;
                    break;
                }
                case ID_TELE_GNSS_TIME:
                {
                    data_type = ID_TELE_GNSS_TIME;
                    parse_count = SIZE_TELE_GNSS_TIME;
                    break;
                }
                case ID_TELE_GNSS_DATA:
                {
                    data_type = ID_TELE_GNSS_DATA;
                    parse_count = SIZE_TELE_GNSS_DATA;
                    break;
                }
                case ID_TELE_SW_STATE:
                {
                    data_type = ID_TELE_SW_STATE;
                    parse_count = SIZE_TELE_SW_STATE;
                    break;
                }
                case ID_TELE_HW_STATE:
                {
                    data_type = ID_TELE_HW_STATE;
                    parse_count = SIZE_TELE_HW_STATE;
                    break;
                }
                case ID_TELE_PRESS_TEMP:
                {
                    data_type = ID_TELE_PRESS_TEMP;
                    parse_count = SIZE_TELE_PRESS_TEMP;
                    break;
                }
                case ID_TELE_PRESS_ONLY:
                {
                    data_type = ID_TELE_PRESS_ONLY;
                    parse_count = SIZE_TELE_PRESS_ONLY;
                    break;
                }
                case ID_TELE_IMU:
                {
                    data_type = ID_TELE_IMU;
                    parse_count = SIZE_TELE_IMU;
                    break;
                }
                case ID_TELE_MAGNET:
                {
                    data_type = ID_TELE_MAGNET;
                    parse_count = SIZE_TELE_MAGNET;
                    break;
                }
                case ID_TELE_BATTERY:
                {
                    data_type = ID_TELE_BATTERY;
                    parse_count = SIZE_TELE_BATTERY;
                    break;
                }
                case ID_TELE_AIR_SPEED:
                {
                    data_type = ID_TELE_AIR_SPEED;
                    parse_count = SIZE_TELE_AIR_SPEED;
                    break;
                }
                case ID_TELE_AIR_TEMP:
                {
                    data_type = ID_TELE_AIR_TEMP;
                    parse_count = SIZE_TELE_AIR_TEMP;
                    break;
                }
                default:
                {
                	data_type = ID_EMPTY;
                	parse_count = 0;

                    parser_state = START0;
                }
            }
            break;
        }
		case PAYLOAD:
		{
			if (size_pay < parse_count) // Fill payload with new data until size_apy reachs parse_count
            {
                size_pay++;
            }
            if (size_pay == parse_count)
            {
            	ret_val = 1;
            	parser_state = START0;
            }
			break;
		}
		default: {}
	}

	data_buffer[size_of_buffer] = next_byte;
	size_of_buffer++;
	*data_size = size_of_buffer;

	return ret_val;
}
//

//
void DataProtocol::setReceived_Millis(uint8_t pay[SIZE_TELE_MILLIS])
{
	ms_since_boot = ((uint32_t)pay[0] << 24) | ((uint32_t)pay[1] << 16) |
                    ((uint32_t)pay[2] << 8) | (uint32_t)pay[3];
    new_ms_since_boot = TRUE;
}
//

/*
	void DataProtocol::setReceived_Micros(uint8_t pay[SIZE_TELE_MICROS])
	{
	}
*/

//
void DataProtocol::setReceived_GnssTime(uint8_t pay[SIZE_TELE_GNSS_TIME])
{
	gnss_time = ((uint32_t)pay[0] << 24) | ((uint32_t)pay[1] << 16) |
                ((uint32_t)pay[2] << 8) | (uint32_t)pay[3];
    new_gnss_time = TRUE;
}
//

//
void DataProtocol::setReceived_GnssData(uint8_t pay[SIZE_TELE_GNSS_DATA])
{
	uint8_t i = 0;
    double temp_lat;
    double temp_lon;
    uint8_t * p_temp_lat = (uint8_t*)(&temp_lat);
    uint8_t * p_temp_lon = (uint8_t*)(&temp_lon);

    *(p_temp_lat) = pay[i++];
    *(p_temp_lat+1) = pay[i++];
    *(p_temp_lat+2) = pay[i++];
    *(p_temp_lat+3) = pay[i++];
    *(p_temp_lat+4) = pay[i++];
    *(p_temp_lat+5) = pay[i++];
    *(p_temp_lat+6) = pay[i++];
    *(p_temp_lat+7) = pay[i++];

    *(p_temp_lon) = pay[i++];
    *(p_temp_lon+1) = pay[i++];
    *(p_temp_lon+2) = pay[i++];
    *(p_temp_lon+3) = pay[i++];
    *(p_temp_lon+4) = pay[i++];
    *(p_temp_lon+5) = pay[i++];
    *(p_temp_lon+6) = pay[i++];
    *(p_temp_lon+7) = pay[i++];

    gnss_data.latitude = temp_lat;
    gnss_data.longitude = temp_lon;
    /*
	gnss_data.latitude = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
                    	 ((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
	gnss_data.longitude = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
                    	  ((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
    */
	gnss_data.altitude = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
                    	 ((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
	gnss_data.heading = ((int16_t)pay[i++] << 8) | (int16_t)pay[i++];
	gnss_data.speed = ((int16_t)pay[i++] << 8) | (int16_t)pay[i++];
	gnss_data.fix_status = pay[i++];
	gnss_data.n_satellites = pay[i++];
	gnss_data.dop = ((uint16_t)pay[i++] << 8) | (uint16_t)pay[i++];
	gnss_data.h_dop = ((uint16_t)pay[i++] << 8) | (uint16_t)pay[i++];
	gnss_data.v_dop = ((uint16_t)pay[i++] << 8) | (uint16_t)pay[i++];
    new_gnss_data = TRUE;
}
//

/*
	void DataProtocol::setReceived_SwState(uint8_t pay[SIZE_TELE_SW_STATE])
	{
	}
*/

//
void DataProtocol::setReceived_HwState(uint8_t pay[SIZE_TELE_HW_STATE])
{
	hw_state = pay[0];
    new_hw_state = TRUE;
}
//

//
void DataProtocol::setReceived_PressTemp(uint8_t pay[SIZE_TELE_PRESS_TEMP])
{
	uint8_t i = 0;
	pressure_1 = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
           		 ((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
	temperature_1 = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
           		 	((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
 	pressure_2 = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
           		 ((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
	temperature_2 = ((int32_t)pay[i++] << 24) | ((int32_t)pay[i++] << 16) |
           		 	((int32_t)pay[i++] << 8) | (int32_t)pay[i++];
 	new_press_temp = TRUE;
}
//

/*
	void DataProtocol::setReceived_PressOnly(uint8_t pay[SIZE_TELE_PRESS_ONLY])
	{
	}
*/

/*
	void DataProtocol::setReceived_Imu(uint8_t pay[SIZE_TELE_IMU])
	{
	}
*/

/*
	void DataProtocol::setReceived_Magnet(uint8_t pay[SIZE_TELE_COMPASS])
	{
	}
*/

//
void DataProtocol::setReceived_Battery(uint8_t pay[SIZE_TELE_BATTERY])
{
	voltage_battery_1 = ((uint16_t)pay[0] << 8) | (uint16_t)pay[1];
	voltage_battery_2 = ((uint16_t)pay[2] << 8) | (uint16_t)pay[3];
	new_voltage = TRUE;
}
//

/*
	void DataProtocol::setReceived_AirSpeed(uint8_t pay[SIZE_TELE_AIR_SPEED])
	{
	}
*/

//
void DataProtocol::setReceived_AirTemp(uint8_t pay[SIZE_TELE_AIR_TEMP])
{
	ext_temp_1 = ((int16_t)pay[0] << 8) | (int16_t)pay[1];
	ext_temp_2 = ((int16_t)pay[2] << 8) | (int16_t)pay[3];
	new_ext_temp = TRUE;
}
//

//
uint32_t DataProtocol::get_Millis()
{
	new_ms_since_boot = FALSE;
	return ms_since_boot;
}
//

/*
	uint64_y DataProtocol::get_Micros()
	{
	}
*/

//
void DataProtocol::get_GnssTime(uint8_t * hour, uint8_t * min, uint8_t * sec)
{
	new_gnss_time = FALSE;
	*hour = (uint8_t)(gnss_time/1000000);
	*min = (uint8_t)((gnss_time%1000000)/10000);
	*sec = (uint8_t)((gnss_time%10000)/100);
}
//

//
gnss_data_t DataProtocol::get_GnssData()
{
	new_gnss_data = FALSE;
	return gnss_data;
}
//

/*
	uint8_t DataProtocol::get_SwState()
	{
	}
*/

//
uint8_t DataProtocol::get_HwState()
{
	new_hw_state = FALSE;
	return hw_state;
}
//

//
void DataProtocol::get_PressTemp(int32_t * press1, int32_t * temp1, int32_t * press2, int32_t * temp2)
{
	new_press_temp = FALSE;
	*press1 = pressure_1;
	*press2 = pressure_2;
	*temp1 = temperature_1;
	*temp2 = temperature_2;
}
//

/*
	//get_PressOnly
	//get_Imu
	//get_Magnet
*/

//
void DataProtocol::get_Battery(uint16_t * volt1, uint16_t * volt2)
{
	new_voltage = FALSE;
	*volt1 = voltage_battery_1;
	*volt2 = voltage_battery_2;
}
//

/*
	//get_AirSpeed
*/

//
void DataProtocol::get_AirTemp(int16_t * temp1, int16_t * temp2)
{
	new_ext_temp = FALSE;
	*temp1 = ext_temp_1;
	*temp2 = ext_temp_2;
}
//

//
void DataProtocol::build_Millis(uint8_t * data, uint8_t * size_data, uint32_t ms)
{
    data[0] = INIT_FRAME_1;
    data[1] = INIT_FRAME_2;
    data[2] = ID_TELE_MILLIS;
    data[3] = (uint8_t)(ms >> 24);
    data[4] = (uint8_t)(ms >> 16);
    data[5] = (uint8_t)(ms >> 8);
    data[6] = (uint8_t)ms;
    *size_data = 3 + SIZE_TELE_MILLIS;
}
//

/*
    //build_Micros
*/

//
void DataProtocol::build_GnssTime(uint8_t * data, uint8_t * size_data, uint32_t g_time)
{
    data[0] = INIT_FRAME_1;
    data[1] = INIT_FRAME_2;
    data[2] = ID_TELE_GNSS_TIME;
    data[3] = (uint8_t)(g_time >> 24);
    data[4] = (uint8_t)(g_time >> 16);
    data[5] = (uint8_t)(g_time >> 8);
    data[6] = (uint8_t)g_time;
    *size_data = 3 + SIZE_TELE_GNSS_TIME;
}
//

//
void DataProtocol::build_GnssData(uint8_t * data, uint8_t * size_data, gnss_data_t g_data)
{
    uint8_t i = 0;
    uint8_t * p_temp_lat = (uint8_t*)(&g_data.latitude);
    uint8_t * p_temp_lon = (uint8_t*)(&g_data.longitude);
  
    data[i++] = INIT_FRAME_1;
    data[i++] = INIT_FRAME_2;
    data[i++] = ID_TELE_GNSS_DATA;
    data[i++] = *(p_temp_lat);
    data[i++] = *(p_temp_lat+1);
    data[i++] = *(p_temp_lat+2);
    data[i++] = *(p_temp_lat+3);
    data[i++] = *(p_temp_lat)+4;
    data[i++] = *(p_temp_lat+5);
    data[i++] = *(p_temp_lat+6);
    data[i++] = *(p_temp_lat+7);
    data[i++] = *(p_temp_lon);
    data[i++] = *(p_temp_lon+1);
    data[i++] = *(p_temp_lon+2);
    data[i++] = *(p_temp_lon+3);
    data[i++] = *(p_temp_lon)+4;
    data[i++] = *(p_temp_lon+5);
    data[i++] = *(p_temp_lon+6);
    data[i++] = *(p_temp_lon+7);
    data[i++] = (uint8_t)(g_data.altitude >> 24);
    data[i++] = (uint8_t)(g_data.altitude >> 16);
    data[i++] = (uint8_t)(g_data.altitude >> 8);
    data[i++] = (uint8_t)g_data.altitude;
    data[i++] = (uint8_t)(g_data.heading >> 8);
    data[i++] = (uint8_t)g_data.heading;
    data[i++] = (uint8_t)(g_data.speed >> 8);
    data[i++] = (uint8_t)g_data.speed;
    data[i++] = (uint8_t)g_data.fix_status;
    data[i++] = (uint8_t)g_data.n_satellites;
    data[i++] = (uint8_t)(g_data.dop >> 8);
    data[i++] = (uint8_t)g_data.dop;
    data[i++] = (uint8_t)(g_data.h_dop >> 8);
    data[i++] = (uint8_t)g_data.h_dop;
    data[i++] = (uint8_t)(g_data.v_dop >> 8);
    data[i++] = (uint8_t)g_data.v_dop;
    *size_data = 3 + SIZE_TELE_GNSS_DATA;
}
//

/*
    //Software state
*/

//
void DataProtocol::build_HwState(uint8_t * data, uint8_t * size_data, uint8_t state)
{
    data[0]= INIT_FRAME_1;
    data[1] = INIT_FRAME_2;
    data[2] = ID_TELE_HW_STATE;
    data[3] = state;
    *size_data = 3 + SIZE_TELE_HW_STATE;
}
//

//
void DataProtocol::build_PressTemp(uint8_t * data, uint8_t * size_data, int32_t p1, int32_t t1, int32_t p2, int32_t t2)
{
    data[0] = INIT_FRAME_1;
    data[1] = INIT_FRAME_2;
    data[2] = ID_TELE_PRESS_TEMP;
    data[3] = (uint8_t)(p1 >> 24);
    data[4] = (uint8_t)(p1 >> 16);
    data[5] = (uint8_t)(p1 >> 8);
    data[6] = (uint8_t)p1;
    data[7] = (uint8_t)(t1 >> 24);
    data[8] = (uint8_t)(t1 >> 16);
    data[9] = (uint8_t)(t1 >> 8);
    data[10] = (uint8_t)t1;
    data[11] = (uint8_t)(p2 >> 24);
    data[12] = (uint8_t)(p2 >> 16);
    data[13] = (uint8_t)(p2 >> 8);
    data[14] = (uint8_t)p2;
    data[15] = (uint8_t)(t2 >> 24);
    data[16] = (uint8_t)(t2 >> 16);
    data[17] = (uint8_t)(t2 >> 8);
    data[18] = (uint8_t)t2;
    *size_data = 3 + SIZE_TELE_PRESS_TEMP;
}
//

/*
    //Press only
    //IMU
    //Magnetometer
*/

//
void DataProtocol::build_Battery(uint8_t * data, uint8_t * size_data, uint16_t batt1, uint16_t batt2)
{
    data[0] = INIT_FRAME_1;
    data[1] = INIT_FRAME_2;
    data[2] = ID_TELE_BATTERY;
    data[3] = (uint8_t)(batt1 >> 8);
    data[4] = (uint8_t)batt1;
    data[5] = (uint8_t)(batt2 >> 8);
    data[6] = (uint8_t)batt2;
    *size_data = 3 + SIZE_TELE_BATTERY;
}
//

/*
    //Air speed
*/

//
void DataProtocol::build_AirTemp(uint8_t * data, uint8_t * size_data, int16_t t1, int16_t t2)
{
    data[0] = INIT_FRAME_1;
    data[1] = INIT_FRAME_2;
    data[2] = ID_TELE_AIR_TEMP;
    data[3] = (uint8_t)(t1 >> 8);
    data[4] = (uint8_t)t1;
    data[5] = (uint8_t)(t2 >> 8);
    data[6] = (uint8_t)t2;
    *size_data = 3 + SIZE_TELE_AIR_TEMP;
}
//