/*
** EPITECH PROJECT, 2018
** death_zac.c
** File description:
** death_zac.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void print_letter(st_rpg *s)
{
	sfEvent event;
	g_object *letter =
	create_object("ressources/images/scenes/letter_death_zach.jpg",
	create_vector2f(s->fi->camera.x, s->fi->camera.y - 960),
	create_rect(0, 0, 531, 761), 0);

	sfSprite_setPosition(letter->sprite, create_vector2f(s->fi->camera.x -
	(letter->rect.width / 2), s->fi->camera.y - (letter->rect.height / 2)));
	while (42) {
		sfRenderWindow_pollEvent(s->window, &event);
		draw_all(s);
		sfRenderWindow_drawSprite(s->window, letter->sprite, NULL);
		sfRenderWindow_display(s->window);
		if (sfKeyboard_isKeyPressed(sfKeyReturn)
			&& event.type == sfEvtKeyPressed)
			break;
	}
	destroy_object(letter);
}

void draw_scene_zach(st_rpg *s)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->cut.map->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cut.zachd->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->player.obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->cut.samy_value].pnj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->fi->pnj[s->cut.jade_value].pnj->sprite, NULL);
}

void setup_pos_for_scene_zach(st_rpg *s, sfVector2f scale, sfVector2f scale2)
{
	sfSprite_scale(s->cut.map->sprite, scale);
	sfSprite_scale(s->cut.zachd->sprite, scale2);
	s->player.obj->rect =
	set_texturerect_top(s->player.obj, 144);
	s->fi->pnj[s->cut.jade_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.jade_value].pnj, 144);
	s->fi->pnj[s->cut.samy_value].pnj->rect =
	set_texturerect_top(s->fi->pnj[s->cut.samy_value].pnj, 144);
	s->player.obj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 400);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	s->fi->pnj[s->cut.samy_value].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 500);
	s->fi->pnj[s->cut.jade_value].pnj->pos =
	create_vector2f(s->fi->camera.x - 60, s->fi->camera.y + 500);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.jade_value].pnj->sprite,
	s->fi->pnj[s->cut.jade_value].pnj->pos);
	sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
	s->fi->pnj[s->cut.samy_value].pnj->pos);
}
