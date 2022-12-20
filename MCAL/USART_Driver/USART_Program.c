/*
 * USART_Program.c
 *
 *  Created on: Oct 18, 2022
 *      Author: Kimo Store
 */
#include "USART_Private.h"
#include "USART_Interface.h"
#include "USART_Config.h"

u8 Buffer;
ISR(USART_RX_VECTOR)
{
	Buffer = UDR;

}


ISR(USART_TX_VECTOR)
{

}

ISR(USART_BUFFER_EMPTY_VECTOR)
{

}
void USART_voidReceiveCharacterInterrupt(u8 *Copy_u8Data)
{
	*Copy_u8Data = Buffer;
	Buffer = 0;
}

void USART_voidInit(u32 Copy_u8BaudRate)
{
#if USARTMODE == ASynchronousNormal
	UBRRH = (u8)((Fosc / (16*Copy_u8BaudRate))>>24);
	UBRRL = (u8)((Fosc / (16*Copy_u8BaudRate)));
	CLEAR_BIT(UCSRC , UMSEL);
#elif USARTMODE == ASynchronousUDoubleSpeed

	UBRRH = (u8)((Fosc / (8*Copy_u8BaudRate))>>24);
	UBRRL = (u8)((Fosc / (8*Copy_u8BaudRate)));
	CLEAR_BIT(UCSRC , UMSEL);
#elif USARTMODE == SynchronousMasterMode

	UBRRH = (u8)((Fosc / (2*Copy_u8BaudRate))>>24);
	UBRRL = (u8)((Fosc / (2*Copy_u8BaudRate)));
	SET_BIT(UCSRC , UMSEL);
#endif

	SET_BIT(UCSRB , RXEN); /* Enable Receiver */
	SET_BIT(UCSRB , TXEN); /* Enable Transmitter */


#if USART_FrameSize == 5
	CLEAR_BIT(UCSRC , UCSZ2);
	CLEAR_BIT(UCSRC , UCSZ1);
	CLEAR_BIT(UCSRC , UCSZ0);

#elif USART_FrameSize == 6
	CLEAR_BIT(UCSRC , UCSZ2);
	CLEAR_BIT(UCSRC , UCSZ1);
	SET_BIT(UCSRC , UCSZ0);

#elif USART_FrameSize == 7
	CLEAR_BIT(UCSRC , UCSZ2);
	SET_BIT(UCSRC , UCSZ1);
	CLEAR_BIT(UCSRC , UCSZ0);

#elif USART_FrameSize == 8
	CLEAR_BIT(UCSRC , UCSZ2);
	SET_BIT(UCSRC , UCSZ1);
	SET_BIT(UCSRC , UCSZ0);


#elif USART_FrameSize == 9
	SET_BIT(UCSRC , UCSZ2);
	SET_BIT(UCSRC , UCSZ1);
	SET_BIT(UCSRC , UCSZ0);

#endif


#if USART_StopBit == 1
	CLEAR_BIT(UCSRC , USBS);
#elif USART_StopBit == 2
	SET_BIT(UCSRC , USBS);
#endif

#if	USART_Parity == No_Parity
	CLEAR_BIT(UCSRC , UPM0);
	CLEAR_BIT(UCSRC , UPM1);

#elif USART_Parity == Odd_Parity
	SET_BIT(UCSRC , UPM0);
	SET_BIT(UCSRC , UPM1);

#elif USART_Parity == Even_Parity
	CLEAR_BIT(UCSRC , UPM0);
	SET_BIT(UCSRC , UPM1);

#endif

}

void USART_voidInitInterrupt()
{

	SET_BIT(UCSRB , RXCIE);
	//SET_BIT(UCSRB , TXCIE);
	//SET_BIT(UCSRB , UDRIE);
	SET_BIT(UCSRB , RXEN); /* Enable Receiver */
	SET_BIT(UCSRB , TXEN); /* Enable Transmitter */


	sei();
}

void USART_voidSendCharacterPolling(u8 Copy_u8Char)
{
	/* Wait for Empty Transmit Buffer */

	while((CHECK_BIT(UCSRA , UDRE)) == 0);
	UDR = Copy_u8Char;


}
void USART_voidSendStringPolling(u8 *Copy_u8String)
{
	u8 i =0;
	while(Copy_u8String[i] != '\0')
	{
		USART_voidSendCharacterPolling(Copy_u8String[i]);
		i++;
	}
	Copy_u8String[i] = '\0';
}
u8 USART_voidReceiveCharacterPolling()
{
	while((CHECK_BIT(UCSRA , RXC)) == 0);
	return UDR;
}
void USART_voidReceiveStringPolling(u8 *Copy_u8String)
{
	u8 i =0;
	Copy_u8String[i] = USART_voidReceiveCharacterPolling();
	while(Copy_u8String[i] != '\r')
	{
		i++;
		Copy_u8String[i] = USART_voidReceiveCharacterPolling();
	}
	Copy_u8String[i] = '\0';
}


