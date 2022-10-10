/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Seven-Segment display
 * Level  	   : Medium
 * Description : This file abstracts the interface with the Seven-Segment Display
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 9/10/2022(October)
 *******************************************************************************/
#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
#include"std_types.h"
/*******************************************************************************
 * 								Settings
 *******************************************************************************/
/**Specifies the Location of the SS Data Pins whether Decoded or not, note that
 * the data pins should be connected in succession**/
#define SEVEN_SEGMENT_PORT_ID		PORTC_ID
#define SEVEN_SEGMENT_FIRST_PIN_ID	PIN0_ID
/**Specifies the location of the Enable Bit of the SS if it exists if there is
 * no Enable bit itshould be sit to 8, it also Specifies the type of the SS**/
#define SEVEN_SEGMENT_EN_PORT_ID	PORTC_ID
#define SEVEN_SEGMENT_EN_PIN_ID		8
#define COMMON_CATHODE
#ifdef	COMMON_CATHODE
#define	SEVEN_SEGMENT_ENABLE		LOGIC_HIGH
#else
#ifdef 	COMMON_ANODE
#define	SEVEN_SEGMENT_ENABLE		LOGIC_LOW
#endif
#endif
/*******************************************************************************
 * 							Function Definitions
 *******************************************************************************/
/**Initializes the SS and should be called at the beginning of the main**/
void SEVEN_SEGMENT_init(void);
/**Displays the number on the SS**/
void SEVEN_SEGMENT_displayDigit(uint8 num);
/**In the future i plan to add a function that prints on multiple Seven segmen
 * displays**/

#endif /* SEVEN_SEGMENT_H_ */
