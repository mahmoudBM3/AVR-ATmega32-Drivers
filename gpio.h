/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : General-purpose Input output Ports
 * Level  	   : Low
 * Description : This file abstracts the interface with the I/O ports
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 1/10/2022(October)
 *******************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_
#include"std_types.h"
/*PORT Definitions */
#define NUM_OF_PORTS 4
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
/*PIN Definitions*/
#define NUM_OF_PINS_PER_PORT 8
#define PIN0_ID  0
#define PIN1_ID  1
#define PIN2_ID  2
#define PIN3_ID  3
#define PIN4_ID  4
#define PIN5_ID  5
#define PIN6_ID  6
#define PIN7_ID  7
/*DataType Definitions*/
typedef enum{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;
typedef enum{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;
/*Function Definitions*/
/*void GPIO_setupPinDirection(uint8 port_num , uint8 pin_num , GPIO_PinDirectionType direction);
 * This function sets the direction of a certain pin to either input or output
 * **************Inputs*****************
 * port_num:the number or ID  where the pin lies
 * pin_num: the number or ID of the required pin
 * direction:specifies the direction of the pin either input or output
 * 0:input
 * 1:output
 * **************Outputs*****************
 * No outputs
 */
void GPIO_setupPinDirection(uint8 port_num , uint8 pin_num , GPIO_PinDirectionType direction);
/*void GPIO_setupPortDirection(uint8 port_num , uint8 pin_num , GPIO_PinDirectionType direction);
 * This function sets the direction of a port to either input or output
 * **************Inputs*****************
 * port_num:the number or ID of the port
 * direction:specifies the direction of each pin on the port either input or output
 * 0:input
 * 1:output
 * **************Outputs*****************
 * No outputs
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PinDirectionType direction);
/*void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);
 * This function writes a given output to a pin on  a given port to 0 or 1
 * **************Inputs*****************
 * port_num:the number or ID of the port
 * pin_num: the number or ID of the required pin
 * value:specifies the value of the output on the pin
 * 0:Low
 * 1:High
 * **************Outputs*****************
 * No outputs
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);
/*void GPIO_writePort(uint8 port_num, uint8 value);
 * This function writes a given output on port to 0 or 1
 * **************Inputs*****************
 * port_num:the number or ID of the port
 * value:specifies the value of the output on the port
 * 0:Low
 * 1:High
 * **************Outputs*****************
 * No outputs
 */
void GPIO_writePort(uint8 port_num, uint8 value);
/*uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);
 * This function reads input value on a pin on a port either 0 or 1
 * **************Inputs*****************
 * port_num:the number or ID of the port
 * pin_num: the number or ID of the required pin
 *
 * **************Outputs*****************
 * result: has the value of the pin input level
 * 0:Low
 * 1:High
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);
/*uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);
 * This function reads input value on a port
 * **************Inputs*****************
 * port_num:the number or ID of the port
 * **************Outputs*****************
 * result: has the value of the port input level
 * 0:Low
 * 1:High
 */
uint8 GPIO_readPort(uint8 port_num);



#endif /* GPIO_H_ */
