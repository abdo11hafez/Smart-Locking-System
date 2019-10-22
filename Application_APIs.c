/*
 * Application_APIs.c
 *
 * Created: 10/22/2019 4:25:47 PM
 *  Author: Abdelrahman Hafez
 */ 
 #include "Application_APIs.h"
 
 void Fist_Time_Entry_Check(void)
 {
	 uint8_t PasswordBuffer[PASSWORD_DIGITS], Flag=0, key=0, digit_count;
	 EEPROM_Read_Byte(PASSWORD_FLAG_ADRESS,&Flag) ;	 
	 if (!Flag)
	 {
		 do
		 {	
			LCD_clrScreen(0);
			LCD_DisplayString(0,"Enter Password for First Time :- ") ;
			LCD_GoToSecondLine(0);
			digit_count=0 ;
			while (digit_count<PASSWORD_DIGITS)
			{
				Keypad_GetPressedKey(0,&key);
				EEPROM_Write_Byte(PASSWOED_ADRESS+digit_count,key);
				LCD_DisplayChar(0,'*');
				digit_count++;
				_delay_ms(500);
			}
			LCD_clrScreen(0);
			LCD_DisplayString(0,"Confirm Password :- ") ;
			LCD_GoToSecondLine(0);
			digit_count=0;
			while (digit_count<PASSWORD_DIGITS)
			{
				Keypad_GetPressedKey(0,PasswordBuffer+digit_count);
				LCD_DisplayChar(0,'*');
				digit_count++;
				_delay_ms(500);
			}
			 
		 }
		 while(Password_Compare(PasswordBuffer) );
		 EEPROM_Write_Byte(PASSWORD_FLAG_ADRESS,(uint8_t)1);		 
	 }
	 
	 return ;
 }

 void Enter_Password(uint8_t * PasswordBuffer)
 {
	 uint8_t i=0;
	 LCD_clrScreen(0);
	 LCD_DisplayString(0,"System is Locked Enter Password :- ") ;
	 LCD_GoToSecondLine(0);
	 do
	 {
		 Keypad_GetPressedKey(0,PasswordBuffer+i);
		 LCD_DisplayChar(0,'*');
		 i++;
		 _delay_ms(500);
		 
	 } while (i<PASSWORD_DIGITS);
 }
 
 uint8_t Password_Compare(uint8_t * PasswordBuffer)
 {
	 uint8_t MemoryBuffer[PASSWORD_DIGITS],i;
	 for (i=0;i<PASSWORD_DIGITS;i++)
	 {
		EEPROM_Read_Byte(PASSWOED_ADRESS+i,MemoryBuffer+i); 
	 }
	 return memcmp(PasswordBuffer,MemoryBuffer,PASSWORD_DIGITS);
 }
 
 void System_Reset(void)
 {
	 EEPROM_Write_Byte(PASSWORD_FLAG_ADRESS,(uint8_t)0);
 }