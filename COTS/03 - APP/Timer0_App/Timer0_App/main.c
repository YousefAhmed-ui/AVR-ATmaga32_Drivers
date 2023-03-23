/*
 * Timer0_App.c
 *
 * Created: 10/03/2023 05:06:51 م
 * Author : El-Wattaneya
 */ 

#define   F_CPU  8000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GlobInt_interface.h"
#include "TIMER0.h"


void Blink(void)
{
	static u16 Counter = 0;
	Counter++;
	
	if(Counter == 9540)
	{
		DIO_enuTogglePin(DIO_enuPin0);
		Counter = 0;
	}
	
}


int main(void)
{
	DIO_enuInit();
	Globint_voidEnableGlobalInt();
	TMR0_enuRegisterCallback(Blink);
	TMR0_enuSetTickTimeMS(250);
	TMR0_vidInitPreCompile();
    
    while (1) 
    {
		
    }
}

