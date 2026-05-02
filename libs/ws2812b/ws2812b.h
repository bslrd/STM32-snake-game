/**
 * @file ws2812b.h
 * @brief ws2812b diodes handling module based on SPI (STM32 HAL).
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_

#include <stdint.h>
#include "main.h"

/**
 * @brief Number of LEDs in the module.
 */
#define LED_NUMBER 64


/**
 * @brief Initializes ws2812b handling module by passing given SPI handler.
 *
 * @param spi_handler pointer to spi handler of choice.
 *
 * @note Should be called from main() before use of other ws2812b functions
 */
void ws2812b_init(SPI_HandleTypeDef * spi_handler);

/**
 * @brief Sets chosen diode to specified RGB color.
 *
 * @param diode_id Index of LED (0 to LED_NUMBER-1).
 * @param R R value of color (0 to 255)
 * @param G G value of color (0 to 255)
 * @param B B value of color (0 to 255)
 *
 * @note Stores RGB value in internal buffer (ws2812b_color); does not update physical LEDs.
 */
void ws2812b_set_rgb(uint16_t diode_id, uint8_t R, uint8_t G, uint8_t B);

/**
 * @brief Transfers diode color values specified with ws2812b_set_rgb to physical display.
 */
void ws2812b_update(void);


#endif /* INC_WS2812B_H_ */
