/**
 * @file ws2812b.c
 * @brief Implementation of ws2812b diodes handling module (STM32 HAL).
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#include "ws2812b.h"

/***********************************/
// CONFIGURATION
/***********************************/
#define BRIGHTNESS_MODE 2			// 0 - OFF, 1 - Dont preserve colors, 2 - preserve colors
#define BRIGHTNESS 0.5				// 0 to 100 [%]
static SPI_HandleTypeDef *hspi_ws2812b;

/***********************************/
// WS2812B LOGIC STATES
/***********************************/
#define zero 0b1100000
#define one 0b11111000

/***********************************/
// COLOR STRUCTURE
/***********************************/
typedef struct{
  uint8_t red, green, blue;
} ws2812b_color;
static ws2812b_color ws2812b_array[LED_NUMBER];

/***********************************/
// PUBLIC API
/***********************************/
void ws2812b_init(SPI_HandleTypeDef * spi_handler)
{
	hspi_ws2812b = spi_handler;
}

void ws2812b_set_rgb(uint16_t diode_id, uint8_t R, uint8_t G, uint8_t B)
{
	if(diode_id >= LED_NUMBER) return;
	uint8_t brightness_multiplier = 1;
	switch(BRIGHTNESS_MODE)
	{
	case 0:
		brightness_multiplier = 1;
		break;
	case 1:
		brightness_multiplier = 100.0/BRIGHTNESS;
		break;
	case 2:
		uint8_t min = 0;
		if (R != 0) min = R;
		if (G != 0 && (min == 0 || G < min)) min = G;
		if (B != 0 && (min == 0 || B < min)) min = B;

		if(min)
		{
			uint8_t min_changed = min * BRIGHTNESS/100.0;
			if(!min_changed)
			{
				min_changed = 1;
			}
			brightness_multiplier = min/min_changed;
		}
		break;
	}
	ws2812b_array[diode_id].red = R/brightness_multiplier;
	ws2812b_array[diode_id].green = G/brightness_multiplier;
	ws2812b_array[diode_id].blue = B/brightness_multiplier;
}

void ws2812b_update(void)
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
