/**
 * @file ws2812b_matrix_symbols.h
 * @brief ws2812b diode matrix symbols display module.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#ifndef INC_WS2812B_MATRIX_SYMBOLS_H
#define INC_WS2812B_MATRIX_SYMBOLS_H

#include <stdint.h>
#include <stdbool.h>
#include "ws2812b_matrix.h"


/**
 * @brief displays two digit numbers on led matrix.
 *
 * @param number Number to display (0-99)
 * @param R R value of color (0-255)
 * @param G G value of color (0-255)
 * @param B B value of color (0-255)
 *
 * @note predefined digits are created for 8x8 matrix display.
 */
void ws2812b_matrix_digits(int number, int R, int G, int B);

/**
 * @brief displays a symbol on led matrix.
 *
 * @param symbol Symbol defined as two dimensional matrix of values 0 and 1 (0 - led off, 1 - led on)
 * @param R R value of color (0-255)
 * @param G G value of color (0-255)
 * @param B B value of color (0-255)
 */
void ws2812b_matrix_symboles(const bool symbole[MATRIX_DIM][MATRIX_DIM], int R, int G, int B, int x_offset, int y_offset, bool rotated);

#endif /* INC_WS2812B_MATRIX_SYMBOLS_H_ */
