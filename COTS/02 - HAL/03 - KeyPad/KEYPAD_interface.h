/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 27/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

typedef enum{
    KEYPAD_enuOk,
    KEYPAD_enuNotOk,
    KEYPAD_enuNullPtr
}KEYPAD_enuErrorStatus;


typedef enum
{

	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD

}DIO_typePORT;



KEYPAD_enuErrorStatus KEYPAD_GetKey(u8 * Add_pKeyPressed);


#endif