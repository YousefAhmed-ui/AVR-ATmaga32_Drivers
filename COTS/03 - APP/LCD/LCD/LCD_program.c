/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 10/2/2023                                                                                                     */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_Config.h"


#define FUNC_SET_COMMAND          0b00111000
#define LCD_DISP_ON               0b00001100
#define LCD_CLEAR_DISP            0b00000001
#define CGRAM_BLOCK_NUM           8
#define MAX_Y_POS                 16

LCD_enuErrorStatus_t LCD_WriteData(u8 Copy_u8Data)
{
	LCD_enuErrorStatus_t Local_enuErrorStatus = LCD_enuOk;
	if( Copy_u8Data > 255 )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else
	{
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin16,LCD_enuHigh);
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin17,LCD_enuLow);
		Local_enuErrorStatus = DIO_enuSetPort(LCD_DATA_PORT,Copy_u8Data);
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin18 , LCD_enuHigh);
		_delay_ms(2);
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin18 , LCD_enuLow);

	}
	return Local_enuErrorStatus;
	

}
LCD_enuErrorStatus_t LCD_WriteCommand(u8 Copy_u8Command)
{
	LCD_enuErrorStatus_t Local_enuErrorStatus = LCD_enuOk;
	if( Copy_u8Command > 255 )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else
	{
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin16,LCD_enuLow);
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin17,LCD_enuLow);
		Local_enuErrorStatus = DIO_enuSetPort(LCD_DATA_PORT,Copy_u8Command);
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin18 , LCD_enuHigh);
		_delay_ms(2);
		Local_enuErrorStatus = DIO_enuSetPin(LCD_enuPin18 , LCD_enuLow);
	}
	return Local_enuErrorStatus;

}
void LCD_Init()
{
	_delay_ms(40);
	/* Function set command */
	LCD_WriteCommand(FUNC_SET_COMMAND);
	/*Display powered on*/
	LCD_WriteCommand(LCD_DISP_ON);
	/* Clear Display*/
	LCD_WriteCommand(LCD_CLEAR_DISP);

}
LCD_enuErrorStatus_t LCD_GotoXY(u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	LCD_enuErrorStatus_t Local_enuErrorStatus = LCD_enuOk;
	u8 Local_u8Location = 0;
	if( (Copy_u8XPos != XPOS_FIRST_ROW) && (Copy_u8XPos != XPOS_SECOND_ROW) )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else if( Copy_u8YPos > MAX_Y_POS )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else
	{
		if( Copy_u8XPos == XPOS_FIRST_ROW )
		{
			Local_u8Location = Copy_u8YPos;
		}
		else if( Copy_u8XPos == XPOS_SECOND_ROW )
		{
			Local_u8Location = Copy_u8YPos + 0x40;
		}
		else{}
		LCD_WriteCommand(Local_u8Location+128);
	}
	return Local_enuErrorStatus;


}
LCD_enuErrorStatus_t LCD_DisplaySpecialCahar(u8 * Add_Pattern , u8 Copy_u8Block , u8 Copy_u8XPos , u8 Copy_u8YPos )
{
	LCD_enuErrorStatus_t Local_enuErrorStatus = LCD_enuOk;
	u8 Local_u8CGRamAddress = 0;
	u8 Local_u8Iterator = 0;
	if( Add_Pattern == NULL )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else if( Copy_u8Block > CGRAM_BLOCK_NUM )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else if( (Copy_u8XPos != XPOS_FIRST_ROW) && (Copy_u8XPos != XPOS_SECOND_ROW) )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else if( Copy_u8YPos > MAX_Y_POS )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else
	{
		Local_u8CGRamAddress = Copy_u8Block * CGRAM_BLOCK_NUM;

		LCD_WriteCommand( Local_u8CGRamAddress + 64 );

		for(Local_u8Iterator = 0 ; Local_u8Iterator < CGRAM_BLOCK_NUM ; Local_u8Iterator++ )
		{
			LCD_WriteData(Add_Pattern[Local_u8Iterator]);
		}
		LCD_GotoXY( Copy_u8XPos , Copy_u8YPos );

		LCD_WriteData(Copy_u8Block);
	}
	return Local_enuErrorStatus;
	


}
LCD_enuErrorStatus_t LCD_WriteString(char * Add_String)
{
	LCD_enuErrorStatus_t Local_enuErrorStatus = LCD_enuOk;
	u8 Local_u8Iterator = 0;
	if( Add_String == NULL )
	{
		Local_enuErrorStatus = LCD_enuNotOk;
	}
	else
	{
		while(Add_String[Local_u8Iterator] != '\0')
		{
			LCD_WriteData(Add_String[Local_u8Iterator]);
			Local_u8Iterator++;
		}
	}

}
void LCD_WriteNum(u8 Copy_u8Num)
{

	u8 Local_u8Arr[16] = {0};
	u8 Local_u8Value = 0;
	u8 Local_u8Iterator1 = 0;
	u8 Local_u8Iterator2 = 0;
	while( Copy_u8Num != 0 )
	{
		Local_u8Arr[Local_u8Iterator1] = Copy_u8Num % 10;
		Copy_u8Num /= 10;
		Local_u8Iterator1++;

	}
	for( Local_u8Iterator2 = Local_u8Iterator1 ; Local_u8Iterator2 > 0 ; Local_u8Iterator2++ )
	{
		LCD_WriteData(Local_u8Arr[Local_u8Iterator2]);
	}

}


