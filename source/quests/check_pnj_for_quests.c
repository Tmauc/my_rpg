/*
** EPITECH PROJECT, 2018
** check_pnj_for_quests.c
** File description:
** check_pnj_for_quests file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void check_pnj_for_quests5(st_rpg *s)
{
	if (s->fi->quests[7]->status == 1 && s->fi->num_dungeon == 4) {
		stop_player(s);
		s->returnv = 0;
		s->fi->return_value = 0;
		s->fi->num_dungeon = 0;
		s->player.obj->pos = create_vector2f(7950, 8160);
		sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
		s->fi->camera_pos = 0;
		move_camera(s);
		death_samy(s);
		if (s->fi->return_value != 2) {
			sfText_setString(s->fi->text_finish_quests->text,
			"Quest 4 complete!");
			s->fi->var_for_quests = 255;
			s->fi->quests[7]->status = 2;
		}
	}
	if (s->fi->return_value == 2)
		death_fcnt(s);
	check_pnj_for_quests6(s);
}

void check_pnj_for_quests4(st_rpg *s)
{
	if (s->fi->quests[6]->status == 1 && s->fi->num_dungeon == 3) {
		stop_player(s);
		s->returnv = 0;
		s->fi->return_value = 0;
		s->fi->num_dungeon = 0;
		s->fi->quests[6]->status = 2;
		s->player.obj->pos = create_vector2f(7950, 8160);
		sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
		s->fi->camera_pos = 0;
		move_camera(s);
		death_zac(s);
		if (s->fi->return_value != 2) {
			sfText_setString(s->fi->text_finish_quests->text,
			"Quest 3 complete!");
			s->fi->var_for_quests = 255;
		}
	}
	check_pnj_for_quests5(s);
}

void check_pnj_for_quests3(st_rpg *s)
{
	if (s->fi->quests[5]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Samy") == 0) {
		stop_player(s);
		sfText_setString(s->fi->text_finish_quests->text,
		"Quest 2 complete!");
		s->fi->var_for_quests = 255;
		quests_3(s);
	}
	check_pnj_for_quests4(s);
}

void check_pnj_for_quests2(st_rpg *s)
{
	if (s->fi->quests[3]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Matthew") == 0) {
		s->fi->quests[3]->status = 2;
		s->fi->dialog_box_isopen = 1;
		dialog_box(s, "father_loos_son1", "Matthew");
	} if (s->fi->quests[4]->status == 1 && s->fi->num_dungeon == 2) {
		s->fi->quests[4]->status = 2;
		s->returnv = 0;
		s->fi->return_value = 0;
		s->fi->num_dungeon = 0;
		s->player.obj->pos = create_vector2f(7950, 8160);
		sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
		s->fi->camera_pos = 0;
		move_camera(s);
		scene_recup_son(s);
		reset_pos_friends(s);
	}
	check_pnj_for_quests3(s);
}

void check_pnj_for_quests(st_rpg *s)
{
	if (s->fi->quests[0]->status == 1 && s->fi->begin_status == 0)
		begin_scene(s);
	if (s->fi->quests[0]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Samy") == 0) {
		stop_player(s);
		quests_1(s);
		after_quests(s);
		wake_up(s);
	} if (s->fi->quests[1]->status == 1 &&
	my_strcmp(s->fi->pnj[s->fi->nb_pnj].name, "Holm") == 0) {
		stop_player(s);
		s->fi->quests[1]->status = 2;
	} if (s->fi->quests[2]->status == 1 && s->fi->num_dungeon == 1) {
		s->fi->num_dungeon = 0;
		s->fi->quests[2]->status = 2;
		reset_pos_friends(s);
	}
	check_pnj_for_quests2(s);
	if (s->fi->return_value == 2)
		death_fcnt(s);
}
