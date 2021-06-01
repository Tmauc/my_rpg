/*
** EPITECH PROJECT, 2018
** mandatory_blocks.c
** File description:
** spawn mandatory blocks like entry and leave
*/

#include "my.h"
#include "my_rpg.h"

int count_rooms(proom_t *proom)
{
	int res = 0;

	while (proom[res].last == 0)
		res += 1;
	return (res);
}

void create_entry(proc_t *proc)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room].pos1[0] +
	(rand() % (proc->proom[room].width));
	int posy = proc->proom[room].pos1[1] +
	(rand() % (proc->proom[room].height));

	proc->map[posy + 2][posx + 2] = 'E';
}

void create_leave(proc_t *proc)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room].pos1[0] +
	(rand() % (proc->proom[room].width));
	int posy = proc->proom[room].pos1[1] +
	(rand() % (proc->proom[room].height));

	if (proc->map[posy + 2][posx + 2] == 'E')
		proc->map[posy + 2][posx + 2] = 'B';
	else
		proc->map[posy + 2][posx + 2] = 'S';
}
