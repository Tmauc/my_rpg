/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_spells_archer(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1) {
		destroy_projectile(s->f.arc.arrow[i]);
		destroy_particle(s->f.arc.parta[i]);
	}
	destroy_projectile(s->f.arc.axe);
	sfClock_destroy(s->f.arc.kal.clock);
	destroy_aoe(s->f.arc.barrage);
	destroy_aoe(s->f.arc.heal);
	destroy_effect(s->f.arc.leaf);
	destroy_dash(s->f.arc.leap);
	destroy_archer_sound(s);
}

void destroy_spells_gunner(st_rpg *s)
{
	for (int i = 0; i != 100; i += 1)
		destroy_projectile(s->f.gun.flame[i]);
	for (int i = 0; i != 10; i += 1) {
		destroy_projectile(s->f.gun.bullet[i]);
		destroy_projectile(s->f.gun.ultb[i]);
		destroy_object(s->f.gun.trait[i]);
	}
	sfClock_destroy(s->f.gun.t.clock);
	sfClock_destroy(s->f.gun.blitzt.clock);
	destroy_projectile(s->f.gun.blitz);
	destroy_projectile(s->f.gun.grenade);
	destroy_projectile(s->f.gun.net);
	destroy_anim(s->f.gun.explosion);
	destroy_anim(s->f.gun.boots);
	destroy_anim(s->f.gun.expbullet);
	sfCircleShape_destroy(s->f.gun.explo);
	sfCircleShape_destroy(s->f.gun.expbt);
	destroy_effect(s->f.gun.rush);
	destroy_dash(s->f.gun.jump);
	destroy_gunner_sound(s);
}

void destroy_spells_rogue(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		destroy_projectile(s->f.rog.dagger[i]);
	sfClock_destroy(s->f.rog.ultt.clock);
	destroy_projectile(s->f.rog.dance);
	destroy_swing(s->f.rog.auto_a[0]);
	destroy_swing(s->f.rog.auto_a[1]);
	destroy_aoe(s->f.rog.zone);
	destroy_aoe(s->f.rog.flash);
	destroy_button(s->f.rog.backstab);
	destroy_particle(s->f.rog.partp);
	destroy_particle(s->f.rog.partd);
	destroy_dash(s->f.rog.tp);
	destroy_dash(s->f.rog.draw);
	destroy_rogue_sound(s);
}

void destroy_spells_warrior(st_rpg *s)
{
	destroy_aoe(s->f.war.shield);
	destroy_aoe(s->f.war.crack);
	destroy_swing(s->f.war.auto_a);
	destroy_swing(s->f.war.whirl);
	destroy_projectile(s->f.war.hasagi);
	destroy_effect(s->f.war.endure);
	destroy_effect(s->f.war.lifesteal);
	destroy_effect(s->f.war.destroyer);
	destroy_effect(s->f.war.parade);
	destroy_object(s->f.war.paricon);
	destroy_dash(s->f.war.rush);
	destroy_dash(s->f.war.ultd);
	destroy_warrior_sound(s);
}

void destroy_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {destroy_spells_archer,
		destroy_spells_gunner, destroy_spells_rogue,
		destroy_spells_warrior};

	(list[s->player.cdata.classe])(s);

}
