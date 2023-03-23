/******************************************************************/
/*TIMER0 Driver                */
/* Target: ATMEGA32                                      */
/* Yousef_Ahmed                              */
/* Date:2023-03-02                                       */
/******************************************************************/

#include "STD_TYPES.h"
#include "TIMER0.h"
#include "INTERRUPT.h"
/********************************registers************************/
#define TCCR0          *((volatile u8 * const)0x53)
#define TCNT0          *((volatile u8 * const)0x52)
#define OCR0           *((volatile u8 * const)0x5C)
#define TIMSK          *((volatile u8 * const)0x59)
#define TIFR           *((volatile u8 * const)0x58)
/*****************************************************************/

#define MAX_CLOCK               (u32)8000000
#define MAX_TCNT_VALUE          255 


/*****************************************************************/
static TMR0_t AppCallBack;

extern const TMR0Config_t Timer_cfg[TMR_count]; 

void TMR0_vidInitPreCompile(void)
{
    u8 Local_u8Reg = 0;
    #if MODE == TMR_NORMAL_MODE
        Local_u8Reg = TCCR0;
        Local_u8Reg &= TMR_CLEAR_MODE_MASK;
        Local_u8Reg |= TMR_NORMAL_MODE;
        TCCR0 = Local_u8Reg;
        #if PRESCALAR == TMR_NO_CLOCK_SOURCE
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_NO_CLOCK_SOURCE;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_NO_PRESCALAR
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_NO_PRESCALAR;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_8
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_8;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_64
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_64;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_256
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_256;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_1024
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_1024;
            TCCR0 = Local_u8Reg;                                            
        #endif
        #if INT_SOURCE == TMR_CTC_INT
            TIMSK |= TMR_OUT_PUT_COMP_MATCH_INT_EN;
        #elif INT_SOURCE == TMR_OVERFLOW_INT
            TIMSK |= TMR_OUT_PUT_OVER_FLOW_INT_EN;
        #endif                
    #elif  MODE == TMR_PHASE_CORRECT_PWM_MODE
        Local_u8Reg = TCCR0;
        Local_u8Reg &= TMR_CLEAR_MODE_MASK;
        Local_u8Reg |= TMR_PHASE_CORRECT_PWM_MODE;
        TCCR0 = Local_u8Reg;
        #if PRESCALAR == TMR_NO_CLOCK_SOURCE
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_NO_CLOCK_SOURCE;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_NO_PRESCALAR
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_NO_PRESCALAR;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_8
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_8;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_64
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_64;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_256
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_256;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_1024
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_1024;
            TCCR0 = Local_u8Reg;                                            
        #endif
        #if INT_SOURCE == TMR_CTC_INT
            TIMSK |= TMR_OUT_PUT_COMP_MATCH_INT_EN;
        #elif INT_SOURCE == TMR_OVERFLOW_INT
            TIMSK |= TMR_OUT_PUT_OVER_FLOW_INT_EN;
        #endif        
    #elif MODE == TMR_CTC_MODE
        Local_u8Reg = TCCR0;
        Local_u8Reg &= TMR_CLEAR_MODE_MASK;
        Local_u8Reg |= TMR_CTC_MODE;
        TCCR0 = Local_u8Reg;
        #if PRESCALAR == TMR_NO_CLOCK_SOURCE
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_NO_CLOCK_SOURCE;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_NO_PRESCALAR
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_NO_PRESCALAR;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_8
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_8;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_64
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_64;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_256
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_256;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_1024
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_1024;
            TCCR0 = Local_u8Reg;                                            
        #endif
        #if INT_SOURCE == TMR_CTC_INT
            TIMSK |= TMR_OUT_PUT_COMP_MATCH_INT_EN;
        #elif INT_SOURCE == TMR_OVERFLOW_INT
            TIMSK |= TMR_OUT_PUT_OVER_FLOW_INT_EN;
        #endif
    #elif MODE == TMR_FAST_PWM__MODE
        Local_u8Reg = TCCR0;
        Local_u8Reg &= TMR_CLEAR_MODE_MASK;
        Local_u8Reg |= TMR_FAST_PWM__MODE;
        TCCR0 = Local_u8Reg;
        #if PRESCALAR == TMR_NO_CLOCK_SOURCE
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_NO_CLOCK_SOURCE;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_NO_PRESCALAR
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_NO_PRESCALAR;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_8
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_8;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_64
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_64;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_256
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_256;
            TCCR0 = Local_u8Reg;
        #elif PRESCALAR == TMR_CLOCK_DIVIDED_BY_1024
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
            Local_u8Reg |= TMR_CLOCK_DIVIDED_BY_1024;
            TCCR0 = Local_u8Reg;                                            
        #endif
        #if OC0_CONFIG == TMR_COMP_MATCH_FAST_PWM_MODE_NORMAL
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_OC0_CLEAR_MODE_MASK;
            Local_u8Reg |= TMR_COMP_MATCH_FAST_PWM_MODE_NORMAL;
            TCCR0 = Local_u8Reg;
        #elif OC0_CONFIG == TMR_COMP_MATCH_FAST_PWM_MODE_CLEAR_ON_COMP_SET_ON_TOP_OC0
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_OC0_CLEAR_MODE_MASK;
            Local_u8Reg |= TMR_COMP_MATCH_FAST_PWM_MODE_CLEAR_ON_COMP_SET_ON_TOP_OC0;
            TCCR0 = Local_u8Reg;
        #elif OC0_CONFIG == TMR_COMP_MATCH_FAST_PWM_MODE_SET_ON_COMP_CLEAR_ON_TOP_OC0
            Local_u8Reg = TCCR0;
            Local_u8Reg &= TMR_OC0_CLEAR_MODE_MASK;
            Local_u8Reg |= TMR_COMP_MATCH_FAST_PWM_MODE_SET_ON_COMP_CLEAR_ON_TOP_OC0;
            TCCR0 = Local_u8Reg;
        #endif
    #endif                                

}
void TMR0_vidInitPostCompile(TMR0Config_t Copy_strConfig)
{
    u8 Local_u8Reg = 0;
    Local_u8Reg = TCCR0;
    Local_u8Reg &= TMR_CLEAR_MODE_MASK;
    Local_u8Reg &= TMR_PRESCALAR_CLEAR_MASK;
    Local_u8Reg |= (Copy_strConfig.Mode | Copy_strConfig.Prescalar);
    TIMSK |= Copy_strConfig.Interrupt_source;
}
TMR0_enuErrorStatus TMR0_enuSetCompMatchValue(u8 Copy_u8Value)
{
    TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_Ok;
    
    if( Copy_u8Value > MAX_TCNT_VALUE )
    {
        Local_enuErrorStatus = TMR0_NotOk;
    }
    else
    {
        OCR0 = Copy_u8Value; 
    }
        
    return Local_enuErrorStatus;



}

TMR0_enuErrorStatus TMR0_enuRegisterCallback(TMR0_t TimerCallBackFunction)
{
    TMR0_enuErrorStatus Local_enuErrorStatus = TMR0_Ok;
    if(TimerCallBackFunction)
    {
        AppCallBack = TimerCallBackFunction;
    }
    else
    {
        Local_enuErrorStatus = TMR0_NotOk;
    }

    return Local_enuErrorStatus;

}


ISR_ITI(TIMER0_OVF)
{
    AppCallBack();

}
ISR_ITI(TIMER0_COMP)
{
    AppCallBack();
}