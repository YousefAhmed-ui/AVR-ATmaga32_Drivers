/*
 * Interrupt_PushButton.c
 *
 * Created: 27/01/2023 07:14:00 ص
 * Author : El-Wattaneya
 */ 

#define F_CPU  8000000UL
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_inteface.h"
#include "Switch.h"
#include "GlobInt_interface.h"
#include "EXTI_interface.h"




int main(void)
{
	u8 Local_u8PinValue = 0;
    DIO_enuInit();
	EXTI_enuInitInterrupt();
	EXTI_enuEnableInterrupt(1);
	Globint_voidEnableGlobalInt();
    while (1) 
    {
		//Switch_enuGetValue(DIO_enuPin27,&Local_u8PinValue);
		//_delay_ms(100);
		//if(Local_u8PinValue)
		//{
		//	DIO_enuSetPin( DIO_enuPin28 , DIO_enuHigh );
		//	
		//}
		
    }
	return 0;
}

void __vector_2(void) __attribute__((interrupt));
void __vector_2(void) {
	LED_enuOn( DIO_enuPin28);
}

