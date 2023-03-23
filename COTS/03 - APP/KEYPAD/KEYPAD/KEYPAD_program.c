/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 27/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"


void KEYPAD_voidInit(void)
{
	DIO_enuSetPin(KEYPAD_COLUMN1,DIO_enuHigh);
	DIO_enuSetPin(KEYPAD_COLUMN2,DIO_enuHigh);
	DIO_enuSetPin(KEYPAD_COLUMN3,DIO_enuHigh);
	
}


KEYPAD_enuErrorStatus KEYPAD_GetKey(u8 * Add_pKeyPressed)
{
	KEYPAD_enuErrorStatus Local_u8ErrorStatus = KEYPAD_enuOk;
	u8 * Local_u8KeyPressed = Add_pKeyPressed;
	static u8 Local_u8KEYPAD_ARR[ROWS_SIZE][COLUMN_SIZE] = KEYPAD_ARR;
	u8 Local_u8ColumnIndex,Local_u8RowIndix;
	static u8 Local_u8ColumnArr[COLUMN_SIZE] = {KEYPAD_COLUMN1,KEYPAD_COLUMN2,KEYPAD_COLUMN3};
	static u8 Local_u8RowArr[ROWS_SIZE] = {KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3};
	u8 Local_u8PinValue;
	if( Add_pKeyPressed == NULL )
	{
		Local_u8ErrorStatus = KEYPAD_enuNullPtr;
	}
	else
	{
		for( Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < COLUMN_SIZE ; Local_u8ColumnIndex++ )
		{
			DIO_enuSetPin(Local_u8ColumnArr[Local_u8ColumnIndex],DIO_enuLow);
			for( Local_u8RowIndix = 0 ; Local_u8RowIndix < ROWS_SIZE ; Local_u8RowIndix++ )
			{
				DIO_enuGetPin( Local_u8RowArr[Local_u8RowIndix] , &Local_u8PinValue);
				if(DIO_enuLow == Local_u8PinValue)
				{
					*Local_u8KeyPressed = Local_u8KEYPAD_ARR[Local_u8RowIndix][Local_u8ColumnIndex];
					while(DIO_enuLow == Local_u8PinValue)
					{
						DIO_enuGetPin( Local_u8RowArr[Local_u8RowIndix] , &Local_u8PinValue);
					}
					
					return Local_u8ErrorStatus;
					
				}
			}
			DIO_enuSetPin(Local_u8ColumnArr[Local_u8ColumnIndex],DIO_enuHigh);
			
		}
	}
}