/*
** EPITECH PROJECT, 2018
** move_pnj.c
** File description:
** move_pnj.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void walk_animation_pnj(st_rpg *s, int nb_pnj)
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
		s->fi->pnj[nb_pnj].pnj->rect.left = s->player.animcol * 48;
	}
}

void update_pos_pnj(st_rpg *s, int nb_pnj)
{
	walk_animation_pnj(s, nb_pnj);
	sfSprite_setTextureRect(s->fi->pnj[nb_pnj].pnj->sprite,
	s->fi->pnj[nb_pnj].pnj->rect);
	sfSprite_setPosition(s->fi->pnj[nb_pnj].pnj->sprite,
	s->fi->pnj[nb_pnj].pnj->pos);
	draw(s);
}

void move_pnj_x(st_rpg *s, int posx, int nb_pnj)
{
	if (s->fi->pnj[nb_pnj].pnj->pos.x > posx) {
		while (s->fi->pnj[nb_pnj].pnj->pos.x >= posx + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.x -= 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 48;
			update_pos_pnj(s, nb_pnj);
		}
	} if (s->fi->pnj[nb_pnj].pnj->pos.x < posx) {
		while (s->fi->pnj[nb_pnj].pnj->pos.x <= posx + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.x += 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 96;
			update_pos_pnj(s, nb_pnj);
		}
	}
}

void move_pnj(st_rpg *s, int posx, int posy, int nb_pnj)
{
	if (s->fi->pnj[nb_pnj].pnj->pos.y > posy) {
		while (s->fi->pnj[nb_pnj].pnj->pos.y >= posy + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.y -= 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 144;
			update_pos_pnj(s, nb_pnj);
		}
	} if (s->fi->pnj[nb_pnj].pnj->pos.y < posy) {
		while (s->fi->pnj[nb_pnj].pnj->pos.y <= posy + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.y += 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 0;
			update_pos_pnj(s, nb_pnj);
		}
	}
	move_pnj_x(s, posx, nb_pnj);
}
