#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_
#include "I2C.h" 
void EEPROM_init(void);   /* declaration of the function that intializes the EEPROM */
uint8_t EEPROM_Write_Byte(uint16_t adress,uint8_t data); /* declaration of the function that writes data into the memory */
uint8_t EEPROM_Read_Byte(uint16_t address,uint8_t *data); /* declaration of the function that read data from the memory   */

#endif /* EXTERNAL_EEPROM_H_ */
