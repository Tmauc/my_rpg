/*
** EPITECH PROJECT, 2018
** tp_corridor.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_corridor3(st_rpg *s)
{
	s->player.obj->pos.x = 4472;
	s->player.obj->pos.y = 7020;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_corridor2(st_rpg *s)
{
	s->player.obj->pos.x = 5116;
	s->player.obj->pos.y = 7020;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_corridor1(st_rpg *s)
{
	s->player.obj->pos.x = 5847;
	s->player.obj->pos.y = 7020;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}
