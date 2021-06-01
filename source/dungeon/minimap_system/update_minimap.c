/*
** EPITECH PROJECT, 2018
** update_minimap.c
** File description:
** update minimap on screen
*/

#include "my.h"
#include "my_rpg.h"

void increment_visited(st_rpg *rpg)
{
	int posx = rpg->player.obj->pos.x / 96;
	int posy = rpg->player.obj->pos.y / 96;

	for (int i = 0; rpg->proc.proom[i].last == 0; i++) {
		if (rpg->proc.proom[i].visited == 0 &&
		interval(posx, rpg->proc.proom[i].pos1[0] + 1,
		rpg->proc.proom[i].pos2[0] + 2) &&
		interval(posy, rpg->proc.proom[i].pos1[1] + 1,
		rpg->proc.proom[i].pos2[1] + 2)) {
			rpg->proc.proom[i].visited = 1;
		}
	}
}

void draw_room_minimap(proc_t *proc, proom_t *proom)
{
	proom->drawed = 1;
	for (int y = proom->pos1[1] + 1; y < proom->pos2[1] + 3; y++) {
		for (int x = proom->pos1[0] + 1; x < proom->pos2[0] + 3; x++) {
			draw_rect_room(proc, x, y);
		}
	}
}

void make_corridors_minimap(st_rpg *rpg)
{
	int p_pos[2] =
	{rpg->player.obj->pos.x / 96, rpg->player.obj->pos.y / 96};

	for (int y = p_pos[1] - 1; y < p_pos[1] + 2; y++) {
		for (int x = p_pos[0] - 1; x < p_pos[0] + 2; x++) {
			draw_rect_corridor(&rpg->proc, x, y);
		}
	}
}

void update_minimap(st_rpg *rpg)
{
	sfVector2f text_center =
	{rpg->player.obj->pos.x - (48),
		rpg->player.obj->pos.y - HEIGHT / 3.2};

	increment_visited(rpg);
	make_corridors_minimap(rpg);
	sfText_setPosition(rpg->proc.minimap.current_level_text, text_center);
	for (int i = 0; rpg->proc.proom[i].last == 0; i++) {
		if (rpg->proc.proom[i].visited && !rpg->proc.proom[i].drawed)
			draw_room_minimap(&rpg->proc, &rpg->proc.proom[i]);
	}
	draw_rect_player(rpg);
}
