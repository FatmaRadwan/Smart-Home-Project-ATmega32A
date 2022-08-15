/****************************************************************/
/*   Author             :    FATMA MOHAMED AHMED 			    */
/*	 Date 				:    8 SEPTEMBER 2020					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   									*/
/*									 [interface.c]			    */
/****************************************************************/

/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/****************************************************************/
/* Description    :  This function used to initiate LCD     	*/
/*					 Inputs : void                              */
/*					 return : void		 						*/
/****************************************************************/
void	LCD_voidInit(void);
/****************************************************************/
/* Description    :  This function used to write a charachter   */
/*                           on LCD    	                        */
/*					 Inputs : Copy_u8Data               		*/
/*					 return : void		 						*/
/****************************************************************/
void	LCD_voidWriteChar(u8 Copy_u8Data);	
/****************************************************************/
/* Description    :  This function used to send a command     	*/
/*					    to LCD                                  */
/*                   Inputs : Copy_u8CMD                		*/
/*					 return : void		 						*/
/****************************************************************/
void	LCD_voidSendCMD(u8 Copy_u8CMD);

void LCD_voidWriteInt(u32 COPY_u8Int);
void LCD_voidWriteString(u8 *COPY_Pu8Str);
void LCD_voidLatch(u8 COPY_u8Data);




#endif
