/*
** EPITECH PROJECT, 2018
** draw_item_ground.c
** File description:
** file to stock all functions about drawing an item on ground
*/

#include "my.h"
#include "my_rpg.h"

void draw_item_on_ground(st_rpg *rpg)
{
	gitem_t *crt = rpg->proc.first_gritem;

	while (crt != NULL) {
		sfRenderWindow_drawSprite(rpg->window, crt->sprite, NULL);
		crt = crt->next;
	}
}
