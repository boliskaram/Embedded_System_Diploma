/*
 * I2C.c
 *
 * Created: 7/11/2022 7:18:19 PM
 *  Author: Bolis
 */ 

#include "I2C.h"

void MCAL_I2C_MASTER_Init(){
	
	TWBR = (unsigned char) (((F_CPU/SCL_clk)-16)/(2*prescaler));
	TWSR = 0 ; 
}
void MCAL_I2C_MASTER_TX(uint8_t address,uint8_t data){
 	
 	generate_start();
	while ((TWSR)!=0x08);

	send_slaveAdress(address);
	while ((TWSR) != 0x18);
 
 	Write_data(data);
	while ((TWSR) != 0x28);

	
	generate_stop();

}

void generate_start(){
	//enable TWI
	SET_BIT(TWCR,TWEN);
	// set TWSTA to transmit start condition
	SET_BIT(TWCR,TWSTA);
	// clear interrupt flag by write 1
	SET_BIT(TWCR,TWINT);
	// wait flag set to know start transmitted
	while(!READ_BIT(TWCR,TWINT));
}
void send_slaveAdress(uint8_t address){
	//write slave address with write operation
	TWDR = address;
	//enable TWI
	SET_BIT(TWCR,TWEN);
	// clear interrupt flag by write 1
	SET_BIT(TWCR,TWINT);
	// wait flag set to know address transmitted
	while(!READ_BIT(TWCR,TWINT));
}
void Write_data(uint8_t data){
	// write data when TWINT high
	TWDR = data;
	//enable TWI
	SET_BIT(TWCR,TWEN);
	// clear interrupt flag by write 1
	SET_BIT(TWCR,TWINT);
	// wait flag set to know data transmitted
	while(!READ_BIT(TWCR,TWINT));
 }

void generate_stop(){
	TWCR = 0x00;
	// clear interrupt flag by write 1
	SET_BIT(TWCR,TWINT);
	// set TWSTO to transmit stop condition
	SET_BIT(TWCR,TWSTO);
	//enable TWI
	SET_BIT(TWCR,TWEN);
}

void MCAL_I2C_SLAVE_Init(uint8_t address){
	// set address to salve
	TWAR =  address ;
}
uint8_t MCAL_I2C_slave_RX(){
	uint8_t data;
	TWCR = 0x00;
	
	// clear interrupt flag by write 1
	SET_BIT(TWCR,TWINT);
	// set TWEA to transmit ACK
	SET_BIT(TWCR,TWEA);
	//enable TWI
	SET_BIT(TWCR,TWEN);
	
	while(!READ_BIT(TWCR,TWINT));
	while ((TWSR) != 0x60);             // own SLA+W(0) has been transmitted and ACK has been returned
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!READ_BIT(TWCR,TWINT));
	while ((TWSR) != 0x80);          // Data has been transmitted and ACK has been returned
	data = TWDR;
	return data;
}
