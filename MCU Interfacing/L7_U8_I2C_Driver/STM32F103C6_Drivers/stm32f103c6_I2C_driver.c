/*
 * stm32f103c6_I2C_driver.c
 *
 *  Created on: Apr 12, 2022
 *      Author: Bolis
 */

#include "stm32f103c6_I2C_driver.h"

//-----------------------------------------------------------------------
//				Generic Variables

I2C_Config_t G_I2C_Config[2] = {NULL , NULL};

//--------------------------------------------------------------------------
// 				Generic Macros

#define I2C1_Index	0
#define I2C2_Index	1

//-----------------------------------------------------------------------------
void MCAL_I2C_Init(I2C_Typedef *I2Cx,I2C_Config_t* I2C_CFG){

	uint16_t freqrange=0 , tmpReg=0 , result=0;
	uint32_t Pclk = 8000000;
	if(I2Cx == I2C1){
		G_I2C_Config[I2C1_Index]= *I2C_CFG;
		RCC_EN_CLK_I2C1();
	}
	else if(I2Cx == I2C2){
		G_I2C_Config[I2C2_Index]= *I2C_CFG;
		RCC_EN_CLK_I2C1();
	}

	if(I2C_CFG->I2C_Mode == I2C_Mode_I2C){

		// to congig CR2 and put frequency
		tmpReg = I2Cx->CR2;

		tmpReg &= ~(I2C_CR2_FREQ_Msk);

		Pclk = MCAL_RCC_GetPCLK1Freq();
		freqrange = (uint16_t)(Pclk/1000000);

		tmpReg |= freqrange;
		// write to CR2
		I2Cx->CR2 = tmpReg;

		I2Cx->CR1 &= ~(I2C_CR1_PE) ;

		tmpReg = 0;


		if((I2C_CFG->I2C_CLK_Speed == I2C_SCLK_SM_50K) || (I2C_CFG->I2C_CLK_Speed == I2C_SCLK_SM_100K)){

			result = (uint16_t)(Pclk / (I2C_CFG->I2C_CLK_Speed * 2 )) ;

			tmpReg |= result;

			I2Cx->CCR = tmpReg ;

			I2Cx->TRISE = freqrange + 1;


		}else{
			// if FM not supported now
		}

		//set CR1 config
		tmpReg = I2Cx->CR1;

		tmpReg |= (uint16_t)(I2C_CFG->I2C_ACK_CTRL | I2C_CFG->G_Call_Address_Detection |I2C_CFG->I2C_Mode | I2C_CFG->StretchMode);

		I2Cx->CR1 = tmpReg;

		tmpReg = 0;

		if(I2C_CFG->I2C_Slave_Address.EN_Dual_Address == 1){
			tmpReg = I2C_OAR2_ENDUAL;
			tmpReg |= I2C_CFG->I2C_Slave_Address.Secondary_Slave_Address << I2C_OAR2_ADD2_Pos ;
			I2Cx->OAR2 = tmpReg;
		}
		tmpReg =  0;
		tmpReg |= I2C_CFG->I2C_Slave_Address.Primary_Slave_Address << 1 ;
		tmpReg |= I2C_CFG->I2C_Slave_Address.I2C_Slave_Address_Mode;
		I2Cx->OAR1 = tmpReg;
	}

	else{
		// if SMBUS not supported now
	}

	if(I2C_CFG->P_Slave_EV_CallBack != NULL){
		// En Interrupt
		I2Cx->CR2 |= (I2C_CR2_ITBUFEN);
		I2Cx->CR2 |= (I2C_CR2_ITERREN);
		I2Cx->CR2 |= (I2C_CR2_ITEVTEN);

		if(I2Cx == I2C1){

			NVIC_IRQ31_I2C1_EV_EN;
			NVIC_IRQ32_I2C1_ER_EN;
		}
		else if(I2Cx == I2C1){
			NVIC_IRQ33_I2C2_EV_EN;
			NVIC_IRQ34_I2C2_ER_EN;
		}
		I2Cx->SR1 = 0;
		I2Cx->SR2 = 0;
	}

	I2Cx->CR1 |= I2C_CR1_PE;
}

void MCAL_I2C_DeInit(I2C_Typedef *I2Cx){

	if(I2Cx == I2C1){
		NVIC_IRQ31_I2C1_EV_Disable;
		NVIC_IRQ32_I2C1_ER_Disable;
		RCC_Reset_I2C1();
	}
	else if(I2Cx == I2C2){
		NVIC_IRQ33_I2C2_EV_Disable;
		NVIC_IRQ34_I2C2_ER_Disable;
		RCC_Reset_I2C2();
	}
}

void MCAL_I2C_GPIO_Set_Pins(I2C_Typedef *I2Cx){

	GPIO_PinConfig_t PinCFG;
	if(I2Cx == I2C1){
		PinCFG.GPIO_PinNumber = GPIO_PIN_6;
		PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD ;
		PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10 ;
		MCAL_GPIO_Init(GPIOB, &PinCFG);

		PinCFG.GPIO_PinNumber = GPIO_PIN_7;
		PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD ;
		PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10 ;
		MCAL_GPIO_Init(GPIOB, &PinCFG);
	}
	else if(I2Cx == I2C2){
		PinCFG.GPIO_PinNumber = GPIO_PIN_10;
		PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD ;
		PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10 ;
		MCAL_GPIO_Init(GPIOB, &PinCFG);

		PinCFG.GPIO_PinNumber = GPIO_PIN_11;
		PinCFG.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD ;
		PinCFG.GPIO_OutputSpeed = GPIO_SPEED_10 ;
		MCAL_GPIO_Init(GPIOB, &PinCFG);
	}
}

void MCAL_I2C_Master_Rx(I2C_Typedef *I2Cx,uint16_t devAddr ,uint8_t *dataOut,uint32_t dataLen ,Stop_Condation stop ,Repeated_start start){

	int i;

	uint8_t index = I2Cx == I2C1 ? I2C1_Index : I2C2_Index;
	// to send start bit
	I2C_generateStart(I2Cx, ENABLE, start);

	// wait to receive ACK about send start bit
	while(!I2c_GetFlagStatus(I2Cx, EV5));

	// write address
	I2C_sendAddress(I2Cx, devAddr, I2C_Read);

	// wait to address sent flag
	while(!(I2c_GetFlagStatus(I2Cx, EV6)));


	I2C_AcknowledgeConfig(I2Cx , ENABLE);

	if(dataLen){
		// receive data
		for (i = dataLen; i > 0; i--) {
			// wait to address sent flag
			while(!I2c_GetFlagStatus(I2Cx, EV7));

			*dataOut = I2Cx->DR;
			dataOut++;
		}
		I2C_AcknowledgeConfig(I2Cx , DISABLE);
	}

	// set stop
	if(stop == with_stop)
		I2C_generateStop(I2Cx, ENABLE);

	if(G_I2C_Config[index].I2C_ACK_CTRL == I2C_ACK_EN){
		I2C_AcknowledgeConfig(I2Cx  , ENABLE);
	}

}

void I2C_AcknowledgeConfig(I2C_Typedef *I2Cx , FunctionalState state){
	if(state != DISABLE){
		I2Cx->CR1 |= I2C_CR1_ACK;
	}
	else{
		I2Cx->CR1 &= ~(I2C_CR1_ACK);
	}
}
void MCAL_I2C_Master_Tx(I2C_Typedef *I2Cx,uint16_t devAddr ,uint8_t *dataOut,uint32_t dataLen ,Stop_Condation stop ,Repeated_start start){

	int i =0 ;
	// to send start bit
	I2C_generateStart(I2Cx, ENABLE, start);

	// wait to receive ACK about send start bit
	while(!(I2c_GetFlagStatus(I2Cx, EV5)));

	// write address
	I2C_sendAddress(I2Cx, devAddr, I2C_Write);

	// wait to address sent flag
	while(!(I2c_GetFlagStatus(I2Cx, EV6)));

	// to check master BUSY TXE flags
	while(!(I2c_GetFlagStatus(I2Cx, MASTER_RYTE_WRITE)));

	// send Data
	for (i = 0; i < dataLen; ++i) {
		I2Cx->DR = dataOut[i];
		// to check Tx buffer is empty
		while(!(I2c_GetFlagStatus(I2Cx, EV8)));
	}

	// set stop
	if(stop == with_stop)
		I2C_generateStop(I2Cx, ENABLE);

}


void I2C_generateStart(I2C_Typedef *I2Cx ,FunctionalState NewState ,Repeated_start start){

	if(start != repeated_start){

		// check BUS is idle or BUSY
		while(I2c_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));
	}

	if(NewState != DISABLE){

		I2Cx->CR1 |= I2C_CR1_START ;
	}else{
		I2Cx->CR1 &= ~(I2C_CR1_START) ;
	}
}

void I2C_sendAddress(I2C_Typedef *I2Cx,uint16_t address ,I2C_ReadWrite I2C_RW){

	address = address << 1 ;
	if(I2C_RW != I2C_Write){

		address |= 1<<0 ;
	}
	else{
		address &= ~(1<<0);
	}

	I2Cx->DR =	address ;
}


void I2C_generateStop(I2C_Typedef *I2Cx ,FunctionalState NewState){

	if(NewState != DISABLE){

		I2Cx->CR1 |= I2C_CR1_STOP ;
	}
	else{
		I2Cx->CR1 &= ~(I2C_CR1_STOP) ;
	}
}

FlagStatus I2c_GetFlagStatus(I2C_Typedef *I2Cx,Status flag){
	FlagStatus bitstatus = RESET;
	uint32_t flag1 = 0 ,flag2 = 0 , lastEvent = 0;
//	volatile uint32_t dummyRead;

	switch(flag){
	case I2C_FLAG_BUSY:
		if((I2Cx->SR2) & (I2C_SR2_BUSY))
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;

	case EV5:
		if((I2Cx->SR1) & (I2C_SR1_SB))
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;

	case EV6:
		if((I2Cx->SR1) & (I2C_SR1_ADDR))
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;

	case MASTER_RYTE_WRITE:
		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2 << 16;
		lastEvent = (flag1 | flag2) & ((uint32_t)0x00FFFFFF);
		if((lastEvent & flag) == flag)
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;

	case EV8_1:
	case EV8:
		if((I2Cx->SR1) & (I2C_SR1_TXE))
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;
	case EV7:
		if((I2Cx->SR1) & (I2C_SR1_RXNE))
			bitstatus = SET;
		else
			bitstatus = RESET;
		break;

	}
	return bitstatus;
}


void MCAL_I2C_Slave_Tx(I2C_Typedef *I2Cx , uint8_t data){
	I2Cx->DR = data;
}


uint8_t MCAL_I2C_Slave_Rx(I2C_Typedef *I2Cx){

	uint8_t data;
	data = (uint8_t)(I2Cx->DR);
	return data;
}


void I2C1_EV_IRQHandler(void){

	volatile uint32_t dummyRead = 0 ;
	I2C_Typedef *I2Cx = I2C1 ;
	uint32_t t1,t2,t3;

	t1 = I2Cx->CR2 & (I2C_CR2_ITEVTEN);
	t2 = I2Cx->CR2 & (I2C_CR2_ITBUFEN);
	t3 = I2Cx->SR1 & (I2C_SR1_STOPF);

	if(t1 && t3){
		I2Cx->CR1 |= 0x0000;
		Slave_States(I2Cx,I2C_EV_Stop);
	}

	t3 = I2Cx->SR1 & (I2C_SR1_ADDR);

	if(t1 && t3){

		if(I2Cx->SR2 & (I2C_SR2_MSL)){

		}
		else{

			dummyRead = I2Cx->SR1;
			dummyRead = I2Cx->SR2;
			Slave_States(I2Cx ,I2C_EV_ADDR_Matched);
		}
	}

	t3 = I2Cx->SR1 & (I2C_SR1_TXE);

	if(t1 && t2 && t3){

		if(I2Cx->SR2 & (I2C_SR2_MSL)){

		}
		else{
			Slave_States(I2Cx,I2c_EV_DATA_REQ);
		}
	}

	t3 = I2Cx->SR1 & (I2C_SR1_RXNE);

	if(t1 && t2 && t3){

		if(I2Cx->SR2 & (I2C_SR2_MSL)){

		}
		else{
			Slave_States(I2Cx,I2c_EV_DATA_RCV);
		}
	}


}

void Slave_States(I2C_Typedef *I2Cx , Slave_State state){

	uint8_t index = I2Cx == I2C1 ?I2C1_Index : I2C2_Index;

	switch (state) {
	case I2C_ERROR_AF:
		if(I2Cx->SR2 & (I2C_SR2_TRA)){

		}

		break;

	case I2C_EV_Stop:
		if(I2Cx->SR2 & (I2C_SR2_TRA)){

			G_I2C_Config[index].P_Slave_EV_CallBack(I2C_EV_Stop);
		}

		break;

	case I2C_EV_ADDR_Matched:

			G_I2C_Config[index].P_Slave_EV_CallBack(I2C_EV_ADDR_Matched);

		break;

	case I2c_EV_DATA_REQ:
		if(I2Cx->SR2 & (I2C_SR2_TRA)){

			G_I2C_Config[index].P_Slave_EV_CallBack(I2c_EV_DATA_REQ);
		}
		break;

	case I2c_EV_DATA_RCV:

		if(!(I2Cx->SR2 & (I2C_SR2_TRA))){

			G_I2C_Config[index].P_Slave_EV_CallBack(I2c_EV_DATA_RCV);
		}

		break;
	}
}


void I2C1_ER_IRQHandler(void){

}

void I2C2_EV_IRQHandler(void){

}

void I2C2_ER_IRQHandler(void){

}

