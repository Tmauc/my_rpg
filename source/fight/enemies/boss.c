/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_boss(st_rpg *s)
{
	if (s->boss == 1)
		destroy_samy(s);
	if (s->boss == 2)
		destroy_champ(s);
	if (s->boss == 3) {
		destroy_champ(s);
		destroy_ly(s);
	}
	destroy_boss_life_bar(s);
}

void display_boss(st_rpg *s)
{
	if (s->boss == 1)
		display_samy(s);
	if (s->boss == 2)
		display_champ(s);
	if (s->boss == 3) {
		display_champ(s);
		display_ly(s);
	}
	display_boss_life_bar(s);
}

void update_boss(st_rpg *s, float dt)
{
	if (s->boss == 1)
		update_samy(s, dt);
	if (s->boss == 2)
		update_champ(s, dt);
	if (s->boss == 3) {
		update_champ(s, dt);
		update_ly(s, dt);
	}
	update_boss_life_bar_width(s);
}

int boss_is_dead(st_rpg *s)
{
	if (s->boss == 1 || s->boss == 2) {
		if (!s->f.mob[0]->alive) {
			win(s, "You win");
			return (1);
		}
	} if (s->boss == 3) {
		if (!s->f.mob[0]->alive && !s->f.mob[1]->alive) {
			win(s, "You win");
			return (1);
		}
	}
	return (0);
}

void generate_boss(st_rpg *s)
{
	if (s->boss == 1)
		generate_samy(s);
	if (s->boss == 2) {
		for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1)
			destroy_enemy(s->f.mob[i]);
		s->proc.pvar.enemy_nbr = 1;
		s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
		generate_champ(s);
	} if (s->boss == 3) {
		generate_ly(s);
		generate_champ(s);
	}
	create_boss_life_bar(s);
}
