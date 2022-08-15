/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#ifndef  _TIMER_INTERFACE_H
#define  _TIMER_NTERFACE_H


void TIMER0_Overflow_voidInit(void);
void TIMER0_voidInit_CTC_Mood(void);
void TIMER0_overflow_voidSetCallBack(void (*pf)(void));
void TIMER0_CTC_voidSetCallBack(void (*pf)(void));
void TIMER0_voidInit_FastPWM_Mood(void);
void TIMER0_voidSetDutuCycle(u8 COPY_u8Matching);


#endif
