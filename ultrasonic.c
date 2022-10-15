/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : HC-SR04 Ultrasonic Distance Sensor
 * Level  	   : LOW
 * Description : This file abstracts the interface with Ultrasonic Sensor
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 15/10/2022(October)
 *******************************************************************************/
#include"ultrasonic.h"
#include"icu.h"
#include"gpio.h"
#include"util/delay.h"
/*******************************************************************************
 * 						Global Timer Count Variables						   *
 *******************************************************************************/
uint16 g_hightime = 0;
uint16 g_inittime = 0;
uint8 g_edgecount = 0;
/*******************************************************************************
 * 							Functions Definitions							   *
 *******************************************************************************/
/**This function handles the edge processing for the sensor**/
static void ULTRASONIC_Edge_processing(void);
/**This function Triggers the sensor to send a pulse to measure the distance**/
static void ULTRASONIC_trigger(void);
/*******************************************************************************
 * 								Sensor Functions							   *
 *******************************************************************************/
/**This function is called to handle the edge Captured by the ICU**/
static void ULTRASONIC_Edge_processing(void) {
	/**Edge count Variable is incremented**/
	g_edgecount++;
	if (g_edgecount == 1) {
		g_inittime = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(FALLING);
	} else if (g_edgecount == 2) {
		g_hightime = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RISING);
	}
}
void ULTRASONIC_init(void) {
	/**Configuring the ICU unit**/
	ICU_ConfigType icuconfig = { ICU_FCPU_8, RISING };
	ICU_init(&icuconfig);
	ICU_setCallbackFunction(ULTRASONIC_Edge_processing);
	/**Configuring the Trigger Pin**/
	GPIO_writePin(US_TRIG_PORT, US_TRIG_PIN, LOGIC_LOW);
	GPIO_setupPinDirection(US_TRIG_PORT, US_TRIG_PIN, PIN_OUTPUT);
}

uint16 ULTRASONIC_readDistance(void) {
	/**Clearing the variables to prepare for measurement**/
	g_inittime = 0;
	g_edgecount = 0;
	g_hightime = 0;
	/**Clearing the timer count and Triggering the sesnor**/
	ICU_clearTimerCount();
	ULTRASONIC_trigger();
	/**Waiting till the ICU measures the high time**/
	while (g_edgecount < 2) {
	}
	/**Calculating the distance**/
	uint16 hightime = (g_hightime - g_inittime);
	uint16 distance = ((uint64) hightime) * 17250.0 / (F_CPU / ICU_PRESCALER);
	return distance;
}
static void ULTRASONIC_trigger(void) {
	/**Writing Logic High for 10µs and then writing Logic Low on the Trigger pin
	 * to trigger the sensor**/
	GPIO_writePin(US_TRIG_PORT, US_TRIG_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePin(US_TRIG_PORT, US_TRIG_PIN, LOGIC_LOW);

}

