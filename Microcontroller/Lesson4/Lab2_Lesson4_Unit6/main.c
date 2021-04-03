/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Bolis
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS, BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1<<BIT))>>BIT)

#define IO_BASE 0x20
#define IO_PORTD *(volatile unsigned int *)(IO_BASE + 0x12)
#define IO_DDRD *(volatile unsigned int *)(IO_BASE + 0x11)
#define INT_MCUCR *(volatile unsigned int *)(IO_BASE + 0x35)
#define INT_GICR *(volatile unsigned int *)(IO_BASE + 0x3B)
#define INT_MCUCSR *(volatile unsigned int *)(IO_BASE + 0x34)

int main(){

	//	allow  pin(5,6,7) as  output in portD (pin = 0)
	SET_BIT(IO_DDRD,5);
	SET_BIT(IO_DDRD,6);
	SET_BIT(IO_DDRD,7);
	//	set int0 logical
	SET_BIT(INT_MCUCR,0);
	RESET_BIT(INT_MCUCR,1);
	//	set int1 rising edge
	SET_BIT(INT_MCUCR,2);
	SET_BIT(INT_MCUCR,3);
	//	set int2 falling edge
	RESET_BIT(INT_MCUCSR,6);
	//	enable all int0,1,2
	SET_BIT(INT_GICR,5);
	SET_BIT(INT_GICR,6);
	SET_BIT(INT_GICR,7);
	sei();
	while(1){
		RESET_BIT(IO_PORTD,5);
		RESET_BIT(IO_PORTD,6);
		RESET_BIT(IO_PORTD,7);
	}
	return 0;
}

ISR(INT0_vect){
	SET_BIT(IO_PORTD,5);
	_delay_ms(1000);

}
ISR(INT1_vect){
	SET_BIT(IO_PORTD,6);
	_delay_ms(1000);

}
ISR(INT2_vect){
	SET_BIT(IO_PORTD,7);
	_delay_ms(1000);

}


