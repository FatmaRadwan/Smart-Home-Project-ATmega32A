/******************************************/
/*   Author     :FATMA MOHAMED AHMED 	  */
/*  version     : V01			          */
/******************************************/
/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef  UART_INTERFACE_H
#define  UART_INTERFACE_H

void UART_VoidInit(void);
void UART_VoidTransmit(u8 DATA);
u8 UART_VoidRead(void);
void UART_sendString(const u8 *Str);
void UART_VidSend(u8 *LOC_u8Data);

/*********************** equation of baud rate *****************/

#define  LOC_baudEquation	((FREQ_CPU / (16 * BAUD_RATE)) - 1 )

/***********USART Control and Status Register A BITs ***********/
#define RXc		7
#define TXc		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0
/***************************************************************/

/***********USART Control and Status Register B BITs ***********/
#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0
/***************************************************************/

/***********USART Control and Status Register C BITs ***********/
#define URSEL		7
#define UMSEL		6
#define UPM1		5
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL		0
/***************************************************************/



#endif /* --- End of the gaurd --- */
