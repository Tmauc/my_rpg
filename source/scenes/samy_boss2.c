/*
** EPITECH PROJECT, 2018
** samy_boss2.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void dialog_samy_boss_2(st_rpg *s)
{
	s->boss = 1;
	quit_game_for_dungeon(s);
	s->fi->return_value = launch_dungeon(s, &dungeon_boss_samy);
	s->boss = 0;
	sfMusic_stop(s->fi->samy_boss.music);
}

void samy_boss_part2_in_if(st_rpg *s)
{
	s->fi->dream_status = 1;
	s->fi->dialog_box_isopen = 1;
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->reflexion_music.music);
	dialog_box(s, "player_dream2", "hero");
	sfMusic_stop(s->fi->reflexion_music.music);
	sfMusic_play(s->fi->music.music);
	s->fi->dream_status = 0;
	set_all_var_at_zero(s);
	after_quests(s);
	wake_up(s);
	s->fi->dialog_box_isopen = 0;
}
