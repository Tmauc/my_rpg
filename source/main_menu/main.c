/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void main_menu_interface_animation(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
		sfText_setColor(s->mainm.button[i]->text->text, grey);
	sfText_setColor(s->mainm.button[s->mainm.option]->text->text, sfWhite);
}

void cursor_animation(st_rpg *s, int min, int max)
{
	s->mainm.cursor->pos.x += s->mainm.sens;
	if (s->mainm.cursor->pos.x > max || s->mainm.cursor->pos.x < min)
		s->mainm.sens = -s->mainm.sens;
	sfSprite_setPosition(s->mainm.cursor->sprite, s->mainm.cursor->pos);
}

void main_menu_update_downward(st_rpg *s)
{
	if (sfSprite_getPosition(s->mainm.guy->sprite).y < 200)
		sfSprite_setPosition(s->mainm.guy->sprite,
		create_vector2f(sfSprite_getPosition(s->mainm.guy->sprite).x,
		sfSprite_getPosition(s->mainm.guy->sprite).y + 10));
	if (sfSprite_getPosition(s->mainm.title->sprite).y < 100)
		sfSprite_setPosition(s->mainm.title->sprite,
		create_vector2f(sfSprite_getPosition(s->mainm.title->sprite).x,
		sfSprite_getPosition(s->mainm.title->sprite).y + 10));
}

int main_menu(st_rpg *s)
{
	initialize_menu(s);
	if (main_menu_cutscene(s) == 1)
		return (0);
	while (sfRenderWindow_isOpen(s->window)) {
		if (event_main_menu(s))
			break;
		movement_mainm(s);
		main_menu_update_downward(s);
		cursor_animation(s, 690, 710);
		main_menu_interface_animation(s);
		shader_move(s);
		display_menu_background(s);
		display_main_menu_interface(s);
		sfRenderWindow_display(s->window);
	}
	return (s->returnv);
}
