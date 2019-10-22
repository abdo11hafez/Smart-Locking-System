#include "external_eeprom.h"  

void EEPROM_init(void)
{
	 
	I2C_init();   
}

uint8_t EEPROM_Write_Byte(uint16_t address, uint8_t data)
{
    I2C_start();
    if (I2C_Get_Status() != START_SENT)
        return 0;

    I2C_write((uint8_t)(0xA0 | ((address & 0x0700)>>7)));
    if (I2C_Get_Status() != M_Tx_SLA_W_ACK)
        return 0;

    I2C_write(address);
    if (I2C_Get_Status() != M_Tx_DATA_ACK)
        return 0;

    I2C_write(data);
    if (I2C_Get_Status() != M_Tx_DATA_ACK)
        return 0;

    I2C_stop();

    return 1;
}

uint8_t EEPROM_Read_Byte(uint16_t adress, uint8_t *data)
{
    I2C_start();
    if (I2C_Get_Status() != START_SENT)
        return 0;

    I2C_write((uint8_t)((0xA0) | ((adress & 0x0700)>>7)));
    if (I2C_Get_Status() != M_Tx_SLA_W_ACK)
        return 0;

    I2C_write(adress);
    if (I2C_Get_Status() != M_Tx_DATA_ACK)
        return 0;

    I2C_start();
    if (I2C_Get_Status() != REPEATED_START_SENT)
        return 0;

    I2C_write((uint8_t)((0xA0) | ((adress & 0x0700)>>7) | 1));
    if (I2C_Get_Status() != M_Tx_SLA_R_ACK)
        return 0;

    *data = I2C_Read_With_NACK();
    if (I2C_Get_Status() != M_Rx_DATA_NACK)
        return 0;

    I2C_stop();
    return 1;
}
