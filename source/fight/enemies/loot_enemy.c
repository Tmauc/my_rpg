/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void loot_enemy(st_rpg *s)
{
	int bonus_by_level = 10 - s->player.stat->lvl;

	if (bonus_by_level < 0)
		bonus_by_level = 0;
	s->player.stat->exp += (rand() % 3) + bonus_by_level;
}
