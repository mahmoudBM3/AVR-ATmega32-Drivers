/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : DC MOTOR
 * Level  	   : Medium
 * Description : This file abstracts the interface with the DC MOTOR
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 6/10/2022(October)
 *******************************************************************************/
/*******************************************************************************
 * GUIDE:
 * To use this driver first you have to set up the pins you are using for the E,
 * IN1,IN2 pins .
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
/*******************************************************************************
            						Settings
 *******************************************************************************/
/**MOTOR Pins**/
#define DCMOTOR_E_PORT			PORTB_ID
#define DCMOTOR_E_PIN			PIN3_ID
#define DCMOTOR_IN1_PORT		PORTB_ID
#define DCMOTOR_IN1_PIN			PIN5_ID
#define DCMOTOR_IN2_PORT		PORTB_ID
#define DCMOTOR_IN2_PIN			PIN6_ID
/*******************************************************************************/
/**MOTOR States Enum**/
typedef enum {
	STOP = 0, CLOCKWISE = 1, ANTICLOCKWISE = 2
}DCMOTOR_STATE;
/*******************************************************************************
 	 	 	 	 	 	 	  Function Definitions
 *******************************************************************************/
/**This function initializes the DC Motor*/
void DCMOTOR_init(void);
/**This function Changes the DC Motor settings to work with the given speed and
 * state*/
void DCMOTOR_rotate(DCMOTOR_STATE state,uint8 speed);
/*******************************************************************************/

#endif /* DC_MOTOR_H_ */
