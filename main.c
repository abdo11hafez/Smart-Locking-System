 #include "Application_APIs.h"

int main() {
	uint8_t buffer[PASSWORD_DIGITS],lock_status=1,key;
	GPIO_Init() ;
	LCD_Init() ;	
	EEPROM_init();
	//System_Reset();	/*called first time by System Admin to clear password flag (should comment rest of main function)*/
	Fist_Time_Entry_Check();		
	while (1) 
	{
		while (lock_status)
		{
			GPIO_Write(6,0x00);
			GPIO_Write(7,0xff);
			Enter_Password(buffer);
			lock_status=Password_Compare(buffer);			
		}
		if (!lock_status)
		{
			GPIO_Write(7,0x00);
			GPIO_Write(6,0xff);
			LCD_clrScreen(0);
			LCD_DisplayString(0,"System is Unlocked Press any key to lock")	;
			Keypad_GetPressedKey(0,&key) ;
			_delay_ms(500);
			lock_status=1;			
		}				
	}	
}
