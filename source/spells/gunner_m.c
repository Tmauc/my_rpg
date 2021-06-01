/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_blitz(st_rpg *s)
{
	launch_projectile(s, s->f.gun.blitz, get_angle(s));
	sfMusic_play(s->f.gun.zap);
}

void gunner_medikit(st_rpg *s)
{
	heal(s, s->player.stat->pvm / 3);
}

void gunner_grenade(st_rpg *s)
{
	int mx = sfMouse_getPositionRenderWindow(s->window).x;
	int my = sfMouse_getPositionRenderWindow(s->window).y;

	s->f.gun.grenade->range = hypot(abs(mx - 960),
	abs(my - 540));
	s->f.gun.grenade->obj->speed = s->f.gun.grenade->range;
	launch_projectile(s, s->f.gun.grenade, get_angle(s));
	sfClock_restart(s->f.gun.explosion->t.clock);
}

void choose_spell1_gunner(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {gunner_blitz, gunner_medikit,
		gunner_grenade};

	(list[s->player.tree.spell1])(s);
}
