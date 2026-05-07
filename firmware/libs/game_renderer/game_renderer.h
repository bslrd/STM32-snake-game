/**
 * @file game_renderer.h
 *
 * @brief Snake rendering module dedicated for ws2812b matrix display.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#ifndef INC_GAME_RENDERER_H_
#define INC_GAME_RENDERER_H_

#include "snake.h"
#include "game.h"

/**
 * @brief Renders the snake on the LED matrix.
 *
 * @param game pointer to current snake state used for rendering.
 *
 * @note color scheme is defined inside snake_renderer.c.
 */
void render_snake(const snake_state *game);


/**
 * @brief Renders game menu on the LED matrix.
 *
 * @param game pointer to current snake state used for rendering.
 *
 * @note color scheme is defined inside snake_renderer.c.
 */
void render_menu(const snake_state *game);


/**
 * @brief Renders game start animation on the LED matrix.
 *
 * @note color scheme is defined inside snake_renderer.c.
 */
void render_start(void);

#endif /* INC_GAME_RENDERER_H_ */
