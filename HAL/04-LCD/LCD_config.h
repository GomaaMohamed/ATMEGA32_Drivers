/*****************************************************************************
* @file:    LCD_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*	     This is free software: you are free to change and redistribute it.  
*	     There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Thu, 07 Sep 2023 19:09:10 +0300
* @brief:   LCD Driver.
******************************************************************************/
#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/* LCD Type Configuration
       LCD_TYPE Options:
                        LCD_16X2
                        LCD_20X4
 */
#define LCD_TYPE LCD_20X4

/* LCD Mode configuration
       LCD_MODE Options:
                        M_4BIT_SAMEPORT  
                        M_4BIT_SEPARATED 
                        M_8BIT  
*/
#define LCD_MODE  M_4BIT_SEPARATED

/************* for 8 bit mode and 4 bit_sameport mode define the LCD port **********/
#define LCD_PORT	       GPIOB // data wires on portA
#define LCD_PORT_CONTROL	GPIOA // RS RW EN portB
#define D0  
#define D1  
#define D2  
#define D3  
#define D4  PIN0
#define D5  PIN1
#define D6  PIN2
#define D7  PIN4

#define RS  PIN3
#define RW  PIN2
#define EN  PIN2

/************ for 4 bit same port mode define pins mask in port **********/
#define M_4BIT_MASK 0Xf0



#endif

