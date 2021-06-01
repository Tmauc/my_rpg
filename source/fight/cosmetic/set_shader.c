/*
** EPITECH PROJECT, 2018
** set_shader.c
** File description:
** description
*/

#include "my_rpg.h"

void destroy_dungeon_shader(st_rpg *s)
{
	destroy_shader(&s->f.shade.vanish);
	destroy_shader(&s->f.shade.power);
	destroy_shader(&s->f.shade.armor);
	destroy_shader(&s->f.shade.endure);
	destroy_shader(&s->f.shade.poison);
	destroy_shader(&s->f.shade.stun);
	destroy_shader(&s->f.shade.samy_roda);
	destroy_shader(&s->f.shade.samy_rush);
	destroy_shader(&s->f.shade.champ);
	destroy_shader(&s->f.shade.bless);
}

void set_shader(st_rpg *s)
{
	s->f.shade.vanish = create_shader("shader/vanish.frag", 0);
	s->f.shade.power = create_shader("shader/power.frag", 0);
	s->f.shade.armor = create_shader("shader/stun.frag", 0);
	s->f.shade.poison = create_shader("shader/poison.frag", 0);
	s->f.shade.stun = create_shader("shader/stun.frag", 0);
	s->f.shade.bless = create_shader("shader/bless.frag", 0);
	s->f.shade.samy_roda = create_shader("shader/samy_roda.frag", 0);
	s->f.shade.samy_rush = create_shader("shader/samy_rush.frag", 0);
	s->f.shade.champ = create_shader("shader/champ.frag", 0);
	s->f.shade.endure = create_shader("shader/endure.frag", 1);
}
