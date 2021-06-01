/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_update_auto_attack(st_rpg *s)
{
	s->f.gun.t.time = sfClock_getElapsedTime(s->f.gun.t.clock);
	s->f.gun.t.sec = s->f.gun.t.time.microseconds / 1000000.0;
	if (s->f.gun.t.sec > s->f.gun.autospeed && s->f.gun.auto_a == 1) {
		s->f.gun.bullet[s->f.gun.current]->angle = get_angle(s);
		launch_projectile(s, s->f.gun.bullet[s->f.gun.current],
		s->f.gun.bullet[s->f.gun.current]->angle);
		launch_particle(s->f.gun.partg,
		s->player.weapon[rand() % 2]->pos, get_angle(s));
		update_current_bullet(s);
		sfClock_restart(s->f.gun.t.clock);
	} if (s->f.gun.bullet[9]->shot == 2) {
		clocked_animation(s->f.gun.expbullet);
		if (s->f.gun.expbullet->li >= s->f.gun.expbullet->ver)
			s->f.gun.bullet[9]->shot = 0;
	}
}

void reset_flamet_animation(st_rpg *s, int i)
{
	if (s->f.gun.flame[i]->obj->rect.top > 180)
		s->f.gun.flame[i]->obj->rect.top = 0;
}

void gunner_update_flamet_animation(st_rpg *s)
{
	for (int i = 0; i != 100; i += 1) {
		if (s->f.gun.flame[i]->shot) {
			s->f.gun.flame[i]->obj->rect.top += 30;
			reset_flamet_animation(s, i);
			sfSprite_setTextureRect(s->f.gun.flame[i]->obj->sprite,
			s->f.gun.flame[i]->obj->rect);
		} if (s->f.gun.flame[i]->obj->speed > 0 &&
			s->f.gun.flame[i]->shot)
			s->f.gun.flame[i]->obj->speed -= s->f.gun.cdiminution
			/ 100;
	}
}

void update_flame(st_rpg *s)
{
	if (s->f.gun.cflame > 99) {
		s->f.gun.cflame = 0;
		for (int i = 0; i != 100; i += 1)
			s->f.gun.flame[i]->obj->speed = s->f.gun.cdiminution;
	}
}

void gunner_update_flamet(st_rpg *s)
{
	s->f.gun.t.time = sfClock_getElapsedTime(s->f.gun.t.clock);
	s->f.gun.t.sec = s->f.gun.t.time.microseconds / 1000000.0;
	if (s->f.gun.t.sec > 0.01 && s->f.gun.flamet == 1) {
		s->f.gun.flame[s->f.gun.cflame]->angle = get_angle(s);
		launch_projectile(s, s->f.gun.flame[s->f.gun.cflame],
		s->f.gun.flame[s->f.gun.cflame]->angle + (rand() % 9) - 4);
		s->f.gun.cflame += 1;
		s->f.gun.flamestay -= s->f.gun.t.sec;
		s->f.gun.t.sec = 0;
		update_flame(s);
		sfClock_restart(s->f.gun.t.clock);
		gunner_update_flamet_animation(s);
		if (s->f.gun.flamestay < 0) {
			s->f.gun.flamet = 0;
			s->f.cast = 0;
		}
	}
}
