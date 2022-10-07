/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : LM-35 Temperature Sensor
 * Level  	   : Low
 * Description : This file abstracts the PWM for ATMega32 µC
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 6/10/2022(October)
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*PWM Clock Selecting Datatype Enum*/
#define TIMER_TOP_COUNT		255
typedef enum {
	PWM_NOCLK = 0,
	PWM_FCPU = 1,
	PWM_FCPU_8 = 2,
	PWM_FCPU_64 = 3,
	PWM_FCPU_256 = 4,
	PWM_FCPU_1024 = 5,
} PWM_ClockConfig;
/*Function Definition*/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
