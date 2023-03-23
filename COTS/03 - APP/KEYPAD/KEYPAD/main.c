/*
 * KEYPAD.c
 *
 * Created: 01/02/2023 06:53:36 م
 * Author : El-Wattaneya
 */ 
#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Sev_Seg_interface.h"
#include "KEYPAD_interface.h"




int main(void)
{
	DIO_enuInit();
	KEYPAD_voidInit();
    u8 Local_u8Key = 0xff;
    while (1) 
    {
		
		do 
		{
		   KEYPAD_GetKey(&Local_u8Key);
		} while (Local_u8Key == 0xff );
		Sev_Seg_enuDisplay_Num(Sev_Seg_PORTB , Local_u8Key);
			
		
		
		
			
    }
}

