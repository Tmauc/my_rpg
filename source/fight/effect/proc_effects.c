/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_effect_archer(st_rpg *s, float dt)
{
	proc_effect(s->f.arc.leaf, dt);
	if (s->f.arc.leaf->count < 0 && s->f.arc.leaf->amount != 0) {
		s->player.stat->frc -= s->f.arc.leaf->amount;
		s->f.arc.leaf->amount = 0;
		s->f.arc.leaf->count = 0;
	}
}

void proc_effect_gunner(st_rpg *s, float dt)
{
	proc_effect(s->f.gun.rush, dt);
	if (s->f.gun.rush->count < 0 && s->f.gun.rush->amount != 0) {
		s->player.obj->speed -= s->f.gun.rush->amount;
		s->f.gun.rush->amount = 0;
		s->f.gun.rush->count = 0;
	}
}

void proc_effect_rogue(st_rpg *s, float dt)
{
	if (s->f.rog.vanish > 0)
		s->f.rog.vanish -= dt;
}

void proc_effect_warrior(st_rpg *s, float dt)
{
	proc_effect(s->f.war.endure, dt);
	proc_effect(s->f.war.lifesteal, dt);
	proc_effect(s->f.war.destroyer, dt);
	if (s->f.war.endure->count <= 0 && s->f.war.endure->amount != 0) {
		s->f.war.endure->amount = 0;
	} if (s->f.war.destroyer->count <= 0 &&
	s->f.war.destroyer->amount != 0) {
		s->player.stat->frc -= s->f.war.destroyer->amount;
		s->f.war.destroyer->amount = 0;
	} if (s->f.war.parade->amount == 0 && s->player.tree.passive == 0 &&
	!s->player.tree.lock[0]) {
		proc_effect(s->f.war.parade, dt);
		if (s->f.war.parade->count <= 0) {
			s->f.war.parade->count = 5;
			s->f.war.parade->amount = 1;
		}
	}
}

void proc_effects(st_rpg *s, float dt)
{
	void (*list[4])(st_rpg *s, float dt) = {proc_effect_archer,
		proc_effect_gunner, proc_effect_rogue, proc_effect_warrior};

	(list[s->player.cdata.classe])(s, dt);
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		proc_effect(s->f.mob[i]->stun, dt);
		proc_effect(s->f.mob[i]->poison, dt);
		proc_enemy_stun(s, i);
		proc_enemy_poison(s, i);
		movement_enemies(s, i, dt);
	}
	proc_effect(s->f.recover, dt);
	if (s->f.recover->count > 0) {
		s->f.recover->amount = 1;
	} else {
		s->f.recover->count = 0;
		s->f.recover->amount = 0;
	}
}
