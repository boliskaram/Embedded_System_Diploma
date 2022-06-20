/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Bolis
 */

#include "I2C_Slave_EEPROM.h"

void eeprom_init(void){
	I2C_Config_t I2C_CFG;

	I2C_CFG.G_Call_Address_Detection = I2C_G_Call_Address_EN ;
	I2C_CFG.I2C_ACK_CTRL = I2C_ACK_EN ;
	I2C_CFG.I2C_CLK_Speed = I2C_SCLK_SM_100K ;
	I2C_CFG.I2C_Mode = I2C_Mode_I2C ;
	I2C_CFG.P_Slave_EV_CallBack = NULL ;
	I2C_CFG.StretchMode = I2C_StretchMode_EN ;

	MCAL_I2C_GPIO_Set_Pins(I2C1);
	MCAL_I2C_Init(I2C1, &I2C_CFG);
}

unsigned char eeprom_write_Nbytes(uint32_t memory_address,uint8_t* data,uint8_t dataLen){

	uint8_t buffer[256];

	buffer[0]= (uint8_t)(memory_address >> 8); // upper byte memory address

	buffer[1]= (uint8_t)(memory_address); // lower byte memory address

	for(uint8_t i=2 ; i < (dataLen+2) ; i++){
		buffer[i] = data[i-2];
	}

	MCAL_I2C_Master_Tx(I2C1, Slave_Address, buffer , dataLen+2, with_stop, start);

	return 0;
}

unsigned char eeprom_read_Nbytes(uint32_t memory_address,uint8_t* data,uint8_t dataLen){

	uint8_t buffer[2];

	buffer[0]= (uint8_t)(memory_address >> 8); // upper byte memory address

	buffer[1]= (uint8_t)(memory_address); // lower byte memory address

	MCAL_I2C_Master_Tx(I2C1, Slave_Address, buffer , 2, without_stop, start);

	MCAL_I2C_Master_Rx(I2C1, Slave_Address, data, dataLen, with_stop, repeated_start);

	return 0;
}
