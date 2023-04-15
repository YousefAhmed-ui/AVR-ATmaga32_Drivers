/*
 * SPI_Trial.c
 *
 * Created: 16/04/2023 12:58:10 ص
 * Author : El-Wattaneya
 */ 

#include "STD_TYPES.h"
#include "SPI.h"


int main(void)
{
    SPI_cfg_t cfg = {
		
		.spi_Enable = spi_ENABLE,
		
	};
	spi_Init(&cfg);
		
	
    while (1) 
    {
    }
}

