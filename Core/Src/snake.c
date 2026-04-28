#include "snake.h"
#include "stdlib.h"

// game variables



static snake_state game;

void snake_move()
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
		game.collision[game.tail[0].x][game.tail[0].y] = 0;
		for(int i = 0; i < game.length-1; i++)
		{
			game.tail[i].x = game.tail[i+1].x;
			game.tail[i].y = game.tail[i+1].y;
		}
		game.tail[game.length-1].x = game.head.x;
		game.tail[game.length-1].y = game.head.y;

	}

	game.collision[game.head.x][game.head.y] = 1;

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
	if(game.head.x < 0 || game.head.x >= GAME_DIM || game.head.y < 0 ||game.head.y >= GAME_DIM || game.collision[game.head.x][game.head.y] == 1)
		game.GAME_OVER = 1;
	game.prev_move_dir = game.move_dir;
}
void fruit_pick_position()
{
	do{
		game.fruit.x = rand()%GAME_DIM;
		game.fruit.y = rand()%GAME_DIM;
	}while((game.length != GAME_SIZE - 1) && (game.collision[game.fruit.x][game.fruit.y]==1 || (game.fruit.x == game.head.x && game.fruit.y == game.head.y)));
}
void snake_fruit_check()
{
	if(game.fruit.x == game.head.x && game.fruit.y == game.head.y)
	{
		game.GROWTH = 1;
		fruit_pick_position();
  	}
}

void snake_game_init(int seed)
{
	game.GAME_OVER = 0;
    game.GROWTH = 1;
    for(int i = 0; i < GAME_DIM; i++)
    	{
    		for(int j = 0; j < GAME_DIM; j++)
    		{
    			game.collision[i][j] = 0;
    		}
    	}
	game.length = 0;
	game.head.x = 0;
	game.head.y = 0;
	for(int i = 0; i < GAME_SIZE; i++)
	{
		game.tail[i].x = 0;
		game.tail[i].y = 0;
	}
	game.prev_move_dir = RIGHT;
	game.move_dir = RIGHT;
	srand(seed);
	fruit_pick_position();

}

void snake_update_direction(direction mvd)
{
	game.move_dir = mvd;
}

const snake_state* snake_get_state(void)
{
    return &game;
}
