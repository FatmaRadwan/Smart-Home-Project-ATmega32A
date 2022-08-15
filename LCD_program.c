/****************************************************************/
/*   Author             :   FATMA MOHAMED AHMED 			    */
/*	 Date 				:   8 SEPTEMBER 2020					*/
/*	 Version 			:   1.0V 							 	*/
/*	 Description 		:  Program algorithm for LCD Peripheral	*/
/*									 [prog.c]				    */
/****************************************************************/


/****************************************************************/
/***********************  LCD DIRECTIVES ************************/
/****************************************************************/

#include	"STD_TYPES.h"
#include	"Bit_Math.h"
#include     <avr/delay.h>


/****************************************************************/
/********************* LCD Component DIRECTIVES *****************/
/****************************************************************/

#include	"DIO_interface.h"

#include 	"LCD_interface.h"

#include    "LCD_config.h"
/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

void	LCD_voidInit(void)
{
	if (LCD_MODE == EIGHT_BIT)
	{
		/*  wait for 30msec for VDD RISES to 4.5 volt   */
			_delay_ms(35);

			/*     function Set  2lines Display and 5*7 Char Font*/
			//LCD_voidSendCMD(0b00111000);
		    LCD_voidSendCMD(0x38);
			/*  wait until 39 Micro Sec   */
			_delay_ms(1);

			/*     Display ON/OFF Control D=1 Display on Cursor OFF*/
			//LCD_voidSendCMD(0b00001100);
			LCD_voidSendCMD(0x0c);
			/*  wait until 39 Micro Sec   */
			_delay_ms(1);

			/*    Clear Display           */
			//LCD_voidSendCMD(0b00000001);
			LCD_voidSendCMD(0x01);
			/*  wait until  1.53 m Sec   */
			_delay_ms(2);

			/*     Entry mode I/D=1 write from left to right  S=0 Shifting OFF */
			//LCD_voidSendCMD(0b00000110);
			LCD_voidSendCMD(0x06);

	}

	else if (LCD_MODE == FOUR_BIT)
	{
		/*  wait for 30msec for VDD RISES to 4.5 volt   */
			_delay_ms(35);
			/*    function Set 4bit 2lines Display and 5*7 Char Font send on 3 times*/
/*
			DIO_voidSetPinValue(CONTROL_PORT , RS  , LOW);
			DIO_voidSetPinValue(CONTROL_PORT , RW  , LOW);
			DIO_voidSetPinValue(DATA_PORT , PIN7  , 0);
			DIO_voidSetPinValue(DATA_PORT , PIN6  , 0);
			DIO_voidSetPinValue(DATA_PORT , PIN5  , 1);
			DIO_voidSetPinValue(DATA_PORT , PIN4  , 0);

			/*          EN=1                    */

			//LCD_voidSendCMD(0x02);

			DIO_voidSetPinValue(CONTROL_PORT , EN  , HIGH);
			_delay_ms(2);
			    /*          EN=0                    */
			DIO_voidSetPinValue(CONTROL_PORT , EN  , LOW);
			_delay_ms(2);


			LCD_voidSendCMD(0x28);
			/*  wait until 39 Micro Sec   */
			_delay_ms(1);

			/*     Display ON/OFF Control D=1 Display on Cursor OFF*/
			LCD_voidSendCMD(0x0c);
			/*  wait until 39 Micro Sec   */
			_delay_ms(1);

			/*    Clear Display           */
			 LCD_voidSendCMD(0x01);
			/*  wait until  1.53 m Sec   */
			_delay_ms(2);

			/*     Entry mode I/D=1 write from left to right  S=0 Shifting OFF */
			LCD_voidSendCMD(0x06);
	}
}
void LCD_voidWriteChar(u8 Copy_u8Data)
{
	/*  RS=1  */
	DIO_voidSetPinValue(CONTROL_PORT , RS  , HIGH);
	/*  RW=0  */
	DIO_voidSetPinValue(CONTROL_PORT , RW  , LOW);

	LCD_voidLatch(Copy_u8Data);


}
void LCD_voidSendCMD(u8 Copy_u8CMD)
{
	/*  RS=0  */
	DIO_voidSetPinValue(CONTROL_PORT , RS  , LOW);
	/*  RW=0  */
	DIO_voidSetPinValue(CONTROL_PORT , RW  , LOW);

	LCD_voidLatch(Copy_u8CMD);
}

void LCD_voidWriteString(u8 *COPY_Pu8Str)
{
	while(*COPY_Pu8Str!='\0')
	{
		LCD_voidWriteChar(*COPY_Pu8Str);
		COPY_Pu8Str++;
	}
}

void LCD_voidGoToXY(u8 COPY_u8Row  , u8 COPY_u8Column)
{
    if (COPY_u8Row<2 && COPY_u8Column<16)
    {
    	switch (COPY_u8Row)
    	{
    	case 0: LCD_voidSendCMD(0x80+COPY_u8Column); break;
    	case 1: LCD_voidSendCMD(0xc0+COPY_u8Column); break;
    	}
    }

}


void LCD_voidWriteInt(u32 COPY_u8Int)
{
	u32  num=0;

	while(COPY_u8Int!=0)
		{
			num=(num*10)+(COPY_u8Int%10);
			COPY_u8Int/=10;
		}

	while (num!=0)
	{
       // num=COPY_u8Int %10;
	     switch(num%10)
	        {
	           case 0 : LCD_voidWriteChar(48); break;
	           case 1 : LCD_voidWriteChar(49); break;
	           case 2 : LCD_voidWriteChar(50); break;
	           case 3 : LCD_voidWriteChar(51); break;
	           case 4 : LCD_voidWriteChar(52); break;
	           case 5 : LCD_voidWriteChar(53); break;
	           case 6 : LCD_voidWriteChar(54); break;
	           case 7 : LCD_voidWriteChar(55); break;
	           case 8 : LCD_voidWriteChar(56); break;
	           case 9 : LCD_voidWriteChar(57); break;
	          }
	     num/=10;
     }
}


void LCD_voidLatch(u8 COPY_u8Data)
{
	if (COPY_u8Data == 0x28)
	{
		DIO_voidSetPinValue( DATA_PORT , PIN7 ,GET_BIT(COPY_u8Data ,PIN7));
		DIO_voidSetPinValue( DATA_PORT , PIN6 , (COPY_u8Data >> 6) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN5 , (COPY_u8Data >> 5) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN4 , (COPY_u8Data >> 4) & 1);
		/*          EN=1                    */
		   DIO_voidSetPinValue(CONTROL_PORT , EN  , HIGH);
			_delay_ms(2);
		   /*          EN=0                    */
		   DIO_voidSetPinValue(CONTROL_PORT , EN  , LOW);
			_delay_ms(2);

	}

	DIO_voidSetPinValue( DATA_PORT , PIN7 , (COPY_u8Data >> 7) & 1);
	DIO_voidSetPinValue( DATA_PORT , PIN6 , (COPY_u8Data >> 6) & 1);
	DIO_voidSetPinValue( DATA_PORT , PIN5 , (COPY_u8Data >> 5) & 1);
	DIO_voidSetPinValue( DATA_PORT , PIN4 , (COPY_u8Data >> 4) & 1);

	if ( LCD_MODE == EIGHT_BIT)
	{
		DIO_voidSetPinValue( DATA_PORT , PIN3 , (COPY_u8Data >> 3) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN2 , (COPY_u8Data >> 2) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN1 , (COPY_u8Data >> 1) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN0 , (COPY_u8Data >> 0) & 1);
		/*          EN=1                    */
		   DIO_voidSetPinValue(CONTROL_PORT , EN  , HIGH);
			_delay_ms(2);
		   /*          EN=0                    */
		   DIO_voidSetPinValue(CONTROL_PORT , EN  , LOW);
			_delay_ms(2);
	}
	if ( LCD_MODE == FOUR_BIT)
		{

		/*          EN=1                    */
			   DIO_voidSetPinValue(CONTROL_PORT , EN  , HIGH);
				_delay_ms(2);
			   /*          EN=0                    */
			   DIO_voidSetPinValue(CONTROL_PORT , EN  , LOW);
				_delay_ms(2);

		DIO_voidSetPinValue( DATA_PORT , PIN7 , (COPY_u8Data >> 3) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN6 , (COPY_u8Data >> 2) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN5 , (COPY_u8Data >> 1) & 1);
		DIO_voidSetPinValue( DATA_PORT , PIN4 , (COPY_u8Data >> 0) & 1);
			/*          EN=1                    */
			   DIO_voidSetPinValue(CONTROL_PORT , EN  , HIGH);
				_delay_ms(2);
			   /*          EN=0                    */
			   DIO_voidSetPinValue(CONTROL_PORT , EN  , LOW);
				_delay_ms(2);
		}

}
