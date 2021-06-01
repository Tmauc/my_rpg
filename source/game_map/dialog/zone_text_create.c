/*
** EPITECH PROJECT, 2018
** zone_text_create.c
** File description:
** zone_text_create.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_dialog_box(st_rpg *s)
{
	destroy_button(s->fi->pnj[s->fi->nb_pnj].dialog_box);
	destroy_button(s->fi->pnj[s->fi->nb_pnj].name_box);
	s->fi->var_choice = 0;
	s->fi->nb_choice_pre = 0;
}

void create_dialog_box(st_rpg *s)
{
	float pos_x = s->fi->camera.x - 450;
	float pos_y = s->fi->camera.y + 250;
	float pos_text_x = pos_x + 50;
	float pos_text_y = pos_y + 70;

	s->fi->pnj[s->fi->nb_pnj].dialog_box = create_button("jk",
	create_object("ressources/images/dialog_box/dialog_box_obj.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 908, 185), 0),
	sfWhite, 35);
	sfText_setPosition(s->fi->pnj[s->fi->nb_pnj].dialog_box->text->text,
	create_vector2f(pos_text_x, pos_text_y));
	s->fi->pnj[s->fi->nb_pnj].dialog_box->text->font =
	sfFont_createFromFile("ressources/fonts/testfont/mangat.ttf");
	sfText_setFont(s->fi->pnj[s->fi->nb_pnj].dialog_box->text->text,
	s->fi->pnj[s->fi->nb_pnj].dialog_box->text->font);
}

void create_name_box(st_rpg *s, char *name)
{
	float pos_x = s->fi->camera.x - 440;
	float pos_y = s->fi->camera.y + 200;
	float pos_text_x = pos_x + 30;
	float pos_text_y = pos_y + 26;

	s->fi->pnj[s->fi->nb_pnj].name_box =
	create_button(name,
	create_object("ressources/images/dialog_box/name_box_obj.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 162, 76), 0),
	sfWhite, 20);
	sfText_setPosition(s->fi->pnj[s->fi->nb_pnj].name_box->text->text,
	create_vector2f(pos_text_x, pos_text_y));
}
