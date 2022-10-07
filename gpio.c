/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : General-purpose Input output Ports
 * Level  	   : Low
 * Description : This file abstracts the interface with the I/O ports
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 1/10/2022(October)
 *******************************************************************************/
#include"gpio.h"
#include"common_macros.h"
#include "avr/io.h"

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num,
		GPIO_PinDirectionType direction) {
	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT)) {
		return;
	} else {
		switch (port_num) {
		case PORTA_ID:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRA, pin_num);
			} else {
				SET_BIT(DDRA, pin_num);
			}
			break;
		case PORTB_ID:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRB, pin_num);
			} else {
				SET_BIT(DDRB, pin_num);
			}
			break;
		case PORTC_ID:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRC, pin_num);
			} else {
				SET_BIT(DDRC, pin_num);
			}
			break;
		case PORTD_ID:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRD, pin_num);
			} else {
				SET_BIT(DDRD, pin_num);
			}
			break;

		}
	}
}
void GPIO_setupPortDirection(uint8 port_num, GPIO_PinDirectionType direction) {
	if ((port_num >= NUM_OF_PORTS)) {
		return;

	} else {
		switch (port_num) {
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value) {
	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT)) {
		return;
	} else {
		switch (port_num) {
		case PORTA_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTA, pin_num);
			} else {
				SET_BIT(PORTA, pin_num);
			}
			break;
		case PORTB_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTB, pin_num);
			} else {
				SET_BIT(PORTB, pin_num);
			}
			break;
		case PORTC_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTC, pin_num);
			} else {
				SET_BIT(PORTC, pin_num);
			}
			break;
		case PORTD_ID:
			if (value == LOGIC_LOW) {
				CLEAR_BIT(PORTD, pin_num);
			} else {
				SET_BIT(PORTD, pin_num);
			}
			break;

		}
	}
}
void GPIO_writePort(uint8 port_num, uint8 value) {
	if ((port_num >= NUM_OF_PORTS)) {
		return;
	} else {
		switch (port_num) {
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num) {
	uint8 result = 0;
	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT)) {
		return result;
	}
	switch (port_num) {
	case PORTA_ID:
		result = GET_BIT(PINA, pin_num);
		break;
	case PORTB_ID:
		result = GET_BIT(PINB, pin_num);
		break;
	case PORTC_ID:
		result = GET_BIT(PINC, pin_num);
		break;
	case PORTD_ID:
		result = GET_BIT(PIND, pin_num);
		break;
	}

	return result;
}
uint8 GPIO_readPort(uint8 port_num) {
	uint8 result = 0;
	if ((port_num >= NUM_OF_PORTS)) {
		return result;
	}
	switch (port_num) {
	case PORTA_ID:
		result = PINA;
		break;
	case PORTB_ID:
		result = PINB;
		break;
	case PORTC_ID:
		result = PINC;
		break;
	case PORTD_ID:
		result = PIND;
		break;
	}

	return result;
}
