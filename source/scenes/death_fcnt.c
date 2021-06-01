/*
** EPITECH PROJECT, 2018
** samy_boss.c
** File description:
** samy_boss.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void set_all_var_at_zero(st_rpg *s)
{
	s->fi->var_choice = 0;
	s->fi->nb_choice_pre = 0;
	s->fi->choice_cursor = 0;
}

void death_fcnt(st_rpg *s)
{
	stop_player(s);
	s->returnv = 0;
	s->fi->return_value = 0;
	s->fi->num_dungeon = 0;
	s->player.obj->pos = create_vector2f(7950, 8160);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->camera_pos = 0;
	move_camera(s);
	reset_pos_friends(s);
	after_quests(s);
	wake_up(s);
	sfClock_restart(s->proc.gman.clock);
}
