/*
 * stm32f103c6_RCC_driver.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#ifndef INC_STM32F103C6_RCC_DRIVER_H_
#define INC_STM32F103C6_RCC_DRIVER_H_

#include "stm32f103x6.h"

#define HSI_RC_CLK 0
#define HSE_CLK 1

uint32_t MCAL_RCC_GetSYSCLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /* INC_STM32F103C6_RCC_DRIVER_H_ */
