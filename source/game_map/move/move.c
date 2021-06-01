/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void move_camera2(st_rpg *s)
{
	switch (s->fi->camera_pos) {
	case 2:
		s->fi->camera.x = s->fi->camera_prec.x;
		s->fi->camera.y = s->player.obj->pos.y;
		s->fi->camera_prec.y = s->fi->camera.y;
		break;
	case 3:
		s->fi->camera.y = s->fi->camera_prec.y;
		s->fi->camera.x = s->player.obj->pos.x;
		s->fi->camera_prec.x = s->fi->camera.x;
		break;
	case 4:
		s->fi->camera.y = s->fi->camera_prec.y;
		s->fi->camera.x = s->fi->camera_prec.x;
		break;
	}
}

void move_camera(st_rpg *s)
{
	check_pos_camera_x(s);
	check_pos_camera_y(s);
	check_pos_angles(s);
	switch (s->fi->camera_pos) {
	case 0:
		s->fi->camera = s->player.obj->pos;
		s->fi->camera_prec = s->fi->camera;
		break;
	case 1:
		s->fi->camera.x = 3717;
		s->fi->camera.y = 4086;
		break;
	default:
		move_camera2(s);
		break;
	}
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->window, s->fi->view);
}
