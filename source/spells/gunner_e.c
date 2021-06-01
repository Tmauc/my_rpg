/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void gunner_net(st_rpg *s)
{
	sfMusic_play(s->f.gun.s_net);
	s->f.gun.net->angle = get_angle(s);
	launch_projectile(s, s->f.gun.net, s->f.gun.net->angle);
}

void gunner_jump(st_rpg *s)
{
	sfMusic_play(s->f.gun.s_explo);
	s->f.gun.explosion->obj->pos = create_vector2f(s->player.obj->pos.x
	- 50 * 1.8,
	s->player.obj->pos.y - 50 * 1.8);
	sfCircleShape_setPosition(s->f.gun.explo,
	s->f.gun.explosion->obj->pos);
	sfSprite_setPosition(s->f.gun.boots->obj->sprite,
	s->f.gun.explosion->obj->pos);
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (circle_hitbox_enemy(s->f.gun.explo, s->f.mob[i]) &&
			s->f.mob[i]->alive)
			s->f.mob[i]->stat->pva -= 40 + 15 * s->player.stat->lvl;
	}
	s->f.gun.boots->li = 0;
	s->f.gun.boots->c = 0;
	s->f.gun.jump->speed = 80;
	launch_particle(s->f.gun.partf, s->player.obj->pos, get_angle(s));
	launch_dash(s, s->f.gun.jump);
}

void choose_spell2_gunner(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {gunner_net, gunner_jump};

	(list[s->player.tree.spell2])(s);
}
