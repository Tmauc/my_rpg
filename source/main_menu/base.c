/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void initialize_menu_interface_part2(st_rpg *s)
{
	s->mainm.guy = create_object("ressources/images/menu/guy.png",
	create_vector2f(212, -600), create_rect(0, 0, 234, 307), 0);
	s->mainm.title = create_object("ressources/images/menu/title.png",
	create_vector2f(558, -300), create_rect(0, 0, 804, 67), 0);
	sfSprite_setScale(s->mainm.guy->sprite, create_vector2f(2, 2));
	s->mainm.shader = create_shader("shader/rainbow.frag", 1);
	set_text_option(s);
}

void initialize_menu_interface(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	s->mainm.menu = 0;
	s->mainm.sens = 1;
	s->mainm.option = 0;
	get_sound_option(s);
	s->mainm.cursor = create_object(
	"ressources/images/interface/cursor.png",
	create_vector2f(700, 500), create_rect(0, 0, 100, 116), 2);
	s->mainm.button[0] = create_vbutton("Play", create_vector2f(800, 500),
	grey, 100);
	s->mainm.button[1] = create_vbutton("Options",
	create_vector2f(800, 620), grey, 100);
	s->mainm.button[2] = create_vbutton("Quit", create_vector2f(800, 740),
	grey, 100);
	initialize_menu_interface_part2(s);
}

void initialize_menu_part2(st_rpg *s)
{
	sfSprite_setScale(s->mainm.abyss[1]->sprite, create_vector2f(-1, 1));
	s->mainm.t.sec = 0.0;
	s->mainm.t.clock = sfClock_create();
	initialize_menu_interface(s);
}

void initialize_menu(st_rpg *s)
{
	s->returnv = 0;
	s->mainm.create = 0;
	s->mainm.first = create_object("ressources/images/menu/first.png",
	create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 6);
	s->mainm.rope = create_object("ressources/images/menu/ropesheet.png",
	create_vector2f(200, 0), create_rect(0, 0, 72, 1080), 0);
	for (int i = 0; i != 2; i += 1) {
		s->mainm.abyss[i] =
		create_object("ressources/images/menu/abyss2.png",
		create_vector2f(300 + 1400 * i , 5712 * i),
		create_rect(0, 0, 1920, 5712), 2);
		s->mainm.rockback[i] =
		create_object("ressources/images/menu/RockCave.png",
		create_vector2f(0, 2936 * i), create_rect(0, 0, 1920, 2936), 6);
		s->mainm.rock2[i] =
		create_object("ressources/images/menu/rock3.png",
		create_vector2f(110, 2236 * i),
		create_rect(0, 0, 1920, 2236), 4);
	}
	initialize_menu_part2(s);
}

int left_clicked_on_buttons(st_rpg *s, sfEvent event)
{
	int max = 3;

	if (s->mainm.menu > 2)
		max += 1;
	for (int i = 0; i != max; i += 1) {
		if (event.type == sfEvtMouseButtonPressed &&
			sfMouse_isButtonPressed(sfMouseLeft) &&
			mouse_in_object(s->mainm.button[i]->obj, s->window))
			return (1);
	}
	return (0);
}
