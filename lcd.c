/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : LCD Screen
 * Level  	   : Medium
 * Description : This file abstracts the interface with the LCD screen
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 3/10/2022(October)
 *******************************************************************************/
#include"lcd.h"
#include"gpio.h"
#include<util/delay.h>
#include"common_macros.h"
/*******************************************************************************
 * EN : HIGH:Enable Data transfer
 * 		LOW :Disable Data Transfer
 * RS : HIGH:Transfer Display Data
 * 		LOW: Transfer Instruction Data
 * Delays are increased because available screens in the market have very bad
 *  response times
 *******************************************************************************/
#if((LCD_DATA_MODE!=8)&&(LCD_DATA_MODE!=4))

#error "Invalid Bitmode"

#endif
void LCD_init(void) {
	/**Enable and Register Select Pins Initialization*/
	GPIO_setupPinDirection(LCD_E_PORT, LCD_E_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RS_PORT, LCD_RS_PIN, PIN_OUTPUT);
	_delay_ms(20);
	/**DATA Pins Initialization*/
#if(LCD_DATA_MODE==4)
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_DB4_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_DB5_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_DB6_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_DB7_PIN, PIN_OUTPUT);
	LCD_sendCommand(LCD_FOUR_BIT_MODE_INIT1);
	LCD_sendCommand(LCD_FOUR_BIT_MODE_INIT2);
	LCD_sendCommand(LCD_FOUR_BIT_MODE_INIT);

#elif(LCD_DATA_MODE==8)
	{
		GPIO_setupPortDirection(LCD_DATA_PORT, PORT_OUTPUT);
		LCD_sendCommand(LCD_EIGHT_BIT_MODE_INIT);
	}
#endif
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);

}
/**Send a command to the LCD**/
void LCD_sendCommand(uint8 command) {
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_LOW);
	_delay_ms(1);/*Should be tas = 50ns min.*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);/*Should be tpw-tdsw 190ns*/
#if(LCD_DATA_MODE==4)
	/*Send The higher nibble in the command*/
	GPIO_writePin(LCD_DATA_PORT, LCD_DB4_PIN, GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB5_PIN, GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB6_PIN, GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB7_PIN, GET_BIT(command,7));
	_delay_ms(1);/*should be tdsw = 100ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);/*should be th =  13ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);/*Should be tpw-tdsw 190ns*/
	/*Send the lower nibble in the command*/
	GPIO_writePin(LCD_DATA_PORT, LCD_DB4_PIN, GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB5_PIN, GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB6_PIN, GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB7_PIN, GET_BIT(command,3));
	_delay_ms(1);/*should be tdsw = 100ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);/*should be th =  13ns*/
#elif(LCD_DATA_MODE==8)
	GPIO_writePort(LCD_DATA_PORT, command);
	_delay_ms(1);/*should be tdsw = 100ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);/*should be th =  13ns*/
#endif
}
/**Display a Character**/
void LCD_displayCharacter(uint8 character) {
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_HIGH);
	_delay_ms(1);/*Should be tas = 50ns min.*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);/*Should be tpw-tdsw 190ns*/
#if(LCD_DATA_MODE==4)
	/*Send The higher nibble in the command*/
	GPIO_writePin(LCD_DATA_PORT, LCD_DB4_PIN, GET_BIT(character,4));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB5_PIN, GET_BIT(character,5));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB6_PIN, GET_BIT(character,6));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB7_PIN, GET_BIT(character,7));
	_delay_ms(1);/*should be tdsw = 100ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);/*should be th =  13ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);/*Should be tpw-tdsw 190ns*/
	/*Send the lower nibble in the command*/
	GPIO_writePin(LCD_DATA_PORT, LCD_DB4_PIN, GET_BIT(character,0));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB5_PIN, GET_BIT(character,1));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB6_PIN, GET_BIT(character,2));
	GPIO_writePin(LCD_DATA_PORT, LCD_DB7_PIN, GET_BIT(character,3));
	_delay_ms(1);/*should be tdsw = 100ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);/*should be th =  13ns*/
#elif(LCD_DATA_MODE==8)
	GPIO_writePort(LCD_DATA_PORT, character);
	_delay_ms(1);/*should be tdsw = 100ns*/
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);/*should be th =  13ns*/
#endif
}
/**Display a String**/
void LCD_displayString(const char str[]) {
	int count = 0;
	while (str[count] != '\0') {
		LCD_displayCharacter(str[count]);
		count++;
	}
}
/**Change the cursor Location to a specific row and column**/
void LCD_moveCursor(uint8 row, uint8 col) {
	uint8 lcd_memory_address = 0;
	switch (row) {
	case 0:
		lcd_memory_address = col + 0x00;
		break;
	case 1:
		lcd_memory_address = col + 0x40;
		break;
	case 2:
		lcd_memory_address = col + 0x10;
		break;
	case 3:
		lcd_memory_address = col + 0x50;
		break;
	default:
		lcd_memory_address = 0x00;
	}
	LCD_sendCommand(LCD_SET_CURSOR_LOCATION | lcd_memory_address);

}
/**Print the string in a specific location**/
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char str[]) {
	LCD_moveCursor(row, col);
	LCD_displayString(str);
}
/**Print a given number**/
void LCD_integerToString(int num) {
	char buff[16];
	itoa(num, buff, 10);
	LCD_displayString(buff);
}
/**Clear the Screen**/
void LCD_clearScreen(void) {
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
