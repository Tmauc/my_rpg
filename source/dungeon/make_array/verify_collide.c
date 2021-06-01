/*
** EPITECH PROJECT, 2018
** verify_collide.c
** File description:
** verify if a rect is not too close from another
*/

#include "my.h"
#include "procedural.h"

int intersect(proom_t *r1, proom_t *r2)
{
	if (r1->pos1[0] <= r2->pos2[0] && r1->pos2[0] >= r2->pos1[0]
	&& r1->pos1[1] <= r2->pos2[1] && r1->pos2[1] >= r2->pos1[1]) {
		return (1);
	}
	return (0);
}

int verify_intersect(proom_t *temp_proom, proc_t *proc, int iter)
{
	for (int i = 0; i < iter; i++) {
		if (intersect(temp_proom, &proc->proom[i]))
			return (1);
	}
	return (0);
}

void new_room(proc_var_t *pvar, proom_t *proom)
{
	proom->width = pvar->min_room_s + (rand() %
	(pvar->max_room_s - pvar->min_room_s + 1));
	proom->height = pvar->min_room_s + (rand() %
	(pvar->max_room_s - pvar->min_room_s + 1));
	proom->pos1[0] = rand() % (pvar->map_width - proom->width - 2) + 1;
	proom->pos1[1] = rand() % (pvar->map_height - proom->height - 2) + 1;
	proom->pos2[0] = proom->pos1[0] + proom->width;
	proom->pos2[1] = proom->pos1[1] + proom->height;
	proom->center[0] = floor((proom->pos1[0] + proom->pos2[0]) / 2);
	proom->center[1] = floor((proom->pos1[1] + proom->pos2[1]) / 2);
	proom->visited = 0;
	proom->drawed = 0;
	proom->last = 0;
}

void make_positions_proom(proc_t *proc)
{
	proom_t temp_proom;
	int iter = 0;

	for (int i = 0; i < proc->pvar.nbr_rooms; i++) {
		new_room(&proc->pvar, &temp_proom);
		if (!verify_intersect(&temp_proom, proc, iter)) {
			proc->proom[iter] = temp_proom;
			iter += 1;
			make_corridors(proc, iter);
		}
	}
	proc->proom[iter].last = 1;
}

void make_holes(proom_t *proom, char **map)
{
	for (int y = proom->pos1[1]; y < proom->pos2[1]; y++) {
		for (int x = proom->pos1[0]; x < proom->pos2[0]; x++) {
			map[y][x] = ' ';
		}
	}
}
