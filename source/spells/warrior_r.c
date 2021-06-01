/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_earthquake(st_rpg *s)
{
	sfMusic_play(s->f.war.s_stomp);
	launch_dash(s, s->f.war.ultd);
}

void warrior_endure(st_rpg *s)
{
	sfMusic_play(s->f.war.s_endure);
	s->f.war.endure->count = s->f.war.endure->duration;
	s->f.war.endure->amount = 1;
}

void choose_spell3_warrior(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {warrior_earthquake, warrior_endure};

	(list[s->player.tree.spell3])(s);
}
