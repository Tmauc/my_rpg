/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "my_rpg.h"

int security_map_enemy_y(st_rpg *s, float dt, int i)
{
	int vy = s->f.mob[i]->ratios.y * s->f.mob[i]->stat->vit * 15 * dt;
	int py = s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y * 0.2);
	int sy = s->f.mob[i]->obj->pos.y +
	(s->f.mob[i]->obj->rect.height * s->f.mob[i]->scale.y * 0.8);

	if (sy / 96 < 0 || sy / 96 > s->proc.pvar.map_height
		|| py / 96 < 0 || py / 96 > s->proc.pvar.map_height)
		return (1);
	if ((sy + vy) / 96 < 0 || (sy + vy) / 96 > s->proc.pvar.map_height
		|| (py + vy) / 96 < 0 || (py + vy) /
		96 > s->proc.pvar.map_height)
		return (1);
	return (0);
}

int security_map_enemy(st_rpg *s, float dt, int i)
{
	int vx = s->f.mob[i]->ratios.x * s->f.mob[i]->stat->vit * 15 * dt;
	int px = s->f.mob[i]->obj->pos.x + (s->f.mob[i]->obj->rect.width * s
	->f.mob[i]->scale.x * 0.2);
	int sx = s->f.mob[i]->obj->pos.x + (s->f.mob[i]->obj->rect.width * s
	->f.mob[i]->scale.x * 0.8);

	if (security_map_enemy_y(s, dt, i))
		return (1);
	if (px / 96 < 0 || px / 96 > s->proc.pvar.map_width
		|| sx / 96 < 0 || sx / 96 > s->proc.pvar.map_width)
		return (1);
	if ((sx + vx) / 96 < 0 || (sx + vx) / 96 > s->proc.pvar.map_width
		|| (px + vx) / 96 < 0 || (px + vx) /
		96 > s->proc.pvar.map_width)
		return (1);
	return (0);
}

int security_map(st_rpg *s)
{
	int x = s->player.obj->pos.x;
	int y = s->player.obj->pos.y;
	int ax = s->player.acceleration.x * s->proc.gman.dt;
	int ay = s->player.acceleration.y * s->proc.gman.dt;

	if ((x + 22) / 96 < 0 || (x + 22) / 96 > s->proc.pvar.map_width
	|| (x - 22) / 96 < 0 || (x - 22) / 96 > s->proc.pvar.map_width) {
		return (1);
	} if ((y + 34 + ay) / 96 < 0 || (y + 34 + ay) / 96 > s->proc.pvar.
	map_height || (y + ay) / 96 < 0 || (y + ay) / 96 > s->proc.pvar.
	map_height) {
		return (1);
	} if ((y + 32) / 96 < 0 || (y + 2) / 96 < 0 || (y + 32) / 96 > s->proc.
	pvar.map_height || (y + 2) / 96 > s->proc.pvar.map_height) {
		return (1);
	} if ((x + 24 + ax) / 96 < 0 || (x - 24 + ax) / 96 < 0 ||
		(x + 24 + ax) / 96 > s->proc.pvar.map_width ||
		(x - 24 + ax) / 96 > s->proc.pvar.map_width)
		return (1);
	return (0);
}
