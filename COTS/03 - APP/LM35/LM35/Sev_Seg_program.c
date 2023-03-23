/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 20/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"




#include "DIO_interface.h"
#include "Sev_Seg_interface.h"
#include "Sev_Seg_config.h"
#include "Sev_Seg_private.h"



Sev_Seg_tenuErrorStatus Sev_Seg_enuDisplay_Num( u8 Copy_u8Port , u8 Copy_u8Number)
{
    Sev_Seg_tenuErrorStatus Local_enuErrorStatus = 0;
    if( Copy_u8Port > Sev_Seg_PORT_NUM)
    {
        Local_enuErrorStatus = Sev_Seg_enuNotOk; 
    }
    else if( Copy_u8Number > MAX_PORT_VAL )
    {
        Local_enuErrorStatus = Sev_Seg_enuNotOk; 
    }
    else
    {
    DIO_enuSetPort( Copy_u8Port , Sev_Seg_Nums[Copy_u8Number]);
    }
    return Local_enuErrorStatus;
}