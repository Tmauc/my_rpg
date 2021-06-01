/*
** EPITECH PROJECT, 2018
** easy_stats.c
** File description:
** easy stats to increment
*/

#include "my.h"
#include "my_rpg.h"

void create_use_item(st_rpg *rpg)
{
	rpg->player.speed_effect = create_effect("speed", 0, 5);
	rpg->player.cdr_effect = create_effect("cdr", 100, 5);
}

void destroy_use_item(st_rpg *rpg)
{
	rpg->player.stat->vit = 10;
	destroy_effect(rpg->player.speed_effect);
	destroy_effect(rpg->player.cdr_effect);
}

void add_speed(st_rpg *rpg, int to_add)
{
	if (rpg->player.speed_effect->amount == 0) {
		rpg->player.speed_effect->amount = to_add;
		rpg->player.stat->vit += rpg->player.speed_effect->amount;
		rpg->player.speed_effect->count =
		rpg->player.speed_effect->duration;
	}
}

void add_cdr(st_rpg *rpg, int to_add)
{
	if (rpg->player.cdr_effect->amount == 100) {
		rpg->player.cdr_effect->amount = to_add;
		rpg->player.cdr_effect->count =
		rpg->player.cdr_effect->duration;
	}
}

void update_use_item(st_rpg *rpg, float dt)
{
	proc_effect(rpg->player.speed_effect, dt);
	if (rpg->player.speed_effect->count < 0) {
		rpg->player.speed_effect->count = 0;
		rpg->player.stat->vit -= rpg->player.speed_effect->amount;
		rpg->player.speed_effect->amount = 0;
	}
	proc_effect(rpg->player.cdr_effect, dt);
	if (rpg->player.cdr_effect->count < 0) {
		rpg->player.cdr_effect->count = 0;
		rpg->player.cdr_effect->amount = 100;
	}
}
