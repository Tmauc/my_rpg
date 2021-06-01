/*
** EPITECH PROJECT, 2018
** destroy_inventory.c
** File description:
** destroy inventory file
*/

#include "my.h"
#include "my_rpg.h"

void destroy_inventory_sprites(st_rpg *rpg)
{
	if (rpg->inv.sprite != NULL)
		sfSprite_destroy(rpg->inv.sprite);
	if (rpg->inv.highlight != NULL)
		sfSprite_destroy(rpg->inv.highlight);
	if (rpg->inv.selected != NULL)
		sfSprite_destroy(rpg->inv.selected);
}

void destroy_inventory_textures(st_rpg *rpg)
{
	if (rpg->inv.selected_texture != NULL)
		sfTexture_destroy(rpg->inv.selected_texture);
	sfTexture_destroy(rpg->inv.texture);
	sfTexture_destroy(rpg->inv.sheet);
	sfFont_destroy(rpg->inv.inventory_font);
	if (rpg->inv.resume != NULL)
		sfText_destroy(rpg->inv.resume);
}

void destroy_inventory_items(st_rpg *rpg)
{
	item_t *current = rpg->inv.first_slot;
	item_t *last;

	while (current != NULL) {
		if (current->show_stacks != NULL)
			sfText_destroy(current->show_stacks);
		if (current->description != NULL)
			sfText_destroy(current->description);
		if (current->sprite != NULL)
			sfSprite_destroy(current->sprite);
		last = current;
		current = current->next;
		free(last);
	}
}

void destroy_inventory(st_rpg *rpg)
{
	destroy_inventory_items(rpg);
	destroy_inventory_sprites(rpg);
	destroy_inventory_textures(rpg);
}
