/*
 * UART.c
 *
 * Created: 7/4/2022 9:59:46 PM
 *  Author: Bolis
 */ 

#include "UART.h"

S_UARTConfig_t *G_UART_Config = NULL ;



void MCAL_UART_Init(S_UARTConfig_t *UART_Config){
	
 	uint8_t UBRR ;
 	UBRR = ((F_CPU/(16 * UART_Config->UART_BaudRate))-1);
	UBRRL = UBRR;
	
	UCSRC |= UART_Config->UART_StopBits;
	
	UCSRC |= UART_Config->UART_Parity;

	UCSRC |= UART_Config->UART_DataSize;
 	
 	
	UCSRB |= UART_Config->UART_MODE;
}

void MCAL_UART_SendData(uint8_t pTxBuffer){
	
	while(!READ_BIT(UCSRA,UDRE));
	UDR = pTxBuffer;
}
uint8_t MCAL_UART_ReceiveData(void){

	while(!(READ_BIT(UCSRA,RXC)));
	uint8_t pRxBuffer = UDR;	
	return pRxBuffer ;
}


// void __vector_13(void) __attribute__((signal,used));
// void __vector_13(void){
// 	if(G_UART_Config->P_IRQ_Callback != NULL){
// 		G_UART_Config->P_IRQ_Callback();
// 	}
//}