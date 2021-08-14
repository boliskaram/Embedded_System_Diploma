/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Aug 8, 2021
 *      Author: Bolis
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//-------------------------------
//Includes
//-------------------------------
#include "stm32f103x6.h"

//=====================================================================================

typedef struct
{
	uint16_t GPIO_PinNumber;		// specifies the GPIO Pins to be configured
	// this parameter can be a value of @ref GPIO_PINS_define

	uint8_t GPIO_Mode;				// specifies the operating mode for the selected pins
	// this parameter can be a value of @ref GPIO_MODE_define

	uint8_t GPIO_OutputSpeed;   	// specifies the speed for the selected pins
	// this parameter can be a value of @ref GPIO_SPEED_define

}GPIO_PinConfig_t;



//=====================================================================================
//-------------------------------
//Macros Configuration References
//-------------------------------

// @ref GPIO_PINS_define
#define GPIO_PIN_0				((uint16_t)0x0001)		// pin 0 selected
#define GPIO_PIN_1				((uint16_t)0x0002)		// pin 1 selected
#define GPIO_PIN_2				((uint16_t)0x0004)		// pin 2 selected
#define GPIO_PIN_3				((uint16_t)0x0008)		// pin 3 selected
#define GPIO_PIN_4				((uint16_t)0x0010)		// pin 4 selected
#define GPIO_PIN_5				((uint16_t)0x0020)		// pin 5 selected
#define GPIO_PIN_6				((uint16_t)0x0040)		// pin 6 selected
#define GPIO_PIN_7				((uint16_t)0x0080)		// pin 7 selected
#define GPIO_PIN_8				((uint16_t)0x0100)		// pin 8 selected
#define GPIO_PIN_9				((uint16_t)0x0200)		// pin 9 selected
#define GPIO_PIN_10				((uint16_t)0x0400)		// pin 10 selected
#define GPIO_PIN_11				((uint16_t)0x0800)		// pin 11 selected
#define GPIO_PIN_12				((uint16_t)0x1000)		// pin 12 selected
#define GPIO_PIN_13				((uint16_t)0x2000)		// pin 13 selected
#define GPIO_PIN_14				((uint16_t)0x4000)		// pin 14 selected
#define GPIO_PIN_15				((uint16_t)0x8000)		// pin 15 selected

// @ref GPIO_MODE_define
#define GPIO_MODE_ANALOG			0x00000000U		//0: Analog mode
#define GPIO_MODE_INPUT_FLO			0x00000001U		//1: Floating input (reset state)
#define GPIO_MODE_INPUT_PU			0x00000002U		//2: Input with pull-up
#define GPIO_MODE_INPUT_PD			0x00000003U		//3: Input with pull-down
#define GPIO_MODE_OUTPUT_PP			0x00000004U		//4: General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD			0x00000005U		//5: General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006U		//6: Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007U		//7: Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT			0x00000008U		//8: Alternate function input

// @ref GPIO_SPEED_define
#define GPIO_SPEED_10			0x00000001U		//1: Output mode, max speed 10 MHZ
#define GPIO_SPEED_2			0x00000002U 	//2: Output mode, max speed 2 MHz
#define GPIO_SPEED_50			0x00000003U 	//3: Output mode, max speed 50 MHz

// @ref GPIO_PIN_state
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0

// @ref GPIO_LOCK_Define
#define GPIO_LOCK_TRUE 			1
#define GPIO_LOCK_FALSE 		0

//=====================================================================================
//-------------------------------
// MCAL GPIO Driver APIs
//-------------------------------


void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);


uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber );

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber , uint8_t value );

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber);


#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */










