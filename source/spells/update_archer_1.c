/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_current_arrow(st_rpg *s)
{
	if (s->f.arc.current > 19)
		s->f.arc.current = 0;
}

void update_kalash(st_rpg *s)
{
	s->f.arc.kal.time = sfClock_getElapsedTime(s->f.arc.kal.clock);
	s->f.arc.kal.sec = s->f.arc.kal.time.microseconds / 1000000.0;
	if (s->f.arc.kal.sec > s->f.arc.kalashspeed && s->f.arc.kalash == 1) {
		s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s);
		launch_projectile(s, s->f.arc.arrow[s->f.arc.current],
		s->f.arc.arrow[s->f.arc.current]->angle);
		sfMusic_play(s->f.arc.l_click);
		launch_particle(s->f.arc.parta[s->f.arc.current],
		s->player.obj->pos, get_angle(s));
		s->f.arc.current += 1;
		s->f.arc.kalashcount += 1;
		if (s->f.arc.kalashcount > 9) {
			s->f.cast = 0;
			s->f.arc.kalash = 0;
			s->f.arc.kalashcount = 0;
		}
		update_current_arrow(s);
		sfClock_restart(s->f.arc.kal.clock);
	}
}

void update_axe_part2(st_rpg *s, sfVector2f ratios)
{
	if (s->f.arc.axe->used <= 0)
		s->f.arc.axe->shot = 0;
	s->f.arc.axe->obj->pos.x = s->f.arc.axe->rpos.x - ratios.x * s
	->f.arc.axe->obj->rect.width / 2 + ratios.y * s->f.arc.axe->obj
	->rect.height / 2;
	s->f.arc.axe->obj->pos.y = s->f.arc.axe->rpos.y - ratios.y * s
	->f.arc.axe->obj->rect.width / 2 - ratios.x * s->f.arc.axe->obj
	->rect.height / 2;
	sfSprite_setPosition(s->f.arc.axe->obj->sprite, s->f.arc.axe->obj->pos);
	sfSprite_setRotation(s->f.arc.axe->obj->sprite, s->f.arc.axe->angle);
}

void update_axe(st_rpg *s)
{
	sfVector2f ratios;

	s->f.arc.axe->angle += 15;
	s->f.arc.axeangle += 5;
	ratios = get_ratios(s->f.arc.axe->angle);
	s->f.arc.axe->ratios = get_ratios(s->f.arc.axeangle);
	s->f.arc.axe->rpos.x += s->f.arc.axe->ratios.x * s->f.arc.axe->obj
	->speed;
	s->f.arc.axe->rpos.y += s->f.arc.axe->ratios.y * s->f.arc.axe->obj
	->speed;
	s->f.arc.axe->used -= hypot(s->f.arc.axe->ratios.x * s->f.arc.axe->obj
	->speed, s->f.arc.axe->ratios.y * s->f.arc.axe->obj->speed);
	update_axe_part2(s, ratios);
}
