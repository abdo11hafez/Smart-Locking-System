/*
 * GPIO.c
 *
 *	Updated on : 10/14/2019 3:00:34 PM
 *  Author	   : Abdelrahman Hafez
 */ 
#include "GPIO.h"
#include "GPIO_Cfg.h"

const GPIO_CfgType GPIO_ConfigParam [GPIO_GROUPS_NUMBER] =
{
	{
		0,						/*PORTA*/	 /*LCD DATA*/
		0xF0,					/*MASK*/
		0xFF,					/*OUTPUT*/
		0x00					/*NO PULLUP*/
	},
	{
		1,						/*PORTB*/	 /*LCD ENABLE*/
		1<<2,					/*MASK*/
		0xFF,					/*OUTPUT*/
		0x00					/*NO PULLUP*/
	},
	{
		1,						/*PORTB*/	/*LCD R/W */
		1<<1,					/*MASK*/
		0xFF,					/*OUTPUT*/			   
		0x00					/*NO PULLUP*/
	},
	{
		1,						/*PORTB*/	/* LCD RS */
		1<<0,					/*MASK*/
		0xFF,					/*OUTPUT*/
		0x00					/*NO PULLUP*/
	},
	{
		3,						/*PORTD*/	  /* KEYPAD ROWS */
		0x0F,					/*MASK*/
		0x00,					/*input*/
		0xff					/*PULLUP*/
	},
	{
		3,						/*PORTD*/	  /* KEYPAD COLUMNS */
		0xf0,					/*MASK*/
		0xFF,					/*OUTPUT*/
		0xff					/*PULLUP*/
	},
	{
		1,						/*PORTD*/	  /* unlocked LED */
		1<<5,					/*MASK*/
		0xFF,					/*OUTPUT*/
		0x00					/*NO PULLUP*/
	},
	{
		1,						/*PORTD*/	  /* locked LED */
		1<<6,					/*MASK*/
		0xFF,					/*OUTPUT*/
		0x00					/*NO PULLUP*/
	}
	
	
	
};