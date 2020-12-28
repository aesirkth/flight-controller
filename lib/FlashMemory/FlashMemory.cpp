#include "FlashMemory.hpp"

/* 
    Class constructor
*/
Flash::Flash(SPIClass * spi_bus, SPISettings * spi_settings, uint8_t pin_ss, uint8_t pin_wp, uint8_t pin_hold)
{
    _spi = spi_bus;
    _spi_settings = spi_settings;
    _ss = pin_ss;
    _wp = pin_wp;
    _hold = pin_hold;

    pinMode(_wp, OUTPUT);
    pinMode(_hold, OUTPUT);
    digitalWrite(_wp, HIGH);
    digitalWrite(_hold, HIGH);
}

/* 
    Performs a soft reset of the flash memory IC. Blocking operation.
*/
void Flash::reset()
{
    _spi->beginTransaction(*_spi_settings);
    while (isBusy())
    {
        delayMicroseconds(1);
    }

    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_RESET);
    digitalWrite(_ss, HIGH);

    delayMicroseconds(FLASH_TIME_RESET);
    _spi->endTransaction();
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

    _spi->beginTransaction(*_spi_settings);
    digitalWrite(_ss, LOW);
    SPI1.transfer(OPCODE_JEDEC_ID); // Read chip ID
    SPI1.transfer(DUMMY_BYTE); // Dummy
    temp = SPI1.transfer(DUMMY_BYTE); // Get Manufacturer ID
    manu_id = temp;
    temp = SPI1.transfer(DUMMY_BYTE); // Get Device ID 1/2
    ic_id = (uint16_t)temp << 8;
    temp = SPI1.transfer(DUMMY_BYTE); // Get Device ID 2/2
    ic_id |= (uint16_t)temp;
    digitalWrite(_ss, HIGH);
    _spi->endTransaction();

    if ((manu_id == MANUFACTURER_ID) && (ic_id == DEVICE_ID)) ret_val = RET_SUCCESS;

    return ret_val;
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
        _spi->beginTransaction(*_spi_settings);
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
        _spi->beginTransaction(*_spi_settings);
        while (isBusy())
        {
            delayMicroseconds(1);
        }

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

    _spi->beginTransaction(*_spi_settings);
    digitalWrite(_ss, LOW);
    _spi->transfer(OPCODE_WRITE_ENABLE);
    digitalWrite(_ss, HIGH);
    while (isBusy())
    {
        delayMicroseconds(1);
    }
    _spi->endTransaction();

    uint8_t temp = 0;
    this->readStatusRegister(SR_3_ADDR, &temp);
    if (temp & SR_3_WEL)
    {
        ret_val = RET_SUCCESS;
    }
    
    return ret_val;
}

/*
    This instruction transfer the data stored in the given Page Address into the memory's 
    data buffer. This process will complete after max 'tRD = 60us'.
    ret_val -> int -> 'RET_SUCCESS' Page data loading initiated
*/
int Flash::pageDataRead(uint16_t page_addr)
{
    int ret_val = RET_ERROR;

    _spi->beginTransaction(*_spi_settings);
    while (isBusy())
    {
        delayMicroseconds(1);
    }

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

    _spi->beginTransaction(*_spi_settings);
    while (isBusy())
    {
        delayMicroseconds(1);
    }

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

    ret_val = RET_SUCCESS;

    return ret_val;
}

/* 
    Check if the memory controller is ready to accept new commands
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