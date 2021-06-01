/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_icons_cd(st_rpg *s)
{
	for (int i = 0; i < 4; i++)
		destroy_object(s->f.cd[i]);
}

void update_cdcount_icons(st_rpg *s, int i)
{
	if (s->f.cdcount[i] > 0) {
		s->f.cdcount[i] -= 0.05 *
		((float)s->player.cdr_effect->amount / 100.);
	}
}

void update_icons_cd(st_rpg *s)
{
	s->f.cdt.time = sfClock_getElapsedTime(s->f.cdt.clock);
	s->f.cdt.sec = s->f.cdt.time.microseconds / 1000000.0;
	if (s->f.cdt.sec > 0.05) {
		for (int i = 0; i < 4; i++) {
			update_cdcount_icons(s, i);
			s->f.cd[i]->rect.width = 128 * s->f.cdcount[i] /
			s->f.cds[i];
			sfSprite_setTextureRect(s->f.cd[i]->sprite,
			s->f.cd[i]->rect);
			sfClock_restart(s->f.cdt.clock);
		}
	}
}

void create_icons_cd(st_rpg *s)
{
	for (int i = 0; i < 4; i++)
		s->f.cd[i] = create_object(
		"ressources/images/interface/semiblack.png",
		create_vector2f(s->origin.x + 200 + 100 * i, s->origin.y + 800),
		create_rect(0, 0, 128, 128), 0);
	s->f.cdt = create_st_time();
}
