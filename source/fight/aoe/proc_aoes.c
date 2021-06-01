/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_aoe_archer(st_rpg *s, float dt)
{
	proc_aoe(s, s->f.arc.heal, dt);
	proc_aoe(s, s->f.arc.barrage, dt);
	apply_projectile(s, s->f.arc.axe, s->f.mob);
}

void proc_aoe_rogue(st_rpg *s, float dt)
{
	proc_aoe(s, s->f.rog.zone, dt);
	proc_aoe(s, s->f.rog.flash, dt);
}

void proc_aoe_warrior(st_rpg *s, float dt)
{
	proc_aoe(s, s->f.war.crack, dt);
	proc_aoe(s, s->f.war.shield, dt);
	apply_projectile(s, s->f.war.hasagi, s->f.mob);
}

void proc_aoes(st_rpg *s, float dt)
{
	void (*list[4])(st_rpg *s, float dt) = {proc_aoe_archer,
		proc_aoe_rogue, proc_aoe_rogue, proc_aoe_warrior};

	if (s->player.cdata.classe != 1)
		(list[s->player.cdata.classe])(s, dt);
}
