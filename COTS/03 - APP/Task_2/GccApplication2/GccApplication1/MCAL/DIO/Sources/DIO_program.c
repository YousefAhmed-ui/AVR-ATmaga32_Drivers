/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 12/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"


//#define DIO_PORTA 0
//#define DIO_PORTB 1
//#define DIO_PORTC 2
//#define DIO_PORTD 3

typedef enum
{

	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD

}DIO_typePORT;


DIO_tenuErrorStatus DIO_enuInit(void)
{
	u8 i;
	u8 Local_u8PortNumber = 0;
	u8 Local_u8PinNumber  = 0;
	for(i = 0 ; i < DIO_enuNumberOfPins ; i++)
	{
		Local_u8PortNumber = i/NumberOfPin;
		Local_u8PinNumber = i%NumberOfPin;
		switch (Local_u8PortNumber)
		{
			case(DIO_PORTA):
			if(DIO_strPinConfig[i].DIO_PinDirection == DIO_DIR_OUTPUT)
			{
				SET_BIT(DDRA,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(DDRA,Local_u8PinNumber);
				if(DIO_strPinConfig[i].DIO_InputStatus == DIO_INPUT_PULL_UP )
				{
					SET_BIT(PORTA,Local_u8PinNumber);
				}
			}
			break;
			case(DIO_PORTB):
			if(DIO_strPinConfig[i].DIO_PinDirection == DIO_DIR_OUTPUT)
			{
				SET_BIT(DDRB,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(DDRB,Local_u8PinNumber);
				if(DIO_strPinConfig[i].DIO_InputStatus == DIO_INPUT_PULL_UP )
				{
					SET_BIT(PORTB,Local_u8PinNumber);
				}
			}
			break;
			case(DIO_PORTC):
			if(DIO_strPinConfig[i].DIO_PinDirection == DIO_DIR_OUTPUT)
			{
				SET_BIT(DDRC,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(DDRC,Local_u8PinNumber);
				if(DIO_strPinConfig[i].DIO_InputStatus == DIO_INPUT_PULL_UP )
				{
					SET_BIT(PORTC,Local_u8PinNumber);
				}
			}
			break;
			case(DIO_PORTD):
			if(DIO_strPinConfig[i].DIO_PinDirection == DIO_DIR_OUTPUT)
			{
				SET_BIT(DDRD,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(DDRD,Local_u8PinNumber);
				if(DIO_strPinConfig[i].DIO_InputStatus == DIO_INPUT_PULL_UP )
				{
					SET_BIT(PORTD,Local_u8PinNumber);
				}
			}
			break;
			default:

			break;
		}
	}
	return DIO_enuOk;

}

//DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Copy_u8PinNumber)
//{
//    DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
//	if ( Copy_u8PinNumber > 31)
//    {
//        Local_u8ErrorStatus = DIO_enuInvalidPinNumber;
//    }
//    else
//    {
//
//    u8 Local_u8PortNumber = Copy_u8PinNumber/NumberOfPin;
//	u8 Local_u8PinNumber = Copy_u8PinNumber%NumberOfPin;
//
//        switch (Local_u8PortNumber)
//        {
//        case (DIO_PORTA):
//            SET_BIT(PORTA,Local_u8PinNumber);
//            break;
//        case (DIO_PORTB):
//            SET_BIT(PORTB,Local_u8PinNumber);
//            break;
//        case (DIO_PORTC):
//            SET_BIT(PORTC,Local_u8PinNumber);
//            break;
//        case (DIO_PORTD):
//            SET_BIT(PORTD,Local_u8PinNumber);
//            break;
//        default:
//            Local_u8ErrorStatus = DIO_enuNotOk;
//            break;
//        }
//	}
//
//    return Local_u8ErrorStatus;
//
//}
//DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Copy_u8PinNumber)
//{
//
//	DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
//    if ( Copy_u8PinNumber > 31)
//    {
//        Local_u8ErrorStatus = DIO_enuInvalidPinNumber;
//    }
//    else
//    {
//    u8 Local_u8PortNumber = Copy_u8PinNumber/NumberOfPin;
//	u8 Local_u8PinNumber = Copy_u8PinNumber%NumberOfPin;
//
//        switch (Local_u8PortNumber)
//        {
//        case (DIO_PORTA):
//            CLR_BIT(PORTA,Local_u8PinNumber);
//            break;
//        case (DIO_PORTB):
//            CLR_BIT(PORTB,Local_u8PinNumber);
//            break;
//        case (DIO_PORTC):
//            CLR_BIT(PORTC,Local_u8PinNumber);
//            break;
//        case (DIO_PORTD):
//            CLR_BIT(PORTD,Local_u8PinNumber);
//            break;
//        default:
//            Local_u8ErrorStatus = DIO_enuNotOk;
//            break;
//        }
//
//    }
//    return Local_u8ErrorStatus;
//}


DIO_tenuErrorStatus DIO_enuGetPin(DIO_tPinValue Copy_u8PinNumber ,u8 * Add_pu8PinValue)
{
	DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;

	if ( Copy_u8PinNumber > MAX_NUM_OF_PINS )
	{
		Local_u8ErrorStatus = DIO_enuInvalidPinNumber;
	}
	else
	{

		u8 Local_u8PortNumber = Copy_u8PinNumber/NumberOfPin;
		u8 Local_u8PinNumber = Copy_u8PinNumber%NumberOfPin;

		switch (Local_u8PortNumber)
		{
			case (DIO_PORTA):
			*Add_pu8PinValue = GET_BIT(PINA,Local_u8PinNumber);
			break;
			case (DIO_PORTB):
			*Add_pu8PinValue = GET_BIT(PINB,Local_u8PinNumber);
			break;
			case (DIO_PORTC):
			*Add_pu8PinValue = GET_BIT(PINC,Local_u8PinNumber);
			break;
			case (DIO_PORTD):
			*Add_pu8PinValue = GET_BIT(PIND,Local_u8PinNumber);
			break;
			default:
			Local_u8ErrorStatus = DIO_enuNotOk;
			break;
		}
		
	}


	return Local_u8ErrorStatus;
}








DIO_tenuErrorStatus DIO_enuSetPin(DIO_tPinValue Copy_u8PinNumber, DIO_tPinValue Copy_enuPinValue)
{
	DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
	if ( Copy_u8PinNumber > MAX_NUM_OF_PINS)
	{
		Local_u8ErrorStatus = DIO_enuInvalidPinNumber;
	}
	else
	{

		u8 Local_u8PortNumber = Copy_u8PinNumber/NumberOfPin;
		u8 Local_u8PinNumber = Copy_u8PinNumber%NumberOfPin;

		switch (Local_u8PortNumber)
		{
			case (DIO_PORTA):
			if( Copy_enuPinValue == DIO_enuHigh )
			{
				SET_BIT(PORTA,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(PORTA,Local_u8PinNumber);
			}
			break;
			case (DIO_PORTB):

			if( Copy_enuPinValue == DIO_enuHigh )
			{
				SET_BIT(PORTB,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(PORTB,Local_u8PinNumber);
			}
			break;
			case (DIO_PORTC):
			if( Copy_enuPinValue == DIO_enuHigh )
			{
				SET_BIT(PORTC,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(PORTC,Local_u8PinNumber);
			}
			break;
			case (DIO_PORTD):
			if( Copy_enuPinValue == DIO_enuHigh )
			{
				SET_BIT(PORTD,Local_u8PinNumber);
			}
			else
			{
				CLR_BIT(PORTD,Local_u8PinNumber);
			}
			break;
			default:
			Local_u8ErrorStatus = DIO_enuNotOk;
			break;
		}
	}
	
	return Local_u8ErrorStatus;

}

DIO_tenuErrorStatus DIO_enuTogglePin( DIO_tPinValue Copy_u8PinNumber )
{
	DIO_tenuErrorStatus Local_u8ErrorStatus = DIO_enuOk;
	if ( Copy_u8PinNumber > 31)
	{
		Local_u8ErrorStatus = DIO_enuInvalidPinNumber;
	}
	else
	{

		u8 Local_u8PortNumber = Copy_u8PinNumber/NumberOfPin;
		u8 Local_u8PinNumber = Copy_u8PinNumber%NumberOfPin;

		switch (Local_u8PortNumber)
		{
			case (DIO_PORTA):
			TOG_BIT(PORTA,Local_u8PinNumber);
			break;
			case (DIO_PORTB):
			TOG_BIT(PORTB,Local_u8PinNumber);
			break;
			case (DIO_PORTC):
			TOG_BIT(PORTC,Local_u8PinNumber);
			break;
			case (DIO_PORTD):
			TOG_BIT(PORTD,Local_u8PinNumber);
			break;
			default:
			Local_u8ErrorStatus = DIO_enuNotOk;
			break;
		}
	}
	
	return Local_u8ErrorStatus;

}