/**
 * @file ws2812b_matrix.h
 * @brief ws2812b diode matrix handling module based on ws2812b driver.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#ifndef INC_WS2812B_MATRIX_H_
#define INC_WS2812B_MATRIX_H_

#include <stdint.h>
#include <stdbool.h>


/**
 * @brief Width of the ws2812b matrix.
 */
#define MATRIX_DIM	8

/**
 * @brief Sets diode of chosen coordinates to specified RGB color.
 *
 * @param x horizontal coordinate of chosen diode (0 to MATRIX_DIM -1)
 * @param y vertical coordinate of chosen diode (0 to MATRIX_DIM -1)
 * @param R R value of color (0-255)
 * @param G G value of color (0-255)
 * @param B B value of color (0-255)
 *
 * @note Stores RGB value in internal buffer (ws2812b_color); does not update physical LEDs.
 * @note Coordinate mapping depends on physical wiring (zigzag layout assumed).
 */
void ws2812b_matrix_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B);

/**
 * @brief Fills diode matrix with one chosen color.
 *
 * @param R R value of color (0 to 255)
 * @param G G value of color (0 to 255)
 * @param B B value of color (0 to 255)
 * @param delay value of delay in ms between each diode state change (use only with update = true)
 * @param update specifies if this function should update physical diode state.
 *
 * @note Stores RGB value in internal buffer (ws2812b_color); does not update physical LEDs unless update = true.
 */
void ws2812b_matrix_fill(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, bool update);

#endif /* INC_WS2812B_MATRIX_H_ */
