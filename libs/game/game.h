/**
 * @file game.h
 * @brief High-level game state machine module controlling application flow.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */


#ifndef INC_GAME_H_
#define INC_GAME_H_

/**
 * @brief Main game state machine function.
 *
 * @details Handles two application states (MENU, GAME).
 *
 * @note Should be called from main() while loop.
 */
void game_loop(void);

/**
 * @brief Main game init function.
 *
 * @note Should be called from main() to initialize first menu.
 */
void game_init(void);

/**
 * @brief Requests start of the game in state machine.
 *
 * @param game_seed Seed used for random fruit position generator.
 *
 * @note Should be called from start button interrupt.
 */
void game_start_request(int game_seed);

/**
 * @brief Requests one tick game progression (one snake move) in state machine.
 *
 * @note Should be called from timer interrupt with desired snake movement frequency.
 */
void game_tick_request(void);

#endif /* INC_GAME_H_ */
