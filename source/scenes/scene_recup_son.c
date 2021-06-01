/*
** EPITECH PROJECT, 2018
** scene_recup_son.c
** File description:
** scene_recup_son.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_scene_son(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map_son->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->cut.son_value].pnj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);

}

void move_all_character_son(st_rpg *s)
{
	move_player_to_zach(s, create_vector2f(s->fi->camera.x - 60,
	s->fi->camera.y - 50));
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "save_son1", "Son");
	s->fi->pnj[s->cut.son_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.son_value].pnj, 0);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "save_son2", "Son");
	move_player_to_zach(s, create_vector2f(s->fi->camera.x - 60,
	s->fi->camera.y + 500));
	move_pnj_zach(s, create_vector2f(s->fi->camera.x - 60,
	s->fi->camera.y + 500), s->cut.son_value);
	s->fi->pnj[s->cut.son_value].pnj->pos = create_vector2f(1300, 6155);
	sfSprite_setPosition(s->fi->pnj[s->cut.son_value].pnj->sprite,
	s->fi->pnj[s->cut.son_value].pnj->pos);
	s->player.obj->pos = create_vector2f(1368, 6133);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	move_camera(s);
}

void setup_pos_for_scene_son(st_rpg *s, sfVector2f scale)
{
	sfSprite_scale(s->cut.map_son->sprite, scale);
	s->fi->pnj[s->cut.son_value].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y - 100);
	sfSprite_setPosition(s->fi->pnj[s->cut.son_value].pnj->sprite,
	s->fi->pnj[s->cut.son_value].pnj->pos);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
}

void scene_recup_son(st_rpg *s)
{
	sfVector2f scale = {2, 2};

	s->cut.map_son->pos = create_vector2f(s->fi->camera.x - 540,
	s->fi->camera.y - 560);
	sfSprite_setPosition(s->cut.map_son->sprite, s->cut.map_son->pos);
	s->fi->son_status = 1;
	setup_pos_for_scene_son(s, scale);
	move_all_character_son(s);
	stop_player(s);
	s->fi->son_status = 0;
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 48);
	s->fi->pnj[s->cut.son_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.son_value].pnj, 96);
	s->fi->dialog_box_isopen = 1;
	dialog_box(s, "father_loos_son2", "Matthew");
	s->player.obj->pos = create_vector2f(1368, 6133);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	sfMusic_play(s->fi->music.music);
}
