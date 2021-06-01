/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void cust_menu_interface_animation(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	for (int i = 0; i != cust_get_buttons(s->cust.menu); i += 1)
		sfText_setColor(s->cust.bt[i]->text->text, grey);
	sfText_setColor(s->cust.bt[s->cust.option]->text->text, sfWhite);
}

int cust_left_clicked(st_rpg *s, sfEvent event)
{
	for (int i = 0; i != cust_maxx_buttons(s->cust.menu); i += 1) {
		if (event.type == sfEvtMouseButtonPressed &&
			sfMouse_isButtonPressed(sfMouseLeft) &&
			mouse_in_object(s->cust.bt[i]->obj, s->window))
			return (1);
	}
	return (0);
}

void custom_manage_name_write(st_rpg *s, sfEvent event)
{
	if (event.type == sfEvtTextEntered && event.text.unicode > 30 &&
	event.text.unicode < 127 && s->cust.pos < 12) {
		s->cust.cdata.name[s->cust.pos] = event.text.unicode;
		s->cust.pos += 1;
	} if ((event.type == sfEvtKeyPressed &&
	sfKeyboard_isKeyPressed(sfKeyBack)) && s->cust.pos > 0) {
		s->cust.cdata.name[s->cust.pos - 1] = 0;
		s->cust.pos -= 1;
	} if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		s->cust.option = 2;
		get_cursor_pos(s);
	}
	sfText_setString(s->cust.bt[3]->text->text, s->cust.cdata.name);
}

int custom_event(st_rpg *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtClosed) {
			s->returnv = 1;
			custom_destroy(s);
			return (1);
		} if (s->cust.option == 3 && s->cust.menu == 2)
			custom_manage_name_write(s, event);
		else
			custom_manage_cursor_events_key(s, event);
		custom_manage_cursor_events_mouse(s);
		if (custom_launch(s, event)) {
			s->returnv = 1;
			return (1);
		}
	}
	return (0);
}

int custom_main(st_rpg *s)
{
	create_st_custom(s);
	while (sfRenderWindow_isOpen(s->window)) {
		if (custom_event(s))
			break;
		s->cust.face->rect.left = 100 * s->cust.cdata.sex;
		sfSprite_setTextureRect(s->cust.face->sprite,
		s->cust.face->rect);
		cust_cursor_animation(s);
		cust_menu_interface_animation(s);
		display_cust(s);
		sfRenderWindow_display(s->window);
	}
	return (s->returnv);
}
