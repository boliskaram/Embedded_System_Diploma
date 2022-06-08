/*
 * Timer.c
 *
 * Created: 6/6/2022 11:51:11 PM
 * Author : Bolis
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "MCAL/Timer/Timer.h"

extern uint8_t u8_TOVNum;

void TOIE_callback(){
	PORTA = ~PORTA;
}

int main(void)
{
	/* Replace with your application code */
	DDRA = 0xFF;
	sei();
	TIMER0_CALLBACK_CompareMatch_INTERRUPT(TOIE_callback);
	TIMER0_CONFIG_t T0CFG = {CTC,PRESCALING_CLK8,TOIE_DISABLE,OCIE_ENABLE};
	/*T0CFG.MODE=CTC;
	T0CFG.CLK= PRESCALING_CLK8;
	T0CFG.OCM_Interrupt = OCIE_ENABLE ; 
	T0CFG.TOVF_Interrupt = TOIE_DISABLE;*/
	TIMER0_SetCompareVal(0xF0);
	TIMER0_Init(&T0CFG);   
	
	
	while (1) 
    {
    }
}

