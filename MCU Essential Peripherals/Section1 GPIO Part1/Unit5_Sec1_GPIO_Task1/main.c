/*
 * Unit5_Sec1_GPIO_Task1.c
 *
 * Created: 7/31/2021 9:01:31 PM
 * Author : Bolis
 */ 

//#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1<<BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1<<BIT))>>BIT)
#define TOGGLE_BIT(ADDRESS, BIT) ADDRESS ^= (1<<BIT)
#define DDRA (*(volatile unsigned char*) 0x3A)
#define PORTA (*(volatile unsigned char*) 0x3B)


int main(void)
{
	
	for(int i=0;i<=7;i++){
		SET_BIT(DDRA,i);
	}
	/* Replace with your application code */
	while (1)
	{
		for(int i=0;i<=7;i++){
			SET_BIT(PORTA,i);
			_delay_ms(200);
		}
		_delay_ms(200);
		
		for(int i=7;i>=0;i--){
			RESET_BIT(PORTA,i);
			_delay_ms(200);
		}
	}
}


