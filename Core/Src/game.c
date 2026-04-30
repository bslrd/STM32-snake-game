/*
 * game.c
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */

#include <snake_renderer.h>
#include "game.h"
#include "LED_matrix.h"
#include "LED_digits.h"
#include "snake.h"
#include "stdbool.h"
#include "Joystick.h"

static enum
  {
	  MENU,
	  GAME
  }API_STATE;

volatile static bool tick = 0;
volatile static bool start_request = 0;

void game_start_request()
{
	start_request = 1;
}
void game_tick()
{
	if(API_STATE == GAME)
	tick = 1;
}
void game_init()
{
	LED_fill(255,0,0,10,1);
	LED_digits(00,255,255,255);
	LED_update();
}
void game_loop()
{
	switch(API_STATE)
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

void game_menu()
{
	if(start_request)
	{
	  start_request = 0;
	  API_STATE = GAME;
	  LED_fill(0,0,0,10,1);
	  snake_init_request();
	}
}

void game_run()
{
	joystick_read();
	if(joystick_check_tilt())
	{
		snake_update_direction(joystick_get_direction());
	}
	if(tick)
	{
		tick = 0;
		snake_move_request();
	}
	render_snake(snake_get_state());
	if(snake_is_over())
	{
		API_STATE = MENU;
		render_menu(snake_get_state());
	}
}
