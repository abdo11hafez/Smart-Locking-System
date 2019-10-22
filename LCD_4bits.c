#include "GPIO.h"
#include "LCD_4bits.h"

static LCD_CheckType LCD_EnableTrigger(uint8_t GroupId)
{
    const LCD_CfgType * CfgPtr;
    if ( GroupId <LCD_GROUPS_NUMBER)
    {
        CfgPtr =  & LCD_ConfigParam[GroupId];
        GPIO_Write(CfgPtr->Lcd_Enable_GPIO_GroupId, 0xff);
        _delay_ms(1);
        GPIO_Write(CfgPtr->Lcd_Enable_GPIO_GroupId, 0x00);
        _delay_ms(6);
        return LCD_OK;
    }
    return LCD_NOK;
}

static LCD_SendCommand(uint8_t GroupId ,uint8_t cmd)
{
    uint8_t high_nibble , low_nibble ;
    HIGH_NIBBLE(high_nibble,cmd);
    LOW_NIBBLE(low_nibble,cmd);
    const LCD_CfgType * CfgPtr;
    if ( GroupId <LCD_GROUPS_NUMBER)
        {
        CfgPtr = & LCD_ConfigParam[GroupId];

        GPIO_Write(CfgPtr->Lcd_RS_GPIO_GroupId, 0) ;            // enable command mode
        GPIO_Write(CfgPtr->Lcd_RW_GPIO_GroupId, 0) ;            // activate LCD write

        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, 0) ;
        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, high_nibble);  // to send high nibble command
        LCD_EnableTrigger(GroupId);                                  // trigger LCD enable

        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, 0) ;
        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, low_nibble);  // to send low nibble command
        LCD_EnableTrigger(GroupId);

        return LCD_OK ;
        }
    else return LCD_NOK ;
}


LCD_CheckType LCD_Init(void)
{
	uint8_t LoopIndex;
	const LCD_CfgType * CfgPtr;
	if (LCD_GROUPS_NUMBER >0 ) {
		for(LoopIndex = 0; (LoopIndex < LCD_GROUPS_NUMBER); LoopIndex ++)
		{
			CfgPtr = & LCD_ConfigParam[LoopIndex];
			GPIO_Write(CfgPtr->Lcd_Enable_GPIO_GroupId, 0xff); // activate LCD enable

			LCD_SendCommand (LoopIndex,0x33);			// 4-bit mode
			LCD_SendCommand (LoopIndex,0x32);
			LCD_SendCommand (LoopIndex,0x28);
			LCD_SendCommand (LoopIndex,0x0c);			// turn on LCD
		}
		return LCD_OK ;
	}
	else return LCD_NOK ;
}

LCD_CheckType LCD_DisplayChar (uint8_t GroupId ,uint8_t data)
{
    uint8_t high_nibble , low_nibble ;
    HIGH_NIBBLE(high_nibble,data);
    LOW_NIBBLE(low_nibble,data);
    const LCD_CfgType * CfgPtr;
    if ( GroupId <LCD_GROUPS_NUMBER)
    {
        CfgPtr = & LCD_ConfigParam[GroupId];

        GPIO_Write(CfgPtr->Lcd_RS_GPIO_GroupId, 0xff) ;		//  enable data mode
        GPIO_Write(CfgPtr->Lcd_RW_GPIO_GroupId, 0)    ;		//  activate LCD write

        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, 0) ;
        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, high_nibble) ;	// to send high nibble data
        LCD_EnableTrigger(GroupId);									    // trigger LCD enable

        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, 0) ;
        GPIO_Write(CfgPtr->Lcd_Data_GPIO_GroupId, low_nibble) ;		// to send low nibble data
        LCD_EnableTrigger(GroupId);

            return LCD_OK;
        }
    else return LCD_NOK ;
}

LCD_CheckType LCD_clrScreen(uint8_t GroupId)
{
	LCD_CheckType RetVal;
    if ( GroupId <LCD_GROUPS_NUMBER)
    {
        RetVal=LCD_SendCommand(GroupId,0x01);
        return RetVal;
    }
    else return LCD_NOK ;
}

LCD_CheckType LCD_DisplayString(uint8_t GroupId ,uint8_t * ptr)
{
	LCD_CheckType RetVal;
    if ( GroupId <LCD_GROUPS_NUMBER)
    {
        while(* ptr!= '\0')
        {
            RetVal=LCD_DisplayChar(GroupId ,*ptr);
            ptr++;
        }
        return RetVal;
    }
    else return LCD_NOK;
}

LCD_CheckType LCD_GoToFirstLine(uint8_t GroupId)
{
	LCD_CheckType RetVal ;
	RetVal=LCD_SendCommand(GroupId,0x80) ;
	return RetVal;	
}

LCD_CheckType LCD_GoToSecondLine(uint8_t GroupId)
{
	LCD_CheckType RetVal ;
	RetVal=LCD_SendCommand(GroupId,0xC0) ;
	return RetVal;
}
