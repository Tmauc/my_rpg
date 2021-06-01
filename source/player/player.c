/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_player(st_rpg *s)
{
	free(s->player.stat);
	destroy_object(s->player.weapon[0]);
	destroy_object(s->player.obj);
	sfClock_destroy(s->player.t.clock);
	if (check_double_class(s))
		destroy_object(s->player.weapon[1]);
}

int check_double_class(st_rpg *s)
{
	if (s->player.cdata.classe == 1 || s->player.cdata.classe == 2)
		return (1);
	return (0);
}

void create_player(st_rpg *s)
{
	sfVector2f scale = {2, 2};

	s->player.obj = create_object("ressources/images/hero.png",
	create_vector2f(3700, 3800),
	create_rect(0, 0 + 150 * s->player.cdata.sex, 48, 48), 0);
	sfSprite_scale(s->player.obj->sprite, scale);
	s->player.animcol = 1;
	s->player.animsens = 1;
	s->player.animspeed = 0.2;
	s->player.t = create_st_time();
	init_player_movement(s);
	init_player_camera(s);
}

void display_player_bless(st_rpg *s)
{
	int a = s->f.recover->count * 100;
	if ((a % 20) > 10) {
		sfRenderWindow_drawSprite(s->window,
		s->player.obj->sprite, &s->f.shade.bless.state);
	}
}

void display_player(st_rpg *s)
{
	if (s->f.recover->count > 0) {
		display_player_bless(s);
	} else {
		display_player_shade(s);
	}
	sfRenderWindow_drawSprite(s->window, s->player.weapon[0]->sprite, NULL);
	if (check_double_class(s))
		sfRenderWindow_drawSprite(s->window, s->player.weapon[1]
		->sprite, NULL);
}
