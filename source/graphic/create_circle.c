/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

sfCircleShape *create_circle(int radius, int thickness, sfColor color)
{
	sfCircleShape *circle = sfCircleShape_create();
	sfCircleShape_setRadius(circle, radius);
	sfCircleShape_setOutlineColor(circle, color);
	sfCircleShape_setFillColor(circle, sfTransparent);
	sfCircleShape_setOutlineThickness(circle, thickness);
	return (circle);
}
