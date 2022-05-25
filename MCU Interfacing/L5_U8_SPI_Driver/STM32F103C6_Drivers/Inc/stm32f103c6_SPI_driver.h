/*
 * stm32f103c6_SPI_driver.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_

#include "stdlib.h"
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"


struct S_IRQ_SPI{
	uint8_t TXE:1;
	uint8_t RXNE:1;
	uint8_t ERRI:1;
	uint8_t Reserved:5;
};



typedef struct {
	uint16_t		Device_Mode ; 				//SPI operation mode @ref SPI_Device_MODE_define

	uint16_t	 	Comm_Mode ;					//SPI bidirectional mode state @ref SPI_Comm_Mode_define

	uint16_t		Frame_Format ;				//LSB or MSB @ref SPI_Frame_Format_define

	uint16_t		Data_Size ;					// @ref SPI_Data_Size_define

	uint16_t		CLKPolarity ;				//@ref SPI_CLKPolarity_define

	uint16_t		CLKPhase ; 					//@ref SPI_CLKPhase_define

	uint16_t		NSS;						//@ref SPI_NSS_define

	uint16_t		SPI_BAUDRATE_PS;				//@ref SPI_BAUDRATE_PS_define

	uint16_t 	IRQ_EN ;					//ref SPI_IRQ_EN_define


	void(* P_IRQ_CallBack)(struct S_IRQ_SPI irq_src);			//set the c function() which will be called once the Irq happen


}SPI_Config_t;

//=========================================================================
//Reference Macros

//@ref SPI_Device_MODE_define
#define	SPI_Device_MODE_SLAVE	(0x00000000)	//0: Slave configuration
#define	SPI_Device_MODE_MASTER	(0x1<<2)		//1: Master configuration

//@ref SPI_Comm_Mode_define
#define SPI_Comm_Mode_2LINES			(0x00000000)		//0: 2-line unidirectional data mode selected
#define SPI_Comm_Mode_2LINES_RXONLY		(0x1<<10)			//1: Output disabled (Receive-only mode)
#define SPI_Comm_Mode_1LINES_RXONLY		(0x1<<15 )			//1: 1-line bidirectional data mode selected	0: Output disabled (receive-only mode)
#define SPI_Comm_Mode_1LINES_TXONLY		(0x1<<15 | 0x1<<14) //1: 1-line bidirectional data mode selected  1: Output enabled (transmit-only mode)

//@ref SPI_Frame_Format_define
#define SPI_Frame_Format_MSB_SEND_FIRST		(0x00000000)	//0: MSB transmitted first
#define SPI_Frame_Format_LSB_SEND_FIRST		(0x1<<7)		//1: LSB transmitted first

//@ref SPI_Data_Size_define
#define SPI_Data_Size_8B					(0x00000000)	//0: 8-bit data frame format is selected for transmission/reception
#define SPI_Data_Size_9B					(0x1<<11)   	//1: 16-bit data frame format is selected for transmission/reception

//@ref SPI_CLKPolarity_define
#define SPI_CLKPolarity_LOW_idel			(0x00000000)	//0: CK to 0 when idle
#define SPI_CLKPolarity_HIGH_idel			(0x1<<1)		//1: CK to 1 when idle

//@ref SPI_CLKPhase_define
#define SPI_CLKPhase_1EDGE_1DATA_capture	(0x00000000)	//0: The first clock transition is the first data capture edge
#define SPI_CLKPhase_2EDGE_1DATA_capture	(0x1<<0)		//1: The second clock transition is the first data capture edge

//@ref SPI_NSS_define
#define SPI_NSS_HARDWARE_SLAVE						(0x00000000) //0: Software slave management disabled
#define SPI_NSS_HARDWARE_MASTER_SS_output_EN 		(0x1<<2)	 //1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work in a multimaster environment.
#define SPI_NSS_HARDWARE_MASTER_SS_output_Disable	~(0x1<<2) //0: SS output is disabled in master mode and the cell can work in multimaster configuration

#define SPI_NSS_SOFTWARE_Internal_RESET					(0x1<<9) //1: Software slave management enabled olny
#define SPI_NSS_SOFTWARE_Internal_SET					(0x1<<9 | 0x1<<8)


//@ref SPI_BAUDRATE_PS_define
#define SPI_BAUDRATE_PS_2					(0x00000000)
#define SPI_BAUDRATE_PS_4					(0b001<<3)
#define SPI_BAUDRATE_PS_8					(0b010<<3)
#define SPI_BAUDRATE_PS_16					(0b011<<3)
#define SPI_BAUDRATE_PS_32					(0b100<<3)
#define SPI_BAUDRATE_PS_64					(0b101<<3)
#define SPI_BAUDRATE_PS_128					(0b110<<3)
#define SPI_BAUDRATE_PS_256					(0b111<<3)


//ref SPI_IRQ_EN_define

#define SPI_IRQ_EN_NONE						(0x00000000)
#define SPI_IRQ_EN_TXIE						(0x1 << 7)
#define SPI_IRQ_EN_RXNEIE					(0x1 << 6)
#define SPI_IRQ_EN_ERRIE					(0x1 << 5)



enum PollingMechism{
	Polling_enable,
	Polling_disable
};

//-------------------------------------------------------------------
//						APIS Supported by MCAL Driver
//-------------------------------------------------------------------



void MCAL_SPI_Init(SPI_Typedef *SPIx ,SPI_Config_t *SPI_Config);
void MCAL_SPI_DeInit(SPI_Typedef *SPIx);
void MCAL_SPI_SendData(SPI_Typedef *SPIx,uint16_t *pTxBuffer , enum PollingMechism PollingEN);
void MCAL_SPI_ReciveData(SPI_Typedef *SPIx,uint16_t *pRxBuffer , enum PollingMechism PollingEN);
void MCAL_SPI_Set_Pins(SPI_Typedef *SPIx);
void MCAL_SPI_Tx_Rx(SPI_Typedef *SPIx,uint16_t *pBuffer , enum PollingMechism PollingEN);






#endif /* INC_STM32F103C6_SPI_DRIVER_H_ */

