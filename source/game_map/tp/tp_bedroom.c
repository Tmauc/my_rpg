/*
** EPITECH PROJECT, 2018
** tp_bedroom.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_bedroom3(st_rpg *s)
{
	s->player.obj->pos.x = 7443;
	s->player.obj->pos.y = 9094;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_bedroom2(st_rpg *s)
{
	s->player.obj->pos.x = 8550;
	s->player.obj->pos.y = 9049;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_bedroom(st_rpg *s)
{
	s->player.obj->pos.x = 8792;
	s->player.obj->pos.y = 6969;
	s->player.obj->rect.top = 0;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}
