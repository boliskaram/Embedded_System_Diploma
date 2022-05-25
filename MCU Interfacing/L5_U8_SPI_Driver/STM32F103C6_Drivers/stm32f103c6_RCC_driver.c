/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */
#include "stm32f103c6_RCC_driver.h"


const uint8_t AHBPrescTable[16] = {0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8};
const uint8_t APBPrescTable[16] = {0,0,0,0,1,2,3,4};
uint32_t MCAL_RCC_GetSYSCLKFreq(void){

	switch( (RCC->CFGR >> 2) & 0b11){
	case 0:
		return HSI_RC_CLK;
		break;
	case 1:
		return HSE_CLK;
		break;
	case 2:
		return 16000000 ;
		break;
	}
}

uint32_t MCAL_RCC_GetHCLKFreq(void){

	return ( MCAL_RCC_GetSYSCLKFreq() >> AHBPrescTable[ (RCC->CFGR >> 4) & 0xf ] );
}

uint32_t MCAL_RCC_GetPCLK1Freq(void){

	return ( MCAL_RCC_GetHCLKFreq() >> APBPrescTable[ (RCC->CFGR >> 8) & 0b111 ] );

}

uint32_t MCAL_RCC_GetPCLK2Freq(void){

	return ( MCAL_RCC_GetHCLKFreq() >> APBPrescTable[ (RCC->CFGR >> 11) & 0b111 ] );
}
