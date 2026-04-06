#include "snake.h"
#include "stdlib.h"

// game variables
uint8_t length = 0;
int head_position[2]={0};
uint8_t prev_head_position[2]={0};
uint8_t tail_x[64] = {0};
uint8_t tail_y[64] = {0};
uint8_t move_direction = RIGHT;
uint8_t prev_move_direction = RIGHT;
uint8_t fruit_position[2]={0};
uint8_t collision[8][8]={0};
uint8_t GROWTH = 0;
uint8_t EATEN = 1;
uint8_t MOVE = 0;
uint8_t GAME_OVER = 1;

void move()
{
	if(GROWTH)
	{
		tail_x[length] = head_position[0];
		tail_y[length] = head_position[1];
		length++;
		GROWTH = 0;
	}
	else if(length)
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
	if(head_position[0] > 7) head_position[0] = 7;
	if(head_position[1] < 0) head_position[1] = 0;
	if(head_position[1] > 7) head_position[1] = 7;

	prev_head_position[0] = head_position[0];
	prev_head_position[1] = head_position[1];
	prev_move_direction = move_direction;
}

void fruit_check()
{
	if(fruit_position[0] == head_position[0] && fruit_position[1] == head_position[1])
	{
		GROWTH = 1;
		do{
			fruit_position[0] = rand()%8;
			fruit_position[1] = rand()%8;
		}while(collision[fruit_position[0]][fruit_position[1]]==1 || (fruit_position[0] == head_position[0] && fruit_position[1] == head_position[1]));
  	}
}

void collision_check()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
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
}

void game_init()
{
	GAME_OVER = 0;
	length = 0;
	head_position[0] = 0;
	head_position[1] = 0;
	for(int i = 0; i < 64; i++)
	{
		tail_x[i] = 0;
		tail_y[i] = 0;
	}

	EATEN = 1;
	prev_head_position[0]= 0;
	prev_head_position[0]= 1;
	prev_move_direction = RIGHT;
	move_direction = RIGHT;
	fruit_position[0]= 0;
	fruit_position[1]= 0;

}
