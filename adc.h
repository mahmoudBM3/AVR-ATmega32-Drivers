/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Analog-to-Digital Converter
 * Level  	   : Low
 * Description : This file abstracts the interface with the ADC Peripheral
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 5/10/2022(October)
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include "common_macros.h"
#include "std_types.h"
/**
 * GUIDE:
 * This ADC Driver can work at all AVR ADC modes and can configure all of its settings
 * using the configuration struct
 * TECHNIQUE : 	POLLING:	Uses the polling technique where you will wait inside the ADC_readChannelFunction
 * 							to get the reading and then return to the calling function to complete the res of the program flow
 * 				INTERRUPTS:	Uses the interrupts Technique where the ADC_readChannel Function starts the process
 * 							of Conversion and then you will return to the program Flow but without the reading you will have
 * 							to wait to get the reading when the ISR is called and gives the result in the global g_adcresult
 * 							variable, the time you will have to wait heavily depends on the frequency of the ADC but 5ms is always
 * 							a safe value to guarantee the Conversion is complete
 * REFERNCE :	AREF:		uses the external voltage on the AREF Pin of µC as the reference for conversion(Make sure AREF is connected to the correct Reference)
 * 				AVCC:		uses the VCC voltage (5v) on the AVCC Pin of µC as the reference for conversion(Make sure AVCC pin is connected to 5v)
 * 				INTERNAL:	uses the internal 2.56V as the reference for conversion(No pins need to be connected)
 * PRESCALER:	Has to be adjusted such that the ADC Frequency is between (50-200)KHz
 * */
/**ADC Config DataType*/
typedef struct{
	/**This Specifies the reference for the ADC Conversion*/
	enum {
		AREF=0,AVCC=1,INTERNAL=3
	}ADC_Reference;
	/**This Specifies the Prescaler for the ADC Frequency it should be adjusted such that the ADC Frequency between (50-200)MHz*/
	enum {
		FCPU_2=1,FCPU_4=2,FCPU_8=3,FCPU_16=4,FCPU_32=5,FCPU_64=6,FCPU_128=7
	}ADC_Prescaler;
}ADC_ConfigType;
extern ADC_ConfigType g_adcconfig;
extern uint16 g_adcresult;
/**************************
  *Function Definitions*
 **************************/


/**This function initializes the ADC Peripheral to start working and should be called at the beginning of the main
 * to be used by all the analog sensor in the system*/


void   ADC_init(ADC_ConfigType *config);


/**This Function reads the ADC value from the specified ADC Channel*/


uint16 ADC_readChannel(uint8 ch_num);



#endif /* ADC_H_ */
