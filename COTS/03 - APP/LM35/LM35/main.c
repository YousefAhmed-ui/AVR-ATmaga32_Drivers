/*
 * LM35.c
 *
 * Created: 09/02/2023 12:16:08 ص
 * Author : El-Wattaneya
 */ 
#define F_CPU  8000000UL
#include <util/delay.h>
#include "ADC.h"
#include "DIO_interface.h"
#include "Sev_Seg_interface.h"

int main(void)
{
	DIO_enuInit();
	adc_SelectRef(adc_AVCC_MASK);
	adc_SelectAdjustment(adc_ADLAR_LEFT_ADJUST);
	adc_SelectChannelSingle(adc_ADMUX_ADC4);
	//adc_SetAutoTrigger(adc_ENABLE_TRIGGER_MASK);
	//adc_SelectAutoTriggerSource(adc_TRIGGER_SOURCE_FREE_RUNNING);
	adc_Enable(adc_ENABLE_MASK);

	adc_SelectPrescalar(adc_PRESCALAR_DIVIDED_BY128);
    u16 Local_u16var = 0;
	//u16 Local_u16MilliVolts;
	//u8 Local_u8Temp;
		
    while (1) 
    {
		adc_StartConversion_8Bit(&Local_u16var);
		//DIO_enuSetPort(DIO_PORTC,Local_u16var);
		//_delay_ms(1000);
		//Local_u16MilliVolts = (u16)(((u32)Local_u8var * 5000UL)/256UL);
		//Local_u8Temp = Local_u16MilliVolts/10;
		//Sev_Seg_enuDisplay_Num(Sev_Seg_PORTB,Local_u8Temp%10);
	    //Sev_Seg_enuDisplay_Num(Sev_Seg_PORTA,Local_u8Temp/10);
		if(Local_u16var > 50 && Local_u16var < 75)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);						
		}
		else if(Local_u16var > 75 && Local_u16var < 100)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);
			
		}
		else if(Local_u16var > 100 && Local_u16var < 125)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);
			
		}
		else if(Local_u16var > 125 && Local_u16var < 150)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);
			
		}
		else if(Local_u16var > 150 && Local_u16var < 175)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);
			
		}
		else if(Local_u16var > 175 && Local_u16var < 200)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuLow);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);
			
		}
		else if(Local_u16var > 200 && Local_u16var < 225)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuLow);
			
		}
		else if(Local_u16var > 225 && Local_u16var < 250)
		{
			DIO_enuSetPin(DIO_enuPin16,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin17,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin18,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin19,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin20,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin21,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin22,DIO_enuHigh);
			DIO_enuSetPin(DIO_enuPin23,DIO_enuHigh);
			
		}								
				
	
		

		

		
		
		
    }
}

