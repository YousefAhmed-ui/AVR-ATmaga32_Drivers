/*
 * LCD.c
 *
 * Created: 10/02/2023 09:28:12 م
 * Author : El-Wattaneya
 */ 
#define F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

u8 Glob_u8Arr1[8] = {3, 3, 3, 3, 3, 3, 3, 3};
u8 Glob_u8Arr2[8] = {24, 24, 24, 24, 24, 24, 24, 24};
u8 Glob_u8Ball[8] = {0, 0, 4, 14, 4, 0, 0, 0};		

//u8 Local_u8Arr[8] = {3, 3, 3, 31, 31, 0, 27, 27};
//u8 Local_u8Arr2[8] = {31, 19, 19, 31, 3, 31, 31, 0};
//u8 Local_u8Arr3[8] = {0, 0, 21, 21, 31, 31, 0, 0};
//u8 Local_u8Arr4[8] = {2, 0, 7, 5, 31, 31, 0, 0};

int main(void)
{
		u8 Local_u8Buttonval = 0;
		u8 Local_Stepcounter = 15;
		u8 Local_u8SelectedLine = 0;
	    DIO_enuInit();
	    LCD_Init();
        LCD_DisplaySpecialCahar(Glob_u8Arr1 , 0 , Local_u8SelectedLine , 15);
        LCD_DisplaySpecialCahar(Glob_u8Arr2 , 1 , Local_u8SelectedLine , 0);
        LCD_DisplaySpecialCahar(Glob_u8Ball , 2 , Local_u8SelectedLine , 14);
	
	while(1)
	{
		
	}

	//u8 Local_u8Buttonval = 0;
	//u8 Local_Stepcounter = 10;
	//u8 Local_u8SelectedLine = 0;
    //DIO_enuInit();
	//LCD_Init();
	////LCD_WriteData('A');
	//
	//		
	////LCD_WriteString("Here We are");
	////_delay_ms(20);
	//LCD_DisplaySpecialCahar( Local_u8Arr , 0 , Local_u8SelectedLine , Local_Stepcounter );
	//LCD_DisplaySpecialCahar( Local_u8Arr2 , 1 , Local_u8SelectedLine , Local_Stepcounter-1 );
	//LCD_DisplaySpecialCahar(Local_u8Arr3, 2 , Local_u8SelectedLine , Local_Stepcounter-2);
	//LCD_DisplaySpecialCahar(Local_u8Arr4 , 3 , Local_u8SelectedLine , Local_Stepcounter-3);
	////LCD_WriteNum(150);
    //while (1) 
    //{
	//	_delay_ms(50);
	//	DIO_enuGetPin(DIO_enuPin0 , &Local_u8Buttonval);
	//	if(Local_u8Buttonval == 0)
	//	{
	//		LCD_WriteCommand(LCD_CLEAR_DISP);
	//		LCD_DisplaySpecialCahar(Local_u8Arr , 0 , Local_u8SelectedLine , Local_Stepcounter );
	//		LCD_DisplaySpecialCahar(Local_u8Arr2, 1 , Local_u8SelectedLine , Local_Stepcounter-1 );
	//		LCD_DisplaySpecialCahar(Local_u8Arr3, 2 , Local_u8SelectedLine , Local_Stepcounter-2);
	//		LCD_DisplaySpecialCahar(Local_u8Arr4 , 3 , Local_u8SelectedLine , Local_Stepcounter-3);
	//		Local_Stepcounter--;
	//		if(Local_Stepcounter < 3)
	//		{
	//			Local_Stepcounter = 3;
	//		}
	//		
	//		
	//		
	//	}
	//	DIO_enuGetPin(DIO_enuPin1 , &Local_u8Buttonval);
	//	if(Local_u8Buttonval == 0)
	//	{
	//		LCD_WriteCommand(LCD_CLEAR_DISP);
	//		LCD_DisplaySpecialCahar(Local_u8Arr , 0 , Local_u8SelectedLine ,Local_Stepcounter );
	//		LCD_DisplaySpecialCahar(Local_u8Arr2 , 1 , Local_u8SelectedLine ,Local_Stepcounter-1 );
	//		LCD_DisplaySpecialCahar(Local_u8Arr3 , 2 , Local_u8SelectedLine ,Local_Stepcounter-2);
	//		LCD_DisplaySpecialCahar(Local_u8Arr4 , 3 , Local_u8SelectedLine ,Local_Stepcounter-3);
	//		Local_Stepcounter++;
	//		if(Local_Stepcounter  >= 15)
	//		{
	//			Local_Stepcounter = 15;
	//		}
	//		
	//		
	//					
	//	}
	//	DIO_enuGetPin(DIO_enuPin2 , &Local_u8Buttonval);
	//	if(Local_u8Buttonval == 0)
	//	{
	//		LCD_WriteCommand(LCD_CLEAR_DISP);
	//		LCD_DisplaySpecialCahar( Local_u8Arr , 0 , XPOS_FIRST_ROW ,  Local_Stepcounter );
	//		LCD_DisplaySpecialCahar( Local_u8Arr2 , 1 , XPOS_FIRST_ROW ,  Local_Stepcounter-1 );
	//		LCD_DisplaySpecialCahar(Local_u8Arr3, 2 , XPOS_FIRST_ROW ,  Local_Stepcounter-2);
	//		LCD_DisplaySpecialCahar(Local_u8Arr4 , 3 , XPOS_FIRST_ROW ,  Local_Stepcounter-3);
	//		Local_u8SelectedLine = XPOS_FIRST_ROW;
	//		
	//		
	//	}
	//	DIO_enuGetPin(DIO_enuPin3 , &Local_u8Buttonval);
	//	if(Local_u8Buttonval == 0)
	//	{
	//		LCD_WriteCommand(LCD_CLEAR_DISP);
	//		LCD_DisplaySpecialCahar( Local_u8Arr , 0 , XPOS_SECOND_ROW ,  Local_Stepcounter  );
	//		LCD_DisplaySpecialCahar( Local_u8Arr2 , 1 , XPOS_SECOND_ROW ,  Local_Stepcounter-1);
	//		LCD_DisplaySpecialCahar(Local_u8Arr3, 2 , XPOS_SECOND_ROW ,  Local_Stepcounter-2);
	//		LCD_DisplaySpecialCahar(Local_u8Arr4 , 3 , XPOS_SECOND_ROW ,  Local_Stepcounter-3);
	//		Local_u8SelectedLine = XPOS_SECOND_ROW;
	//	
	//		
	//	}				
		
		
	//}
}

