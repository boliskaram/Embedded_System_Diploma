/*
 * stm32f103c6_USART_driver.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#ifndef INC_STM32F103C6_USART_DRIVER_H_
#define INC_STM32F103C6_USART_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_RCC_driver.h"


typedef struct {

	uint8_t USART_Mode;				// to enable TX and RX
									//@ref USART_Mode_define

	uint32_t BaudRate;				// to set baudrate
									//@ref USART_BaudRate_define

	uint8_t	Payload_Length;			//number of data bits
									//@ref USART_Payload_Length_define

	uint8_t Parity;					//parity mode
									//@ref USART_Parity_define

	uint8_t StopBits; 				//number of stop bits
									//@ref USART_StopBits_define

	uint8_t HwFlowCtl;				//hardware flow control enable or disable
									//@ref USART_HwFlowCtl_define

	uint8_t IRQ_EN;					//En or Disable uart Irq tx/rx
									//@ref USART_IRQ_EN_define

	void(* P_IRQ_CallBack)(void); 	//set the c function() which will be called once the Irq happen

}USART_Config_t;

//=========================================================================
//Reference Macros

//@ref USART_Mode_define
#define USART_Mode_Tx			(uint32_t)(1<<3)
#define USART_Mode_Rx			(uint32_t)(1<<2)
#define USART_Mode_Tx_RX		((uint32_t)(1<<2 | 1<<3))

//@ref USART_BaudRate_define
#define USART_BaudRate_2400			2400
#define USART_BaudRate_9600			9600
#define USART_BaudRate_19200		19200
#define USART_BaudRate_57600		57600
#define USART_BaudRate_115200		115200
#define USART_BaudRate_230400		230400
#define USART_BaudRate_460800		460800
#define USART_BaudRate_921600		921600
#define USART_BaudRate_2250000		2250000
#define USART_BaudRate_4500000		4500000

//@ref USART_Payload_Length_define
#define USART_Payload_Length_8B		(uint32_t)(0)
#define USART_Payload_Length_9B		(uint32_t)(1<<12)

//@ref USART_Parity_define
#define USART_Parity_NONE			(uint32_t)(0)
#define USART_Parity_EVEN			(uint32_t)(1<<10)
#define USART_Parity_ODD			((uint32_t)(1<<9 | 1<<10))

//@ref USART_StopBits_define
#define USART_StopBits_half			(uint32_t)(1<<12)
#define USART_StopBits_1			(uint32_t)(0)
#define USART_StopBits_1_half		(uint32_t)(3<<12)
#define USART_StopBits_2			(uint32_t)(2<<12)

//@ref USART_HwFlowCtl_define
#define USART_HwFlowCtl_NONE		(uint32_t)(0)
#define USART_HwFlowCtl_CTS			(uint32_t)(1<<9)
#define USART_HwFlowCtl_RTS			(uint32_t)(1<<8)
#define USART_HwFlowCtl_RTS_CTS		((uint32_t)(1<<8 |1<<9))

//@ref USART_IRQ_EN_define
#define USART_IRQ_EN_NONE			(uint32_t)(0)
#define USART_IRQ_EN_TXE			(uint32_t)(1<<7) 	//Transmit data register empty
#define USART_IRQ_EN_TC				(uint32_t)(1<<6) 	//Transmission complete
#define USART_IRQ_EN_RXNEIE			(uint32_t)(1<<5)	//Received data ready to be read & Overrun error detected
#define USART_IRQ_EN_PE				(uint32_t)(1<<8)	//Parity error

enum Polling_mechism{
	enable,
	disable
};


#define USARTDIV(_PCLK_,_BAUD_)   				(uint32_t) (_PCLK_ / (16 * _BAUD_) )
#define USARTDIV_MUL100(_PCLK_,_BAUD_)   		(uint32_t) ( (25 * _PCLK_) / (4 * _BAUD_))
#define Mantissa(_PCLK_,_BAUD_)   				(uint32_t) (USARTDIV(_PCLK_,_BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)			(uint32_t) (USARTDIV(_PCLK_,_BAUD_) * 100)
#define DIV_Fraction(_PCLK_,_BAUD_)				(uint32_t) (((USARTDIV_MUL100(_PCLK_,_BAUD_) - Mantissa_MUL100(_PCLK_,_BAUD_)) * 16 ) / 100 )
#define USART_BBR_Register(_PCLK_,_BAUD_)		( ( Mantissa(_PCLK_,_BAUD_) )<<4) | ( ( DIV_Fraction(_PCLK_,_BAUD_) ) & 0xF )


//==================================================================================
//					API
//==========================================================================


void MCAL_USART_Init(USART_Typedef *USARTx,USART_Config_t* USART_Config);
void MCAL_USART_DeInit(USART_Typedef *USARTx);

void MCAL_USART_GPIO_Set_Pins(USART_Typedef *USARTx);

void MCAL_USART_SendData(USART_Typedef*  USARTx , uint16_t *pTxBuffer,enum Polling_mechism pollingEn);
void MCAL_USART_ReceiveData(USART_Typedef* USARTx, uint16_t *pRxBuffer,enum Polling_mechism pollingEn);

void MCAL_USART_Wait_TC(USART_Typedef *USARTx);


#endif /* INC_STM32F103C6_USART_DRIVER_H_ */
