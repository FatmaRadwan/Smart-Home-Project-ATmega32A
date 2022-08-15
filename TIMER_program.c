/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "TIMER_private.h"

#define    NULL    (void *) 0 

void (*TIMER0_overflow_callBack)(void) = NULL ;
void (*TIMER0_CTC_callBack)(void) = NULL ;

void TIMER0_Overflow_voidInit(void)
{
	//overflow mode
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	
	//prescaler=8
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
	//periphral enable
	SET_BIT(TIMSK,TOIE);

	//preload value = 192
	TCNT0=0xC0;

}

void TIMER0_voidInit_CTC_Mood(void)
{
	//CTC mode
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);

	//prescaler=64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	//OCR0=125
	OCR0=0x7D;

	//periphral enable
	SET_BIT(TIMSK,OCIE0);

}
void TIMER0_voidInit_FastPWM_Mood(void)
{
	//Fast PWM mode
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

	//non inverted pwm
	CLR_BIT(TCCR0,COM00);
    SET_BIT(TCCR0,COM01);

	//prescaler=64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

}

void TIMER0_voidSetDutuCycle(u8 COPY_u8Matching)
{
    OCR0 = COPY_u8Matching;
}

void TIMER0_overflow_voidSetCallBack(void (*pf)(void))
{
	TIMER0_overflow_callBack=pf;
}

void __vector_11(void)  __attribute__((signal,used));

void __vector_11 (void)
{
	TIMER0_overflow_callBack();
}


void TIMER0_CTC_voidSetCallBack(void (*pf)(void))
{
	TIMER0_CTC_callBack=pf;
}

void __vector_10(void)  __attribute__((signal,used));

void __vector_10 (void)
{
	TIMER0_CTC_callBack();
}
