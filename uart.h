/*
 * uart.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mabkr
 */

#ifndef UART_H_
#define UART_H_
#include"std_types.h"
typedef struct{
	enum{
		POLLING=0,
		INTERRUPTS=1
	}UART_Technique;

	uint32 UART_BaudRate;

}UART_ConfigType;


#endif /* UART_H_ */
