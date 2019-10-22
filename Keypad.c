/*
 * Keypad.c
 *
 * Created: 10/19/2019 3:01:45 PM
 *  Author: Abdelrahman Hafez
 */ 

#include "GPIO.h"
#include "Keypad.h"

#define F_CPU 8000000UL
#include <util/delay.h>

Keypad_CheckType Keypad_GetPressedKey(uint8_t GroupId ,uint8_t *data)
{
	uint8_t Temp,col;
	const Keypad_CfgType * CfgPtr;
	if ( GroupId <KEYPAD_GROUPS_NUMBER)
	{
		CfgPtr = & Keypad_ConfigParam[GroupId];
		while(1)
		{
			for (col=0;col<cols;col++)
			{
				GPIO_Write(CfgPtr->Keypad_Columns_GPIO_GroupId,(0xf&~(1<<col))<<4) ;
				GPIO_Read(CfgPtr->Keypad_Rows_GPIO_GroupId,&Temp);
				switch (Temp)
				{
					case 	0xE	:
					*data=Keypad_Keys[0][col] ;
					return Keypad_OK;
					break;
					case 	0xD  :
					*data=Keypad_Keys[1][col] ;
					return Keypad_OK;
					break;
					case  0xB	  :
					*data=Keypad_Keys[2][col] ;
					return Keypad_OK;
					break;
					case  0x7	   :
					*data=Keypad_Keys[3][col] ;
					return Keypad_OK;
					break;
				}
			}
		}						
	}
		
	return	 Keypad_NOK;	
}
