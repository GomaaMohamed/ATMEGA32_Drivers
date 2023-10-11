/*****************************************************************************
* @file:    WDG_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 01 Oct 2023 22:26:56 +0300
* @brief:   Watch Dog Driver for Atmega32.
******************************************************************************/
#ifndef WDG_INTERFACE_H
#define WDG_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* WDG time data type */
typedef enum
{
    // 5 volt operation options
    WDGT_5V_16_3ms=0,
    WDGT_5V_32_5ms,
    WDGT_5V_65_0ms,
    WDGT_5V_0_13s,
    WDGT_5V_0_26s,
    WDGT_5V_0_52s,
    WDGT_5V_1_0s,
    WDGT_5V_2_1s,
    // 3 volt operation options
    WDGT_3V_17_1ms=0,
    WDGT_3V_34_3ms,
    WDGT_3V_68_5ms,
    WDGT_3V_0_14s,
    WDGT_3V_0_27s,
    WDGT_3V_0_55s,
    WDGT_3V_1_1s,
    WDGT_3V_2_2s,
    WDGT_ERR=8
} WatchDogTime_type;

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Start watch dog timer
 * @parameter1----------------> (WatchDogTime) time after it the wdgt will reset controller
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void WDG_startTimer(WatchDogTime_type WatchDogTime);

/**
 * @brief---------------------> Stop watch dog timer
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Watch dog timer is activated
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void WDG_stopTimer(void);


#endif

