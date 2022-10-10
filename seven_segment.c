/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Seven-Segment display
 * Level  	   : Medium
 * Description : This file abstracts the interface with the Seven-Segment Display
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 9/10/2022(October)
 *******************************************************************************/
#include"gpio.h"
#include"seven_segment.h"
#include"common_macros.h"
#define DECODED_SEVEN_SEGMENT
uint8 g_sevensegmentbytes[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
#ifdef DECODED_SEVEN_SEGMENT
void SEVEN_SEGMENT_init(void) {
	/**Setting up the SS data and Enable bit as output pins**/
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
			SEVEN_SEGMENT_FIRST_PIN_ID + 1, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
			SEVEN_SEGMENT_FIRST_PIN_ID + 2, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
			SEVEN_SEGMENT_FIRST_PIN_ID + 3, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_EN_PORT_ID, SEVEN_SEGMENT_EN_PIN_ID,PIN_OUTPUT);
}
void SEVEN_SEGMENT_displayDigit(uint8 num) {
	/**Writing the data on the data pins then enabling the SS**/
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID,
			GET_BIT(num, 0));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 1,
			GET_BIT(num, 1));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 2,
			GET_BIT(num, 2));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 3,
			GET_BIT(num, 3));
	GPIO_writePin(SEVEN_SEGMENT_EN_PORT_ID, SEVEN_SEGMENT_EN_PIN_ID,
		SEVEN_SEGMENT_ENABLE);

}
#else
void SEVEN_SEGMENT_init(void) {
	/**Setting up the SS data and Enable bit as output pins**/
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
	SEVEN_SEGMENT_FIRST_PIN_ID + 1, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
	SEVEN_SEGMENT_FIRST_PIN_ID + 2, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
	SEVEN_SEGMENT_FIRST_PIN_ID + 3, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
	SEVEN_SEGMENT_FIRST_PIN_ID + 4, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
	SEVEN_SEGMENT_FIRST_PIN_ID + 5, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_PORT_ID,
	SEVEN_SEGMENT_FIRST_PIN_ID + 6, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_EN_PORT_ID, SEVEN_SEGMENT_EN_PIN_ID,PIN_OUTPUT);
}
void SEVEN_SEGMENT_displayDigit(uint8 num) {
	/**Writing the data on the data pins then enabling the SS**/
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID,
			GET_BIT(g_sevensegmentbytes[num], 0));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 1,
			GET_BIT(g_sevensegmentbytes[num], 1));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 2,
			GET_BIT(g_sevensegmentbytes[num], 2));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 3,
			GET_BIT(g_sevensegmentbytes[num], 3));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 4,
			GET_BIT(g_sevensegmentbytes[num], 4));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 5,
			GET_BIT(g_sevensegmentbytes[num], 5));
	GPIO_writePin(SEVEN_SEGMENT_PORT_ID, SEVEN_SEGMENT_FIRST_PIN_ID + 6,
			GET_BIT(g_sevensegmentbytes[num], 6));
	GPIO_writePin(SEVEN_SEGMENT_EN_PORT_ID, SEVEN_SEGMENT_EN_PIN_ID,
	SEVEN_SEGMENT_ENABLE);
}
#endif
