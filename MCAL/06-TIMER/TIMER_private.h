/*****************************************************************************
* @file:    TIMER_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 06 Sep 2023 10:51:56 +0300
* @brief:   Timer Driver for Atmega32.
******************************************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/* ==================================================================== */
/* =================== private variables and Macros =================== */
/* ==================================================================== */

/* Registers of Timer */

// Base address of timers
#define BASE_ADDRESS 0x20

/******** Shared registers **********/
#define SFIOR  *((volatile u8*)(BASE_ADDRESS + 0x30))
#define OSCCAL *((volatile u8*)(BASE_ADDRESS + 0x31))
#define TWCR   *((volatile u8*)(BASE_ADDRESS + 0x36))
#define SPMCR  *((volatile u8*)(BASE_ADDRESS + 0x37))
#define TIFR   *((volatile u8*)(BASE_ADDRESS + 0x38))
#define TIMSK  *((volatile u8*)(BASE_ADDRESS + 0x39))

/******** Timer0 registers **********/
#define TCNT0 *((volatile u8*)(BASE_ADDRESS + 0x32))
#define TCCR0 *((volatile u8*)(BASE_ADDRESS + 0x33))
#define OCR0  *((volatile u8*)(BASE_ADDRESS + 0x3C))

/******** Timer1 registers ************/
#define ICR1   *((volatile u16*)(BASE_ADDRESS + 0x26))
#define ICR1L  *((volatile u8*)(BASE_ADDRESS + 0x26))
#define ICR1H  *((volatile u8*)(BASE_ADDRESS + 0x27))

#define OCR1B  *((volatile u16*)(BASE_ADDRESS + 0x28))
#define OCR1BL *((volatile u8*)(BASE_ADDRESS + 0x28))
#define OCR1BH *((volatile u8*)(BASE_ADDRESS + 0x29))

#define OCR1A  *((volatile u16*)(BASE_ADDRESS + 0x2A))
#define OCR1AL *((volatile u8*)(BASE_ADDRESS + 0x2A))
#define OCR1AH *((volatile u8*)(BASE_ADDRESS + 0x2B))

#define TCNT1  *((volatile u16*)(BASE_ADDRESS + 0x2C))
#define TCNT1L *((volatile u8*)(BASE_ADDRESS + 0x2C))
#define TCNT1H *((volatile u8*)(BASE_ADDRESS + 0x2D))

#define TCCR1B *((volatile u8*)(BASE_ADDRESS + 0x2E))
#define TCCR1A *((volatile u8*)(BASE_ADDRESS + 0x2F))



/************* Timer2 registers ***************/
#define OCR2    *((volatile u8*)(BASE_ADDRESS + 0x23))
#define TCNT2   *((volatile u8*)(BASE_ADDRESS + 0x24))
#define TCCR2   *((volatile u8*)(BASE_ADDRESS + 0x25))


/*** TCCR0 bits ***/
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/*** TCCR2 bits ***/
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

/*** ASSR bits ***/
/* bits 7-4 reserved */
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0

/*** TCCR1A bits ***/
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/*** TCCR1B bits ***/
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0


/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* SPMCR */
#define SPMIE   7
#define RWWSB   6
/* bit 5 reserved */
#define RWWSRE  4
#define BLBSET  3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

#define  TIM_STOP	0x07
#define  TIMER0_PRESCKER_ADJUST(Scalar) (TCCR0=((TCCR0)&(~0x07))|(Scalar))

/************** Private variables *******************/
static void (*TIMER0_OVF_CallBack) (void)=NULL;
static void (*TIMER0_CMP_CallBack) (void)=NULL;
static volatile u8 Timer0Scaler = 0;

static void (*TIMER1_OVF_CallBack) (void)=NULL;
static void (*TIMER1_CMPA_CallBack) (void)=NULL;
static void (*TIMER1_CMPB_CallBack) (void)=NULL;
static void (*TIMER1_ICU_CallBack) (void)=NULL;
static volatile u8 Timer1Scaler = 0;


#endif

