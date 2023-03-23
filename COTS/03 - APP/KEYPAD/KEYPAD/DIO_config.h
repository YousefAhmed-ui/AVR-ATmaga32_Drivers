/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 13/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#include "STD_TYPES.h"


#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

#define DIO_DIR_OUTPUT  1
#define DIO_DIR_INPUT   0

#define DIO_INPUT_PULL_UP       0
#define DIO_INPUT_PULL_DOWN     1

#define NumberOfPin       8
#define MAX_NUM_OF_PINS   31

typedef struct 
{
    u8 DIO_PinDirection;
    u8 DIO_InputStatus;
}DIO_strPinConfig_t;


extern const DIO_strPinConfig_t DIO_strPinConfig[32];




#endif /*DIO_COFIG_H*/



