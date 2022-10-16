/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : USART Module
 * Level  	   : Low
 * Description : This file abstracts the interface with the USART Communication
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 16/10/2022(October)
 *******************************************************************************/
#ifndef UART_H_
#define UART_H_
/*******************************************************************************
 * 							Included Libraries								   *
 *******************************************************************************/
#include"std_types.h"
/*******************************************************************************
 * 							Configuration Struct							   *
 *******************************************************************************/
typedef struct {
	uint32 UART_BaudRate;
	enum {
		ASYNCH = 0, SYNCH = 1
	} UART_Mode;
	enum {
		FIVEBIT = 0, SIXBIT = 1, SEVENBIT = 2, EIGHTBIT = 3
	} UART_CharacterSize;
	enum {
		NORECEIVE = 0, RECEIVEPOLLING = 1, RECEIVEINTERRUPT = 2
	} UART_ReceiveTechnique;
	enum {
		NOTRANSMIT = 0, TRANSMITPOLLING = 1, TRANSMITINTERRUPT = 2
	} UART_TransmitTechnique;
	enum {
		ONEBIT = 0, TWOBIT = 1
	} UART_StopBitMode;
	enum {
		NOPARITY = 0, EVEN = 2, ODD = 3
	} UART_ParityMode;

} UART_ConfigType;
/*******************************************************************************
 * 							GLobal Data Variables							   *
 *******************************************************************************/
extern volatile uint8 g_uartdata;
/*******************************************************************************
 * 							Function Definitions							   *
 *******************************************************************************/
/**
 * USART Initialization Function Takes the Address of the configuration struct
 * as input and initilaizes the USART Peripheral as required by the Configuration
 * **/
void UART_init(UART_ConfigType *config);
/**
 * USART Send Byte Function Sends a given byte as input through the USART
 * Communication Protocol
 * **/
void UART_sendByte(uint8 data);
/**
 * USART Receive Byte Protocol receives a byte by the USART Communication
 * Protocol
 * **/
uint8 UART_receiveByte(void);
/**
 * USART Set Receive Callback Function is usable only in receieve Complete
 * Interrupt Mode which  sets the function that is called by the ISR when the
 * Receive is complete by the USART Communication Protocol
 * **/
void UART_setCallBack(void (*callbackptr)(void));
/**
 * USART Send String Functiion sends a given string as input through the USART
 * Communication Protocol
 * **/
void UART_sendString(char str[]);
/**
 * USART Receive String Functiion receives a string from USART Communication
 * Protocol and stores it in the string given as argument
 * **/
void UART_receiveString(char str[]);

#endif /* UART_H_ */
