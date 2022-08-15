/*
 * main.c
 *
 *   Author   :    FATMA MOHAMED AHMED 			    */
 */

#include <avr/io.h>			/* Include AVR std. library file */
#include    "STD_TYPES.h"
#include    "Bit_Math.h"
#include    "DIO_interface.h"
#include    "LCD_interface.h"
#include    "LCD_config.h"
#include    "KYEPAD_interface.h"
#include    "ADC_interface.h"
#include    "GIE_interface.h"
#include    "ADC_private.h"
#include    "TIMER_interface.h"
#include    "TIMER_private.h"
#include 	"UART_interface.h"
#include    <util/delay.h>


u8 	 LOC_u8Value =100;					//variable to store ESP's Value

u16  Global_u16Temp;                    //variable to store temperature

u16  Global_u16ADCDigitalValue = 0;     //variable to store digital value

u16  Global_u16ADCAnalogValue = 0;      //variable to store analog value

/****************************************************************/
/* Description    :  This function used to start conversion     */
/*                    every second.	                            */
/*					 return : void		 						*/
/****************************************************************/
void Timer0_voidCount (void)
{
	static u32 counter =0;
	counter++;
	if (counter == 3907)
	{
		ADC_voidGetDigitalValue(0,&Global_u16ADCDigitalValue);

		counter=0;
		TCNT0=192;
	}
}


/****************************************************************/
/* Description    :  This function used to check temperature    */
/*                    after conversion.                         */
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidWarning (void)
{

	static u8 LOCAL_u8flag=0;   //to control warning message between temperature >40  || temperature <40

	Global_u16ADCAnalogValue = ((Global_u16ADCDigitalValue * 5000UL)/1024);
	Global_u16Temp = Global_u16ADCAnalogValue/10 ;

	if (Global_u16Temp >=40)
	{
		LCD_voidSendCMD(0x01);
		LCD_voidWriteString("WARNING");
		LCD_voidGoToXY(1,0);
		LCD_voidWriteString("TEMPERATURE =");
		LCD_voidWriteInt(Global_u16Temp);
		DIO_voidSetPinValue(PORTC,PIN3,HIGH);//buzzer on
		DIO_voidTogglePine(PORTD,PIN3); //led
		LOCAL_u8flag=1;

	}

	else
	{
		if (LOCAL_u8flag==1)
		{
			LCD_voidSendCMD(0x01);
			DIO_voidSetPinValue(PORTC,PIN3,LOW);
			DIO_voidSetPinValue(PORTD,PIN3,LOW);
			LOCAL_u8flag=0;
		}

	}
		LOC_u8Value =UART_VoidRead();
		if((LOC_u8Value ==5) ||(LOC_u8Value =='5') )
		{
			DIO_voidSetPinValue(PORTC,PIN4,HIGH);	//Room1 on


		}
		if((LOC_u8Value =='4') ||(LOC_u8Value ==4) )
		{
			DIO_voidSetPinValue(PORTC,PIN4,LOW);	//Room1 off

		}

		if((LOC_u8Value ==7) ||(LOC_u8Value =='7') )
		{
			DIO_voidSetPinValue(PORTC,PIN5,HIGH);	//Room2 on


		}
		if((LOC_u8Value =='6') ||(LOC_u8Value ==6) )
		{
			DIO_voidSetPinValue(PORTC,PIN5,LOW);	//Room2 off

		}
		//lock door
		if((LOC_u8Value ==3) ||(LOC_u8Value =='3') )
				{
					DIO_voidSetPinValue(PORTD,PIN2,HIGH);	//door on
		        	DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);


		        	TCNT1 = 0;
		        	ICR1 = 2499;


		        	TCCR1A = (1<<WGM11)|(1<<COM1A1);
		        	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
		        	OCR1A = 65;
				}
				if((LOC_u8Value =='2') ||(LOC_u8Value ==2) )
				{
					DIO_voidSetPinValue(PORTD,PIN2,LOW);	//door off
					OCR1A=330;

				}



}

int main (void)
{
	DIO_voidSetPinDirection(PORTD ,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTD ,PIN0,INPUT);
	UART_VoidInit();


	DIO_voidSetPortDirection(PORTA,0xf0);             // A4 : A7 Data Port from processor to LCD

	DIO_voidSetPinDirection(PORTD,PIN2,OUTPUT);       //led -->Door
	DIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);       //led -->temperature
	DIO_voidSetPinDirection(PORTC,PIN3 ,OUTPUT);     //buzzer
	DIO_voidSetPinDirection(PORTC,PIN4,OUTPUT);       //led -->Room1
	DIO_voidSetPinDirection(PORTC,PIN5,OUTPUT);       //led -->Room2

	DIO_voidSetPinDirection(CONTROL_PORT,RS,OUTPUT);  //PIN C0
	DIO_voidSetPinDirection(CONTROL_PORT,RW,OUTPUT);  //PIN C1
	DIO_voidSetPinDirection(CONTROL_PORT,EN,OUTPUT);  //PIN C2

	DIO_voidSetPortDirection(KYEPAD_PORT , 0x0f);     //keypad Port B
	DIO_voidSetPortValue(KYEPAD_PORT,0xff);           //pull up



	TIMER0_overflow_voidSetCallBack(Timer0_voidCount);  //set Timer ISR
	LCD_voidInit();                                     //initialize LCD
	ADC_voidInit_interrupt();                            //initialize ADC
	ADC_SetCallBack (ADC_voidWarning);                  //set ADC ISR
	GIE_voidInit();                                     // initialize Global interrupt enable
	TIMER0_Overflow_voidInit();


	/******************************************* PROGRAM ************************************************/

	reset:
	LCD_voidSendCMD(0x01);
	LCD_voidWriteString("ENTER YOUR PASS: ");             //welcome message
	LCD_voidSendCMD(0xc0);

	u8 LOCAL_u8Count=0;            //  index number of password
	u8 LOCAL_u8Input=0xff;
	u8 LOCAL_u8PassWord[5];        //array to store input password

	u8 LOCAL_u8Wrong = 0;         // counter for wrong password



	while(1)
	{


		check:
		while (LOCAL_u8Count<5)
		{
			LOCAL_u8Input = KEYPAD_u8GetPressedKey();

			if (LOCAL_u8Input != 0xff)
			{

				LCD_voidWriteChar(LOCAL_u8Input);
				LOCAL_u8PassWord[LOCAL_u8Count]=LOCAL_u8Input;
				LOCAL_u8Count++;
				_delay_ms(1000);

			}

		}


		if (LOCAL_u8PassWord[0] == '1' && LOCAL_u8PassWord[1] == '2' && LOCAL_u8PassWord[2] == '3' && LOCAL_u8PassWord[3] == '7' && LOCAL_u8PassWord[4] == '9'  )
		{


			DIO_voidSetPinValue(PORTD,PIN2,HIGH);
			LCD_voidSendCMD(0x01);
			LCD_voidWriteString("welcome -_-");
			LCD_voidSendCMD(0xc0);
			LCD_voidWriteString("A Door Opened .");
			_delay_ms(500);
			LOCAL_u8Count=0;
/**********************************************************/


        	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
        	DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);

        	TCNT1 = 0;
        	ICR1 = 2499;


TCCR1A = (1<<WGM11)|(1<<COM1A1);
TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
OCR1A = 65;
_delay_ms(5000);
while(OCR1A<=330)
{
	if(((PINA>>1)&1)==0)
	{
		 OCR1A=65;
		_delay_ms(500);
 }
	OCR1A += 25;
	_delay_ms(500);

}

/**********************************************************/
DIO_voidSetPinValue(PORTD,PIN2,LOW);
	goto reset;
		}


		else if (LOCAL_u8Wrong<2)
		{
			LOCAL_u8Wrong++;
			LCD_voidSendCMD(0x01);
			LCD_voidWriteString("wrong pass");
			LCD_voidSendCMD(0xc0);
			LCD_voidWriteString("try again:");
			LOCAL_u8Count=0;
			goto check;


		}

		else
		{
			LCD_voidSendCMD(0x01);
			LCD_voidWriteString("not allowed");
			for(u8 x =0 ;x<12 ;x++)
			{
			_delay_ms(5000);
			}
			goto reset;
		}


	}

	return 0;

}
