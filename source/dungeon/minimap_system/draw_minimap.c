/*
** EPITECH PROJECT, 2018
** draw_minimap.c
** File description:
** file to stock all functions about drawing minimap
*/

#include "my.h"
#include "my_rpg.h"

void draw_rect_room(proc_t *proc, int x, int y)
{
	sfColor white_trans = {255, 255, 255, 128};
	sfColor red_trans = {183, 0, 0, 128};
	int size[2] = {12, 12};
	int pos[2];

	pos[0] = x * 12;
	pos[1] = y * 12;
	if (is_wall(proc->map[y][x])) {
		my_draw_rect(proc->minimap.f_minimap,
		pos, size, white_trans);
	} if (proc->map[y][x] == 'S' || proc->map[y][x] == 'B') {
		my_draw_rect(proc->minimap.f_minimap,
		pos, size, red_trans);
	}
}

void draw_rect_corridor(proc_t *proc, int x, int y)
{
	sfColor white_trans = {255, 255, 255, 128};
	int size[2] = {12, 12};
	int pos[2] = {x * 12, y * 12};

	if (is_wall(proc->map[y][x])) {
		my_draw_rect(proc->minimap.f_minimap, pos, size, white_trans);
	}
}

void draw_rect_player(st_rpg *rpg)
{
	sfColor green_trans = {0, 183, 0, 128};
	sfColor trans = {0, 0, 0, 0};
	int size[2] = {12, 12};
	int last_posx = rpg->player.last_pos.x / 96;
	int last_posy = rpg->player.last_pos.y / 96;
	int posx = rpg->player.obj->pos.x / 96;
	int posy = rpg->player.obj->pos.y / 96;

	my_draw_rect(rpg->proc.minimap.f_minimap,
	(int[2]){last_posx * 12, last_posy * 12}, size, trans);
	my_draw_rect(rpg->proc.minimap.f_minimap,
	(int[2]){posx * 12, posy * 12}, size, green_trans);
}
