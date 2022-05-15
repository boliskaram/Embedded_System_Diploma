/*
 * stm32f103c6_EXTI_driver.c
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */
#include "stm32f103c6_EXTI_driver.h"
#include "stm32f103c6_gpio_driver.h"

//=====================================================================
//						Generic Variables
//=====================================================================
void(* GP_IRQ_CallBack[15])(void);

//=====================================================================
//						Generic Macros
//=====================================================================

#define AFIO_GPIO_EXTI_Mapping(x)		((x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0)


//=====================================================================
//						Generic Functions
//=====================================================================


void Enable_NVIC(uint16_t IRQ){
	switch (IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_EN;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_EN;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_EN;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_EN;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_EN;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_EN;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_EN;
		break;

	}

}

void Disable_NVIC(uint16_t IRQ){
	switch (IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;

	}
}

void Update_EXTI(EXTI_PinConfig_t *EXTI_Config){
	//	1: config gpio AF input as floating input

	GPIO_PinConfig_t Pincfg ;
	Pincfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_Pin;
	Pincfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &Pincfg);

	//	2: config AFIO to route between EXTI and POAT A,B,C,D

	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_line_Number / 4 ;
	uint8_t AFIO_EXTICR_Postion = (EXTI_Config->EXTI_PIN.EXTI_line_Number % 4) * 4 ;

	// clear bits
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~( 0xF << AFIO_EXTICR_Postion ) ;
	//
	AFIO->EXTICR[AFIO_EXTICR_Index] |= (( AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) &0xF) << AFIO_EXTICR_Postion);

	// 3: Rising or falling register
	//	clear registers
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_line_Number);
	EXTI->FTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_line_Number);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING){
		EXTI->RTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_line_Number);

	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING){
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_line_Number);
	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING_FALLING){
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_line_Number);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_line_Number);
	}

	// IRQ handling CALLBACK
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_line_Number] = EXTI_Config->P_IRQ_CallBack;

	// Enable/Disable ISR

	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable){
		EXTI->IMR |=(1<<EXTI_Config->EXTI_PIN.EXTI_line_Number);
		Enable_NVIC (EXTI_Config->EXTI_PIN.EXTI_line_Number);
	}else {
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_line_Number);
		Disable_NVIC (EXTI_Config->EXTI_PIN.EXTI_line_Number);
	}
}


//=====================================================================
//						APIs Functions Definitions
//=====================================================================

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config){

	Update_EXTI(EXTI_Config);
}

void MCAL_EXTI_GPIO_DeInit(void){
	EXTI->IMR 	= 0x00000000;
	EXTI->EMR 	= 0x00000000;
	EXTI->RTSR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR 	= 0xFFFFFFFF;

	//	Disable EXTI IRQ from NVIC

	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;

}


void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config){

	Update_EXTI(EXTI_Config);
}




//==========================================================
//						ISR Functions
//==========================================================


void EXTI0_IRQHandler(void){

	//	clear PR by w1
	EXTI->PR |= (1<<0);

	//	call IRQ_CALL
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void){
	//	clear PR by w1
	EXTI->PR |= (1<<1);

	//	call IRQ_CALL
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void){
	//	clear PR by w1
	EXTI->PR |= (1<<2);

	//	call IRQ_CALL
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void){
	//	clear PR by w1
	EXTI->PR |= (1<<3);

	//	call IRQ_CALL
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void){
	//	clear PR by w1
	EXTI->PR |= (1<<4);

	//	call IRQ_CALL
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void){

	if(EXTI->PR &  1<<5) {EXTI->PR |= (1<<5);  GP_IRQ_CallBack[5](); }
	if(EXTI->PR &  1<<6) {EXTI->PR |= (1<<6);  GP_IRQ_CallBack[6](); }
	if(EXTI->PR &  1<<7) {EXTI->PR |= (1<<7);  GP_IRQ_CallBack[7](); }
	if(EXTI->PR &  1<<8) {EXTI->PR |= (1<<8);  GP_IRQ_CallBack[8](); }
	if(EXTI->PR &  1<<9) {EXTI->PR |= (1<<9);  GP_IRQ_CallBack[9](); }
}

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR &  1<<10) {EXTI->PR |= (1<<10);  GP_IRQ_CallBack[10](); }
	if(EXTI->PR &  1<<11) {EXTI->PR |= (1<<11);  GP_IRQ_CallBack[11](); }
	if(EXTI->PR &  1<<12) {EXTI->PR |= (1<<12);  GP_IRQ_CallBack[12](); }
	if(EXTI->PR &  1<<13) {EXTI->PR |= (1<<13);  GP_IRQ_CallBack[13](); }
	if(EXTI->PR &  1<<14) {EXTI->PR |= (1<<14);  GP_IRQ_CallBack[14](); }
	if(EXTI->PR &  1<<15) {EXTI->PR |= (1<<15);  GP_IRQ_CallBack[15](); }
}
