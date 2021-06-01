/*
** EPITECH PROJECT, 2018
** verify_collisions.c
** File description:
** verify collisions for player and map
*/

#include "my_rpg.h"
#include "my.h"

int enemy_is_ok_horizontal(st_rpg *s, float dt, int i)
{
	int vx = s->f.mob[i]->ratios.x * s->f.mob[i]->stat->vit * 15 * dt;
	int px = s->f.mob[i]->obj->pos.x + (s->f.mob[i]->obj->rect.width * s
	->f.mob[i]->scale.x * 0.2);
	int py = s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y * 0.2);
	int sx = s->f.mob[i]->obj->pos.x + (s->f.mob[i]->obj->rect.width * s
	->f.mob[i]->scale.x * 0.8);
	int sy = s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y * 0.8);

	if (vcollide(s->proc.map[sy / 96][(sx + vx) / 96]) &&
	vcollide(s->proc.map[py / 96][(sx + vx) / 96]) &&
	vcollide(s->proc.map[sy / 96][(px + vx) / 96]) &&
	vcollide(s->proc.map[py / 96][(px + vx) / 96])) {
		return (1);
	}
	return (0);
}

int enemy_is_ok_vertical(st_rpg *s, float dt, int i)
{
	int vy = s->f.mob[i]->ratios.y * s->f.mob[i]->stat->vit * 15 * dt;
	int px = s->f.mob[i]->obj->pos.x + (s->f.mob[i]->obj->rect.width * s
	->f.mob[i]->scale.x * 0.2);
	int py = s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y * 0.2);
	int sx = s->f.mob[i]->obj->pos.x + (s->f.mob[i]->obj->rect.width * s
	->f.mob[i]->scale.x * 0.8);
	int sy = s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y * 0.8);

	if (vcollide(s->proc.map[(sy + vy) / 96][px / 96]) &&
	vcollide(s->proc.map[(py + vy) / 96][sx / 96]) &&
	vcollide(s->proc.map[(sy + vy) / 96][sx / 96]) &&
	vcollide(s->proc.map[(py + vy) / 96][px / 96])) {
		return (1);
	}
	return (0);
}

void pathfinding(st_rpg *s, float dt, int i)
{
	if (security_map_enemy(s, dt, i))
		return;
	if (!enemy_is_ok_vertical(s, dt, i)) {
		s->f.mob[i]->ratios.y = 0;
		if (s->f.mob[i]->ratios.x > 0)
			s->f.mob[i]->ratios.x = 1;
		else
			s->f.mob[i]->ratios.x = -1;
	} if (!enemy_is_ok_horizontal(s, dt, i)) {
		s->f.mob[i]->ratios.x = 0;
		if (s->f.mob[i]->ratios.y > 0)
			s->f.mob[i]->ratios.y = 1;
		else
			s->f.mob[i]->ratios.y = -1;
	}
}

void verify_collide_map_enemies(st_rpg *s, float dt, int i)
{
	int vx = s->f.mob[i]->ratios.x * s->f.mob[i]->stat->vit * 15 * dt;
	int vy = s->f.mob[i]->ratios.y * s->f.mob[i]->stat->vit * 15 * dt;

	if (security_map_enemy(s, dt, i))
		return;
	if (enemy_is_ok_vertical(s, dt, i))
		s->f.mob[i]->obj->pos.y += vy;
	if (enemy_is_ok_horizontal(s, dt, i))
		s->f.mob[i]->obj->pos.x += vx;
}
