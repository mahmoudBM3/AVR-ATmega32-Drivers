/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : External EEPROM
 * Level  	   : High
 * Description : This file Abstarcts the Interface with External M24C16 Module
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 4/11/2022(November)
 *******************************************************************************/
#include"external_eeprom.h"
#include"twi.h"
uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data) {
	/**Sending the Start Condition**/
	TWI_start();
	if (TWI_getStatus() != TWI_START) {
		return ERROR;
	}
	/**Sending EEPROM Address and the first three bits of the byte address**/
	TWI_writeByte(((uint8) (0xA0)) | ((u16addr & 0x0700) >> 7));
	if (TWI_getStatus() != TWI_MT_SLA_W_ACK) {
		return ERROR;
	}
	/**Sending the rest of the byte address**/
	TWI_writeByte((uint8) u16addr);
	if (TWI_getStatus() != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/**Sending the repeated Start Condition to get the Data**/
	TWI_start();
	if (TWI_getStatus()!= TWI_REP_START) {
		return ERROR;
	}
	/**Sending the device address again but now with read**/
	TWI_writeByte((uint8) (0xA0) | ((u16addr & 0x0700) >> 7) | 1);
	if (TWI_getStatus() != TWI_MT_SLA_R_ACK) {
		return ERROR;
	}
	*u8data = TWI_readByteWithNACK();
	if (TWI_getStatus() != TWI_MR_DATA_NACK) {
		return ERROR;
	}
	TWI_stop();
	return SUCCESS;

}
uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data) {
	/**Sending the Start Condition**/
	TWI_start();
	if (TWI_getStatus() != TWI_START) {
		return ERROR;
	}
	/**Sending EEPROM Address and the first three bits of the byte address**/
	TWI_writeByte(((uint8) (0xA0)) | ((u16addr & 0x0700) >> 7));
	if (TWI_getStatus() != TWI_MT_SLA_W_ACK) {
		return ERROR;
	}
	/**Sending the rest of the byte address**/
	TWI_writeByte((uint8) u16addr);
	if (TWI_getStatus() != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	TWI_writeByte(u8data);
	if (TWI_getStatus() != TWI_MT_DATA_ACK)
		return ERROR;
	/**Sending the Stop Condition**/
	TWI_stop();
	return SUCCESS;

}

