/*
** EPITECH PROJECT, 2018
** highlight_weapon_armor.c
** File description:
** file to stock all functions about highlighting weapon and armor
*/

#include "my.h"
#include "my_rpg.h"

void update_pos_weapon_armor_focus(st_rpg *rpg, sfVector2f *pos)
{
	if (rpg->inv.focused->pos == -1) {
		pos->x = rpg->player.obj->pos.x + WIDTH / 4.12 - 7.5;
		pos->y = rpg->player.obj->pos.y - HEIGHT / 6 - 7.5;
	} if (rpg->inv.focused->pos == -2) {
		pos->x = rpg->player.obj->pos.x + WIDTH / 4.12 - 7.5;
		pos->y = rpg->player.obj->pos.y - HEIGHT / 3 - 7.5;
	}
}

void highlight_armor(st_rpg *rpg, item_t *current, int *clicked)
{
	int left = rpg->player.obj->pos.x + WIDTH / 4.12;
	int top = rpg->player.obj->pos.y - HEIGHT / 6;

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){left, top});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
	if (sfMouse_isButtonPressed(key_select_item) == sfTrue) {
		rpg->inv.focused = current;
		*clicked = 1;
	}
}

void highlight_weapon(st_rpg *rpg, item_t *current, int *clicked)
{
	int left = rpg->player.obj->pos.x + WIDTH / 4.12;
	int top = rpg->player.obj->pos.y - HEIGHT / 3;

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){left, top});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
	if (sfMouse_isButtonPressed(key_select_item) == sfTrue) {
		rpg->inv.focused = current;
		*clicked = 1;
	}
}

void verify_armor_weapon_highlight(st_rpg *rpg, int *clicked)
{
	if (mouse_on_inventory_slot(rpg, rpg->player.obj->pos.x + WIDTH / 4.12,
		rpg->player.obj->pos.y - HEIGHT / 6))
		highlight_armor(rpg, rpg->inv.armor, clicked);
	if (mouse_on_inventory_slot(rpg, rpg->player.obj->pos.x + WIDTH / 4.12,
		rpg->player.obj->pos.y - HEIGHT / 3))
		highlight_weapon(rpg, rpg->inv.weapon, clicked);
}
