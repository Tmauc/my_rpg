/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void rogue_withdraw(st_rpg *s)
{
	heal(s, s->player.stat->pvm / 4);
	launch_dash(s, s->f.rog.draw);
	launch_particle(s->f.rog.partd, s->player.obj->pos, 0);
}

void rogue_zone(st_rpg *s)
{
	sfMusic_play(s->f.rog.s_vanish);
	launch_aoe(s, s->f.rog.zone);
	sfCircleShape_setPosition(s->f.rog.zone->circle,
	create_vector2f(s->origin.x + 960 - sfCircleShape_getRadius(s
	->f.rog.zone->circle),
	s->origin.y + 540 - sfCircleShape_getRadius(s->f.rog.zone->circle)));
	sfSprite_setPosition(s->f.rog.zone->anim->obj->sprite,
	create_vector2f(s->origin.x + 960 - s->f.rog.zone->anim->obj
	->rect.width / 2,
	s->origin.y + 540 - s->f.rog.zone->anim->obj->rect.height / 2));
	s->f.rog.vanish += 5;
}

void choose_spell2_rogue(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {rogue_withdraw, rogue_zone};

	(list[s->player.tree.spell2])(s);
}
