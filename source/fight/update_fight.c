/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_fight(st_rpg *s)
{
	s->f.proc.time = sfClock_getElapsedTime(s->f.proc.clock);
	s->f.proc.sec = s->f.proc.time.microseconds / 1000000.0;
	if (s->f.proc.sec > 0.016) {
		proc_aoes(s, s->f.proc.sec);
		proc_effects(s, s->f.proc.sec);
		update_use_item(s, s->f.proc.sec);
		update_projectiles(s, s->f.proc.sec);
		update_boss(s, s->f.proc.sec);
		sfClock_restart(s->f.proc.clock);
	}
	update_boss_life_bar_origin(s);
}
