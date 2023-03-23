/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 25/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 




#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum{
    EXTI_enuOk = 0,
    EXTI_enuInValidIntNum,
    EXTI_InValidSenseMode
}EXTI_enuErrorStatus_t;




EXTI_enuErrorStatus_t EXTI_enuInitInt(void);



EXTI_enuErrorStatus_t EXTI_enuEnableInterrupt(u8 Copy_u8IntNum);




#endif