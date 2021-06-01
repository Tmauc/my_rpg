/*
** EPITECH PROJECT, 2018
** fill_screen.c
** File description:
** fill the screen with one color
*/

#include "my.h"
#include "my_rpg.h"

void my_fill_screen(framebuffer_t *buffer, sfColor color)
{
	for (unsigned int y = 0; y < buffer->height; y++) {
		for (unsigned int x = 0; x < buffer->width; x++) {
			my_put_pixel(buffer, x, y, color);
		}
	}
}

void fill_minimap_screen(framebuffer_t *buffer, sfColor color)
{
	color.a = 128;
	for (unsigned int y = 0; y < buffer->height; y++) {
		for (unsigned int x = 0; x < buffer->width; x++) {
			my_put_pixel(buffer, x, y, color);
		}
	}
}

void reset_screen(framebuffer_t *buffer)
{
	sfColor trans = {0, 0, 0, 0};

	for (unsigned int y = 0; y < buffer->height; y++) {
		for (unsigned int x = 0; x < buffer->width; x++) {
			my_put_pixel(buffer, x, y, trans);
		}
	}
}
