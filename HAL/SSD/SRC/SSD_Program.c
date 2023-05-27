/*******************************************************************************
 * Filename              :   SSD_Program.c
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
#include "../../../MCAL/GPIO/Include/GPIO_Interface.h"
#include "../Include/SSD_Interface.h"
#include "../Include/SSD_Config.h"
#include "../Include/SSD_Private.h"

static void (*DisplayNum[10])(void) = {
	&DisplayZero, &DisplayOne, &DisplayTwo, &DisplayThree, &DisplayFour, &DisplayFive, &DisplaySix,
	&DisplaySeven, &DisplayEight, &DisplayNine};
/*==============================================================================================================================================
 * Function Definitions
 *==============================================================================================================================================*/
/*
 * Prototype   : void SSD_Init(SSD_ID ID);
 * Description : Initialize the SSD
 * Arguments   : SSD_ID ID
 * return      : void
 */
void SSD_Init(SSD_ID ID)
{
	Pin_Config_t A = {.Port = A_PORT, .PinNum = A_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t B = {.Port = B_PORT, .PinNum = B_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t C = {.Port = C_PORT, .PinNum = C_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t D = {.Port = D_PORT, .PinNum = D_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t E = {.Port = E_PORT, .PinNum = E_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t F = {.Port = F_PORT, .PinNum = F_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t G = {.Port = G_PORT, .PinNum = G_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	Pin_Config_t CM = {.Port = COM1_PORT, .PinNum = COM1_PIN, .OutputMode = PushPull, .Mode = Output_10MHZ};

	if (ID == SSD2)
	{
		CM.Port = COM2_PORT;
		CM.PinNum = COM2_PIN;
	}
	else if (ID == SSD3)
	{
		CM.Port = COM3_PORT;
		CM.PinNum = COM3_PIN;
	}
	GPIO_u8PinInit(&A);

	GPIO_u8PinInit(&B);

	GPIO_u8PinInit(&C);

	GPIO_u8PinInit(&D);

	GPIO_u8PinInit(&E);

	GPIO_u8PinInit(&F);

	GPIO_u8PinInit(&G);

	GPIO_u8PinInit(&CM);
}
/*
 * Prototype   : void SSD_DisplayNumber(SSD_ID ID,uint8_t Copy_u8Number);
 * Description : Display a number on the SSD
 * Arguments   : SSD_ID ID,uint8_t Copy_u8Number
 * return      : void
 */
void SSD_DisplayNumber(SSD_ID ID, uint8_t Copy_u8Number)
{
	if (ID == SSD1)
	{
		GPIO_u8SetPinValue(COM1_PORT, COM1_PIN, PinHigh);
		GPIO_u8SetPinValue(COM2_PORT, COM2_PIN, PinLow);
		GPIO_u8SetPinValue(COM3_PORT, COM3_PIN, PinLow);
	}
	else if (ID == SSD2)
	{
		GPIO_u8SetPinValue(COM1_PORT, COM1_PIN, PinLow);
		GPIO_u8SetPinValue(COM2_PORT, COM2_PIN, PinHigh);
		GPIO_u8SetPinValue(COM3_PORT, COM3_PIN, PinLow);
	}
	else if (ID == SSD3)
	{
		GPIO_u8SetPinValue(COM1_PORT, COM1_PIN, PinLow);
		GPIO_u8SetPinValue(COM2_PORT, COM2_PIN, PinLow);
		GPIO_u8SetPinValue(COM3_PORT, COM3_PIN, PinHigh);
	}
	DisplayNum[Copy_u8Number]();
}
/*==============================================================================================================================================
 * Static Function
 *==============================================================================================================================================*/
static void DisplayZero(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinHigh);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinHigh);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinLow);
}
static void DisplayOne(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinLow);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinLow);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinLow);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinLow);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinLow);
}
static void DisplayTwo(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinLow);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinHigh);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinLow);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
static void DisplayThree(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinLow);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinLow);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
static void DisplayFour(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinLow);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinLow);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinLow);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinHigh);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
static void DisplayFive(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinLow);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinLow);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinHigh);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
static void DisplaySix(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinLow);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinHigh);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinHigh);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
static void DisplaySeven(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinLow);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinLow);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinLow);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinLow);
}
static void DisplayEight(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinHigh);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinHigh);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
static void DisplayNine(void)
{
	GPIO_u8SetPinValue(A_PORT, A_PIN, PinHigh);
	GPIO_u8SetPinValue(B_PORT, B_PIN, PinHigh);
	GPIO_u8SetPinValue(C_PORT, C_PIN, PinHigh);
	GPIO_u8SetPinValue(D_PORT, D_PIN, PinHigh);
	GPIO_u8SetPinValue(E_PORT, E_PIN, PinLow);
	GPIO_u8SetPinValue(F_PORT, F_PIN, PinHigh);
	GPIO_u8SetPinValue(G_PORT, G_PIN, PinHigh);
}
