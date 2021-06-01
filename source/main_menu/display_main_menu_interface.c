/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void display_main_menu_interface_part2(st_rpg *s)
{
	if (s->mainm.menu == 2) {
		for (int i = 0; i != 4; i++) {
			sfRenderWindow_drawText(s->window,
			s->mainm.s_button[i]->text->text, NULL);
		}
		sfRenderWindow_drawText(s->window,
		s->mainm.sound[0]->text, NULL);
		sfRenderWindow_drawText(s->window,
		s->mainm.sound[1]->text, NULL);
	}
	if (s->mainm.menu > 2) {
		sfRenderWindow_drawText(s->window,
		s->mainm.button[3]->text->text, NULL);
	}
}

void display_main_menu_interface(st_rpg *s)
{
	sfRenderWindow_drawText(s->window,
	s->mainm.button[0]->text->text, NULL);
	sfRenderWindow_drawText(s->window,
	s->mainm.button[1]->text->text, NULL);
	sfRenderWindow_drawText(s->window,
	s->mainm.button[2]->text->text, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.cursor->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.title->sprite,
	&s->mainm.shader.state);
	display_main_menu_interface_part2(s);
}
