/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "stm32f103c6_RCC_driver.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_I2C_driver.h"
#include "I2C_Slave_EEPROM.h"

int main(void)
		{
	eeprom_init();

	unsigned char data1[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	unsigned char data2[7]={0};


	eeprom_write_Nbytes(0xAF, data1, 7);
	eeprom_read_Nbytes(0xAF, data2, 7);

	data1[0] = 0xA;
	data1[1] = 0xB;
	data1[2] = 0xC;
	data1[3] = 0xD;

	eeprom_write_Nbytes(0xFFF, data1, 4);
	eeprom_read_Nbytes(0xFFF, data2, 4);

	for(;;);

}