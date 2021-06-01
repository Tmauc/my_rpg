/*
** EPITECH PROJECT, 2018
** destroy_quests.c
** File description:
** destroy_quests.c project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_quests(st_rpg *s)
{
	for (int i = 0; s->fi->quests[i] != NULL; i++) {
		free(s->fi->quests[i]->title);
		free(s->fi->quests[i]->path);
	}
	destroy_button(s->fi->quests_box.quests_box);
	destroy_button(s->fi->quests_box.quests_des);
	destroy_shader(&s->fi->shader);
	destroy_shader(&s->fi->shade_white);
}

void destroy_pnj(st_rpg *s)
{
	int i = 0;

	while (i != s->fi->max_pnj) {
		destroy_object(s->fi->pnj[i].pnj);
		free(s->fi->pnj[i].name);
		i++;
	}
}

void destroy_name_box(st_rpg *s)
{
	for (int i = 0; i != s->fi->size_name_pnj; i++) {
		destroy_button(s->fi->name_head[i]);
	}
	free(s->fi->name_head);
	destroy_object(s->fi->name_head_edge[0]);
	destroy_object(s->fi->name_head_edge[1]);
	s->fi->oui = 0;
}
