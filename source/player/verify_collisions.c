/*
** EPITECH PROJECT, 2018
** verify_collisions.c
** File description:
** verify collisions for player and map
*/

#include "my.h"
#include "my_rpg.h"

int vcollide(char block)
{
	if (block == ' ' || block == 'E' || block == 'S' || block == 'B') {
		return (1);
	}
	return (0);
}

int is_wall(char block)
{
	char *blocks_str = "TLRVWNPAZUYHOIGJ";

	for (int i = 0; blocks_str[i] != '\0'; i++) {
		if (blocks_str[i] == block)
			return (1);
	}
	return (0);
}

int interval(float value, float less, float max)
{
	if (value > less && value < max)
		return (1);
	return (0);
}
