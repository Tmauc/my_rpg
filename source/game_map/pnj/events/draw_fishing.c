/*
** EPITECH PROJECT, 2018
** draw_fishing.c
** File description:
**
*/

#include "my.h"
#include "my_rpg.h"

void draw_fishing_instance(st_rpg *rpg, fish_t *fish)
{
	sfRenderWindow_clear(rpg->window, sfBlack);
	sfRenderWindow_drawSprite(rpg->window, fish->character, NULL);
	sfRenderWindow_drawText(rpg->window, fish->cur_score, NULL);
	sfRenderWindow_drawText(rpg->window, fish->time_rem, NULL);
	sfRenderWindow_display(rpg->window);
}
