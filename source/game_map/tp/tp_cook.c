/*
** EPITECH PROJECT, 2018
** tp_bedroom.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void tp_cook2(st_rpg *s)
{
	s->player.obj->pos.x = 153;
	s->player.obj->pos.y = 8640;
	s->player.obj->rect.top = 96;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}

void tp_cook1(st_rpg *s)
{
	s->player.obj->pos.x = 2636;
	s->player.obj->pos.y = 11194;
	s->player.obj->rect.top = 48;
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	s->fi->camera_pos = 0;
}
