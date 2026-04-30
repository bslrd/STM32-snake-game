#ifndef WS2812B_MATRIX
#define WS2812B_MATRIX

#include "stdint.h"


// number of LEDs in matrix
#define MATRIX_SIZE 64

// LED matrix dimensions
#define MATRIX_DIM	8

void ws2812b_matrix_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B);
void ws2812b_matrix_fill(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, uint8_t update);

#endif
