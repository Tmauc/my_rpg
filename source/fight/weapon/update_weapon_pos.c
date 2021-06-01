/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void archer_update_pos_weapon(st_rpg *s)
{
	float angle = get_angle(s);
	sfVector2f ratios = get_ratios(angle);
	float sizey = sfTexture_getSize(s->player.weapon[0]->texture).y;

	sfSprite_setRotation(s->player.weapon[0]->sprite, angle);
	s->player.weapon[0]->pos =
	create_vector2f(s->origin.x + 960 + 47 * ratios.x + sizey / 2 *
	ratios.y, s->origin.y + 540 + 47 * ratios.y - sizey / 2 * ratios.x);
	sfSprite_setPosition(s->player.weapon[0]->sprite,
	s->player.weapon[0]->pos);
}

void gunner_update_pos_weapon(st_rpg *s)
{
	float angle = get_angle(s);
	sfVector2f ratios = get_ratios(angle);

	for (int i = 0; i != 2; i += 1) {
		sfSprite_setRotation(s->player.weapon[i]->sprite, angle);
		sfSprite_setScale(s->player.weapon[i]->sprite,
		create_vector2f(2.5, 1.5));
		s->player.weapon[i]->pos =
		create_vector2f(s->origin.x + 960 + 47 *
		ratios.y, s->origin.y + 540 - 47 * ratios.x);
		if (i == 0) {
			s->player.weapon[i]->pos =
			create_vector2f(s->origin.x + 960 - 33 *
			ratios.y, s->origin.y + 540 + 33 * ratios.x);
			sfSprite_setScale(s->player.weapon[i]->sprite,
			create_vector2f(2.5, -1.5));
		}
		sfSprite_setPosition(s->player.weapon[i]->sprite,
		s->player.weapon[i]->pos);
	}
}

void rogue_update_pos_weapon(st_rpg *s)
{
	float angle = get_angle(s);
	sfVector2f ratios = get_ratios(angle);

	for (int i = 0; i != 2; i += 1) {
		if (s->f.rog.auto_a[i]->shot == 0)
			sfSprite_setRotation(s->player.weapon[i]->sprite,
			angle);
		sfSprite_setScale(s->player.weapon[i]->sprite,
		create_vector2f(-0.5, 1));
		s->player.weapon[i]->pos =
		create_vector2f(s->origin.x + 960 + 47 *
		ratios.y, s->origin.y + 540 - 47 * ratios.x);
		if (i == 1)
			s->player.weapon[i]->pos =
			create_vector2f(s->origin.x + 960 - 33 *
			ratios.y, s->origin.y + 540 + 33 * ratios.x);
		sfSprite_setPosition(s->player.weapon[i]->sprite,
		s->player.weapon[i]->pos);
	}
}

void warrior_update_pos_weapon(st_rpg *s)
{
	float angle = get_angle(s);
	sfVector2f ratios = get_ratios(angle);

	if (s->f.war.auto_a->shot == 0) {
		sfSprite_setRotation(s->player.weapon[0]->sprite, angle);
		sfSprite_setScale(s->player.weapon[0]->sprite,
		create_vector2f(0.2, 1));
	}
	s->player.weapon[0]->pos = create_vector2f(
	s->origin.x + 960 + 20 * ratios.x,
	s->origin.y + 540 + 20 * ratios.y);
	sfSprite_setPosition(s->player.weapon[0]->sprite,
	s->player.weapon[0]->pos);
}

void update_pos_weapon(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {archer_update_pos_weapon,
		gunner_update_pos_weapon, rogue_update_pos_weapon,
		warrior_update_pos_weapon};

	(list[s->player.cdata.classe])(s);
}
