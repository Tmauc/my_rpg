/*
** EPITECH PROJECT, 2018
** inv_handle_mouse.c
** File description:
** mouse events in inventory
*/

#include "my.h"
#include "my_rpg.h"

void draw_focused_item(st_rpg *rpg)
{
	int left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 7.5;
	int top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 62.5;
	sfVector2f pos;

	if (rpg->inv.focused == NULL)
		return;
	pos.x = left_pos + 120 * (rpg->inv.focused->pos % 9);
	pos.y = top_pos + 120 * (rpg->inv.focused->pos / 9);
	update_pos_weapon_armor_focus(rpg, &pos);
	sfSprite_setPosition(rpg->inv.selected, (sfVector2f){pos.x, pos.y});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.selected, NULL);
	draw_resume_item(rpg);
}

void highlight_item(st_rpg *rpg, item_t *current, int *clicked)
{
	int left_pos = rpg->player.obj->pos.x - WIDTH / 2.5 + 15.5;
	int top_pos = rpg->player.obj->pos.y - HEIGHT / 2.5 + 70.5;
	sfVector2f pos = {left_pos + 120 * (current->pos % 9),
		top_pos + 120 * (current->pos / 9)};

	sfSprite_setPosition(rpg->inv.highlight, (sfVector2f){pos.x, pos.y});
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.highlight, NULL);
	if (sfMouse_isButtonPressed(key_select_item) == sfTrue) {
		rpg->inv.focused = current;
		*clicked = 1;
		rpg->inv.drawed = 0;
	} if (rpg->inv.use_item && 1 < current->id && current->id < 15) {
		use_inventory_item(rpg, current);
		rpg->inv.use_item = 0;
	}
}

int mouse_on_inventory_slot(st_rpg *rpg, int posx, int posy)
{
	sfVector2i mouse_pos =
	{sfMouse_getPositionRenderWindow(rpg->window).x + rpg->origin.x,
		sfMouse_getPositionRenderWindow(rpg->window).y + rpg->origin.y};

	if (posx < mouse_pos.x && posy < mouse_pos.y &&
		mouse_pos.x < posx + 120 && mouse_pos.y < posy + 120)
		return (1);
	return (0);
}

void verify_mouse_inv_events(st_rpg *rpg)
{
	item_t *current = rpg->inv.first_slot;
	int clicked = 0;

	while (current != NULL) {
		if (mouse_on_inventory_slot(rpg, rpg->player.obj->pos.x - WIDTH
		/ 2.5 + 15 + 120 * (current->pos % 9), rpg->player.obj->pos.y -
		HEIGHT / 2.5 + 70 + 120 * (current->pos / 9))) {
			highlight_item(rpg, current, &clicked);
		}
		current = current->next;
	}
	verify_armor_weapon_highlight(rpg, &clicked);
	if (sfMouse_isButtonPressed(key_select_item) && clicked == 0)
		rpg->inv.focused = NULL;
	rpg->inv.use_item = 0;
}
