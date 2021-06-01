/*
** EPITECH PROJECT, 2018
** update_ground_item.c
** File description:
** verify item pickup on ground
*/

#include "my.h"
#include "my_rpg.h"

void dispawn_item(st_rpg *rpg, gitem_t *to_remove)
{
	gitem_t *last = NULL;
	gitem_t *current = rpg->proc.first_gritem;

	while (current != to_remove) {
		last = current;
		current = current->next;
	}
	if (last == NULL)
		rpg->proc.first_gritem = rpg->proc.first_gritem->next;
	else
		last->next = current->next;
}

void update_item_ground(st_rpg *rpg)
{
	gitem_t *current = rpg->proc.first_gritem;
	sfVector2i ipos;
	sfVector2i ppos =
	{rpg->player.obj->pos.x / 96, rpg->player.obj->pos.y / 96};

	while (current != NULL) {
		ipos = (sfVector2i){current->pos.x / 96, current->pos.y / 96};
		if (ipos.x == ppos.x && ipos.y == ppos.y) {
			add_inventory_item(rpg->inv.first_slot, current->id);
			dispawn_item(rpg, current);
		}
		current = current->next;
	}
}
