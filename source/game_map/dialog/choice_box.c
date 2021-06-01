/*
** EPITECH PROJECT, 2018
** dialog_box_menu.c
** File description:
** dialog_box_menu.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_choice_box(st_rpg *s, int compter)
{
	int i = 0;

	while (i != compter) {
		destroy_button(s->fi->pnj[s->fi->nb_pnj].choice_box[i]);
		i++;
	}
	free(s->fi->pnj[s->fi->nb_pnj].choice_box);
	destroy_object(s->fi->pnj[s->fi->nb_pnj].cursor);
	destroy_object(s->fi->pnj[s->fi->nb_pnj].choice_box_edge[0]);
	destroy_object(s->fi->pnj[s->fi->nb_pnj].choice_box_edge[1]);
}

void up_cursor(st_rpg *s)
{
	if (s->fi->choice_cursor > 0) {
		s->fi->pnj[s->fi->nb_pnj].cursor->pos.y -= 60;
		s->fi->var_choice--;
		s->fi->choice_cursor--;
	}
	sfSprite_setPosition(s->fi->pnj[s->fi->nb_pnj].cursor->sprite,
	s->fi->pnj[s->fi->nb_pnj].cursor->pos);
}

void down_cursor(st_rpg *s, int compter)
{
	if (s->fi->choice_cursor < compter - 1) {
		s->fi->pnj[s->fi->nb_pnj].cursor->pos.y += 60;
		s->fi->var_choice++;
		s->fi->choice_cursor++;
	}
	sfSprite_setPosition(s->fi->pnj[s->fi->nb_pnj].cursor->sprite,
	s->fi->pnj[s->fi->nb_pnj].cursor->pos);
}

void choise_box_bouc(st_rpg *s, int compter, char **tab)
{
	int a = 0;
	int i = 0;

	while (a != 1) {
		a = event_choice_box(s, compter);
		draw_choice_menu(s, compter);
	}
	while (tab[i] != NULL) {
		i++;
	}
	destroy_choice_box(s, compter);
}

int choice_box(st_rpg *s, int fd)
{
	int compter = 0;
	char *str = get_next_line(fd);
	char **tab = my_calloc(sizeof(char*) * 1);

	tab = remalloc_tab(tab, str);
	while (1) {
		free(str);
		str = get_next_line(fd);
		if (my_strcmp(str, "<") == 0)
			break;
		tab = remalloc_tab(tab, str);
		compter++;
	}
	compter++;
	create_choice_box(s, compter, tab);
	choise_box_bouc(s, compter, tab);
	return (choice_box_check_quit(s, tab, str, compter));
}
