/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : LM-35 TEmperature Sensor
 * Level  	   : Medium
 * Description : This file abstracts the interface with the LM-35 Temperature Sensor
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 5/10/2022(October)
 *******************************************************************************/
#include"lm35_sensor.h"
#include"adc.h"
#include<util/delay.h>
#include"common_macros.h"

uint8 LM35_getTemperature() {
	uint8 temp;
	/**Calculating the temperature value**/
	temp = (uint8) (((uint32) ADC_readChannel(LM35_PIN) * SENSOR_MAX_TEMP * ADC_REFERENCE)
			/ (ADC_MAX_READING * SENSOR_MAX_VOLT));
	return temp;
}

