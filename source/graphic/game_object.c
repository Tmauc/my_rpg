/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_obj
*/

#include <stdlib.h>
#include "game_object.h"

void destroy_object(g_object *object)
{
	sfTexture_destroy(object->texture);
	sfSprite_destroy(object->sprite);
	free(object);
}

void destroy_text(t_object *object)
{
	sfText_destroy(object->text);
	sfFont_destroy(object->font);
	free(object);
}

t_object *create_text(char *str, sfVector2f pos, char *font)
{
	t_object *text = malloc(sizeof(t_object));

	text->text = sfText_create();
	text->font = sfFont_createFromFile(font);
	sfText_setString(text->text, str);
	sfText_setFont(text->text, text->font);
	sfText_setColor(text->text, sfWhite);
	sfText_setPosition(text->text, pos);
	return (text);
}

void display_object(sfRenderWindow *window, g_object *object)
{
	sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

g_object *create_object(char *path, sfVector2f pos, sfIntRect rect, float sp)
{
	g_object *object = malloc(sizeof(g_object));

	object->sprite = sfSprite_create();
	object->texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->pos = pos;
	object->rect = rect;
	sfSprite_setPosition(object->sprite, object->pos);
	sfSprite_setTextureRect(object->sprite, object->rect);
	object->speed = sp;
	return (object);
}
