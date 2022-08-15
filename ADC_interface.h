/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/

#ifndef  _ADC_INTERFACE_H
#define  _ADC_INTERFACE_H


void ADC_voidInit(void);

void ADC_voidGetDigitalValue(u8 COPY_u8Channel , u16  *COPY_Pu16DigitalValue);

void  ADC_SetCallBack (void(*pf) (void));

#endif
