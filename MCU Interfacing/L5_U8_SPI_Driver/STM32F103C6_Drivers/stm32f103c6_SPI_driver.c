/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#include "stm32f103c6_SPI_driver.h"

SPI_Config_t *G_SPI_Config[2]={NULL,NULL};

#define SPI_SR_TXE		((uint8_t)0x02)
#define SPI_SR_RXNE		((uint8_t)0x01)

#define SPI1_INDEX		0
#define SPI2_INDEX		1


void MCAL_SPI_Init(SPI_Typedef *SPIx,SPI_Config_t *SPI_Config){

	uint16_t TempRegCR1 = 0;
	uint16_t TempRegCR2 = 0;

	if(SPIx == SPI1){

		G_SPI_Config[SPI1_INDEX] =	SPI_Config;
		RCC_EN_CLK_SPI1();
	}
	else if(SPIx == SPI2){

		G_SPI_Config[SPI2_INDEX] =	SPI_Config ;
		RCC_EN_CLK_SPI2();
	}

	//Bit 6 SPE: SPI enable
	TempRegCR1 |= (0x1<<6);

	TempRegCR1 |= SPI_Config->Device_Mode ;

	TempRegCR1 |= SPI_Config->Comm_Mode ;

	TempRegCR1 |= SPI_Config->Frame_Format ;

	TempRegCR1 |= SPI_Config->Data_Size ;

	TempRegCR1 |= SPI_Config->CLKPolarity ;

	TempRegCR1 |= SPI_Config->CLKPhase ;

	TempRegCR1 |= SPI_Config->SPI_BAUDRATE_PS ;


	if(SPI_Config->NSS == SPI_NSS_HARDWARE_MASTER_SS_output_EN){

		TempRegCR2 |= SPI_Config->NSS ;

	}else if(SPI_Config->NSS == SPI_NSS_HARDWARE_MASTER_SS_output_Disable){

		TempRegCR2 &=  SPI_Config->NSS ;

	}else{

		TempRegCR1 |= SPI_Config->NSS ;
	}

	if(SPI_Config->IRQ_EN != SPI_IRQ_EN_NONE){

		TempRegCR2 |= SPI_Config->IRQ_EN;

		if(SPIx == SPI1){

			NVIC_IRQ35_SPI1_EN;
		}
		else if(SPIx == SPI1){

			NVIC_IRQ36_SPI2_EN;
		}
	}

	SPIx->CR1 = TempRegCR1 ;
	SPIx->CR2 = TempRegCR2 ;
}



void MCAL_SPI_DeInit(SPI_Typedef *SPIx){

	if(SPIx == SPI1){
		RCC_Reset_SPI1();
		NVIC_IRQ35_SPI1_Disable;
	}
	else if(SPIx == SPI2){
		RCC_Reset_SPI2();
		NVIC_IRQ36_SPI2_Disable;
	}
}


void MCAL_SPI_SendData(SPI_Typedef *SPIx,uint16_t *pTxBuffer , enum PollingMechism PollingEN){

	if(PollingEN == Polling_enable)
		while(!((SPIx->SR) & SPI_SR_TXE));

	SPIx->DR = *pTxBuffer ;

}

void MCAL_SPI_ReciveData(SPI_Typedef *SPIx,uint16_t *pRxBuffer , enum PollingMechism PollingEN){
	if(PollingEN == Polling_enable)
		while(!((SPIx->SR) & SPI_SR_RXNE));

	*pRxBuffer = SPIx->DR ;
}



void MCAL_SPI_Set_Pins(SPI_Typedef *SPIx){

	GPIO_PinConfig_t PinCFG;
	if(SPIx == SPI1){
		//PA4 : NSS
		//PA5 : SCK
		//PA6 : MISO
		//PA7 : MOSI
		if(G_SPI_Config[SPI1_INDEX]->Device_Mode == SPI_Device_MODE_MASTER){
			//PA4 : NSS
			switch(G_SPI_Config[SPI1_INDEX]->NSS)
			{
			case SPI_NSS_HARDWARE_MASTER_SS_output_EN:

				PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
				PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
				MCAL_GPIO_Init(GPIOA, &PinCFG);

				break;

			case SPI_NSS_HARDWARE_MASTER_SS_output_Disable:

				PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCFG);

				break;
			}


			//PA5 : SCK
			PinCFG.GPIO_PinNumber = GPIO_PIN_5;
			PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &PinCFG);


			//PA6 : MISO
			PinCFG.GPIO_PinNumber = GPIO_PIN_6;
			PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			//PA7 : MOSI
			PinCFG.GPIO_PinNumber = GPIO_PIN_7;
			PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

		}else{
			//PA4 : NSS
			if(G_SPI_Config[SPI1_INDEX]->NSS == SPI_NSS_HARDWARE_SLAVE){
				PinCFG.GPIO_PinNumber = GPIO_PIN_4;
				PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCFG);
			}
			//PA5 : SCK
			PinCFG.GPIO_PinNumber = GPIO_PIN_5;
			PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			//PA6 : MISO
			PinCFG.GPIO_PinNumber = GPIO_PIN_6;
			PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			//PA7 : MOSI
			PinCFG.GPIO_PinNumber = GPIO_PIN_7;
			PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

		}


	}
	else if (SPIx == SPI2)
	{
		//PB12 : NSS
		//PB13 : SCK
		//PB14 : MISO
		//PB15 : MOSI

		if(G_SPI_Config[SPI2_INDEX]->Device_Mode == SPI_Device_MODE_MASTER){
			//PA4 : NSS
			switch(G_SPI_Config[SPI2_INDEX]->NSS)
			{
			case SPI_NSS_HARDWARE_MASTER_SS_output_EN:

				PinCFG.GPIO_PinNumber = GPIO_PIN_12;
				PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
				PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
				MCAL_GPIO_Init(GPIOB, &PinCFG);

				break;

			case SPI_NSS_HARDWARE_MASTER_SS_output_Disable:

				PinCFG.GPIO_PinNumber = GPIO_PIN_12;
				PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCFG);

				break;
			}


			//PA5 : SCK
			PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
			MCAL_GPIO_Init(GPIOB, &PinCFG);


			//PA6 : MISO
			PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCFG);

			//PA7 : MOSI
			PinCFG.GPIO_PinNumber = GPIO_PIN_15;
			PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
			MCAL_GPIO_Init(GPIOB, &PinCFG);

		}else{
			//PA4 : NSS
			if(G_SPI_Config[SPI2_INDEX]->NSS == SPI_NSS_HARDWARE_SLAVE){
				PinCFG.GPIO_PinNumber = GPIO_PIN_12;
				PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCFG);
			}
			//PA5 : SCK
			PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCFG);

			//PA6 : MISO
			PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10;
			MCAL_GPIO_Init(GPIOB, &PinCFG);

			//PA7 : MOSI
			PinCFG.GPIO_PinNumber = GPIO_PIN_15;
			PinCFG.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCFG);
		}

	}

}


void MCAL_SPI_Tx_Rx(SPI_Typedef *SPIx,uint16_t *pBuffer , enum PollingMechism PollingEN){
	if(PollingEN == Polling_enable)
		while(!((SPIx)->SR & SPI_SR_TXE));
	SPIx->DR = *pBuffer ;

	if(PollingEN == Polling_enable)
		while(!((SPIx)->SR & SPI_SR_RXNE));
	*pBuffer = SPIx->DR ;

}




//===============================================================
//       IRQ
//===============================================================

void SPI1_IRQHandler(void){

	struct S_IRQ_SPI irq_src;

	irq_src.TXE = ( (SPI1->SR & (1<<1)) >> 1 );
	irq_src.RXNE = ( (SPI1->SR & (1<<0)) >> 0 );
	irq_src.ERRI = ( (SPI1->SR & (1<<4)) >> 4 );

	G_SPI_Config[SPI1_INDEX]->P_IRQ_CallBack(irq_src);
}



void SPI2_IRQHandler(){

	struct S_IRQ_SPI irq_src;

	irq_src.TXE = ( (SPI1->SR & (1<<1)) >> 1 );
	irq_src.RXNE = ( (SPI1->SR & (1<<0)) >> 0 );
	irq_src.ERRI = ( (SPI1->SR & (1<<4)) >> 4 );

	G_SPI_Config[SPI2_INDEX]->P_IRQ_CallBack(irq_src);
}










