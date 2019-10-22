#include "I2C.h" /* include the header file for the TWI Driver */

extern const I2C_CnfgType CnfgGroup	;
 void I2C_init(void)
 {
	 TWSR = (TWSR & 0xFC) | (CnfgGroup.Prescaler);
	 #ifndef  F_CPU
	 #define  F_CPU 8000000UL
	 #endif
	 TWBR = ((((F_CPU / CnfgGroup.Scl_Freq) / CnfgGroup.Prescaler) - 16 ) / 2);
	 TWAR = (TWAR & 0x01) | (((CnfgGroup.Address)<<1) & 0xFE);
	 TWAR = (TWAR & 0xFE) | (CnfgGroup.GeneralCallRecognition & 0x01);
	 TWCR = (1<<TWEN);
 }

 void I2C_start(void)
 {
	 TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	 while(!(TWCR & (1<<TWINT)));
 }

 void I2C_stop(void)
 {
	 TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
 }

 void I2C_write(uint8_t data)
 {
	 TWDR = data;
	 TWCR = (1 << TWINT) | (1 << TWEN);
	 while(!(TWCR & (1<<TWINT)));
 }

 uint8_t I2C_Read_With_ACK(void)
 {
	 TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	 while(!(TWCR & (1<<TWINT)));
	 return TWDR;
 }
 uint8_t I2C_Read_With_NACK(void)
 {
	 TWCR = (1 << TWINT) | (1 << TWEN);
	 while(!(TWCR & (1<<TWINT)));
	 return TWDR;
 }

 uint8_t I2C_Get_Status(void)
 {
	 uint8_t status;
	 status = TWSR & 0xF8;
	 return status;
 }


