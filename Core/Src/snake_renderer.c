/*
 * snake_mx_renderer.c
 *
 *  Created on: 30 kwi 2026
 *      Author: dominik
 */
#include <snake_renderer.h>
#include "LED_matrix.h"
#include "LED_digits.h"

void render_snake(const snake_state *game)
{
	LED_fill(0,0,0,0,0);
	LED_symbole(game->collision,Rt,Gt,Bt,0,0,0);
	LED_set_coord(game->fruit.x, game->fruit.y, Rf,Gf,Bf);
	LED_set_coord(game->head.x, game->head.y, Rh,Gh,Bh);
	LED_update();
}
void render_menu(const snake_state *game)
{
	LED_fill(255,0,0,10,1);
	LED_digits(game->length,255,255,255);
	LED_update();
}
