/*
** EPITECH PROJECT, 2018
** diplay_player_shader.c
** File description:
** description
*/

#include "my_rpg.h"

void display_warrior_shad(st_rpg *s)
{
	if (s->f.war.endure->count > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.endure.state);
	} else if (s->f.war.lifesteal->count > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.power.state);
	} else {
		if (s->f.war.parade->amount == 1 &&
		s->player.tree.passive == 0 &&
		!s->player.tree.lock[0]) {
			sfRenderWindow_drawSprite(s->window,
			s->player.obj->sprite, &s->f.shade.armor.state);
		} else {
			sfRenderWindow_drawSprite(s->window,
			s->player.obj->sprite, NULL);
		}
	}
}

void display_gunner_shad(st_rpg *s)
{
	if (s->f.gun.rush->count > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.power.state);
	} else {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, NULL);
	}
}

void display_archer_shad(st_rpg *s)
{
	if (s->f.arc.leaf->count > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.power.state);
	} else {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, NULL);
	}
}

void display_rogue_shad(st_rpg *s)
{
	if (s->f.rog.vanish > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.vanish.state);
	} else {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, NULL);
	}
}

void display_player_shade(st_rpg *s)
{
	void (*list[4])(st_rpg *s) = {display_archer_shad, display_gunner_shad,
		display_rogue_shad, display_warrior_shad};

	(list[s->player.cdata.classe])(s);
	s->f.shade.endure.time.time =
	sfClock_getElapsedTime(s->f.shade.endure.time.clock);
	s->f.shade.endure.time.sec =
	s->f.shade.endure.time.time.microseconds / 1000000.0;
	if (s->f.shade.endure.time.sec > 1 &&
	s->f.shade.endure.time.sec < 2) {
		sfShader_setFloatParameter(s->f.shade.endure.shader, "time",
		-s->f.shade.endure.time.sec);
	} else {
		sfShader_setFloatParameter(s->f.shade.endure.shader, "time",
		s->f.shade.endure.time.sec);
	}
	if (s->f.shade.endure.time.sec > 2) {
		sfClock_restart(s->f.shade.endure.time.clock);
	}
}
