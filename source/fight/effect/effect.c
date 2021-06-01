/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_effect(effect_t *effect)
{
	free(effect);
}

effect_t *create_effect(char *type, int amount, float duration)
{
	effect_t *effect = malloc(sizeof(effect_t));

	effect->type = type;
	effect->amount = amount;
	effect->duration = duration;
	effect->count = 0;
	return (effect);
}

void proc_effect(effect_t *effect, float dt)
{
	if (effect->count > 0)
		effect->count -= dt;
}
