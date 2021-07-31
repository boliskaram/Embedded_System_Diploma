/*
 * Unit5_Sec1_GPIO_Task2.c
 *
 * Created: 7/30/2021 8:09:11 PM
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
#define PORTB (*(volatile unsigned char*) 0x38)
#define DDRB (*(volatile unsigned char*) 0x37)
#define PINB (*(volatile unsigned char*) 0x36)



int main(void)
{
	RESET_BIT(DDRB,0);
	SET_BIT(PORTB,0);
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,3);
	
	char x=0;
	
    while (1) 
    {
		
		if(READ_BIT(PINB,0) == 0){		
			while(READ_BIT(PINB,0) == 0){
				SET_BIT(PORTA,x);
				}
				if(0 <= x && x < 3){
					x++;
					}
				
		}
    }
}