#include "LED_matrix.h"

LED_color LED_array[LED_MATRIX_SIZE];
SPI_HandleTypeDef *hspi_LED_matrix;

static uint8_t buffer[LED_MATRIX_SIZE*24+120];

void LED_init(SPI_HandleTypeDef * spi_handler)
{
	hspi_LED_matrix = spi_handler;
}

void LED_set_rgb(int16_t diode_id, uint8_t R, uint8_t G, uint8_t B)
{
	if(diode_id >= LED_MATRIX_SIZE || diode_id < 0) return;
	LED_array[diode_id].red = R * BRIGHTNESS/100.0;
	LED_array[diode_id].green = G * BRIGHTNESS/100.0;
	LED_array[diode_id].blue = B * BRIGHTNESS/100.0;
}

void LED_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B)
{
	LED_set_rgb(x+y*LED_MATRIX_DIM,R,G,B);
}

void LED_update()
{



	for(uint8_t i = 0; i < 120; i++)
		buffer[i] = 0x00;

	for(uint16_t i=0, j=120; i<LED_MATRIX_SIZE; i++)
	{
		//GREEN
		for(int8_t k=7; k>=0; k--)
		{
			if((LED_array[i].green & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}

		//RED
		for(int8_t k=7; k>=0; k--)
		{
			if((LED_array[i].red & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}

		//BLUE
		for(int8_t k=7; k>=0; k--)
		{
			if((LED_array[i].blue & (1<<k)) == 0)
				buffer[j] = zero;
			else
				buffer[j] = one;
			j++;
		}
	}


	HAL_SPI_Transmit(hspi_LED_matrix, buffer, LED_MATRIX_SIZE* 24 + 120, 1000);
}

void LED_fill(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, uint8_t send)
{
	if(delay)
	{
		for(int i = 0; i < LED_MATRIX_SIZE; i++)
		{
			LED_set_rgb(i,R,G,B);
			if(send)
			LED_update();
			HAL_Delay(delay);
		}
	}
	else
	{
		for(int i = 0; i < LED_MATRIX_SIZE; i++)
		{
			LED_set_rgb(i,R,G,B);
		}
		if(send)
		LED_update();
	}
}
