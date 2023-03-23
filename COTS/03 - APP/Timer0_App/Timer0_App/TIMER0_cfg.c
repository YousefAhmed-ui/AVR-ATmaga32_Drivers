/******************************************************************/
/*TIMER0 Driver                 */
/* Target: ATMEGA32                                               */
/* Yousef_Ahmed                               */
/* Date:2023-03-02                                       */
/******************************************************************/

#include "STD_TYPES.h"
#include "TIMER0.h"

const TMR0Config_t Timer_cfg[TMR_count] = {
    [TMR0] = {
        .Mode = TMR_CTC_MODE,
        .Prescalar = TMR_CLOCK_DIVIDED_BY_8,
        .Interrupt_source = TMR_CTC_INT

    }
};