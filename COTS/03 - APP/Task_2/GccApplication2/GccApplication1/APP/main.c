/*
 * GccApplication1.c
 *
 * Created: 10/01/2023 07:02:06 م
 * Author : El-Wattaneya
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "Switch.h"
#define F_CPU  8000000UL


//#define Delay_Amount  3001*(F_CPU/1000000)




void delay_ms_iti(unsigned long int Copy_Count)
{
	unsigned long int i;
	Copy_Count = (u32)((f32)Copy_Count*((f32)F_CPU/1000000.0)*91.2);
	for ( i = 0 ; i < Copy_Count ; i++ )
	{

		asm("NOP");
	}
	
}




int main(void)
{
	DIO_enuInit();
	u8 Local_u8PushButton1 = 0;
	u8 Local_u8PushButton2 = 0;
	u8 i = 0;
	//u8 Local_u8pinvalue = 0;

    //DIO_enuSetPin(DIO_enuPin18 , DIO_enuHigh);
	//DIO_enuSetPin(DIO_enuPin19 , DIO_enuHigh);
	//DIO_enuSetPin(DIO_enuPin20 , DIO_enuHigh);
	//DIO_enuSetPin(DIO_enuPin21 , DIO_enuHigh);

    while (1) 
    {

		while(i < 4)
		{
			Switch_enuGetValue(DIO_enuPin26,&Local_u8PushButton1);
			Switch_enuGetValue(DIO_enuPin27,&Local_u8PushButton2);
			delay_ms_iti(150);
			if(Local_u8PushButton1)
			{
				
				LED_enuOn(DIO_enuPin28+i);
				i++;
				if ( i > 3)
				{
					i = 3;
				}
				break;
				
			}
			if(Local_u8PushButton2)
			{
				LED_enuOff(DIO_enuPin28+i);
				i--;
				if ( i < 1)
				{
					i = 1;
				}
				break;
		
			}
		
		}
	
		
		/*Task 1 Led Animation*/
		//LED_enuOn(DIO_enuPin28);
		//delay_ms_iti(500);
		//LED_enuToggle(DIO_enuPin28);
		//delay_ms_iti(500);
		//LED_enuOn(DIO_enuPin29);
		//delay_ms_iti(500);
		//LED_enuToggle(DIO_enuPin29);
		//delay_ms_iti(500);
		//LED_enuOn(DIO_enuPin30);
		//delay_ms_iti(500);
		//LED_enuToggle(DIO_enuPin30);
		//delay_ms_iti(500);
		//LED_enuOn(DIO_enuPin31);
		//delay_ms_iti(500);
		//LED_enuToggle(DIO_enuPin31);
		//delay_ms_iti(500);
		//LED_enuOn(DIO_enuPin30);
		//delay_ms_iti(500);
		//LED_enuToggle(DIO_enuPin30);
		//delay_ms_iti(500);
		//LED_enuOn(DIO_enuPin29);
		//delay_ms_iti(500);
		//LED_enuToggle(DIO_enuPin29);
		//delay_ms_iti(500);
		
		
		
		//LED_enuOn(DIO_enuPin28);
		//delay_ms_iti(1000);
		//LED_enuToggle(DIO_enuPin28);
		//delay_ms_iti(1000);								
		//DIO_enuSetPin(DIO_enuPin9 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin10 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin11 , DIO_enuLow);
		//delay_ms_iti(500);
		//DIO_enuSetPin(DIO_enuPin8 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin9 , DIO_enuHigh);
		//DIO_enuSetPin(DIO_enuPin10 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin11 , DIO_enuLow);
		//delay_ms_iti(2000);
		//DIO_enuSetPin(DIO_enuPin8 , DIO_enuHigh);
		//DIO_enuSetPin(DIO_enuPin9 , DIO_enuHigh);
		//DIO_enuSetPin(DIO_enuPin10 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin11 , DIO_enuLow);
		//delay_ms_iti(2000);
		//DIO_enuSetPin(DIO_enuPin8 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin9 , DIO_enuLow);
		//DIO_enuSetPin(DIO_enuPin10 , DIO_enuHigh);
		//DIO_enuSetPin(DIO_enuPin11 , DIO_enuLow);
		//delay_ms_iti(2000);
	//DIO_enuGetPin(DIO_enuPin26,&Local_u8pinvalue);
	//if(Local_u8pinvalue)
	//{
	//delay_ms_iti(100);				 

	
	//delay_ms_iti(1000);
	//}
		
		
    }
	return 0;
}

