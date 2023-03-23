/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 7/2/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#ifndef ADC_H
#define ADC_H


#include "STD_TYPES.h"
#include "BIT_MATH.h"


/*********************************************Masks************************************************************************/
#define         adc_AREF_MASK                               0x00
#define         adc_AVCC_MASK                               0x40
#define         adc_Inernal_MASK                            0xC0     //2.56 v

#define         adc_ADLAR_LEFT_ADJUST                       0x20
#define         adc_ADLAR_RIGHT_ADJUST                      0x00 


#define         adc_ADMUX_ADC0                              0b00000
#define         adc_ADMUX_ADC1                              0b00001
#define         adc_ADMUX_ADC2                              0b00010
#define         adc_ADMUX_ADC3                              0b00011
#define         adc_ADMUX_ADC4                              0b00100
#define         adc_ADMUX_ADC5                              0b00101
#define         adc_ADMUX_ADC6                              0b00110
#define         adc_ADMUX_ADC7                              0b00111


#define         adc_ENABLE_MASK                             0x80 
#define         adc_DISABLE_MASK                            0x00

#define         adc_ENABLE_TRIGGER_MASK                     0x20
#define         adc_DISABLE_TRIGGER_MASK                    0x00

#define         adc_ENABLE_INT                              0x08
#define         adc_DISABLE_INT                             0x00


#define         adc_PRESCALAR_DIVIDED_BY2                   0b001
#define         adc_PRESCALAR_DIVIDED_BY4                   0b010
#define         adc_PRESCALAR_DIVIDED_BY8                   0b011
#define         adc_PRESCALAR_DIVIDED_BY16                  0b100
#define         adc_PRESCALAR_DIVIDED_BY32                  0b101
#define         adc_PRESCALAR_DIVIDED_BY64                  0b110
#define         adc_PRESCALAR_DIVIDED_BY128                 0b111

#define         adc_TRIGGER_SOURCE_FREE_RUNNING             0x00
#define         adc_TRIGGER_SOURCE_ANALOG_COMP              0x20
#define         adc_TRIGGER_SOURCE_EXTI_0                   0x40
#define         adc_TRIGGER_SOURCE_TIMER0_COMP_MATCH        0x60
#define         adc_TRIGGER_SOURCE_TIMER0_OVERFLOW          0x80
#define         adc_TRIGGER_SOURCE_TIMER1_COMP_MATCH        0xA0
#define         adc_TRIGGER_SOURCE_TIMER1_OVERFLOW          0xC0
#define         adc_TRIGGER_SOURCE_CAPTURE_EVENT            0xE0

#define         adc_START_CONVERSION_MASK                   0x40
#define         adc_CLEAR_CONVERSION_MASK                   0xBF

/*************************************Types**************************************************************************/
typedef enum{
    ADC_enuOk,
    ADC_enuNotOk
}ADC_enuErrorStatus_t;

typedef enum{
    OFF,
    ON
}ADC_enuStatus_t;

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SelectRef(u8 Copy_u8Ref);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SelectAdjustment(u8 Copy_u8Adjustment);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SelectChannelSingle(u8 Copy_u8Channel);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_Enable(u8 Copy_u8EnableMask);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_Disable(u8 Copy_u8DisableMask);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SetAutoTrigger(ADC_enuStatus_t Copy_u8Status);

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SetInterrupt( ADC_enuStatus_t Copy_u8Status );

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SelectPrescalar(u8 Copy_u8Prescalar );

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
ADC_enuErrorStatus_t adc_SelectAutoTriggerSource(u8 Copy_u8TriggerSource);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
ADC_enuErrorStatus_t adc_StartConversion_8Bit( u16 * Copy_u8GetAdcVal );

#endif