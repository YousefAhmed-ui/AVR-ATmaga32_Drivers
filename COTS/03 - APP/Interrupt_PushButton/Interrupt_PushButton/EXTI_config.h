/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 25/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

#include "STD_TYPES.h"

#define LowLevel        0
#define OnChange        1
#define FallingEdge     2
#define RisingEdge      3
#define MAX_MODES       4

#define INT0_LOWLEVEL         0b00000000
#define INT0_ONCHANGE         0b00000001
#define INT0_FALLINGEDGE      0b00000010
#define INT0_RISINGEDGE       0b00000011

#define INT1_LOWLEVEL         0b00000000
#define INT1_ONCHANGE         0b00000100
#define INT1_FALLINGEDGE      0b00001000
#define INT1_RISINGEDGE       0b00001100

#define INT2_FALLINEDGE       0b00000000
#define INT2_RISINGEDGE       0b01000000

#define INT0_MODE            INT0_RISINGEDGE
#define INT1_MODE            INT1_RISINGEDGE
#define INT2_MODE            INT2_RISINGEDGE



typedef struct{
	u8 INT_Num;
	u8 INT_SenseMode;
}EXTI_INT_t;

#define INT0  0
#define INT1  1
#define INT2  2
#define EXTI_Num  3





#endif