/*
** EPITECH PROJECT, 2018
** check_pnj_for_quests_part2.c
** File description:
** check_pnj_for_quests_part2 file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void check_pnj_for_quests6(st_rpg *s)
{
	if (s->fi->quests[8]->status == 1 && s->fi->num_dungeon == 5) {
		stop_player(s);
		s->returnv = 0;
		s->fi->return_value = 0;
		s->fi->num_dungeon = 0;
		s->player.obj->pos = create_vector2f(7950, 8160);
		sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
		s->fi->camera_pos = 0;
		move_camera(s);
		final_fight(s);
		if (s->fi->return_value != 2) {
			sfText_setString(s->fi->text_finish_quests->text,
			"Quest 5 complete!");
			s->fi->var_for_quests = 255;
			s->fi->quests[8]->status = 2;
		}
		if (s->fi->return_value == 2)
			death_fcnt(s);
	}
}
