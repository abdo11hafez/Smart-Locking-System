/*
 * I2C_Cfg.c
 *
 * Created: 10/22/2019 8:52:26 PM
 *  Author: Abdelrahman Hafez
 */ 

#include "I2C.h"

const I2C_CnfgType CnfgGroup =
{	0x00, 			 /* Prescaler of the frequency			 */
	100000,			 /* I2C Clock Frequency					 */
	0x02, 			 /* address of the device (Slave Mode)   */
	0x01			 /* general call recognition mode setup	 */
} ;
