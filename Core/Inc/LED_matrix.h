#ifndef LED_MATRIX
#define LED_MATRIX

#include "stdint.h"
#include "main.h"

// number of LEDs
#define WS2812B_LEDS 64

// logic states definition
#define zero 0b1000000
#define one 0b11111000

typedef struct ws2812b_color {
  uint8_t red, green, blue;
} ws2812b_color;

extern SPI_HandleTypeDef *hspi_ws2812b;

void LED_init(SPI_HandleTypeDef * spi_handler);
void LED_set_rgb(int16_t diode_id, uint8_t R, uint8_t G, uint8_t B);
void LED_set_coord(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B);
void fill_color(uint8_t R, uint8_t G, uint8_t B, uint8_t delay, uint8_t send);
void LED_update(void);

#endif
