/*****************************************************************************
* @file:    GPS_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sun, 10 Sep 2023 13:26:58 +0300
* @brief:   GPS Driver.
* Note: all getters return strings in formatted values of location and time
******************************************************************************/
#ifndef _GPS_INTERFACE_H
#define _GPS_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize gps module 
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant  
 */
void GPS_init(void);

/**
 * @brief---------------------> Update time and location 
 * @return--------------------> None
 * @preconditions-------------> Gps module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void GPS_update(void);


/**
 * @brief---------------------> Get current time 
 * @return--------------------> Buffer address contains current time
 * @preconditions-------------> Gps module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
u8 *GPS_getTime(void);

/**
 * @brief---------------------> Get current Latitude 
 * @return--------------------> Buffer address contains current Latitude
 * @preconditions-------------> Gps module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
u8 *GPS_getLatitude(void);

/**
 * @brief---------------------> Get current longitude
 * @return--------------------> Buffer address contains current longitude
 * @preconditions-------------> Gps module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
u8 *GPS_getLongitude(void);

/**
 * @brief---------------------> Get current altitude
 * @return--------------------> Buffer address contains current altitude
 * @preconditions-------------> Gps module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
u8* GPS_getAltitude(void);

#endif