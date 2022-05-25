/*
 * Keypad.c
 *
 * Created: 8/3/2021 5:34:51 PM
 *  Author: Bolis
 */





#include "keypad.h"


int Key_padRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int Key_padCol[] = { C0, C1, C2, C3 }; //columns

void delay_mss(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init() {
	//	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	//	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	//	KEYPAD_PORT = 0xFF;
	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_PinNumber = R0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OutputSpeed = GPIO_SPEED_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}

char Keypad_getkey() {
	int i, j;
	for (i = 0; i < 4; i++) {
		//		KEYPAD_PORT |= ((1 << Key_padCol[0]) | (1 << Key_padCol[1])
		//				| (1 << Key_padCol[2]) | (1 << Key_padCol[3]));
		//		KEYPAD_PORT &= ~(1 << Key_padCol[i]);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);
		for (j = 0; j < 4; j++) {
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0) {
				while (MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0)
					;
				switch (i) {
				case (0):
							if (j == 0)
								return '7';
							else if (j == 1)
								return '4';
							else if (j == 2)
								return '1';
							else if (j == 3)
								return '?';
				break;
				case (1):
							if (j == 0)
								return '8';
							else if (j == 1)
								return '5';
							else if (j == 2)
								return '2';
							else if (j == 3)
								return '0';
				break;
				case (2):
							if (j == 0)
								return '9';
							else if (j == 1)
								return '6';
							else if (j == 2)
								return '3';
							else if (j == 3)
								return '=';
				break;
				case (3):
							if (j == 0)
								return '/';
							else if (j == 1)
								return '*';
							else if (j == 2)
								return '-';
							else if (j == 3)
								return '+';
				break;
				}
			}
		}
	}
	return 'A';
}















//#include "Keypad.h"
//
//int KEYPAD_R[] = {R0,R1,R2,R3};
//int KEYPAD_C[] = {C0,C1,C2,C3};
//
//void Keypad_init(){
//	//	DataDir_KEYPAD_port &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
//	//	DataDir_KEYPAD_port |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
//
//	GPIO_PinConfig_t Pincfg;
//
//	Pincfg.GPIO_PinNumber = R0;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = R1;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = R2;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = R3;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = C0;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = C1;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = C2;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	Pincfg.GPIO_PinNumber = C3;
//	Pincfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	Pincfg.GPIO_OutputSpeed = GPIO_SPEED_10;
//	MCAL_GPIO_Init(KEYPAD_port, &Pincfg);
//
//	//	KEYPAD_port = 0xff;
//
//	MCAL_GPIO_WritePort(KEYPAD_port, 0xFF);
//}
//
//char Keypad_getChar(){
//	int i,j;
//	for (i=0; i<4; i++){
//		//		KEYPAD_port |= ((1<<KEYPAD_C[0]) | (1<<KEYPAD_C[1]) | (1<<KEYPAD_C[2]) | (1<<KEYPAD_C[3]));
//		MCAL_GPIO_WritePin(KEYPAD_port, KEYPAD_C[0], GPIO_PIN_SET);
//		MCAL_GPIO_WritePin(KEYPAD_port, KEYPAD_C[1], GPIO_PIN_SET);
//		MCAL_GPIO_WritePin(KEYPAD_port, KEYPAD_C[2], GPIO_PIN_SET);
//		MCAL_GPIO_WritePin(KEYPAD_port, KEYPAD_C[3], GPIO_PIN_SET);
//
//		//		KEYPAD_port &= ~(1<<KEYPAD_C[i]);
//		MCAL_GPIO_WritePin(KEYPAD_port, KEYPAD_C[i], GPIO_PIN_RESET);
//
//		for (j=0; j<4; j++){
//
//			//			if(!(KEYPAD_pin & (1<<KEYPAD_R[j]))){
//			if(MCAL_GPIO_ReadPin(KEYPAD_port, KEYPAD_R[j]) == 0){
//				while (MCAL_GPIO_ReadPin(KEYPAD_port, KEYPAD_R[j]) == 0);
//				switch (i)
//				{
//				case(0):
//											if(j==0) return '7';
//											else if(j==1) return '4';
//											else if(j==2) return '1';
//											else if(j==3) return '!';
//				break;
//				case(1):
//											if(j==0) return '8';
//											else if(j==1) return '5';
//											else if(j==2) return '2';
//											else if(j==3) return '0';
//				break;
//				case(2) :
//											if(j==0) return '9';
//											else if(j==1) return '6';
//											else if(j==2) return '3';
//											else if(j==3) return '=';
//				break;
//				case(3):
//											if(j==0) return '/';
//											else if(j==1) return '*';
//											else if(j==2) return '-';
//											else if(j==3) return '+';
//				break;
//				}
//			}
//		}
//	}
//	return 'A';
//}
