/******************************************************************/
/*UART Driver                */
/* Target:ATmega32                       */
/* Yousef_Ahmed                              */
/* Date:2023-04-03                                       */
/******************************************************************/
#include "STD_TYPES.h"


#define   UCSRC    *((volatile u8 *const)0x40)
#define   UBRRH    *((volatile u8 *const)0x40)

typedef struct{

    u8 UBRRL;
    u8 UCSRB;
    u8 UCSRA;
    u8 UDR;
     
}UART_t;





