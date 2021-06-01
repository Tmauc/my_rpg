/*
** EPITECH PROJECT, 2018
** death_zac.c
** File description:
** death_zac.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void dialog_death_zach(st_rpg *s)
{

	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_death_zach1", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_zach1", "samy");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_death_zach2", "jade");
	print_letter(s);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_zach2", "samy");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_death_zach3", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_death_zach3", "samy");
}

void move_all_character_zach(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->player.obj->pos.x,
	s->fi->camera.y - 150));
	move_pnj_zach(s, create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 90), s->cut.jade_value);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x,
	s->fi->camera.y - 190), s->cut.jade_value);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 150,
	s->fi->camera.y - 90), s->cut.samy_value);
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 149,
	s->fi->camera.y - 190), s->cut.samy_value);
	s->fi->pnj[s->cut.jade_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 96);
}

void death_zac_part2(st_rpg *s, sfMusic *music)
{
	move_all_character_zach(s);
	draw(s);
	dialog_death_zach(s);
	s->fi->zach_status = 0;
	reset_pos_friends(s);
	sfMusic_stop(music);
	after_quests(s);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	sfMusic_destroy(music);
	s->fi->dream_status = 1;
	s->fi->dialog_box_isopen = 1;
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->reflexion_music.music);
	dialog_box(s, "player_dream1", "hero");
	sfMusic_stop(s->fi->reflexion_music.music);
	sfMusic_play(s->fi->music.music);
	s->fi->dream_status = 0;
	wake_up(s);
}

void death_zac(st_rpg *s)
{
	sfVector2f scale = {2, 2};
	sfVector2f scale2 = {1.4, 1.4};
	sfMusic *music = create_music(s->s_music,
	"ressources/audio/death_zach.ogg");

	s->cut.map->pos = create_vector2f(s->fi->camera.x - 540,
	s->fi->camera.y - 560);
	s->cut.zachd->pos = create_vector2f(s->fi->camera.x - 50,
	s->fi->camera.y - 190);
	sfSprite_setPosition(s->cut.map->sprite, s->cut.map->pos);
	sfSprite_setPosition(s->cut.zachd->sprite, s->cut.zachd->pos);
	sfMusic_stop(s->fi->music.music);
	sfMusic_setLoop(music, 1);
	sfMusic_play(music);
	s->fi->zach_status = 1;
	setup_pos_for_scene_zach(s, scale, scale2);
	death_zac_part2(s, music);
}
