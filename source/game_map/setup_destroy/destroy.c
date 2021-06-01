/*
** EPITECH PROJECT, 2018
** delete.c
** File description:
** delete file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void destroy_all_obj(st_rpg *s)
{
	destroy_object(s->player.obj);
	destroy_object(s->fi->ID_character);
	destroy_object(s->fi->loading);
	destroy_object(s->cut.map);
	destroy_object(s->cut.map_samy);
	destroy_object(s->cut.zachd);
	destroy_object(s->cut.champ);
	destroy_object(s->cut.map_samy_boss);
	destroy_object(s->cut.samyd);
	destroy_object(s->cut.samy_boss);
	destroy_object(s->fi->lake);
	destroy_object(s->cut.map_son);
	destroy_object(s->cut.map_boss);
	destroy_object(s->cut.champ_boss);
	destroy_object(s->cut.ly_boss);
	destroy_object(s->cut.ly_death);
	destroy_object(s->cut.champ_death);
	destroy_object(s->cut.begin);
}

void destroy_music(st_rpg *s)
{
	sfMusic_destroy(s->fi->music.music);
	sfMusic_destroy(s->fi->samys_music.music);
	sfMusic_destroy(s->fi->reflexion_music.music);
	sfMusic_destroy(s->fi->samy_boss.music);
	sfMusic_destroy(s->fi->boss_music.music);
}

void destroy_sprite(st_rpg *s)
{
	sfSprite_destroy(s->fi->map.sprite);
	sfSprite_destroy(s->fi->map.sprite2);
	sfSprite_destroy(s->fi->map.sprite3);
	sfSprite_destroy(s->fi->map.sprite4);
	sfSprite_destroy(s->fi->map.sprite5);
}

void destroy_texture(st_rpg *s)
{
	sfTexture_destroy(s->fi->map.texture);
	sfTexture_destroy(s->fi->map.texture2);
	sfTexture_destroy(s->fi->map.texture3);
	sfTexture_destroy(s->fi->map.texture4);
	sfTexture_destroy(s->fi->map.texture5);
}

void destroy(st_rpg *s)
{
	sfImage_destroy(s->fi->map.image);
	sfImage_destroy(s->fi->map.map_backgound);
	sfImage_destroy(s->fi->map.map_relief);
	sfImage_destroy(s->fi->map.map_col);
	sfImage_destroy(s->fi->map.map_colID);
	sfImage_destroy(s->fi->map.map_prof);
	destroy_sprite(s);
	destroy_texture(s);
	destroy_pnj(s);
	destroy_quests(s);
	destroy_all_obj(s);
	sfClock_destroy(s->fi->time.clock);
	sfClock_destroy(s->fi->pnj_clock.clock);
	sfClock_destroy(s->fi->clock);
	sfClock_destroy(s->fi->lake_clock.clock);
	destroy_music(s);
	destroy_inventory(s);
	free_all(s);
}
