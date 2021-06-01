/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void get_cooldowns_archer(st_rpg *s)
{
	int cd1[3] = {8, 4, 6};
	int cd2[2] = {20, 15};
	int cd3[2] = {28, 10};

	s->f.cds[0] = 0.5;
	s->f.cds[1] = cd1[s->player.tree.spell1];
	s->f.cds[2] = cd2[s->player.tree.spell2];
	s->f.cds[3] = cd3[s->player.tree.spell3];
}

void get_cooldowns_gunner(st_rpg *s)
{
	int cd1[3] = {8, 4, 6};
	int cd2[2] = {20, 15};
	int cd3[2] = {30, 30};

	s->f.cds[0] = 1.9;
	s->f.cds[1] = cd1[s->player.tree.spell1];
	s->f.cds[2] = cd2[s->player.tree.spell2];
	s->f.cds[3] = cd3[s->player.tree.spell3];
}

void get_cooldowns_rogue(st_rpg *s)
{
	int cd1[3] = {8, 4, 6};
	int cd2[2] = {20, 15};
	int cd3[2] = {20, 25};

	s->f.cds[0] = 0.6;
	s->f.cds[1] = cd1[s->player.tree.spell1];
	s->f.cds[2] = cd2[s->player.tree.spell2];
	s->f.cds[3] = cd3[s->player.tree.spell3];
}

void get_cooldowns_warrior(st_rpg *s)
{
	int cd1[3] = {8, 8, 8};
	int cd2[2] = {20, 15};
	int cd3[2] = {20, 25};

	s->f.cds[0] = 0.8;
	s->f.cds[1] = cd1[s->player.tree.spell1];
	s->f.cds[2] = cd2[s->player.tree.spell2];
	s->f.cds[3] = cd3[s->player.tree.spell3];
}

void get_cooldowns(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {get_cooldowns_archer,
		get_cooldowns_gunner, get_cooldowns_rogue,
		get_cooldowns_warrior};

	(list[s->player.cdata.classe])(s);
}
