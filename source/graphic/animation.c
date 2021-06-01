/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_anim(st_anim *anim)
{
	destroy_object(anim->obj);
	sfClock_destroy(anim->t.clock);
	free(anim);
}

st_anim *create_anim(g_object *obj, sfVector2i max, float speed)
{
	st_anim *anim = malloc(sizeof(st_anim));

	anim->height = obj->rect.height;
	anim->width = obj->rect.width;
	anim->obj = obj;
	anim->t = create_st_time();
	anim->hor = max.x;
	anim->ver = max.y;
	anim->speed = speed;
	anim->c = 0;
	anim->li = 0;
	return (anim);
}

void clocked_animation(st_anim *anim)
{
	anim->t.time = sfClock_getElapsedTime(anim->t.clock);
	anim->t.sec = anim->t.time.microseconds / 1000000.0;
	if (anim->t.sec > anim->speed && anim->li < anim->ver) {
		anim->c += 1;
		if (anim->c == anim->hor) {
			anim->c = 0;
			anim->li += 1;
		}
		anim->t.sec = 0;
		sfClock_restart(anim->t.clock);
		anim->obj->rect.left = anim->c * anim->width;
		anim->obj->rect.top = anim->li * anim->height;
		sfSprite_setTextureRect(anim->obj->sprite, anim->obj->rect);
	}
}
