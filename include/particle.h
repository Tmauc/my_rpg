/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** structurates
*/

#ifndef PARTICLES_H_
#define PARTICLES_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>

typedef struct particle_info
{
	sfVector2i size;
	float speed;
	int rands;
	float life;
	float lsave;
	float fade;
	sfVector2i r;
	sfVector2i g;
	sfVector2i b;
	int a;
	float angle;
	sfVector2f ratios;
} infopart_t;

typedef struct particle
{
	sfVertex *vertex;
	infopart_t *info;
	int size;
} particle_t;

#endif
