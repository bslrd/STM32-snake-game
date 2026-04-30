/*
 * ws2812b.h
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_

#include "stdint.h"
#include "main.h"

// brightness configuration !!!
#define LED_BRIGHTNESS_SWITCH 1			// use brightness?
#define BRIGHTNESS 2// brightness value 0-100 %


// number of LEDs
#define LED_NUMBER 64


// logic states definition
#define zero 0b1100000
#define one 0b11111000

void ws2812b_init(SPI_HandleTypeDef * spi_handler);
void ws2812b_set_rgb(int16_t diode_id, uint8_t R, uint8_t G, uint8_t B);
void ws2812b_update(void);


#endif /* INC_WS2812B_H_ */
