/*
 * SPI.c
 *
 * Created: 7/8/2022 3:49:02 PM
 *  Author: Bolis
 */ 
#include "SPI.h"
#include "../GPIO/GPIO.h"



void MCAL_SPI_Init(S_SPIConfig_t *SPI_CFG){
	
	uint8_t tempRegSPCR = 0 ;
	
	if (SPI_CFG->SPI_MODE == SPI_MODE_MASTER)
	{
		MCAL_GPIO_Init_Pin('B',4,OUTPUT);
		MCAL_GPIO_Init_Pin('B',5,OUTPUT);
		MCAL_GPIO_Init_Pin('B',7,OUTPUT);
		tempRegSPCR |= SPI_CFG->SPI_Clock_Rate;
		tempRegSPCR |= SPI_CFG->SPI_MODE ;
	}
	else{
		//SET_BIT(DDRB,6);
		MCAL_GPIO_Init_Pin('B',6,OUTPUT);
		MCAL_GPIO_Init_Pin('B',4,INPUT);
		MCAL_GPIO_Init_Pin('B',5,INPUT);
		MCAL_GPIO_Init_Pin('B',7,INPUT);
		tempRegSPCR |= SPI_CFG->SPI_MODE;
	}
	tempRegSPCR |= SPI_CFG->SPI_Data_Order;
	tempRegSPCR |= SPI_CFG->SPI_CLK_Polarity;
	tempRegSPCR |= SPI_CFG->SPI_CLK_Phase;
	
	SPCR = tempRegSPCR ;
	//enable SPI
	SET_BIT(SPCR,6);
}

void MCAL_SPI_SendData(uint8_t data){
	SPDR = data ;
	while (!READ_BIT(SPSR,7));
}
uint8_t MCAL_SPI_RecieveData(){
	uint8_t data = 0;
	while (READ_BIT(SPSR,7) == 0);
	data = SPDR;
	return data ; 
}
uint8_t MCAL_SPI_TX_RX(uint8_t TxData){
	uint8_t RxData;
	SPDR = TxData ;
	while (!READ_BIT(SPSR,7));
	RxData = SPDR;
	return RxData ;
}