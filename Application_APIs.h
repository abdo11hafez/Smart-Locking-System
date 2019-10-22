/*
 * Application_APIs.h
 *
 * Created: 10/22/2019 4:51:53 PM
 *  Author: Abdelrahman Hafez
 */ 


#ifndef APPLICATION_APIS_H_
#define APPLICATION_APIS_H_
 #include "external_eeprom.h"
 #include "GPIO.h"
 #include "LCD_4bits.h"
 #include "keypad.h"
 #include <string.h>

 #define PASSWORD_FLAG_ADRESS 0x0002
 #define PASSWOED_ADRESS 0X0200
 #define PASSWORD_DIGITS 4
 
 void Fist_Time_Entry_Check(void);
 void Enter_Password(uint8_t * PasswordBuffer) ;
 uint8_t Password_Compare(uint8_t * PasswordBuffer);
 void System_Reset(void);


#endif /* APPLICATION_APIS_H_ */