/*
** EPITECH PROJECT, 2018
** move_pnj.c
** File description:
** move_pnj.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

sfIntRect set_texturerect_top(g_object *obj, int top)
{
	obj->rect.top = top;
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	return (obj->rect);
}

void wake_up(st_rpg *s)
{
	s->player.obj->rect.left = 0 + 144 * s->player.cdata.sex;
	sfSprite_setTextureRect(s->player.obj->sprite, s->player.obj->rect);
	while (s->player.obj->pos.y != 8070) {
		move_camera(s);
		s->player.obj->pos.y -= 1;
		sfSprite_setPosition(s->player.obj->sprite,
		s->player.obj->pos);
		draw(s);
	}
	s->player.obj->pos = create_vector2f(7950, 8037);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
	stop_player(s);
	sfClock_restart(s->proc.gman.clock);
}

void set_pnj_meeting_without_zac(st_rpg *s)
{
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 0);
	s->fi->pnj[s->cut.jade_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.jade_value].pnj, 48);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 96);
	s->fi->pnj[s->cut.samy_value].pnj->pos = create_vector2f(8192, 4738);
	s->fi->pnj[s->cut.jade_value].pnj->pos = create_vector2f(8261, 4781);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(10000, 10000);
	s->player.obj->pos = create_vector2f(8131, 4771);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.jade_value].pnj->sprite,
	s->fi->pnj[s->cut.jade_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
}

void start_quests_4(st_rpg *s)
{
	set_pnj_meeting_without_zac(s);
	move_camera(s);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_zac_is_missing1", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_zac_is_missing1", "samy");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_zac_is_missing2", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "jade_zac_is_missing3", "jade");
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "samy_zac_is_missing2", "samy");
	sfMusic_stop(s->fi->reflexion_music.music);
	sfMusic_play(s->fi->music.music);
	stop_player(s);
	sfClock_restart(s->proc.gman.clock);
}

void quests_3(st_rpg *s)
{
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->samys_music.music);
	s->fi->quests[5]->status = 2;
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 0);
	dialog_box(s, "samy_night", "samy");
	sfMusic_stop(s->fi->samys_music.music);
	after_quests(s);
	s->fi->pnj[s->cut.zac_value].pnj->pos = create_vector2f(1000, 1000);
	sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
	s->fi->pnj[s->cut.zac_value].pnj->pos);
	wake_up(s);
	sfMusic_stop(s->fi->music.music);
	sfMusic_play(s->fi->reflexion_music.music);
	background_with_text(s,
	"ressources/images/scenes/background_zach_missing.png",
	"Zach is missing", "ressources/fonts/quests2.otf");
	start_quests_4(s);
}
