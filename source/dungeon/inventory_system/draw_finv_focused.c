/*
** EPITECH PROJECT, 2018
** draw_finv_focused.c
** File description:
** draw focused fast inv with mouse
*/

#include "my.h"
#include "my_rpg.h"

sfVector2f get_mouse_position_finv(st_rpg *rpg)
{
	sfVector2f mouse_pos = {0, 0};

	mouse_pos.x -= WIDTH / 2 + HEIGHT / 8 - 20;
	mouse_pos.y -= HEIGHT / 2 + HEIGHT / 8 - 20;
	mouse_pos.x +=
	sfMouse_getPositionRenderWindow(rpg->window).x;
	mouse_pos.y +=
	sfMouse_getPositionRenderWindow(rpg->window).y;
	return (mouse_pos);
}

void draw_map_focused(st_rpg *rpg, int angle)
{
	sfVector2f c_pos = {rpg->finv.created_pos.x + rpg->player.obj->pos.x,
		rpg->finv.created_pos.y + rpg->player.obj->pos.y};

	if (-20 <= angle && angle < 90) {
		sfSprite_setPosition(rpg->finv.spr[0],
		(sfVector2f){c_pos.x + 115, c_pos.y + 80});
		sfRenderWindow_drawSprite(rpg->window, rpg->finv.spr[0], NULL);
		rpg->finv.focused_slot = 0;
	} if (angle < -160 || 90 <= angle) {
		sfSprite_setPosition(rpg->finv.spr[1],
		(sfVector2f){c_pos.x + 5, c_pos.y + 80});
		sfRenderWindow_drawSprite(rpg->window, rpg->finv.spr[1], NULL);
		rpg->finv.focused_slot = 1;
	} if (-160 <= angle && angle < -20) {
		sfSprite_setPosition(rpg->finv.spr[2],
		(sfVector2f){c_pos.x + 12, c_pos.y + 6});
		sfRenderWindow_drawSprite(rpg->window, rpg->finv.spr[2], NULL);
		rpg->finv.focused_slot = 2;
	}
}

void verify_mouse_focused(st_rpg *rpg)
{
	sfVector2f mouse_pos = get_mouse_position_finv(rpg);
	sfVector2f diff_pos = {mouse_pos.x - rpg->finv.created_pos.x,
		mouse_pos.y - rpg->finv.created_pos.y};
	float mx = mouse_pos.x - rpg->finv.created_pos.x;
	float my = mouse_pos.y - rpg->finv.created_pos.y;
	int angle;

	rpg->finv.focused_slot = -1;
	if (-30 < diff_pos.x && diff_pos.x < 30 &&
		-30 < diff_pos.y && diff_pos.y < 30)
		return;
	if (my <= 0)
		angle = -acos(mx / hypot(mx, my)) * (180 / 3.14159265);
	else
		angle = acos(mx / hypot(mx, my)) * (180 / 3.14159265);
	draw_map_focused(rpg, angle);
}

void verify_mouse_released(st_rpg *rpg)
{
	if (!rpg->finv.mouse_released || rpg->finv.focused_slot < 0)
		return;
	use_inventory_item(rpg, rpg->finv.slots[rpg->finv.focused_slot]);
}
