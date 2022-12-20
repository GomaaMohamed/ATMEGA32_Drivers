/*
 * Keypad_Program.c
 *
 *  Created on: Nov 16, 2022
 *      Author: Kimo Store
 */


#include "Keypad_Private.h"
#include "Keypad_Interface.h"
#include "Keypad_Config.h"

void Keypad_voidInit()
{

	/*

	GPIO_void_Set_Direction_PIN(Keypad_Rows_PORT , FirstRow , INPUT);
	GPIO_void_Set_Direction_PIN(Keypad_Rows_PORT , SecondRow , INPUT);
	GPIO_void_Set_Direction_PIN(Keypad_Rows_PORT , ThirdRow , INPUT);
	GPIO_void_Set_Direction_PIN(Keypad_Rows_PORT , ForthRow , INPUT);


	GPIO_void_Set_Direction_PIN(Keypad_Cols_PORT , FirstCol , OUTPUT);
	GPIO_void_Set_Direction_PIN(Keypad_Cols_PORT , SecondCol , OUTPUT);
	GPIO_void_Set_Direction_PIN(Keypad_Cols_PORT , ThirdCol , OUTPUT);
	GPIO_void_Set_Direction_PIN(Keypad_Cols_PORT , ForthCol , OUTPUT);



	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT , FirstCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT , SecondCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT , ThirdCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT , ForthCol , HIGH);
	 */

	CLEAR_BIT(KEYPAD_PORT_DIR_R,FIRST_ROW);
	CLEAR_BIT(KEYPAD_PORT_DIR_R,SECOND_ROW);
	CLEAR_BIT(KEYPAD_PORT_DIR_R,THIRD_ROW);
	CLEAR_BIT(KEYPAD_PORT_DIR_R,FOURTH_ROW);

	SET_BIT(KEYPAD_PORT_OUT_R , FIRST_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R , SECOND_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R , THIRD_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R , FOURTH_ROW);

	SET_BIT(KEYPAD_PORT_DIR_C , FIRST_COL);
	SET_BIT(KEYPAD_PORT_DIR_C , SECOND_COL);
	SET_BIT(KEYPAD_PORT_DIR_C , THIRD_COL);
	SET_BIT(KEYPAD_PORT_DIR_C , FOURTH_COL);

	SET_BIT(KEYPAD_PORT_OUT_C , FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , FOURTH_COL);
}

u8 Keypad_voidGetPressedKey()
{
	u8 keyPressed = 0;


	_delay_ms(5);

	CLEAR_BIT(KEYPAD_PORT_OUT_C , FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , FOURTH_COL);

	_delay_ms(5);

	if((CHECK_BIT(KEYPAD_PORT_IN_R , FIRST_ROW)) == 0){keyPressed = '7';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , SECOND_ROW)) == 0){keyPressed = '4';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , THIRD_ROW)) == 0){keyPressed = '1';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , FOURTH_ROW)) == 0){keyPressed = '.';}




	_delay_ms(5);

	SET_BIT(KEYPAD_PORT_OUT_C , FIRST_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C , SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , FOURTH_COL);

	_delay_ms(5);

	if((CHECK_BIT(KEYPAD_PORT_IN_R , FIRST_ROW)) == 0){keyPressed = '8';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , SECOND_ROW)) == 0){keyPressed = '5';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , THIRD_ROW)) == 0){keyPressed = '2';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , FOURTH_ROW)) == 0){keyPressed = '0';}



	_delay_ms(5);

	SET_BIT(KEYPAD_PORT_OUT_C , FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , SECOND_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C , THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , FOURTH_COL);

	_delay_ms(5);

	if((CHECK_BIT(KEYPAD_PORT_IN_R , FIRST_ROW)) == 0){keyPressed = '9';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , SECOND_ROW)) == 0){keyPressed = '6';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , THIRD_ROW)) == 0){keyPressed = '3';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , FOURTH_ROW)) == 0){keyPressed = '=';}

	_delay_ms(5);

	SET_BIT(KEYPAD_PORT_OUT_C , FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C , THIRD_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C , FOURTH_COL);

	_delay_ms(5);

	if((CHECK_BIT(KEYPAD_PORT_IN_R , FIRST_ROW)) == 0){keyPressed = '/';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , SECOND_ROW)) == 0){keyPressed = '*';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , THIRD_ROW)) == 0){keyPressed = '-';}
	else if((CHECK_BIT(KEYPAD_PORT_IN_R , FOURTH_ROW)) == 0){keyPressed = '+';}


	return keyPressed;





	/*
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,FirstCol , LOW);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,SecondCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ThirdCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ForthCol , HIGH);

	_delay_ms(5);
	if(Btn_voidRead(Keypad_Rows_PORT , FirstRow) == 0 ){keyPressed = '7';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , SecondRow) == 0 ){keyPressed = '4';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ThirdRow) == 0 ){keyPressed = '1';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ForthRow) == 0 ){keyPressed = '.';}
*/

	/*Second column */
/*
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,FirstCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,SecondCol , LOW);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ThirdCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ForthCol , HIGH);

	_delay_ms(5);
	if(GPIO_void_ReadPIN(Keypad_Rows_PORT , FirstRow) == 0 ){keyPressed = '8';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , SecondRow) == 0 ){keyPressed = '5';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ThirdRow) == 0 ){keyPressed = '2';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ForthRow) == 0 ){keyPressed = '0';}
*/
	/*Third column */
/*
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,FirstCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,SecondCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ThirdCol , LOW);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ForthCol , HIGH);

	_delay_ms(5);
	if(GPIO_void_ReadPIN(Keypad_Rows_PORT , FirstRow) == 0 ){keyPressed = '9';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , SecondRow) == 0 ){keyPressed = '6';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ThirdRow) == 0 ){keyPressed = '3';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ForthRow) == 0 ){keyPressed = '=';}

*/
	/*Forth column */
/*
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,FirstCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,SecondCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ThirdCol , HIGH);
	GPIO_void_Set_Value_PIN(Keypad_Cols_PORT ,ForthCol , LOW);

	_delay_ms(5);
	if(GPIO_void_ReadPIN(Keypad_Rows_PORT , FirstRow) == 0 ){keyPressed = '/';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , SecondRow) == 0 ){keyPressed = '*';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ThirdRow) == 0 ){keyPressed = '-';}
	else if(GPIO_void_ReadPIN(Keypad_Rows_PORT , ForthRow) == 0 ){keyPressed = '+';}

*/

}



