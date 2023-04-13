/*******************************************************************************
 * Filename              :   RCC_Register.h
 * Author                :   Mohamemd Waleed Gad
 * Origin Date           :   13/4/2023
 * Version               :   1.0.0
 * Compiler              :   GCC ARM Embedded Toolchain
 * Target                :
 * Notes                 :   None
 **
 *******************************************************************************/
/************************ SOURCE REVISION LOG *********************************
 *
 *    Date    Version   Author             Description
 *  13/10/20   1.0.0   Mohamemd Waleed   Initial Release.
 *
 *******************************************************************************/

#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_

/*******************   Register Definition        ********************/
typedef struct {
	volatile uint32_t RCC_CR       ;
	volatile uint32_t RCC_CFGR     ;
	volatile uint32_t RCC_CIR      ;
	volatile uint32_t RCC_APB2RSTR ;
	volatile uint32_t RCC_APB1RSTR ;
	volatile uint32_t RCC_AHBENR   ;
	volatile uint32_t RCC_APB2ENR  ;
	volatile uint32_t RCC_APB1ENR  ;
	volatile uint32_t RCC_BDCR     ;
	volatile uint32_t RCC_CSR      ;
}RCC_REG_t;

/*******************   BASE Address Definition    *********************/
/* Defining Base Address Of RCC */
#define RCC_BASE_ADDRESS	0x40021000

#define RCC ( (volatile RCC_REG_t *) RCC_BASE_ADDRESS)

/*==============================================================================================================================================
 * Clock Control Register definition (CR)
 *==============================================================================================================================================*/

#define CR_PLLRDY             25             // PLL Ready flag
#define CR_PLLON              24             // PLL Enable
#define CR_CSSON              19             // Clock security system enable
#define CR_HSEBYP             18             // HSE Bypass on
#define CR_HSERDY             17             // HSE Ready flag
#define CR_HSEON              16             // HSE Enable
#define CR_HSIRDY             1              // HSI Ready flag
#define CR_HSION              0              // HSI Enable
/*==============================================================================================================================================
 * Clock Configuration Register definition (CFGR)
 *==============================================================================================================================================*/
#define CFGR_USBPRE                   22       // USB prescaler
#define CFGR_PLLMUL                   18       // PLL multiplication factor
#define CFGR_PLLXTPRE                 17       // HSE divider for PLL entry
#define CFGR_PLLSRC                   16       // PLL entry clock source



#endif /* RCC_REGISTER_H_ */
