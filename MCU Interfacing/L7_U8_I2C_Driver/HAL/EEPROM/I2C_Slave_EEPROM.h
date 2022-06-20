/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Bolis
 */

#ifndef EEPROM_I2C_SLAVE_EEPROM_H_
#define EEPROM_I2C_SLAVE_EEPROM_H_

#include "stm32f103c6_I2C_driver.h"

#define Slave_Address	0x2A

void eeprom_init(void);
unsigned char eeprom_write_Nbytes(uint32_t memory_address,uint8_t* data,uint8_t dataLen);
unsigned char eeprom_read_Nbytes(uint32_t memory_address,uint8_t* data,uint8_t dataLen);

#endif /* EEPROM_I2C_SLAVE_EEPROM_H_ */
