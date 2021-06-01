/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my.h"
#include "my_rpg.h"

void heal(st_rpg *s, int amount)
{
	s->player.stat->pva += amount;
	if (s->player.stat->pva > s->player.stat->pvm)
		s->player.stat->pva = s->player.stat->pvm;
}

int hurt(st_rpg *s, float amount)
{
	if (s->player.cdata.classe == 3) {
		if (s->f.war.parade->amount == 1) {
			s->f.war.parade->amount = 0;
			s->f.recover->count = s->f.recover->duration;
			return (1);
		} if (s->f.war.endure->amount == 1)
			return (1);
	}
	s->player.stat->pva -= amount;
	if (s->player.stat->pva < 0)
		s->player.stat->pva = 0;
	return (0);
}

int player_is_dead(st_rpg *s)
{
	if (s->player.stat->pva <= 0)
		return (1);
	return (0);
}
