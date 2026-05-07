/**
 * @file game_renderer.c
 *
 * @brief Implementation of snake rendering module for ws2812b matrix display.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */

#include "ws2812b.h"
#include "ws2812b_matrix.h"
#include "ws2812b_matrix_symbols.h"
#include "game_renderer.h"

/***********************************/
// GAME COLORS CONFIGURATION
/***********************************/
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

// background color
#define Rb		0
#define Gb		0
#define Bb		0

// menu color
#define Rm		125
#define Gm		0
#define Bm		0

// digits color
#define Rd		75
#define Gd		75
#define Bd		75
/***********************************/


void render_snake(const snake_state *game)
{
	ws2812b_matrix_fill(Rb,Gb,Bb,0,0);
	ws2812b_matrix_symboles(game->collision_map,Rt,Gt,Bt,0,0,1);
	ws2812b_matrix_set_coord(game->fruit.x, game->fruit.y, Rf,Gf,Bf);
	ws2812b_matrix_set_coord(game->head.x, game->head.y, Rh,Gh,Bh);
	ws2812b_update();
}

void render_menu(const snake_state *game)
{
	ws2812b_matrix_fill(Rm,Gm,Bm,10,1);
	ws2812b_matrix_digits(game->length,Rd,Gd,Bd);
	ws2812b_update();
}

void render_start(void)
{
	ws2812b_matrix_fill(Rb,Gb,Bb,10,1);
}
