/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 25/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


EXTI_enuErrorStatus_t EXTI_enuInitInterrupt(void)
{
    EXTI_enuErrorStatus_t Local_enuErrorStatus = EXTI_enuOk; 
        #if INT0_MODE == LowLevel
         MCUCR = 0;
         MCUCR |= INT0_LOWLEVEL;
        #elif INT0_MODE == OnChange
         MCUCR = 0;
         MCUCR |= INT0_ONCHANGE;
        #elif INT0_MODE == FallingEdge
         MCUCR = 0;
         MCUCR |= INT0_ONCHANGE;
        #else
         MCUCR = 0;
         MCUCR |= INT0_RISINGEDGE;
        #endif

        #if INT1_MODE == LowLevel
         MCUCR = 0;
         MCUCR |= INT1_LOWLEVEL;
        #elif INT1_MODE == OnChange
         MCUCR = 0;
         MCUCR |= INT1_ONCHANGE;
        #elif INT1_MODE == FallingEdge
         MCUCR = 0;
         MCUCR |= INT1_ONCHANGE;
        #else
         MCUCR = 0;
         MCUCR |= INT1_RISINGEDGE;
        #endif

        #if INT2_MODE == FallingEdge
         MCUCSR = 0;
         MCUCSR |= INT0_ONCHANGE;
        #else
         MCUCSR = 0;
         MCUCSR |= INT2_RISINGEDGE;
        #endif                 
}



EXTI_enuErrorStatus_t EXTI_enuEnableInterrupt(u8 Copy_u8IntNum)
{
    u8 Local_u8ErrorStatus = EXTI_enuOk;
    if( Copy_u8IntNum > EXTI_Num )
    {
        Local_u8ErrorStatus = EXTI_enuInValidIntNum;
    }
    else
    {   
        if(Copy_u8IntNum == INT0)
         SET_BIT(GICR,GICR_INTF0);
        else if (Copy_u8IntNum == INT1)    
         SET_BIT(GICR,GICR_INTF1);
        else
         SET_BIT(GICR,GICR_INTF2);
          
    }
 

    return Local_u8ErrorStatus;
}