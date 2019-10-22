#include <stdint.h>
#include "LCD_4bits_Cfg.h"

# ifndef LCD_4bits_h
# define LCD_4bits_h

#include <stdint.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define HIGH_NIBBLE(h_nib,data) h_nib= (data & 0xf0)  // h_nib will hold value of high nibble of data
#define LOW_NIBBLE(l_nib,data)  l_nib= (data<<4)      // l_nib will hold the value of low nibble of data

typedef struct
{
uint8_t Lcd_Data_GPIO_GroupId;   // Data pins index in GPIO ConfigParam Structure in "gpio_cfg.c"

uint8_t Lcd_Enable_GPIO_GroupId; // Enable pin index in GPIO ConfigParam Structure in "gpio_cfg.c"

uint8_t Lcd_RW_GPIO_GroupId;     // R/W pin index in GPIO ConfigParam Structure in "gpio_cfg.c"

uint8_t Lcd_RS_GPIO_GroupId;     // RS pin index in GPIO ConfigParam Structure in "gpio_cfg.c"

}LCD_CfgType;

extern const LCD_CfgType LCD_ConfigParam [LCD_GROUPS_NUMBER];
typedef enum {LCD_OK =0, LCD_NOK} LCD_CheckType;

void delayMs(int n) ;
LCD_CheckType LCD_Init(void);
LCD_CheckType LCD_DisplayChar (uint8_t GroupId ,uint8_t data);
LCD_CheckType LCD_clrScreen(uint8_t GroupId );
LCD_CheckType LCD_GoToFirstLine(uint8_t GroupId);
LCD_CheckType LCD_GoToSecondLine(uint8_t GroupId);
LCD_CheckType LCD_DisplayString(uint8_t GroupId ,uint8_t * ptr);

#endif
