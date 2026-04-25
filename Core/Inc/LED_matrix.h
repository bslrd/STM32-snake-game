#ifndef LED_MATRIX
#define LED_MATRIX

#include "stdint.h"
#include "main.h"

// brightness configuration !!!
#define LED_BRIGHTNESS_SWITCH 1			// use brightness?
#define BRIGHTNESS 2// brightness value 0-100 %


// number of LEDs in matrix
#define LED_MATRIX_SIZE 64

// LED matrix dimensions
#define LED_MATRIX_DIM	8

// logic states definition
#define zero 0b1100000
#define one 0b11111000


typedef struct LED_color {
  uint8_t red, green, blue;
} LED_color;

extern SPI_HandleTypeDef *hspi_LED_matrix;

void LED_init(SPI_HandleTypeDef * spi_handler);
void LED_set_rgb(int16_t diode_id, uint8_t R, uint8_t G, uint8_t B);
void LED_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B);
void LED_fill(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, uint8_t send);
void LED_update(void);

#endif
