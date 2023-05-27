/*******************************************************************************
 * Filename              :   LCD_Program.c
 * Author                :   Mohamemd Waleed Gad
 * Origin Date           :   May 11, 2023
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :   None
 **
 *******************************************************************************/
/************************ SOURCE REVISION LOG *********************************
 *
 *    Date    Version   Author             Description
 *  14/10/20   1.0.0   Mohamemd Waleed   Initial Release.
 *
 *******************************************************************************/
#include <stdint.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../MCAL/GPIO/Include/GPIO_Interface.h"
#include "../../../MCAL/RCC/Include/RCC_Interface.h"
#include "../Include/LCD_Interface.h"
#include "../Include/LCD_Config.h"
#include "../Include/LCD_Private.h"
#include "../../../MCAL/SysTick/Include/SysTick_Interface.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Prototype   : void LCD_voidInit(void);
 * Description : Initialize LCD
 * Arguments   : void
 * return      : void
 */
void LCD_voidInit(void)
{
	/* Display ON/OFF Control */
	uint8_t DISPLAY_ON_OFF_CONTROL = 0x08 ;

	/* Function Set */
	uint8_t FUNCTION_SET_4BIT = 0x20 ;
	/* Initialize Pins */
	GPIO_u8PinInit(&RS);
	GPIO_u8PinInit(&E);
	GPIO_u8PinInit(&D4);
	GPIO_u8PinInit(&D5);
	GPIO_u8PinInit(&D6);
	GPIO_u8PinInit(&D7);
	/* Wait for more than 30 ms */
	SysTick_Delay_ms(30);

	/*FUNCTION SET 4 BIT INTIALIZATION*/
	#if NUMBER_OF_LINES == ONE_LINE
		CLEAR_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
	#elif NUMBER_OF_LINES == TWO_LINES
		SET_BIT( FUNCTION_SET_4BIT , NUMBER_OF_LINES_BIT ) ;
	#endif

	#if FONT_SIZE == FONT_5x8
		CLEAR_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
	#elif FONT_SIZE == FONT_5x11
		SET_BIT( FUNCTION_SET_4BIT , FONT_SIZE_BIT ) ;
	#endif

		LCD_voidSendCommand(0b00100000);
		LCD_voidSendCommand(FUNCTION_SET_4BIT);

		/*Display ON/OFF Control*/

	#if DISPLAY == DISPLAY_ENABLE
		SET_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
	#elif DISPLAY == DISPLAY_DISABLE
		CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , DISPLAY_BIT );
	#endif

	#if CURSOR == CURSOR_DISABLE
		CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
	#elif CURSOR == CURSOR_ENABLE
		SET_BIT( DISPLAY_ON_OFF_CONTROL , CURSOR_BIT );
	#endif

	#if BLINK_CURSOR == BLINK_DISABLE
		CLEAR_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
	#elif BLINK_CURSOR == BLINK_ENABLE
		SET_BIT( DISPLAY_ON_OFF_CONTROL , BLINK_BIT );
	#endif

		LCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);

		/*Clear Display*/
		LCD_voidSendCommand(CLCD_CLEAR_DISPLAY);

		/*Return Cursor Home*/
		LCD_voidSendCommand(CLCD_RETURN_HOME);

		SysTick_Delay_ms(2);

}
/*
 * Prototype   : void LCD_voidSendCommand(uint8_t Local_u8Command);
 * Description : Send command to LCD
 * Arguments   : uint8_t Local_u8Command
 * return      : void
 */
void LCD_voidSendCommand(uint8_t Local_u8Command)
{
	/* Mirroring Commands */
	uint8_t Counter=0 , Command_Reversed=0,Bit=0;
	for (Counter=0;Counter<8;Counter++)
	{

		Bit = GET_BIT(Local_u8Command,Counter);
		if(Bit==1)
			SET_BIT(Command_Reversed,(7-Counter));
		else if (Bit==0)
			CLR_BIT(Command_Reversed,(7-Counter));

	}
	/*set RS pin to low for command*/
	GPIO_u8SetPinValue(RS.Port, RS.PinNum, PinLow);

	/*send command to data pins*/
	GPIO_u8SetFourPortValue(PORTB, PIN12, (Command_Reversed & 0x0F));

	/*send enable pulse*/
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinHigh);
	SysTick_Delay_ms(2);
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinLow);

	SysTick_Delay_us(200);

	/*send command to data pins*/

	GPIO_u8SetFourPortValue(PORTB, PIN12, ((Command_Reversed >> 4) & 0x0F));
	/*send enable pulse*/
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinHigh);
	SysTick_Delay_ms(2);
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinLow);
}
/*
 * Prototype   : void LCD_voidSendData(uint8_t Local_u8Data);
 * Description : Send data to LCD
 * Arguments   : uint8_t Local_u8Data
 * return      : void
 */
void LCD_voidSendData(uint8_t Local_u8Data)
{
	uint8_t Counter=0 , Command_Reversed=0,Bit=0;
	for (Counter=0;Counter<8;Counter++)
	{
		Bit = GET_BIT(Local_u8Data,Counter);
		if(Bit==1)
			SET_BIT(Command_Reversed,(7-Counter));
		else if (Bit==0)
			CLR_BIT(Command_Reversed,(7-Counter));
	}
	/*set RS pin to low for command*/
	GPIO_u8SetPinValue(RS.Port, RS.PinNum, PinHigh);

	/*send Data to data pins*/
	GPIO_u8SetFourPortValue(PORTB, PIN12, (Command_Reversed & 0x0F));
	/*send enable pulse*/
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinHigh);
	SysTick_Delay_ms(2);
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinLow);

	/*send Data to data pins*/
	GPIO_u8SetFourPortValue(PORTB, PIN12, ((Command_Reversed >> 4) & 0x0F));
	/*send enable pulse*/
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinHigh);
	SysTick_Delay_ms(2);
	GPIO_u8SetPinValue(E.Port, E.PinNum, PinLow);
}
/*
 * Prototype   : void LCD_voidSendString(const char *Local_String);
 * Description : Send string to LCD
 * Arguments   : const char *Local_String
 * return      : void
 */
void LCD_voidSendString(const char *Local_String)
{
	uint8_t Local_counter=0;
	while(Local_String[Local_counter]!='\0')
	{
		LCD_voidSendData(Local_String[Local_counter]);
		Local_counter++;
	}

}
/*
 * Prototype   : void LCD_voidGoToXY(uint8_t Local_u8XPos, uint8_t Local_u8YPos);
 * Description : Go to specific position in LCD
 * Arguments   : uint8_t Local_u8XPos, uint8_t Local_u8YPos
 * return      : void
 */
void LCD_voidGoToXY(uint8_t Local_u8XPos, uint8_t Local_u8YPos)
{
	uint8_t Local_u8Address =0 ;
	if(Local_u8XPos == 0 )
	{
		Local_u8Address = Local_u8YPos ;
	}
	else if (Local_u8XPos == 1)
	{
		Local_u8Address = Local_u8YPos +0x40 ;  // or +64 in decimal
	}
	LCD_voidSendCommand(Local_u8Address+128);    // 1000 0000 = 128
}
/*
 * Prototype   : void LCD_WriteSpecialChar(uint8_t *Local_u8Pattern, uint8_t Local_u8PatternNumber, uint8_t Local_u8XPos, uint8_t Local_u8YPos);
 * Description : Write special character in LCD
 * Arguments   : uint8_t *Local_u8Pattern, uint8_t Local_u8PatternNumber, uint8_t Local_u8XPos, uint8_t Local_u8YPos
 * return      : void
 */
void LCD_WriteSpecialChar(uint8_t *Local_u8Pattern, uint8_t Local_u8PatternNumber, uint8_t Local_u8XPos, uint8_t Local_u8YPos)
{
	uint8_t Local_u8CGRAMAddress=0,Local_u8Iterator=0;
	/*calculate cgram address whose each block is 8 bytes*/
	Local_u8CGRAMAddress=Local_u8PatternNumber*8;
	/*send cgram command to lcd ith set bitting 6 , clearing bit 7 */
	LCD_voidSendCommand(Local_u8CGRAMAddress+64);
	/*write a pattern into cgram*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		LCD_voidSendData(Local_u8Pattern[Local_u8Iterator]);
	}
	/*go back to ddram*/
	LCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
	/*display the pattern written in CGram*/
	LCD_voidSendData(Local_u8PatternNumber);
}
/*
 * Prototype   : void LCD_voidSendNumber(int32_t Local_S32Number);
 * Description : Send number to LCD
 * Arguments   : int32_t Local_S32Number
 * return      : void
 */
void LCD_VoidSendNumber(int32_t Local_S32Number)
{
	int32_t Local_S32Nu = 1;
	if(Local_S32Number == 0)
	{
		LCD_voidSendData('0');
	}
	else if(Local_S32Number <0)
	{
		LCD_voidSendData('-');
		Local_S32Number *=-1 ;
	}
	while(Local_S32Number != 0)
	{
		Local_S32Nu = ((Local_S32Nu * 10) + (Local_S32Number % 10));
		Local_S32Number = (Local_S32Number / 10);
	}
	while(Local_S32Nu !=1 )
	{
		LCD_voidSendData((Local_S32Nu % 10) + 48);
		Local_S32Nu = (Local_S32Nu/10);
	}

}
/*
 * Prototype   : void LCD_voidShiftLeft(void);
 * Description : Shift left
 * Arguments   : void
 * return      : void
 */
void LCD_ShiftLeft(void)
{
	LCD_voidSendCommand(0b00011000);
}
/*
 * Prototype   : void LCD_voidShiftRight(void);
 * Description : Shift right
 * Arguments   : void
 * return      : void
 */
void LCD_ShiftRight(void)
{
	LCD_voidSendCommand(0b00011100);
}
/*
 * Prototype   : void LCD_voidClear(void);
 * Description : Clear LCD
 * Arguments   : void
 * return      : void
 */
void LCD_voidClear(void)
{
	LCD_voidSendCommand(0b00000001);
}
/*
 * Prototype   : void LCD_voidCursorOn(void);
 * Description : Turn on cursor
 * Arguments   : void
 * return      : void
 */
void LCD_voidCursorOn(void);
/*
 * Prototype   : void LCD_voidCursorOff(void);
 * Description : Turn off cursor
 * Arguments   : void
 * return      : void
 */
void LCD_voidCursorOff(void)
{
	LCD_voidSendCommand(0b00001100);
}
/*
 * Prototype   : void LCD_voidBlinkOn(void);
 * Description : Turn on blink
 * Arguments   : void
 * return      : void
 */
void LCD_voidBlinkOn(void)
{
	LCD_voidSendCommand(0b00001111);
}
/*
 * Prototype   : void LCD_voidBlinkOff(void);
 * Description : Turn off blink
 * Arguments   : void
 * return      : void
 */
void LCD_voidBlinkOff(void)
{
	LCD_voidSendCommand(0b00001100);
}
