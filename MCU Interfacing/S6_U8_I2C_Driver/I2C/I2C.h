/*
 * I2c.h
 *
 * Created: 7/11/2022 7:19:01 PM
 *  Author: Bolis
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "../../std_macros.h"
#define SCL_clk 400000
#define prescaler 1


typedef enum{
	
	start,
	repeated_start
}Repeated_start;

typedef enum{
	ERROR,
	NOT_ERROR,
}ERROR_STATUS;

//void MCAL_I2C_Init();
//void MCAL_I2C_SLAVE_Init();
//
// ERROR_STATUS MCAL_I2C_MASTER_TX(uint8_t address,uint8_t data);
// void generate_start();
// void send_slaveAdress(uint8_t address);
// void Write_data(uint8_t data);
// void generate_stop();
// 
// ERROR_STATUS MCAL_I2C_slave_RX(uint8_t address,uint8_t* data);



void MCAL_I2C_Init();
void MCAL_I2C_MASTER_TX(uint8_t address,uint8_t data);
void generate_start();
void send_slaveAdress(uint8_t address);
void Write_data(uint8_t data);
void generate_stop();

void MCAL_I2C_SLAVE_Init(uint8_t address);
uint8_t MCAL_I2C_slave_RX();

void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(unsigned char ack);

#endif /* I2C_H_ */