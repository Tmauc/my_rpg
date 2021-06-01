/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_current_bullet(st_rpg *s)
{
	s->f.gun.current += 1;
	if (s->f.gun.current > 9) {
		s->f.gun.ult = 0;
		s->f.gun.auto_a = 0;
		s->f.gun.current = 0;
	}
}

void gunner_update_blitz(st_rpg *s)
{
	s->f.gun.blitzt.time = sfClock_getElapsedTime(s->f.gun.blitzt.clock);
	s->f.gun.blitzt.sec = s->f.gun.blitzt.time.microseconds / 1000000.0;
	if (s->f.gun.blitzt.sec > 0.1 && s->f.gun.blitz->shot) {
		s->f.gun.blitz->obj->rect.left += 40;
		if (s->f.gun.blitz->obj->rect.left >= 80) {
			s->f.gun.blitz->obj->rect.left = 0;
			s->f.gun.blitz->obj->rect.top += 15;
		} if (s->f.gun.blitz->obj->rect.top >= 60)
			s->f.gun.blitz->obj->rect.top = 0;
		sfSprite_setTextureRect(s->f.gun.blitz->obj->sprite,
		s->f.gun.blitz->obj->rect);
		sfClock_restart(s->f.gun.blitzt.clock);
	}
}

void gunner_update_grenade_speed(st_rpg *s, float dt)
{
	if (s->f.gun.grenade->shot == 2) {
		clocked_animation(s->f.gun.explosion);
		if (s->f.gun.explosion->li >= s->f.gun.explosion->ver) {
			s->f.gun.grenade->obj->speed = s->f.gun.grenadespeed;
			s->f.gun.grenade->shot = 0;
		}
	} else if (s->f.gun.grenade->shot == 1) {
		if (s->f.gun.explosion->t.sec > s->f.gun.explosion->speed &&
		s->f.gun.grenade->obj->speed > 0) {
			s->f.gun.grenade->obj->speed -= s->f.gun.grenade
			->range * dt / 1.92;
			sfClock_restart(s->f.gun.explosion->t.clock);
		}
		update_projectile(s->f.gun.grenade, dt);
	}
}

void proc_grenade(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		sfMusic_play(s->f.gun.s_explo);
		launch_particle(s->f.gun.partf, s->f.gun.grenade->obj->pos,
		get_angle(s));
		if (circle_hitbox_enemy(s->f.gun.explo, s->f.mob[i]) &&
		s->f.mob[i]->alive) {
			s->f.mob[i]->stat->pva -= 50 + 15 * s->player.stat->frc;
			launch_dmg_show(s, 50 + 15 * s->player.stat->frc,
			s->f.mob[i]->obj);
		}
	}
}

void gunner_update_grenade(st_rpg *s, float dt)
{
	s->f.gun.explosion->t.time = sfClock_getElapsedTime(s->f.gun.explosion
	->t.clock);
	s->f.gun.explosion->t.sec = s->f.gun.explosion->t.time.microseconds /
	1000000.0;
	if (s->f.gun.explosion->t.sec >= s->f.gun.delay &&
	s->f.gun.grenade->shot == 1) {
		s->f.gun.explosion->obj->pos = create_vector2f(s->f.gun.grenade
		->obj->pos.x - 50 * 1.8,
		s->f.gun.grenade->obj->pos.y - 50 * 1.8);
		sfSprite_setPosition(s->f.gun.explosion->obj->sprite,
		s->f.gun.explosion->obj->pos);
		sfCircleShape_setPosition(s->f.gun.explo,
		s->f.gun.explosion->obj->pos);
		s->f.gun.grenade->shot = 2;
		s->f.gun.explosion->li = 0;
		s->f.gun.explosion->c = 0;
		proc_grenade(s);
	}
	gunner_update_grenade_speed(s, dt);
}
