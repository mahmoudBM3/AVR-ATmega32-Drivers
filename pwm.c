/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : LM-35 Temperature Sensor
 * Level  	   : Low
 * Description : This file abstracts the PWM for ATMega32 µC
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 6/10/2022(October)
 *******************************************************************************/
#include "common_macros.h"
#include "pwm.h"
#include<avr/io.h>
PWM_ClockConfig ClockSelect = PWM_FCPU_8;
void PWM_Timer0_Start(uint8 duty_cycle) {
	/*Initializing the PWM Signal*/
	CLEAR_BIT(TCCR0, FOC0);
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, COM01);
	CLEAR_BIT(TCCR0, COM00);
	/*Selecting Clock Source*/
	TCCR0 = ((TCCR0 & 0xF8) | ClockSelect);
	OCR0 =(uint8)((duty_cycle*TIMER_TOP_COUNT/100.0));;
	return;

}
