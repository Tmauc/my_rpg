/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void cust_menu_togo_name(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	s->cust.menu = 2;
	s->cust.chosen = 1;
	destroy_button(s->cust.bt[1]);
	destroy_button(s->cust.bt[2]);
	s->cust.bt[1] = create_vbutton("Back", create_vector2f(1100, 600),
	grey, 70);
	s->cust.bt[2] = create_vbutton("Ok !", create_vector2f(1475, 600),
	grey, 70);
	s->cust.bt[3] = create_vbutton("Name", create_vector2f(1250, 400),
	grey, 50);
}

void cust_menu_togo_sex(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	s->cust.menu = 1;
	destroy_button(s->cust.bt[1]);
	destroy_button(s->cust.bt[2]);
	s->cust.bt[1] = create_vbutton("Male", create_vector2f(1100, 600),
	grey, 70);
	s->cust.bt[2] = create_vbutton("Female", create_vector2f(1400, 600),
	grey, 70);
}

void cust_menu_togo_classes(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	s->cust.menu = 3;
	destroy_button(s->cust.bt[1]);
	destroy_button(s->cust.bt[2]);
	destroy_button(s->cust.bt[3]);
	s->cust.bt[1] = create_vbutton("Archer", create_vector2f(900, 600),
	grey, 50);
	s->cust.bt[2] = create_vbutton("Gunner", create_vector2f(1150, 600),
	grey, 50);
	s->cust.bt[3] = create_vbutton("Rogue", create_vector2f(1400, 600),
	grey, 50);
	s->cust.bt[4] = create_vbutton("Warrior", create_vector2f(1600, 600),
	grey, 50);
	get_cursor_pos_classes(s);
}

int cust_menu_backto_main(st_rpg *s)
{
	loading(s);
	custom_destroy(s);
	s->mainm.option = 0;
	s->mainm.menu = 0;
	return (main_menu(s));
}
