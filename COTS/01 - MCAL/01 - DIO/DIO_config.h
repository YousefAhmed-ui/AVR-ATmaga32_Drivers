/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 13/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

#define DIO_DIR_OUTPUT  1
#define DIO_DIR_INPUT   0

#define DIO_INPUT_PULL_UP       0
#define DIO_INPUT_PULL_DOWN     1


typedef struct 
{
    u8 DIO_PinDirection;
    u8 DIO_InputStatus;
}DIO_strPinConfig_t;




const DIO_strPinConfig_t DIO_strPinConfig[32] =
{
    /*PORTA*/   /*PULL UP*/       /* PULL DOWN*/
    /*PIN0*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN1*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN2*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN3*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN4*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN5*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN6*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN7*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},

    /*PORTB*/   /*PULL UP*/       /* PULL DOWN*/
    /*PIN8*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN9*/ {DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN10*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN11*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN12*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN13*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN14*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN15*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},

    /*PORTC*/   /*PULL UP*/       /* PULL DOWN*/
    /*PIN16*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN17*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN18*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN19*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN20*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN21*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN22*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN23*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},

    /*PORTD*/   /*PULL UP*/       /* PULL DOWN*/
    /*PIN24*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN25*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN26*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN27*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN28*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN29*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN30*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
    /*PIN31*/{DIO_DIR_OUTPUT, DIO_INPUT_PULL_DOWN},
};


#endif /*DIO_COFIG_H*/



