/*
** EPITECH PROJECT, 2018
** my_draw_rect.c
** File description:
** draw a rect on the screen
*/

#include "my.h"
#include "my_rpg.h"

void my_draw_rect(framebuffer_t *buff, int pos[2], int size[2], sfColor color)
{
	int cx = 0;
	int cy = 0;

	while (cy != size[1]) {
		my_put_pixel(buff, pos[0] + cx, pos[1] + cy, color);
		if (cx == size[0] - 1) {
			cx = 0;
			cy = cy + 1;
		} else {
			cx = cx + 1;
		}
	}
}

void my_draw_vrect(framebuffer_t *buff, int pos[2], int size[2], sfColor color)
{
	for (int x = pos[0]; x < pos[0] + size[0]; x++)
		my_put_pixel(buff, x, pos[1], color);
	for (int x = pos[0]; x < pos[0] + size[0]; x++)
		my_put_pixel(buff, x, pos[1] + size[1] - 1, color);
	for (int y = pos[1]; y < pos[1] + size[1]; y++)
		my_put_pixel(buff, pos[0], y, color);
	for (int y = pos[1]; y < pos[1] + size[1]; y++)
		my_put_pixel(buff, pos[0] + size[0] - 1, y, color);
}

void my_draw_f_rect(framebuffer_t *buff, int pos[2], int size[2], int diag[4])
{
	sfColor white_trans = {255, 255, 255, 128};
	int temp_pos[2] = {pos[0], pos[1]};

	size[0] /= 2;
	size[1] /= 2;
	if (diag[0] == 1) {
		my_draw_rect(buff, temp_pos, size, white_trans);
	} if (diag[1] == 1) {
		temp_pos[0] = pos[0] + size[0];
		temp_pos[1] = pos[1];
		my_draw_rect(buff, temp_pos, size, white_trans);
	} if (diag[2] == 1) {
		temp_pos[0] = pos[0];
		temp_pos[1] = pos[1] + size[1];
		my_draw_rect(buff, temp_pos, size, white_trans);
	} if (diag[3] == 1) {
		temp_pos[0] = pos[0] + size[0];
		temp_pos[1] = pos[1] + size[1];
		my_draw_rect(buff, temp_pos, size, white_trans);
	}
}
