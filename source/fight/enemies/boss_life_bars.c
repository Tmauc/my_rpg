/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_boss_life_bar(st_rpg *s)
{
	if (s->boss != 0 && s->f.mob[0]->alive) {
		sfRenderWindow_drawSprite(s->window,
		s->f.boss.bar->sprite, NULL);
		sfRenderWindow_drawSprite(s->window,
		s->f.boss.life[0]->sprite, NULL);
		sfRenderWindow_drawText(s->window,
		s->f.boss.name->text, NULL);
	} if (s->boss == 3 && (s->f.mob[0]->alive || s->f.mob[1]->alive)) {
		if (!s->f.mob[0]->alive && s->f.mob[1]->alive) {
			sfRenderWindow_drawSprite(s->window,
			s->f.boss.bar->sprite, NULL);
			sfRenderWindow_drawText(s->window,
			s->f.boss.name->text, NULL);
		} if (s->f.mob[1]->alive)
			sfRenderWindow_drawSprite(s->window,
			s->f.boss.life[1]->sprite, NULL);
	}
}

void destroy_boss_life_bar(st_rpg *s)
{
	if (s->boss != 0) {
		destroy_object(s->f.boss.bar);
		destroy_object(s->f.boss.life[0]);
		destroy_text(s->f.boss.name);
	} if (s->boss == 3)
		destroy_object(s->f.boss.life[1]);
}

void update_boss_life_bar_origin(st_rpg *s)
{
	int x = s->origin.x;
	int y = s->origin.y;

	if (s->boss != 0) {
		sfSprite_setPosition(s->f.boss.bar->sprite,
		create_vector2f(x + 1000, y + 50));
		sfSprite_setPosition(s->f.boss.life[0]->sprite,
		create_vector2f(x + 1000, y + 50));
		sfText_setPosition(s->f.boss.name->text,
		(sfVector2f){x + 1200, y + 110});
	} if (s->boss == 3) {
		sfSprite_setPosition(s->f.boss.life[1]->sprite,
		create_vector2f(x + 1000, y + 75));
	}
}

void update_boss_life_bar_width(st_rpg *s)
{
	if (s->boss == 1) {
		s->f.boss.life[0]->rect.width = 700 *
		s->f.mob[0]->stat->pva / s->f.mob[0]->stat->pvm;
		sfSprite_setTextureRect(s->f.boss.life[0]->sprite,
		s->f.boss.life[0]->rect);
	} if (s->boss == 2 || s->boss == 3) {
		s->f.boss.life[0]->rect.width = 700 *
		s->f.mob[0]->stat->pva / s->f.mob[0]->stat->pvm;
		sfSprite_setTextureRect(s->f.boss.life[0]->sprite,
		s->f.boss.life[0]->rect);
	} if (s->boss == 3) {
		s->f.boss.life[1]->rect.width = 700 *
		s->f.mob[1]->stat->pva / s->f.mob[1]->stat->pvm;
		sfSprite_setTextureRect(s->f.boss.life[1]->sprite,
		s->f.boss.life[1]->rect);
	}
}

void create_boss_life_bar(st_rpg *s)
{
	if (s->boss != 0) {
		s->f.boss.bar = create_object(
		"ressources/images/interface/boss_lifebar.png",
		create_vector2f(0, 0), create_rect(0, 0, 700, 50), 0);
		s->f.boss.life[0] = create_object(
		"ressources/images/interface/boss_lifebar.png",
		create_vector2f(0, 0), create_rect(50, 0, 700, 50), 0);
	} if (s->boss == 3) {
		s->f.boss.life[0]->rect.height = 25;
		s->f.boss.life[1] = create_object(
		"ressources/images/interface/boss_lifebar.png",
		create_vector2f(0, 0), create_rect(75, 0, 700, 25), 0);
	}
	create_boss_name(s);
}
