/*
** EPITECH PROJECT, 2018
** name_to_head.c
** File description:
** name_to_head.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

float create_name_box_middle(st_rpg *s, int i, float pos_x, int j)
{
	int size = my_strlen(s->fi->pnj[i].name);
	float posx = s->fi->pnj[i].pnj->pos.x - (size - 3) * 7;
	float pos_y = s->fi->pnj[i].pnj->pos.y - 25;
	float pos_text_x = pos_x + 10;

	pos_x = posx + 15 + (12 * j);
	s->fi->name_head[j] = create_button(s->fi->pnj[i].name,
	create_object("ressources/images/name_box/name.png",
	create_vector2f(pos_x, pos_y),
	create_rect(0, 0, 12, 32), 0), sfWhite, 18);
	sfText_setPosition(s->fi->name_head[j]->text->text,
	create_vector2f(pos_text_x, pos_y + 5));
	s->fi->name_head[j]->text->font =
	sfFont_createFromFile("ressources/fonts/testfont/mangat.ttf");
	sfText_setFont(s->fi->name_head[j]->text->text,
	s->fi->name_head[j]->text->font);
	return (pos_x);
}

void create_box_name(st_rpg *s, int i)
{
	int j = 0;
	int size = my_strlen(s->fi->pnj[i].name);
	float posx = s->fi->pnj[i].pnj->pos.x - (size - 3) * 7;
	float pos_x = s->fi->pnj[i].pnj->pos.x - (size - 3) * 7;
	float pos_y = s->fi->pnj[i].pnj->pos.y - 25;

	s->fi->size_name_pnj = size;
	s->fi->name_head = malloc(sizeof(st_button) * size + 1);
	s->fi->name_head_edge[0] =
	create_object("ressources/images/name_box/name2.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 15, 32), 0);
	for (j = 0; j != size; j++) {
		pos_x = create_name_box_middle(s, i, pos_x, j);
	}
	pos_x = posx + 15 + (12 * j);
	s->fi->name_head_edge[1] =
	create_object("ressources/images/name_box/name1.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 15, 32), 0);
}
