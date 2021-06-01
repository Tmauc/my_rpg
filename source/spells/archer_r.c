/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_barrage(st_rpg *s)
{
	sfMusic_play(s->f.arc.s_arrow_rain);
	launch_aoe(s, s->f.arc.barrage);
	stop_player(s);
	s->f.cast = 2;
}

void archer_axe(st_rpg *s)
{
	s->f.arc.axe->rpos = create_vector2f(s->origin.x + 960,
	s->origin.y + 540);
	s->f.arc.axe->angle = get_angle(s);
	s->f.arc.axeangle = s->f.arc.axe->angle - 70;
	launch_projectile(s, s->f.arc.axe, s->f.arc.axe->angle - 70);
}

void choose_spell3_archer(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {archer_barrage, archer_axe};

	(list[s->player.tree.spell3])(s);
}
