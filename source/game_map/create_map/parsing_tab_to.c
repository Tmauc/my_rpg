/*
** EPITECH PROJECT, 2018
** parsing_tab_to.c
** File description:
** parsing_tab_to.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int tab_circle(char **tab, int i, st_rpg *s, int circle)
{
	s->fi->colcircle[circle].rayon_circle =
	((str_to_int(tab[i]) / 100) / 2) * 5;
	i++;
	s->fi->colcircle[circle].center_circle_x =
	((str_to_int(tab[i]) / 100) * 5) +
	s->fi->colcircle[circle].rayon_circle;
	i++;
	s->fi->colcircle[circle].center_circle_y =
	((str_to_int(tab[i]) / 100) * 5)+ s->fi->colcircle[circle].rayon_circle;
	i++;
	return (i);
}

int tab_square(char **tab, int i, st_rpg *s, int square)
{
	s->fi->colsquare[square].pos.x = (str_to_int(tab[i]) / 100) * 5;
	i++;
	s->fi->colsquare[square].pos.y = (str_to_int(tab[i]) / 100) * 5;
	i++;
	s->fi->colsquare[square].width = (str_to_int(tab[i]) / 100) * 5;
	i++;
	s->fi->colsquare[square].height = (str_to_int(tab[i]) / 100) * 5;
	i++;
	return (i);
}

void tab_to_struct(st_rpg *s, char **tab, int y)
{
	int compter = 0;
	int circle = 0;
	int square = 0;
	int i = 0;

	while (compter != 521) {
		if (my_strcmp("yes", tab[i]) == 0) {
			i++;
			i = tab_circle(tab, i, s, circle);
			circle++;
		} else if (my_strcmp("no", tab[i]) == 0) {
			i++;
			i = tab_square(tab, i, s, square);
			square++;
		}
		compter++;
	}
	free_tab(tab, y);
}
