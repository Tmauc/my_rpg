/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

int launch_main_menu_saves(st_rpg *s)
{
	if (s->mainm.option == 2)
		main_menu_togo_main(s);
	else {
		s->mainm.create = s->mainm.option;
		main_menu_togo_slots(s);
	}
	return (0);
}

int launch_main_menu_options(st_rpg *s)
{
	if (s->mainm.option == 2) {
		set_new_sound(s);
		main_menu_togo_main(s);
	}
	return (0);
}

int launch_main_menu_main(st_rpg *s)
{
	if (s->mainm.option == 0) {
		main_menu_togo_saves(s);
	} if (s->mainm.option == 1) {
		main_menu_togo_options(s);
	} else if (s->mainm.option == 2) {
		destroy_main_menu(s);
		return (1);
	}
	return (0);
}

int launch_main_menu_create_slots(st_rpg *s)
{
	if (s->mainm.option == 3)
		main_menu_togo_saves(s);
	else {
		s->save = s->mainm.option + 1;
		destroy_main_menu(s);
		return (custom_main(s));
	}
	return (0);
}

int launch_main_menu_load_slots(st_rpg *s)
{
	if (s->mainm.option == 3)
		main_menu_togo_saves(s);
	else {
		s->save = s->mainm.option + 1;
		loading(s);
		destroy_main_menu(s);
		load_save(s);
		create_player(s);
		return (prog(s));
	}
	return (0);
}
