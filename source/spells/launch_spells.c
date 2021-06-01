/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void launch_auto_attack(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {archer_auto_attack, gunner_auto_attack,
		rogue_auto_attack, warrior_auto_attack};

	(list[s->player.cdata.classe])(s);
}

void launch_spell1(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {choose_spell1_archer,
		choose_spell1_gunner, choose_spell1_rogue,
		choose_spell1_warrior};

	(list[s->player.cdata.classe])(s);
}

void launch_spell2(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {choose_spell2_archer,
		choose_spell2_gunner, choose_spell2_rogue,
		choose_spell2_warrior};

	(list[s->player.cdata.classe])(s);
}

void launch_spell3(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {choose_spell3_archer,
		choose_spell3_gunner, choose_spell3_rogue,
		choose_spell3_warrior};

	(list[s->player.cdata.classe])(s);
}

void launch_spells(st_rpg *s)
{
	if (sfMouse_isButtonPressed(sfMouseLeft) && s->f.cdcount[0] <= 0) {
		s->f.cdcount[0] = s->f.cds[0];
		launch_auto_attack(s);
	} if (sfMouse_isButtonPressed(sfMouseRight) && s->f.cdcount[1] <= 0 &&
	!s->player.tree.lock[s->player.tree.spell1 + 3]) {
		s->f.cdcount[1] = s->f.cds[1];
		launch_spell1(s);
	} if (sfKeyboard_isKeyPressed(sfKeyE) && s->f.cdcount[2] <= 0 &&
	!s->player.tree.lock[s->player.tree.spell2 + 6]) {
		s->f.cdcount[2] = s->f.cds[2];
		launch_spell2(s);
	} if (sfKeyboard_isKeyPressed(sfKeyR) && s->f.cdcount[3] <= 0 &&
	!s->player.tree.lock[s->player.tree.spell3 + 8]) {
		s->f.cdcount[3] = s->f.cds[3];
		launch_spell3(s);
	}
}
