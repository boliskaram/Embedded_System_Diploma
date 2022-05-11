/*
 * stm32f103c6_EXTI_driver.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"


typedef struct
{
	uint16_t 		EXTI_line_Number;
	GPIO_Typedef 	*GPIO_Port;
	uint16_t 		GPIO_Pin;
	uint8_t			IVT_IRQ_Number;

}EXTI_GPIO_Mapping_t;

typedef struct{
	EXTI_GPIO_Mapping_t EXTI_PIN;    	// specifies the external interrupt gpio mapping
										// this parameter can be a value of @ref EXTI_define

	uint8_t				Trigger_Case;	// specifies rising or falling or both
										// this parameter can be a value of @ref EXTI_Trigger_define

	uint8_t				IRQ_EN;			// enable or disable the EXTI IRQ(enable the irq mask in EXTI and NVIC interrupt)
										// this parameter can be a value of @ref EXTI_IRQ_define

	void(* P_IRQ_CallBack)(void);		//set the C Function() which will be called once the IRQ happen
}EXTI_PinConfig_t;




//====================================================
// Macros Configuration References
//====================================================
// EXTI Lines
#define EXTI0		0
#define EXTI1		1
#define EXTI2		2
#define EXTI3		3
#define EXTI4		4
#define EXTI5		5
#define EXTI6		6
#define EXTI7		7
#define EXTI8		8
#define EXTI9		9
#define EXTI10		10
#define EXTI11		11
#define EXTI12		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15

//===================================================
//Reference Macros

//@ref EXTI_define

//EXTI0
#define EXTI0PA0	(EXIT_GPIO_Mapping_t){EXTI0,GPIOA,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PB0	(EXIT_GPIO_Mapping_t){EXTI0,GPIOB,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PC0	(EXIT_GPIO_Mapping_t){EXTI0,GPIOC,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PD0	(EXIT_GPIO_Mapping_t){EXTI0,GPIOD,GPIO_PIN_0,EXTI0_IRQ}

//EXTI1
#define EXTI1PA1	(EXIT_GPIO_Mapping_t){EXTI1,GPIOA,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PB1	(EXIT_GPIO_Mapping_t){EXTI1,GPIOB,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PC1	(EXIT_GPIO_Mapping_t){EXTI1,GPIOC,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PD1	(EXIT_GPIO_Mapping_t){EXTI1,GPIOD,GPIO_PIN_1,EXTI1_IRQ}

//EXTI2
#define EXTI2PA2	(EXIT_GPIO_Mapping_t){EXTI2,GPIOA,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PB2	(EXIT_GPIO_Mapping_t){EXTI2,GPIOB,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PC2	(EXIT_GPIO_Mapping_t){EXTI2,GPIOC,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PD2	(EXIT_GPIO_Mapping_t){EXTI2,GPIOD,GPIO_PIN_2,EXTI2_IRQ}

//EXTI3
#define EXTI3PA3	(EXIT_GPIO_Mapping_t){EXTI3,GPIOA,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PB3	(EXIT_GPIO_Mapping_t){EXTI3,GPIOB,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PC3	(EXIT_GPIO_Mapping_t){EXTI3,GPIOC,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PD3	(EXIT_GPIO_Mapping_t){EXTI3,GPIOD,GPIO_PIN_3,EXTI3_IRQ}

//EXTI4
#define EXTI4PA4	(EXIT_GPIO_Mapping_t){EXTI4,GPIOA,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PB4	(EXIT_GPIO_Mapping_t){EXTI4,GPIOB,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PC4	(EXIT_GPIO_Mapping_t){EXTI4,GPIOC,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PD4	(EXIT_GPIO_Mapping_t){EXTI4,GPIOD,GPIO_PIN_4,EXTI4_IRQ}

//EXTI5
#define EXTI5PA5	(EXIT_GPIO_Mapping_t){EXTI5,GPIOA,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PB5	(EXIT_GPIO_Mapping_t){EXTI5,GPIOB,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PC5	(EXIT_GPIO_Mapping_t){EXTI5,GPIOC,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PD5	(EXIT_GPIO_Mapping_t){EXTI5,GPIOD,GPIO_PIN_5,EXTI5_IRQ}

//EXTI6
#define EXTI6PA6	(EXIT_GPIO_Mapping_t){EXTI6,GPIOA,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PB6	(EXIT_GPIO_Mapping_t){EXTI6,GPIOB,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PC6	(EXIT_GPIO_Mapping_t){EXTI6,GPIOC,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PD6	(EXIT_GPIO_Mapping_t){EXTI6,GPIOD,GPIO_PIN_6,EXTI6_IRQ}

//EXTI7
#define EXTI7PA7	(EXIT_GPIO_Mapping_t){EXTI7,GPIOA,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PB7	(EXIT_GPIO_Mapping_t){EXTI7,GPIOB,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PC7	(EXIT_GPIO_Mapping_t){EXTI7,GPIOC,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PD7	(EXIT_GPIO_Mapping_t){EXTI7,GPIOD,GPIO_PIN_7,EXTI7_IRQ}

//EXTI8
#define EXTI8PA8	(EXIT_GPIO_Mapping_t){EXTI8,GPIOA,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PB8	(EXIT_GPIO_Mapping_t){EXTI8,GPIOB,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PC8	(EXIT_GPIO_Mapping_t){EXTI8,GPIOC,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PD8	(EXIT_GPIO_Mapping_t){EXTI8,GPIOD,GPIO_PIN_8,EXTI8_IRQ}

//EXTI9
#define EXTI9PA9	(EXIT_GPIO_Mapping_t){EXTI9,GPIOA,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PB9	(EXTI_GPIO_Mapping_t){EXTI9,GPIOB,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PC9	(EXIT_GPIO_Mapping_t){EXTI9,GPIOC,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PD9	(EXIT_GPIO_Mapping_t){EXTI9,GPIOD,GPIO_PIN_9,EXTI9_IRQ}

//EXTI10
#define EXTI10PA10	(EXIT_GPIO_Mapping_t){EXTI10,GPIOA,GPIO_PIN_10,EXTI0_IRQ}
#define EXTI10PB10	(EXIT_GPIO_Mapping_t){EXTI10,GPIOB,GPIO_PIN_10,EXTI0_IRQ}
#define EXTI10PC10	(EXIT_GPIO_Mapping_t){EXTI10,GPIOC,GPIO_PIN_10,EXTI0_IRQ}
#define EXTI10PD10	(EXIT_GPIO_Mapping_t){EXTI10,GPIOD,GPIO_PIN_10,EXTI0_IRQ}

//EXTI11
#define EXTI11PA11	(EXIT_GPIO_Mapping_t){EXTI11,GPIOA,GPIO_PIN_11,EXTI0_IRQ}
#define EXTI11PB11	(EXIT_GPIO_Mapping_t){EXTI11,GPIOB,GPIO_PIN_11,EXTI0_IRQ}
#define EXTI11PC11	(EXIT_GPIO_Mapping_t){EXTI11,GPIOC,GPIO_PIN_11,EXTI0_IRQ}
#define EXTI11PD11	(EXIT_GPIO_Mapping_t){EXTI11,GPIOD,GPIO_PIN_11,EXTI0_IRQ}

//EXTI12
#define EXTI12PA12	(EXIT_GPIO_Mapping_t){EXTI12,GPIOA,GPIO_PIN_12,EXTI0_IRQ}
#define EXTI12PB12	(EXIT_GPIO_Mapping_t){EXTI12,GPIOB,GPIO_PIN_12,EXTI0_IRQ}
#define EXTI12PC12	(EXIT_GPIO_Mapping_t){EXTI12,GPIOC,GPIO_PIN_12,EXTI0_IRQ}
#define EXTI12PD12	(EXIT_GPIO_Mapping_t){EXTI12,GPIOD,GPIO_PIN_12,EXTI0_IRQ}

//EXTI13
#define EXTI13PA13	(EXIT_GPIO_Mapping_t){EXTI13,GPIOA,GPIO_PIN_13,EXTI0_IRQ}
#define EXTI13PB13	(EXIT_GPIO_Mapping_t){EXTI13,GPIOB,GPIO_PIN_13,EXTI0_IRQ}
#define EXTI13PC13	(EXIT_GPIO_Mapping_t){EXTI13,GPIOC,GPIO_PIN_13,EXTI0_IRQ}
#define EXTI13PD13	(EXIT_GPIO_Mapping_t){EXTI13,GPIOD,GPIO_PIN_13,EXTI0_IRQ}

//EXTI14
#define EXTI14PA14	(EXIT_GPIO_Mapping_t){EXTI14,GPIOA,GPIO_PIN_14,EXTI0_IRQ}
#define EXTI14PB14	(EXIT_GPIO_Mapping_t){EXTI14,GPIOB,GPIO_PIN_14,EXTI0_IRQ}
#define EXTI14PC14	(EXIT_GPIO_Mapping_t){EXTI14,GPIOC,GPIO_PIN_14,EXTI0_IRQ}
#define EXTI14PD14	(EXIT_GPIO_Mapping_t){EXTI14,GPIOD,GPIO_PIN_14,EXTI0_IRQ}

//EXTI15
#define EXTI15PA15	(EXIT_GPIO_Mapping_t){EXTI15,GPIOA,GPIO_PIN_15,EXTI0_IRQ}
#define EXTI15PB15	(EXIT_GPIO_Mapping_t){EXTI15,GPIOB,GPIO_PIN_15,EXTI0_IRQ}
#define EXTI15PC15	(EXIT_GPIO_Mapping_t){EXTI15,GPIOC,GPIO_PIN_15,EXTI0_IRQ}
#define EXTI15PD15	(EXIT_GPIO_Mapping_t){EXTI15,GPIOD,GPIO_PIN_15,EXTI0_IRQ}


//----------------------------------------------------------------------------
//@ref EXTI_Trigger_define

#define EXTI_Trigger_RISING				0
#define EXTI_Trigger_FALLING			1
#define EXTI_Trigger_RISING_FALLING		2

//----------------------------------------------------------------------------
//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable		0
#define EXTI_IRQ_Disable	1



//================================================================================
//									APIs
//================================================================================


void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config);

void MCAL_EXTI_GPIO_DeInit(void);

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config);


#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
