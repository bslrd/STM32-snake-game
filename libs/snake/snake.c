/**
 * @file snake.c
 * @brief Implementation of game logic module with low level state machine.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */



#include <stdlib.h>
#include <stdbool.h>
#include "snake.h"


/***********************************/
// STATIC FUNCTION PROTOTYPES
/***********************************/
void snake_move(void);
void snake_fruit_check(void);
void snake_game_init(void);

/***********************************/
// STATE VARIABLES
/***********************************/
static snake_state game = {
	    .state = GAME_OVER,
	    .length = 0,
	    .head = {0,0},
	    .move_dir = RIGHT,
	    .prev_move_dir = RIGHT,
	    .GROWTH = 1};

static direction_t direction_request = NONE;
static bool init_request = 0;
static bool move_request = 0;
static int seed = 0;

/***********************************/
// PUBLIC API
/***********************************/
void snake_update(void)
{
	switch(game.state)
	{
	case INIT:
		snake_game_init();
		game.state = RUNNING;
		break;
	case RUNNING:
		if(direction_request != NONE)
		{
			game.move_dir = direction_request;
			direction_request = NONE;
		}

		if(move_request)
		{
			move_request = 0;
			snake_move();
			snake_fruit_check();
		}
		if(init_request)
		{
			init_request = 0;
			game.state = INIT;
		}
		break;
	case GAME_OVER:
		if(init_request)
		{
			init_request = 0;
			game.state = INIT;
		}
		break;
	}
}

void snake_direction_request(direction_t requested_direction)
{
	direction_request = requested_direction;
}

void snake_init_request(int fruit_seed)
{
	seed = fruit_seed;
	init_request = 1;
}

void snake_move_request(void)
{
	move_request = 1;
}

bool snake_is_over(void)
{
	return game.state == GAME_OVER;
}

const snake_state* snake_get_state(void)
{
    return &game;
}

/***********************************/
// INTERNAL FUNCTIONS
/***********************************/
void snake_move(void)
{
	if(game.GROWTH)
	{
		game.tail[game.length].x = game.head.x;
		game.tail[game.length].y = game.head.y;
		game.length++;
		game.GROWTH = 0;
	}
	else
	{
		game.collision_map[game.tail[0].x][game.tail[0].y] = 0;
		for(int i = 0; i < game.length-1; i++)
		{
			game.tail[i].x = game.tail[i+1].x;
			game.tail[i].y = game.tail[i+1].y;
		}
		game.tail[game.length-1].x = game.head.x;
		game.tail[game.length-1].y = game.head.y;

	}

	game.collision_map[game.head.x][game.head.y] = 1;

	switch(game.move_dir)
	{
		case UP:
			if(game.prev_move_dir == DOWN)
				{
					game.move_dir = game.prev_move_dir;
					game.head.y -= 1;
				}
			else 	game.head.y += 1;
			break;
		case DOWN:
			if(game.prev_move_dir == UP)
				{
					game.move_dir = game.prev_move_dir;
					game.head.y += 1;
				}
			else 	game.head.y -= 1;
			break;
		case LEFT:
			if(game.prev_move_dir == RIGHT)
				{
					game.move_dir = game.prev_move_dir;
					game.head.x += 1;
				}
			else 	game.head.x -= 1;
			break;
		case RIGHT:
			if(game.prev_move_dir == LEFT)
				{
					game.move_dir = game.prev_move_dir;
					game.head.x -= 1;
				}
			else 	game.head.x += 1;
			break;
	}
	if(game.head.x < 0 || game.head.x >= GAME_DIM || game.head.y < 0 ||game.head.y >= GAME_DIM || game.collision_map[game.head.x][game.head.y] == 1)
		game.state = GAME_OVER;
	game.prev_move_dir = game.move_dir;
}

void fruit_pick_position(void)
{
	do{
		game.fruit.x = rand()%GAME_DIM;
		game.fruit.y = rand()%GAME_DIM;
	}while((game.length != MAX_SNAKE_SIZE - 1) && (game.collision_map[game.fruit.x][game.fruit.y]==1 || (game.fruit.x == game.head.x && game.fruit.y == game.head.y)));
}

void snake_fruit_check(void)
{
	if(game.fruit.x == game.head.x && game.fruit.y == game.head.y)
	{
		game.GROWTH = 1;
		fruit_pick_position();
  	}
}

void snake_game_init(void)
{
    for(int i = 0; i < GAME_DIM; i++)
	{
		for(int j = 0; j < GAME_DIM; j++)
		{
			game.collision_map[i][j] = 0;
		}
	}
    game.GROWTH = 1;
	game.length = 0;
	game.head.x = 0;
	game.head.y = 0;
	for(int i = 0; i < MAX_SNAKE_SIZE; i++)
	{
		game.tail[i].x = 0;
		game.tail[i].y = 0;
	}
	game.prev_move_dir = RIGHT;
	game.move_dir = RIGHT;
	srand(seed);
	fruit_pick_position();
}

