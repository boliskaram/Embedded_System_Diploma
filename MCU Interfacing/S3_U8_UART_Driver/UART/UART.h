/*
 * UART.h
 *
 * Created: 7/4/2022 9:59:57 PM
 *  Author: Bolis
 */ 


#ifndef UART_H_
#define UART_H_

#include "../../std_macros.h"
#include "../GPIO/GPIO.h"
#define F_CPU 8000000UL

#define NULL 0

typedef struct{
	uint8_t UART_MODE ; 
	uint8_t UART_Parity;
	uint8_t UART_StopBits;
	uint8_t UART_DataSize;
	uint32_t UART_BaudRate;
	//uint8_t UART_IRQ_EN;
	//void(*P_IRQ_Callback)(void);
	
}S_UARTConfig_t;



#define UART_MODE_TX	(uint8_t)(1<<3)
#define UART_MODE_RX	(uint8_t)(1<<4)
#define UART_MODE_TX_RX	(uint8_t) (1<<3)|(1<<4)

#define UART_Parity_NONE	(uint8_t) 0
#define UART_Parity_EVEN	(uint8_t) (2<<4)
#define UART_Parity_ODD		(uint8_t) (3<<4)


#define UART_StopBits_ONE	(uint8_t) 0x00
#define UART_StopBits_TWO	(uint8_t) (1<<3)


#define UART_DataSize_5bits	(uint8_t) 0
#define UART_DataSize_6bits	(uint8_t) (1<<1)
#define UART_DataSize_7bits	(uint8_t) (2<<1)
#define UART_DataSize_8bits	(uint8_t) (1<<1)|(1<<2)

#define UART_BaudRate_2400		2400
#define UART_BaudRate_4800		4800
#define UART_BaudRate_9600		9600
#define UART_BaudRate_19200		19200
#define UART_BaudRate_115200	115200

#define UART_IRQ_EN_NONE		0
#define UART_IRQ_EN_RXCIE		(uint8_t)(1<<7)
#define UART_IRQ_EN_TXCIE		(uint8_t)(1<<6)


enum Polling_mechism{
	enable,
	disable
};


void MCAL_UART_Init(S_UARTConfig_t *UART_Config);
void MCAL_UART_SendData(uint8_t pTxBuffer);
uint8_t MCAL_UART_ReceiveData(void);

#endif /* UART_H_ */