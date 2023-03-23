/******************************************************************/
/*TIMER1 Driver                */
/* Target:ATMEGA32                       */
/* Yousef_Ahmed                              */
/* Date:2023-03-11                                       */
/******************************************************************/
#include "STD_TYPES.h"
#include "TIMER1.h"
#include "INTERRUPT.h"

/**********************************Regisers*******************************************/
#define TCCR1B   *((volatile u16 * const)0x4E)
#define TCNT1L   *((volatile u16 * const)0x4C)
#define OCR1AL   *((volatile u16 * const)0x4A)
#define OCR1BL   *((volatile u16 * const)0x48)
#define ICR1L    *((volatile u16 * const)0x46)
#define TIMSK    *((volatile u8 * const)0x59)
/***************************************************************************************/

#define MAX_REG_VAL                 65536

#define ICU_CALLBACK                0
#define CTC_A_CALLBACK              1
#define CTC_B_CALLBACK              2
#define OVER_FLOW                   3

#define MODE_CLEAR_MASK             0xFCE7
#define PRESCALAR_CLEAR_MASK        0xFFF8
#define OC1A_CLEAR_MASK             0x3FFF
#define OC1B_CLEAR_MASK             0xCFFF
#define ICU_CLEAR_MASK              0xFFBF
/***************************************************************************************/

static TMR1_t TMR1_cbf[4];

void TMR1_vidInitPreCompile(void)
{
    u16 Local_u16Reg = 0;
    #if MODE == TMR1_NORMAL_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_NORMAL_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif
    #elif MODE == TMR1_PWM_PHASE_CORRECT_8BIT_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_PWM_PHASE_CORRECT_8BIT_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;                                                
            #endif
#elif MODE == TMR1_PWM_PHASE_CORRECT_9BIT_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_PWM_PHASE_CORRECT_9BIT_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;                                                
            #endif
#elif MODE == TMR1_PWM_PHASE_CORRECT_10BIT_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_PWM_PHASE_CORRECT_10BIT_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE
                 Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;                                                
            #endif
#elif MODE == TMR1_CTC_OCR1A_TOP_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_CTC_OCR1A_TOP_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_CLEAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_CLEAR;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_SET
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_SET;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_CLEAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1B_CLEAR;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_SET
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1B_SET;
                TCCR1B = Local_u16Reg;                                                
            #endif
#elif MODE == TMR1_FAST_PWM_8BIT_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_FAST_PWM_8BIT_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
#elif MODE == TMR1_FAST_PWM_9BIT_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_FAST_PWM_9BIT_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
#elif MODE == TMR1_FAST_PWM_10BIT_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_FAST_PWM_10BIT_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif

#elif MODE == TMR1_PHASE_CORRECT_ICR1_TOP_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_PHASE_CORRECT_ICR1_TOP_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif

#elif MODE == TMR1_PHASE_CORRECT_OCR1A_TOP_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_PHASE_CORRECT_OCR1A_TOP_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif 
            
#elif MODE == TMR1_CTC_ICR1_TOP_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_CTC_ICR1_TOP_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_CLEAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_CLEAR;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_COMP_MATCH_MODE_OC1A_SET
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_SET;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_CLEAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_COMP_MATCH_MODE_OC1B_SET
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1B_SET;
                TCCR1B = Local_u16Reg;                                                
            #endif

#elif MODE == TMR1_FAST_PWM_ICR1_TOP_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_FAST_PWM_ICR1_TOP_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_CLEAR;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif

#elif MODE == TMR1_FAST_PWM_OCR1A_TOP_MODE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= MODE_CLEAR_MASK;
        Local_u16Reg |= TMR1_FAST_PWM_ICR1_TOP_MODE;
        TCCR1B = Local_u16Reg;
            #if PRESCALAR == TMR1_NO_PRESCALAR
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_NO_PRESCALAR;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_8 
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_8;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_64
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_256
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_256;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_CLOCK_DIVIDED_BY_1024
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_CLOCK_DIVIDED_BY_64;
                TCCR1B = Local_u16Reg;
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE;
                TCCR1B = Local_u16Reg; 
            #elif PRESCALAR == TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= PRESCALAR_CLEAR_MASK;
                Local_u16Reg |= TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE;
                TCCR1B = Local_u16Reg;                                                                                                                          
            #endif
            #if INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_A_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_A_INT;
            #elif INT_SOURCE == TMR1_OVER_FLOW_INT
                TIMSK |= TMR1_OVER_FLOW_INT;
            #elif INT_SOURCE == TMR1_COMP_MATCH_CHANNEL_B_INT
                TIMSK |= TMR1_COMP_MATCH_CHANNEL_B_INT;
            #elif INT_SOURCE == TMR1_INPUT_CAPTURE_INT
                TIMSK |= TMR1_INPUT_CAPTURE_INT;            
            #endif                                    
            #if OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_COMP_MATCH_MODE_OC1A_CLEAR;
                TCCR1B = Local_u16Reg;
            #elif OC1A_CONFIG == TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1A_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif
            #if OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_DISABLED
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_DISABLED;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_TOGGLE
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_TOGGLE;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP;
                TCCR1B = Local_u16Reg;
            #elif OC1B_CONFIG == TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP
                Local_u16Reg = TCCR1B;
                Local_u16Reg &= OC1B_CLEAR_MASK;
                Local_u16Reg |= TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP;
                TCCR1B = Local_u16Reg;                                                
            #endif                                                                                                                                                                   

    #endif 

    #if ICU_CAPTURE_MODE == TMR1_INPUT_CAPTURE_RISING_EDGE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= ICU_CLEAR_MASK;
        Local_u16Reg |= TMR1_INPUT_CAPTURE_RISING_EDGE;
        TCCR1B = Local_u16Reg;
    #elif  ICU_CAPTURE_MODE == TMR1_INPUT_CAPTURE_FALLING_EDGE
        Local_u16Reg = TCCR1B;
        Local_u16Reg &= ICU_CLEAR_MASK;
        Local_u16Reg |= TMR1_INPUT_CAPTURE_FALLING_EDGE;
        TCCR1B = Local_u16Reg;
    #endif       
    ///*Set_OC1A to fast pwm non inverted*/
    //TCCR1B |= TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP;
    ///*Set the mode*/
    //TCCR1B |= TMR1_FAST_PWM_ICR1_TOP_MODE;
    ///*Set the prescalar*/
    //TCCR1B &= ~(TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE);
    //TCCR1B |= TMR1_CLOCK_DIVIDED_BY_8;
}
TMR1_enuErrorStatus TMR1_enuSetChannel1CompMatchValue(u16 Copy_u16Value)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(Copy_u16Value > MAX_REG_VAL)
    {
        Local_enuErrorStatus = TMR1_NotOk;
    }
    else
    {
        OCR1AL = Copy_u16Value;
    }
    return Local_enuErrorStatus;
    
}
TMR1_enuErrorStatus TMR1_enuSetChannel2CompMatchValue(u16 Copy_u16Value)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(Copy_u16Value > MAX_REG_VAL)
    {
        Local_enuErrorStatus = TMR1_NotOk;
    }
    else
    {
        OCR1BL = Copy_u16Value;
    }
    return Local_enuErrorStatus;    

}
TMR1_enuErrorStatus TMR1_enuSetChannel1InputCaptureReg(u16 Copy_u16Value)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(Copy_u16Value > MAX_REG_VAL)
    {
        Local_enuErrorStatus = TMR1_NotOk;
    }
    else
    {
        ICR1L = Copy_u16Value;
    }    
    
    return Local_enuErrorStatus;
}

TMR1_enuErrorStatus TMR1_enuSetCallbackOverFlow(TMR1_t TimerCallBackFunction)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(TimerCallBackFunction)
    {
        TMR1_cbf[OVER_FLOW] = TimerCallBackFunction; 
    }
    else
    {
         Local_enuErrorStatus = TMR1_NullPtr;
    }
    return Local_enuErrorStatus;

}
TMR1_enuErrorStatus TMR1_enuSetCallbackCTCChannelA(TMR1_t TimerCallBackFunction)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(TimerCallBackFunction)
    {
        TMR1_cbf[CTC_A_CALLBACK] = TimerCallBackFunction;
    }
    else
    {
        Local_enuErrorStatus = TMR1_NullPtr;
    }
    return Local_enuErrorStatus;
}
TMR1_enuErrorStatus TMR1_enuSetCallbackCTCChannelB(TMR1_t TimerCallBackFunction)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(TimerCallBackFunction)
    {
        TMR1_cbf[CTC_B_CALLBACK] = TimerCallBackFunction;
    }
    else
    {
        Local_enuErrorStatus = TMR1_NullPtr;
    }
    return Local_enuErrorStatus;
}

TMR1_enuErrorStatus TMR1_enuSetCallbackICU(TMR1_t TimerCallBackFunction)
{
    TMR1_enuErrorStatus Local_enuErrorStatus = TMR1_Ok;

    if(TimerCallBackFunction)
    {
        TMR1_cbf[ICU_CALLBACK] = TimerCallBackFunction;
    }
    else
    {
        Local_enuErrorStatus = TMR1_NullPtr;
    }
    return Local_enuErrorStatus;    

}

ISR_ITI(TIMER1_CAPT)
{
    if(TMR1_cbf[ICU_CALLBACK])
    {
        TMR1_cbf[ICU_CALLBACK]();
    }
}

ISR_ITI(TIMER1_COMPA)
{
    if(TMR1_cbf[CTC_A_CALLBACK])
    {
        TMR1_cbf[CTC_A_CALLBACK]();
    }

}

ISR_ITI(TIMER1_COMPB)
{
    if(TMR1_cbf[CTC_B_CALLBACK])
    {
        TMR1_cbf[CTC_B_CALLBACK]();
    }

}

ISR_ITI(TIMER1_OVF)
{
    if(TMR1_cbf[OVER_FLOW])
    {
        TMR1_cbf[OVER_FLOW]();
    }

}