#include <string.h>

#include "FlashMemory.hpp"
#include "DmaSpi.h"
/* 
    Class constructor
*/
Flash::Flash(SPIClass* spi_bus, SPISettings spi_settings, uint8_t pin_ss, uint8_t pin_wp, uint8_t pin_hold)
{
    _spi = spi_bus;
    _spi_settings = spi_settings;
    _ss = pin_ss;
    _wp = pin_wp;
    _hold = pin_hold;
    pinMode(_ss, OUTPUT);
    pinMode(_wp, OUTPUT);
    pinMode(_hold, OUTPUT);
    digitalWrite(_ss, HIGH);
    digitalWrite(_wp, HIGH);
    digitalWrite(_hold, HIGH);
}

/* 
    Performs a soft reset of the flash memory IC. Blocking operation.
*/
void Flash::reset()
{
    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_RESET);
    delayMicroseconds(FLASH_TIME_RESET);
    digitalWrite(_ss, HIGH);
}

/* 
    Checks if communication with the memory works by requesting its manufacturer
    and device JEDEC IDs and comparing them with expected values.   
    ret_val -> int -> 'RET_SUCCESS' Test completed succesfully / 'RET_ERROR' Test failed
*/
int Flash::test()
{
    int ret_val = RET_ERROR;

    uint8_t temp = 0;
    uint8_t manu_id = 0;
    uint16_t ic_id = 0;

    _spi->beginTransaction(_spi_settings);
    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_JEDEC_ID); // Read chip ID
    _spi->transfer(DUMMY_BYTE); // Dummy
    temp = _spi->transfer(DUMMY_BYTE); // Get Manufacturer ID
    manu_id = temp;
    temp = _spi->transfer(DUMMY_BYTE); // Get Device ID 1/2
    ic_id = (uint16_t)temp << 8;
    temp = _spi->transfer(DUMMY_BYTE); // Get Device ID 2/2
    ic_id |= (uint16_t)temp;
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    if ((manu_id == MANUFACTURER_ID) && (ic_id == DEVICE_ID)) ret_val = RET_SUCCESS;

    return ret_val;
}

bool Flash::begin() {
    if (test() != RET_SUCCESS) 
    {
        return false;
    }
    writeStatusRegister(SR_1_ADDR, 0); // remove pesky write protect bits
    return true;
}

/*
    Read the value of the Status Register specified by 'reg_address' into 'reg_value'
    ret_val -> int -> 'RET_SUCCESS' Reading succesfully / 'RET_ERROR' Reading failed
*/
int Flash::readStatusRegister(uint8_t reg_address, uint8_t * reg_value)
{
    int ret_val = RET_ERROR;

    if ((reg_address == SR_1_ADDR) || (reg_address == SR_2_ADDR) || (reg_address == SR_3_ADDR)) // Check valid Status Register address
    {
        _spi->beginTransaction(_spi_settings);
        digitalWrite(_ss, LOW);
        _spi->transfer(OPCODE_READ_STATUS_REG); // Read Status Register
        _spi->transfer(reg_address); //Register address
        *reg_value = _spi->transfer(DUMMY_BYTE);
        digitalWrite(_ss, HIGH);
        _spi->endTransaction();

        ret_val = RET_SUCCESS;
    }

    return ret_val;
}

/*
    Write 'reg_value' in the the Status Register specified by 'reg_address'
    ret_val -> int -> 'RET_SUCCESS' Writting succesfully / 'RET_ERROR' Writting failed
*/
int Flash::writeStatusRegister(uint8_t reg_address, uint8_t reg_value)
{
    int ret_val = RET_ERROR;

    if ((reg_address == SR_1_ADDR) || (reg_address == SR_2_ADDR) || (reg_address == SR_3_ADDR)) // Check valid Status Register address
    {
        _spi->beginTransaction(_spi_settings);
        waitBusy();

        digitalWrite(_ss, LOW);
        _spi->transfer(OPCODE_WRITE_STATUS_REG); // Read Status Register
        _spi->transfer(reg_address); //Register address
        _spi->transfer(reg_value);
        digitalWrite(_ss, HIGH);
        _spi->endTransaction();

        ret_val = RET_SUCCESS;
    }

    return ret_val;
}

/*
    Sets the Write Enable Latch (WEL) bit on SR-3 in order to enable write/erase operations 
    in the memory.
    ret_val -> int -> 'RET_SUCCESS' WEL succesfully set / 'RET_ERROR' WEL setting failed
*/
int Flash::writeEnable()
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(_spi_settings);
    waitBusy();
    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_WRITE_ENABLE);
    digitalWrite(_ss, HIGH);
    waitBusy();
    _spi->endTransaction();

    uint8_t temp = 0;
    this->readStatusRegister(SR_3_ADDR, &temp);
    if (temp & SR_3_WEL)
    {
        ret_val = RET_SUCCESS;
    }
    
    return ret_val;
}

void Flash::findBadBlocks() {
    uint8_t buf[2048] = {0};
    for(uint16_t i = 0; i < AMOUNT_OF_BLOCKS; i++) {
        blockErase(i * 64);
        programDataLoad(buf, 2048, 0, true);
        programExecute(i * 64);
        pageDataRead(i * 64);
        readData(buf, 0);
        for (uint16_t j = 0; j < PAGE_SIZE; j++) {
            if (buf[j] != 0) {
                Serial.print("BAD: ");
                Serial.println(i);
            }
        }
    }
}

void Flash::bufferedWrite(uint8_t* buf, uint8_t len) {
    if (_buffered_column_index + len >= PAGE_SIZE) {
        uint8_t bytes_left = PAGE_SIZE - _buffered_column_index;
        programDataLoad(buf, bytes_left, _buffered_column_index, false);
        programExecute(_buffered_page_index);
        _buffered_page_index++;
        programDataLoad(buf, len - bytes_left, 0, false);
        _buffered_column_index = len - bytes_left;
        return;
    }
    programDataLoad(buf, len, _buffered_column_index, false);
    _buffered_column_index += len;
}

void Flash::flush() {
    programExecute(_buffered_page_index);
    _buffered_page_index++;
    _buffered_column_index = 0;
}

/*
    This instruction transfer the data stored in the given Page Address into the memory's 
    data buffer. This process will complete after max 'tRD = 60us'.
    ret_val -> int -> 'RET_SUCCESS' Page data loading initiated
*/
int Flash::pageDataRead(uint16_t page_addr)
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_PAGE_READ);
    _spi->transfer(DUMMY_BYTE);
    _spi->transfer((uint8_t)(page_addr >> 8));
    _spi->transfer((uint8_t)page_addr);
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    ret_val = RET_SUCCESS;

    return ret_val;
}

/*
    Read the data stored into the memory buffer starting at the specified Column Address.
    Enter 'column_addr' = 0 to read the entire Page. 'data_buffer' size has to be at least
    2048 bytes as that will be the maximum amount of data that can be read.
    ret_val -> int -> 'RET_SUCCESS' Data has been read from memory
*/
int Flash::readData(uint8_t * data_buffer, uint16_t column_addr)
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_READ);
    _spi->transfer((uint8_t)(column_addr >> 8));
    _spi->transfer((uint8_t)column_addr);
    _spi->transfer(DUMMY_BYTE);

    for (uint16_t i = column_addr; i < 2048; i++)
    {
        data_buffer[i] = _spi->transfer(DUMMY_BYTE);
    }
    
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    //Check SR-3 for ECC related errors
    waitBusy();
    uint8_t reg_val = 0;
    ret_val = RET_SUCCESS;

    return ret_val;
}

/*
    Load up to 2048 bytes (1 Page) into the memory buffer starting at the specified Column Address.
    If loaded data is less than 2048 bytes, the remaining bytes will be set to 0xFF.
    'data_buffer' size has to be at least 2048 bytes as that will be the maximum amount of
    data that can be written.
    ret_val -> int -> 'RET_SUCCESS' Data has been loaded in the memory buffer
*/
int Flash::programDataLoad(uint8_t * data_buffer, uint16_t len, uint16_t column_addr, bool reset)
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    uint8_t op_code = reset ?  OPCODE_PROGRAM_LOAD : OPCODE_RANDOM_PROGRAM_LOAD;
    _spi->transfer(op_code); // Load Program Data
    _spi->transfer((uint8_t)(column_addr >> 8)); // Column Address (16-bit)
    _spi->transfer((uint8_t)column_addr);
    for (int i = 0; i < len; i++)
    {
        _spi->transfer(data_buffer[i]); // Transfer 1 byte of data
    }
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    ret_val = RET_SUCCESS;

    return ret_val;
}


void Flash::programDataLoadAsync(uint8_t * data_buffer, uint16_t len, uint16_t column_addr, bool reset)
{
    static DmaSpi1::Transfer* trx;
    static AbstractChipSelect* cs;
    digitalWriteFast(_ss, LOW);
    _spi->beginTransaction(_spi_settings);
    waitBusy();
    _spi->endTransaction();
    digitalWriteFast(_ss, HIGH);
 
    uint16_t total_len = 3 + len;
    uint8_t op_code = reset ?  OPCODE_PROGRAM_LOAD : OPCODE_RANDOM_PROGRAM_LOAD;
    _dma_buf[0] = op_code;
    _dma_buf[1] = (uint8_t)(column_addr >> 8);
    _dma_buf[2] = (uint8_t)(column_addr);
    memcpy(_dma_buf + 3, data_buffer, len);
    free(trx);
    free(cs);
    cs = new ActiveLowChipSelect1(_ss, _spi_settings);
    trx = new DmaSpi1::Transfer(_dma_buf, total_len, nullptr, 0, cs);
    _dma_spi->registerTransfer(*trx);
}

void Flash::printAllRegisters() 
{
    uint8_t val;
    _spi->beginTransaction(_spi_settings);
    waitBusy();
    digitalWriteFast(_ss, LOW);
    readStatusRegister(SR_1_ADDR, &val);
    Serial.print("SR-1: ");
    Serial.println(val, BIN);
    readStatusRegister(SR_2_ADDR, &val);
    Serial.print("SR-2: ");
    Serial.println(val, BIN);
    readStatusRegister(SR_3_ADDR, &val);
    Serial.print("SR-3: ");
    Serial.println(val, BIN);
    digitalWriteFast(_ss, HIGH);
    _spi->endTransaction();
}

/*
    Program the contents of the buffer into the specified Page Address
    ret_val -> int -> 
        'RET_SUCCESS' Data has beed programed to memory
        'RET_ERROR' There was an error during data programming

    **NOTE**    Separate the error checking logic as to not block execution
                until the program operation has finished.
*/
int Flash::programExecute(uint16_t page_addr)
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_PROGRAM_EXECUTE);
    _spi->transfer(DUMMY_BYTE);
    _spi->transfer((uint8_t)(page_addr >> 8));
    _spi->transfer((uint8_t)page_addr);
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    //Check SR-3 for errors during program operation
    waitBusy();
    uint8_t reg_val = 0;
    if (readStatusRegister(SR_3_ADDR, &reg_val) == RET_SUCCESS)
    {
        ret_val = (reg_val & SR_3_PFAIL) ? RET_ERROR : RET_SUCCESS;
    }

    return ret_val;
}

/*
    Erase (sets each byte to 0xFF) the content of the memory block 
    (64 Pages = 128 KB) corresponding to the specified Page Address.
    ret_val -> int -> 
        'RET_SUCCESS' Memory block has been erased
        'RET_ERROR' There was an error during memory erasing

    **NOTE**    Separate the error checking logic as to not block execution
                until the erase operation has finished.
*/
int Flash::blockErase(uint16_t page_addr)
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_BLOCK_ERASE);
    _spi->transfer(DUMMY_BYTE);
    _spi->transfer((uint8_t)(page_addr >> 8));
    _spi->transfer((uint8_t)page_addr);
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    //Check SR-3 for errors during erase operation
    waitBusy();
    uint8_t reg_val = 0;
    if (readStatusRegister(SR_3_ADDR, &reg_val) == RET_SUCCESS)
    {
        ret_val = (reg_val & SR_3_EFAIL) ? RET_ERROR : RET_SUCCESS;
    }
    
    return ret_val;
}

/* 
    Check if the memory controller is ready to accept new commands.
    ret_val -> uint8_t -> '1' Controller is busy / '0' Controller is ready
*/
uint8_t Flash::isBusy()
{
    uint8_t ret_val = 0;
    // Read Status Register SR-3
    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_READ_STATUS_REG); // Read Status Register
    _spi->transfer(SR_3_ADDR); // SR-3 Address
    ret_val = _spi->transfer(DUMMY_BYTE) & SR_3_BUSY; // Read busy it value. If '1' the Flash is busy with some task.
    digitalWrite(_ss, HIGH);

    return ret_val;
}

void Flash::waitBusy()
{
    uint32_t start = micros();
    while (isBusy() && micros() - start < BUSY_MAX_WAIT)
    {
        yield();
    }
}

/* 
    Use always this function first before using the memory on the
    main application. It will check for Bad Blocks marked at the 
    factory that will need to be deal with prior to end use.
*/
void Flash::checkFactoryBadBlocks()
{
    uint8_t read_buffer[2048];

    for (uint16_t block_num = 0; block_num < 1024; block_num++)
    {
        this->pageDataRead(block_num*64);
        this->readData(read_buffer, 0);

        Serial.print("Block ");
        Serial.print(block_num);
        Serial.print(" => ");
        Serial.print(read_buffer[0], HEX);
        if (read_buffer[0] != 0xFF) Serial.print(" BAD");
        Serial.println();
    }
}

/* 
    Read and display the memory's internal LUT that store the links used to
    handle bad memory blocks.
*/
void Flash::readBadBlockLUT()
{
    uint16_t logic_blocks[20];
    uint16_t physical_blocks[20];

    _spi->beginTransaction(_spi_settings);
    waitBusy();

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_BBM_READ);
    _spi->transfer(DUMMY_BYTE);
    for (int i = 0; i < 20; i++)
    {
        uint8_t temp = 0;
        temp = _spi->transfer(DUMMY_BYTE);
        logic_blocks[i] = (uint16_t)temp << 8;
        temp = _spi->transfer(DUMMY_BYTE);
        logic_blocks[i] |= (uint16_t)temp;
        temp = _spi->transfer(DUMMY_BYTE);
        physical_blocks[i] = (uint16_t)temp << 8;
        temp = _spi->transfer(DUMMY_BYTE);
        physical_blocks[i] |= (uint16_t)temp;
    } 
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    Serial.println("** Bad Block Management LUT **");
    for (int i = 0; i < 20; i++)
    {
        Serial.print("LBA ");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(logic_blocks[i], BIN);
        Serial.print(" <=> PBA ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(physical_blocks[i], BIN);
    } 
}

void testFlashMemory(Flash * obj)
{
    /*
    uint8_t write_buff[2048];
    uint8_t read_buff[2048];
    uint8_t page_count;
    int8_t ret_val = 0;
    
    Serial.println("** ERASE block 0**");
    obj->writeEnable();
    ret_val = obj->blockErase(2);
    if (ret_val == RET_ERROR)
    {
        Serial.println("ERROR Block Erase");
    }
    Serial.println("** ERASE block 1**");
    obj->writeEnable();
    ret_val = obj->blockErase(70);
    if (ret_val == RET_ERROR)
    {
        Serial.println("ERROR Block Erase");
    }

    Serial.println("** WRITE 1 **");
    page_count = 0;
    while (page_count < 128)
    {
        for (int i = 0; i < 2048; i++)
        {
            write_buff[i] = page_count;
        }
        obj->writeEnable();
        obj->programDataLoad(write_buff, 0);
        ret_val = obj->programExecute(page_count);
        if (ret_val == RET_ERROR)
        {
            Serial.println("ERROR Program Execute");
        }
        page_count++;
        //Display values
        Serial.print("Page ");
        Serial.print(page_count);
        Serial.print(": ");
        Serial.print(write_buff[0], HEX);
        Serial.print(", ");
        Serial.print(write_buff[1], HEX);
        Serial.print(", ");
        Serial.print(write_buff[2], HEX);
        Serial.print(", ");
        Serial.println(write_buff[3], HEX);
    }

    Serial.println("** READ 1 **");
    page_count = 0;
    while (page_count < 128)
    {
        obj->pageDataRead(page_count);
        obj->readData(read_buff, 0);
        page_count++;
        //Display values
        Serial.print("Page ");
        Serial.print(page_count);
        Serial.print(": ");
        Serial.print(read_buff[0], HEX);
        Serial.print(", ");
        Serial.print(read_buff[1], HEX);
        Serial.print(", ");
        Serial.print(read_buff[2], HEX);
        Serial.print(", ");
        Serial.println(read_buff[3], HEX);
    }

    Serial.println("** ERASE **");
    obj->writeEnable();
    ret_val = obj->blockErase(2);
    if (ret_val == RET_ERROR)
    {
        Serial.println("ERROR Block Erase");
    }

    Serial.println("** READ 2 **");
    page_count = 0;
    while (page_count < 128)
    {
        obj->pageDataRead(page_count);
        obj->readData(read_buff, 0);
        page_count++;
        //Display values
        Serial.print("Page ");
        Serial.print(page_count);
        Serial.print(": ");
        Serial.print(read_buff[0], HEX);
        Serial.print(", ");
        Serial.print(read_buff[1], HEX);
        Serial.print(", ");
        Serial.print(read_buff[2], HEX);
        Serial.print(", ");
        Serial.println(read_buff[3], HEX);
    }

    Serial.println("** WRITE 2 **");
    //obj->writeEnable();
    page_count = 10;
    while (page_count < 40)
    {
        for (int i = 0; i < 2048; i++)
        {
            write_buff[i] = page_count-100;
        }
        obj->writeEnable();
        obj->programDataLoad(write_buff, 0);
        ret_val = obj->programExecute(page_count);
        if (ret_val == RET_ERROR)
        {
            Serial.println("ERROR Program Execute");
        }
        page_count++;
        //Display values
        Serial.print("Page ");
        Serial.print(page_count);
        Serial.print(": ");
        Serial.print(write_buff[0], HEX);
        Serial.print(", ");
        Serial.print(write_buff[1], HEX);
        Serial.print(", ");
        Serial.print(write_buff[2], HEX);
        Serial.print(", ");
        Serial.println(write_buff[3], HEX);
    }

    Serial.println("** READ 3 **");
    page_count = 0;
    while (page_count < 128)
    {
        obj->pageDataRead(page_count);
        obj->readData(read_buff, 0);
        page_count++;
        //Display values
        Serial.print("Page ");
        Serial.print(page_count);
        Serial.print(": ");
        Serial.print(read_buff[0], HEX);
        Serial.print(", ");
        Serial.print(read_buff[1], HEX);
        Serial.print(", ");
        Serial.print(read_buff[2], HEX);
        Serial.print(", ");
        Serial.println(read_buff[3], HEX);
    }
    */
}
