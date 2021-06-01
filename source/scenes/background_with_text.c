/*
** EPITECH PROJECT, 2018
** background_with_text.c
** File description:
** background_with_text.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void print_background_with_text(st_rpg *s, g_object *background,
t_object *text_obj)
{
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, background->sprite, NULL);
	sfRenderWindow_drawText(s->window, text_obj->text, NULL);
	sfRenderWindow_display(s->window);
}

void background_with_text(st_rpg *s, char *path_sprite, char *text, char *font)
{
	int compter = 0;
	int posx = s->fi->camera.x - 960;
	int posy = s->fi->camera.y - 540;
	g_object *background;
	t_object *text_obj;

	background = create_object(path_sprite,
	create_vector2f(posx, posy),
	create_rect(0, 0, 1920, 1080), 0);
	text_obj = create_text(text,
	create_vector2f(posx + 200, s->fi->camera.y - 20), font);
	sfText_setColor(text_obj->text, sfBlack);
	sfText_setCharacterSize(text_obj->text, 100);
	while (compter != 200) {
		print_background_with_text(s, background, text_obj);
		compter += 1;
	}
	destroy_object(background);
	destroy_text(text_obj);
}
