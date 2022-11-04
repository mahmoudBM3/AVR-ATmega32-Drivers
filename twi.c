/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Two-Wire Interface Module
 * Level  	   : Low
 * Description : This file abstracts the interface with the TWI Communication
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 1/11/2022(November)
 *******************************************************************************/
#include "twi.h"

#include<avr/io.h>
#include"common_macros.h"

void TWI_init(const TWI_ConfigType *config) {
	/**Selecting the TWI Bitrate**/
	TWBR = config->TWI_Bitrate;
	/**Selecting the TWI Prescaler**/
	TWSR = (TWSR & 0xFC) | (config->TWI_Prescaler & 0x03);
	/**Selecting TWI unit Slave Address**/
	TWAR = (config->TWI_Address << 1);
	/**Enabling TWI**/
	SET_BIT(TWCR, TWEN);
}
void TWI_start(void) {

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT)) {
	}

}
void TWI_stop(void) {
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
void TWI_writeByte(uint8 data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT)) {
	}
}
uint8 TWI_readByteWithACK(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (BIT_IS_CLEAR(TWCR, TWINT)) {
	}
	return TWDR;
}
uint8 TWI_readByteWithNACK(void) {
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (BIT_IS_CLEAR(TWCR, TWINT)) {
	}
	return TWDR;
}

uint8 TWI_getStatus(void) {
	return (TWSR&0xF8) ;
}
