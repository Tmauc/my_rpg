/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_gunner_part2(st_rpg *s)
{
	if (s->f.gun.grenade->shot == 1)
		display_projectile(s->window, s->f.gun.grenade);
	if (s->f.gun.grenade->shot == 2)
		sfRenderWindow_drawSprite(s->window,
		s->f.gun.explosion->obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->f.gun.boots->obj->sprite, NULL);
	if (s->f.gun.bullet[9]->shot == 2)
		sfRenderWindow_drawSprite(s->window,
		s->f.gun.expbullet->obj->sprite, NULL);
	display_particle(s->f.gun.partf, s->window);
	display_particle(s->f.gun.partg, s->window);
}

void display_gunner(st_rpg *s)
{
	for (int i = 99; i != -1; i -= 1)
		display_projectile(s->window, s->f.gun.flame[i]);
	for (int i = 0; i != 10; i += 1) {
		display_projectile(s->window, s->f.gun.bullet[i]);
		display_projectile(s->window, s->f.gun.ultb[i]);
		if (s->f.gun.ultb[i]->shot)
			sfRenderWindow_drawSprite(s->window,
			s->f.gun.trait[i]->sprite, NULL);
	}
	display_projectile(s->window, s->f.gun.blitz);
	display_projectile(s->window, s->f.gun.net);
	display_gunner_part2(s);
}
