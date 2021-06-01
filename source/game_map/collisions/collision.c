/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void case_relief(st_rpg *s, int nb_ID)
{
	switch (s->fi->map.layer_relief[nb_ID]) {
	case 435:
		s->fi->relief = 2;
		break;
	case 436:
		s->fi->relief = 1;
		break;
	default:
		s->fi->relief = 0;
		break;
	}
}

int collision_id(st_rpg *s)
{
	int i = 0;
	int size_cube = 5 * 32;
	int nb_ID = 0;

	while (i != 10) {
		nb_ID = 60 * ((s->fi->pos[i].y / size_cube))
		+ s->fi->pos[i].x / size_cube;
		if (case_tp(s, nb_ID) == 0) {
			s->fi->camera_pos = 0;
		}
		if (case_id(s, nb_ID) == 1) {
			return (1);
		}
		case_relief(s, nb_ID);
		i++;
	}
	return (0);
}

int check_colpnj(st_rpg *s, int nbr)
{
	int i = 0;

	while (i != 10) {
		if (s->fi->pos[i].x < (s->fi->pnj[nbr].pnj->pos.x +
		s->fi->pnj[nbr].pnj->rect.width)
		&& (s->fi->pos[i].x > s->fi->pnj[nbr].pnj->pos.x)
		&& (s->fi->pos[i].y < s->fi->pnj[nbr].pnj->pos.y +
		s->fi->pnj[nbr].pnj->rect.height + 33)
		&& (s->fi->pos[i].y > s->fi->pnj[nbr].pnj->pos.y)) {
			return (1);
		} else {
			i++;
		}
	}
	return (0);
}

int check_colsquare(st_rpg *s, int nbr)
{
	int i = 0;

	while (i != 10) {
		if (s->fi->pos[i].x > s->fi->colsquare[nbr].pos.x &&
		s->fi->pos[i].x < (s->fi->colsquare[nbr].pos.x +
		s->fi->colsquare[nbr].width) &&
		s->fi->pos[i].y > s->fi->colsquare[nbr].pos.y &&
		s->fi->pos[i].y < (s->fi->colsquare[nbr].pos.y +
		s->fi->colsquare[nbr].height)) {
			return (1);
		} else {
			i++;
		}
	}
	return (0);
}

int check_colcircle(st_rpg *s, int nbr)
{
	float distance_pt_center = 0;
	int i = 0;

	while (i != 10) {
		distance_pt_center = sqrt(powf((s->fi->pos[i].x
		- s->fi->colcircle[nbr].center_circle_x), 2) +
		powf(((s->fi->pos[i].y)
		- s->fi->colcircle[nbr].center_circle_y), 2));
		if (distance_pt_center <= s->fi->colcircle[nbr].rayon_circle) {
			return (1);
		} else
			i++;
	}
	return (0);
}
