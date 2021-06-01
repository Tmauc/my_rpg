/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_current_dagger(st_rpg *s)
{
	if (s->f.rog.ultcount > 100) {
		s->f.panim = 0;
		s->f.rog.ulting = 0;
		s->f.rog.ultcount = 0;
	} if (s->f.rog.current > 29)
		s->f.rog.current = 0;
}

void rogue_update_flash2(st_rpg *s)
{
	s->f.rog.flash->anim->t.sec = 0;
	sfClock_restart(s->f.rog.flash->anim->t.clock);
	s->f.rog.flash->anim->obj->rect.left = s->f.rog.flash->anim->c
	* s->f.rog.flash->anim->width;
	s->f.rog.flash->anim->obj->rect.top = s->f.rog.flash->anim->li
	* s->f.rog.flash->anim->height;
	s->f.rog.fscale += 1;
	sfSprite_setScale(s->f.rog.flash->anim->obj->sprite,
	create_vector2f(s->f.rog.fscale, s->f.rog.fscale));
	sfSprite_setPosition(s->f.rog.flash->anim->obj->sprite,
	create_vector2f(
	sfSprite_getPosition(s->f.rog.flash->anim->obj->sprite).x - 96,
	sfSprite_getPosition(s->f.rog.flash->anim->obj->sprite).y -
	96));
	sfSprite_setTextureRect(s->f.rog.flash->anim->obj->sprite,
	s->f.rog.flash->anim->obj->rect);
}

void rogue_update_flash(st_rpg *s)
{
	s->f.rog.flash->anim->t.time = sfClock_getElapsedTime(s->f.rog.flash
	->anim->t.clock);
	s->f.rog.flash->anim->t.sec = s->f.rog.flash->anim->t.time.microseconds
	/ 1000000.0;
	if (s->f.rog.flash->anim->t.sec > s->f.rog.flash->anim->speed &&
	s->f.rog.flash->anim->li < s->f.rog.flash->anim->ver) {
		s->f.rog.flash->anim->c += 1;
		if (s->f.rog.flash->anim->c == s->f.rog.flash->anim->hor) {
			s->f.rog.flash->anim->c = 0;
			s->f.rog.flash->anim->li += 1;
		}
		rogue_update_flash2(s);
	}
}

void rogue_update_shadowstep(st_rpg *s)
{
	if (s->f.rog.tp->on) {
		s->f.rog.tp->count -= s->f.rog.tp->speed;
		if (s->f.rog.tp->count <= 0) {
			stop_player(s);
			s->f.cast = 0;
			s->f.rog.tp->on = 0;
			launch_particle(s->f.rog.partp, s->player.obj->pos, 0);
		}
	}
}

void change_side_player(st_rpg *s)
{
	switch (s->f.rog.ultr.top) {
	case 0 :
		s->f.rog.ultr.top = 48;
		break;
	case 48 :
		s->f.rog.ultr.top = 144;
		break;
	case 144 :
		s->f.rog.ultr.top = 96;
		break;
	case 96 :
		s->f.rog.ultr.top = 0;
		break;
	}
	s->player.obj->rect = s->f.rog.ultr;
	sfSprite_setTextureRect(s->player.obj->sprite, s->player.obj->rect);
}
