/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void stop_tentacle(st_rpg *s)
{
	if (s->f.boss.ctent > 5) {
		s->f.boss.ctent = 0;
		s->f.mob[0]->cast = 0;
	}
}

int precedent_tentacle_is_mid(st_rpg *s)
{
	if (s->f.boss.ctent > 0) {
		if (s->f.boss.tent[s->f.boss.ctent - 1]->anim->li > 0)
			return (1);
	}
	return (0);
}

void update_tentacle(st_rpg *s)
{
	s->f.boss.trat = get_ratios(get_angle_enemy(s, 0));
	launch_aoe(s, s->f.boss.tent[s->f.boss.ctent]);
	sfCircleShape_setPosition(s->f.boss.tent[s->f.boss.ctent]->circle,
	create_vector2f(s->f.mob[0]->obj->pos.x + 144 + s->f.boss.trat.x * 70 *
	s->f.boss.ctent - sfCircleShape_getRadius(s->f.boss.tent[s
	->f.boss.ctent]->circle), s->f.mob[0]->obj->pos.y + 72 + s->f.boss.trat
	.y * 100 * (s->f.boss.ctent + 2) - sfCircleShape_getRadius(s
	->f.boss.tent[s->f.boss.ctent]->circle)));
	sfSprite_setPosition(s->f.boss.tent[s->f.boss.ctent]->anim->obj->sprite,
	create_vector2f(s->f.mob[0]->obj->pos.x + 144 + s->f.boss.trat.x * 70 *
	s->f.boss.ctent - s->f.boss.tent[s->f.boss.ctent]->anim->obj->rect.width
	/ 2, s->f.mob[0]->obj->pos.y + 72 + s->f.boss.trat.y * 100 * (s->f.boss.
	ctent + 2) - s->f.boss.tent[s->f.boss.ctent]->anim
	->obj->rect.height / 2));
	proc_enemy_aoe(s, s->f.boss.tent[s->f.boss.ctent], 0);
	s->f.boss.ctent += 1;
	stop_tentacle(s);
}

void update_well(st_rpg *s)
{
	if (s->f.boss.well->anim->li == 3)
		proc_enemy_aoe(s, s->f.boss.well, 0);
}

void update_shadowball(st_rpg *s, float dt)
{
	if (s->f.boss.used < 300)
		s->f.boss.ballrat = get_ratios(get_angle_enemy(s, 0));
	s->f.boss.ballpos.x += s->f.boss.ballrat.x * 1000 * dt;
	s->f.boss.ballpos.y += s->f.boss.ballrat.y * 1000 * dt;
	s->f.boss.used -= hypot(s->f.boss.ballrat.x * 1000 * dt,
	s->f.boss.ballrat.y * 1000 * dt);
	sfCircleShape_setPosition(s->f.boss.ball->circle,
	create_vector2f(s->f.boss.ballpos.x - sfCircleShape_getRadius(s
	->f.boss.ball->circle), s->f.boss.ballpos.y - sfCircleShape_getRadius(s
	->f.boss.ball->circle)));
	sfSprite_setPosition(s->f.boss.ball->anim->obj->sprite,
	create_vector2f(s->f.boss.ballpos.x - s->f.boss.ball->anim->obj
	->rect.width / 2, s->f.boss.ballpos.y -
	s->f.boss.ball->anim->obj->rect.height / 2));
	proc_enemy_aoe(s, s->f.boss.ball, 0);
}
