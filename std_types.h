/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Platform-Independent Datatypes
 * Level  	   : Low
 * Description : This file abstracts the datatypes for the other module so if the datatype sizes
 * 				 changes like with the platform only this file should be changed
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 1/10/2022(October)
 *******************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/* Boolean Data-type Definition*/
typedef unsigned char boolean;
/*  True-False Definition */

#ifndef TRUE
#define TRUE       (1u)
#endif
#ifndef FALSE
#define FALSE      (0u)
#endif
/* Logic Levels Definitions*/
#define LOGIC_HIGH (1u)
#define LOGIC_LOW  (0u)
#define NULL_PTR   ((void*)0)


/*These are the datatypes that can be used*/
typedef unsigned char			 uint8; 		/*		               0:255	              */
typedef signed char				 sint8;		    /*	                -128:127                  */
typedef unsigned short int  	 uint16;        /*	   	               0:65535	              */
typedef signed short int 		 sint16;		/*		          -32768:32767                */
typedef unsigned long 			 uint32;	    /*                    0 : 4294967295          */
typedef signed long 			 sint32;		/*          -2147483648 : +2147483647         */
typedef unsigned long long  	 uint64;		/*                    0 : 18446744073709551615*/
typedef signed long long 		 sint64;		/* -9223372036854775808 : 9223372036854775807 */
typedef float                    float32;
typedef double					 float64;


#endif /* STD_TYPES_H_ */
