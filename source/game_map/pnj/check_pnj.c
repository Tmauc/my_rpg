/*
** EPITECH PROJECT, 2018
** check_pnj.c
** File description:
** check_pnj file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int check_pnj_withpos_name(st_rpg *s, int j, int i)
{
	if (s->fi->pos[j].x < (s->fi->pnj[i].pnj->pos.x +
	s->fi->ID_character->rect.width + 14)
	&& (s->fi->pos[j].x > s->fi->pnj[i].pnj->pos.x + 14)
	&& (s->fi->pos[j].y < s->fi->pnj[i].pnj->pos.y +
	s->fi->ID_character->rect.height + 66)
	&& (s->fi->pos[j].y > s->fi->pnj[i].pnj->pos.y + 66)) {
		create_box_name(s, i);
		s->fi->oui = 1;
		s->fi->pnj_shade = i;
		return (1);
	} else {
		if (s->fi->oui == 1)
			destroy_name_box(s);
		return (0);
	}
}

void check_pnj_name(st_rpg *s)
{
	int i = 0;
	int j = 0;
	int a = 0;

	while (i != s->fi->max_pnj) {
		j = 0;
		while (j != 10 && a == 0) {
			a = check_pnj_withpos_name(s, j, i);
			j++;
		}
		i++;
	}
}

void check_pnj_withpos(st_rpg *s, int j, int i)
{
	if (s->fi->pos[j].x < (s->fi->pnj[i].pnj->pos.x +
	s->fi->ID_character->rect.width + 14)
	&& (s->fi->pos[j].x > s->fi->pnj[i].pnj->pos.x + 14)
	&& (s->fi->pos[j].y < s->fi->pnj[i].pnj->pos.y +
	s->fi->ID_character->rect.height + 66)
	&& (s->fi->pos[j].y > s->fi->pnj[i].pnj->pos.y + 66)) {
		s->fi->dialog_box_isopen = 1;
		s->fi->nb_pnj = i;
		s->returnv = 0;
		s->fi->return_value = 0;
		stop_player(s);
	}
}

void check_pnj(st_rpg *s)
{
	int i = 0;
	int j = 0;

	while (i != s->fi->max_pnj) {
		j = 0;
		while (j != 10) {
			check_pnj_withpos(s, j, i);
			j++;
		}
		i++;
	}
}
