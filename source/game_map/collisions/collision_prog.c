/*
** EPITECH PROJECT, 2018
** collision_prog.c
** File description:
** collision_prog.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int collision_prog_2(st_rpg *s)
{
	int nbr = 0;

	while (nbr < s->fi->max_pnj) {
		if (check_colpnj(s, nbr) == 1) {
			return (1);
		} else
			nbr++;
	}
	return (0);
}

int collision_prog(st_rpg *s)
{
	int nbr = 0;

	while (nbr < s->fi->nbr_colcircle) {
		if (check_colcircle(s, nbr) == 1) {
			return (1);
		} else
			nbr++;
	}
	nbr = 0;
	while (nbr < s->fi->nbr_colsquare) {
		if (check_colsquare(s, nbr) == 1) {
			return (1);
		} else
			nbr++;
	}
	return (collision_prog_2(s));
}

int collision(st_rpg *s)
{
	if (collision_id(s) == 1)
		return (1);
	else {
		return (collision_prog(s));
	}
}
