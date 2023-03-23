#include "Switch.h"

#include "STD_Types.h"
#include "DIO_interface.h"
#include "BIT_Math.h"
DIO_tenuErrorStatus Switch_enuGetValue(DIO_tenuPins Switch , u8 * Add_pu8PinValue)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_enuOk;
	Local_enuErrorStatus =  DIO_enuGetPin( Switch , Add_pu8PinValue );
	

   return Local_enuErrorStatus;

}