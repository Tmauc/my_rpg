/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_aoe(sfRenderWindow *window, aoe_t *aoe)
{
	if (aoe->shot) {
		sfRenderWindow_drawSprite(window, aoe->anim->obj->sprite, NULL);
		sfRenderWindow_drawCircleShape(window, aoe->circle, NULL);
	}
}

void launch_aoe(st_rpg *s, aoe_t *aoe)
{
	sfCircleShape_setPosition(aoe->circle,
	create_vector2f(s->origin.x +
	sfMouse_getPositionRenderWindow(s->window).x -
	sfCircleShape_getRadius(aoe->circle), s->origin.y +
	sfMouse_getPositionRenderWindow(s->window).y -
	sfCircleShape_getRadius(aoe->circle)));
	sfSprite_setPosition(aoe->anim->obj->sprite,
	create_vector2f(s->origin.x +
	sfMouse_getPositionRenderWindow(s->window).x -
	aoe->anim->obj->rect.width / 2, s->origin.y +
	sfMouse_getPositionRenderWindow(s->window).y -
	aoe->anim->obj->rect.height / 2));
	aoe->anim->obj->rect.left = 0;
	aoe->anim->obj->rect.top = 0;
	aoe->anim->c = 0;
	aoe->anim->li = 0;
	aoe->shot = 1;
	aoe->count = 0;
	sfClock_restart(aoe->anim->t.clock);
}

void proc_aoe(st_rpg *s, aoe_t *aoe, float dt)
{
	if (aoe->shot)
		aoe->count += dt;
	else
		return;
	if (aoe->count >= aoe->duration) {
		aoe->shot = 0;
		s->f.cast = 0;
		aoe->count = 0;
	}
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (circle_hitbox_enemy(aoe->circle, s->f.mob[i])
			&& !my_strcmp(aoe->effect, "damage") &&
			s->f.mob[i]->alive)
			apply_aoe(s, aoe, s->f.mob[i]);
		if (circle_hitbox(aoe->circle, s->player.obj) &&
			!my_strcmp(aoe->effect, "heal"))
			heal(s, aoe->dmg);
	}
}

void destroy_aoe(aoe_t *aoe)
{
	destroy_anim(aoe->anim);
	sfCircleShape_destroy(aoe->circle);
}
