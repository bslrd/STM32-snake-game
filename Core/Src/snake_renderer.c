/*
 * snake_mx_renderer.c
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */
#include <snake_renderer.h>
#include "ws2812b.h"
#include <ws2812b_matrix.h>
#include "ws2812b_matrix_symboles.h"

void render_snake(const snake_state *game)
{
	ws2812b_matrix_fill(0,0,0,0,0);
	ws2812b_matrix_symboles(game->collision,Rt,Gt,Bt,0,0,0);
	ws2812b_matrix_set_coord(game->fruit.x, game->fruit.y, Rf,Gf,Bf);
	ws2812b_matrix_set_coord(game->head.x, game->head.y, Rh,Gh,Bh);
	ws2812b_update();
}
void render_menu(const snake_state *game)
{
	ws2812b_matrix_fill(255,0,0,10,1);
	ws2812b_matrix_digits(game->length,255,255,255);
	ws2812b_update();
}
