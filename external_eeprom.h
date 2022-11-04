/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : External EEPROM
 * Level  	   : High
 * Description : This file Abstarcts the Interface with External M24C16 Module
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 4/11/2022(November)
 *******************************************************************************/
#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_
#include"std_types.h"
#define SUCCESS	1
#define	ERROR	0
/*******************************************************************************
 * 							Function Prototypes
 *******************************************************************************/
/**
 * This function Takes the address of the byte in the EEPROM and a pointer to
 * where that byte will be saved and returns the status of this process either
 * a SUCCESS or an ERROR
 * @param u16addr
 * @param u8data
 * @return
 */
uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data);
/**
 * This function Takes the address of the byte in the EEPROM and the data that
 * will be written in that address and returns the status of this process either
 * a SUCCESS or an ERROR
 * @param u16addr
 * @param u8data
 * @return
 */
uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data);



#endif /* EXTERNAL_EEPROM_H_ */
