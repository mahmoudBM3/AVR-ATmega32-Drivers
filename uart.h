/*
 * uart.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mabkr
 */

#ifndef UART_H_
#define UART_H_
#include"std_types.h"
typedef struct {
	enum {
		NORMAL = 0, DOUBLESPEED = 1
	} UART_SpeedMode;
	enum {
		NOPARITY = 0, EVEN = 2, ODD = 3
	} UART_ParityMode;
	enum {
		FIVEBIT = 0, SIXBIT = 1, SEVENBIT = 2, EIGHTBIT = 3, NINEBIT = 7
	} UART_CharacterSize;
	enum {
		ASYNCH = 0, SYNCH = 1
	} UART_Mode;
	enum {
		NORECEIVE = 0, RECEIVEPOLLING = 1, RECEIVEINTERRUPT = 2
	} UART_ReceiveTechnique;
	enum {
		NOTRANSMIT = 0, TRANSMITPOLLING = 1, TRANSMITINTERRUPT = 2
	} UART_TransmitTechnique;
	enum {
		ONEBIT = 0, TWOBIT = 1
	} UART_StopBitMode;
	uint32 UART_BaudRate;

} UART_ConfigType;
void UART_init(UART_ConfigType *config);
void UART_sendByte(uint8 data);
uint8 UART_receiveByte(void);

#endif /* UART_H_ */
