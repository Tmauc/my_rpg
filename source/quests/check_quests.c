/*
** EPITECH PROJECT, 2018
** check_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void set_all_before_quests(st_rpg *s, int i)
{
	i--;
	while (i >= 0) {
		s->fi->quests[i]->status = 3;
		i--;
	}
}

void check_status_for_finish_quests(st_rpg *s, int i)
{
	s->fi->quests[i]->status = 3;
	if (s->fi->quests[i + 1] != NULL)
		s->fi->quests[i + 1]->status = 1;
}

void check_status_quests(st_rpg *s)
{
	for (int i = 0; s->fi->quests[i] != NULL; i++) {
		if (s->fi->quests[i]->status == 2)
			check_status_for_finish_quests(s, i);
		if (s->fi->quests[i]->status == 3 ||
			s->fi->quests[i]->status == 1)
			set_all_before_quests(s, i);
	}
}

void update_quests_box_des(st_rpg *s)
{
	int file = open(s->fi->quests[s->fi->quests_box.nb_quests]->path,
	O_RDONLY);
	char buffer[51] = {'\0'};
	char *str = NULL;
	char *temp = NULL;
	int toto = 50;

	while (toto == 50) {
		toto = read(file, buffer, 50);
		buffer[toto] = '\0';
		temp = my_strcat(str, buffer);
		free(str);
		str = temp;
	}
	sfText_setString(s->fi->quests_box.quests_des->text->text, str);
	close(file);
}

void check_quests(st_rpg *s)
{
	check_status_quests(s);
	for (int i = 0; s->fi->quests[i] != NULL; i++) {
		if (s->fi->quests[i]->status == 1) {
			s->fi->quests_box.nb_quests = i;
			sfText_setString(s->fi->quests_box.quests_box
			->text->text, s->fi->quests[i]->title);
		}
	}
}
