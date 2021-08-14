/*
 * Keypad.h
 *
 * Created: 8/3/2021 5:35:06 PM
 *  Author: Bolis
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define KEYPAD_port PORTD
#define DataDir_KEYPAD_port DDRD
#define KEYPAD_pin PIND


#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

void KEYPAD_init();
char KEYPAD_getChar();

#endif /* KEYPAD_H_ */