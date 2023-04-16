/******************************************************************/
/*SPI Driver                */
/* Target:ATMEGA32                       */
/* Yousef_Ahmed                              */
/* Date:2023-04-15                                       */
/******************************************************************/

#include "STD_TYPES.h"
#include "INTERRUPT.h"
#include "SPI.h"

typedef struct{

    u8 SPCR;
    u8 SPSR;
    u8 SPDR;

}SPI_t;


#define SPI            ((volatile SPI_t*const)0x2D)

#define SPIF            7   





static SPI_State_t SendBusyFlag;

static u8* SendBuffer;
 
static u8 SendBufferIndex;
 
static u8 SendBufferSize;
 

static SPI_State_t RecieveBusyFlag;

static u8* RecieveBuffer;
 
static u8 RecieveBufferIndex;
 
static u8 RecieveBufferSize;
 
static SPI_cbf CallBack;


static u8 interrupt;

SPI_Error_t spi_Init(SPI_cfg_t* Config )
{
    SPI_Error_t Local_enuErrorStatus = spi_Ok;

    u8 Local_u8Tmp = 0;

    if(Config == NULL){

        Local_enuErrorStatus = spi_NullPtr;

    }else if(Config->Clock_Phase != spi_CLOCK_PHASE_SAMPLE_SETUP && Config->Clock_Phase != spi_CLOCK_PHASE_SETUP_SAMPLE){

        Local_enuErrorStatus = spi_PhaseError;

    }else if(Config->Clock_Rate > spi_CLOCK_RATE_FREQ_DIVIDED_BY_128){

        Local_enuErrorStatus = spi_ClockError;

    }else if(Config->ClockPol != spi_CLOCK_POLARITY_HIGH && Config->ClockPol != spi_CLOCK_POLARITY_LOW){

        Local_enuErrorStatus = spi_ClockError;

    }else if(Config->Data_Order != spi_DATA_ORDER_LSB_FIRST && Config->Data_Order != spi_DATA_ORDER_MSB_FIRST){

        Local_enuErrorStatus = spi_WrongConfig;

    }else{

        Local_u8Tmp = SPI->SPCR;

        Local_u8Tmp &= ~(spi_ENABLE) | ~(spi_DATA_ORDER_LSB_FIRST) | ~(spi_MASTER_SELECT) | ~(spi_CLOCK_POLARITY_HIGH) | ~(spi_CLOCK_PHASE_SETUP_SAMPLE) | ~(spi_CLOCK_RATE_FREQ_DIVIDED_BY_128);

        Local_u8Tmp |= Config->Clock_Phase | Config->Clock_Rate | Config->ClockPol | Config->Data_Order | Config->Mode | Config->spi_Enable;

        SPI->SPCR = Local_u8Tmp;

        SPI->SPSR |= Config->DoubleSpeed; 

        interrupt = Config->spi_Int;


    }

    return Local_enuErrorStatus;
}


SPI_Error_t spi_TranscieveByteSynch(u8 Copy_u8SendByte , u8* Copy_u8RecieveByte)
{
    SPI_Error_t Local_enuErrorStatus = spi_Ok;

    u16 Local_u16Timeout = 0;

    if(Copy_u8RecieveByte == NULL){

        Local_enuErrorStatus = spi_NullPtr;

    }else{

        SPI->SPDR = Copy_u8SendByte;

        while((!(SPI->SPSR) & (1 << SPIF)) && (Local_u16Timeout < 1000)){

            Local_u16Timeout++;

            if(Local_u16Timeout == 1000){

                Local_enuErrorStatus = spi_TimeOut;

            }

        }

        *Copy_u8RecieveByte = SPI->SPDR;

    }
    return Local_enuErrorStatus;

}



SPI_Error_t spi_SendBufferAsynch(SPI_Send_t* Buffer)
{
    SPI_Error_t Local_enuErrorStatus = spi_Busy;

    if(Buffer == NULL){

        Local_enuErrorStatus = spi_NullPtr;

    }else{

        if(SendBusyFlag == spi_Idle){

            SendBuffer = Buffer->Sendbuffer;

            SendBufferIndex = Buffer->BufferIndex;

            SendBufferSize = Buffer->BufferSize;

            SendBusyFlag = spi_Busy;

            SPI->SPDR |= interrupt;

            SendBufferIndex++;

            Local_enuErrorStatus = spi_Ok;

        }else{

            Local_enuErrorStatus = spi_Busy;

        }

    }

    return Local_enuErrorStatus;
}

SPI_Error_t spi_SetCallBackFunction(SPI_cbf CallBackFunction)
{
    SPI_Error_t Local_enuErrorStatus = spi_Ok;

    if(CallBackFunction){

        CallBack = CallBackFunction;

    }else{

        Local_enuErrorStatus = spi_NullPtr;

    }

    return Local_enuErrorStatus;
}


ISR_ITI(SPI_STC)
{
    if(SPI->SPDR & spi_MASTER_SELECT){

        if( SendBufferIndex < SendBufferSize ){

            SPI->SPDR = SendBuffer[SendBufferIndex];

            SendBufferIndex++;

            SPI->SPSR &= ~(1<<SPIF);

        }else{

            SendBusyFlag = spi_Idle;

            SendBufferSize = 0;

            SPI->SPSR &= ~(1<<SPIF);

            if(CallBack){

                CallBack();

            }


        }


    }

}