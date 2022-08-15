/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#include   "STD_TYPES.h"
#include   "Bit_Math.h"
#include   "DIO_interface.h"
#include   "KYEPAD_interface.h"
#include   <util/delay.h>

const     u8  KEYPAD_u8SwitchValue [4][4]=
{
	{'1','2','3','='},
    {'4','5','6','0'},
	{'7','8','9','+'},
	{'/','*','-','.'}
};

u8 Column =0;
u8 Row =4;

u8    KEYPAD_u8GetPressedKey(void)
{
  u8 LOCAL_u8PressedKey = 0xff;

   for(Column=0;Column<4;Column++)
   {
	   DIO_voidSetPinValue(KYEPAD_PORT , Column , LOW);
	   for(Row=4;Row<8;Row++)
	   {
		   if(DIO_u8GetPinValue(KYEPAD_PORT,Row)==0)
		   {
			   LOCAL_u8PressedKey = KEYPAD_u8SwitchValue [Column][Row-4];
			   _delay_ms(10);  
		   }
		   while(DIO_u8GetPinValue(KYEPAD_PORT,Row)==0);

	   }
	   DIO_voidSetPinValue(KYEPAD_PORT , Column , HIGH);
   }

  
  return LOCAL_u8PressedKey;	
}
