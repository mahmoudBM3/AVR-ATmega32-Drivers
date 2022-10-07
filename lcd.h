/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : LCD Screen
 * Level  	   : Medium
 * Description : This file abstracts the interface with the LCD screen
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 3/10/2022(October)
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_
#include"std_types.h"
/*******************************************************************************
 	 	  	  	  	  	  	  	  Settings
********************************************************************************/
/**Specifies the Bit Mode of the LCD*/
#define LCD_DATA_MODE	8
/**Specifies the PORT in which the DATA Bits of the LCD are connected*/
#define LCD_DATA_PORT	PORTC_ID
/**Only for the 4-BIT Mode : Specifies the Pins on which the Data bits are
 * connected*/
#if(LCD_DATA_MODE==4)
#define LCD_DB4_PIN		PIN3_ID
#define LCD_DB5_PIN		PIN4_ID
#define LCD_DB6_PIN		PIN5_ID
#define LCD_DB7_PIN		PIN6_ID
#endif
/**Specifies where the E and RS pins are connected*/
#define LCD_E_PORT		PORTD_ID
#define LCD_E_PIN		PIN2_ID
#define LCD_RS_PORT		PORTD_ID
#define LCD_RS_PIN		PIN0_ID
/*******************************************************************************/
/*******************************************************************************
							LCD Commands :
********************************************************************************/
#define LCD_CLEAR_COMMAND			0x01
#define LCD_GO_TO_HOME				0x02
#define LCD_FOUR_BIT_MODE_INIT1		0x33
#define LCD_FOUR_BIT_MODE_INIT2		0x32
#define LCD_FOUR_BIT_MODE_INIT		0x28
#define LCD_EIGHT_BIT_MODE_INIT		0x38
#define LCD_CURSOR_OFF         		0x0C
#define LCD_CURSOR_ON				0x0E
#define LCD_SET_CURSOR_LOCATION		0x80
/*******************************************************************************/
/*******************************************************************************
 * 						Function Definitions
 *******************************************************************************/
/**This function initializes the LCD and should be called at the beginning of
 * the main*/
void LCD_init(void);
/**This function Sends a given command to the LCD*/
void LCD_sendCommand(uint8 command);
/**This function Displays a given character on where the cursor is located on
 * the LCD*/
void LCD_displayCharacter(uint8 character);
/**This function Displays a given String on where the cursor is located on
 * the LCD*/
void LCD_displayString(const char str[]);
/**This function moves the cursor to the specified row and column(0,1,2,3)*/
void LCD_moveCursor(uint8 row, uint8 col);
/**This function moves the cursor to the specified row and column(0,1,2,3) and
 * displays the given string at that location*/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char str[]);
/**This function takes an integer number and displays it on the screen at the
 * cursor location*/
void LCD_integerToString(int num);
/**This function Clears the screen*/
void LCD_clearScreen(void);


#endif /* LCD_H_ */
