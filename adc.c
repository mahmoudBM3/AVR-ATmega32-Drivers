/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Analog-to-Digital Converter
 * Level  	   : Low
 * Description : This file abstracts the interface with the ADC Peripheral
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 5/10/2022(October)
 *******************************************************************************/
#include "adc.h"
/***********************************************
 * Settings
 ***********************************************/
ADC_ConfigType g_adcconfig = { INTERNAL, FCPU_8 };
/***********************************************/
uint16 g_adcresult = 0;
/**This functions initializes the ADCPeripheral and sets it up for the given settings in the Configuration structure**/
void ADC_init(ADC_ConfigType *config) {

	/**Taking System settings for other functions**/
	g_adcconfig = *config;

	/**Setting Reference Voltage**/

	ADMUX = (ADMUX & 0x3F) | ((config->ADC_Reference << 6) & 0xC0);

	/**Clearing adjust Left Bit**/

	CLEAR_BIT(ADMUX, ADLAR);

	/**Selcting Either To enable or disable Interrupts**/

	CLEAR_BIT(ADCSRA, ADIE);

	/**Enabling ADC**/

	SET_BIT(ADCSRA, ADEN);

	/**Setting Prescaler Setting**/

	ADCSRA = (ADCSRA & 0xF8) | ((config->ADC_Prescaler) & 0x07);
}
/**This function either gets the reading from an ADC channel or starts the conversion and returns the result of the ADC**/
uint16 ADC_readChannel(uint8 ch_num) {
	/**Setting The ADC Channel**/
	/*Clearing Channel Bits*/
	CLEAR_BIT(ADMUX, MUX4);
	CLEAR_BIT(ADMUX, MUX3);
	CLEAR_BIT(ADMUX, MUX2);
	CLEAR_BIT(ADMUX, MUX1);
	CLEAR_BIT(ADMUX, MUX0);
	/*Inserting Channel*/
	ADMUX |= (ch_num & 0x1F);
	/**Start Conversion**/
	SET_BIT(ADCSRA, ADSC);
	/**POLLING until the conversion is complete then returning the result*/
	while (BIT_IS_CLEAR(ADCSRA, ADIF)) {
	}
	SET_BIT(ADCSRA, ADIF);
	g_adcresult = ADC;
	return ADC;

}

