/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** game_object.h
*/

#ifndef GAME_OBJECT_
#define GAME_OBJECT_
#include <SFML/Graphics.h>

typedef struct text_object
{
	sfText *text;
	sfFont *font;
	sfVector2f pos;
} t_object;

typedef struct game_object
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
	float speed;
} g_object;

typedef struct time_manage
{
	float sec;
	sfClock *clock;
	sfTime time;
} st_time;

g_object *create_object(char *path, sfVector2f pos, sfIntRect rect, float sp);
void destroy_object(g_object *object);
void destroy_text(t_object *object);
t_object *create_text(char *str, sfVector2f pos, char *font);

#endif
