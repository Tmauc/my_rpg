/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_locked_spells_cd(st_rpg *s)
{
	if (s->player.tree.lock[s->player.tree.spell1 + 3])
		sfSprite_setTextureRect(s->f.cd[1]->sprite, create_rect(0, 0,
		sfSprite_getTextureRect(s->f.cd[1]->sprite).height,
		sfSprite_getTextureRect(s->f.cd[1]->sprite).height));
	if (s->player.tree.lock[s->player.tree.spell2 + 6])
		sfSprite_setTextureRect(s->f.cd[2]->sprite, create_rect(0, 0,
		sfSprite_getTextureRect(s->f.cd[2]->sprite).height,
		sfSprite_getTextureRect(s->f.cd[2]->sprite).height));
	if (s->player.tree.lock[s->player.tree.spell3 + 8])
		sfSprite_setTextureRect(s->f.cd[3]->sprite, create_rect(0, 0,
		sfSprite_getTextureRect(s->f.cd[3]->sprite).height,
		sfSprite_getTextureRect(s->f.cd[3]->sprite).height));
}

void display_locked_spells(st_rpg *s)
{
	if (s->player.tree.lock[s->player.tree.spell1 + 3])
		display_object(s->window, s->f.locks[0]);
	if (s->player.tree.lock[s->player.tree.spell2 + 6])
		display_object(s->window, s->f.locks[1]);
	if (s->player.tree.lock[s->player.tree.spell3 + 8])
		display_object(s->window, s->f.locks[2]);
}
