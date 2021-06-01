/*
** EPITECH PROJECT, 2018
** inventory_items_handling.c
** File description:
** handle item in inventory
*/

#include "my.h"
#include "my_rpg.h"

void verify_destroy_item(item_t *current)
{
	if (current->sprite != NULL)
		sfSprite_destroy(current->sprite);
	current->sprite = NULL;
	if (current->show_stacks != NULL)
		sfText_destroy(current->show_stacks);
	current->show_stacks = NULL;
}

void remove_inventory_item(st_rpg *rpg, item_t *to_remove)
{
	item_t *current = rpg->inv.first_slot;

	while (current != to_remove)
		current = current->next;
	current->stacks -= 1;
	if (current->stacks == 0) {
		verify_destroy_item(current);
		clear_inventory_slot(current);
		if (rpg->inv.focused == to_remove) {
			rpg->inv.focused = NULL;
		}
	}
}

int add_inventory_item(item_t *first_slot, unsigned int id)
{
	item_t *current = first_slot;
	int pos = search_item(first_slot, id);

	if (pos == -1) {
		while (current != NULL && current->id != 1)
			current = current->next;
		if (current == NULL)
			return (0);
		verify_destroy_item(current);
		current->id = id;
		current->stacks += 1;
	} else {
		while ((signed)current->pos < pos)
			current = current->next;
		current->stacks += 1;
	}
	return (1);
}

void use_inventory_item(st_rpg *rpg, item_t *current)
{
	int to_add[] = {0, 0, 5, 3, 150, 10, 10, 0, 0};
	void (*function[])(st_rpg *, int) =
	{NULL, NULL, &heal, &add_speed, &add_cdr, &heal, &heal, &heal};

	(*function[current->id])(rpg, to_add[current->id]);
	remove_inventory_item(rpg, current);
}
