/*
 * Timer1_App1.c
 *
 * Created: 11/03/2023 06:47:04 م
 * Author : El-Wattaneya
 */ 

#define F_CPU 8000000UL
#include "TIMER1.h"
#include "DIO_interface.h"
#include "util/delay.h"
#include "ADC.h"

s32 map(s32 Copy_s32Inputmin , s32 Copy_s32Inputmax , s32 Copy_s32OutPutmin , s32 Copy_s32OutPutmax , s32 Copy_s32Inputval)
{
	s32 Local_s32Inputval  = (Copy_s32OutPutmin + Copy_s32Inputval);
	 Local_s32Inputval *= (Copy_s32OutPutmax - Copy_s32OutPutmin);
	 Local_s32Inputval /= (Copy_s32Inputmax -Copy_s32Inputmin);
	
	return Local_s32Inputval;
}


int main(void)
{
    DIO_enuInit();
	adc_SelectRef(adc_AVCC_MASK);
	adc_SelectAdjustment(adc_ADLAR_LEFT_ADJUST);
	adc_SelectChannelSingle(adc_ADMUX_ADC4);
	adc_SelectPrescalar(adc_PRESCALAR_DIVIDED_BY128);
	adc_Enable(adc_ENABLE_MASK);
	TMR1_vidInitPreCompile();
	//u16 Local_u16Counter = 0;
	u8 Local_u8Val = 0;
	s32 Local_s32var = 0;
	TMR1_enuSetChannel1InputCaptureReg(20000);
	
    while (1) 
    {
		adc_StartConversion_8Bit(&Local_u8Val);
		Local_s32var = map(0,255,750,2500,Local_u8Val);
		TMR1_enuSetChannel1CompMatchValue(Local_s32var);
		_delay_ms(10);
		//for(Local_u16Counter = 750 ; Local_u16Counter < 2500 ; Local_u16Counter++)
		//{
		//	TMR1_enuSetChannel1CompMatchValue(Local_u16Counter);
		//	
		//}
			
    }
}

