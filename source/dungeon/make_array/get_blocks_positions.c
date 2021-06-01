/*
** EPITECH PROJECT, 2018
** get_blocks_positions.c
** File description:
** get block positions on the map
*/

#include "my.h"
#include "my_rpg.h"

void verify_entry_pos(proc_t *proc, int y, int x, sfVector2f *result)
{
	if (proc->map[y][x] == 'E' || proc->map[y][x] == 'B') {
		result->y = y * 96 + 48;
		result->x = x * 96 + 48;
	}
}

sfVector2f get_entry_pos(proc_t *proc)
{
	sfVector2f result = {0, 0};

	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++)
			verify_entry_pos(proc, y, x, &result);
	}
	return (result);
}

void verify_exit_pos(proc_t *proc, int y, int x, sfVector2f *result)
{
	if (proc->map[y][x] == 'S' || proc->map[y][x] == 'B') {
		result->y = y * 96;
		result->x = x * 96;
	}
}

sfVector2f get_exit_pos(proc_t *proc)
{
	sfVector2f result = {0, 0};

	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++)
			verify_exit_pos(proc, y, x, &result);
	}
	return (result);
}
