#include <stdint.h>

#define EC_TO_GC_TC_START 0x40
#define EC_TO_GC_TC_END 0x4F

#define GC_TO_EC_TC_START 0x30 
#define GC_TO_EC_TC_END 0x3F

#define EC_TO_GC_TM_START 0x90
#define EC_TO_GC_TM_END 0xFF

void DataProtocolCallback(uint8_t id, uint8_t* buf, uint8_t len);
void handleDataStreams();