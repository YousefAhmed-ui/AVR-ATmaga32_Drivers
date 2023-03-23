/*
 * Timer0_App2.c
 *
 * Created: 10/03/2023 08:51:18 م
 * Author : El-Wattaneya
 */ 

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TIMER0.h"
#include "util/delay.h"


int main(void)
{
	DIO_enuInit();
	TMR0_vidInitPreCompile();
	u8 local_u8counter = 0;
    u8 local_u8val1;
	u8 local_u8val2;
    while (1) 
    {
		DIO_enuGetPin(DIO_enuPin26,&local_u8val1);
		DIO_enuGetPin(DIO_enuPin27,&local_u8val2);
		_delay_ms(100);
		if(local_u8val1 == 0)
		{
			local_u8counter+=50;
			TMR0_enuSetCompMatchValue(local_u8counter);
			if(local_u8counter > 255)
			{
				local_u8counter = 255;
			}
		}
		if(local_u8val2 == 0)
		{
			local_u8counter -=50;
			TMR0_enuSetCompMatchValue(local_u8counter);
			if(local_u8counter < 0)
			{
				local_u8counter = 0;
			}
		}

	}
	
}

