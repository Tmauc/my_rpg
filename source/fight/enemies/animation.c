/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void walk_animation_enemy(st_rpg *s, int i)
{
	if (s->f.mob[i]->animcol == 2 || s->f.mob[i]->animcol == 0)
		s->f.mob[i]->animsens = -s->f.mob[i]->animsens;
	s->f.mob[i]->animcol += s->f.mob[i]->animsens;
	s->f.mob[i]->obj->rect.left = s->f.mob[i]->animcol *
	s->f.mob[i]->obj->rect.width;
}

int choose_orientation_enemy(st_rpg *s, int i)
{
	if (abs(s->f.mob[i]->ratios.x * 100) >
	abs(s->f.mob[i]->ratios.y * 100)) {
		if (s->f.mob[i]->ratios.x > 0)
			return (2);
		else
			return (1);
	} else {
		if (s->f.mob[i]->ratios.y > 0)
			return (0);
		else
			return (3);
	}
}

void enemy_animation(st_rpg *s, int i)
{
	if (s->f.mob[i]->ratios.x != 0 || s->f.mob[i]->ratios.y != 0) {
		walk_animation_enemy(s, i);
		s->f.mob[i]->obj->rect.top = choose_orientation_enemy(s, i) *
		s->f.mob[i]->obj->rect.height;
		sfSprite_setTextureRect(s->f.mob[i]->obj->sprite,
		s->f.mob[i]->obj->rect);
	}
}

void enemies_animation(st_rpg *s)
{
	s->f.ent.time = sfClock_getElapsedTime(s->f.ent.clock);
	s->f.ent.sec = s->f.ent.time.microseconds / 1000000.0;
	if (s->f.ent.sec > 0.15) {
		for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
			enemy_animation(s, i);
		}
		sfClock_restart(s->f.ent.clock);
	}
}
