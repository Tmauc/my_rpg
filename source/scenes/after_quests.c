/*
** EPITECH PROJECT, 2018
** after_quests.c
** File description:
** after_quests.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void reset_pos_friends(st_rpg *s)
{
	sfClock_restart(s->proc.gman.clock);
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 144);
	s->fi->pnj[s->cut.zac_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.zac_value].pnj, 144);
	s->fi->pnj[s->cut.jade_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.jade_value].pnj, 144);
	s->fi->pnj[s->cut.samy_value].pnj->pos =
	create_vector2f(7882, 7374);
	s->fi->pnj[s->cut.jade_value].pnj->pos =
	create_vector2f(10000, 10000);
	s->fi->pnj[s->cut.zac_value].pnj->pos =
	create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.jade_value].pnj->sprite,
	s->fi->pnj[s->cut.jade_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
}

void set_position_after_quests(st_rpg *s)
{
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(8100, 7000);
	s->fi->pnj[s->cut.jade_value].pnj->pos = create_vector2f(9230, 7000);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(7950, 7700);
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.jade_value].pnj->sprite,
	s->fi->pnj[s->cut.jade_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->return_value = 0;
	update_death(s);
}

void after_quests(st_rpg *s)
{
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->camera_pos = 0;
	move_camera(s);
	night_scene(s);
	s->fi->pnj[s->cut.zac_value].pnj->rect.left = 0;
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 193);
	s->fi->pnj[s->cut.zac_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.zac_value].pnj, 193);
	s->fi->pnj[s->cut.jade_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.jade_value].pnj, 193);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 193);
	set_position_after_quests(s);
	sfClock_restart(s->proc.gman.clock);
}
