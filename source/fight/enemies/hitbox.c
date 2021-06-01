/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void get_object_ends_enemy(enemy_t *mob, sfVector2f points[4])
{
	sfVector2f ratios = get_ratios(sfSprite_getRotation(mob->obj->sprite));
	int width = mob->obj->rect.width * mob->scale.x;
	int height = mob->obj->rect.height * mob->scale.y;
	float x = mob->obj->pos.x;
	float y = mob->obj->pos.y;

	points[0] = create_vector2f(x + 0.1 * (ratios.x * width + ratios.y *
	height), y + 0.1 * (ratios.x * height + ratios.y * width));
	points[1] = create_vector2f(x + 0.9 * ratios.x * width + 0.1 * ratios.y
	* height, y + 0.9 * ratios.y * width + 0.1 * ratios.x * height);
	points[2] = create_vector2f(x + 0.9 * ratios.y * height + 0.1 * ratios.x
	* width, y + 0.9 * ratios.x * height + 0.1 * ratios.y * width);
	points[3] = create_vector2f(x + 0.9 * (ratios.x * width + ratios.y *
	height), y + 0.9 * (ratios.x * height + ratios.y * width));
}

int check_inside_target_enemy(sfVector2f *coord1, sfVector2f *coord2)
{
	for (int i = 0; i != 4; i += 1) {
		if (coord1[i].x > coord2[0].x && coord1[i].x < coord2[1].x &&
			coord1[i].y > coord2[0].y && coord1[i].y < coord2[2].y)
			return (1);
	}
	return (0);
}

int enemy_hitbox(g_object *attack, enemy_t *mob)
{
	sfVector2f coord1[4];
	sfVector2f coord2[4];
	get_object_ends(attack, coord1);
	get_object_ends_enemy(mob, coord2);

	if (check_inside_target_enemy(coord1, coord2)) {
		return (1);
	}
	return (0);
}

int circle_hitbox_enemy(sfCircleShape *circle, enemy_t *mob)
{
	sfVector2f coord1[4];
	int radius = sfCircleShape_getRadius(circle);
	sfVector2f pos = sfCircleShape_getPosition(circle);
	sfVector2f center = create_vector2f(pos.x + radius,
	pos.y + radius);
	int in = 0;

	get_object_ends_enemy(mob, coord1);
	for (int i = 0; i != 4; i += 1) {
		if (sqrt(powf(coord1[i].x - center.x, 2) + powf(coord1[i].y
			- center.y, 2)) <= radius)
			in += 1;
	}
	if (in >= 2)
		return (1);
	return (0);
}
