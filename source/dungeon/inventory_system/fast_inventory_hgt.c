/*
** EPITECH PROJECT, 2018
** fast_inventory_hgt.c
** File description:
** fast inventory highlight
*/

#include "my.h"
#include "my_rpg.h"

void draw_fast_inv_slot(st_rpg *rpg)
{
	sfVector2f pos = rpg->player.obj->pos;

	if (rpg->finv.slots[0] == NULL) {
		sfSprite_setPosition(rpg->inv.highlight,
		(sfVector2f){pos.x + 596, pos.y + 230});
		sfRenderWindow_drawSprite(rpg->window,
		rpg->inv.highlight, NULL);
	} if (rpg->finv.slots[1] == NULL) {
		sfSprite_setPosition(rpg->inv.highlight,
		(sfVector2f){pos.x + 473, pos.y + 135});
		sfRenderWindow_drawSprite(rpg->window,
		rpg->inv.highlight, NULL);
	} if (rpg->finv.slots[2] == NULL) {
		sfSprite_setPosition(rpg->inv.highlight,
		(sfVector2f){pos.x + 350, pos.y + 230});
		sfRenderWindow_drawSprite(rpg->window,
		rpg->inv.highlight, NULL);
	}
}
