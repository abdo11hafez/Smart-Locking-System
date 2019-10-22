/*
 * Keypad.h
 *
 * Created: 10/19/2019 3:00:45 PM
 *  Author: Abdelrahman Hafez
 */ 

#include <stdint.h>
#include "Keypad_Cfg.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_
#define rows 4
#define cols 3
typedef struct
{
	uint8_t Keypad_Rows_GPIO_GroupId;   // Rows pins index in GPIO ConfigParam Structure in "gpio_cfg.c"

	uint8_t Keypad_Columns_GPIO_GroupId; // Columns pins index in GPIO ConfigParam Structure in "gpio_cfg.c"

}Keypad_CfgType;

static const uint8_t Keypad_Keys[rows][cols] =
{
	{'7','8','9'},
	{'4','5','6'},
	{'1','2','3'},
	{'*','0','#'}
};

 extern const Keypad_CfgType Keypad_ConfigParam [KEYPAD_GROUPS_NUMBER];
 typedef enum {Keypad_OK =0, Keypad_NOK} Keypad_CheckType;

Keypad_CheckType Keypad_GetPressedKey(uint8_t GroupId ,uint8_t *data);
#endif /* KEYPAD_H_ */