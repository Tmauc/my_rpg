/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void warrior_stance(st_rpg *s)
{
	sfMusic_play(s->f.war.s_shield);
	s->f.cast = 2;
	stop_player(s);
	launch_aoe(s, s->f.war.shield);
	sfCircleShape_setPosition(s->f.war.shield->circle,
	create_vector2f(s->origin.x + 960 - sfCircleShape_getRadius(s
	->f.war.shield->circle),
	s->origin.y + 540 - sfCircleShape_getRadius(s->f.war.shield->circle)));
	sfSprite_setPosition(s->f.war.shield->anim->obj->sprite,
	create_vector2f(s->origin.x + 960 - s->f.war.shield->anim->obj
	->rect.width / 2,
	s->origin.y + 540 - s->f.war.shield->anim->obj->rect.height / 2));
}

void warrior_lifesteal(st_rpg *s)
{
	s->f.war.lifesteal->count = s->f.war.lifesteal->duration;
}

void choose_spell2_warrior(st_rpg *s)
{
	void (*list[2])(st_rpg *s) = {warrior_stance, warrior_lifesteal};

	(list[s->player.tree.spell2])(s);
}
