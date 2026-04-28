#ifndef SNAKE
#define SNAKE

#include "stdint.h"

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

typedef struct
{
	int length;
	int8_t head_position[2];
	uint8_t prev_head_position[2];
	uint8_t tail_position_x[GAME_SIZE];
	uint8_t tail_position_y[GAME_SIZE];
	uint8_t fruit_position[2];
	direction move_direction;
	direction prev_move_direction;
	uint8_t collision[GAME_DIM][GAME_DIM];
}snake_state;



void snake_move(void);			// move snake in set direction
void snake_fruit_check(void);		// check if fruit was eaten and randomly place new fruit
void snake_collision_check(void); // update snake collisions and check GAME OVER condition
void snake_game_init(int seed);		// initialize game variables
void snake_update_direction(direction mvd);
const snake_state* snake_get_state(void);


extern uint8_t GROWTH;
extern uint8_t MOVE;
extern uint8_t GAME_OVER;

#endif
