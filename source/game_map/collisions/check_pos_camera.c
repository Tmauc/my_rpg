/*
** EPITECH PROJECT, 2018
** check_pos_camera.c
** File description:
** check_pos_camera.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void check_pos_angles(st_rpg *s)
{
	if ((s->player.obj->pos.x <= 960 && s->player.obj->pos.x >= 136 &&
		s->player.obj->pos.y <= 532 && s->player.obj->pos.y >= 24) ||
		(s->player.obj->pos.x >= 8634 && s->player.obj->pos.x <= 9378 &&
		s->player.obj->pos.y <= 532 && s->player.obj->pos.y >= 24) ||
		(s->player.obj->pos.y >= 2740 && s->player.obj->pos.y <= 3167 &&
		s->player.obj->pos.x <= 960 && s->player.obj->pos.x >= 136) ||
		(s->player.obj->pos.y >= 2709 && s->player.obj->pos.y <= 3167 &&
		s->player.obj->pos.x >= 8634 && s->player.obj->pos.x <= 9378) ||
		(s->player.obj->pos.y <= 5990 && s->player.obj->pos.y >= 5566 &&
		s->player.obj->pos.x <= 6719 && s->player.obj->pos.x >= 6216) ||
		(s->player.obj->pos.x <= 6719 && s->player.obj->pos.x >= 6216 &&
		s->player.obj->pos.y <= 3915 && s->player.obj->pos.y >= 3709) ||
		(s->player.obj->pos.y <= 3915 && s->player.obj->pos.y >= 3709 &&
		s->player.obj->pos.x <= 8709 && s->player.obj->pos.x >= 7840))
		s->fi->camera_pos = 4;
}

void check_pos_camera_y(st_rpg *s)
{
	if ((s->player.obj->pos.y <= 532 && s->player.obj->pos.y >= 24 &&
		s->player.obj->pos.x >= 136 && s->player.obj->pos.x
		<= 9378) || (s->player.obj->pos.y <= 5990 &&
		s->player.obj->pos.y >= 5566 && s->player.obj->pos.x
		>= 6270 && s->player.obj->pos.x <= 8709))
		s->fi->camera_pos = 3;
	if ((s->player.obj->pos.y >= 2709 && s->player.obj->pos.y
		<= 3167 && s->player.obj->pos.x >= 136 &&
		s->player.obj->pos.x <= 9378) || (s->player.obj->pos.y
		<= 3915 && s->player.obj->pos.y >= 3709 &&
		s->player.obj->pos.x >= 6270 &&
		s->player.obj->pos.x <= 8709))
		s->fi->camera_pos = 3;
	if ((s->player.obj->pos.y >= 3400 && s->player.obj->pos.y
		<= 3900 && s->player.obj->pos.x >= 3526 &&
		s->player.obj->pos.x <= 3900))
		s->fi->camera_pos = 1;
}

void check_pos_camera_x(st_rpg *s)
{
	if ((s->player.obj->pos.x <= 960 && s->player.obj->pos.x >= 136 &&
		s->player.obj->pos.y >= 24 && s->player.obj->pos.y
		<= 3167) || (s->player.obj->pos.x <= 6719 &&
		s->player.obj->pos.x >= 6216 && s->player.obj->pos.y
		>= 3709 && s->player.obj->pos.y <= 5970))
		s->fi->camera_pos = 2;
	if ((s->player.obj->pos.x >= 8634 && s->player.obj->pos.x
		<= 9378 && s->player.obj->pos.y >= 24 &&
		s->player.obj->pos.y <= 3167) || (s->player.obj->pos.x
		<= 8709 && s->player.obj->pos.x >= 7840 &&
		s->player.obj->pos.y >= 3709 && s->player.obj->pos.y
		<= 5970))
		s->fi->camera_pos = 2;
}
