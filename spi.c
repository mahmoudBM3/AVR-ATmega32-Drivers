#include"common_macros.h"
#include"spi.h"
#include<avr/io.h>
#include"gpio.h"

void SPI_initMaster(SPI_ConfigType *configptr) {
	/**Setting up the SPI pins up**/
	GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);

	/**Enabling SPI**/
	SET_BIT(SPCR, SPE);
	/**Transmitting MSB first**/
	CLEAR_BIT(SPCR, DORD);
	/**Enabling Master Mode**/
	SET_BIT(SPCR, MSTR);
	/**Selecting the Clock Polarity**/
	if (configptr->ClockPolarity == SPI_RISING) {
		CLEAR_BIT(SPCR, CPOL);
	} else if (configptr->ClockPolarity == SPI_FALLING) {
		SET_BIT(SPCR, CPOL);
	}
	/**Selecting CLock Phase**/
	CLEAR_BIT(SPCR, CPHA);
	/**Selecting the SCK Clock rate**/
	SPCR = (SPCR & 0xFC) | (configptr->SCKFrequency & 0x03);
	if (configptr->SCKFrequency >= SPI_FCPU_2) {
		SET_BIT(SPSR, SPI2X);
	} else if (configptr->SCKFrequency < SPI_FCPU_2) {
		CLEAR_BIT(SPSR, SPI2X);
	}

}
void SPI_initSlave(SPI_ConfigType *configptr) {
	/**Setting up the SPI pins**/
	GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_INPUT);
	/**Enabling SPI**/
	SET_BIT(SPCR, SPE);
	/**Transmitting MSB first**/
	CLEAR_BIT(SPCR, DORD);
	/**Enabling Master Mode**/
	CLEAR_BIT(SPCR, MSTR);
	/**Selecting the Clock Polarity**/
	if (configptr->ClockPolarity == SPI_RISING) {
		CLEAR_BIT(SPCR, CPOL);
	} else if (configptr->ClockPolarity == SPI_FALLING) {
		SET_BIT(SPCR, CPOL);
	}
	/**Selecting CLock Phase**/
	CLEAR_BIT(SPCR, CPHA);
	/**Selecting the SCK Clock rate**/
	SPCR = (SPCR & 0xFC) | (configptr->SCKFrequency & 0x03);
	if (configptr->SCKFrequency >= SPI_FCPU_2) {
		SET_BIT(SPSR, SPI2X);
	} else if (configptr->SCKFrequency < SPI_FCPU_2) {
		CLEAR_BIT(SPSR, SPI2X);
	}

}
uint8 SPI_sendReceiveByte(uint8 data) {
	SPDR = data;
	while (BIT_IS_CLEAR(SPSR, SPIF)) {
	}
	SET_BIT(SPSR, SPIF);
	return SPDR;
}
