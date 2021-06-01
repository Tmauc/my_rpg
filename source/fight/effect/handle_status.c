/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void handle_poison(st_rpg *s, enemy_t *mob)
{
	if (s->player.cdata.classe == 2 && s->player.tree.passive == 1 &&
	!s->player.tree.lock[1] && rand() % 6 == 1) {
		mob->poison->amount = 1;
		mob->poison->count = 1;
	}
}

void handle_stun(char *str, enemy_t *mob, float duration)
{
	if (!my_strcmp(str, "stun"))
		mob->stun->count += duration;
}

void handle_status(st_rpg *s, float amount, enemy_t *mob)
{
	if (s->player.cdata.classe == 3) {
		handle_lifesteal(s, amount, s->f.war.lifesteal);
		handle_rage(s, amount, mob);
	}
}
