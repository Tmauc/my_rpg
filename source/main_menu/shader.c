/*
** EPITECH PROJECT, 2018
** shader.c
** File description:
** description
*/

#include "my_rpg.h"

void shader_move(st_rpg *s)
{
	s->mainm.shader.time.time =
	sfClock_getElapsedTime(s->mainm.shader.time.clock);
	s->mainm.shader.time.sec =
	s->mainm.shader.time.time.microseconds / 1000000.0;
	if (s->mainm.shader.time.sec > 1 &&
	s->mainm.shader.time.sec < 2) {
		sfShader_setFloatParameter(s->mainm.shader.shader, "time",
		-s->mainm.shader.time.sec);
	} else {
		sfShader_setFloatParameter(s->mainm.shader.shader, "time",
		s->mainm.shader.time.sec);
	}
	if (s->mainm.shader.time.sec > 2) {
		sfClock_restart(s->mainm.shader.time.clock);
	}
}
