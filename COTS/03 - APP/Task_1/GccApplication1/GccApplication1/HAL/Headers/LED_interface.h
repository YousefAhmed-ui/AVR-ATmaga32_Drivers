/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 17/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "DIO_interface.h"

/*******************4**************************/
/*LED On Funtion
  Input : Copy_u8PinNumber
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/ 
DIO_tenuErrorStatus LED_enuOn( DIO_tenuPins Copy_u8PinNumber );
/*******************4**************************/
/*LED Off Funtion
  Input : Copy_u8PinNumber
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/ 
DIO_tenuErrorStatus LED_enuOff( DIO_tenuPins Copy_u8PinNumber );
/*******************4**************************/
/*LED Toggle Funtion
  Input : Copy_u8PinNumber
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/
DIO_tenuErrorStatus LED_enuToggle( DIO_tenuPins Copy_u8PinNumber );

#endif /*LED_INTERFACE_H*/