/*
 * LCD.h
 *
 * Created: 8/2/2021 5:58:48 PM
 *  Author: Bolis
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "avr/io.h"
#define F_CPU 8000000UL
#include "util/delay.h"


#define LCD_port PORTA
#define DataDir_LCD_port DDRA
#define LCD_control PORTB
#define DataDir_LCD_control DDRB
#define EN_switch 3
#define RW_switch 2
#define RS_switch 1
#define Data_shift 4

#define FOUR_BIT_MODE
//#define EIGHT_BIT_MODE


#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


void LCD_init();
void LCD_is_busy();
void LCD_clear_screen ();
void LCD_write_command(unsigned char command);
void LCD_write_char(unsigned char data);
void LCD_write_string(char* data);
void LCD_goto(char line,char position);

 

#endif /* LCD_H_ */