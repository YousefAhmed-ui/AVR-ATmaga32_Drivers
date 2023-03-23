/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 25/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/


#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define MCUCR    *((volatile u8*)0x55)
#define MCUCSR   *((volatile u8*)0x54)
#define GICR     *((volatile u8*)0x5B)
#define GIFR     *((volatile u8*)0x5A)


#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3


#define MCUCSR_ISC2   6

#define GICR_INTF0    6
#define GICR_INTF1    7
#define GICR_INTF2    5



#endif