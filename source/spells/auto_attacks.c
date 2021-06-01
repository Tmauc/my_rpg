/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_auto_attack(st_rpg *s)
{
	sfMusic_play(s->f.arc.l_click);
	s->f.arc.arrow[s->f.arc.current]->angle = get_angle(s);
	launch_projectile(s, s->f.arc.arrow[s->f.arc.current],
	s->f.arc.arrow[s->f.arc.current]->angle);
	launch_particle(s->f.arc.parta[s->f.arc.current],
	s->player.obj->pos, get_angle(s));
	s->f.arc.current += 1;
	update_current_arrow(s);
}

void gunner_auto_attack(st_rpg *s)
{
	s->f.gun.autocount = 0;
	s->f.gun.auto_a = 1;
	sfMusic_play(s->f.gun.l_click);
}

void rogue_auto_attack(st_rpg *s)
{
	sfMusic_play(s->f.rog.l_click);
	if (s->f.rog.vanish > 0 && s->player.tree.passive == 2 &&
	!s->player.tree.lock[2]) {
		rogue_backstab(s);
	} else {
		launch_swing(s, s->f.rog.auto_a[0],
		s->player.weapon[0]);
		s->f.cast = 1;
		s->f.rog.auto_bool = 1;
	}
	s->f.rog.vanish = 0;
}

void warrior_auto_attack(st_rpg *s)
{
	if (s->f.war.sound) {
		sfMusic_play(s->f.war.s_sword1);
		s->f.war.sound = 0;
	} else {
		sfMusic_play(s->f.war.s_sword2);
		s->f.war.sound = 1;
	}
	s->f.war.auto_a->sens = -s->f.war.auto_a->sens;
	s->f.war.auto_a->begin = -s->f.war.auto_a->begin;
	launch_swing(s, s->f.war.auto_a, s->player.weapon[0]);
	s->f.cast = 1;
}
