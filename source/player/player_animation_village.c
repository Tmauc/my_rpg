/*
** EPITECH PROJECT, 2018
** player_animations.c
** File description:
** anim for player
*/

#include "my.h"
#include "my_rpg.h"

int choose_orientation(st_rpg *s)
{
	if (abs(s->player.nbr_frame.x) > abs(s->player.nbr_frame.y)) {
		if (s->player.nbr_frame.x > 0)
			return (2);
		else
			return (1);
	} else {
		if (s->player.nbr_frame.y > 0)
			return (0);
		else
			return (3);
	}
}

void player_animation_village(st_rpg *s)
{
	if (abs(s->player.nbr_frame.x) != 0 ||
	abs(s->player.nbr_frame.y) != 0) {
		walk_animation(s);
		s->player.obj->rect.top = choose_orientation(s) * 48;
		sfSprite_setTextureRect(s->player.obj->sprite,
		s->player.obj->rect);
	}
}
