/*
 * keypad.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mabkr
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include"std_types.h"

/*******************************************************************************
 * 								SETTINGS
 *******************************************************************************/
#define	NUM_OF_COLS				4
#define	NUM_OF_ROWS				4
#define BUTTON_IS_PRESSED		LOGIC_LOW
#define BUTTON_IS_RELESED		LOGIC_HIGH
#define KEYPAD_ROW_PORT_ID		PORTB_ID
#define KEYPAD_ROW_FIRST_PIN_ID	PIN4_ID
#define KEYPAD_COL_PORT_ID		PORTD_ID
#define KEYPAD_COL_FIRST_PIN_ID	PIN2_ID
uint8 KEYPAD_getPressedKey(void);



#endif /* KEYPAD_H_ */
