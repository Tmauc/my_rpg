/*
** EPITECH PROJECT, 2018
** transfer_pixel.c
** File description:
** transfer_pixel file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void transfer_pixel(st_rpg *s)
{
	int width = 0;
	int height = 0;
	int compter = 0;

	while (height != 100) {
		width = 0;
		draw_loading(s);
		while (width != 60) {
			transfer_pixel_background(s, compter, height);
			transfer_pixel_relief(s, compter, height);
			transfer_pixel_col(s, compter, height);
			transfer_pixel_colid(s, compter, height);
			transfer_pixel_prof(s, compter, height);
			s->fi->map.x2 += 32;
			width++;
			compter++;
		}
		s->fi->map.x2 = 0;
		height++;
	}
}
