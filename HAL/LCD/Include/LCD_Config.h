/*******************************************************************************
* Filename              :   LCD_Config.h
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
#ifndef LCD_INCLUDE_LCD_CONFIG_H_
#define LCD_INCLUDE_LCD_CONFIG_H_

#define LCD_DATA_PORT           PORTB

#define LCD_DATA_PIN4           PIN15

#define LCD_DATA_PIN5           PIN14

#define LCD_DATA_PIN6           PIN13

#define LCD_DATA_PIN7           PIN12

#define LCD_CTRL_PORT           PORTA

#define LCD_RS_PIN              PIN11

#define LCD_E_PIN               PIN8



/* 1-> DISPLAY_ENABLE
 * 2-> DISPLAY_DISABLE
 */

#define DISPLAY  DISPLAY_ENABLE

/* 1-> CURSOR_ENABLE
 * 2-> CURSOR_DISABLE
 */


#define CURSOR  CURSOR_DISABLE


/* 1-> BLINK_ENABLE
 * 2-> BLINK_DISABLE
 */

#define BLINK_CURSOR  BLINK_DISABLE



/* 1-> ONE_LINE
 * 2-> TWO_LINES
 */

#define NUMBER_OF_LINES  TWO_LINES


/* 1-> FONT_5x8
 * 2-> FONT_5x11
 */
#define FONT_SIZE FONT_5x11


#endif /* LCD_INCLUDE_LCD_CONFIG_H_ */
