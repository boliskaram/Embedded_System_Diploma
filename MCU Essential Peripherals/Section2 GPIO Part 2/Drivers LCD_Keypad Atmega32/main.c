/*
 * Drivers.c
 *
 * Created: 8/2/2021 5:11:35 PM
 * Author : Bolis
 */ 

#include <avr/io.h>
#include "LCD/LCD.h"
#include "KEYPAD/Keypad.h"

int main(void)
{
	LCD_init();
	KEYPAD_init();
	_delay_ms(50);
	unsigned char pressedKey ;
	//LCD_write_char('a');
	//LCD_write_string("Bolis Karam Soliman bolis karam soliman Bolis Karam Soliman bolis karam soliman Bolis Karam Soliman bolis karam soliman");
	
    /* Replace with your application code */
    while (1) 
    {
		//LCD_write_char('B');
		pressedKey = KEYPAD_getChar();
		switch(pressedKey){
			case 'A':
			break;
			case '!':
			LCD_clear_screen();
			break; 
			default:
			LCD_write_char(pressedKey);
			break;
		}
    }
}

