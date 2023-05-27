/*******************************************************************************
 * Filename              :   LCD_Interface.h
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
#ifndef LCD_INCLUDE_LCD_INTERFACE_H_
#define LCD_INCLUDE_LCD_INTERFACE_H_

typedef struct
{
    Pin_Config_t RS;
    Pin_Config_t E;
    Pin_Config_t D[4];
} LCD_PINS_t;
/*******************************************************************************
 *                      Function Decleration                                   *
 *******************************************************************************/
/*
*/
/*
 * Prototype   : void LCD_voidSendCommand(uint8_t Local_u8Command);
 * Description : Send command to LCD
 * Arguments   : uint8_t Local_u8Command
 * return      : void
 */
void LCD_voidSendCommand(uint8_t Local_u8Command);
/*
 * Prototype   : void LCD_voidSendData(uint8_t Local_u8Data);
 * Description : Send data to LCD
 * Arguments   : uint8_t Local_u8Data
 * return      : void
 */
void LCD_voidSendData(uint8_t Local_u8Data);
/*
 * Prototype   : void LCD_voidInit(void);
 * Description : Initialize LCD
 * Arguments   : void
 * return      : void
 */
void LCD_voidInit(void);
/*
 * Prototype   : void LCD_voidSendString(const char *Local_String);
 * Description : Send string to LCD
 * Arguments   : const char *Local_String
 * return      : void
 */
void LCD_voidSendString(const char *Local_String);
/*
 * Prototype   : void LCD_voidGoToXY(uint8_t Local_u8XPos, uint8_t Local_u8YPos);
 * Description : Go to specific position in LCD
 * Arguments   : uint8_t Local_u8XPos, uint8_t Local_u8YPos
 * return      : void
 */
void LCD_voidGoToXY(uint8_t Local_u8XPos, uint8_t Local_u8YPos);
/*
 * Prototype   : void LCD_WriteSpecialChar(uint8_t *Local_u8Pattern, uint8_t Local_u8PatternNumber, uint8_t Local_u8XPos, uint8_t Local_u8YPos);
 * Description : Write special character in LCD
 * Arguments   : uint8_t *Local_u8Pattern, uint8_t Local_u8PatternNumber, uint8_t Local_u8XPos, uint8_t Local_u8YPos
 * return      : void
 */
void LCD_WriteSpecialChar(uint8_t *Local_u8Pattern, uint8_t Local_u8PatternNumber, uint8_t Local_u8XPos, uint8_t Local_u8YPos);
/*
 * Prototype   : void LCD_VoidSendNumber(int32_t Local_S32Number);
 * Description : Send number to LCD
 * Arguments   : int32_t Local_S32Number
 * return      : void
 */
void LCD_VoidSendNumber(int32_t Local_S32Number);
/*
 * Prototype   : void LCD_voidClear(void);
 * Description : Clear LCD
 * Arguments   : void
 * return      : void
 */
void LCD_voidClear(void);
/*
 * Prototype   : void LCD_voidShiftLeft(void);
 * Description : Shift LCD to left
 * Arguments   : void
 * return      : void
 */
void LCD_ShiftLeft(void);
/*
 * Prototype   : void LCD_voidShiftRight(void);
 * Description : Shift LCD to right
 * Arguments   : void
 * return      : void
 */
void LCD_ShiftRight(void);
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
void LCD_voidCursorOff(void);
/*
 * Prototype   : void LCD_voidBlinkOn(void);
 * Description : Turn on blink
 * Arguments   : void
 * return      : void
 */
void LCD_voidBlinkOn(void);
/*
 * Prototype   : void LCD_voidBlinkOff(void);
 * Description : Turn off blink
 * Arguments   : void
 * return      : void
 */
void LCD_voidBlinkOff(void);


#endif /* LCD_INCLUDE_LCD_INTERFACE_H_ */
