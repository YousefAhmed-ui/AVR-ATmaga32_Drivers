/*************************************************************************************************************************/
/* author : yousef ahmed                                                                                                 */
/* date   : 27/1/2023                                                                                                    */
/* version: V01                                                                                                          */
/*************************************************************************************************************************/ 

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H


#define KEYPAD_PORT      DIO_PORTA

#define KEYPAD_ROW1      DIO_enuPin0       
#define KEYPAD_ROW2      DIO_enuPin1       
#define KEYPAD_ROW3      DIO_enuPin2

#define KEYPAD_COLUMN1   DIO_enuPin3       
#define KEYPAD_COLUMN2   DIO_enuPin4       
#define KEYPAD_COLUMN3   DIO_enuPin5       




#define ROWS_SIZE       3
#define COLUMN_SIZE     3

#define KEYPAD_ARR   {{1,2,3},{4,5,6},{7,8,9}}




#endif