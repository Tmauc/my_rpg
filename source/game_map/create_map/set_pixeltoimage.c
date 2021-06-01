/*
** EPITECH PROJECT, 2018
** set_pixeltoimage.c
** File description:
** set_pixeltoimage.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void set_background(st_rpg *s)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	s->fi->map.texture =
	sfTexture_createFromImage(s->fi->map.map_backgound, NULL);
	s->fi->map.sprite = sfSprite_create();
	sfSprite_scale(s->fi->map.sprite, invers);
	sfSprite_setTextureRect(s->fi->map.sprite, s->fi->map.square);
	sfSprite_setTexture(s->fi->map.sprite, s->fi->map.texture, sfTrue);
}

void set_relief(st_rpg *s)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	s->fi->map.texture5 =
	sfTexture_createFromImage(s->fi->map.map_relief, NULL);
	s->fi->map.sprite5 = sfSprite_create();
	sfSprite_scale(s->fi->map.sprite5, invers);
	sfSprite_setTextureRect(s->fi->map.sprite5, s->fi->map.square);
	sfSprite_setTexture(s->fi->map.sprite5, s->fi->map.texture5, sfTrue);
}

void set_col(st_rpg *s)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	s->fi->map.texture2 =
	sfTexture_createFromImage(s->fi->map.map_col, NULL);
	s->fi->map.sprite2 = sfSprite_create();
	sfSprite_scale(s->fi->map.sprite2, invers);
	sfSprite_setTextureRect(s->fi->map.sprite2, s->fi->map.square);
	sfSprite_setTexture(s->fi->map.sprite2, s->fi->map.texture2, sfTrue);
}

void set_colid(st_rpg *s)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	s->fi->map.texture3 =
	sfTexture_createFromImage(s->fi->map.map_colID, NULL);
	s->fi->map.sprite3 = sfSprite_create();
	sfSprite_scale(s->fi->map.sprite3, invers);
	sfSprite_setTextureRect(s->fi->map.sprite3, s->fi->map.square);
	sfSprite_setTexture(s->fi->map.sprite3, s->fi->map.texture3, sfTrue);
}

void set_prof(st_rpg *s)
{
	sfVector2f invers;

	invers.x = 5;
	invers.y = 5;
	s->fi->map.texture4 =
	sfTexture_createFromImage(s->fi->map.map_prof, NULL);
	s->fi->map.sprite4 = sfSprite_create();
	sfSprite_scale(s->fi->map.sprite4, invers);
	sfSprite_setTextureRect(s->fi->map.sprite4, s->fi->map.square);
	sfSprite_setTexture(s->fi->map.sprite4, s->fi->map.texture4, sfTrue);
}
