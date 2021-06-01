/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mouse_in_object
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "game_object.h"
#include "my_rpg.h"

int mouse_in_object_dialogbox(g_object *obj,
sfRenderWindow *window, st_rpg *s)
{
	int v = s->fi->camera.x - 960;
	int w = s->fi->camera.y - 540;
	int mx = sfMouse_getPositionRenderWindow(window).x + v;
	int my = sfMouse_getPositionRenderWindow(window).y + w;
	int posx = obj->pos.x;
	int posy = obj->pos.y;
	int width = obj->rect.width;
	int height = obj->rect.height;

	if (mx > posx && mx < posx + width) {
		if (my > posy && my < posy + height) {
			return (1);
		}
	}
	return (0);
}
