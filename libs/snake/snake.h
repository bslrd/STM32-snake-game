/**
 * @file snake.h
 * @brief Snake game logic module with low level state machine.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */


#ifndef INC_SNAKE_H_
#define INC_SNAKE_H_

#include <stdint.h>
#include <stdbool.h>
#include "2dspace.h"

// SET GAME DIMENSIONS //

/**
 * @brief Width of the game in snake length units (should be consulted with dispay width).
 */
#define GAME_DIM 8

/**
 * @brief Maximum size that can be occupied by snake body parts.
 */
#define MAX_SNAKE_SIZE (GAME_DIM*GAME_DIM)

/**
 * @brief snake game state type
 */
typedef enum
{
	INIT,
	GAME_OVER,
	RUNNING,
}state_t;

/**
 * @brief Structure holding all snake info.
 */
typedef struct
{
	uint8_t length;
	vec2_t head;
	vec2_t tail[MAX_SNAKE_SIZE];
	vec2_t fruit;
	direction_t move_dir;
	direction_t prev_move_dir;
	bool collision_map[GAME_DIM][GAME_DIM];
	bool GROWTH;
	state_t state;
}snake_state;

/**
 * @brief snake logic state machine function.
 *
 * @details Handles three snake game states (INIT, GAME_OVER, RUNNING).
 *
 * @note Called by game.c state machine.
 */
void snake_update(void);

/**
 * @brief Requests change of current snake direction in state machine.
 *
 * @param requested_direction Direction requested by input system.
 *
 * @note Called by game.c state machine.
 */
void snake_direction_request(direction_t requested_direction);

/**
 * @brief Requests initialization of the snake game in state machine.
 *
 * @param fruit_seed Seed used for random fruit position generator.
 *
 * @note Called by game.c state machine.
 */
void snake_init_request(int fruit_seed);

/**
 * @brief Requests 1-tile move of snake in state machine.
 *
 * @note Called by game.c state machine.
 */
void snake_move_request(void);

/**
 * @brief Checks if snake game state is GAME_OVER.
 */
bool snake_is_over(void);

/**
 * @brief Passes current snake game state.
 *
 * @note The pointer represents valid state until next snake_update() function use.
 */
const snake_state *snake_get_state(void);

#endif /* INC_SNAKE_H_ */
