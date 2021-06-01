/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_particles(st_rpg *s)
{
	s->partime.time = sfClock_getElapsedTime(s->partime.clock);
	s->partime.sec = s->partime.time.microseconds / 1000000.0;
	if (s->partime.sec > (1 / 60)) {
		update_particles_class(s, s->partime.sec);
		update_main_particles(s, s->partime.sec);
		sfClock_restart(s->partime.clock);
	}
}
