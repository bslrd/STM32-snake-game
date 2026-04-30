#include "ws2812b_matrix.h"
#include "ws2812b.h"

void ws2812b_matrix_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B)
{
	ws2812b_set_rgb(x+(MATRIX_DIM-1-y)*MATRIX_DIM,R,G,B);
}


void ws2812b_matrix_fill(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, uint8_t update)
{
	if(delay)
	{
		for(int i = 0; i < MATRIX_SIZE; i++)
		{
			ws2812b_set_rgb(i,R,G,B);
			if(update)
			ws2812b_update();
			HAL_Delay(delay);
		}
	}
	else
	{
		for(int i = 0; i < MATRIX_SIZE; i++)
		{
			ws2812b_set_rgb(i,R,G,B);
		}
		if(update)
		ws2812b_update();
	}
}
