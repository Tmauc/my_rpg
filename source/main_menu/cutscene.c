/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my_rpg.h"

void display_menu_background(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->mainm.abyss[0]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.abyss[1]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.rock2[0]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.rock2[1]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->mainm.rockback[0]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window,
	s->mainm.rockback[1]->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.first->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.rope->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->mainm.guy->sprite, NULL);
}

int event_main_menu_cutscene(st_rpg *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtClosed) {
			destroy_main_menu(s);
			return (1);
		}
		if (event.type == sfEvtKeyPressed) {
			s->mainm.rope->rect.left = 70 * 14;
			sfSprite_setTextureRect(s->mainm.rope->sprite,
			s->mainm.rope->rect);
			return (2);
		}
	}
	return (0);
}

void movement_mainm(st_rpg *s)
{
	s->mainm.first->pos.y -= s->mainm.first->speed;
	sfSprite_setPosition(s->mainm.first->sprite, s->mainm.first->pos);
	for (int i = 0; i != 2; i += 1) {
		s->mainm.rockback[i]->pos.y -= s->mainm.rockback[i]->speed;
		s->mainm.rock2[i]->pos.y -= s->mainm.rock2[i]->speed;
		s->mainm.abyss[i]->pos.y -= s->mainm.abyss[i]->speed;
		if (s->mainm.rockback[i]->pos.y <= -2936)
			s->mainm.rockback[i]->pos.y += 2936 * 2;
		if (s->mainm.rock2[i]->pos.y <= -2236)
			s->mainm.rock2[i]->pos.y += 2236 * 2;
		if (s->mainm.abyss[i]->pos.y <= -5712)
			s->mainm.abyss[i]->pos.y += 5712 * 2;
		sfSprite_setPosition(s->mainm.rockback[i]->sprite,
		s->mainm.rockback[i]->pos);
		sfSprite_setPosition(s->mainm.abyss[i]->sprite,
		s->mainm.abyss[i]->pos);
		sfSprite_setPosition(s->mainm.rock2[i]->sprite,
		s->mainm.rock2[i]->pos);
	}
}

void rope_animation(st_rpg *s)
{
	s->mainm.t.time = sfClock_getElapsedTime(s->mainm.t.clock);
	s->mainm.t.sec = s->mainm.t.time.microseconds / 1000000.0;
	if (s->mainm.t.sec > 0.1 && s->mainm.rope->rect.left < 950) {
		s->mainm.rope->rect.left += 70;
		sfSprite_setTextureRect(s->mainm.rope->sprite,
		s->mainm.rope->rect);
		sfClock_restart(s->mainm.t.clock);
	}
}

int main_menu_cutscene(st_rpg *s)
{
	int a = 0;

	while (sfRenderWindow_isOpen(s->window)) {
		a = event_main_menu_cutscene(s);
		if (a == 1 || a == 2)
			return (a);
		rope_animation(s);
		if (s->mainm.rope->rect.left > 950)
			break;
		display_menu_background(s);
		sfRenderWindow_display(s->window);
	}
	return (0);
}
