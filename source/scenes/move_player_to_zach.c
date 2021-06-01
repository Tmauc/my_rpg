/*
** EPITECH PROJECT, 2018
** move_pnj.c
** File description:
** move_pnj.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void walk_animation_player_zach(st_rpg *s)
{
	s->fi->pnj_clock.tmp =
	sfClock_getElapsedTime(s->fi->pnj_clock.clock);
	s->fi->pnj_clock.seconds =
	s->fi->pnj_clock.tmp.microseconds / 1000000.0;
	if (s->fi->pnj_clock.seconds > 0.1) {
		if (s->player.animcol == 2 || s->player.animcol == 0)
			s->player.animsens = -s->player.animsens;
		s->player.animcol += s->player.animsens;
		sfClock_restart(s->fi->pnj_clock.clock);
		s->player.obj->rect.left = s->player.animcol * 48
		+ 144 * s->player.cdata.sex;
	}
}

void update_pos_player_zach(st_rpg *s)
{
	walk_animation_player_zach(s);
	sfSprite_setTextureRect(s->player.obj->sprite,
	s->player.obj->rect);
	sfSprite_setPosition(s->player.obj->sprite,
	s->player.obj->pos);
	draw(s);
}

void move_player_x_zach(st_rpg *s, int posx)
{
	if (s->player.obj->pos.x > posx) {
		while (s->player.obj->pos.x >= posx + 10) {
			s->player.obj->pos.x -= 8;
			s->player.obj->rect.top = 48;
			update_pos_player_zach(s);
		}
	} if (s->player.obj->pos.x < posx) {
		while (s->player.obj->pos.x <= posx + 10) {
			s->player.obj->pos.x += 8;
			s->player.obj->rect.top = 96;
			update_pos_player_zach(s);
		}
	}
}

void move_player_to_zach(st_rpg *s, sfVector2f pos)
{
	if (s->player.obj->pos.y > pos.y) {
		while (s->player.obj->pos.y >= pos.y + 10) {
			s->player.obj->pos.y -= 8;
			s->player.obj->rect.top = 144;
			update_pos_player_zach(s);
		}
	} if (s->player.obj->pos.y < pos.y) {
		while (s->player.obj->pos.y <= pos.y + 10) {
			s->player.obj->pos.y += 8;
			s->player.obj->rect.top = 0;
			update_pos_player_zach(s);
		}
	}
	move_player_x_zach(s, pos.x);
}
