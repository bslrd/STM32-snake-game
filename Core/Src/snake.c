#include "snake.h"
#include "stdlib.h"

// game variables
uint8_t length = 1;
int head_position[2]={0};
uint8_t tail_x[GAME_SIZE] = {0};
uint8_t tail_y[GAME_SIZE] = {0};
static direction move_direction = RIGHT;
direction prev_move_direction = RIGHT;
uint8_t fruit_position[2]={0};
uint8_t collision[GAME_DIM][GAME_DIM]={0};
uint8_t GROWTH = 0;
uint8_t MOVE = 0;
uint8_t GAME_OVER = 1;

void snake_move()
{
	if(GROWTH)
	{
		tail_x[length] = head_position[0];
		tail_y[length] = head_position[1];
		length++;
		GROWTH = 0;
	}
	else
	{
		for(int i = 0; i < length-1; i++)
		{
			tail_x[i] = tail_x[i+1];
			tail_y[i] = tail_y[i+1];
		}
		tail_x[length-1] = head_position[0];
		tail_y[length-1] = head_position[1];
	}

	switch(move_direction)
	{
		case UP:
			if(prev_move_direction == DOWN)
				{
					move_direction = prev_move_direction;
					head_position[1] -= 1;
				}
			else 	head_position[1] += 1;
			break;
		case DOWN:
			if(prev_move_direction == UP)
				{
					move_direction = prev_move_direction;
					head_position[1] += 1;
				}
			else 	head_position[1] -= 1;
			break;
		case LEFT:
			if(prev_move_direction == RIGHT)
				{
					move_direction = prev_move_direction;
					head_position[0] += 1;
				}
			else 	head_position[0] -= 1;
			break;
		case RIGHT:
			if(prev_move_direction == LEFT)
				{
					move_direction = prev_move_direction;
					head_position[0] -= 1;
				}
			else 	head_position[0] += 1;
			break;
	}
	if(head_position[0] < 0) head_position[0] = 0;
	if(head_position[0] >= GAME_DIM) head_position[0] = GAME_DIM-1;
	if(head_position[1] < 0) head_position[1] = 0;
	if(head_position[1] >= GAME_DIM) head_position[1] = GAME_DIM-1;

	prev_move_direction = move_direction;
}

void snake_fruit_check()
{
	if(fruit_position[0] == head_position[0] && fruit_position[1] == head_position[1])
	{
		GROWTH = 1;
		do{
			fruit_position[0] = rand()%GAME_DIM;
			fruit_position[1] = rand()%GAME_DIM;
		}while(collision[fruit_position[0]][fruit_position[1]]==1 || (fruit_position[0] == head_position[0] && fruit_position[1] == head_position[1]));
  	}
}

void snake_collision_check()
{
	for(int i = 0; i < GAME_DIM; i++)
	{
		for(int j = 0; j < GAME_DIM; j++)
		{
			collision[i][j] = 0;
		}
	}
	for(int i = 0; i < length; i++)
	{
		collision[tail_x[i]][tail_y[i]] = 1;

	}
	if(collision[head_position[0]][head_position[1]] == 1)
		GAME_OVER = 1;

	////popraw zeby petli nie bylo -> usuwanie ostatneigo elementu ogona z mac kolizji
}

void snake_game_init()
{
	GAME_OVER = 0;
	length = 0;
	head_position[0] = 0;
	head_position[1] = 0;
	for(int i = 0; i < GAME_SIZE; i++)
	{
		tail_x[i] = 0;
		tail_y[i] = 0;
	}

	prev_move_direction = RIGHT;
	move_direction = RIGHT;
	fruit_position[0]= 0;
	fruit_position[1]= 0;

}

void snake_update_direction(direction mvd)
{
	move_direction = mvd;
}
