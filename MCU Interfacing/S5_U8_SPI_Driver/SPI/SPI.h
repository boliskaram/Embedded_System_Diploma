/*
 * SPI.h
 *
 * Created: 7/8/2022 3:49:14 PM
 *  Author: Bolis
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../../std_macros.h"

typedef struct{
	uint8_t SPI_MODE ;
	uint8_t SPI_CLK_Polarity ;	
	uint8_t SPI_CLK_Phase ;
	uint8_t SPI_Data_Order;
	uint8_t SPI_Clock_Rate;
	
}S_SPIConfig_t;

#define SPI_MODE_SLAVE		(uint8_t)(0x00)
#define SPI_MODE_MASTER		(uint8_t)(1<<4)

#define SPI_CLK_Polarity_LOW_idel	(uint8_t)(0x00)
#define SPI_CLK_Polarity_HIGH_idel	(uint8_t)(1<<3)

#define SPI_CLK_Phase_1EDGE_DataCapture	(uint8_t)(0x00)
#define SPI_CLK_Phase_2EDGE_DataCapture	(uint8_t)(1<<2)

#define SPI_Data_Order_MSB	(uint8_t)(0x00)
#define SPI_Data_Order_LSB	(uint8_t)(1<<5)

#define SPI_Clock_Rate_PS_4		(uint8_t)(0x00)
#define SPI_Clock_Rate_PS_16	(uint8_t)(1<<0)
#define SPI_Clock_Rate_PS_64	(uint8_t)(1<<1)
#define SPI_Clock_Rate_PS_128	(uint8_t)(1<<0 | 1<<1)


void MCAL_SPI_Init(S_SPIConfig_t *SPI_CFG);
void MCAL_SPI_SendData(uint8_t data);
uint8_t MCAL_SPI_RecieveData();
uint8_t MCAL_SPI_TX_RX(uint8_t data);


#endif /* SPI_H_ */