/*
** EPITECH PROJECT, 2018
** draw_fast_inventory.c
** File description:
** file to stock all functions about creating fast inventory
*/

#include "my.h"
#include "my_rpg.h"

void set_created_position(st_rpg *rpg)
{
	sfVector2f mouse_pos = {0, 0};

	if (rpg->finv.created == 0) {
		mouse_pos.x -= WIDTH / 2 + HEIGHT / 8 - 20;
		mouse_pos.y -= HEIGHT / 2 + HEIGHT / 8 - 20;
		mouse_pos.x +=
		sfMouse_getPositionRenderWindow(rpg->window).x;
		mouse_pos.y +=
		sfMouse_getPositionRenderWindow(rpg->window).y;
		rpg->finv.created_pos.x = mouse_pos.x;
		rpg->finv.created_pos.y = mouse_pos.y;
	}
	rpg->finv.created = 1;
}

void draw_fast_inventory_background(st_rpg *rpg)
{
	sfVector2f pos_screen = {0, 0};

	set_created_position(rpg);
	pos_screen = rpg->finv.created_pos;
	pos_screen.x += rpg->player.obj->pos.x;
	pos_screen.y += rpg->player.obj->pos.y;
	sfSprite_setPosition(rpg->finv.sprite, pos_screen);
	sfRenderWindow_drawSprite(rpg->window, rpg->finv.sprite, NULL);
}

void draw_fast_inventory(st_rpg *rpg)
{
	draw_fast_inventory_background(rpg);
	draw_items_fast_inventory(rpg);
	verify_mouse_focused(rpg);
	verify_mouse_released(rpg);
	rpg->finv.mouse_released = 0;
}

void verify_fast_inventory(st_rpg *rpg)
{
	if (sfMouse_isButtonPressed(key_fast_inv)) {
		draw_fast_inventory(rpg);
	} else {
		rpg->finv.created = 0;
	}
}
