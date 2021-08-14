/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Aug 8, 2021
 *      Author: Bolis Karam
 */

#include "stm32f103c6_gpio_driver.h"


uint8_t Get_CRLH_Postion(uint16_t PinNumber)
{
	switch(PinNumber){
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}




/*=========================================================================
 * @Fn				- MCAL_GPIO_Init
 * @breif 			- Initializes GPIOx PINy
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @param [in] 		- PinConfig : the configuration  information for the specified GPIO PIN
 * @retval 			- none
 * Note 			- stm32f103c6 MCU has GPIO A,B,C,D,E
 * 					- LQFP48 Package has only GPIO A,B part of C,D
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig){

	//Port configuration register low (GPIOx_CRL)  	Pins from 0 to 7
	//Port configuration register low (GPIOx_CRL) 	Pins from 8 to 15

	volatile uint32_t* configregister = NULL ;
	uint8_t PIN_Config = 0;

	configregister  = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH;

	//clear CNF0[1:0] MODE0[1:0]
	(*configregister) &= ~(0xff << Get_CRLH_Postion(PinConfig->GPIO_PinNumber));

	// if pin is output
	if(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP ||
			PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP ){
		//set CNF0[1:0] MODE0[1:0]
		PIN_Config = ((((PinConfig->GPIO_Mode - 4) << 2) | (PinConfig->GPIO_OutputSpeed)) & 0x0f );
	}

	// if pin is input
	// MODE = 00: Input mode (reset state)
	else{
		if(PinConfig->GPIO_Mode == GPIO_MODE_ANALOG || PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO  ){
			//set CNF0[1:0] MODE0[1:0]
			PIN_Config = ((((PinConfig->GPIO_Mode) << 2) | 0x0) & 0x0f );
		}
		else if (PinConfig->GPIO_Mode == GPIO_MODE_AF_INPUT){
			//set CNF0[1:0] MODE0[1:0]
			PIN_Config = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0) & 0x0f );
		}
		else{
			//set CNF0[1:0] MODE0[1:0]
			PIN_Config = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0f );

			if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU){
				GPIOx->ODR |= PinConfig->GPIO_PinNumber ;
			}
			else{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}

	//write on CRL,CRH Register
	(*configregister) |= ((PIN_Config) << Get_CRLH_Postion(PinConfig->GPIO_PinNumber));
}


/*=========================================================================
 * @Fn				- MCAL_GPIO_DeInit
 * @breif 			- Reset All the GPIOx Register
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @retval 			- none
 * Note 			- none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx){

	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}


}


/*=========================================================================
 * @Fn				- MCAL_GPIO_ReadPin
 * @breif 			- Read specific Pin
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @param [in] 		- PinNumber: set pin Number according @ref GPIO_PINS_define
 * @retval 			- the input pin value (two values based @ref GPIO_PIN_state)
 * Note 			- none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber)
{
	uint8_t PinValue ;

	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		PinValue = GPIO_PIN_SET ;
	}
	else{
		PinValue = GPIO_PIN_RESET;
	}
	return PinValue;
}



/*=========================================================================
 * @Fn				- MCAL_GPIO_ReadPort
 * @breif 			- Read specific Port
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @retval 			- the input port value
 * Note 			- none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16_t PortValue;
	PortValue = (uint16_t)GPIOx->IDR;
	return PortValue;
}


/*=========================================================================
 * @Fn				- MCAL_GPIO_WritePin
 * @breif 			- write on specific pin
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @param [in] 		- PinNumber: when set pin Number according @ref GPIO_PINS_define
 * @param [in] 		- value: pin value
 * @retval 			- none
 * Note 			- none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber , uint8_t value )
{
	if( value != GPIO_PIN_RESET)
	{
		GPIOx->ODR |= PinNumber;
		//or
		//GPIOx->BSRR = (uint32_t) PinNumber;

	}
	else{
		GPIOx->ODR &= ~(PinNumber);
		//or
		//GPIOx->BRR = (uint32_t) PinNumber;
	}

}


/*=========================================================================
 * @Fn				- MCAL_GPIO_WritePort
 * @breif 			- Write on specific Port
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @param [in] 		- value: pin value
 * @retval 			- none
 * Note 			- none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value)
{
	GPIOx->ODR = (uint32_t)value;

}


/*=========================================================================
 * @Fn				- MCAL_GPIO_TogglePin
 * @breif 			- toggle specific Pin
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @param [in] 		- PinNumber: when set pin Number according @ref GPIO_PINS_define
 * @retval 			- none
 * Note 			- none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}


/*=========================================================================
 * @Fn				- MCAL_GPIO_LockPin
 * @breif 			- lock specific Pin
 * @param [in] 		- GPIOx: when x can be (A...E) to select GPIO peripheral
 * @param [in] 		- PinNumber: when set pin Number according @ref GPIO_PINS_define
 * @retval 			- ok if pin is locked or error if pin is not locked @ref GPIO_LOCK_Define
 * Note 			- none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx ,uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.

	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked

	//set LCKK[16]
	volatile uint32_t flag = 1<<16;

	//set the LCKy
	flag |= PinNumber;

	//	write 1
	GPIOx->LCKR = flag;
	//	write 0
	GPIOx->LCKR = PinNumber;
	//	write 1
	GPIOx->LCKR = flag;
	// 	read 0
	flag = GPIOx->LCKR;
	// 	read
	if((uint32_t)(GPIOx->LCKR & 1<<16)){
		return 	GPIO_LOCK_TRUE;
	}else {
		return GPIO_LOCK_FALSE;
	}
}

