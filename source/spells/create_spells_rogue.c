/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_rogue_daggers_part2(st_rpg *s)
{
	s->f.rog.auto_a[0] = create_swing_from_file("ressources/spells/2/auto");
	s->f.rog.auto_a[0]->sens = -s->f.rog.auto_a[0]->sens;
	s->f.rog.auto_a[1] =
	create_swing_from_file("ressources/spells/2/auto2");
	s->f.rog.zone = create_aoe_from_file("ressources/spells/2/Zone");
	s->f.rog.flash = create_aoe_from_file("ressources/spells/2/Flash");
	s->f.rog.fscale = 1;
	s->f.rog.tp = create_dash(2000, 2000);
	s->f.rog.draw = create_dash(200, 1000);
}

void create_rogue_daggers(st_rpg *s)
{
	for (int i = 0; i != 30; i += 1)
		s->f.rog.dagger[i] = create_projectile("ressources/proj/Kunai");
	s->f.rog.ultspeed = 0.1;
	s->f.rog.side = 0;
	s->f.rog.ultcount = 0;
	s->f.rog.ultangle = 1;
	s->f.rog.ulting = 0;
	s->f.rog.vanish = 0;
	s->f.rog.auto_bool = 0;
	s->f.rog.current = 0;
	s->f.rog.ultt = create_st_time();
	s->f.rog.dance = create_projectile("ressources/spells/2/Kunai");
	create_rogue_daggers_part2(s);
}

void create_rogue_autos(st_rpg *s)
{
	s->f.rog.bstab = 0;
	s->f.rog.bdmg = s->f.rog.auto_a[0]->dmg * 3;
	s->f.rog.backstab = create_button("M1",
	create_object("ressources/spells/2/auto2.png",
	create_vector2f(s->origin.x + 200, s->origin.y + 800),
	create_rect(0, 0, 128, 128), 0), sfWhite, 25);
	s->f.rog.bpos[0] = create_vector2f(0, 0);
	s->f.rog.bpos[1] = create_vector2f(0, 0);
	s->f.rog.brat = create_vector2f(0, 0);
	s->f.rog.bcount = 0;
	if (s->player.tree.passive == 1) {
		s->player.stat->frc += 0.1 * s->player.stat->frc;
	}
	s->f.rog.ultr = create_rect(0, 48 + 144 * s->player.cdata.sex, 48, 48);
	s->f.rog.partp = create_particle("ressources/particles/shadowstep");
	s->f.rog.partd = create_particle("ressources/particles/withdraw");
}

void create_rogue_sound(st_rpg *s)
{
	s->f.rog.l_click =
	sfMusic_createFromFile("ressources/audio/sound/dag.ogg");
	s->f.rog.flashbang =
	sfMusic_createFromFile("ressources/audio/sound/flashbang.ogg");
	s->f.rog.s_vanish =
	sfMusic_createFromFile("ressources/audio/sound/vanish.ogg");
	s->f.rog.s_ult =
	sfMusic_createFromFile("ressources/audio/sound/rog_ult.ogg");
	s->f.rog.s_dag_toss =
	sfMusic_createFromFile("ressources/audio/sound/throw_dag.ogg");
	sfMusic_setVolume(s->f.rog.l_click, s->s_effect);
	sfMusic_setVolume(s->f.rog.flashbang, s->s_effect);
	sfMusic_setVolume(s->f.rog.s_vanish, s->s_effect);
	sfMusic_setVolume(s->f.rog.s_ult, s->s_effect);
	sfMusic_setVolume(s->f.rog.s_dag_toss, s->s_effect);
}
