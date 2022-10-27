/*
 * spi.h
 *
 *  Created on: Oct 16, 2022
 *      Author: mabkr
 */

#ifndef SPI_H_
#define SPI_H_
#include"std_types.h"

typedef enum {
	SPI_RISING = 0, SPI_FALLING = 1
} SPI_ClockPolarityType;
typedef enum {
	SPI_FCPU_4 = 0,
	SPI_FCPU_16 = 1,
	SPI_FCPU_64 = 2,
	SPI_FCPU_128 = 3,
	SPI_FCPU_2 = 4,
	SPI_FCPU_8 = 5,
	SPI_FCPU_32 = 6,

} SPI_SCKFrequencyType;
typedef struct{
	SPI_ClockPolarityType 	ClockPolarity;
	SPI_SCKFrequencyType	SCKFrequency;
}SPI_ConfigType;

#endif /* SPI_H_ */
