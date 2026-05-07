/**
 * @file ws2812b_matrix.c
 * @brief Implementation of ws2812b diode matrix handling module.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#include "ws2812b.h"
#include "ws2812b_matrix.h"

void ws2812b_matrix_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B)
{
	ws2812b_set_rgb(x+(MATRIX_DIM-1-y)*MATRIX_DIM,R,G,B);
}


void ws2812b_matrix_fill(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, bool update)
{
	if(delay)
	{
		for(int i = 0; i < LED_NUMBER; i++)
		{
			ws2812b_set_rgb(i,R,G,B);
			if(update)
			ws2812b_update();
			HAL_Delay(delay);
		}
	}
	else
	{
		for(int i = 0; i < LED_NUMBER; i++)
		{
			ws2812b_set_rgb(i,R,G,B);
		}
		if(update)
		ws2812b_update();
	}
}
