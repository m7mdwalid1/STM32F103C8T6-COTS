/*******************************************************************************
* Filename              :   LCD_Private.h
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
#ifndef LCD_INCLUDE_LCD_PRIVATE_H_
#define LCD_INCLUDE_LCD_PRIVATE_H_

static Pin_Config_t RS =
{
		.Port = LCD_CTRL_PORT,
		.PinNum = LCD_RS_PIN,
		.OutputMode = PushPull,
		.Mode=Output_10MHZ,
};

static Pin_Config_t E =
{
		.Port = LCD_CTRL_PORT,
		.PinNum = LCD_E_PIN,
		.OutputMode = PushPull,
		.Mode=Output_10MHZ,
};
static Pin_Config_t D4 =
{
		.Port = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN4,
		.OutputMode = PushPull,
		.Mode=Output_10MHZ,
};
static Pin_Config_t D5 =
{
		.Port = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN5,
		.OutputMode = PushPull,
		.Mode=Output_10MHZ,
};
static Pin_Config_t D6 =
{
		.Port = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN6,
		.OutputMode = PushPull,
		.Mode=Output_10MHZ,
};
static Pin_Config_t D7 =
{
		.Port = LCD_DATA_PORT,
		.PinNum = LCD_DATA_PIN7,
		.OutputMode = PushPull,
		.Mode=Output_10MHZ,
};


/*COMMANDS*/
#define CLCD_CLEAR_DISPLAY ( 0x01 )
#define CLCD_RETURN_HOME   ( 0X02 )
#define SET_DDRAM_ADDRESS  ( 0x80 )
#define SET_CGRAM_ADDRESS  ( 0x40 )



/*SOME VALUES*/
#define SECOND_LINE_START_ADDRESS ( 0x40 )

/*FOR MORE THAN 2 ROWS LCDS */
#define THIRD_LINE_START_ADDRESS  ( 0x14 )
#define FOURTH_LINE_START_ADRESS  ( 0x54 )

#define LOCATION_SIZE_IN_CGRAM        8
#define MAX_NUMBER_OF_DIGITS_IN_S32  10
#define ZERO_ASCII                   48

#define LCD_8BIT_MODE    1
#define LCD_4BIT_MODE    2

#define DISPLAY_ENABLE   1
#define DISPLAY_DISABLE  2

#define CURSOR_ENABLE    1
#define CURSOR_DISABLE   2

#define BLINK_ENABLE     1
#define BLINK_DISABLE    2

#define ONE_LINE         1
#define TWO_LINES  		 2

#define FONT_5x8  		 1
#define FONT_5x11 		 2

#define NUMBER_OF_LINES_BIT   3
#define FONT_SIZE_BIT         2

#define RIGHT_LEFT_SHIFT_BIT  2

#define DISPLAY_BIT 		  2
#define CURSOR_BIT  		  1
#define BLINK_BIT   	      0

#define LCD_16X2  1
#define LCD_20X4  2

#endif /* LCD_INCLUDE_LCD_PRIVATE_H_ */
