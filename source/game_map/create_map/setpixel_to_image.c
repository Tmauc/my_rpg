/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void setpixel_to_image_relief(st_rpg *s, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	for (; c != 32; c++) {
		p = 0;
		s->fi->map.x = s->fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			s->fi->map.color =
			sfImage_getPixel(s->fi->map.image, x, y);
			sfImage_setPixel(s->fi->map.map_relief, s->fi->map.x,
			s->fi->map.y, s->fi->map.color);
			p++;
			x++;
			s->fi->map.x++;
		}
		s->fi->map.y++;
		y++;
	}
}

void setpixel_to_image_prof(st_rpg *s, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	for (; c != 32; c++) {
		p = 0;
		s->fi->map.x = s->fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			s->fi->map.color =
			sfImage_getPixel(s->fi->map.image, x, y);
			sfImage_setPixel(s->fi->map.map_prof, s->fi->map.x,
			s->fi->map.y, s->fi->map.color);
			p++;
			x++;
			s->fi->map.x++;
		}
		s->fi->map.y++;
		y++;
	}
}

void setpixel_to_image_colid(st_rpg *s, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	for (; c != 32; c++) {
		p = 0;
		s->fi->map.x = s->fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			s->fi->map.color =
			sfImage_getPixel(s->fi->map.image, x, y);
			sfImage_setPixel(s->fi->map.map_colID, s->fi->map.x,
			s->fi->map.y, s->fi->map.color);
			p++;
			x++;
			s->fi->map.x++;
		}
		s->fi->map.y++;
		y++;
	}
}

void setpixel_to_image_col(st_rpg *s, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	for (; c != 32; c++) {
		p = 0;
		s->fi->map.x = s->fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			s->fi->map.color =
			sfImage_getPixel(s->fi->map.image, x, y);
			sfImage_setPixel(s->fi->map.map_col, s->fi->map.x,
			s->fi->map.y, s->fi->map.color);
			p++;
			x++;
			s->fi->map.x++;
		}
		s->fi->map.y++;
		y++;
	}
}

void setpixel_to_image_background(st_rpg *s, int col, int c, int p)
{
	int x = 0;
	int compter = (col / 31);
	int y = compter * 32;

	for (; c != 32; c++) {
		p = 0;
		s->fi->map.x = s->fi->map.x2;
		x = (col - compter * 31) * 32 - 32;
		while (p != 32) {
			s->fi->map.color =
			sfImage_getPixel(s->fi->map.image, x, y);
			sfImage_setPixel(s->fi->map.map_backgound, s->fi->map.x,
			s->fi->map.y, s->fi->map.color);
			p++;
			x++;
			s->fi->map.x++;
		}
		s->fi->map.y++;
		y++;
	}
}
