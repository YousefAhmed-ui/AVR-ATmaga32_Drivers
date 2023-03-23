/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 10/2/2023                                                                                                     */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#ifndef LCD_INTEFACE_H
#define LCD_INTEFACE_H


#define LCD_CLEAR_DISP            0b00000001

#define XPOS_FIRST_ROW        0
#define XPOS_SECOND_ROW       1


typedef enum
{

	LCD_PORTA = 0,
	LCD_PORTB,
	LCD_PORTC,
	LCD_PORTD

}LCD_typePORT;


typedef enum
{

	LCD_enuPin0 = 0,
	LCD_enuPin1    ,
	LCD_enuPin2    ,
	LCD_enuPin3    ,
	LCD_enuPin4    ,
	LCD_enuPin5    ,
	LCD_enuPin6    ,
	LCD_enuPin7    ,
	LCD_enuPin8    ,
	LCD_enuPin9    ,
	LCD_enuPin10   ,
	LCD_enuPin11   ,
	LCD_enuPin12   ,
	LCD_enuPin13   ,
	LCD_enuPin14   ,
	LCD_enuPin15   ,
	LCD_enuPin16   ,
	LCD_enuPin17   ,
	LCD_enuPin18   ,
	LCD_enuPin19   ,
	LCD_enuPin20   ,
	LCD_enuPin21   ,
	LCD_enuPin22   ,
	LCD_enuPin23   ,
	LCD_enuPin24   ,
	LCD_enuPin25   ,
	LCD_enuPin26   ,
	LCD_enuPin27   ,
	LCD_enuPin28   ,
	LCD_enuPin29   ,
	LCD_enuPin30   ,
	LCD_enuPin31   ,
	LCD_enuNumberOfPins
}LCD_tenuPins;

typedef enum
{
	LCD_enuLow = 0,
	LCD_enuHigh
}LCD_tPinValue;





typedef enum{
	LCD_enuOk,
	LCD_enuNotOk
}LCD_enuErrorStatus_t;

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
LCD_enuErrorStatus_t LCD_WriteData(u8 Copy_u8Data);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
LCD_enuErrorStatus_t LCD_WriteCommand(u8 Copy_u8Command);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
void LCD_Init();
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
LCD_enuErrorStatus_t LCD_GotoXY(u8 Copy_u8XPos , u8 Copy_u8YPos);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
LCD_enuErrorStatus_t LCD_DisplaySpecialCahar(u8 * Add_Pattern , u8 Copy_u8Block , u8 Copy_u8XPos , u8 Copy_u8YPos );
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
LCD_enuErrorStatus_t LCD_WriteString(char * Add_String);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
void LCD_WriteNum(u8 Copy_u8Num);


#endif