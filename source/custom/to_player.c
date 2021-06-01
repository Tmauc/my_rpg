/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_player_from_cust(st_rpg *s)
{
	s->player.cdata = s->cust.cdata;
	s->player.cdata.quest = 0;
	create_weapon(s);
	s->player.tree.skillp = 0;
	create_first_tree(s);
	s->player.stat = create_first_stat();
}
