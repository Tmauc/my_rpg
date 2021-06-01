/*
** EPITECH PROJECT, 2018
** quests_1.c
** File description:
** quests_1.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void quests_1_part2(st_rpg *s)
{
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7888, 7502, s->cut.zac_value);
	s->fi->pnj[s->cut.zac_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.zac_value].pnj, 144);
	s->player.obj->rect = set_texturerect_top(s->player.obj, 0);
	dialog_box(s, "zac_beginning", "zach");
	sfText_setString(s->fi->text_finish_quests->text,
	"Quest 1 complete!");
	s->fi->var_for_quests = 255;
	sfMusic_stop(s->fi->samys_music.music);
}

void quests_1(st_rpg *s)
{
	s->player.animsens = 1;
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->samys_music.music);
	s->fi->quests[0]->status = 2;
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 0);
	dialog_box(s, "samy_beginning", "samy");
	s->fi->dialog_box_isopen = 1;
	move_pnj(s, 7947, 7374, s->cut.jade_value);
	s->player.obj->rect = set_texturerect_top(s->player.obj, 96);
	dialog_box(s, "jade_beginning", "jade");
	quests_1_part2(s);
}
