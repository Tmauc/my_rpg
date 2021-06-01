/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_boss_name(st_rpg *s)
{
	if (s->boss == 1) {
		s->f.boss.name = create_text("Corrupted Samy",
		(sfVector2f){0, 0}, "ressources/fonts/boss.otf");
	} if (s->boss == 2) {
		s->f.boss.name = create_text("Champ",
		(sfVector2f){0, 0}, "ressources/fonts/boss.otf");
	} if (s->boss == 3) {
		s->f.boss.name = create_text("Champ & Ly",
		(sfVector2f){0, 0}, "ressources/fonts/boss.otf");
	} if (s->boss != 0)
		sfText_setCharacterSize(s->f.boss.name->text, 80);
}
