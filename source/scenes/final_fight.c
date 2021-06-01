/*
** EPITECH PROJECT, 2018
** samy_boss.c
** File description:
** samy_boss.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_final_fight(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map_boss->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cut.champ_boss->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->player.obj->sprite, NULL);
}

void dialog_boss(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->player.obj->pos.x,
	s->player.obj->pos.y - 200));
	s->fi->dialog_box_isopen = 1;
	sfMusic_play(s->fi->boss_music.music);
	sfMusic_setLoop(s->fi->boss_music.music, 1);
	dialog_box(s, "champ_final_fight", "Champ");
}

void setup_pos_for_scene_final_fight(st_rpg *s, sfVector2f scale,
sfVector2f scale2)
{
	sfSprite_setScale(s->cut.map_boss->sprite, scale);
	sfSprite_setScale(s->cut.champ_boss->sprite, scale2);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x - 100, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}

void final_fight_part2(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	setup_pos_for_scene_final_fight(s, scale, scale2);
	dialog_boss(s);

	s->boss = 2;
	quit_game_for_dungeon(s);
	s->fi->return_value = launch_dungeon(s, &dungeon_boss_champ);
	s->boss = 0;
	s->fi->boss_status = 0;
	reset_pos_friends(s);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(10000, 10000);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	if (s->fi->return_value == 4) {
		final_fight_ly(s);
	} else {
		sfMusic_stop(s->fi->boss_music.music);
		s->fi->num_dungeon = 0;
	}
}

void final_fight(st_rpg *s)
{
	sfVector2f scale = {1.5, 1.5};
	sfVector2f scale2 = {3, 3};

	s->returnv = 0;
	s->fi->return_value = 0;
	s->fi->num_dungeon = 0;
	sfMusic_stop(s->fi->music.music);
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->camera_pos = 0;
	move_camera(s);
	s->cut.map_boss->pos = create_vector2f(s->fi->camera.x - 740,
	s->fi->camera.y - 560);
	s->cut.champ_boss->pos = create_vector2f(s->fi->camera.x - 180,
	s->fi->camera.y - 150);
	sfSprite_setPosition(s->cut.champ_boss->sprite,
	s->cut.champ_boss->pos);
	sfSprite_setPosition(s->cut.map_boss->sprite,
	s->cut.map_boss->pos);
	s->fi->boss_status = 1;
	final_fight_part2(s, scale, scale2);
}
