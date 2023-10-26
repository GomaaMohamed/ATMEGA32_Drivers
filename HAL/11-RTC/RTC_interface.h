/*****************************************************************************
* @file:    RTC_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 24 Sep 2023 21:12:51 +0300
* @brief:   Real Time Clock Driver.
******************************************************************************/
#ifndef _RTC_INTERFACE_H
#define _RTC_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Time data type */
typedef struct time
{
    u8 Hour;
    u8 Minute;
    u8 Second;
} Time_type;

/* Calender data type */
typedef struct calender
{
    u8 Day;
    u8 Date;
    u8 Month;
    u8 Year;
} Calender_type;

/* ==================================================================== */
/* ======================== Public Macros ============================= */
/* ==================================================================== */

#define HOUR_12_AM				0x40
#define HOUR_12_PM				0x60
#define HOUR_24					0x00


/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */			
				
/**
 * @brief---------------------> Initialize rtc module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void RTC_init(void);

/**
 * @brief---------------------> Write calender
 * @parameter1----------------> (Day) day to be setted
 * @parameter2----------------> (Date) date to be setted
 * @parameter3----------------> (Month) month to be setted
 * @parameter4----------------> (Year) year to be setted
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void RTC_writeCalendar(u8 Day, u8 Date, u8 Month, u8 Year);

/**
 * @brief---------------------> Write clock
 * @parameter1----------------> (Hour) hour to be setted
 * @parameter2----------------> (Minute) minute to be setted
 * @parameter3----------------> (Second) Second to be setted
 * @parameter4----------------> (Format) format to be setted
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void RTC_writeClock(u8 Hour, u8 Minute, u8 Second, u8 Format);

/**
 * @brief---------------------> Check clock format
 * @parameter1----------------> (Hour) hour to be checked its format
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
u8 RTC_isItPM(u8 Hour);

/**
 * @brief---------------------> Read clock
 * @param---------------------> None
 * @return--------------------> Clock 
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
Time_type RTC_readClock(void);

/**
 * @brief---------------------> Read calender
 * @param---------------------> None
 * @return--------------------> Calender
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
Calender_type RTC_readCalendar(void);




#endif

