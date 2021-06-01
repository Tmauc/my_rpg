/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_update_ultimate_part2(st_rpg *s)
{
	if (s->f.gun.t.sec > 0.15 && s->f.gun.ult == 2) {
		launch_projectile(s, s->f.gun.ultb[s->f.gun.current],
		s->f.gun.ultb[s->f.gun.current]->angle);
		update_current_bullet(s);
		sfClock_restart(s->f.gun.t.clock);
		if (s->f.gun.current == 0) {
			s->f.gun.ult = 0;
			s->f.cast = 0;
		}
	}
}

void gunner_update_ultimate(st_rpg *s)
{
	s->f.gun.t.time = sfClock_getElapsedTime(s->f.gun.t.clock);
	s->f.gun.t.sec = s->f.gun.t.time.microseconds / 1000000.0;
	if (s->f.gun.t.sec > 0.1 && s->f.gun.ult == 1) {
		for (int i = 0; i != 10; i += 1) {
			s->f.gun.ultb[i]->dmg += s->f.gun.ultb[i]->dmgratio;
		}
		if (s->f.gun.ultb[0]->dmg > s->f.gun.origin * 5 ||
		sfMouse_isButtonPressed(sfMouseLeft)) {
			s->f.gun.ult = 2;
			sfMusic_play(s->f.gun.l_click);
		}
		sfClock_restart(s->f.gun.t.clock);
	}
	gunner_update_ultimate_part2(s);
}
