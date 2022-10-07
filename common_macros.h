/*******************************************************************************
 * File Description:
 * Author      : Mahmoud Sherif Mahmoud
 * Module      : Platform-Independent Common Macros
 * Level  	   : Independent of anything
 * Description : This file defines the preprocessor macros that are commonly used
 * µC		   : ATMega 32 (8-BIT)
 * Date 	   : 1/10/2022(October)
 *******************************************************************************/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
/*Sets a certain bit in the given register to 1*/
#define SET_BIT(REG,BIT)    ( REG |= ( 1 << BIT ) )
/*Clears a certain bit in the given register to 0*/
#define CLEAR_BIT(REG,BIT)  ( REG &= ~ ( ( 1 << BIT ) ) )
/*Toggles a certain bit in the given register*/
#define TOGGLE_BIT(REG,BIT)  ( REG ^= ( ( 1 << BIT ) ) )
/*Rotates the register right by a given num*/
#define ROR(REG,num)  ( REG = ( REG >> num ) | ( REG << ( 8 - num ) ) )
/*Rotates the register left by a given num*/
#define ROL(REG,num)  ( REG = ( REG << num ) | ( REG >> ( 8 - num ) ) )
/*Checks if a given bit in a Register is set*/
#define BIT_IS_SET(REG,BIT)	 ( REG & ( 1 << BIT ) )
/*Checks if a given bit in a Register is cleared*/
#define BIT_IS_CLEAR(REG,BIT)	 (!( REG & ( 1 << BIT ) ) )
/*Checks for the value of the bit*/
#define GET_BIT(REG,BIT) ( ( ( REG & ( 1 << BIT ) ) >> BIT ) )
#endif /* COMMON_MACROS_H_ */
