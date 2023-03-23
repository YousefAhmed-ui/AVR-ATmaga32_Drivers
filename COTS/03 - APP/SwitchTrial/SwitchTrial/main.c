/*
 * SwitchTrial.c
 *
 * Created: 15/03/2023 03:35:50 م
 * Author : El-Wattaneya
 */ 

#define F_CPU   8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "GlobInt_interface.h"
#include "TIMER0.h"
#include "util/delay.h"

u8 Global_u8Val;



void Switch(void)
{
	
	DIO_enuSetPin(DIO_enuPin1 , DIO_enuHigh);
	static u8 counter = 0;
	static u8 val = 1;
	static u8 flag = 0;
	counter++;
	if(counter % 200 == 0)
	{
		Switch_enuGetValue(DIO_enuPin26,&val);
		if(val == 0)
		{
			flag++;
			if(flag == 5)
			{
				 Global_u8Val = 1;
				 
				 flag = 0;
				
			}
			
		}
	}
	
}



int main(void)
{
	DIO_enuInit();
	Globint_voidEnableGlobalInt();
	TMR0_enuRegisterCallback(Switch);
	TMR0_enuSetCompMatchValue((u8)100);
	TMR0_vidInitPreCompile();
	
	
	
    
    while (1) 
    {
		if(Global_u8Val == 1)
		{
			DIO_enuSetPin(DIO_enuPin1 , DIO_enuHigh);
			Global_u8Val = 0;
			//_delay_ms(100);
			
		}
			
    }
}

