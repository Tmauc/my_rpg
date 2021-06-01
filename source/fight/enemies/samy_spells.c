/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_samy_dash(st_rpg *s)
{
	float amount = s->f.mob[0]->stat->frc -
	(s->player.stat->def / 100 * s->f.mob[0]->stat->frc);

	hurt(s, amount);
	stop_player(s);
	launch_dash(s, s->f.knock);
	s->f.knock->ratios = get_ratios(get_angle_enemy(s,
	0) + 90 + ((rand() % 2) * 180));
	s->player.nbr_frame.x = s->f.knock->ratios.x *
	s->f.knock->speed * 3;
	s->player.nbr_frame.y = s->f.knock->ratios.y *
	s->f.knock->speed * 3;
	launch_dmg_show(s, amount, s->player.obj);
	s->f.recover->count = 1.5;
	s->f.recover->amount = 1;
}

void update_samy_dash(st_rpg *s, float dt)
{
	if (s->f.boss.dash->on) {
		s->f.boss.dash->count -= s->f.boss.dash->speed;
		if (s->f.boss.dash->count <= 0) {
			s->f.mob[0]->cast = 0;
			s->f.boss.dash->on = 0;
		} if (enemy_hitbox(s->player.obj, s->f.mob[0]))
			proc_samy_dash(s);
		s->f.mob[0]->ratios.x =
		s->f.boss.dash->ratios.x * s->f.boss.dash->speed;
		s->f.mob[0]->ratios.y =
		s->f.boss.dash->ratios.y * s->f.boss.dash->speed;
		verify_collide_map_enemies(s, dt, 0);
		sfSprite_setPosition(s->f.mob[0]->obj->sprite,
		s->f.mob[0]->obj->pos);
	}
	update_particle(s->f.boss.samy_fus, dt);
}

void update_samy_fusrohdah(st_rpg *s)
{
	if (s->f.boss.fus->on) {
		s->f.boss.fus->count -= s->f.boss.fus->speed;
		if (s->f.boss.fus->count <= 0) {
			s->f.mob[0]->cast = 0;
			s->f.boss.fus->on = 0;
		}
	}
}
