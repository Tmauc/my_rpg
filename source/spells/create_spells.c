/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_spells_archer(st_rpg *s)
{
	create_archer_passive(s);
	create_archer_projectiles(s);
	create_archer_sound(s);
}

void create_spells_gunner(st_rpg *s)
{
	create_gunner_bullets(s);
	create_gunner_second(s);
	create_gunner_explosions(s);
	create_gunner_ults(s);
	create_gunner_sound(s);
}

void create_spells_rogue(st_rpg *s)
{
	create_rogue_daggers(s);
	create_rogue_autos(s);
	create_rogue_sound(s);
}

void create_spells_warrior(st_rpg *s)
{
	create_spells_warrior1(s);
	create_spells_warrior2(s);
	create_warrior_sound(s);
}

void create_class(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {create_spells_archer,
		create_spells_gunner, create_spells_rogue,
		create_spells_warrior};

	(list[s->player.cdata.classe])(s);
}
