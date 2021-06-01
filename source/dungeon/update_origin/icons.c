/*
** EPITECH PROJECT, 2018
** main_proc.c
** File description:
** main_proc file for procedural gen
*/

#include "my.h"
#include "my_rpg.h"

void origin_icons(st_rpg *s)
{
	int x = s->origin.x + 200;
	int y = s->origin.y + 800;

	for (int i = 0; i != 4; i += 1) {
		sfSprite_setPosition(s->f.icons[i]->obj->sprite,
		create_vector2f(x + i * 100, y));
		sfText_setPosition(s->f.icons[i]->text->text,
		create_vector2f(x + i * 100, y));
		sfSprite_setPosition(s->f.cd[i]->sprite,
		create_vector2f(x + i * 100, y));
		if (i != 3)
			sfSprite_setPosition(s->f.locks[i]->sprite,
			create_vector2f(x + 120 + 100 * i, y + 20));
	}
	if (s->player.cdata.classe == 2) {
		sfSprite_setPosition(s->f.rog.backstab->obj->sprite,
		(sfVector2f){x, y});
		sfText_setPosition(s->f.rog.backstab->text->text,
		(sfVector2f){x, y});
	}
}
