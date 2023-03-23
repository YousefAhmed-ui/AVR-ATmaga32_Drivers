/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 13/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum
{

    DIO_enuOk = 0,
    DIO_enuNotOk,
    DIO_enuNullPtr,
    DIO_enuInvalidPinNumber

}DIO_tenuErrorStatus;


typedef enum
{

    DIO_enuPin0 = 0,
    DIO_enuPin1    ,
    DIO_enuPin2    ,
    DIO_enuPin3    ,
    DIO_enuPin4    ,
    DIO_enuPin5    ,
    DIO_enuPin6    ,
    DIO_enuPin7    ,
    DIO_enuPin8    ,
    DIO_enuPin9    ,
    DIO_enuPin10   ,
    DIO_enuPin11   ,
    DIO_enuPin12   ,
    DIO_enuPin13   ,
    DIO_enuPin14   ,
    DIO_enuPin15   ,
    DIO_enuPin16   ,
    DIO_enuPin17   ,
    DIO_enuPin18   ,
    DIO_enuPin19   ,
    DIO_enuPin20   ,
    DIO_enuPin21   ,
    DIO_enuPin22   ,
    DIO_enuPin23   ,
    DIO_enuPin24   ,
    DIO_enuPin25   ,
    DIO_enuPin26   ,
    DIO_enuPin27   ,
    DIO_enuPin28   ,
    DIO_enuPin29   ,
    DIO_enuPin30   ,
    DIO_enuPin31   ,
    DIO_enuNumberOfPins
}DIO_tenuPins;




typedef enum
{
    DIO_enuLow = 0,
    DIO_enuHigh
}DIO_tPinValue;

/*******************4**************************/
/*DIO Init Funtion
  Input : void
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/  

DIO_tenuErrorStatus DIO_enuInit(void);

/***********************************************/
/*DIO Set Pin Function
  Input : Pin Number (0 -> 31)
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/

DIO_tenuErrorStatus DIO_enuSetPin(DIO_tPinValue Copy_u8PinNumber, DIO_tPinValue Copy_enuPinValue);

/***********************************************/
/*DIO Clear Pin Function
  Input : Pin Number (0 -> 31)
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/

//DIO_tenuErrorStatus DIO_enuClearPin(DIO_tPinValue Copy_u8PinNumber);
/***********************************************/
/*DIO Get Pin Function
  Input : Pin Number (0 -> 31)
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/

DIO_tenuErrorStatus DIO_enuGetPin(DIO_tPinValue Copy_u8PinNumber ,u8 * Add_pu8PinValue);


DIO_tenuErrorStatus DIO_enuTogglePin( DIO_tPinValue Copy_u8PinNumber );



DIO_tenuErrorStatus DIO_enuSetPort( u8 Copy_u8Port , u8 Copy_u8Value);




#endif /*DIO_INTERFACE*/