/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void rogue_storm(st_rpg *s)
{
	sfMusic_play(s->f.rog.s_ult);
	s->f.rog.ultcount = 0;
	s->f.rog.ulting = 1;
	s->f.rog.ultangle = 1;
	s->f.rog.side = 0;
	s->f.panim = 1;
	s->f.rog.vanish = 0;
}

void rogue_blind(st_rpg *s)
{
	sfMusic_play(s->f.rog.flashbang);
	launch_aoe(s, s->f.rog.flash);
	sfCircleShape_setPosition(s->f.rog.flash->circle,
	create_vector2f(s->origin.x + 960 - sfCircleShape_getRadius(s
	->f.rog.flash->circle),
	s->origin.y + 540 - sfCircleShape_getRadius(s->f.rog.flash->circle)));
	sfSprite_setPosition(s->f.rog.flash->anim->obj->sprite,
	create_vector2f(s->origin.x + 960 - s->f.rog.flash->anim->obj
	->rect.width / 2,
	s->origin.y + 540 - s->f.rog.flash->anim->obj->rect.height / 2));
	s->f.rog.fscale = 1;
	sfSprite_setScale(s->f.rog.flash->anim->obj->sprite,
	create_vector2f(s->f.rog.fscale, s->f.rog.fscale));
}

void choose_spell3_rogue(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {rogue_storm, rogue_blind};

	(list[s->player.tree.spell3])(s);
}
