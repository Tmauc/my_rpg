/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

float get_angle_enemy(st_rpg *s, int i)
{
	float mx = s->player.obj->pos.x -
	(s->f.mob[i]->obj->pos.x +
	(s->f.mob[i]->obj->rect.width * s->f.mob[i]->scale.x) / 2);
	float my = s->player.obj->pos.y -
	(s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y) / 2);

	if (my <= 0) {
		return (-acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	} else {
		return (acos(mx / hypot(mx, my)) * (180 / 3.14159265));
	}
}

void enemy_idle(st_rpg *s, float dt, int i)
{
	if (s->f.mob[i]->idlecount >= 0) {
		s->f.mob[i]->idlecount -= dt;
	} if (s->f.mob[i]->alive && !s->f.mob[i]->aggro &&
	s->f.mob[i]->idlecount < 0) {
		s->f.mob[i]->idle = rand() % 3;
		s->f.mob[i]->idlecount = 1;
		if (s->f.mob[i]->idle == 1)
			s->f.mob[i]->ratios = get_ratios(rand() % 360);
		else
			s->f.mob[i]->ratios = (sfVector2f){0, 0};
	} if (!s->f.mob[i]->aggro) {
		verify_collide_map_enemies(s, dt, i);
		sfSprite_setPosition(s->f.mob[i]->obj->sprite,
		s->f.mob[i]->obj->pos);
		sfSprite_setPosition(s->f.mob[i]->life->sprite,
		create_vector2f(s->f.mob[i]->obj->pos.x,
		s->f.mob[i]->obj->pos.y - 20));
	}
}

void movement_enemies(st_rpg *s, int i, float dt)
{
	enemy_idle(s, dt, i);
	if (s->f.mob[i]->alive && s->f.mob[i]->cast != 2 &&
	s->f.mob[i]->aggro) {
		s->f.mob[i]->ratios = get_ratios(get_angle_enemy(s, i));
		if (s->f.mob[i]->type == 6)
			s->f.mob[i]->ratios = get_ratios(get_angle_enemy(s,
			i) + 45);
		pathfinding(s, dt, i);
		verify_collide_map_enemies(s, dt, i);
		sfSprite_setPosition(s->f.mob[i]->obj->sprite,
		s->f.mob[i]->obj->pos);
		sfSprite_setPosition(s->f.mob[i]->life->sprite,
		create_vector2f(s->f.mob[i]->obj->pos.x,
		s->f.mob[i]->obj->pos.y - 20));
	}
}

void set_aggro_enemies(st_rpg *s, int i)
{
	sfCircleShape *circle = sfCircleShape_create();

	sfCircleShape_setRadius(circle, 600);
	sfCircleShape_setPosition(circle, (sfVector2f)
	{s->f.mob[i]->obj->pos.x + s->f.mob[i]->obj->rect.width / 2 - 600,
		s->f.mob[i]->obj->pos.y +
		s->f.mob[i]->obj->rect.height / 2 - 600});
	if (circle_hitbox(circle, s->player.obj) && s->f.rog.vanish <= 0)
		s->f.mob[i]->aggro = 1;
	if ( s->f.rog.vanish > 0)
		s->f.mob[i]->aggro = 0;
	sfCircleShape_destroy(circle);
}
