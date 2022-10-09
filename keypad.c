/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : KeyPad
 * Level  	   : Medium
 * Description : This file abstracts the interface with the KeyPad
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 8/10/2022(October)
 *******************************************************************************/

#include"gpio.h"
#include"keypad.h"
/**Define this Macro if the Keypad consists of only numbers and looks like this
 * 1	2	3	4
 * 5	6	7	8
 * 9	10	11	12
 * 13	14	15	16
 * or:
 * 1	2	3
 * 4	5	6
 * 7	8	9
 * 10	11	12
 * */
//#define NOT_POLLING
//static uint8 previous_state = 255;
#define STANDARD_KEYPAD

#ifndef STANDARD_KEYPAD
#if(NUM_OF_COLS==4)
static uint8 KEYPAD_4x4__adjustKeyNumber(uint8);
#endif
#if(NUM_OF_COLS==3)
static uint8 KEYPAD_4x3__adjustKeyNumber(uint8);
#endif
#endif
#ifndef	NOT_POLLING
uint8 KEYPAD_getPressedKey(void) {
	uint8 row, col;
	/**Setting all ROW&COL pins as inputs**/
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + 1,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + 2,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + 3,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID + 1,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID + 2,PIN_INPUT);
	/**Enabling the fourth column if and only if the Number of columns is 4**/
#if (NUM_OF_COLS==4)
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID + 3,PIN_INPUT);
#endif

	/**Polling until the user presses a key**/
	while (1) {
		/**Scanning over each Column, setting it as output and writing the
		 *  BUTTON_IS_PRESSED on it to detect the activated column**/
		for (row = 0; row < NUM_OF_ROWS; row++) {
			GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID + row, PIN_OUTPUT);
			GPIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + row,BUTTON_IS_PRESSED);
			/**Scanning over each column and reading the value of the pressed Key
			 * if it corresponds to BUTTON_IS_PRESSED the value of this button is returned**/
			for (col = 0; col < NUM_OF_COLS; col++) {
				if (GPIO_readPin(KEYPAD_COL_PORT_ID,KEYPAD_COL_FIRST_PIN_ID + col) == BUTTON_IS_PRESSED) {
					GPIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + row,BUTTON_IS_RELEASED);


					#ifdef STANDARD_KEYPAD
					return ((row * NUM_OF_COLS) + col + 1);

					#else
						#if(NUM_OF_COLS==4)
							return (KEYPAD_4x4__adjustKeyNumber((row * NUM_OF_COLS) + col + 1));
						#endif
						#if(NUM_OF_COLS==3)
							return (KEYPAD_4x3__adjustKeyNumber((row * NUM_OF_COLS) + col + 1));

						#endif
						#endif
				}
			}
			GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID + row, PIN_INPUT);
		}
	}
}
#else
uint8 KEYPAD_getPressedKey(void) {
	uint8 row, col;
	/**Setting all ROW&COL pins as inputs**/
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID,
			PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + 1,
			PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + 2,
			PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + 3,
			PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID,
			PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID + 1,
			PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID + 2,
			PIN_INPUT);
	/**Enabling the fourth column if and only if the Number of columns is 4**/
#if (NUM_OF_COLS==4)
	GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL_FIRST_PIN_ID + 3,
			PIN_INPUT);
#endif
	/**Scanning over each Column, setting it as output and writing the
	 *  BUTTON_IS_PRESSED on it to detect the activated column**/
	for (row = 0; row < NUM_OF_ROWS; row++) {
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID,
		KEYPAD_ROW_FIRST_PIN_ID + row, PIN_OUTPUT);
		GPIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + row,
		BUTTON_IS_PRESSED);
		/**Scanning over each column and reading the value of the pressed Key
		 * if it corresponds to BUTTON_IS_PRESSED the value of this button is returned**/
		for (col = 0; col < NUM_OF_COLS; col++) {
			if (GPIO_readPin(KEYPAD_COL_PORT_ID,KEYPAD_COL_FIRST_PIN_ID + col) == BUTTON_IS_PRESSED) {
				GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID,
						KEYPAD_ROW_FIRST_PIN_ID + row, PIN_INPUT);
				GPIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_ROW_FIRST_PIN_ID + row,BUTTON_IS_RELEASED);
				if (((row * NUM_OF_COLS) + col + 1) != previous_state) {
					previous_state = ((row * NUM_OF_COLS) + col + 1);
#ifdef STANDARD_KEYPAD
					return ((row * NUM_OF_COLS) + col + 1);

#else
						#if(NUM_OF_COLS==4)
							return (KEYPAD_4x4__adjustKeyNumber((row * NUM_OF_COLS) + col + 1));
						#endif
						#if(NUM_OF_COLS==3)
							return (KEYPAD_4x3__adjustKeyNumber((row * NUM_OF_COLS) + col + 1));

						#endif
						#endif
				} else
					return 255;
			}
		}
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_ROW_FIRST_PIN_ID + row, PIN_INPUT);
	}
	previous_state = 255;
	return 255;
}
#endif

#ifndef STANDARD_KEYPAD
#if(NUM_OF_COLS==4)
static uint8 KEYPAD_4x4__adjustKeyNumber(uint8 button_number) {

	switch (button_number) {
	case 1:
		return 7;
		break;
	case 2:
		return 8;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return '%';
		break;
	case 5:
		return 4;
		break;
	case 6:
		return 5;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return '*';
		break;
	case 9:
		return 1;
		break;
	case 10:
		return 2;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return '-';
		break;
	case 13:
		return '13';
		break;
	case 14:
		return 0;
		break;
	case 15:
		return '=';
		break;
	case 16:
		return '+';
		break;
	default:
		return button_number;
	}
}
#endif
#if(NUM_OF_COLS==3)
static uint8 KEYPAD_4x3__adjustKeyNumber(uint8 button_number) {

	switch (button_number) {
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#';
		break;
	default:
		return button_number;
	}

}
#endif
#endif
