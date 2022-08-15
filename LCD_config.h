/******************************************/
/*   Author     :FATMA MOHAMED AHMED	  */
/*  version     : V01			          */
/******************************************/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



#define       LCD_MODE         FOUR_BIT

/*    D0 : D7 on LCD is PORTD */
#define     DATA_PORT        PORTA
/*    RS=A0 & RW=A1 & E=A2 */
#define     CONTROL_PORT     PORTC

#define      RS            PIN0
#define      RW            PIN1
#define      EN            PIN2

#define      FOUR_BIT       0
#define      EIGHT_BIT      1

#endif /* LCD_CONFIG_H_ */
