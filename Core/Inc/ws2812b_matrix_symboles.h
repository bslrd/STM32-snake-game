
#ifndef WS2812B_MATRIX_SYMBOLES
#define WS2812B_MATRIX_SYMBOLES

#include "ws2812b_matrix.h"
#include "stdint.h"

void ws2812b_matrix_digits(int number, int R, int G, int B);
void ws2812b_matrix_symboles(const uint8_t symbole[MATRIX_DIM][MATRIX_DIM], int R, int G, int B, int x_offset, int y_offset, int rotated);

#endif
