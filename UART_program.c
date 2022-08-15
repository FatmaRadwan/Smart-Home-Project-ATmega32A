/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_VoidInit(void)
{
	u8 UCSRC_R =0;		// Use to write on UCSRB oncex
	//Enable Rx && TX  (Register B)
	SET_BIT(UCSRB,RXEN);	//Receiver Enable
	SET_BIT(UCSRB,TXEN);	//Transmitter Enable
	
	//UART select mode (Register C) : Asynchronous mode 
	CLR_BIT(UCSRC_R,UMSEL);	//USART Mode Select
	
	//disenable parity mode 
	CLR_BIT(UCSRC_R,UPM1);	//USART Mode Select
	CLR_BIT(UCSRC_R,UPM0);	//USART Mode Select
	
	//STOP BIT : 1-BIT
	CLR_BIT(UCSRC_R,USBS);	//Stop Bit Select
	
	//Character Size : 8 bit 
	SET_BIT(UCSRC_R,UCSZ0);
	SET_BIT(UCSRC_R,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);	
	
	// SET BIT 7 TO Ready to write
	SET_BIT(UCSRC_R ,URSEL);
	UCSRC = UCSRC_R ;
	//baud rate  :9600 && 8MHz

	/*  Store the low byte of the UBBR*/
	UBRRL = (u8)(LOC_baudEquation);
	 /*  Store the High byte of the UBBR*/
	UBRRH =(u8)(LOC_baudEquation>>8);


//	UBRRL =51;
//	UBRRH =0;
		
}
void UART_VoidTransmit(u8 DATA)
{
	//check if Data register is empty or not 
	while( GET_BIT(UCSRA , UDRE)==0 )	//USART Data Register Empty
	{
		
	}
	UDR =DATA ;
}
void UART_VidSend(u8 *LOC_u8Data){
u8 i=0;
for(i=0;LOC_u8Data[i]!=0;i++){
	while(0==GET_BIT(UCSRA,6));
	UDR=LOC_u8Data[i];
	}
}
u8 UART_VoidRead(void)
{
	//check if Data  is Received completely  or not
	
	while( (GET_BIT(UCSRA ,RXc)) ==0 )	//USART Receive Complete
	{
		
	}
	return UDR;
	
}
void UART_sendString(const u8 *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		UART_VoidTransmit(Str[i]);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}
	*******************************************************************/
}
