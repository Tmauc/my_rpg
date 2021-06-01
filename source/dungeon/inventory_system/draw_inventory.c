/*
** EPITECH PROJECT, 2018
** draw_inventory.c
** File description:
** file to stock all functions about drawing inventory
*/

#include "my.h"
#include "my_rpg.h"

void create_item_sprite(st_rpg *rpg, item_t *current)
{
	sfIntRect current_rect =
	{115 * (current->id % 10), 115 * (current->id / 10), 115, 115};

	current->sprite = sfSprite_create();
	sfSprite_setTexture(current->sprite, rpg->inv.sheet, sfTrue);
	sfSprite_setTextureRect(current->sprite, current_rect);
}

void create_text_sprite(st_rpg *rpg, item_t *current)
{

	current->show_stacks = sfText_create();
	sfText_setFont(current->show_stacks, rpg->inv.inventory_font);
	sfText_setCharacterSize(current->show_stacks, 11);
}

void draw_inventory_sprites(st_rpg *rpg, item_t *current,
sfVector2f current_pos, sfVector2f text_pos)
{
	char *temp = int_to_str((signed)current->stacks);

	if (current->sprite == NULL)
		create_item_sprite(rpg, current);
	if (current->show_stacks == NULL)
		create_text_sprite(rpg, current);
	sfSprite_setPosition(current->sprite, current_pos);
	sfText_setPosition(current->show_stacks, text_pos);
	sfText_setString(current->show_stacks, temp);
	sfRenderWindow_drawSprite(rpg->window, current->sprite, NULL);
	if (current->stacks != 0) {
		sfRenderWindow_drawText(rpg->window, current->show_stacks,
		NULL);
	}
	free(temp);
}

void draw_inventory_items(st_rpg *rpg)
{
	item_t *current = rpg->inv.first_slot;
	float left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 15;
	float top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 70;
	sfVector2f current_pos;
	sfVector2f text_pos;

	while (current != NULL) {
		current_pos.x = left_pos + 120 * (current->pos % 9);
		current_pos.y = top_pos + 120 * (current->pos / 9);
		text_pos.x = left_pos + 120 * (current->pos % 9) + 10;
		text_pos.y = top_pos + 120 * (current->pos / 9) + 90;
		draw_inventory_sprites(rpg, current, current_pos, text_pos);
		current = current->next;
	}
	draw_armor_weapon_slot(rpg);
	draw_fast_inv_slot(rpg);
}

void verify_inventory(st_rpg *rpg)
{
	if (rpg->inv.is_open == 1) {
		draw_inventory_background(rpg);
		draw_inventory_items(rpg);
		verify_mouse_inv_events(rpg);
		draw_focused_item(rpg);
	}
}
