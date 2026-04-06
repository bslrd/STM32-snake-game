#define UP 		0
#define DOWN 	1
#define LEFT	3
#define RIGHT 	4

uint8_t length = 0;
uint8_t head_position[2];
uint8_t tail_x[64] = {0};
uint8_t tail_y[64] = {0};
uint8_t new_tail_position[2];
uint8_t move_direction;
uint8_t prev_move_direction;

uint8_t GROWTH = 0;

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

	prev_head_position = head_position;




}
