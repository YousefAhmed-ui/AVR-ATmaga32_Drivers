/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 17/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef enum
{

    LED_enuOk = 0,
    LED_enuNotOk,
    LED_enuNullPtr,
    LED_enuInvalidPinNumber

}LED_tenuErrorStatus;


typedef enum
{

    LED_enu0 = 0,
    LED_enu1    ,
    LED_enu2    ,
    LED_enu3    ,
    LED_enu4    ,
    LED_enu5    ,
    LED_enu6    ,
    LED_enu7    ,
    LED_enu8    ,
    LED_enu9    ,
    LED_enu10   ,
    LED_enu11   ,
    LED_enu12   ,
    LED_enu13   ,
    LED_enu14   ,
    LED_enu15   ,
    LED_enu16   ,
    LED_enu17   ,
    LED_enu18   ,
    LED_enu19   ,
    LED_enu20   ,
    LED_enu21   ,
    LED_enu22   ,
    LED_enu23   ,
    LED_enu24   ,
    LED_enu25   ,
    LED_enu26   ,
    LED_enu27   ,
    LED_enu28   ,
    LED_enu29   ,
    LED_enu30   ,
    LED_enu31   ,
    LED_enuNumberOfLeds
}LED_tenuPins;

/*******************4**************************/
/*LED On Funtion
  Input : Copy_u8PinNumber
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/ 
LED_tenuErrorStatus LED_enuOn( LED_tenuPins Copy_u8PinNumber );
/*******************4**************************/
/*LED Off Funtion
  Input : Copy_u8PinNumber
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/ 
LED_tenuErrorStatus LED_enuOff( LED_tenuPins Copy_u8PinNumber );
/*******************4**************************/
/*LED Toggle Funtion
  Input : Copy_u8PinNumber
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/
LED_tenuErrorStatus LED_enuToggle( LED_tenuPins Copy_u8PinNumber );

#endif /*LED_INTERFACE_H*/