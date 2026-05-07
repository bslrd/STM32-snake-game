/**
 * @file game.c
 * @brief Implementation of high-level game state machine module.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#include <stdbool.h>
#include "game.h"
#include "snake.h"
#include "Joystick.h"
#include "game_renderer.h"


/***********************************/
// STATIC FUNCTION PROTOTYPES
/***********************************/
static void game_menu(void);
static void game_run(void);

/***********************************/
// STATE VARIABLES
/***********************************/
static enum
  {
	  MENU,
	  GAME
  }GAME_STATE = MENU;

static bool tick_request = 0;
static bool start_request = 0;
static int seed = 0;

/***********************************/
// PUBLIC API
/***********************************/
void game_loop(void)
{
	switch(GAME_STATE)
	{
		case MENU:
			game_menu();
			break;
		case GAME:
			game_run();
		    break;
	}
	snake_update();
}

void game_init(void)
{
	render_menu(snake_get_state());
}

void game_start_request(int game_seed)
{
	if(GAME_STATE == MENU)
	{
		seed = game_seed;
		start_request = 1;
	}
}

void game_tick_request(void)
{
	if(GAME_STATE == GAME)
		tick_request = 1;
}

/***********************************/
// INTERNAL FUNCTIONS
/***********************************/
void game_menu(void)
{
	if(start_request)
	{
	  start_request = 0;
	  snake_init_request(seed);
	  snake_update();
	  GAME_STATE = GAME;
	  render_start();

	}
}

void game_run(void)
{
	snake_direction_request(joystick_get_direction());
	if(tick_request)
	{
		tick_request = 0;
		snake_move_request();
	}

	if(snake_is_over())
	{
		GAME_STATE = MENU;
		render_menu(snake_get_state());
		return;
	}
	render_snake(snake_get_state());

}
