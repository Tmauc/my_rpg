/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_archer(st_rpg *s)
{
	display_aoe(s->window, s->f.arc.barrage);
	display_aoe(s->window, s->f.arc.heal);
	for (int i = 0; i != 20; i += 1) {
		display_projectile(s->window, s->f.arc.arrow[i]);
		if (s->f.arc.arrow[i]->shot)
			display_particle(s->f.arc.parta[i], s->window);
	}
	display_projectile(s->window, s->f.arc.axe);
}

void display_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		display_projectile(s->window, s->f.rog.dagger[i]);
	display_projectile(s->window, s->f.rog.dance);
	display_aoe(s->window, s->f.rog.zone);
	display_aoe(s->window, s->f.rog.flash);
	display_particle(s->f.rog.partp, s->window);
	display_particle(s->f.rog.partd, s->window);
}

void display_warrior(st_rpg *s)
{
	display_projectile(s->window, s->f.war.hasagi);
	display_aoe(s->window, s->f.war.shield);
	display_aoe(s->window, s->f.war.crack);
	if (s->f.war.parade->amount == 1)
		display_object(s->window, s->f.war.paricon);
}

void display_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {display_archer, display_gunner,
		display_rogue, display_warrior};

	(list[s->player.cdata.classe])(s);
}
