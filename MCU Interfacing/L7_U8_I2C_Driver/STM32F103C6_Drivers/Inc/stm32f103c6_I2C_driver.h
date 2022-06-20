/*
 * stm32f103c6_I2C_driver.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_

#include "stdlib.h"
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_RCC_driver.h"


#define I2C_EVENT_MASTER_RYTE_WRITE		((uint32_t)0x00070080)

struct S_I2C_Slave_Address{
	uint16_t EN_Dual_Address;
	uint16_t Primary_Slave_Address;
	uint16_t Secondary_Slave_Address;
	uint32_t I2C_Slave_Address_Mode;		//@ref I2C_Slave_Address_Mode

};

typedef enum{
	 I2C_EV_Stop,
	 I2C_ERROR_AF,
	 I2C_EV_ADDR_Matched,
	 I2c_EV_DATA_REQ,	// the app layer should send the data
	 I2c_EV_DATA_RCV	//	the app layer should send the data
}Slave_State;


typedef enum{
	with_stop,
	without_stop
}Stop_Condation;


typedef enum{
	start,
	repeated_start
}Repeated_start;

typedef enum{
	DISABLE = 0 ,
	ENABLE = 1
}FunctionalState;

typedef enum{
	RESET = 0,
	SET = 1
}FlagStatus;

typedef enum{
	I2C_Write = 0,
	I2C_Read = 1
}I2C_ReadWrite;

typedef enum{
	I2C_FLAG_BUSY = 0,
	EV5,
	EV6,
	EV8,
	EV8_1,
	EV7,
	MASTER_RYTE_WRITE = ((uint32_t)0x00070080),

}Status;

typedef struct{

	uint32_t 	I2C_CLK_Speed;		//@ref I2C_SCLK

	uint32_t 	StretchMode;		//@ref I2C_StretchMode

	uint32_t	I2C_Mode;			//@ref I2C_Mode

	struct S_I2C_Slave_Address	I2C_Slave_Address;

	uint32_t	I2C_ACK_CTRL;		//@ref I2C_ACK_MODE

	uint32_t	G_Call_Address_Detection;	//@ref I2C_G_Call_Address_Detection

	void(* P_Slave_EV_CallBack)(Slave_State state);

}I2C_Config_t;



//@ref I2C_SCLK
#define I2C_SCLK_SM_50K				(50000U)
#define I2C_SCLK_SM_100K			(100000U)
#define I2C_SCLK_FM_200K			(200000U)
#define I2C_SCLK_FM_400K			(400000U)

//@ref I2C_StretchMode
#define I2C_StretchMode_EN			(0x00000000U)
#define I2C_StretchMode_Disable		I2C_CR1_NOSTRETCH


//@ref I2C_Mode
#define I2C_Mode_I2C				(0x00000000U)
#define I2C_Mode_SMBus				I2C_CR1_SMBUS

//@ref I2C_Slave_Address_Mode
#define I2C_Slave_Address_7bit		(00000000U)
#define I2C_Slave_Address_10bit		(uint16_t)(1<<15)

//@ref I2C_ACK_MODE
#define I2C_ACK_EN					I2C_CR1_ACK
#define I2C_ACK_Disable				(uint16_t)(00000000U)

//@ref I2C_G_Call_Address_Detection
#define	I2C_G_Call_Address_EN		I2C_CR1_ENGC
#define	I2C_G_Call_Address_Disable	(uint16_t)(00000000U)


//---------------------------------------------------------------------------------
//							I2C_APIS
//---------------------------------------------------------------------------------


void MCAL_I2C_Init(I2C_Typedef *I2Cx,I2C_Config_t *I2C_CFG);
void MCAL_I2C_DeInit(I2C_Typedef *I2Cx);
void MCAL_I2C_GPIO_Set_Pins(I2C_Typedef *I2Cx);

void MCAL_I2C_Master_Tx(I2C_Typedef *I2Cx,uint16_t devAddr ,uint8_t *dataOut,uint32_t dataLen ,Stop_Condation stop ,Repeated_start start);
void MCAL_I2C_Master_Rx(I2C_Typedef *I2Cx,uint16_t devAddr ,uint8_t *dataOut,uint32_t dataLen ,Stop_Condation stop ,Repeated_start start);



void MCAL_I2C_Slave_Tx(I2C_Typedef *I2Cx , uint8_t data);
uint8_t MCAL_I2C_Slave_Rx(I2C_Typedef *I2Cx);


void I2C_generateStart(I2C_Typedef *I2Cx ,FunctionalState NewState ,Repeated_start start);
void I2C_sendAddress(I2C_Typedef *I2Cx,uint16_t address ,I2C_ReadWrite I2C_RW);
void I2C_generateStop(I2C_Typedef *I2Cx ,FunctionalState NewState);
FlagStatus I2c_GetFlagStatus(I2C_Typedef *I2Cx,Status flag);
void Slave_States(I2C_Typedef *I2Cx , Slave_State state);
void I2C_AcknowledgeConfig(I2C_Typedef *I2Cx , FunctionalState state);


#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */

