/*****************************************************************************
* @file:    UART_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 08 Sep 2023 21:34:43 +0300
* @brief:   UART Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

/* ==================================================================== */
/* ======================== Global Variables ========================== */
/* ==================================================================== */

const u16 BaudRateArray[TOTAL_SPEED_MODE][TOTAL_CPU_F][TOTAL_BAUD_RATE]=
{{{103, 51, 25, 16, 12,  8},{207,103, 51, 34, 25, 16},{416,207,103, 68 ,51, 34}},
{{207,103, 51, 34, 25, 16},{416,207,103, 68 ,51, 34},{832,416,207,138,103, 68}}};

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialze Uart module
void UART_init(void)
{
	    volatile u8  UCSRC_var=0;
		u16 UBRR_var=0; 

	// Set pin directions of UART
	GPIO_setPinDirection(UART_RX_PORT,UART_RX_PIN,INPUT);
	GPIO_setPinDirection(UART_TX_PORT,UART_TX_PIN,OUTPUT);

	// Set transmission speed
	#if (SPEED_MODE==NORMAL_SPEED)
		CLR_BIT(UCSRA,U2X);
	#elif (SPEED_MODE==DOUBLE_SPEED)
		SET_BIT(UCSRA,U2X);
	#endif

		// Set URSEL to write data to UCSRC register 
		SET_BIT(UCSRC_var,7);

		// Set synchronization
	#if (SYNCH_MODE==SYNCH)
		SET_BIT(UCSRC_var,UMSEL)
	#elif (SYNCH_MODE==ASYNCH)
		CLR_BIT(UCSRC_var,UMSEL);
	#endif

		// Set parity mode
	#if (PARITY_MODE==NO_PARITY)
		CLR_BIT(UCSRC_var,UPM0);
		CLR_BIT(UCSRC_var,UPM1);
	#elif (PARITY_MODE==EVEN_PARITY)
		CLR_BIT(UCSRC_var,UPM0);
		SET_BIT(UCSRC_var,UPM1);
	#elif (PARITY_MODE==ODD_PARITY)
		SET_BIT(UCSRC_var,UPM0);
		SET_BIT(UCSRC_var,UPM1);
	#endif

		// Set data bits
	#if (NUMBER_OF_DATA_BITS==DATA_BITS_5)
		CLR_BIT(UCSRC_var,UCSZ0);
		CLR_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRC_var,UCSZ2);
	#elif (NUMBER_OF_DATA_BITS==DATA_BITS_6)
		SET_BIT(UCSRC_var,UCSZ0);
		CLR_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRC_var,UCSZ2);
	#elif (NUMBER_OF_DATA_BITS==DATA_BITS_7)
		CLR_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
	#elif (NUMBER_OF_DATA_BITS==DATA_BITS_8)
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
	#elif (NUMBER_OF_DATA_BITS==DATA_BITS_9)
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
	#endif
		// Stop bits
	#if (NUMBER_OF_STOP_BITS==ONE_STOP_BIT)
		CLR_BIT(UCSRC_var,USBS);
	#elif (NUMBER_OF_STOP_BITS==TWO_STOP_BIT)
		SET_BIT(UCSRC_var,USBS);
	#endif
	// Set UCSRC value  
	UCSRC=UCSRC_var;

	// Set Baud rate 
	UBRR_var=BaudRateArray[SPEED_MODE][CPU_F][BUAD_RATE];
	UBRRH = (u8)(UBRR_var>>8);
	UBRRL = (u8)UBRR_var;

	// Enable UART 
	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);
	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);
}

// Function to send a character
void UART_sendCharacter(u8 Character)
{
	// Wait until serial buffer become empty
    while((GET_BIT(UCSRA , UDRE)) == 0);
	// Send character
	UDR = Character;
}

// Function to receive a character
UartReceiveState_type UART_receiveCharacter(u8 *Character)
{
	// Flag to check if the character was received or not 
	UartReceiveState_type Flag = UART_DATA_UNRECEIVED;
	if ((GET_BIT(UCSRA, RXC)) == 1)
	{
		*Character = UDR;
		Flag = UART_DATA_RECEIVED;
	}
	// Return 1 if the character was successfully received else it reutns 0
	return Flag;
}

// Function to send a string
void UART_sendString(u8 *String)
{
    u8 i =0;
	// Loop on all string and send character by character
	while(String[i] != '\0')
	{
		UART_sendCharacter(String[i]);
		i++;
	}
	// Send null character to indicate the end of the string at receiver
	UART_sendCharacter('\0');
}

// Function to receive a string
void UART_receiveString(u8 *String)
{
    u8 i =0;
	UartReceiveState_type State = UART_receiveCharacter(&String[i]);
	while(String[i] != '\0' && State == UART_DATA_RECEIVED)
	{
		i++;
		String[i] = UART_receiveCharacter(&String[i]);
	}
	String[i] = '\0';
}

// Function to enable Rx interrupt
void UART_enableRxInterrupt(void)
{
    SET_BIT(UCSRB,RXCIE);
}

// Function to disable Rx interrupt
void UART_disableRxInterrupt(void)
{
    CLR_BIT(UCSRB,RXCIE);
}

// Function to enable Tx interrupt
void UART_enableTxInterrupt(void)
{
    SET_BIT(UCSRB,TXCIE);
}

// Function to disable Tx interrupt
void UART_disableTxInterrupt(void)
{
    CLR_BIT(UCSRB,TXCIE);
}

// Function to set Rx Callback
void UART_setRxCallBack(void (*Callback)(void))
{
    UART_RX_Callback = Callback;
}

// Function to set Tx Callback
void UART_setTxCallBack(void (*Callback)(void)
){
    UART_TX_Callback = Callback;
}


/********************** ISRs *********************/

// UART Rx Handler
ISR(USART_RXC_vect)
{
	if (UART_RX_Callback!=NULL)
	{
		UART_RX_Callback();
	}
}

// UART Tx Handler
ISR(USART_TXC_vect)
{
	if (UART_TX_Callback!=NULL)
	{
		UART_TX_Callback();
	}
}


