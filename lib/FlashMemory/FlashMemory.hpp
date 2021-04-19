#ifndef FLASH_MEMORY_H
#define FLASH_MEMORY_H

#include <Arduino.h>
#include <SPI.h>
#include "DmaSpi.h"

#define PAGE_SIZE 2048
#define AMOUNT_OF_BLOCKS 1024
#define AMOUNT_OF_PAGES (AMOUNT_OF_BLOCKS * 64)

#define RET_ERROR   -1
#define RET_BUSY    0
#define RET_SUCCESS 1

// Status Register addresses
#define SR_1_ADDR 0xA0
#define SR_2_ADDR 0xB0
#define SR_3_ADDR 0xC0

// Status Register configuration bits
// SR-1 (Protection Register)
#define SR_1_SRP0   0x80    // Status Register Protect Bit 0
#define SR_1_BP3    0x40    // Block Protect Bit 3
#define SR_1_BP2    0x20    // Block Protect Bit 2
#define SR_1_BP1    0x10    // Block Protect Bit 1
#define SR_1_BP0    0x08    // Block Protect Bit 0
#define SR_1_TB     0x04    // Top/Bottom Protect Bit
#define SR_1_WPE    0x02    // Write Protection Enable Bit
#define SR_1_SRP1   0x01    // Status Register Protect Bit 1
// SR-2 (Configuration Register)
#define SR_2_OTPL   0x80    // One Time Program (OTP) Lock Bit
#define SR_2_OTPE   0x40    // Enter OTP Access Mode Bit
#define SR_2_SR1L   0x20    // Status Register 1 Lock Bit
#define SR_2_ECCE   0x10    // ECC Enbale Bit
#define SR_2_BUF    0x08    // Buffer Read / Continuous Read Mode Bit
// SR-3
#define SR_3_LUTF   0x40    // Look-Up Table Full
#define SR_3_ECC1   0x20    // Cumulative ECC Status 1
#define SR_3_ECC0   0x10    // Cumulative ECC Status 0
#define SR_3_PFAIL  0x08    // Program Failure
#define SR_3_EFAIL  0x04    // Erase Failure
#define SR_3_WEL    0x02    // Write Enale Latch
#define SR_3_BUSY   0x01    // Erase/Program In Progress

// Instructions OpCodes
#define OPCODE_RESET            0xFF
#define OPCODE_JEDEC_ID         0x9F
#define OPCODE_READ_STATUS_REG  0x0F
#define OPCODE_WRITE_STATUS_REG 0x1F
#define OPCODE_WRITE_ENABLE     0x06
#define OPCODE_WRITE_DISABLE    0x04
#define OPCODE_BBM_WRITE        0xA1
#define OPCODE_BBM_READ         0xA5
#define OPCODE_LAST_ECC_FAIL    0xA9
#define OPCODE_BLOCK_ERASE      0xD8
#define OPCODE_PROGRAM_LOAD     0x02
#define OPCODE_RANDOM_PROGRAM_LOAD  0x84
#define OPCODE_PROGRAM_EXECUTE  0x10
#define OPCODE_PAGE_READ        0x13
#define OPCODE_READ             0x03

#define DUMMY_BYTE   0xFF
#define FLASH_TIME_RESET    1000u   // Microseconds
#define MANUFACTURER_ID     0xEF
#define DEVICE_ID           0xAA21
#define BUSY_MAX_WAIT       500u
/* NOTE: The device is supposed to work in Buffer Mode => 'SR_2_BUF' = 1 */
class Flash
{
    // SPI bus and specific pins configuration
    SPIClass * _spi;
    DmaSpi1* _dma_spi = &DMASPI1; // hard code this until i feel like implementing templates
    SPISettings _spi_settings;
    uint8_t _ss;
    uint8_t _wp;
    uint8_t _hold;

    uint8_t _dma_buf[3 + PAGE_SIZE];
    uint8_t _buffered_column_index = 0;
    uint8_t _buffered_page_index = 0;

public:
    Flash(SPIClass* spi_bus, SPISettings spi_settings, uint8_t pin_ss, uint8_t pin_wp, uint8_t pin_hold);
    void reset();
    int test();
    bool begin();
    //int init();
    int readStatusRegister(uint8_t reg_address, uint8_t * reg_value);
    int writeStatusRegister(uint8_t reg_address, uint8_t reg_value);
    int writeEnable();
    void bufferedWrite(uint8_t* buf, uint8_t len);
    void flush();
    void findBadBlocks();

    //int writeDisable();
    int pageDataRead(uint16_t page_addr);
    int readData(uint8_t * data_buffer, uint16_t column_addr);
    int programDataLoad(uint8_t * data_buffer, uint16_t len, uint16_t column_addr, bool reset);
    void programDataLoadAsync(uint8_t * data_buffer, uint16_t len, uint16_t column_addr, bool reset);
    int programExecute(uint16_t page_addr);
    int blockErase(uint16_t page_addr);
    void waitBusy();
    void printAllRegisters();
    uint8_t isBusy();
    void checkFactoryBadBlocks(); // Use always before using the memory for its intended application
    void readBadBlockLUT();
};

void testFlashMemory(Flash * obj);

#endif