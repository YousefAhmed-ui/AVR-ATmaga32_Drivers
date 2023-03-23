/*******************************************************************/
/*         TIMER1 Driver        */
/* Target:ATMEGA32                       */
/*Author :Yousef_Ahmed                         */
/*Date   :2023-03-11                                      */
/*******************************************************************/

#ifndef _TIMER1_H
#define _TIMER1_H


#include "TIMER1_cfg.h"
#include "STD_TYPES.h"

#define TMR0_CLOCK               8000000

typedef enum{
    TMR1_Ok,
    TMR1_NotOk,
    TMR1_NullPtr
}TMR1_enuErrorStatus;


typedef void (*TMR1_t)(void);

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
void TMR1_vidInitPreCompile(void);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/  
TMR1_enuErrorStatus TMR1_enuSetChannel1CompMatchValue(u16 Copy_u16Value);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/  
TMR1_enuErrorStatus TMR1_enuSetChannel2CompMatchValue(u16 Copy_u16Value);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
TMR1_enuErrorStatus TMR1_enuSetChannel1InputCaptureReg(u16 Copy_u16Value);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
TMR1_enuErrorStatus TMR1_enuSetCallbackOverFlow(TMR1_t TimerCallBackFunction);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
TMR1_enuErrorStatus TMR1_enuSetCallbackCTCChannelA(TMR1_t TimerCallBackFunction);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
TMR1_enuErrorStatus TMR1_enuSetCallbackCTCChannelB(TMR1_t TimerCallBackFunction);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
TMR1_enuErrorStatus TMR1_enuSetCallbackICU(TMR1_t TimerCallBackFunction);
#endif /*TIMER1_H*/