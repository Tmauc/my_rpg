/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_main_particles(st_rpg *s)
{
	destroy_particle(s->part.lvlup);
}

void update_main_particles(st_rpg *s, float dt)
{
	update_particle(s->part.lvlup, dt);
}

void display_main_particles(st_rpg *s)
{
	display_particle(s->part.lvlup, s->window);
}

void create_main_particles(st_rpg *s)
{
	s->part.lvlup = create_particle("ressources/particles/levelup");
}
