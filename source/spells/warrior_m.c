/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_rush(st_rpg *s)
{
	sfMusic_play(s->f.war.s_rush);
	launch_dash(s, s->f.war.rush);
}

void warrior_whirlwing(st_rpg *s)
{
	launch_swing(s, s->f.war.whirl, s->player.weapon[0]);
	s->f.cast = 1;
}

void warrior_hasagi(st_rpg *s)
{
	sfMusic_play(s->f.war.s_hasaki);
	s->f.cast = 1;
	s->f.war.estoc = 1;
	s->f.war.count = 0;
	s->f.war.hpos = s->player.weapon[0]->pos;
	s->f.war.hrat = get_ratios(get_angle(s));
	s->f.war.hpos.x -= s->f.war.hrat.x * 50;
	s->f.war.hpos.y -= s->f.war.hrat.y * 50;
}

void choose_spell1_warrior(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {warrior_rush, warrior_whirlwing,
		warrior_hasagi};

	(list[s->player.tree.spell1])(s);
}
