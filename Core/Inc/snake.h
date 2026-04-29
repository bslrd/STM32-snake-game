#ifndef SNAKE
#define SNAKE

#include "stdint.h"
#include "stdbool.h"
/***********************************/
// SET GAME COLORS //

// snake head color
#define Rh		0
#define Gh		0
#define Bh		255

// snake tail color
#define Rt		0
#define Gt		255
#define Bt		0

// fruit color
#define Rf		255
#define Gf		0
#define Bf		0

/***********************************/
// SET GAME DIMENSIONS //

#define GAME_DIM 8

/***********************************/

#define GAME_SIZE GAME_DIM*GAME_DIM

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}direction;

typedef enum
{
	INIT,
	GAME_OVER,
	RUNNING,
}state;

typedef struct
{
	uint8_t x;
	uint8_t y;
}position;

typedef struct
{
	int length;
	position head;
	position tail[GAME_SIZE];
	position fruit;
	direction move_dir;
	direction prev_move_dir;
	uint8_t collision[GAME_DIM][GAME_DIM];
	uint8_t GROWTH;
	state state;
}snake_state;

void snake_update(void);
void snake_init_request(void);
void snake_move_request(void);
bool snake_is_over(void);
void snake_move(void);			// move snake in set direction
void snake_fruit_check(void);		// check if fruit was eaten and randomly place new fruit
void snake_game_init(int seed);		// initialize game variables
void snake_update_direction(direction mvd);
const snake_state* snake_get_state(void);

#endif
