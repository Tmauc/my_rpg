/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_archer(st_rpg *s)
{
	update_kalash(s);
	update_axe(s);
	update_dash(s, s->f.arc.leap);
	if (s->f.arc.heal->shot)
		clocked_animation(s->f.arc.heal->anim);
	if (s->f.arc.barrage->shot)
		clocked_animation(s->f.arc.barrage->anim);
	if (s->f.arc.barrage->anim->li > s->f.arc.barrage->anim->ver) {
		s->f.arc.barrage->anim->li = 0;
		s->f.cast = 0;
	}
}

void update_gunner(st_rpg *s)
{
	gunner_update_auto_attack(s);
	for (int i = 0; i != 10; i += 1) {
		if (s->f.gun.ultb[i]->shot) {
			s->f.gun.trait[i]->rect.width += 80;
			s->f.gun.trait[i]->rect.height -= 1;
			sfSprite_setTextureRect(s->f.gun.trait[i]->sprite,
			s->f.gun.trait[i]->rect);
		}
	}
	clocked_animation(s->f.gun.boots);
	gunner_update_ultimate(s);
	gunner_update_flamet(s);
	update_dash(s, s->f.gun.jump);
	s->f.gun.jump->speed -= 1;
}

void update_rogue(st_rpg *s)
{
	rogue_update_storm(s);
	rogue_update_auto_attack(s);
	rogue_update_shadowstep(s);
	update_dash(s, s->f.rog.draw);
	if (s->f.rog.flash->shot)
		rogue_update_flash(s);
	if (s->f.rog.zone->shot)
		clocked_animation(s->f.rog.zone->anim);
}

void update_warrior(st_rpg *s)
{
	update_swing(s, s->f.war.auto_a, s->player.weapon[0]);
	update_swing(s, s->f.war.whirl, s->player.weapon[0]);
	if (s->f.war.whirl->shot)
		sfSprite_setRotation(s->player.weapon[0]->sprite,
		s->f.war.whirl->count);
	if (s->f.war.whirl->able == 0 && s->f.war.whirl->shot == 1)
		s->f.war.whirl->able = 1;
	if (s->f.war.shield->shot)
		clocked_animation(s->f.war.shield->anim);
	sfSprite_setPosition(s->f.war.paricon->sprite,
	create_vector2f(s->origin.x + 125, s->origin.y + 108));
	warrior_update_quake(s);
	warrior_update_rush(s);
}

void update_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {update_archer, update_gunner,
		update_rogue, update_warrior};

	(list[s->player.cdata.classe])(s);
	update_dash(s, s->f.knock);
}
