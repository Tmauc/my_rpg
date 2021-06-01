/*
** EPITECH PROJECT, 2018
** death_zac.c
** File description:
** death_zac.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_samy(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map_samy->sprite, NULL);
	if (s->cut.champ_status == 1)
		sfRenderWindow_drawSprite(s->window,
		s->cut.champ->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->cut.samy_value].pnj->sprite, NULL);
}

void setup_pos_for_scene_samy(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	s->cut.champ_status = 0;
	sfSprite_setScale(s->cut.map_samy->sprite, scale);
	sfSprite_setScale(s->cut.champ->sprite, scale2);
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 144);
	s->fi->pnj[s->cut.samy_value].pnj->pos =
	create_vector2f(s->fi->camera.x + 20, s->fi->camera.y + 500);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x + 20, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}
