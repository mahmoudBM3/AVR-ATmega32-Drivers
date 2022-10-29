/*
 * i2c.h
 *
 *  Created on: Oct 28, 2022
 *      Author: mabkr
 */

#ifndef I2C_H_
#define I2C_H_
#include"std_types.h"
typedef enum {
	TWI_FCPU_1 = 0, TWI_FCPU_4 = 1, TWI_FCPU_16 = 2, TWI_FCPU_64 = 3
} TWI_PrescalerType;
typedef struct {
	uint8 TWI_Address;
	uint8 TWI_Bitrate;
TWI_PrescalerType TWI_Prescaler;
} TWI_ConfigType;

#endif /* I2C_H_ */
