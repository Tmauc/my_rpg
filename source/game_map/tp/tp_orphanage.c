/*
** EPITECH PROJECT, 2018
** tp_orphanage.c
** File description:
** tp_orphanage.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_village(st_rpg *s)
{
	s->player.obj->pos.x = 6438;
	s->player.obj->pos.y = 184;
	s->player.obj->rect.top = 96;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera = create_vector2f(6438, 550);
	s->fi->camera_prec = s->fi->camera;
	s->fi->camera_pos = 3;
}

void tp_orphanage(st_rpg *s)
{
	s->player.obj->pos.x = 7224;
	s->player.obj->pos.y = 5968;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera = create_vector2f(7226, 5566);
	s->fi->camera_prec = s->fi->camera;
	s->fi->camera_pos = 3;
}
