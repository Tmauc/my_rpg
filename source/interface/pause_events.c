/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

int left_clicked_on_pause(st_rpg *s, sfEvent event)
{
	int max = 5;

	for (int i = 0; i != max; i += 1) {
		if (event.type == sfEvtMouseButtonPressed &&
			sfMouse_isButtonPressed(sfMouseLeft) &&
			mouse_in_origin(s, s->pausm.button[i]->obj))
			return (1);
	}
	return (0);
}

void pause_menu_manage_cursor_events(st_rpg *s, sfEvent event)
{
	int max = 5;

	if (event.type == sfEvtKeyPressed) {
		if (((sfKeyboard_isKeyPressed(sfKeyS) ||
			sfKeyboard_isKeyPressed(sfKeyDown)) &&
			s->pausm.option < max - 1))
			s->pausm.option += 1;
		else if ((sfKeyboard_isKeyPressed(sfKeyZ) ||
			sfKeyboard_isKeyPressed(sfKeyUp)) &&
			s->pausm.option > 0)
			s->pausm.option -= 1;
	}
	for (int i = 0; i != max; i += 1) {
		if (mouse_in_origin(s, s->pausm.button[i]->obj))
			s->pausm.option = i;
	}
}
