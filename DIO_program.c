/****************************************************************/
/*   Author             :    FATMA MOHAMED AHMED  		        */
/*	 Date 				:    7 SEPTEMBER 2020					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Progam algorithm for DIO Peripheral	*/
/*									 [prog.c]				    */
/****************************************************************/




/****************************************************************/
/***********************  LIB DIRECTIVES ************************/
/****************************************************************/

#include	"STD_TYPES.h"
#include	"Bit_Math.h"

/****************************************************************/
/********************* DIO Component DIRECTIVES *****************/
/****************************************************************/

#include	"DIO_interface.h"
#include	"DIO_private.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to Set pin Direction	*/
/*					 Inputs : Copy_u8PORT , Copy_u8PIN ,		*/
/*								Copy_u8Direction	 			*/
/*					 return : void		 						*/
/****************************************************************/
void	DIO_voidSetPinDirection	(	u8 Copy_u8PORT , u8 Copy_u8PIN ,	u8 Copy_u8Direction	)
{
	/*	Range check	*/
	if( (Copy_u8PORT <4 ) && (Copy_u8PIN < 8))
	{
		if(Copy_u8Direction == OUTPUT)
		{
			switch(Copy_u8PORT)
			{
			case PORTA :	SET_BIT(DDRA_REG , Copy_u8PIN); break;
			case PORTB :	SET_BIT(DDRB_REG , Copy_u8PIN); break;
			case PORTC :	SET_BIT(DDRC_REG , Copy_u8PIN); break;
			case PORTD :	SET_BIT(DDRD_REG , Copy_u8PIN); break;
			}
		}
		else if(Copy_u8Direction == INPUT)
		{
			switch(Copy_u8PORT)
			{
			case PORTA :	CLR_BIT(DDRA_REG , Copy_u8PIN); break;
			case PORTB :	CLR_BIT(DDRB_REG , Copy_u8PIN); break;
			case PORTC :	CLR_BIT(DDRC_REG , Copy_u8PIN); break;
			case PORTD :	CLR_BIT(DDRD_REG , Copy_u8PIN); break;
			}
		}else
		{/*		Do nothing		*/}

	}
	else
	{/*		Do nothing			*/}
}
/****************************************************************/
/* Description    :  This function used to Set pin Direction	*/
/*					 Inputs : Copy_u8PORT , Copy_u8PIN ,		*/
/*								Copy_u8Direction	 			*/
/*					 return : void		 						*/
/****************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value)
{
	/*	Range check	*/
	if( (Copy_u8PORT <4 ) && (Copy_u8PIN < 8))
	{
		if(Copy_u8Value == HIGH)
		{
			switch(Copy_u8PORT)
			{
			case PORTA : SET_BIT(PORTA_REG,Copy_u8PIN);	break;
			case PORTB : SET_BIT(PORTB_REG,Copy_u8PIN);	break;
			case PORTC : SET_BIT(PORTC_REG,Copy_u8PIN);	break;
			case PORTD : SET_BIT(PORTD_REG,Copy_u8PIN);	break;
			}
		}	
		else if(Copy_u8Value == LOW)
		{
			switch(Copy_u8PORT)
			{
			case PORTA : CLR_BIT(PORTA_REG,Copy_u8PIN);	break;
			case PORTB : CLR_BIT(PORTB_REG,Copy_u8PIN);	break;
			case PORTC : CLR_BIT(PORTC_REG,Copy_u8PIN);	break;
			case PORTD : CLR_BIT(PORTD_REG,Copy_u8PIN);	break;
			}			
		}
		else
		{/*	Do nothing	*/}
	}
	else
	{/*	DO nothing	*/}

}
/****************************************************************/
/* Description    :  This function used to Set pin Direction	*/
/*					 Inputs : Copy_u8PORT , Copy_u8PIN ,		*/
/*								Copy_u8Direction	 			*/
/*					 return : void		 						*/
/****************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8 LOCAL_u8ReturnValue=0;
	switch(Copy_u8PORT)
	{
	case PORTA : LOCAL_u8ReturnValue = GET_BIT(PINA_REG,Copy_u8PIN); break;
	case PORTB : LOCAL_u8ReturnValue =  GET_BIT(PINB_REG,Copy_u8PIN); break;
	case PORTC : LOCAL_u8ReturnValue = GET_BIT(PINC_REG,Copy_u8PIN); break;
	case PORTD : LOCAL_u8ReturnValue = GET_BIT(PIND_REG,Copy_u8PIN); break;
	}


	return LOCAL_u8ReturnValue;
}
/****************************************************************/
/* Description    :  This function used to Set pin Direction	*/
/*					 Inputs : Copy_u8PORT , Copy_u8PIN ,		*/
/*								Copy_u8Direction	 			*/
/*					 return : void		 						*/
/****************************************************************/
void	DIO_voidTogglePine		(	u8 Copy_u8PORT , u8 Copy_u8PIN 							)
{
	if( (Copy_u8PORT <4 ) && (Copy_u8PIN < 8))
	{
		switch (Copy_u8PORT)
		{
		case PORTA :  TGL_BIT(PORTA_REG,Copy_u8PIN );  break;
		case PORTB :  TGL_BIT(PORTB_REG,Copy_u8PIN );  break;
		case PORTC :  TGL_BIT(PORTC_REG,Copy_u8PIN );  break;
		case PORTD :  TGL_BIT(PORTD_REG,Copy_u8PIN );  break;

		}
	}
}
/****************************************************************/
/* Description    :  This function used to Set pin Direction	*/
/*					 Inputs : Copy_u8PORT , Copy_u8PIN ,		*/
/*								Copy_u8Direction	 			*/
/*					 return : void		 						*/
/****************************************************************/
void	DIO_voidSetPortDirection(	u8 Copy_u8PORT , u8 Copy_u8Direction					)
{
	if(Copy_u8PORT < 4)
	{
		switch(Copy_u8PORT)
		{
		case PORTA : DDRA_REG = Copy_u8Direction ;  break ;
		case PORTB : DDRB_REG = Copy_u8Direction ;  break ;
		case PORTC : DDRC_REG = Copy_u8Direction ;  break ;
		case PORTD : DDRD_REG = Copy_u8Direction ;  break ;
		}
	}
}

/****************************************************************/
/* Description    :  This function used to Set pin Direction	*/
/*					 Inputs : Copy_u8PORT , Copy_u8PIN ,		*/
/*								Copy_u8Direction	 			*/
/*					 return : void		 						*/
/****************************************************************/

void	DIO_voidSetPortValue	(	u8 Copy_u8PORT , u8 Copy_u8Vlaue						)
{
	if(Copy_u8PORT <4)
	{
		switch(Copy_u8PORT)
		{
		case PORTA : PORTA_REG = Copy_u8Vlaue; break;
		case PORTB : PORTB_REG = Copy_u8Vlaue; break;
		case PORTC : PORTC_REG = Copy_u8Vlaue; break;
		case PORTD : PORTD_REG = Copy_u8Vlaue; break;
		}
	}
}

