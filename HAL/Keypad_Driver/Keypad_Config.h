/*
 * Keypad_Config.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_


/*Wiring diagram*/

/* * * *c1  c2 c3 c4
 * row1  1  2  3  /
 * row2  4  5  6  *
 * row3  7  8  9  -
 * row4  .  0  =  +
 */

#define KEYPAD_PORT_OUT_R PORTD
#define KEYPAD_PORT_IN_R  PIND
#define KEYPAD_PORT_DIR_R DDRD

#define KEYPAD_PORT_OUT_C PORTC
//#define KEYPAD_PORT_IN_C  PIND
#define KEYPAD_PORT_DIR_C DDRC

#define FIRST_ROW  (0)
#define SECOND_ROW (1)
#define THIRD_ROW  (2)
#define FOURTH_ROW (3)

#define FIRST_COL  (4)
#define SECOND_COL (5)
#define THIRD_COL  (6)
#define FOURTH_COL (7)



#endif /* HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_ */
