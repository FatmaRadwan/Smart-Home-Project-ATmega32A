/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#include    "STD_TYPES.h"
#include    "Bit_Math.h"
#include    "ADC_private.h"

#define  NULL   (void*) 0
void (*ADC_callBack)(void) = NULL ;
static u16 *ADC_ptr = NULL ;



void ADC_voidInit_interrupt(void)
{
	//select Vref = Vcc
    SET_BIT(ADMUX,REFS0);
    CLR_BIT(ADMUX,REFS1);

	//Right adjust
    CLR_BIT(ADMUX,ADLAR);

	//Trigger enable
	//SET_BIT(ADCSRA,ADATE);

    //select prescaler =64
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	//ADC peripheral enable
    SET_BIT(ADCSRA,ADEN);

    //ADC interrupt enable
    SET_BIT(ADCSRA,ADIE);

    //free running mood
  //  CLR_BIT(SFIOR,ADTS0);
   // CLR_BIT(SFIOR,ADTS1);
   // CLR_BIT(SFIOR,ADTS2);

    // start conversion
   //  SET_BIT(ADCSRA,ADSC);

}
void ADC_voidGetDigitalValue(u8 COPY_u8Channel , u16  *COPY_Pu16DigitalValue)
{
	
	if (COPY_u8Channel >= 0  &&  COPY_u8Channel <=7)
	{
	   ADMUX &= ADMUX_CHANNELS_CLR ;
	   ADMUX |= COPY_u8Channel   ;
	   
	   ADC_ptr=COPY_Pu16DigitalValue;
	   // start conversion
       SET_BIT(ADCSRA,ADSC);
	
	  //waite 
	 // while ((GET_BIT(ADCSRA,ADIF)) == 0);
		//SET_BIT(ADCSRA,ADIF);
	
	   
	}

   // return ADC;
	
}



void  ADC_SetCallBack (void(*pf) (void))
{
	ADC_callBack=pf;
}
void  __vector_16 (void) __attribute__((signal,used));

void  __vector_16 (void)
{
	*ADC_ptr = ADC;
	ADC_callBack();
}
