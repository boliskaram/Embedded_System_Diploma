/*
 * STM32F103x6.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

#include "stdlib.h"
#include "stdint.h"

//-------------------------------
// Base Addresses For Memories
//-------------------------------

#define FLASH_Memory_BASE 						0x08000000UL
#define System_Memory_BASE 						0x1FFFF000UL
#define SRAM_Memory_BASE 						0x20000000UL
#define peripherals_BASE 						0x40000000UL
#define	Cortex_M3_Internal_Peripherals_BASE		0xE0000000UL

#define NVIC_BASE								0xE000E100UL

#define NVIC_ISER0			*(volatile uint32_t*)(NVIC_BASE + 0x00)
#define NVIC_ISER1			*(volatile uint32_t*)(NVIC_BASE + 0x04)
#define NVIC_ISER2			*(volatile uint32_t*)(NVIC_BASE + 0x08)
#define NVIC_ICER0			*(volatile uint32_t*)(NVIC_BASE + 0x80)
#define NVIC_ICER1			*(volatile uint32_t*)(NVIC_BASE + 0x84)
#define NVIC_ICER2			*(volatile uint32_t*)(NVIC_BASE + 0x88)


//------------------------------------
// Base Addresses for AHB peripherals
//------------------------------------

//RCC Address
#define RCC_BASE 								0x40021000

//UART2 Address
#define USART2_BASE							 	0x40004400

//UART3 Address
#define USART3_BASE							 	0x40004800

//------------------------------------
// Base Addresses for APB2 peripherals
//------------------------------------

//GPIO Address
//A,B fully included in LQFP48 Package
#define GPIOA_BASE								0x40010800
#define GPIOB_BASE								0x40010C00
//C,D partial included in LQFP48 Package
#define GPIOC_BASE								0x40011000
#define GPIOD_BASE								0x40011400
//E not included in LQFP48 Package
#define GPIOE_BASE								0x40011800

//AFIO Address
#define AFIO_BASE								0x40010000

//EXTI Address
#define EXTI_BASE								0x40010400

//UART1 Address
#define USART1_BASE							 	0x40013800


//SPI1 Address
#define SPI1_BASE							 	0x40013000
//SPI2 Address
#define SPI2_BASE							 	0x40003800

//=====================================================================================
//------------------------------------
// Peripheral Register
//------------------------------------

//GPIO Registers
typedef struct{
	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR ;

}GPIO_Typedef;

//RCC Registers
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_Typedef;

//AFIO Registers
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	volatile uint32_t Reserved;
	volatile uint32_t MAPR2;
}AFIO_Typedef;

//EXTI Registers
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_Typedef;

//UART Registers
typedef struct{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_Typedef;

//SPI Registers
typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_Typedef;
//=====================================================================================
//------------------------------------
//Peripheral Instants
//------------------------------------

//GPIO Instant
#define GPIOA			((GPIO_Typedef *) GPIOA_BASE)
#define GPIOB           ((GPIO_Typedef *) GPIOB_BASE)
#define GPIOC   		((GPIO_Typedef *) GPIOC_BASE)
#define GPIOD 			((GPIO_Typedef *) GPIOD_BASE)
#define GPIOE			((GPIO_Typedef *) GPIOE_BASE)

//RCC Instant
#define RCC				((RCC_Typedef *) RCC_BASE)

//AFIO Instant
#define AFIO            ((AFIO_Typedef *) AFIO_BASE)

//EXTI Instant
#define EXTI            ((EXTI_Typedef *) EXTI_BASE)

//UART Instant
#define USART1			((USART_Typedef *) USART1_BASE)
#define USART2			((USART_Typedef *) USART2_BASE)
#define USART3			((USART_Typedef *) USART3_BASE)


//SPI Instant
#define SPI1			((SPI_Typedef *) SPI1_BASE)
#define SPI2			((SPI_Typedef *) SPI2_BASE)
//=====================================================================================
//------------------------------------
//clock enable Macros:
//------------------------------------

//GPIO Enable Clock
#define RCC_EN_CLK_GPIOA()	(RCC->APB2ENR |= 1<<2)
#define RCC_EN_CLK_GPIOB() 	(RCC->APB2ENR |= 1<<3)
#define RCC_EN_CLK_GPIOC() 	(RCC->APB2ENR |= 1<<4)
#define RCC_EN_CLK_GPIOD()	(RCC->APB2ENR |= 1<<5)
#define RCC_EN_CLK_GPIOE() 	(RCC->APB2ENR |= 1<<6)

//AFIO Enable Clock
#define RCC_EN_CLK_AFIO() 	(RCC->APB2ENR |= 1<<0)

//USART1 Enable Clock
#define RCC_EN_CLK_USART1() (RCC->APB2ENR |= (1<<14))
//USART2 Enable Clock
#define RCC_EN_CLK_USART2() (RCC->APB1ENR |= (1<<17))
//USART3 Enable Clock
#define RCC_EN_CLK_USART3() (RCC->APB1ENR |= (1<<18))


//USART1 Reset
#define RCC_Reset_USART1() (RCC->APB2RSTR |= (1<<14))
//USART2 Reset
#define RCC_Reset_USART2() (RCC->APB1RSTR |= (1<<17))
//USART3 Reset
#define RCC_Reset_USART3() (RCC->APB1RSTR |= (1<<18))


//SPI1 Enable Clock
#define RCC_EN_CLK_SPI1() (RCC->APB2ENR |= (1<<12))
//SPI2 Enable Clock
#define RCC_EN_CLK_SPI2() (RCC->APB1ENR |= (1<<14))

//SPI1 Reset
#define RCC_Reset_SPI1() (RCC->APB2RSTR |= (1<<12))
//SPI2 Reset
#define RCC_Reset_SPI2() (RCC->APB1RSTR |= (1<<14))

//===============================================================
// IVT
//===================================
//EXTI

#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40

#define USART1_IRQ  37
#define USART2_IRQ  38
#define USART3_IRQ  39

#define SPI1_IRQ  	35
#define SPI2_IRQ  	36
//======================================
// NVIC IRQ enable/disable Macros:
//======================================

//EXTI
//ENABLE
#define NVIC_IRQ6_EXTI0_EN			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_EN			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_EN			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_EN			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_EN			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_EN		(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_EN		(NVIC_ISER1 |= 1<<8)
//DISABLE
#define NVIC_IRQ6_EXTI0_Disable			(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable			(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable			(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable			(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable		(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable		(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1 |= 1<<8)

//USART
//ENABLE
#define NVIC_IRQ37_USART1_EN			(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_EN			(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_EN			(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))

//DISABLE
#define NVIC_IRQ37_USART1_Disable			(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_Disable			(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_Disable			(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))


//SPI
//ENABLE
#define NVIC_IRQ35_SPI1_EN			(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_EN			(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))

//DISABLE
#define NVIC_IRQ35_SPI1_Disable			(NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_Disable			(NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))

#endif /* INC_STM32F103X6_H_ */
