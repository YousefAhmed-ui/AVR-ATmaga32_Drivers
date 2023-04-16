/*******************************************************************/
/*         SPI Driver        */
/* Target:ATMEGA32                       */
/*Author :Yousef_Ahmed                         */
/*Date   :2023-04-15                                      */
/*******************************************************************/

#ifndef _SPI_H
#define _SPI_H

/***************************************macros*************************************************/

#define spi_INT_ENABLE                                           0x80
                 
#define spi_ENABLE                                               0x40
                 
#define spi_DATA_ORDER_LSB_FIRST                                 0x20
#define spi_DATA_ORDER_MSB_FIRST                                 0x00
                 
#define spi_MASTER_SELECT                                        0x10
#define spi_SLAVE_SELECT                                         0x00
                 
#define spi_CLOCK_POLARITY_HIGH                                  0x08  // leading edge falling - trailing edge rising
#define spi_CLOCK_POLARITY_LOW                                   0x00  // the other way around 
                 
#define spi_CLOCK_PHASE_SAMPLE_SETUP                             0x00
#define spi_CLOCK_PHASE_SETUP_SAMPLE                             0x04
                 
#define spi_CLOCK_RATE_FREQ_DIVIDED_BY_4                         0x00
#define spi_CLOCK_RATE_FREQ_DIVIDED_BY_16                        0x01
#define spi_CLOCK_RATE_FREQ_DIVIDED_BY_64                        0x02
#define spi_CLOCK_RATE_FREQ_DIVIDED_BY_128                       0x03

#define spi_DOUBLE_SPEED_EN                                      0x01



/***************************************types***************************************************/

typedef enum{

    spi_Ok,
    spi_NullPtr,
    spi_WrongConfig,
    spi_PhaseError,
    spi_ClockError,
    spi_TimeOut


}SPI_Error_t;


typedef enum{

    spi_Idle,
    spi_Busy

}SPI_State_t;

typedef struct{

    u8* Sendbuffer;
    u8 BufferIndex;
    u8 BufferSize;

}SPI_Send_t;

typedef struct{

    u8* Recievebuffer;
    u8 BufferIndex;
    u8 BufferSize;

}SPI_Recieve_t;

typedef struct{

    u8 spi_Int;
    u8 spi_Enable;
    u8 Data_Order;
    u8 Mode;
    u8 ClockPol;
    u8 Clock_Phase;
    u8 Clock_Rate;
    u8 DoubleSpeed;

}SPI_cfg_t;

typedef void (*SPI_cbf)(void);

/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/ 
extern SPI_Error_t spi_Init(SPI_cfg_t* Config );
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
extern SPI_Error_t spi_TranscieveByteSynch(u8 Copy_u8SendByte , u8* Copy_u8RecieveByte);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
extern SPI_Error_t spi_TranscieveBufferAsynch(SPI_Send_t* SendBuffer , SPI_Recieve_t RecieveBuffer);
/*************************************************************************************************************************/
/* FunctionDiscription  :                                                                                                */
/* Inputs  :                                                                                                             */
/* Return :                                                                                                              */
/*************************************************************************************************************************/
extern SPI_Error_t spi_SetCallBackFunction(SPI_cbf CallBackFunction);

#endif /*SPI_H*/
