/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_create_weapon(st_rpg *s)
{
	s->player.weapon[0] = create_object(
	"ressources/images/weapon/bow.png",
	create_vector2f(960, 540), create_rect(0, 0, 6, 46), 0);
}

void gunner_create_weapon(st_rpg *s)
{
	s->player.weapon[0] = create_object(
	"ressources/images/weapon/gun.png",
	create_vector2f(960, 540), create_rect(0, 0, 12, 11), 0);
	s->player.weapon[1] = create_object(
	"ressources/images/weapon/gun.png",
	create_vector2f(960, 540), create_rect(0, 0, 12, 11), 0);
}

void rogue_create_weapon(st_rpg *s)
{
	s->player.weapon[0] = create_object(
	"ressources/images/weapon/dagger.png",
	create_vector2f(960, 540), create_rect(0, 0, 80, 13), 0);
	s->player.weapon[1] = create_object(
	"ressources/images/weapon/dagger.png",
	create_vector2f(960, 540), create_rect(0, 0, 80, 13), 0);
}

void warrior_create_weapon(st_rpg *s)
{
	s->player.weapon[0] = create_object(
	"ressources/images/weapon/greatsword.png",
	create_vector2f(960, 540), create_rect(0, 0, 93, 21), 0);
}

void create_weapon(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {archer_create_weapon,
		gunner_create_weapon, rogue_create_weapon,
		warrior_create_weapon};

	(list[s->player.cdata.classe])(s);
}
