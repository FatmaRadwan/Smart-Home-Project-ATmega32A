/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "GIE_private.h"




void GIE_voidInit(void)
{
	SET_BIT(SREG,I);
	
}
