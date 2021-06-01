/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_estoc(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (enemy_hitbox(s->player.weapon[0], s->f.mob[i]) &&
		s->f.mob[i]->alive) {
			s->f.mob[i]->stat->pva -= s->f.war.hdmg;
			s->f.war.estoc = 2;
			s->f.cast = 0;
		}
	}
}

void warrior_update_hasagi_estoc(st_rpg *s, float dt)
{
	s->f.war.hpos.x += s->f.war.hrat.x * 10 * dt;
	s->f.war.hpos.y += s->f.war.hrat.y * 10 * dt;
	s->f.war.count += 14;
	sfSprite_setPosition(s->player.weapon[0]->sprite,
	s->f.war.hpos);
	sfSprite_setScale(s->player.weapon[0]->sprite,
	create_vector2f(1, 1));
	proc_estoc(s);
	if (s->f.war.count >= 100 || s->f.war.estoc == 2) {
		s->f.cast = 0;
		s->f.war.estoc = 2;
		s->f.war.hasagi->angle = get_angle(s);
		launch_projectile(s, s->f.war.hasagi,
		s->f.war.hasagi->angle);
	}
}

void warrior_update_hasagi(st_rpg *s, float dt)
{
	if (s->f.war.estoc == 1)
		warrior_update_hasagi_estoc(s, dt);
	else if (s->f.war.estoc == 2)
		update_projectile(s->f.war.hasagi, dt);
	if (!s->f.war.hasagi->shot && s->f.war.estoc == 2)
		s->f.war.estoc = 0;
}

void proc_rush(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (enemy_hitbox(s->player.obj, s->f.mob[i]) &&
		s->f.mob[i]->alive) {
			s->f.mob[i]->stat->pva -= 40 + (s->player.stat->frc / 7)
			* 2;
			s->f.mob[i]->stun->count += 1;
			s->f.war.rush->count = 0;
		}
	}
}

void warrior_update_rush(st_rpg *s)
{
	if (s->f.war.rush->on) {
		s->f.war.rush->count -= s->f.war.rush->speed;
		proc_rush(s);
		if (s->f.war.rush->count <= 0) {
			stop_player(s);
			s->f.cast = 0;
			s->f.war.rush->on = 0;
		}
	}
}
