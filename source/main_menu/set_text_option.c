/*
** EPITECH PROJECT, 2018
** set_text_option.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

void set_text_option(st_rpg *s)
{
	sfColor white = {255, 255, 255, 255};

	s->mainm.sound[0] = create_text(int_to_str(s->s_effect),
	create_vector2f(1400, 520), "ressources/fonts/button.ttf");
	s->mainm.sound[1] = create_text(int_to_str(s->s_music),
	create_vector2f(1400, 640), "ressources/fonts/button.ttf");
	sfText_setCharacterSize(s->mainm.sound[0]->text, 100);
	sfText_setCharacterSize(s->mainm.sound[1]->text, 100);
	s->mainm.s_button[0] = create_vbutton(" < ",
	create_vector2f(1200, 500), white, 150);
	s->mainm.s_button[1] = create_vbutton(" > ",
	create_vector2f(1500, 500), white, 150);
	s->mainm.s_button[2] = create_vbutton(" < ",
	create_vector2f(1200, 620), white, 150);
	s->mainm.s_button[3] = create_vbutton(" > ",
	create_vector2f(1500, 620), white, 150);
}
