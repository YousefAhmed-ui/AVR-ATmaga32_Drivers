/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 20/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 

#ifndef SEV_SEG_CONFIG_H
#define SEV_SEG_CONFIG_H


#define Sev_Seg_AH   1
#define Sev_Seg_AL   0



typedef enum
{

	Sev_Seg_PORTA = 0,
	Sev_Seg_PORTB,
	Sev_Seg_PORTC,
	Sev_Seg_PORTD,
    Sev_Seg_PORT_NUM


}Seven_Seg_typePORT;



    /*Active High*/
#define Zero_AH    0b00000000
#define One_AH     0b00000001
#define Two_AH     0b00000010
#define Three_AH   0b00000011
#define Four_AH    0b00000100
#define Five_AH    0b00000101
#define Six_AH     0b00000110
#define Seven_AH   0b00000111
#define Eight_AH   0b00001000
#define Nine_AH    0b00001001



typedef enum
{

    Sev_Seg_enuOk = 0,
    Sev_Seg_enuNotOk,
    Sev_Seg_enuNullPtr,
    Sev_Seg_enuInvalidPinNumber

}Sev_Seg_tenuErrorStatus;

extern const u8 Sev_Seg_Nums[10] ;

#define MAX_PORT_VAL  255


/***********************************************/
/*seven seg display Function
  Input : Pin Number (0 -> 31)
  Output : DIO_tenuErrorStatus to report error */
/***********************************************/

Sev_Seg_tenuErrorStatus Sev_Seg_enuDisplay_Num( u8 Copy_u8Port , u8 Copy_u8Number);


#endif