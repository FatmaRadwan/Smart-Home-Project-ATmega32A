/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define		UDR		  *((volatile u8*)0x2C)			

#define		UCSRA 	  *((volatile u8*)0x2B)

#define		UCSRB	  *((volatile u8*)0x2A)

#define		UCSRC	  *((volatile u8*)0x40)

#define     UBRRL 	  *((volatile u8*)0x29)

#define     UBRRH     *((volatile u8*)0x40)


#endif /* --- End of the gaurd --- */
