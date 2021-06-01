/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void origin_life_bar(st_rpg *s)
{
	int x = s->origin.x;
	int y = s->origin.y;

	sfSprite_setPosition(s->bar.bars->sprite, create_vector2f(x + 40,
	y + 40));
	sfSprite_setPosition(s->bar.life->sprite, create_vector2f(x + 122,
	y + 58));
	sfSprite_setPosition(s->bar.xp->sprite, create_vector2f(x + 122,
	y + 85));
	sfText_setPosition(s->bar.values[0]->text, create_vector2f(x + 67,
	y + 67));
	sfText_setPosition(s->bar.values[1]->text, create_vector2f(x + 125,
	y + 60));
	sfText_setPosition(s->bar.values[2]->text, create_vector2f(x + 125,
	y + 88));
}
