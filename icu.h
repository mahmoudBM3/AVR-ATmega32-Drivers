/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Interrupt Capture Unit
 * Level  	   : LOW
 * Description : This file abstracts the interface with Interrupt Capture Unit
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 10/10/2022(October)
 *******************************************************************************/
#ifndef ICU_H_
#define ICU_H_
#include "std_types.h"
/*******************************************************************************
 * 							Datatypes Definitions							   *
 *******************************************************************************/
/**Clock Prescaler Definition**/
typedef enum {
		ICU_NOCLK = 0,     /**< NOCLK */
		ICU_FCPU = 1,      /**< FCPU */
		ICU_FCPU_8 = 2,    /**< FCPU_8 */
		ICU_FCPU_64 = 3,   /**< FCPU_64 */
		ICU_FCPU_256 = 4,  /**< FCPU_256 */
		ICU_FCPU_1024 = 5, /**< FCPU_1024 */
		ICU_EX_FALLING = 6,/**< EX_FALLING */
		ICU_EX_RISING = 7  /**< EX_RISING */
	} ICU_Prescaler;
/**EdgeType Definition**/
typedef enum {
	FALLING = 0, RISING = 1
} ICU_TriggeringEdge;
/**Configuration Struct Definition**/
typedef struct {
	ICU_Prescaler		clock_prescaler;
	ICU_TriggeringEdge 	edgetype;
} ICU_ConfigType;
/*******************************************************************************/
/*******************************************************************************
 * 							Function Definitions							   *
 *******************************************************************************/
/**This Function Initializes The ICU and makes it start working**/
void ICU_init(ICU_ConfigType *config_ptr);
/**This Function Deinitializes the ICU and makes it stop working**/
void ICU_deinit(void);
/**This Function Sets the Type of edge which Triggers the ICU**/
void ICU_setEdgeDetectionType(ICU_TriggeringEdge edge);
/**This Function sets the Callback Function which is called by the ISR of ICU**/
void ICU_setCallbackFunction(void (*callback_ptr)(void));
/**This Function Clears the Timer1 count back to 0**/
void ICU_clearTimerCount(void);
/**This Function Returns the value of the timer at which the edge occured**/
uint16 ICU_getInputCaptureValue(void);
#endif /* ICU_H_ */
