/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 17/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "DIO_interface.h"


DIO_tenuErrorStatus LED_enuOn( DIO_tenuPins Copy_u8PinNumber )
{
    DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
    DIO_enuSetPin( Copy_u8PinNumber , DIO_enuHigh );

    return Local_u8ErrorStatus;
}


DIO_tenuErrorStatus LED_enuOff( DIO_tenuPins Copy_u8PinNumber )
{
    DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
	
    DIO_enuSetPin( Copy_u8PinNumber , DIO_enuLow );

    return Local_u8ErrorStatus;
}

DIO_tenuErrorStatus LED_enuToggle( DIO_tenuPins Copy_u8PinNumber )
{
    DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
    DIO_enuTogglePin(Copy_u8PinNumber);

    return Local_u8ErrorStatus;

}
