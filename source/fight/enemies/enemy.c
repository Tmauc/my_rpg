/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_enemies(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1)
		destroy_enemy(s->f.mob[i]);
	destroy_boss(s);
}

void update_enemies(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		update_life_bars_enemies(s, i);
		set_aggro_enemies(s, i);
		attack_enemy(s, i);
	}
	enemies_animation(s);
}

char *get_enemy_path(void)
{
	switch (rand() % 6) {
	case 0:
		return ("ressources/enemies/Fanatic");
	case 1:
		return ("ressources/enemies/Blob");
	case 2:
		return ("ressources/enemies/Bat");
	case 3:
		return ("ressources/enemies/Demon");
	case 4:
		return ("ressources/enemies/Minotaur");
	case 5:
		return ("ressources/enemies/Ghost");
	}
	return (NULL);
}

void generate_enemies(st_rpg *s)
{
	s->proc.pvar.enemy_nbr = s->proc.pvar.min_enemies + rand() %
	(s->proc.pvar.max_enemies - s->proc.pvar.min_enemies);
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	for (int i = 0; i < s->proc.pvar.enemy_nbr; i++) {
		s->f.mob[i] = generate_enemy(get_enemy_path());
		s->f.mob[i]->obj->pos = create_ennemy_position(s);
		sfSprite_setPosition(s->f.mob[i]->obj->sprite,
		s->f.mob[i]->obj->pos);
		sfSprite_setScale(s->f.mob[i]->obj->sprite,
		(sfVector2f){s->f.mob[i]->scale.x, s->f.mob[i]->scale.y});
	}
	generate_boss(s);
}
