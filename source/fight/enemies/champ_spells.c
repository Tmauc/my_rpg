/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void launch_champ_tentacle(st_rpg *s)
{
	sfMusic_play(s->f.boss.s_tent);
	s->f.mob[0]->cast = 2;
	s->f.boss.trat = get_ratios(get_angle_enemy(s, 0));
	launch_aoe(s, s->f.boss.tent[s->f.boss.ctent]);
	sfCircleShape_setPosition(s->f.boss.tent[s->f.boss.ctent]->circle,
	create_vector2f(s->f.mob[0]->obj->pos.x + 144 + s->f.boss.trat.x * 70 *
	s->f.boss.ctent - sfCircleShape_getRadius(s->f.boss.tent[s
	->f.boss.ctent]->circle), s->f.mob[0]->obj->pos.y + 72
	+ s->f.boss.trat.y * 100 * (s->f.boss.ctent + 2) -
	sfCircleShape_getRadius(s->f.boss.tent[s->f.boss.ctent]->circle)));
	sfSprite_setPosition(s->f.boss.tent[s->f.boss.ctent]->anim->obj->sprite,
	create_vector2f(s->f.mob[0]->obj->pos.x + 144 + s->f.boss.trat.x * 70 *
	s->f.boss.ctent - s->f.boss.tent[s->f.boss.ctent]->anim->obj
	->rect.width / 2,
	s->f.mob[0]->obj->pos.y + 72 + s->f.boss.trat.y * 100 *
	(s->f.boss.ctent + 2) -
	s->f.boss.tent[s->f.boss.ctent]->anim->obj->rect.height / 2));
	s->f.boss.ctent += 1;
}

void launch_champ_shadowball(st_rpg *s)
{
	sfMusic_play(s->f.boss.s_ball);
	s->f.boss.ballrat = get_ratios(get_angle_enemy(s, 0));
	launch_aoe(s, s->f.boss.ball);
	s->f.boss.ballpos = create_vector2f(s->f.mob[0]->obj->pos.x + 144,
	s->f.mob[0]->obj->pos.y + 72);
	sfCircleShape_setPosition(s->f.boss.ball->circle,
	create_vector2f(s->f.boss.ballpos.x - sfCircleShape_getRadius(s
	->f.boss.ball->circle), s->f.boss.ballpos.y - sfCircleShape_getRadius(s
	->f.boss.ball->circle)));
	sfSprite_setPosition(s->f.boss.ball->anim->obj->sprite,
	create_vector2f(s->f.boss.ballpos.x - s->f.boss.ball->anim->obj
	->rect.width / 2, s->f.boss.ballpos.y -
	s->f.boss.ball->anim->obj->rect.height / 2));
}

void launch_champ_well(st_rpg *s)
{
	launch_aoe(s, s->f.boss.well);
	sfCircleShape_setPosition(s->f.boss.well->circle,
	create_vector2f(s->player.obj->pos.x - sfCircleShape_getRadius(s
	->f.boss.well->circle),
	s->player.obj->pos.y - sfCircleShape_getRadius(s
	->f.boss.well->circle)));
	sfSprite_setPosition(s->f.boss.well->anim->obj->sprite,
	create_vector2f(s->player.obj->pos.x - s->f.boss.well->anim->obj
	->rect.width / 2,
	s->player.obj->pos.y - s->f.boss.well->anim->obj->rect.height / 2));
}

void launch_champ_spells(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {launch_champ_tentacle,
		launch_champ_shadowball, launch_champ_well};

	s->f.boss.attack = rand() % 3;
	(list[s->f.boss.attack])(s);
}
