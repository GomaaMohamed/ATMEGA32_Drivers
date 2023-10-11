/*****************************************************************************
* @file:    LCD_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Thu, 07 Sep 2023 19:09:10 +0300
* @brief:   LCD Driver.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "string.h"
#include "GPIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize lcd module
void LCD_init(void){
    #if LCD_MODE==M_8BIT
        GPIO_setPortDirection(LCD_PORT,OUTPUT);   //data GPIO_OUTPUT
	    GPIO_setPinDirection(LCD_PORT_CONTROL,RS,OUTPUT);//Rs GPIO_OUTPUT
	    GPIO_setPinDirection(LCD_PORT_CONTROL,RW,OUTPUT);//rw GPIO_OUTPUT
	    GPIO_setPinDirection(LCD_PORT_CONTROL,EN,OUTPUT);//en GPIO_OUTPUT

	    GPIO_setPinValue(LCD_PORT_CONTROL,RW,LOW);//RW =0

	    _delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	    LCD_writeCommand(0x38); //N=1 , F=0
	    _delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	    LCD_writeCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	    _delay_ms(1);           //delay 1ms
	    LCD_writeCommand(0x01); //clear LCD
	    _delay_ms(20);
	    LCD_writeCommand(0x80);


    #elif LCD_MODE==M_4BIT_SAMEPORT
        GPIO_setPinDirection(LCD_PORT,D4,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT,D5,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT,D6,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT,D7,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT_CONTROL,RS,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT_CONTROL,RW,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT_CONTROL,EN,OUTPUT);
	    _delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	    LCD_writeCommand(0x02);//4 bit mode only
	    _delay_ms(1); 
	    LCD_writeCommand(0x28); //N=1 , F=0
	    _delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	    LCD_writeCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	    _delay_ms(1);    //delay 1ms
	    LCD_writeCommand(0x01); //clear LCD
	    _delay_ms(20);
	    LCD_writeCommand(0x06);
	    LCD_writeCommand(0x80);
    #elif LCD_MODE==M_4BIT_SEPARATED
        GPIO_setPinDirection(LCD_PORT,D4,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT,D5,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT,D6,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT,D7,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT_CONTROL,RS,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT_CONTROL,RW,OUTPUT);
	    GPIO_setPinDirection(LCD_PORT_CONTROL,EN,OUTPUT);
    
	    _delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	    LCD_writeCommand(0x02);//4 bit mode only
	    _delay_ms(1);
	    LCD_writeCommand(0x28); //N=1 , F=0
	    _delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	    LCD_writeCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	    _delay_ms(1);    //delay 1ms
	    LCD_writeCommand(0x01); //clear LCD
	    _delay_ms(20);
	    LCD_writeCommand(0x06);
	    LCD_writeCommand(0x80);
    #endif

}

// Function to write character on lcd 
void LCD_writeChar(u8 Character){
	#if LCD_TYPE == LCD_16X2
			if (CurrentCursorPosition==16)
			{
				CurrentCursorPosition = 16;
				LCD_writeCommand(0xC0);
			}
			else
			{
				LCD_writeData(Character);
			}
		#elif LCD_TYPE == LCD_20X4
			if (CurrentCursorPosition == 20)
			{
				CurrentCursorPosition = 20;
				LCD_writeCommand(0xC0);
			}
			else if (CurrentCursorPosition == 40)
			{
				CurrentCursorPosition = 40;
				LCD_writeCommand(0x94);
			}
			else if (CurrentCursorPosition == 60)
			{
				CurrentCursorPosition = 60;
				LCD_writeCommand(0xD4);
			}
			else
			{
				// Do nothing
			}
			
		#endif
		LCD_writeData(Character);
}

// Function to write sentence on lcd 
void LCD_writeSentence(u8 *ptrSentance){
    u8 i=0;
	while(ptrSentance[i])
	{   
		#if LCD_TYPE == LCD_16X2
			if (ptrSentance[i]=='\n')
			{
				CurrentCursorPosition = 16;
				LCD_writeCommand(0xC0);
			}
			else
			{
				LCD_writeData(ptrSentance[i]);
			}
		#elif LCD_TYPE == LCD_20X4
			if ((ptrSentance[i]=='\n' && (CurrentCursorPosition < 20 ))||CurrentCursorPosition == 20)
			{
				CurrentCursorPosition = 20;
				LCD_writeCommand(0xC0);
			}
			else if ((ptrSentance[i]=='\n' && (CurrentCursorPosition > 20 && CurrentCursorPosition < 40))||CurrentCursorPosition == 40)
			{
				CurrentCursorPosition = 40;
				LCD_writeCommand(0x94);
			}
			else if ((ptrSentance[i]=='\n' && (CurrentCursorPosition > 40 && CurrentCursorPosition < 60))||CurrentCursorPosition == 60)
			{
				CurrentCursorPosition = 60;
				LCD_writeCommand(0xD4);
			}
			else
			{
				// Do nothing
			}
			if (ptrSentance[i]!='\n' && ptrSentance[i]!='\0')
			{
				LCD_writeData(ptrSentance[i]);
			}
			
			
		#endif
	    i++;
	}
}

// Function to move cursor to line and char
void LCD_goTo(u8 Line, u8 x){
	#if LCD_TYPE == LCD_16X2
    	if(Line==0)
		{
			if ( x <=15)
			{
				LCD_writeCommand(0x80 + x);
				CurrentCursorPosition = x;
			}
		}
		else if (Line==1)
		{
			if ( x <=15)
			{
				LCD_writeCommand(0xC0 + x);
				CurrentCursorPosition = 16 + x;
			}
		}
	#elif LCD_TYPE == LCD_20X4
		if(Line==0)
		{
			if ( x <=19)
			{
				LCD_writeCommand(0x80 + x);
				CurrentCursorPosition = x;
			}
		}
		else if (Line==1)
		{
			if ( x <=19)
			{
				LCD_writeCommand(0xC0 + x);
				CurrentCursorPosition = 20 + x;
			}
		}
		else if (Line==2)
		{
			if ( x <=19)
			{
				LCD_writeCommand(0x94 + x);
				CurrentCursorPosition = 40 + x;
			}
		}
		else if (Line==3)
		{
			if ( x <=19)
			{
				LCD_writeCommand(0xD4 + x);
				CurrentCursorPosition = 60 + x;
			}
		}
	#endif
}

// Function to write at specific location on lcd
void LCD_out(u8 Line, u8 x,u8 *ptrSentence){
    LCD_goTo( Line,  x);
	LCD_writeSentence(ptrSentence);
}

// Function to write number on lcd 
void LCD_writeNumber(u32 Number){
    u8 i=0,arr[10],j;
	if(Number==0){
		#if LCD_TYPE == LCD_16X2
			if (ptrSentance[i]=='\n')
			{
				CurrentCursorPosition = 16;
				LCD_writeCommand(0xC0);
			}
			else
			{
				LCD_writeData(ptrSentance[i]);
			}
		#elif LCD_TYPE == LCD_20X4
			if (CurrentCursorPosition == 20)
			{
				CurrentCursorPosition = 20;
				LCD_writeCommand(0xC0);
			}
			else if (CurrentCursorPosition == 40)
			{
				CurrentCursorPosition = 40;
				LCD_writeCommand(0x94);
			}
			else if (CurrentCursorPosition == 60)
			{
				CurrentCursorPosition = 60;
				LCD_writeCommand(0xD4);
			}
				LCD_writeData('0');
		#endif
	    
    }
	else{
		while(Number)
		{
			arr[i]=Number%10+'0';
			Number/=10;
			i++;
		}
		for(j=i;j>0;j--)
		{
		#if LCD_TYPE == LCD_16X2
			if (ptrSentance[i]=='\n')
			{
				CurrentCursorPosition = 16;
				LCD_writeCommand(0xC0);
			}
			else
			{
				LCD_writeData(ptrSentance[i]);
			}
		#elif LCD_TYPE == LCD_20X4
			if (CurrentCursorPosition == 20)
			{
				CurrentCursorPosition = 20;
				LCD_writeCommand(0xC0);
			}
			else if (CurrentCursorPosition == 40)
			{
				CurrentCursorPosition = 40;
				LCD_writeCommand(0x94);
			}
			else if (CurrentCursorPosition == 60)
			{
				CurrentCursorPosition = 60;
				LCD_writeCommand(0xD4);
			}
			
				LCD_writeData(arr[j-1]);
			
		#endif
			
		}
	}
} 

// Function to write number on lcd 
void LCD_writeNumber2(u16 Number){
    LCD_writeData(Number%10000/1000+'0');
	LCD_writeData(Number%1000/100+'0');
	LCD_writeData(Number%100/10+'0');
	LCD_writeData(Number%10/1+'0');
}

// Function to create a custom character for lcd
void LCD_createCharacter(u8 *Pattern,u8 Location){
    u8 i=0;
	LCD_writeCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(i=0;i<8;i++)
	LCD_writeData(Pattern[i]);          //Pass the bytes of pattern on LCD
}

// Function to clear lcd
void LCD_clear(void){
    LCD_writeCommand(0x01);
	CurrentCursorPosition = 0;
}

// Function to shift lcd left
void LCD_shiftLcdLeft(void){
	LCD_writeCommand(0x18);
	CurrentCursorPosition--;
}

// Function to shift lcd right
void LCD_shiftLcdRight(void){
	LCD_writeCommand(0x1C);
	CurrentCursorPosition++;
}

/************* service for lcd *****************/
u8   *convert_data(u32 Value){
    s8 i=0;
	static u8 arr[10]={0};
	if(Value==0)
	{arr[i]='0';}
	else{
		while(Value)//123
		{
			arr[8-i]=Value%10+'0';
			Value/=10;
			i++;
		}
	}	
	return &arr[8-i+1];
}
u32  str_to_int(u8 *ptr){
     u32 number=0;
	 for(u16 i=0;i<strlen((char*)ptr);i++)
	 {
		 number=(ptr[i]-48)+number*10;
		 
	 }
	 return number;
}

/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

// Function to send command to lcd
static void LCD_writeCommand(u8 Command){
    #if LCD_MODE==M_8BIT
        GPIO_setPinValue(LCD_PORT_CONTROL,RS,LOW);
	    GPIO_setPortValue(LCD_PORT,Command);

	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(2);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(2);
    #elif LCD_MODE==M_4BIT_SAMEPORT
        GPIO_setPinValue(LCD_PORT_CONTROL,RS,LOW);
	    GPIO_setPinValue(LCD_PORT_CONTROL,RW,LOW);
	    GPIO_clearPortMask(LCD_PORT,M_4BIT_MASK);
	    GPIO_setPortMask(LCD_PORT,((Command&0x0f0)>>(4-D4)));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_ms(2);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_ms(2);
	    GPIO_setPortMask(LCD_PORT,M_4BIT_MASK);
	    GPIO_clearPortMask(LCD_PORT,(Command&0x0f<<(D4)));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_ms(2);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_ms(2);
    #elif LCD_MODE==M_4BIT_SEPARATED
        GPIO_setPinValue(LCD_PORT_CONTROL,RS,LOW);
	    GPIO_setPinValue(LCD_PORT_CONTROL,RW,LOW);
	    GPIO_setPinValue(LCD_PORT,D4,GET_BIT(Command,4));
	    GPIO_setPinValue(LCD_PORT,D5,GET_BIT(Command,5));
	    GPIO_setPinValue(LCD_PORT,D6,GET_BIT(Command,6));
	    GPIO_setPinValue(LCD_PORT,D7,GET_BIT(Command,7));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT,D4,GET_BIT(Command,0));
	    GPIO_setPinValue(LCD_PORT,D5,GET_BIT(Command,1));
	    GPIO_setPinValue(LCD_PORT,D6,GET_BIT(Command,2));
	    GPIO_setPinValue(LCD_PORT,D7,GET_BIT(Command,3));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
    #endif
}

// Function to send data to lcd
static void LCD_writeData(u8 Data){
	#if LCD_TYPE == LCD_16X2
		if(CurrentCursorPosition==16){LCD_writeCommand(0xC0);}
	#elif LCD_TYPE == LCD_20X6
		if(CurrentCursorPosition==20){LCD_writeCommand(0xC0);}
		else if(CurrentCursorPosition==40){LCD_writeCommand(0x94);}
		else if(CurrentCursorPosition==60){LCD_writeCommand(0xD4);}
	#endif

    #if LCD_MODE==M_8BIT
        GPIO_setPinValue(LCD_PORT_CONTROL,RS,HIGH);
	    GPIO_setPortValue(LCD_PORT,(Data));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
    #elif LCD_MODE==M_4BIT_SAMEPORT
        GPIO_setPinValue(LCD_PORT_CONTROL,RS,HIGH);
	    GPIO_setPinValue(LCD_PORT_CONTROL,RW,LOW);
    
	    GPIO_clearPortMask(LCD_PORT,M_4BIT_MASK);
	    GPIO_setPortMask(LCD_PORT,((Data&0x0f0)>>(4-D4)));
    
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
		_delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
    
	    GPIO_clearPortMask(LCD_PORT,M_4BIT_MASK);
	    GPIO_setPortMask(LCD_PORT,(Data&0x0f<<(D4)));
    
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
    #elif LCD_MODE==M_4BIT_SEPARATED
        GPIO_setPinValue(LCD_PORT_CONTROL,RS,HIGH);
	    GPIO_setPinValue(LCD_PORT_CONTROL,RW,LOW);
	    GPIO_setPinValue(LCD_PORT,D4,GET_BIT(Data,4));
	    GPIO_setPinValue(LCD_PORT,D5,GET_BIT(Data,5));
	    GPIO_setPinValue(LCD_PORT,D6,GET_BIT(Data,6));
	    GPIO_setPinValue(LCD_PORT,D7,GET_BIT(Data,7));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT,D4,GET_BIT(Data,0));
	    GPIO_setPinValue(LCD_PORT,D5,GET_BIT(Data,1));
	    GPIO_setPinValue(LCD_PORT,D6,GET_BIT(Data,2));
	    GPIO_setPinValue(LCD_PORT,D7,GET_BIT(Data,3));
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,HIGH);
	    _delay_us(10);
	    GPIO_setPinValue(LCD_PORT_CONTROL,EN,LOW);
	    _delay_us(10);
	#endif
	CurrentCursorPosition++;
}






