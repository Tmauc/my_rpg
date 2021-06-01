/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_enemy(enemy_t *enemy)
{
	free(enemy->stat);
	destroy_object(enemy->life);
	destroy_object(enemy->obj);
	destroy_effect(enemy->stun);
	destroy_effect(enemy->poison);
}

void update_life_bars_enemies(st_rpg *s, int i)
{
	if (s->f.mob[i]->stat->pva <= 0) {
		s->f.mob[i]->stat->pva = s->f.mob[i]->stat->pvm;
		s->f.mob[i]->alive = 0;
		loot_enemy(s);
	}
	sfSprite_setPosition(s->f.mob[i]->life->sprite,
	create_vector2f(s->f.mob[i]->obj->pos.x,
	s->f.mob[i]->obj->pos.y - 20));
	s->f.mob[i]->life->rect.width = (s->f.mob[i]->obj->rect.width
	* s->f.mob[i]->stat->pva / s->f.mob[i]->stat->pvm) *
	s->f.mob[i]->scale.x;
	sfSprite_setTextureRect(s->f.mob[i]->life->sprite,
	s->f.mob[i]->life->rect);
}

void choose_display_enemies(st_rpg *s, int i)
{
	if (s->f.mob[i]->poison->count > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[i]->obj->sprite, &s->f.shade.poison.state);
		if (!s->boss)
			sfRenderWindow_drawSprite(s->window,
			s->f.mob[i]->life->sprite, &s->f.shade.poison.state);
	} else if (s->f.mob[i]->stun->count > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[i]->obj->sprite, &s->f.shade.stun.state);
		if (!s->boss)
			sfRenderWindow_drawSprite(s->window,
			s->f.mob[i]->life->sprite, &s->f.shade.stun.state);
	} else {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[i]->obj->sprite, NULL);
		if (!s->boss)
			sfRenderWindow_drawSprite(s->window,
			s->f.mob[i]->life->sprite, NULL);
	}
}

void display_enemies(st_rpg *s)
{
	if (s->boss != 0) {
		display_boss(s);
		return;
	}
	for (int i = 0; i < s->proc.pvar.enemy_nbr; i += 1) {
		if (s->f.mob[i]->alive) {
			choose_display_enemies(s, i);
		}
	}
}
