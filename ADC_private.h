/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#ifndef  _ADC_PRIVATE_H
#define  _ADC_PRIVATE_H

#define     ADMUX        *((volatile u8*)0x27)
#define     ADCSRA       *((volatile u8*)0x26)
#define     ADCH         *((volatile u8*)0x25)
#define     SFIOR        *((volatile u8*)0x50)

#define     ADC          *((volatile u16*)0x24)

//ADMUX reg
#define      REFS1           7
#define      REFS0           6
#define      ADLAR           5

#define      ADIE            3
#define      ADMUX_CHANNELS_CLR   0b11100000


//ADCSRA reg
#define      ADEN           7
#define      ADSC           6
#define      ADATE          5
#define      ADIF           4
#define      ADPS2          2
#define      ADPS1          1
#define      ADPS0          0

//SFIOR
#define      ADTS2          7
#define      ADTS1          6
#define      ADTS0          5

#endif
