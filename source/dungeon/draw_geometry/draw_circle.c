/*
** EPITECH PROJECT, 2018
** draw_circle.c
** File description:
** draw_circle functions file
*/

#include "my.h"
#include "my_rpg.h"

void my_draw_line(framebuffer_t *b, int pos1[2], int pos2[2], sfColor c)
{
	float cx = pos2[0] - pos1[0];
	float cy = pos2[0] - pos1[1];
	float ix = 0;
	float iy = 0;
	unsigned int max = 0;

	if (my_abs(cx) > my_abs(cy))
		max = my_abs(cx);
	else
		max = my_abs(cy);
	ix = cx / (float)max;
	iy = cy / (float)max;
	cx = pos1[0];
	cy = pos1[1];
	for (unsigned int i = 0; i < max; i++) {
		cx = cx + ix;
		cy = cy + iy;
		my_put_pixel(b, (int)cx, (int)cy, c);
	}
}

void my_draw_octan(framebuffer_t *buffer, int r, int pos[2], sfColor color)
{
	int x = 0;
	int y = r;
	int m = 5 - 4 * r;

	while (x <= y) {
		my_put_pixel(buffer, x + pos[0], y + pos[1], color);
		if (m > 0) {
			y = y - 1;
			m = m - 8 * y;
		}
		x = x + 1;
		m = m + 8 * x + 4;
	}
}

void my_draw_circle(framebuffer_t *buffer, int pos[2], int r, sfColor c)
{
	int x = 0;
	int y = r;
	int m = 5 - 4 * r;

	while (x <= y) {
		my_put_pixel(buffer, x + pos[0], y + pos[1], c);
		my_put_pixel(buffer, y + pos[0], x + pos[1], c);
		my_put_pixel(buffer, -1 * x + pos[0], y + pos[1], c);
		my_put_pixel(buffer, -1 * y + pos[0], x + pos[1], c);
		my_put_pixel(buffer, x + pos[0], -1 * y + pos[1], c);
		my_put_pixel(buffer, y + pos[0], -1 * x + pos[1], c);
		my_put_pixel(buffer, -1 * x + pos[0], -1 * y + pos[1], c);
		my_put_pixel(buffer, -1 * y + pos[0], -1 * x + pos[1], c);
		if (m > 0) {
			y = y - 1;
			m = m - 8 * y;
		}
		x = x + 1;
		m = m + 8 * x + 4;
	}
}

void my_draw_circle_filled(framebuffer_t *b, int pos[2], int r, sfColor c)
{
	for (int i = 1; i <= r; i++)
		my_draw_circle(b, pos, i, c);
}
