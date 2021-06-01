/*
** EPITECH PROJECT, 2018
** player_animations.c
** File description:
** anim for player
*/

#include "my.h"
#include "my_rpg.h"

int orientation_from_mouse(st_rpg *s)
{
	float angle = get_angle(s);

	if (angle > -33 && angle < 33)
		return (2);
	if (angle < -33 && angle > -145)
		return (3);
	if (angle > 33 && angle < 145)
		return (0);
	return (1);
}

void walk_animation(st_rpg *s)
{
	s->player.t.time = sfClock_getElapsedTime(s->player.t.clock);
	s->player.t.sec = s->player.t.time.microseconds / 1000000.0;
	if (s->player.t.sec > s->player.animspeed) {
		if (s->player.animcol == 2 || s->player.animcol == 0)
			s->player.animsens = -s->player.animsens;
		s->player.animcol += s->player.animsens;
		sfClock_restart(s->player.t.clock);
		s->player.obj->rect.left = s->player.animcol * 48
		+ 144 * s->player.cdata.sex;
	}
}

void player_animation(st_rpg *s)
{
	if (abs(s->player.nbr_frame.x) != 0 || abs(s->player.nbr_frame.y) != 0)
		walk_animation(s);
	s->player.obj->rect.top = orientation_from_mouse(s) * 48;
	sfSprite_setTextureRect(s->player.obj->sprite,
	s->player.obj->rect);
}

void update_player_position(st_rpg *rpg)
{
	rpg->player.acceleration.y =
	rpg->player.max_speed * (rpg->player.nbr_frame.y / 10.);
	rpg->player.acceleration.x =
	rpg->player.max_speed * (rpg->player.nbr_frame.x / 10.);
	verify_collide_map(rpg);
}
