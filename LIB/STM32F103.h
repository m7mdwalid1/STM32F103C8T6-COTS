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

/*******************  USART BASE Address Definition    *********************/

#define USART1_BASE_ADDRESS     0x40013800UL
#define USART2_BASE_ADDRESS     0x40004400UL
#define USART3_BASE_ADDRESS     0x40004800UL
#define UART4_BASE_ADDRESS      0x40004C00UL
#define UART5_BASE_ADDRESS      0x40005000UL



#define USART1 ((USART_REG_t *)USART1_BASE_ADDRESS)

#define USART2 ((USART_REG_t *)USART2_BASE_ADDRESS)

#define USART3 ((USART_REG_t *)USART3_BASE_ADDRESS)

#define UART4 ((USART_REG_t *)UART4_BASE_ADDRESS)

#define UART5 ((USART_REG_t *)UART5_BASE_ADDRESS)







/*******************  USART Register Definition        ********************/
typedef struct
{
	volatile uint32_t SR;	  // USART Status register
	volatile uint32_t DR;	  // USART Data register
	volatile uint32_t BRR;  // USART Baud rate register
	volatile uint32_t CR1;  // USART Control register 1
	volatile uint32_t CR2;  // USART Control register 2
	volatile uint32_t CR3;  // USART Control register 3
	volatile uint32_t GTPR; // USART Guard time and prescaler register
} USART_REG_t;
typedef enum
{
	SR_PE = 0,	 // Parity error
	SR_FE = 1,	 // Framing error
	SR_NE = 2,	 // Noise detected flag
	SR_ORE = 3,	 // Overrun error
	SR_IDLE = 4, // IDLE line detected
	SR_RXNE = 5, // Read data register not empty
	SR_TC = 6,	 // Transmission complete
	SR_TXE = 7,	 // Transmit data register empty
	SR_LBD = 8,	 // LIN break detection flag
	SR_CTS = 9	 // CTS flag
} USART_SR_t;
typedef enum
{
	CR1_SBK = 0,	// Send break
	CR1_RWU = 1,	// Receiver wakeup
	CR1_RE = 2,		// Receiver enable
	CR1_TE = 3,		// Transmitter enable
	CR1_IDLEIE = 4, // IDLE interrupt enable
	CR1_RXNEIE = 5, // RXNE interrupt enable
	CR1_TCIE = 6,	// Transmission complete interrupt enable
	CR1_TXEIE = 7,	// TXE interrupt enable
	CR1_PEIE = 8,	// PE interrupt enable
	CR1_PS = 9,		// Parity selection
	CR1_PCE = 10,	// Parity control enable
	CR1_WAKE = 11,	// Wakeup method
	CR1_M = 12,		// Word length
	CR1_UE = 13		// USART enable
} USART_CR1_t;
typedef enum
{
	CR2_ADD = 0,	// Address of the USART node
	CR2_LBDL = 5,	// LIN break detection length
	CR2_LBDIE = 6,	// LIN break detection interrupt enable
	CR2_LBCL = 8,	// Last bit clock pulse
	CR2_CPHA = 9,	// Clock phase
	CR2_CPOL = 10,	// Clock polarity
	CR2_CLKEN = 11, // Clock enable
	CR2_STOP = 12,	// STOP bits
	CR2_LINEN = 14	// LIN mode enable
} USART_CR2_t;
typedef enum
{
	CR3_EIE = 0,	// Error interrupt enable
	CR3_IREN = 1,	// IrDA mode enable
	CR3_IRLP = 2,	// IrDA low-power
	CR3_HDSEL = 3,	// Half-duplex selection
	CR3_NACK = 4,	// Smartcard NACK enable
	CR3_SCEN = 5,	// Smartcard mode enable
	CR3_DMAR = 6,	// DMA enable receiver
	CR3_DMAT = 7,	// DMA enable transmitter
	CR3_RTSE = 8,	// RTS enable
	CR3_CTSE = 9,	// CTS enable
	CR3_CTSIE = 10, // CTS interrupt enable
} USART_CR3_t;
typedef enum
{
  BRR_DIV_Fraction = 0, // fraction of USARTDIV
  BRR_DIV_Mantissa = 4, // mantissa of USARTDIV
} USART_BRR_BITS_t;
typedef enum
{
	GTPR_PSC = 0, // Prescaler value
	GTPR_GT = 8	  // Guard time value
} USART_GTPR_t;

#endif /* STM32F103_H_ */
