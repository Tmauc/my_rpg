/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my_rpg.h"
#include "my.h"

char **get_spinfo(st_rpg *s)
{
	char *tmp = int_to_str(s->player.cdata.classe);
	char **tab = malloc(sizeof(char *) * 21);
	char *str = my_strcat("ressources/spells/", tmp);
	int fd;

	free(tmp);
	tmp = my_strcat(str, "/names");
	free(str);
	fd = open(tmp, O_RDONLY);
	for (int i = 0; i != 20; i += 1)
		tab[i] = get_next_line(fd);
	tab[20] = NULL;
	return (tab);
}

void tree_set_rects(st_rpg *s)
{
	for (int i = 0; i != 3; i += 1) {
		s->treem.pas[i]->rect = create_rect(0, 0, 64, 64);
		s->treem.m2[i]->rect = create_rect(0, 0, 64, 64);
		if (i != 2) {
			s->treem.e[i]->rect = create_rect(0, 0, 64, 64);
			s->treem.r[i]->rect = create_rect(0, 0, 64, 64);
		}
	}
}

void update_tree_pos(st_rpg *s)
{
	int x = s->origin.x + 1535;

	set_tree_positions(s);
	for (int i = 0, dec = 0, m = 3, d = 0; i != 10; i += 1) {
		if (i > 5) {
			d = 61;
			m = 2;
			dec = -90;
		}
		sfSprite_setPosition(s->treem.lock[i]->sprite,
		create_vector2f(x + d + (i % m) * 125 + 13, s->origin.y +
		90 + (i / m) * 90 + dec + 13));
	}
}

void update_tree_mouse(st_rpg *s, int i)
{
	if (mouse_in_origin(s, s->treem.pas[i]))
		tree_proceed(s, i);
	if (mouse_in_origin(s, s->treem.m2[i]))
		tree_proceed(s, i + 3);
	if (i != 2) {
		if (mouse_in_origin(s, s->treem.e[i]))
			tree_proceed(s, i + 6);
		if (mouse_in_origin(s, s->treem.r[i]))
			tree_proceed(s, i + 8);
	}
}

void update_tree_menu(st_rpg *s)
{
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		for (int i = 0; i != 3; i += 1) {
			update_tree_mouse(s, i);
		}
		update_tree_pos(s);
	}
}
