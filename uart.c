#include<avr/io.h>
#include"uart.h"
#include"common_macros.h"
void UART_init(UART_ConfigType *config) {
	/**Enabling Double speed mode*/
	SET_BIT(UCSRA, U2X);
	/**Enabling Receiving and Transmitting*/
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
	/**UCSRC init*/
	SET_BIT(UCSRC, URSEL);
	/**Selecting Asynchronous mode*/
	CLEAR_BIT(UCSRC, UMSEL);
	/**Disabling Parity Error check*/
	CLEAR_BIT(UCSRC, UPM0);
	CLEAR_BIT(UCSRC, UPM1);
	/**Selecting 1 stop bit*/
	CLEAR_BIT(UCSRC, USBS);
	/**Selecting Character Size*/
	CLEAR_BIT(UCSRB, UCSZ2);
	CLEAR_BIT(UCSRC, UCSZ1);
	CLEAR_BIT(UCSRC, UCSZ0);
	/**Selecting the BAUD Rate*/
	uint8 UBRR_value = ((uint32) F_CPU / (8 * config->UART_BaudRate) - 1);
	UBRRL=UBRR_value;
	UBRRH=UBRR_value>>8;

}
void UART_sendByte(uint8 data) {

	while (BIT_IS_CLEAR(UCSRA, UDRE))
		;
	UDR = data;
	return;
}
uint8 UART_receiveByte(void) {
	while (BIT_IS_CLEAR(UCSRA, RXC))
		;
	return UDR;
}
