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


#define UP 		0
#define DOWN 	1
#define LEFT	3
#define RIGHT 	4

void move(void);
void fruit_check(void);
void collision_check(void);
void game_init(void);

extern uint8_t length;
extern int head_position[2];
extern uint8_t prev_head_position[2];
extern uint8_t tail_x[64];
extern uint8_t tail_y[64];
extern uint8_t move_direction;
extern uint8_t prev_move_direction;
extern uint8_t fruit_position[2];
extern uint8_t collision[8][8];
extern uint8_t GROWTH;
extern uint8_t EATEN;
extern uint8_t MOVE;
extern uint8_t GAME_OVER;

#endif
