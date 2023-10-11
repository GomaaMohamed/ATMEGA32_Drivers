/*****************************************************************************
* @file:    RTC_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 24 Sep 2023 21:12:51 +0300
* @brief:   Real Time Clock Driver.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_interface.h"
#include "util/delay.h"

#include "RTC_interface.h"
#include "RTC_private.h"
#include "RTC_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize rtc
void RTC_init(void)
{
	// Initialize i2c
    I2C_init();
	// Enable RTC Clock
	I2C_Start(0b1101000,WRITE);	
	I2C_Write(0x00);						
	I2C_Write(0x00);
    I2C_Stop();
	_delay_ms(10);
	
	// Set RTC control
	I2C_Start(0b1101000,WRITE);	
	I2C_Write(0x07);							
	I2C_Write(0x00);	
    I2C_Stop();
	_delay_ms(10);
}

// Function to write calender
void RTC_writeCalendar(u8 Day, u8 Date, u8 Month, u8 Year)
{
    I2C_Start(0b1101000,WRITE);	    /* Start I2C communication with RTC */
	I2C_Write(3);								/* Write on 3 location for day value */
	I2C_Write(Day);							    /* Write day value on 03 location */
	I2C_Write(Date);							/* Write date value on 04 location */
	I2C_Write(Month);							/* Write month value on 05 location */
	I2C_Write(Year);							/* Write year value on 06 location */
	I2C_Stop();	
}

// Function to write clock
void RTC_writeClock(u8 Hour, u8 Minute, u8 Second, u8 Format)
{
    Hour |= Format;
	I2C_Start(0b1101000,WRITE);             /* Start I2C communication with RTC */
	I2C_Write(0);	                        /* Write on 0 location for second value */
    I2C_Write(Second);						/* Write second value on 00 location */
	I2C_Write(Minute);						/* Write minute value on 01 location */
	I2C_Write(Hour);						/* Write hour value on 02 location */
	I2C_Stop();								/* Stop I2C communication */
}

// Function to read clock
Time_type RTC_readClock(void)
{
    Time_type TempTime;
    I2C_Start(0b1101000, WRITE);        /* Start I2C communication with RTC */
    I2C_Write(0);				        /* Write address to read */
    I2C_RepeatedStart(0b1101000,READ);  /* Repeated start with device read address */
	TempTime.Second = I2C_ReadAck();	/* Read second */
	TempTime.Minute = I2C_ReadAck();	/* Read minute */
	TempTime.Hour   = I2C_ReadNotAck();	/* Read hour with Nack */
	I2C_Stop();
    return TempTime;
}

// Function to read calender
Calender_type RTC_readCalendar(void)
{
    Calender_type TempCalender;
    I2C_Start(0b1101000, WRITE);
    I2C_Write(3);
	I2C_RepeatedStart(0b1101000,READ);

	TempCalender.Day = I2C_ReadAck();		/* Read day */
	TempCalender.Date = I2C_ReadAck();		/* Read date */
	TempCalender.Month = I2C_ReadAck();		/* Read month */
	TempCalender.Year = I2C_ReadNotAck();	/* Read the year with Nack */
	I2C_Stop();
    return TempCalender;
}






