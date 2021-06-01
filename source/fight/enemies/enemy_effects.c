/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void proc_enemy_stun(st_rpg *s, int i)
{
	if (s->f.mob[i]->stun->count > 0)
		s->f.mob[i]->stun->amount = 1;
	if (s->f.mob[i]->stun->amount == 1) {
		s->f.mob[i]->cast = 2;
	} if (s->f.mob[i]->stun->count < 0) {
		s->f.mob[i]->cast = 0;
		s->f.mob[i]->stun->count = 0;
		s->f.mob[i]->stun->duration = 0;
		s->f.mob[i]->stun->amount = 0;
	}
}

void proc_enemy_poison(st_rpg *s, int i)
{
	if (s->f.mob[i]->poison->amount != 0 && s->f.mob[i]->alive) {
		s->f.mob[i]->stat->pva -= (1 + s->player.stat->frc / 7)
		* 0.5 * s->f.mob[i]->poison->amount;
		launch_dmg_show(s, (1 + s->player.stat->frc / 7)
		* 0.5 * s->f.mob[i]->poison->amount, s->f.mob[i]->obj);
	} if (s->f.mob[i]->poison->count < 0) {
		s->f.mob[i]->poison->count = 0;
		s->f.mob[i]->poison->amount = 0;
		s->f.mob[i]->poison->duration = 0;
	}
}
