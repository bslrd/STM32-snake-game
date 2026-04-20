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

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

#define GAME_SIZE GAME_DIM*GAME_DIM


void move(void);			// move snake in set direction
void fruit_check(void);		// check if fruit was eaten and randomly place new fruit
void collision_check(void); // update snake collisions and check GAME OVER condition
void game_init(void);		// initialize game variables

extern uint8_t length;
extern int head_position[2];
extern uint8_t tail_x[GAME_SIZE];
extern uint8_t tail_y[GAME_SIZE];
extern enum direction move_direction;
extern enum direction prev_move_direction;
extern uint8_t fruit_position[2];
extern uint8_t collision[GAME_DIM][GAME_DIM];
extern uint8_t GROWTH;
extern uint8_t MOVE;
extern uint8_t GAME_OVER;

#endif
