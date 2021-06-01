/*
** EPITECH PROJECT, 2018
** samy_boss.c
** File description:
** samy_boss.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_samy_boss(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window,
	s->cut.map_samy_boss->sprite, NULL);
	if (s->cut.samy_boss_status == 1)
		sfRenderWindow_drawSprite(s->window,
		s->cut.samy_boss->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cut.samyd->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
}

void dialog_samy_boss(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->fi->camera.x - 180,
	s->fi->camera.y));
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
	s->fi->dialog_box_isopen = 1;
	sfMusic_play(s->fi->samys_music.music);
	dialog_box(s, "samy_boss_samy1", "Samy");
	s->cut.samy_boss_status = 1;
	sfMusic_stop(s->fi->samys_music.music);
	sfMusic_play(s->fi->samy_boss.music);
	s->cut.samy_boss->pos = create_vector2f(s->cut.samyd->pos.x + 10,
	s->cut.samyd->pos.y - 25);
	s->cut.samyd->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->cut.samyd->sprite, s->cut.samyd->pos);
	sfSprite_setPosition(s->cut.samy_boss->sprite, s->cut.samy_boss->pos);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_boss_samy2", "Samy");
	dialog_samy_boss_2(s);
}

void setup_pos_for_scene_samy_boss(st_rpg *s, sfVector2f scale,
sfVector2f scale2)
{
	sfVector2f scale3 = {3, 3};

	sfSprite_setScale(s->cut.map_samy_boss->sprite, scale);
	sfSprite_setScale(s->cut.samyd->sprite, scale2);
	sfSprite_setScale(s->cut.samy_boss->sprite, scale3);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x + 20, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}

void samy_boss_part2(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	setup_pos_for_scene_samy_boss(s, scale, scale2);
	dialog_samy_boss(s);
	s->cut.samy_boss_status = 0;
	s->fi->samy_boss_status = 0;
	reset_pos_friends(s);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	if (s->fi->return_value == 4) {
		samy_boss_part2_in_if(s);
	}
}

void samy_boss(st_rpg *s)
{
	sfVector2f scale = {1.5, 1.5};
	sfVector2f scale2 = {1.4, 1.4};

	s->returnv = 0;
	s->fi->return_value = 0;
	s->fi->num_dungeon = 0;
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->camera_pos = 0;
	move_camera(s);
	s->cut.map_samy_boss->pos = create_vector2f(s->fi->camera.x - 740,
	s->fi->camera.y - 560);
	s->cut.samyd->pos = create_vector2f(s->fi->camera.x - 180,
	s->fi->camera.y - 150);
	sfSprite_setPosition(s->cut.map_samy_boss->sprite,
	s->cut.map_samy_boss->pos);
	sfSprite_setPosition(s->cut.samyd->sprite, s->cut.samyd->pos);
	sfMusic_stop(s->fi->music.music);
	s->fi->samy_boss_status = 1;
	samy_boss_part2(s, scale, scale2);
}
