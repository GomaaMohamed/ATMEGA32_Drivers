/*****************************************************************************
* @file:    SPI_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sat, 16 Sep 2023 11:01:07 +0300
* @brief:   SPI Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize spi module
void SPI_init(void)
{
    // Initialize spi mode
    #if SPI_MODE == SPI_MASTER
        GPIO_setPinDirection(SPI_MOSI_PORT , SPI_MOSI_PIN , OUTPUT);
	    GPIO_setPinDirection(SPI_SCK_PORT , SPI_SCK_PIN , OUTPUT);
	    GPIO_setPinDirection(SPI_SS_PORT , SPI_SS_PIN , OUTPUT);
	    GPIO_setPinDirection(SPI_MISO_PORT , SPI_MISO_PIN , INPUT);
	    GPIO_setPinValue(SPI_SS_PORT , SPI_SS_PIN , HIGH);
	    SET_BIT(SPCR , MSTR);
    #elif SPI_MODE == SPI_SLAVE
        GPIO_setPinDirection(SPI_MOSI_PORT , SPI_MOSI_PIN , INPUT);
	    GPIO_setPinDirection(SPI_SCK_PORT , SPI_SCK_PIN , INPUT);
	    GPIO_setPinDirection(SPI_SS_PORT , SPI_SS_PIN , INPUT);
	    GPIO_setPinDirection(SPI_MISO_PORT , SPI_MISO_PIN , OUTPUT);
	    CLR_BIT(SPCR , MSTR);
    #endif
	
    // Configure clock polarity
    #if   SPI_CLOCK_POL == SPI_CPOL_0
        CLR_BIT(SPCR, CPOL);
    #elif SPI_CLOCK_POL == SPI_CPOL_1
        SET_BIT(SPCR, CPOL);
    #endif

    // Configure clock phase
    #if   SPI_CLOCK_PHASE == SPI_CPHA_LEADING
        CLR_BIT(SPCR, CPHA);
    #elif SPI_CLOCK_PHASE == SPI_CPHA_TRAILING
        SET_BIT(SPCR, CPHA);
    #endif

    // Configure data order
    #if   SPI_DATA_ORDER == SPI_LSB
        SET_BIT(SPCR, DORD);
    #elif SPI_DATA_ORDER == SPI_MSB
        CLR_BIT(SPCR, DORD);
    #endif

    // Configure spi speed on master mode only
    #if SPI_MODE == SPI_MASTER
        #if   SPI_SPEED == SPI_NORMAL
            CLR_BIT(SPSR, SPI2X);
            #if   SPI_PRESCALER == SPI_PRESCALER_4
                CLR_BIT(SPCR, SPR0);
                CLR_BIT(SPCR, SPR1);
            #elif SPI_PRESCALER == SPI_PRESCALER_16
                SET_BIT(SPCR, SPR0);
                CLR_BIT(SPCR, SPR1);
            #elif SPI_PRESCALER == SPI_PRESCALER_64
                CLR_BIT(SPCR, SPR0);
                SET_BIT(SPCR, SPR1);
            #elif SPI_PRESCALER == SPI_PRESCALER_128
                SET_BIT(SPCR, SPR0);
                SET_BIT(SPCR, SPR1);
            #endif

        #elif SPI_SPEED == SPI_DOUBLE
            SET_BIT(SPSR, SPI2X);
            #if   SPI_PRESCALER == SPI_PRESCALER_2
                CLR_BIT(SPCR, SPR0);
                CLR_BIT(SPCR, SPR1);
            #elif SPI_PRESCALER == SPI_PRESCALER_8
                SET_BIT(SPCR, SPR0);
                CLR_BIT(SPCR, SPR1);
            #elif SPI_PRESCALER == SPI_PRESCALER_32
                CLR_BIT(SPCR, SPR0);
                SET_BIT(SPCR, SPR1);
            #elif SPI_PRESCALER == SPI_PRESCALER_64
                SET_BIT(SPCR, SPR0);
                SET_BIT(SPCR, SPR1);
            #endif
        #endif
    #endif
    // Enable spi
    SET_BIT(SPCR , SPE);
}

// Function to send data at master mode
void SPI_sendDataMaster(u8 Data)
{
    u8 FlushBuffer;
    GPIO_setPinValue(SPI_SS_PORT , SPI_SS_PIN , LOW);
	SPDR = Data;
	while((GET_BIT(SPSR , SPIF)) == 0);
	FlushBuffer = SPDR;
    GPIO_setPinValue(SPI_SS_PORT , SPI_SS_PIN , HIGH);
}

// Function to send string  at master mode
void SPI_sendStringMaster(u8 *String)
{
    u8 i = 0;
    while (String[i] != '\0')
    {
        SPI_sendDataMaster(String[i]);
        i++;
    }
    SPI_sendDataMaster(String[i]);
}

// Function to send data polling at slave mode
void SPI_sendDataSlave(u8 Data)
{
    u8 FlushBuffer;
	SPDR = Data;
	while((GET_BIT(SPSR , SPIF)) == 0);
	FlushBuffer = SPDR;
}

// Function to receive data at master mode
u8 SPI_receiveDataMaster(void)
{
    GPIO_setPinValue(SPI_SS_PORT , SPI_SS_PIN , LOW);
	SPDR = 0xFF;  // Dummy Data
	while((GET_BIT(SPSR , SPIF)) == 0);
    GPIO_setPinValue(SPI_SS_PORT , SPI_SS_PIN , HIGH);
	return SPDR;
}

// Function to receive data polling at slave mode
u8 SPI_receiveDataPollingSlave(void)
{
    while(GET_BIT(SPSR, SPIF) == 1);
    return SPDR;
}

// Function to receive data at slave mode
SpiReceiveState_type SPI_receiveDataSlave(u8 *Data)
{
    SpiReceiveState_type Flag = SPI_DATA_UNRECEIVED;
    if(GET_BIT(SPSR, SPIF) == 1)
    {
        *Data = SPDR;
        Flag = SPI_DATA_RECEIVED;
    }
    return Flag;
}




