/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Serial Peripheral Interface (SPI)
 * Level  	   : Low
 * Description : This file abstracts the interface with the SPI Protocol
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 27/10/2022(October)
 *******************************************************************************/
#ifndef SPI_H_
#define SPI_H_
#include"std_types.h"
/*******************************************************************************
 * 								Some Macros
 *******************************************************************************/
#define SPI_DEFAULT_DATA_VALUE	0xFF
/*******************************************************************************
 * 							Configuration DataTypes
 *******************************************************************************/

/*******************************************************************************
 * This Enum contains the Type of Edge with which SPI works
 *******************************************************************************/

typedef enum {
	SPI_RISING = 0, SPI_FALLING = 1
} SPI_ClockPolarityType;

/*******************************************************************************
 * This Enum contains The different Frequencies with which it operates
 *******************************************************************************/

typedef enum {
	SPI_FCPU_4 = 0,  /**< SPI_FCPU_4 */
	SPI_FCPU_16 = 1, /**< SPI_FCPU_16 */
	SPI_FCPU_64 = 2, /**< SPI_FCPU_64 */
	SPI_FCPU_128 = 3,/**< SPI_FCPU_128 */
	SPI_FCPU_2 = 4,  /**< SPI_FCPU_2 */
	SPI_FCPU_8 = 5,  /**< SPI_FCPU_8 */
	SPI_FCPU_32 = 6, /**< SPI_FCPU_32 */
} SPI_SCKFrequencyType;

/*******************************************************************************
 * This Struct Contains the Settings for SPI
 *******************************************************************************/

typedef struct {
	SPI_ClockPolarityType ClockPolarity;
	SPI_SCKFrequencyType SCKFrequency;
} SPI_ConfigType;
/*******************************************************************************
 * 							Functions Definitions
 *******************************************************************************/
/*******************************************************************************
 * This Function initializes SPI to Work as a Master
 * @param configptr
 *******************************************************************************/
void SPI_initMaster(SPI_ConfigType *configptr);
/*******************************************************************************
 * This Function initializes SPI to Work as a Slave
 * @param configptr
 *******************************************************************************/
void SPI_initSlave(SPI_ConfigType *configptr);
/*******************************************************************************
 * This Function Sends and receives a Byte through The SPI
 * @param data
 * @return
 *******************************************************************************/
uint8 SPI_sendReceiveByte(uint8 data);
/*******************************************************************************
 * This Function sends a String Through SPI
 * @param str
 *******************************************************************************/
void SPI_sendString(uint8 str[]);
/*******************************************************************************
 * This Function Receives a String through SPI
 * @param str
 *******************************************************************************/
void SPI_receiveString(uint8 str[]);

#endif /* SPI_H_ */
