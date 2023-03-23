/*******************************************************************/
/*         TIMER0 Driver         */
/*Target : ATMEGA32                                         */
/*Author :Yousef_Ahmed                         */
/*Date   :2023-03-02                                      */
/*******************************************************************/

#ifndef _TIMER0_CFG_H
#define _TIMER0_CFG_H


#define TMR_NORMAL_MODE                                                                 0b00000000
#define TMR_PHASE_CORRECT_PWM_MODE                                                      0b01000000
#define TMR_CTC_MODE                                                                    0b00001000
#define TMR_FAST_PWM__MODE                                                              0b01001000
#define TMR_CLEAR_MODE_MASK                                                             0b10110111
                   
#define TMR_COMP_MATCH_NON_PWM_MODE_NORMAL                                              0b00000000
#define TMR_COMP_MATCH_NON_PWM_MODE_TOGGLE_OC0                                          0b00010000
#define TMR_COMP_MATCH_NON_PWM_MODE_CLEAR_OC0                                           0b00100000
#define TMR_COMP_MATCH_NON_PWM_MODE_SET_OC0                                             0b00110000
#define TMR_COMP_MATCH_CLEAR_MASK                                                       0b11001111
                   
#define TMR_COMP_MATCH_FAST_PWM_MODE_NORMAL                                             0b00000000
#define TMR_COMP_MATCH_FAST_PWM_MODE_CLEAR_ON_COMP_SET_ON_TOP_OC0                       0b00100000
#define TMR_COMP_MATCH_FAST_PWM_MODE_SET_COMP_CLEAR_ON_TOP_OC0                          0b00110000
                   
#define TMR_COMP_MATCH_PHASE_CORRECT_PWM_MODE_NORMAL                                    0b00000000
#define TMR_COMP_MATCH_PHASE_CORRECT_PWM_MODE_CLEAR_ON_COMP_SET_ON_TOP_OC0              0b00100000
#define TMR_COMP_MATCH_FAST_PWM_MODE_SET_ON_COMP_CLEAR_ON_TOP_OC0                       0b00110000
#define TMR_OC0_CLEAR_MODE_MASK                                                         0b11001111
                   
#define TMR_NO_CLOCK_SOURCE                                                             0b00000000  //TIMER IS OFF
#define TMR_CLOCK_NO_PRESCALAR                                                          0b00000001
#define TMR_CLOCK_DIVIDED_BY_8                                                          0b00000010
#define TMR_CLOCK_DIVIDED_BY_64                                                         0b00000011
#define TMR_CLOCK_DIVIDED_BY_256                                                        0b00000100
#define TMR_CLOCK_DIVIDED_BY_1024                                                       0b00000101
#define TMR_CLOCK_COUNT_ON_FALLING_EDGE                                                 0b00000110
#define TMR_CLOCK_COUNT_ON_RISING_EDGE                                                  0b00000111
#define TMR_PRESCALAR_CLEAR_MASK                                                        0b11111000
                   
#define TMR_OUT_PUT_COMP_MATCH_INT_EN                                                   0b00000010
#define TMR_OUT_PUT_OVER_FLOW_INT_EN                                                    0b00000001
#define TMR_CTC_INT                                                                     0
#define TMR_OVERFLOW_INT                                                                1     

typedef struct{
    u8 Mode;
    u8 Prescalar;
    u8 Interrupt_source;
}TMR0Config_t;


#define MODE          TMR_CTC_MODE
#define PRESCALAR     TMR_CLOCK_DIVIDED_BY_8
#define INT_SOURCE    TMR_CTC_INT
#define OC0_CONFIG    TMR_COMP_MATCH_FAST_PWM_MODE_CLEAR_ON_COMP_SET_ON_TOP_OC0 

#endif /*TIMER0_CFG_H*/
