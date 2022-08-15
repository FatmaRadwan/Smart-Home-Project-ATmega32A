/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#ifndef  _TIMER_PRIVATE_H
#define  _TIMER_PRIVATE_H

#define     TCCR0        *((volatile u8*)0x53)
#define     TCNT0        *((volatile u8*)0x52)
#define     TIMSK        *((volatile u8*)0x59)
#define     TIFR         *((volatile u8*)0x58)
#define     OCR0         *((volatile u8*)0x5C)



#define     WGM01          3
#define     WGM00          6


#define     CS00           0
#define     CS01           1
#define     CS02           2

#define    OCIE0           1

#define    COM00           4
#define    COM01           5


#define     TOIE           0

#endif
