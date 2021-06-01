/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void get_cursor_pos_classes(st_rpg *s)
{
	if (s->cust.option != 0) {
		s->cust.cursor->pos.x = 980 + 250 * (s->cust.option - 1);
		s->cust.cursor->pos.y = 705;
	}
}

void get_cursor_pos(st_rpg *s)
{
	if (s->cust.option == 0) {
		s->cust.cursor->pos.x = 330;
		s->cust.cursor->pos.y = 850;
		s->cust.rot = 90;
	} else {
		if (s->cust.option == 3) {
			s->cust.cursor->pos.x = 1345;
			s->cust.cursor->pos.y = 495;
		} else {
			s->cust.cursor->pos.x = 1180 + 330 *
			(s->cust.option - 1);
			s->cust.cursor->pos.y = 710;
		}
		s->cust.rot = -90;
	} if (s->cust.menu == 3)
		get_cursor_pos_classes(s);
	s->cust.cmin = s->cust.cursor->pos.y;
	s->cust.cmax = s->cust.cmin + 5;
	sfSprite_setPosition(s->cust.cursor->sprite, s->cust.cursor->pos);
	sfSprite_setRotation(s->cust.cursor->sprite, s->cust.rot);
}

void cust_cursor_animation(st_rpg *s)
{
	s->cust.cursor->pos.y += s->cust.sens;
	if (s->cust.cursor->pos.y > s->cust.cmax ||
		s->cust.cursor->pos.y < s->cust.cmin)
		s->cust.sens = -s->cust.sens;
	sfSprite_setPosition(s->cust.cursor->sprite, s->cust.cursor->pos);
}

void custom_manage_cursor_events_key(st_rpg *s, sfEvent event)
{
	int maxx = cust_maxx_buttons(s->cust.menu);
	int minx = cust_minx_buttons(s->cust.menu);

	if (event.type == sfEvtKeyPressed) {
		if (s->cust.option == 3 && (sfKeyboard_isKeyPressed(sfKeyS) ||
			sfKeyboard_isKeyPressed(sfKeyDown)))
			s->cust.option = 1;
		if (s->cust.menu == 2 && (sfKeyboard_isKeyPressed(sfKeyZ) ||
			sfKeyboard_isKeyPressed(sfKeyUp)) &&
			s->cust.option != 3)
			s->cust.option = 3;
		if ((sfKeyboard_isKeyPressed(sfKeyQ) ||
			sfKeyboard_isKeyPressed(sfKeyLeft)) &&
			s->cust.option > minx)
			s->cust.option -= 1;
		if ((sfKeyboard_isKeyPressed(sfKeyD) ||
			sfKeyboard_isKeyPressed(sfKeyRight)) &&
			s->cust.option < maxx)
			s->cust.option += 1;
		get_cursor_pos(s);
	}
}

void custom_manage_cursor_events_mouse(st_rpg *s)
{
	for (int i = 0; i != cust_get_buttons(s->cust.menu); i += 1) {
		if (mouse_in_object(s->cust.bt[i]->obj, s->window) &&
		s->cust.option != i) {
			s->cust.option = i;
			get_cursor_pos(s);
		}
	}
}
