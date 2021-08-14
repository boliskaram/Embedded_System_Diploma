/*
 * stm32f103x6.h
 *
 *  Created on: Aug 8, 2021
 *      Author: Bolis
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-------------------------------
//Includes
//-------------------------------

#include "stdlib.h"
#include <stdint.h>

//=====================================================================================
//-------------------------------
// Base Addresses For Memories
//-------------------------------

#define FLASH_Memory_BASE 						0x08000000UL
#define System_Memory_BASE 						0x1FFFF000UL
#define SRAM_Memory_BASE 						0x20000000UL
#define peripherals_BASE 						0x40000000UL
#define	Cortex_M3_Internal_Peripherals_BASE		0xE0000000UL

//------------------------------------
// Base Addresses for AHB peripherals
//------------------------------------

//RCC Address
#define RCC_BASE 								0x40021000

//------------------------------------
// Base Addresses for APB2 peripherals
//------------------------------------

//GPIO Address
//A,B fully included in LQFP48 Package
#define GPIOA_BASE								0x40010800
#define GPIOB_BASE								0x40010c00
//C,D partial included in LQFP48 Package
#define GPIOC_BASE								0x40011000
#define GPIOD_BASE								0x40011400
//E not included in LQFP48 Package
#define GPIOE_BASE								0x40011800


//AFIO Address
#define AFIO_BASE 								0x40010000

//EXTI Address
#define EXTI_BASE 								0x40010400

//------------------------------------
// Base Addresses for APB1 peripherals
//------------------------------------

//=====================================================================================
//------------------------------------
// Peripheral Register
//------------------------------------

//GPIO Registers
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

//AFIO Registers
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t Reserved;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;

//EXTI Registers
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//RCC Registers
typedef struct
{
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
}RCC_TypeDef;

//=====================================================================================
//------------------------------------
//Peripheral Instants
//------------------------------------

//GPIO Instant
#define GPIOA  			((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB           ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   		((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD 			((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef *) GPIOE_BASE)

//AFIO Instant
#define AFIO			((AFIO_TypeDef *) AFIO_BASE)

//EXTI Instant
#define EXTI 			((EXTI_TypeDef *) EXTI_BASE)

//RCC Instant
#define RCC				((RCC_TypeDef *)RCC_BASE)

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


#endif /* INC_STM32F103X6_H_ */
