/*
 * WDT.c
 *
 * Created: 6/6/2022 7:19:44 PM
 * Author : Bolis
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



void WDT_ON(){
	 WDTCR |= (1 << WDE) |(1 << WDP1) |(1 << WDP2);
	 WDTCR &= ~(1 << WDP0);
}
void WDT_OFF(){
	WDTCR |= (1 << WDE) |(1 << WDTOE);
	WDTCR = 0x00;
}

#define LED_DDR			DDRC
#define LED_PORT		PORTC
int main(void)
{
	LED_DDR |= 1 << 0 ;
	//_delay_ms(500);
    /* Replace with your application code */
    while (1) 
    {
		WDT_ON();
		LED_PORT ^= 1<<0;
		_delay_ms(2000);
		WDT_OFF();
    }
}

