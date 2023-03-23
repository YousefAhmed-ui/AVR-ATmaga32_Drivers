/*******************************************************************/
/*         TIMER1 Driver         */
/* Target:ATMEGA32                       */
/*Author :Yousef_Ahmed                         */
/*Date   :2023-03-11                                      */
/*******************************************************************/

#ifndef _TIMER1_CFG_H
#define _TIMER1_CFG_H

#define TMR1_COMP_MATCH_MODE_OC1A_DISABLED                                      0x0000
#define TMR1_COMP_MATCH_MODE_OC1A_TOGGLE                                        0x4000
#define TMR1_COMP_MATCH_MODE_OC1A_CLEAR                                         0x8000
#define TMR1_COMP_MATCH_MODE_OC1A_SET                                           0xC000
                        
#define TMR1_COMP_MATCH_MODE_OC1B_DISABLED                                      0x0000
#define TMR1_COMP_MATCH_MODE_OC1B_TOGGLE                                        0x1000
#define TMR1_COMP_MATCH_MODE_OC1B_CLEAR                                         0x2000
#define TMR1_COMP_MATCH_MODE_OC1B_SET                                           0x3000
    
#define TMR1_FAST_PWM_MODE_OC1A_DISABLED                                        0x0000
#define TMR1_FAST_PWM_MODE_OC1A_TOGGLE                                          0x4000
#define TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP                        0x8000
#define TMR1_FAST_PWM_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP                        0xC000

#define TMR1_FAST_PWM_MODE_OC1B_DISABLED                                        0x0000
#define TMR1_FAST_PWM_MODE_OC1B_TOGGLE                                          0x1000
#define TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP                        0x2000
#define TMR1_FAST_PWM_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP                        0x3000

#define TMR1_PHASE_CORRECT_MODE_OC1A_DISABLED                                   0x0000
#define TMR1_PHASE_CORRECT_MODE_OC1A_TOGGLE                                     0x4000
#define TMR1_PHASE_CORRECT_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP                   0x8000
#define TMR1_PHASE_CORRECT_MODE_OC1A_SET_ON_COMP_CLEAR_ON_TOP                   0xC000

#define TMR1_PHASE_CORRECT_MODE_OC1B_DISABLED                                   0x0000
#define TMR1_PHASE_CORRECT_MODE_OC1B_TOGGLE                                     0x1000
#define TMR1_PHASE_CORRECT_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP                   0x2000
#define TMR1_PHASE_CORRECT_MODE_OC1B_SET_ON_COMP_CLEAR_ON_TOP                   0x3000

#define TMR1_NORMAL_MODE                                                        0x0000                                                       
#define TMR1_PWM_PHASE_CORRECT_8BIT_MODE                                        0x0100                                                                                                                    
#define TMR1_PWM_PHASE_CORRECT_9BIT_MODE                                        0x0200                                                                                                                    
#define TMR1_PWM_PHASE_CORRECT_10BIT_MODE                                       0x0300                                                                                                              
#define TMR1_CTC_OCR1A_TOP_MODE                                                 0x0008                                                                                                              
#define TMR1_FAST_PWM_8BIT_MODE                                                 0x0108                                                                                                                                                                             
#define TMR1_FAST_PWM_9BIT_MODE                                                 0x0208                                                                                                                                                                             
#define TMR1_FAST_PWM_10BIT_MODE                                                0x0308                                                                                                                                                                             
#define TMR1_PHASE_CORRECT_ICR1_TOP_MODE                                        0x0210                                                                                                                                                                             
#define TMR1_PHASE_CORRECT_OCR1A_TOP_MODE                                       0x0310                                                                                                                                                                             
#define TMR1_CTC_ICR1_TOP_MODE                                                  0x0018                                                                                                                                                                             
#define TMR1_FAST_PWM_ICR1_TOP_MODE                                             0x0218                                                                                                                                                                             
#define TMR1_FAST_PWM_OCR1A_TOP_MODE                                            0x0318 

#define TMR1_STOPPED                                                            0x0000
#define TMR1_NO_PRESCALAR                                                       0x0001
#define TMR1_CLOCK_DIVIDED_BY_8                                                 0x0002
#define TMR1_CLOCK_DIVIDED_BY_64                                                0x0003
#define TMR1_CLOCK_DIVIDED_BY_256                                               0x0004
#define TMR1_CLOCK_DIVIDED_BY_1024                                              0x0005
#define TMR1_EXTERNAL_CLOCK_SRC_FALLING_EDGE                                    0x0006
#define TMR1_EXTERNAL_CLOCK_SRC_RISING_EDGE                                     0x0007

#define TMR1_OVER_FLOW_INT                                                      0x04
#define TMR1_COMP_MATCH_CHANNEL_A_INT                                           0x10
#define TMR1_COMP_MATCH_CHANNEL_B_INT                                           0x08
#define TMR1_INPUT_CAPTURE_INT                                                  0x20

#define TMR1_INPUT_CAPTURE_FALLING_EDGE                                         0x0000
#define TMR1_INPUT_CAPTURE_RISING_EDGE                                          0x0040

#define MODE                                                                    TMR1_FAST_PWM_ICR1_TOP_MODE
#define PRESCALAR                                                               TMR1_CLOCK_DIVIDED_BY_8
#define INT_SOURCE                                                              TMR1_COMP_MATCH_CHANNEL_A_INT
#define OC1A_CONFIG                                                             TMR1_FAST_PWM_MODE_OC1A_CLEAR_ON_COMP_SET_ON_TOP 
#define OC1B_CONFIG                                                             TMR1_FAST_PWM_MODE_OC1B_CLEAR_ON_COMP_SET_ON_TOP
#define ICU_CAPTURE_MODE                                                        TMR1_INPUT_CAPTURE_FALLING_EDGE



#endif /*TIMER1_CFG_H*/
