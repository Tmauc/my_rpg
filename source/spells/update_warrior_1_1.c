/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_proc_quake(st_rpg *s)
{
	stop_player(s);
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (circle_hitbox_enemy(s->f.war.crack->circle, s->f.mob[i]) &&
			s->f.mob[i]->alive)
			apply_aoe(s, s->f.war.crack, s->f.mob[i]);
	}
	s->f.cast = 0;
	s->f.war.ultd->on = 0;
}

void warrior_update_quake(st_rpg *s)
{
	if (s->f.war.ultd->on) {
		s->f.war.ultd->count -= s->f.war.ultd->speed;
		if (s->f.war.ultd->count <= 0) {
			launch_aoe(s, s->f.war.crack);
			sfCircleShape_setPosition(s->f.war.crack->circle,
			create_vector2f(s->origin.x + 960 -
			sfCircleShape_getRadius(s->f.war.crack->circle),
			s->origin.y + 540 - sfCircleShape_getRadius(s
			->f.war.crack->circle)));
			sfSprite_setTextureRect(s->f.war.crack->anim->obj
			->sprite, create_rect(0, 0, 250, 250));
			sfSprite_setPosition(s->f.war.crack->anim->obj->sprite,
			create_vector2f(s->origin.x + 960 - s->f.war.crack
			->anim->obj->rect.width, s->origin.y + 540 -
			s->f.war.crack->anim->obj->rect.height));
			warrior_proc_quake(s);
		}
	}
}
