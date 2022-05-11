	/*
	 * stm32f103c6_gpio_driver.h
	 *
	 *  Created on: Apr 12, 2022
	 *      Author: Bolis
	 */

	#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
	#define INC_STM32F103C6_GPIO_DRIVER_H_

	#include "stm32f103x6.h"


	typedef struct{

		uint16_t GPIO_PinNumber;			// specifies the GPIO Pins to be configured
											// this parameter can be a value of @ref GPIO_PINS_define
		uint8_t GPIO_Mode;					// specifies the operating mode for the selected pins
											// this parameter can be a value of @ref GPIO_MODE_define
		uint8_t GPIO_OutputSpeed; 			// specifies the speed for the selected pins
											// this parameter can be a value of @ref GPIO_SPEED_define
	}GPIO_PinConfig_t;


	//===================================================================
	//@ref GPIO_PINS_define

	#define GPIO_PIN_0			((uint16_t)0x0001)
	#define GPIO_PIN_1			((uint16_t)0x0002)
	#define GPIO_PIN_2			((uint16_t)0x0004)
	#define GPIO_PIN_3			((uint16_t)0x0008)
	#define GPIO_PIN_4			((uint16_t)0x0010)
	#define GPIO_PIN_5			((uint16_t)0x0020)
	#define GPIO_PIN_6			((uint16_t)0x0040)
	#define GPIO_PIN_7			((uint16_t)0x0080)
	#define GPIO_PIN_8			((uint16_t)0x0100)
	#define GPIO_PIN_9			((uint16_t)0x0200)
	#define GPIO_PIN_10			((uint16_t)0x0400)
	#define GPIO_PIN_11			((uint16_t)0x0800)
	#define GPIO_PIN_12			((uint16_t)0x1000)
	#define GPIO_PIN_13			((uint16_t)0x2000)
	#define GPIO_PIN_14			((uint16_t)0x4000)
	#define GPIO_PIN_15			((uint16_t)0x8000)

	//====================================================================
	//@ref GPIO_MODE_define

	#define GPIO_MODE_ANALOG			0x00000000UL	//0:Analog mode
	#define GPIO_MODE_INPUT_FLO			0x00000001UL	//1:Floating input
	#define GPIO_MODE_INPUT_PU			0x00000002UL	//2:Input with pull-up
	#define GPIO_MODE_INPUT_PD			0x00000003UL	//3:Input with pull-down
	#define GPIO_MODE_OUTPUT_PP			0x00000004UL	//4:Output with push_pull
	#define GPIO_MODE_OUTPUT_OD			0x00000005UL	//5:Output with open_drain
	#define GPIO_MODE_OUTPUT_AF_PP		0x00000006UL	//6:Alternate function output Push-pull
	#define GPIO_MODE_OUTPUT_AF_OD		0x00000007UL	//7:Alternate function output Open_drain
	#define GPIO_MODE_AF_INPUT			0x00000008U		//8: Alternate function input


	//====================================================================
	//@ref GPIO_SPEED_define

	//00: Input mode (reset state)
	//01: Output mode, max speed 10 MHz.
	//10: Output mode, max speed 2 MHz.
	//11: Output mode, max speed 50 MHz.

	#define GPIO_SPEED_10				0x00000001UL  //1:Output mode, max speed 10 MHz.
	#define GPIO_SPEED_2				0x00000002UL  //2:Output mode, max speed 2 MHz.
	#define GPIO_SPEED_50				0x00000003UL  //3:Output mode, max speed 50 MHz.

	//====================================================================

	#define GPIO_PIN_SET		1
	#define GPIO_PIN_RESET		0

	// @ref GPIO_LOCK_Define
	#define GPIO_LOCK_ENABLE 	1
	#define GPIO_LOCK_ERROR		0
	//======================================================================
	//-------------------------------
	// MCAL GPIO Driver APIs
	//-------------------------------

	void MCAL_GPIO_Init(GPIO_Typedef *GPIOx, GPIO_PinConfig_t *PinConfig);
	void MCAL_GPIO_DeInit(GPIO_Typedef *GPIOx);
	uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef *GPIOx, uint16_t PinNumber);
	uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef *GPIOx);
	void MCAL_GPIO_WritePin(GPIO_Typedef *GPIOx, uint16_t PinNumber, uint8_t Value);
	void MCAL_GPIO_WritePort(GPIO_Typedef *GPIOx, uint16_t value);
	void MCAL_GPIO_togglePin(GPIO_Typedef *GPIOx, uint16_t PinNumber);
	uint8_t MCAL_GPIO_LockPin(GPIO_Typedef *GPIOx, uint16_t PinNumber);

	#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
