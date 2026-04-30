/*
 * ws2812b.c
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */

#include "ws2812b.h"

static SPI_HandleTypeDef *hspi_ws2812b;



typedef struct{
  uint8_t red, green, blue;
} ws2812b_color;

static ws2812b_color ws2812b_array[LED_NUMBER];

void ws2812b_init(SPI_HandleTypeDef * spi_handler)
{
	hspi_ws2812b = spi_handler;
}

void ws2812b_set_rgb(int16_t diode_id, uint8_t R, uint8_t G, uint8_t B)
{
	if(diode_id >= LED_NUMBER || diode_id < 0) return;
	ws2812b_array[diode_id].red = R * BRIGHTNESS/100.0;
	ws2812b_array[diode_id].green = G * BRIGHTNESS/100.0;
	ws2812b_array[diode_id].blue = B * BRIGHTNESS/100.0;
}


void ws2812b_update()
{
	static uint8_t buffer[LED_NUMBER*24+120];

	for(uint8_t i = 0; i < 120; i++)
		buffer[i] = 0x00;

	for(uint16_t i=0, j=120; i<LED_NUMBER; i++)
	{
		//GREEN
		for(int8_t k=7; k>=0; k--)
		{
			if((ws2812b_array[i].green & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}

		//RED
		for(int8_t k=7; k>=0; k--)
		{
			if((ws2812b_array[i].red & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}

		//BLUE
		for(int8_t k=7; k>=0; k--)
		{
			if((ws2812b_array[i].blue & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}
	}


	HAL_SPI_Transmit(hspi_ws2812b, buffer, LED_NUMBER* 24 + 120, 1000);
}
