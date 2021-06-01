/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_samy(st_rpg *s, float dt)
{
	s->f.mob[0]->cdcount -= dt;
	if (s->f.mob[0]->cdcount < 0 && enemy_is_able(s, 0)) {
		s->f.mob[0]->cast = 2;
		s->f.boss.casting = 1;
		s->f.boss.attack = rand() % 2;
		if (s->f.mob[0]->stat->pva < s->f.mob[0]->stat->pvm / 2 &&
			s->f.boss.rage->amount == 0)
			s->f.boss.attack = 2;
		choose_sound(s);
	} if (s->f.boss.casting > 0) {
		s->f.boss.casting -= dt;
	} if (s->f.boss.casting < 0) {
		s->f.mob[0]->cdcount = s->f.mob[0]->cd;
		s->f.mob[0]->cast = 0;
		s->f.boss.casting = 0;
		launch_samy_spell(s);
	}
	update_samy_dash(s, dt);
	update_samy_fusrohdah(s);
	update_particle(s->f.boss.samy_part, dt);
}

int choose_samy_diplay(st_rpg *s)
{
	if (s->f.boss.casting > 0 && s->f.boss.attack == 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.samy_rush.state);
		return (0);
	} else if (s->f.boss.casting > 0 && s->f.boss.attack == 1) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.samy_roda.state);
		return (0);
	} else if (s->f.boss.casting > 0 && s->f.boss.attack == 2 &&
	s->f.mob[0]->poison->count <= 0 && s->f.mob[0]->stun->count <= 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.power.state);
		return (0);
	}
	return (1);
}

void display_samy(st_rpg *s)
{
	if (s->f.mob[0]->alive && choose_samy_diplay(s) == 1) {
		choose_display_enemies(s, 0);
		display_particle(s->f.boss.samy_part, s->window);
		display_particle(s->f.boss.samy_fus, s->window);
	}
}

void destroy_samy(st_rpg *s)
{
	destroy_dash(s->f.boss.dash);
	destroy_dash(s->f.boss.fus);
	destroy_effect(s->f.boss.rage);
	sfMusic_destroy(s->f.boss.samy_roda);
	sfMusic_destroy(s->f.boss.samy_rage);
	destroy_particle(s->f.boss.samy_part);
	destroy_particle(s->f.boss.samy_fus);
}
