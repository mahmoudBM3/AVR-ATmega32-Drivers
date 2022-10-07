/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : DC MOTOR
 * Level  	   : Medium
 * Description : This file abstracts the interface with the DC MOTOR
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 6/10/2022(October)
 *******************************************************************************/
#include"dc_motor.h"
#include"gpio.h"
#include"pwm.h"
/**This function initializes the DC Motor*/
void DCMOTOR_init(void){
	/**Setting up Motor Pins**/
	GPIO_setupPinDirection(DCMOTOR_E_PORT,DCMOTOR_E_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_IN1_PORT,DCMOTOR_IN1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_IN2_PORT,DCMOTOR_IN2_PIN,PIN_OUTPUT);
	/**Initializing Motor Pins**/
	DCMOTOR_rotate(STOP,0);
}
/**This function Changes the DC Motor settings to work with the given speed and
 * state*/
void DCMOTOR_rotate(DCMOTOR_STATE state,uint8 speed){
	/**Changing Motor Speed**/
	PWM_Timer0_Start(speed);
	/**Changing Motor State**/
	GPIO_writePin(DCMOTOR_IN1_PORT,DCMOTOR_IN1_PIN,(state)&(1<<0));
	GPIO_writePin(DCMOTOR_IN2_PORT,DCMOTOR_IN2_PIN,(state)&(1<<1));
}

