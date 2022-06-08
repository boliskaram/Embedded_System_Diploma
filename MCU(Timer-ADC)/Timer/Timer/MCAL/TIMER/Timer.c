/*
 * Timer.c
 *
 * Created: 6/7/2022 12:16:07 AM
 *  Author: Bolis
 */ 

#include "Timer.h"

/******************************************************************************
*                               GLOBAL & EXTERN VARIABLES                     *
*******************************************************************************/

p_VfunV Callback_OVF;
p_VfunV Callback_CM;

uint8_t u8_TOVNum;
TIMER0_CONFIG_t* G_Timer_Config;

/******************************************************************************
*								 APIS IMPLEMENTATION			              *
*******************************************************************************/

E_STATUS_t TIMER0_Init(TIMER0_CONFIG_t* T_CONFIG){
	
	E_STATUS_t u8_Retval = E_NOK;
	
		if(NULL_Ptr == T_CONFIG){
			u8_Retval =E_NOK;
		}else{
			G_Timer_Config = T_CONFIG;
			
			if((NORMAL == G_Timer_Config->MODE  ) || ( CTC == G_Timer_Config->MODE)){
				TCCR0 |= G_Timer_Config->MODE;
				u8_Retval = E_OK;
			}else{
				u8_Retval = E_NOK;
			}
			
			if ((NO_CLK_SRC <= G_Timer_Config->CLK ) && ( EXT_CLK_RISING >= G_Timer_Config->CLK)){
				TCCR0 |= G_Timer_Config->CLK;
				u8_Retval = E_OK;
			}else{
				u8_Retval = E_NOK;
			}
			
			if ((OCIE_ENABLE == G_Timer_Config->OCM_Interrupt) || (OCIE_DISABLE == G_Timer_Config->OCM_Interrupt)){
				
				TIMSK |= G_Timer_Config->OCM_Interrupt ;
				u8_Retval = E_OK;
			}else{
				u8_Retval = E_NOK;
			}
			
			if ((TOIE_ENABLE == G_Timer_Config->TOVF_Interrupt)||(TOIE_DISABLE == G_Timer_Config->TOVF_Interrupt)){
				
				TIMSK |= G_Timer_Config->TOVF_Interrupt ;
				u8_Retval = E_OK;
			}else{
				u8_Retval = E_NOK;
			}			
		}

	return u8_Retval;
}
E_STATUS_t TIMER0_Stop(){
	
	E_STATUS_t u8_Retval = E_NOK;
	RESET_BIT(TCCR0,CS00);
	RESET_BIT(TCCR0,CS01);
	RESET_BIT(TCCR0,CS02);
	return u8_Retval;
}

E_STATUS_t TIMER0_GetCompareVal(p_uint8_t pu8_TickNum){
	E_STATUS_t u8_Retval = E_NOK;
	*pu8_TickNum = OCR0;
	return u8_Retval;
}
E_STATUS_t TIMER0_SetCompareVal(uint8_t u8_TickNum){
	E_STATUS_t u8_Retval = E_NOK;
	OCR0 = u8_TickNum;
	return u8_Retval;
}

E_STATUS_t TIMER0_GetCounterVal(p_uint8_t pu8_TickNum){
	E_STATUS_t u8_Retval = E_NOK;
	*pu8_TickNum = TCNT0;
	return u8_Retval;
}
E_STATUS_t TIMER0_SetCounterVal(uint8_t u8_TickNum){
	E_STATUS_t u8_Retval = E_NOK;
	TCNT0 = u8_TickNum;
	return u8_Retval;
}

E_STATUS_t TIMER0_GetOverflowVal(p_uint8_t pu8_TickNum){
	E_STATUS_t u8_Retval = E_NOK;
	*pu8_TickNum = u8_TOVNum;
	return u8_Retval;
}
E_STATUS_t TIMER0_SetOverflowVal(uint8_t u8_TickNum){
	E_STATUS_t u8_Retval = E_NOK;
	u8_TOVNum = u8_TickNum;
	return u8_Retval;
}

void TIMER0_CALLBACK_Overflow_INTERRUPT(p_VfunV callback){
	Callback_OVF = callback;
}
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(p_VfunV callback){
	Callback_CM = callback;
}


ISR(TIMER0_OVF_vect){
	u8_TOVNum++;
	Callback_OVF();
}
ISR(TIMER0_COMP_vect){
	Callback_CM();
}
