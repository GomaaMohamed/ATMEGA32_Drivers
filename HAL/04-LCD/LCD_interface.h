/*****************************************************************************
* @file:    LCD_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Thu, 07 Sep 2023 19:09:10 +0300
* @brief:   LCD Driver.
******************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize lcd module
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_init(void);

/**
 * @brief---------------------> Write character on lcd
 * @parameter1----------------> (Character) character to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_writeChar(u8 Character);

/**
 * @brief---------------------> Write sentence on lcd
 * @parameter1----------------> (ptrSentence) sentence to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_writeSentence(u8 *ptrSentance);

/**
 * @brief---------------------> Move cursor at specific position
 * @parameter1----------------> (Line) line number
 * @parameter2----------------> (x) char number
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_goTo(u8 Line, u8 x);

/**
 * @brief---------------------> Write Sentence at specific position
 * @parameter1----------------> (Line) line number
 * @parameter2----------------> (x) char number
 * @parameter3----------------> (ptrSentence) sentence to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_out(u8 Line, u8 x,u8 *ptrSentence);

/**
 * @brief---------------------> Write number on lcd
 * @parameter1----------------> (Number) number to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_writeNumber(u32 Number); 

/**
 * @brief---------------------> Write number on lcd
 * @parameter1----------------> (Number) number to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_writeNumber2(u16 Number);

/**
 * @brief---------------------> Create a custom character
 * @parameter1----------------> (Pattern) pattern of character
 * @parameter2----------------> (Location) location of character at ggram
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_createCharacter(u8 *Pattern,u8 Location);

/**
 * @brief---------------------> Clear lcd 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_clear(void);

/**
 * @brief---------------------> Shift lcd left
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_shiftLcdLeft(void);

/**
 * @brief---------------------> Shift lcd right
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LCD_shiftLcdRight(void);

/*************** service for lcd *******************/
u8   *convert_data(u32 Value); 
u32  str_to_int(u8*ptr);


#endif

