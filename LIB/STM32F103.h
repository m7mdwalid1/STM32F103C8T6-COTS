/*******************************************************************************
 * Filename              :   STM32F103.h
 * Author                :   Mohamemd Waleed Gad
 * Origin Date           :   May 10, 2023
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
#ifndef STM32F103_H_
#define STM32F103_H_

/*******************  RCC Register Definition        ********************/
typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
} RCC_REG_t;

/*******************  RCC BASE Address Definition    *********************/
/* Defining Base Address Of RCC */
#define RCC_BASE_ADDRESS 0x40021000

#define RCC ((RCC_REG_t *)RCC_BASE_ADDRESS)

/*==============================================================================================================================================
 * Clock Control Register definition (CR)
 *==============================================================================================================================================*/

#define CR_PLLRDY 25 // PLL Ready flag
#define CR_PLLON 24	 // PLL Enable
#define CR_CSSON 19	 // Clock security system enable
#define CR_HSEBYP 18 // HSE Bypass on
#define CR_HSERDY 17 // HSE Ready flag
#define CR_HSEON 16	 // HSE Enable
#define CR_HSIRDY 1	 // HSI Ready flag
#define CR_HSION 0	 // HSI Enable
/*==============================================================================================================================================
 * Clock Configuration Register definition (CFGR)
 *==============================================================================================================================================*/
#define CFGR_USBPRE 22	 // USB prescaler
#define CFGR_PLLMUL 18	 // PLL multiplication factor
#define CFGR_PLLXTPRE 17 // HSE divider for PLL entry
#define CFGR_PLLSRC 16	 // PLL entry clock source

/*******************  GPIO Register Definition        ********************/
typedef struct
{
	volatile uint32_t GPIO_CR[2];
	volatile uint32_t GPIO_IDR;
	volatile uint32_t GPIO_ODR;
	volatile uint32_t GPIO_BSRR;
	volatile uint32_t GPIO_BRR;
	volatile uint32_t GPIO_LCKR;
} GPIO_REG_t;

/*******************  GPIO BASE Address Definition    *********************/

#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000

#define GPIOA ((GPIO_REG_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_REG_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_REG_t *)GPIOC_BASE_ADDRESS)

/*******************  SysTick Register Definition        ********************/
typedef struct
{
	volatile uint32_t SYST_CSR;
	volatile uint32_t SYST_RVR;
	volatile uint32_t SYST_CVR;
	volatile uint32_t SYST_CALIB;
} SysTick_REG_t;
#define SYST_CSR_ENABLE 0
#define SYST_CSR_TICKINT 1
#define SYST_CSR_CLKSOURCE 2
#define SYST_CSR_COUNTFLAG 16

#define SYST_RVR_RELOAD 0

#define SYST_CVR_CURRENT 0

/*******************  SysTick BASE Address Definition    *********************/
/* Defining Base Address Of RCC */
#define SysTick_BASE_ADDRESS 0xE000E010

#define SysTick ((SysTick_REG_t *)SysTick_BASE_ADDRESS)

#endif /* STM32F103_H_ */
