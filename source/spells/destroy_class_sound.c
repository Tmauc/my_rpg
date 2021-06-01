/*
** EPITECH PROJECT, 2018
** destroy_class_sound.c
** File description:
** description
*/

#include "my_rpg.h"

void destroy_gunner_sound(st_rpg *s)
{
	destroy_particle(s->f.gun.partf);
	destroy_particle(s->f.gun.partg);
	sfMusic_destroy(s->f.gun.l_click);
	sfMusic_destroy(s->f.gun.s_explo);
	sfMusic_destroy(s->f.gun.zap);
	sfMusic_destroy(s->f.gun.h_noon);
	sfMusic_destroy(s->f.gun.s_flam);
	sfMusic_destroy(s->f.gun.s_net);
}

void destroy_rogue_sound(st_rpg *s)
{
	sfMusic_destroy(s->f.rog.l_click);
	sfMusic_destroy(s->f.rog.s_vanish);
	sfMusic_destroy(s->f.rog.flashbang);
	sfMusic_destroy(s->f.rog.s_ult);
	sfMusic_destroy(s->f.rog.s_dag_toss);
}

void destroy_archer_sound(st_rpg *s)
{
	sfMusic_destroy(s->f.arc.l_click);
	sfMusic_destroy(s->f.arc.s_leap);
	sfMusic_destroy(s->f.arc.s_arrow_rain);
	sfMusic_destroy(s->f.arc.s_fountain);
}

void destroy_warrior_sound(st_rpg *s)
{
	sfMusic_destroy(s->f.war.s_shield);
	sfMusic_destroy(s->f.war.s_endure);
	sfMusic_destroy(s->f.war.s_sword1);
	sfMusic_destroy(s->f.war.s_sword2);
	sfMusic_destroy(s->f.war.s_hasaki);
	sfMusic_destroy(s->f.war.s_rush);
	sfMusic_destroy(s->f.war.s_stomp);
}
