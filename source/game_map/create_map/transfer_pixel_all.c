/*
** EPITECH PROJECT, 2018
** transfer_pixel_all.c
** File description:
** transfer_pixel_all file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void transfer_pixel_background(st_rpg *s, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (s->fi->map.layer_background[compter] > 0) {
		s->fi->map.y = height * 32;
		setpixel_to_image_background(s,
		s->fi->map.layer_background[compter], c, p);
	}
}

void transfer_pixel_relief(st_rpg *s, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (s->fi->map.layer_relief[compter] == 0)
		s->fi->map.layer_relief[compter] = 342;
	s->fi->map.y = height * 32;
	setpixel_to_image_relief(s, s->fi->map.layer_relief[compter], c, p);
}

void transfer_pixel_col(st_rpg *s, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (s->fi->map.layer_col[compter] == 0)
		s->fi->map.layer_col[compter] = 342;
	s->fi->map.y = height * 32;
	setpixel_to_image_col(s, s->fi->map.layer_col[compter], c, p);
}

void transfer_pixel_colid(st_rpg *s, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (s->fi->map.layer_colID[compter] == 0)
		s->fi->map.layer_colID[compter] = 342;
	s->fi->map.y = height * 32;
	setpixel_to_image_colid(s, s->fi->map.layer_colID[compter], c, p);
}

void transfer_pixel_prof(st_rpg *s, int compter, int height)
{
	int c = 0;
	int p = 0;

	if (s->fi->map.layer_prof[compter] == 0)
		s->fi->map.layer_prof[compter] = 342;
	s->fi->map.y = height * 32;
	setpixel_to_image_prof(s, s->fi->map.layer_prof[compter], c, p);
}
