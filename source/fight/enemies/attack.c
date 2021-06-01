/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

int enemy_is_able(st_rpg *s, int i)
{
	if (s->f.mob[i]->aggro && s->f.mob[i]->alive &&
		!s->f.mob[i]->cast && !s->f.recover->amount)
		return (1);
	return (0);
}

void proc_enemy_aoe(st_rpg *s, aoe_t *aoe, int i)
{
	float amount = s->f.mob[i]->stat->frc -
	(s->player.stat->def / 100 * s->f.mob[i]->stat->frc);

	if (circle_hitbox(aoe->circle, s->player.obj) && enemy_is_able(s, i)) {
		if (hurt(s, amount))
			return;
		stop_player(s);
		launch_dash(s, s->f.knock);
		s->f.knock->ratios = get_ratios(get_angle_enemy(s, i));
		s->player.nbr_frame.x = s->f.knock->ratios.x *
		s->f.knock->speed;
		s->player.nbr_frame.y = s->f.knock->ratios.y *
		s->f.knock->speed;
		launch_dmg_show(s, amount, s->player.obj);
		s->f.recover->count = s->f.recover->duration;
	}
}

void attack_enemy(st_rpg *s, int i)
{
	float amount = s->f.mob[i]->stat->frc -
	(s->player.stat->def / 100 * s->f.mob[i]->stat->frc);

	if (enemy_hitbox(s->player.obj, s->f.mob[i]) && enemy_is_able(s, i)) {
		if (hurt(s, amount))
			return;
		stop_player(s);
		launch_dash(s, s->f.knock);
		s->f.knock->ratios = get_ratios(get_angle_enemy(s, i));
		s->player.nbr_frame.x = s->f.knock->ratios.x *
		s->f.knock->speed;
		s->player.nbr_frame.y = s->f.knock->ratios.y *
		s->f.knock->speed;
		launch_dmg_show(s, amount, s->player.obj);
		s->f.recover->count = s->f.recover->duration;
	}
}
