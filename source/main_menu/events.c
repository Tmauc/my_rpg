/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"

void main_menu_manage_cursor_events(st_rpg *s, sfEvent event)
{
	int max = get_max_buttons(s);

	if (event.type == sfEvtKeyPressed) {
		if (((sfKeyboard_isKeyPressed(sfKeyS) ||
		sfKeyboard_isKeyPressed(sfKeyDown)) && s->mainm.option < max)) {
			s->mainm.cursor->pos.y += 120;
			s->mainm.option += 1;
		} else if ((sfKeyboard_isKeyPressed(sfKeyZ) ||
		sfKeyboard_isKeyPressed(sfKeyUp)) && s->mainm.option > 0) {
			s->mainm.cursor->pos.y -= 120;
			s->mainm.option -= 1;
		}
	}
	for (int i = 0; i != max + 1; i += 1) {
		if (mouse_in_object(s->mainm.button[i]->obj, s->window)) {
			s->mainm.cursor->pos.y = s->mainm.button[i]->obj->pos.y;
			s->mainm.option = i;
		}
	}
}

int which_main_menu(st_rpg *s)
{
	if (s->mainm.menu == 0)
		return (launch_main_menu_main(s));
	if (s->mainm.menu == 1)
		return (launch_main_menu_saves(s));
	if (s->mainm.menu == 2)
		return (launch_main_menu_options(s));
	if (s->mainm.menu == 3)
		return (launch_main_menu_load_slots(s));
	if (s->mainm.menu == 4)
		return (launch_main_menu_create_slots(s));
	return (0);
}

int launch_main_menu(st_rpg *s, sfEvent event)
{
	if ((event.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyE)
	|| sfKeyboard_isKeyPressed(sfKeyReturn)))
	|| left_clicked_on_buttons(s, event)) {
		if (which_main_menu(s))
			return (1);
	}
	return (0);
}

int event_main_menu(st_rpg *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtClosed) {
			s->returnv = 1;
			destroy_main_menu(s);
			return (1);
		} if (launch_main_menu(s, event)) {
			s->returnv = 1;
			return (1);
		} if (s->mainm.menu == 2) {
			choose_set_sound(s, event);
		}
		main_menu_manage_cursor_events(s, event);
	}
	return (0);
}
