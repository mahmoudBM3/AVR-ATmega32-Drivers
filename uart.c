#include<avr/io.h>
#include<avr/interrupt.h>
#include"uart.h"
#include"common_macros.h"
UART_ConfigType g_uartconfig;
volatile uint8 g_uartdata = 0;
void (*g_callbackptr)(void) = NULL_PTR;
ISR(USART_RXC_vect) {
	g_uartdata=UDR;
	if (g_callbackptr != NULL_PTR) {
		g_callbackptr();
	}
}
void UART_init(UART_ConfigType *config) {

	g_uartconfig = *config;
	/**Enabling Double speed mode*/
	SET_BIT(UCSRA, U2X);
	/**Enabling Receiving and Transmitting*/
	if (config->UART_ReceiveTechnique != NORECEIVE) {
		SET_BIT(UCSRB, RXEN);
	} else {
		CLEAR_BIT(UCSRB, RXEN);
	}
	if (config->UART_TransmitTechnique != NOTRANSMIT) {
		SET_BIT(UCSRB, TXEN);
	} else {
		CLEAR_BIT(UCSRB, TXEN);
	}
	/**UCSRC init*/
	SET_BIT(UCSRC, URSEL);
	/**Selecting Asynchronous or Synchronous mode*/
	if (config->UART_Mode == ASYNCH) {
		CLEAR_BIT(UCSRC, UMSEL);
	} else {
		SET_BIT(UCSRC, UMSEL);
	}
	/**Choosing Parity Error check*/
	UCSRC = (UCSRC & 0xCF) | ((config->UART_ParityMode & 0x03) << UPM0);
	/**Selecting stop bit*/
	if (config->UART_StopBitMode == ONEBIT) {
		CLEAR_BIT(UCSRC, USBS);
	} else if (config->UART_StopBitMode == TWOBIT) {
		SET_BIT(UCSRC, USBS);
	}
	/**Selecting Character Size*/
	UCSRC = (UCSRC & 0xF9) | ((config->UART_CharacterSize & 0x03) << UCSZ0);
	/**Selecting the BAUD Rate*/
	uint16 UBRR_value = ((uint32) F_CPU / (8 * config->UART_BaudRate) - 1);
	UBRRL = UBRR_value;
	UBRRH = UBRR_value >> 8;
	if (config->UART_ReceiveTechnique == RECEIVEINTERRUPT) {
		SET_BIT(SREG, 7);
		SET_BIT(UCSRB, RXCIE);
	}

}
void UART_setCallBack(void (*callbackptr)(void)) {
	g_callbackptr = callbackptr;
}
void UART_sendByte(uint8 data) {

	while (BIT_IS_CLEAR(UCSRA, UDRE))
		;
	UDR = data;
	return;
}
uint8 UART_receiveByte(void) {
	if (g_uartconfig.UART_ReceiveTechnique == RECEIVEPOLLING) {
		while (BIT_IS_CLEAR(UCSRA, RXC))
			;
		return UDR;
	} else {
		SET_BIT(SREG, 7);
		SET_BIT(UCSRB, RXCIE);
	}

	return 0;

}
void UART_sendString(char str[]) {
	uint8 count = 0;
	while (str[count] != '#') {
		UART_sendByte(str[count]);
		count++;
	}
	return;
}
void UART_receiveString(char str[]) {
	uint8 count = 0;
	while (str[count] != '#') {
		str[count] = UART_receiveByte();
		count++;
	}
	str[count] = '\0';
	return;
}
