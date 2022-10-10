/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Interrupt Capture Unit
 * Level  	   : LOW
 * Description : This file abstracts the interface with Interrupt Capture Unit
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 10/10/2022(October)
 *******************************************************************************/
#include "icu.h"
#include"common_macros.h"
#include <avr/io.h>
#include<avr/interrupt.h>
void (*g_callback_ptr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect) {
	if (g_callback_ptr != NULL_PTR)
		g_callback_ptr();
}

void ICU_init(ICU_ConfigType *config_ptr) {
	/**Setting the ICP1 Pin as input**/
	CLEAR_BIT(DDRD,PD6);
	/**Disabling Output pin**/
	CLEAR_BIT(TCCR1A, COM1A0);
	CLEAR_BIT(TCCR1A, COM1A1);
	CLEAR_BIT(TCCR1A, COM1B0);
	CLEAR_BIT(TCCR1A, COM1B1);
	/**Selecting non-PWM Mode**/
	SET_BIT(TCCR1A, FOC1A);
	SET_BIT(TCCR1A, FOC1B);
	/**Selecting Timer Normal Mode**/
	CLEAR_BIT(TCCR1A, WGM11);
	CLEAR_BIT(TCCR1A, WGM10);
	CLEAR_BIT(TCCR1B, WGM13);
	CLEAR_BIT(TCCR1B, WGM12);
	/**Selecting The Edge**/
	if (config_ptr->edgetype == RISING) {
		SET_BIT(TCCR1B, ICES1);
	} else {
		CLEAR_BIT(TCCR1B, ICES1);
	}
	/**Selecting the Clock Source**/
	TCCR1B = (TCCR1B & 0xF8) | (config_ptr->clock_prescaler);
	/**Enabling Interrupts**/
	SET_BIT(TIMSK, TICIE1);
	SET_BIT(SREG, 7);
}
void ICU_clearTimerCount(void) {
	/**Putting zero in the Timer1 Counting Register**/
	TCNT1 = 0;
	return;
}
void ICU_setCallbackFunction(void (*callback_ptr)(void)) {
	g_callback_ptr = callback_ptr;
}
uint16 ICU_getInputCaptureValue(void) {
	return ICR1;
}
void ICU_setEdgeDetectionType(ICU_TriggeringEdge edge) {
	if (edge == RISING) {
		SET_BIT(TCCR1B, ICES1);
	} else {
		CLEAR_BIT(TCCR1B, ICES1);
	}
}
void ICU_deinit(void) {
	/**Clearing The Timer Control register to disable the ICU**/
	TCCR1A = 0;
	TCCR1B = 0;
	/**Clearing the Input Capture Register**/
	ICR1=0;
	/**Disabling the input Capture Interrupt**/
	CLEAR_BIT(TIMSK,TICIE1);
}
