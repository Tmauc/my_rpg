/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** main.c
*/

#include <SFML/Graphics.h>

sfIntRect create_rect(int top, int left, int width, int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfVector2f create_vector2f(float x, float y)
{
	sfVector2f pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

sfVector2i create_vector2i(int x, int y)
{
	sfVector2i size;

	size.x = x;
	size.y = y;
	return (size);
}
