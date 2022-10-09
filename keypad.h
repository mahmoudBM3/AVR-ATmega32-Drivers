/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : KeyPad
 * Level  	   : Medium
 * Description : This file abstracts the interface with the KeyPad
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 8/10/2022(October)
 *******************************************************************************/
/*******************************************************************************
 * NOTE:
 * NOT_POLLING Mode is working but failed the test so it should be further
 * tested and improved on
 *******************************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include"std_types.h"

/*******************************************************************************
 * 								SETTINGS
 *******************************************************************************/
#define	NUM_OF_COLS				4
#define	NUM_OF_ROWS				4
#define BUTTON_IS_PRESSED		LOGIC_LOW
#define BUTTON_IS_RELEASED		LOGIC_HIGH
#define KEYPAD_ROW_PORT_ID		PORTB_ID
#define KEYPAD_ROW_FIRST_PIN_ID	PIN0_ID
#define KEYPAD_COL_PORT_ID		PORTB_ID
#define KEYPAD_COL_FIRST_PIN_ID	PIN4_ID
/*******************************************************************************
 *  						Function Definitions
 *******************************************************************************/
uint8 KEYPAD_getPressedKey(void);
/**Only one setting is in the C file which is the choice for Standard Keypad or
 * not and is explained at the beginning of The C File **/



#endif /* KEYPAD_H_ */
