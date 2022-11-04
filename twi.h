/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Two-Wire Interface Module
 * Level  	   : Low
 * Description : This file abstracts the interface with the TWI Communication
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 1/11/2022(November)
 *******************************************************************************/
#ifndef TWI_H_
#define TWI_H_
/*******************************************************************************
 * 						  	Included Libraries
 *******************************************************************************/
#include"std_types.h"
/*******************************************************************************
 * 							Configuration Struct
 *******************************************************************************/
typedef enum {
	TWI_FCPU_1 = 0, TWI_FCPU_4 = 1, TWI_FCPU_16 = 2, TWI_FCPU_64 = 3
} TWI_PrescalerType;
typedef struct {
	uint8 TWI_Address;
	uint8 TWI_Bitrate;
TWI_PrescalerType TWI_Prescaler;
} TWI_ConfigType;
/*******************************************************************************
 * 							Function Definitions
 *******************************************************************************/
/**
 * This function Initializes The TWI Module
 * @param config
 */
void TWI_init(const TWI_ConfigType *config);
/**
 * This function Sends the Start Condition
 */
void TWI_start(void);
/**
 * This function Sends the Stop Condition
 */
void TWI_stop(void);
/**
 * This function Sends a byte through the TWI interface
 */
void TWI_writeByte(uint8 data);
/**
 * This function reads a byte and sends an ACK Bit
 */
uint8 TWI_readByteWithACK(void);
/**
 * This function reads a byte only and does not send an ACK Bit
 */
uint8 TWI_readByteWithNACK(void);
/**
 * This function reads The Status of the TWI module
 */
uint8 TWI_getStatus(void);
/*******************************************************************************
 * 							TWI Status Macros
 *******************************************************************************/
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */


#endif /* TWI_H_ */
