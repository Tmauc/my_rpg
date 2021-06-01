/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_champ(st_rpg *s, float dt)
{
	for (int i = 0; i != 6; i += 1)
		clocked_animation(s->f.boss.tent[i]->anim);
	clocked_animation(s->f.boss.well->anim);
	clocked_animation(s->f.boss.ball->anim);
	s->f.mob[0]->cdcount -= dt;
	update_shadowball(s, dt);
	if (precedent_tentacle_is_mid(s))
		update_tentacle(s);
	if (s->f.mob[0]->cdcount < 0 && enemy_is_able(s, 0)) {
		s->f.mob[0]->cdcount  = s->f.mob[0]->cd;
		launch_champ_spells(s);
	}
	update_well(s);
}

int choose_display_champ(st_rpg *s)
{
	if (s->f.boss.casting > 0) {
		sfRenderWindow_drawSprite(s->window,
		s->f.mob[0]->obj->sprite, &s->f.shade.champ.state);
		return (0);
	}
	return (1);
}

void display_champ(st_rpg *s)
{
	if (s->f.mob[0]->alive && choose_display_champ(s) == 1) {
		choose_display_enemies(s, 0);
	}
	for (int i = 0; i != 6; i += 1)
		display_aoe(s->window, s->f.boss.tent[i]);
	display_aoe(s->window, s->f.boss.well);
	display_aoe(s->window, s->f.boss.ball);
}

void destroy_champ(st_rpg *s)
{
	for (int i = 0; i != 6; i += 1)
		destroy_aoe(s->f.boss.tent[i]);
	destroy_aoe(s->f.boss.well);
	destroy_aoe(s->f.boss.ball);
	sfMusic_destroy(s->f.boss.s_ball);
	sfMusic_destroy(s->f.boss.s_tent);
}
