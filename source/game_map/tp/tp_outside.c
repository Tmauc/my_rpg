/*
** EPITECH PROJECT, 2018
** tp_outside.c
** File description:
** tp_outside.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_outside4(st_rpg *s)
{
	s->player.obj->pos.x = 7233;
	s->player.obj->pos.y = 4301;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_outside3(st_rpg *s)
{
	s->player.obj->pos.x = 5025;
	s->player.obj->pos.y = 1401;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_outside2(st_rpg *s)
{
	s->player.obj->pos.x = 4062;
	s->player.obj->pos.y = 1730;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_outside1(st_rpg *s)
{
	s->player.obj->pos.x = 4395;
	s->player.obj->pos.y = 2512;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}
