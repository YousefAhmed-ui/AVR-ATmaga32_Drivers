/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 25/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#include "ADC.h"



/***************************************Registers******************************************/
#define   ADCL         *((volatile u8 *const)0x24)
#define   ADCH         *((volatile u8 *const)0x25)
#define   ADCSRA       *((volatile u8 *const)0x26)
#define   ADMUX        *((volatile u8 *const)0x27)
#define   SFIOR        *((volatile u8 *const)0x50)
/*******************************Masks************************************************************/
#define   ADMUX_REF_CLEAR_MASK               0x3F
#define   ADMUX_ADLAR_CLEAR_MASK             0xDF
#define   ADMUX_CHANNEL_CLEAR_MASK           0x20
#define   ADSRA_PRESCALAR_CLEAR_MASK         0xF8
#define   SFIOR_TRIGGER_SOURCE_CLEAR_MASK    0x1F


ADC_enuErrorStatus_t adc_SelectRef(u8 Copy_u8Ref){
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADMUX;
    if( (Copy_u8Ref != adc_AREF_MASK) || (Copy_u8Ref != adc_AVCC_MASK) || (Copy_u8Ref != adc_Inernal_MASK))
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    else
    {
        Local_u8ADMUX = ADMUX;
        Local_u8ADMUX &= ADMUX_REF_CLEAR_MASK;
        Local_u8ADMUX |= Copy_u8Ref;
        ADMUX = Local_u8ADMUX;
    }
    return Local_u8ErrorStatus;
     
}
ADC_enuErrorStatus_t adc_SelectAdjustment(u8 Copy_u8Adjustment)
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADMUX;
    if((Copy_u8Adjustment != adc_ADLAR_LEFT_ADJUST) || (Copy_u8Adjustment != adc_ADLAR_RIGHT_ADJUST))
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    else
    {
        Local_u8ADMUX = ADMUX;
        Local_u8ADMUX &= ADMUX_ADLAR_CLEAR_MASK;
        Local_u8ADMUX |= Copy_u8Adjustment;
        ADMUX = Local_u8ADMUX;        
    }
    return Local_u8ErrorStatus;
}
ADC_enuErrorStatus_t adc_SelectChannelSingle(u8 Copy_u8Channel)
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADMUX;
    if( (Copy_u8Channel < 0) || ( Copy_u8Channel > 7))
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    else
    {
        Local_u8ADMUX = ADMUX;
        Local_u8ADMUX &= ADMUX_CHANNEL_CLEAR_MASK;
        Local_u8ADMUX |= Copy_u8Channel;
    }
    return Local_u8ErrorStatus;
}
ADC_enuErrorStatus_t adc_Enable(u8 Copy_u8EnableMask)
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADCSRA;
    if( Copy_u8EnableMask != adc_ENABLE_MASK )
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    else
    {
        Local_u8ADCSRA = ADCSRA;
        Local_u8ADCSRA &= ~(adc_ENABLE_MASK);
        Local_u8ADCSRA |= Copy_u8EnableMask;
    }
    return Local_u8ErrorStatus;     

}
ADC_enuErrorStatus_t adc_Disable(u8 Copy_u8DisableMask)
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADCSRA;
    if( Copy_u8DisableMask != adc_DISABLE_MASK )
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    else
    {
        Local_u8ADCSRA = ADCSRA;
        Local_u8ADCSRA &= ~(adc_ENABLE_MASK);
        Local_u8ADCSRA |= Copy_u8DisableMask;
    }
    return Local_u8ErrorStatus;          
}
ADC_enuErrorStatus_t adc_SetAutoTrigger(ADC_enuStatus_t Copy_u8Status)
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADCSRA;
    if( Copy_u8Status == ON )
    {
        Local_u8ADCSRA = ADCSRA;
        Local_u8ADCSRA &= ~(adc_ENABLE_TRIGGER_MASK);
        Local_u8ADCSRA |= adc_ENABLE_TRIGGER_MASK;
        ADCSRA = Local_u8ADCSRA;
    }
    else if(Copy_u8Status == OFF)
    {
        Local_u8ADCSRA = ADCSRA;
        Local_u8ADCSRA &= ~(adc_ENABLE_TRIGGER_MASK);
        Local_u8ADCSRA |= adc_DISABLE_TRIGGER_MASK;
        ADCSRA = Local_u8ADCSRA;
    }
    else
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    

    return Local_u8ErrorStatus;

    
}
ADC_enuErrorStatus_t adc_SetInterrupt( ADC_enuStatus_t Copy_u8Status )
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADCSRA;
    if( Copy_u8Status == ON )
    {
        Local_u8ADCSRA = ADCSRA;
        Local_u8ADCSRA &= ~(adc_ENABLE_INT);
        Local_u8ADCSRA |= adc_ENABLE_INT;
        ADCSRA = Local_u8ADCSRA;
    }
    else if(Copy_u8Status == OFF)
    {
        Local_u8ADCSRA = ADCSRA;
        Local_u8ADCSRA &= ~(adc_ENABLE_INT);
        Local_u8ADCSRA |= adc_DISABLE_INT;
        ADCSRA = Local_u8ADCSRA;
    }
    else
    {
        Local_u8ErrorStatus = ADC_enuNotOk;
    }
    

    return Local_u8ErrorStatus;

    
}    
    
ADC_enuErrorStatus_t adc_SelectPrescalar(u8 Copy_u8Prescalar )
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADCSRA; 
    Local_u8ADCSRA = ADCSRA;
    Local_u8ADCSRA &= ADSRA_PRESCALAR_CLEAR_MASK;  
    Local_u8ADCSRA |= Copy_u8Prescalar;
    ADCSRA = Local_u8ADCSRA;
    return Local_u8ErrorStatus;  
}

ADC_enuErrorStatus_t adc_SelectAutoTriggerSource(u8 Copy_u8TriggerSource)
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8SFIOR;
    Local_u8SFIOR = SFIOR;
    Local_u8SFIOR &= SFIOR_TRIGGER_SOURCE_CLEAR_MASK;
    Local_u8SFIOR |= Copy_u8TriggerSource;
    SFIOR = Local_u8SFIOR;
    return Local_u8ErrorStatus;
}
ADC_enuErrorStatus_t adc_StartConversion_8Bit( u8 * Copy_u8GetAdcVal )
{
    ADC_enuErrorStatus_t Local_u8ErrorStatus = ADC_enuOk;
    u8 Local_u8ADCSRA;
    u32 Local_u32TimeOut = 0;
    Local_u8ADCSRA = ADCSRA;
    Local_u8ADCSRA &= adc_CLEAR_CONVERSION_MASK;
    Local_u8ADCSRA |= adc_START_CONVERSION_MASK;
    ADCSRA = Local_u8ADCSRA;
    while( (ADCSRA & adc_START_CONVERSION_MASK) && Local_u32TimeOut < 1000 )
    {
        Local_u32TimeOut++;
        if(Local_u32TimeOut >= 1000)
        {
            Local_u8ErrorStatus = ADC_enuNotOk;
        }
    }
    *Copy_u8GetAdcVal = ADCH;
        
}