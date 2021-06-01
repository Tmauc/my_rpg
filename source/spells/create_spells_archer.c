/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_archer_passive(st_rpg *s)
{
	for (int i = 0; i != 20; i += 1) {
		s->f.arc.arrow[i] = create_projectile("ressources/proj/Arrow");
		s->f.arc.parta[i] =
		create_particle("ressources/particles/arrow");
		if (s->player.tree.passive == 0) {
			s->f.arc.arrow[i]->dmg += s->f.arc.arrow[i]->dmg * 0.1;
			s->f.arc.arrow[i]->obj->speed += s->f.arc.arrow[i]
			->obj->speed * 0.5;
		} if (s->player.tree.passive == 1)
			s->f.arc.arrow[i]->effect = "slow";

	}
	if (s->player.tree.passive == 2) {
		s->player.max_speed += s->player.max_speed * 0.2;
	}
}

void create_archer_projectiles(st_rpg *s)
{
	s->f.arc.axe = create_projectile("ressources/proj/Axe");
	s->f.arc.kal = create_st_time();
	s->f.arc.current = 0;
	s->f.arc.kalash = 0;
	s->f.arc.axeangle = 0;
	s->f.arc.kalashcount = 0;
	s->f.arc.kalashspeed = 0.08;
	s->f.arc.heal = create_aoe_from_file("ressources/spells/0/Heal");
	s->f.arc.barrage = create_aoe_from_file("ressources/spells/0/Barrage");
	s->f.arc.leaf = create_effect("power", 0, 6);
	s->f.arc.leap = create_dash(70, 800);
}

void create_archer_sound(st_rpg *s)
{
	s->f.arc.l_click =
	sfMusic_createFromFile("ressources/audio/sound/arrow.ogg");
	s->f.arc.s_leap =
	sfMusic_createFromFile("ressources/audio/sound/leap.ogg");
	s->f.arc.s_arrow_rain =
	sfMusic_createFromFile("ressources/audio/sound/arrow_rain.ogg");
	s->f.arc.s_fountain =
	sfMusic_createFromFile("ressources/audio/sound/fountain.ogg");
	sfMusic_setVolume(s->f.arc.l_click, s->s_effect);
	sfMusic_setVolume(s->f.arc.s_leap, s->s_effect);
	sfMusic_setVolume(s->f.arc.s_arrow_rain, s->s_effect);
	sfMusic_setVolume(s->f.arc.s_fountain, s->s_effect);
}
