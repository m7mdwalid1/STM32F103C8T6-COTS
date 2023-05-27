/*******************************************************************************
 * Filename              :   SSD_Interface.h
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
#ifndef SSD_INCLUDE_SSD_INTERFACE_H_
#define SSD_INCLUDE_SSD_INTERFACE_H_
typedef enum
{
	SSD1,
	SSD2,
	SSD3
} SSD_ID;
/*==============================================================================================================================================
 *  Function Declarations
 *==============================================================================================================================================*/
/*
 * Prototype   : void SSD_Init(SSD_ID ID);
 * Description : Initialize the SSD
 * Arguments   : SSD_ID ID
 * return      : void
 */
void SSD_Init(SSD_ID ID);
/*
 * Prototype   : void SSD_DisplayNumber(SSD_ID ID,uint8_t Copy_u8Number);
 * Description : Display a number on the SSD
 * Arguments   : SSD_ID ID,uint8_t Copy_u8Number
 * return      : void
 */
void SSD_DisplayNumber(SSD_ID ID, uint8_t Copy_u8Number);

#endif /* SSD_INCLUDE_SSD_INTERFACE_H_ */
