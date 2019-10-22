#include <avr/io.h>
#include <stdint.h>

#define START_SENT				 0x08 
#define REPEATED_START_SENT      0x10 
#define M_Tx_SLA_W_ACK			 0x18 
#define M_Tx_SLA_R_ACK			 0x40 
#define M_Tx_DATA_ACK			 0x28 
#define M_Rx_DATA_ACK			 0x50 
#define M_Rx_DATA_NACK			 0x58 


typedef struct{
	uint8_t Prescaler;									   /* Prescaler of the frequency			 */
	uint32_t Scl_Freq;                                     /* Clock Frequency						 */
	uint8_t Address;                                       /* address of the device (Slave Mode)     */
	uint8_t GeneralCallRecognition;						   /* general call recognition mode setup	 */

}I2C_CnfgType;

void I2C_init(void); 
void I2C_start(void);                  
void I2C_stop(void);                   
void I2C_write(uint8_t data);            
uint8_t I2C_Read_With_ACK(void);           
uint8_t I2C_Read_With_NACK(void);          
uint8_t I2C_Get_Status(void);             
