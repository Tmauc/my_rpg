/*
** EPITECH PROJECT, 2018
** tp_inside.c
** File description:
** tp_orphanage.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_inside4(st_rpg *s)
{
	s->player.obj->pos.x = 3850;
	s->player.obj->pos.y = 9449;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_inside3(st_rpg *s)
{
	s->player.obj->pos.x = 526;
	s->player.obj->pos.y = 6069;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_inside2(st_rpg *s)
{
	s->player.obj->pos.x = 661;
	s->player.obj->pos.y = 4959;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_inside1(st_rpg *s)
{
	s->player.obj->pos.x = 1615;
	s->player.obj->pos.y = 6229;
	s->player.obj->rect.top = 144;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}
