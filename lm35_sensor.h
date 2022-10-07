/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : LM-35 TEmperature Sensor
 * Level  	   : Medium
 * Description : This file abstracts the interface with the LM-35 Temperature Sensor
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 5/10/2022(October)
 *******************************************************************************/
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include"std_types.h"
#include"common_macros.h"
/*
 * GUIDE:	1-first initialize the ADC in the main function and adjust its settings in its h file
 * 			2-in the sensor h file Adjust its ADC Channel and required ADC info for conversion
 *
 * */
/***********************************
 * 			SETTINGS
 ***********************************/
/**LM35 Pin**/
#define LM35_PIN 2
/**Some Numbers For Conversion**/
#define	ADC_MAX_READING		1023
#define	ADC_REFERENCE		2.56
#define SENSOR_MAX_VOLT		1.5
#define SENSOR_MAX_TEMP		150
/***********************************/


/**Function Definition**/
/**This function returns the value of the Temperature sensed by the temperature sensor in Celsius degrees*/
uint8 LM35_getTemperature();


#endif /* LM35_SENSOR_H_ */
