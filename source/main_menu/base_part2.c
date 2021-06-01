/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

int get_max_buttons(st_rpg *s)
{
	if (s->mainm.menu > 2)
		return (3);
	return (2);
}

void destroy_main_menu_part2(st_rpg *s)
{
	sfClock_destroy(s->mainm.t.clock);
	sfMusic_destroy(s->mainm.music);
	sfMusic_destroy(s->mainm.s_effect);
	destroy_shader(&s->mainm.shader);
	destroy_text(s->mainm.sound[0]);
	destroy_text(s->mainm.sound[1]);
	for (int i = 0; i != 4; i++) {
		destroy_button(s->mainm.s_button[i]);
	}
}

void destroy_main_menu(st_rpg *s)
{
	destroy_object(s->mainm.first);
	destroy_object(s->mainm.guy);
	destroy_object(s->mainm.rope);
	destroy_object(s->mainm.cursor);
	destroy_object(s->mainm.title);
	for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
		destroy_button(s->mainm.button[i]);
	for (int i = 0; i != 2; i += 1) {
		destroy_object(s->mainm.rockback[i]);
		destroy_object(s->mainm.rock2[i]);
		destroy_object(s->mainm.abyss[i]);
	}
	destroy_main_menu_part2(s);
}
