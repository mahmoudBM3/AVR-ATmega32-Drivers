/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : HC-SR04 Ultrasonic Distance Sensor
 * Level  	   : LOW
 * Description : This file abstracts the interface with Ultrasonic Sensor
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 15/10/2022(October)
 *******************************************************************************/
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include"std_types.h"
/*******************************************************************************
 * 								SETTINGS									   *
 *******************************************************************************/
#define US_TRIG_PORT		PORTB_ID
#define US_TRIG_PIN			PIN5_ID
#define ICU_PRESCALER		8
/*******************************************************************************
 * 							Functions Definitions							   *
 *******************************************************************************/

/**This function Initializes the Ultrasonic Sensor and hould be called at the
 * beginning of the main function**/
void ULTRASONIC_init(void);

/**This Functions gets the distance measured by the HC-SR04 Ultrasonic Distance
 * Sensor**/
uint16 ULTRASONIC_readDistance(void);
#endif /* ULTRASONIC_H_ */
