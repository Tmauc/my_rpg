/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

void main_menu_togo_main(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	s->mainm.menu = 0;
	for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
		destroy_button(s->mainm.button[i]);
	s->mainm.button[0] = create_vbutton("Play", create_vector2f(800, 500),
	grey, 100);
	s->mainm.button[1] = create_vbutton("Options",
	create_vector2f(800, 620), grey, 100);
	s->mainm.button[2] = create_vbutton("Quit", create_vector2f(800, 740),
	grey, 100);
}

void main_menu_set_slots(st_rpg *s, sfVector2f pos, int number, sfColor grey)
{
	char *path = my_strcat("saves/", int_to_str(number + 1));
	char *full_path = my_strcat(path, "/cust");
	int fd = open(full_path, O_RDONLY);
	char *buffer = get_next_line(fd);

	free(buffer);
	buffer = get_next_line(fd);
	free(buffer);
	buffer = get_next_line(fd);
	s->mainm.button[number] = create_vbutton(buffer, pos, grey, 100);
	free(buffer);
	free(path);
	free(full_path);
	close(fd);
}

void main_menu_togo_slots(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
		destroy_button(s->mainm.button[i]);
	main_menu_set_slots(s, create_vector2f(800, 500), 0, grey);
	main_menu_set_slots(s, create_vector2f(800, 620), 1, grey);
	main_menu_set_slots(s, create_vector2f(800, 740), 2, grey);
	s->mainm.button[3] = create_vbutton("Back", create_vector2f(800, 860),
	grey, 100);
	s->mainm.menu = 3 + s->mainm.option;
}

void main_menu_togo_saves(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
		destroy_button(s->mainm.button[i]);
	s->mainm.button[0] = create_vbutton("Load save",
	create_vector2f(800, 500), grey, 100);
	s->mainm.button[1] = create_vbutton("New game",
	create_vector2f(800, 620), grey, 100);
	s->mainm.button[2] = create_vbutton("Back",
	create_vector2f(800, 740), grey, 100);
	s->mainm.menu = 1;
	if (s->mainm.option == 3) {
		s->mainm.cursor->pos.y = 740;
		sfSprite_setPosition(s->mainm.cursor->sprite,
		s->mainm.cursor->pos);
		s->mainm.option = 2;
	}
}

void main_menu_togo_options(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	for (int i = 0; i != get_max_buttons(s) + 1; i += 1)
		destroy_button(s->mainm.button[i]);
	s->mainm.button[0] = create_vbutton("Sound            ",
	create_vector2f(800, 500), grey, 100);
	s->mainm.button[1] = create_vbutton("Music            ",
	create_vector2f(800, 620), grey, 100);
	s->mainm.button[2] = create_vbutton("Back",
	create_vector2f(800, 740), grey, 100);
	s->mainm.menu = 2;
}
