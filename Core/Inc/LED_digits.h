
#ifndef LED_DIGITS
#define LED_DIGITS

#include "stdint.h"
#include "LED_matrix.h"

void led_digits(int number, int R, int G, int B);
void led_symbole(const uint8_t symbole[LED_MATRIX_DIM][LED_MATRIX_DIM], int R, int G, int B, int x_offset, int y_offset);

#endif
