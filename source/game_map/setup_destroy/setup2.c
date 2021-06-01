/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setup_pnj_value(st_rpg *s)
{
	s->fi->nb_pnj = 2;
	s->fi->max_pnj = 18;
	s->cut.samy_value = 14;
	s->cut.jade_value = 17;
	s->cut.zac_value = 3;
	s->cut.son_value = 12;
	s->fi->size_name_pnj = 0;
}

void setup_music(st_rpg *s)
{
	s->fi->music.music =
	create_music(s->s_music, "ressources/audio/Alaria city.ogg");
	s->fi->samys_music.music =
	create_music(s->s_music, "ressources/audio/Samy's Theme.ogg");
	s->fi->reflexion_music.music =
	create_music(s->s_music, "ressources/audio/reflexion.ogg");
	s->fi->samy_boss.music =
	create_music(s->s_music, "ressources/audio/boss_samy.ogg");
	s->fi->boss_music.music =
	create_music(s->s_music, "ressources/audio/boss.ogg");
}

void setup_col(st_rpg *s)
{
	sfVector2f scale = {5, 5};

	s->fi->nbr_colcircle = 42;
	s->fi->nbr_colsquare = 479;
	s->fi->direction = 3;
	s->fi->lake = create_object("ressources/map_preset/lake.png",
	create_vector2f(2720, 0), create_rect(0, 0, 288, 366), 0);
	sfSprite_scale(s->fi->lake->sprite, scale);
}

void setup_camera(st_rpg *s)
{
	s->fi->view = sfView_create();
	s->fi->view = sfView_copy(sfRenderWindow_getDefaultView(s->window));
	s->fi->camera.x = s->player.obj->pos.x;
	s->fi->camera.y = s->player.obj->pos.y;
	s->fi->camera_prec.x = s->player.obj->pos.x;
	s->fi->camera_prec.y = s->player.obj->pos.y;
	s->fi->camera_pos = 0;
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->window, s->fi->view);
}
