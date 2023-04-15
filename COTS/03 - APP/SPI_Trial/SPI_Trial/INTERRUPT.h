#ifndef INTERRUPT_H
#define INTERRUPT_H

#define ISR_ITI_HELPER(ISR_NO)    void __vector_##ISR_NO (void) __attribute__((signal));\
                                  void __vector_##ISR_NO (void) 

#define ISR_ITI(ISR_NO)           ISR_ITI_HELPER(ISR_NO)


#define INT0                       1
#define INT1                       2
#define INT2                       3
#define TIMER2_COMP                4
#define TIMER2_OVF                 5
#define TIMER1_CAPT                6
#define TIMER1_COMPA               7
#define TIMER1_COMPB               8
#define TIMER1_OVF                 9
#define TIMER0_COMP                10
#define TIMER0_OVF                 11
#define SPI_STC                    12
#define USART_RXC                  13
#define USART_UDRE                 14
#define USART_TXC                  15
#define ADC                        16
#define EE_RDY                     17
#define ANA_COMP                   18
#define TWI                        19
#define SPM_RDY                    20




#endif