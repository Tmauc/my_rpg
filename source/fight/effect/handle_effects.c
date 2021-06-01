/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void handle_lifesteal(st_rpg *s, float amount, effect_t *effect)
{
	if (effect->count > 0)
		heal(s, amount * effect->amount / 100);
}

void handle_rage(st_rpg *s, float amount, enemy_t *mob)
{
	if (s->player.stat->pva < s->player.stat->pvm / 2 &&
	s->player.tree.passive == 2 && !s->player.tree.lock[2]) {
		mob->stat->pva -= amount / 2;
	}
}

void handle_destroyer(st_rpg *s, enemy_t *mob)
{
	if (mob->stat->pva <= 0) {
		heal(s, 0.15 * s->player.stat->pvm);
		if (s->f.war.destroyer->count == 0) {
			s->f.war.destroyer->amount = 0.3 * s->player.stat->frc
			+ s->player.stat->lvl;
			s->player.stat->frc += s->f.war.destroyer->amount;
		}
		s->f.war.destroyer->count += s->f.war.destroyer->duration;
	}
}
