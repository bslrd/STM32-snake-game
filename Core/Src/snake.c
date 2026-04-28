#include "snake.h"
#include "stdlib.h"

// game variables

uint8_t GROWTH = 0;
uint8_t MOVE = 0;
uint8_t GAME_OVER = 1;

static snake_state game;

void snake_move()
{

	if(GROWTH)
	{
		game.tail_position_x[game.length] = game.head_position[0];
		game.tail_position_y[game.length] = game.head_position[1];
		game.length++;
		GROWTH = 0;
	}
	else
	{
		game.collision[game.tail_position_x[0]][game.tail_position_y[0]] = 0;
		for(int i = 0; i < game.length-1; i++)
		{
			game.tail_position_x[i] = game.tail_position_x[i+1];
			game.tail_position_y[i] = game.tail_position_y[i+1];
		}
		game.tail_position_x[game.length-1] = game.head_position[0];
		game.tail_position_y[game.length-1] = game.head_position[1];

	}

	game.collision[game.head_position[0]][game.head_position[1]] = 1;

	switch(game.move_direction)
	{
		case UP:
			if(game.prev_move_direction == DOWN)
				{
					game.move_direction = game.prev_move_direction;
					game.head_position[1] -= 1;
				}
			else 	game.head_position[1] += 1;
			break;
		case DOWN:
			if(game.prev_move_direction == UP)
				{
					game.move_direction = game.prev_move_direction;
					game.head_position[1] += 1;
				}
			else 	game.head_position[1] -= 1;
			break;
		case LEFT:
			if(game.prev_move_direction == RIGHT)
				{
					game.move_direction = game.prev_move_direction;
					game.head_position[0] += 1;
				}
			else 	game.head_position[0] -= 1;
			break;
		case RIGHT:
			if(game.prev_move_direction == LEFT)
				{
					game.move_direction = game.prev_move_direction;
					game.head_position[0] -= 1;
				}
			else 	game.head_position[0] += 1;
			break;
	}
	if(game.head_position[0] < 0 || game.head_position[0] >= GAME_DIM || game.head_position[1] < 0 ||game.head_position[1] >= GAME_DIM || game.collision[game.head_position[0]][game.head_position[1]] == 1)
		GAME_OVER = 1;
	game.prev_move_direction = game.move_direction;
}
void fruit_pick_position()
{
	do{
		game.fruit_position[0] = rand()%GAME_DIM;
		game.fruit_position[1] = rand()%GAME_DIM;
	}while((game.length != GAME_SIZE - 1) && (game.collision[game.fruit_position[0]][game.fruit_position[1]]==1 || (game.fruit_position[0] == game.head_position[0] && game.fruit_position[1] == game.head_position[1])));
}
void snake_fruit_check()
{
	if(game.fruit_position[0] == game.head_position[0] && game.fruit_position[1] == game.head_position[1])
	{
		GROWTH = 1;
		fruit_pick_position();
  	}
}

void snake_game_init(int seed)
{
	GAME_OVER = 0;
    GROWTH = 1;
    for(int i = 0; i < GAME_DIM; i++)
    	{
    		for(int j = 0; j < GAME_DIM; j++)
    		{
    			game.collision[i][j] = 0;
    		}
    	}
	game.length = 0;
	game.head_position[0] = 0;
	game.head_position[1] = 0;
	for(int i = 0; i < GAME_SIZE; i++)
	{
		game.tail_position_x[i] = 0;
		game.tail_position_y[i] = 0;
	}
	game.prev_move_direction = RIGHT;
	game.move_direction = RIGHT;
	srand(seed);
	fruit_pick_position();

}

void snake_update_direction(direction mvd)
{
	game.move_direction = mvd;
}

const snake_state* snake_get_state(void)
{
    return &game;
}
