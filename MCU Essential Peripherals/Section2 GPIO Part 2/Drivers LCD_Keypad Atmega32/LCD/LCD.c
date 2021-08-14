/*
 * LCD.c
 *
 * Created: 8/2/2021 5:58:30 PM
 *  Author: Bolis
 */ 

#include "LCD.h"


void LCD_EN_switch(){
	LCD_control &= ~(1<<EN_switch); //disable RW data
	_delay_ms(50);
	LCD_control |= (1<<EN_switch); //enable RW data
}

void LCD_is_busy(){
	DataDir_LCD_port &= ~(0xff<<Data_shift); //input
	LCD_control |= (1<<RW_switch);  //read
	LCD_control &= ~(1<<RS_switch); //command mode
	LCD_EN_switch();
	DataDir_LCD_port = 0xff; //output
	LCD_control &= ~(1<<RW_switch); //write
}

void LCD_write_command(unsigned char command){
	
	#ifdef EIGHT_BIT_MODE
		LCD_is_busy();
		LCD_port = command;
		DataDir_LCD_port =  0xff; // output
		LCD_control &= ~(1<<RW_switch | 1<<RS_switch); // write , command mode
		LCD_EN_switch();
	#endif	
	#ifdef FOUR_BIT_MODE
		LCD_is_busy();
		LCD_port = (LCD_port & 0x0f) | (command & 0xf0);
		LCD_control &= ~((1<<RW_switch) | (1<<RS_switch)); // write , command mode
		LCD_EN_switch();
		LCD_port = (LCD_port & 0x0f) | (command<<Data_shift);	
		LCD_control &= ~((1<<RW_switch) | (1<<RS_switch)); // write , command mode
		LCD_EN_switch();
	#endif
}

void LCD_clear_screen(){
	LCD_write_command(LCD_CLEAR_SCREEN); // clear screen
}

void LCD_init(){
	_delay_ms(30); // when start LCD should be wait 
	LCD_is_busy(); //to check if LCD busy 
	DataDir_LCD_control |= (1<<EN_switch | 1<<RW_switch | 1<<RS_switch); // output
	LCD_control &= ~(1<<EN_switch | 1<<RW_switch | 1<<RS_switch); //disable controls
	DataDir_LCD_port = 0xff;  // output
	
	_delay_ms(15);
	LCD_clear_screen();
	
	#ifdef EIGHT_BIT_MODE
		LCD_write_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE 
		LCD_write_command(0x02);
		LCD_write_command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_write_command(LCD_ENTRY_MODE);
	LCD_write_command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_write_command(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_write_char(unsigned char data){
	#ifdef EIGHT_BIT_MODE
		LCD_is_busy();
		LCD_port = data;
		DataDir_LCD_port =  0xff; //output
		LCD_control &= ~(1<<RW_switch); //write
		LCD_control |= (1<<RS_switch); // data mode
		LCD_EN_switch();
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_port = (LCD_port & 0x0f)|(data & 0xf0);
		LCD_control &= ~(1<<RW_switch);
		LCD_control |= (1<<RS_switch);
		LCD_EN_switch(); 
		LCD_port = (LCD_port & 0x0f)|(data<<Data_shift);
		LCD_control |= (1<<RS_switch);
		LCD_control &= ~(1<<RW_switch);
		LCD_EN_switch();
	#endif
}


void LCD_goto(char line ,char position ){
	if(line == 1){
		if(16 > position && position >= 0){
			LCD_write_command(LCD_BEGIN_AT_FIRST_RAW + position);
		}
	}
	else if(line == 2){
		if( 16 > position && position >= 0){
			LCD_write_command(LCD_BEGIN_AT_SECOND_RAW + position);
		}
	}
}

void LCD_write_string(char* data){
	int line_space = 0; // to know when line 1 finish and go to line 2
	while(*data > 0){
		line_space++;
		LCD_write_char(*data++);
		if(line_space == 16){ // when line 1 finish
			LCD_goto(2,0);	// go to line 2 
		}
		else if(line_space == 32){ // when line 2 finish
			LCD_clear_screen();	// clear data 
			LCD_goto(1,0);	// go to start line 1
			line_space = 0; // reset number 
		}
	}
}

