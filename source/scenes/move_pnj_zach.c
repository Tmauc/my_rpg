/*
** EPITECH PROJECT, 2018
** move_pnj.c
** File description:
** move_pnj.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void update_pos_pnj_zach(st_rpg *s, int nb_pnj)
{
	walk_animation_pnj(s, nb_pnj);
	sfSprite_setTextureRect(s->fi->pnj[nb_pnj].pnj->sprite,
	s->fi->pnj[nb_pnj].pnj->rect);
	sfSprite_setPosition(s->fi->pnj[nb_pnj].pnj->sprite,
	s->fi->pnj[nb_pnj].pnj->pos);
	draw(s);
}

void move_pnj_x_zach(st_rpg *s, int posx, int nb_pnj)
{
	if (s->fi->pnj[nb_pnj].pnj->pos.x > posx) {
		while (s->fi->pnj[nb_pnj].pnj->pos.x >= posx + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.x -= 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 48;
			update_pos_pnj_zach(s, nb_pnj);
		}
	} if (s->fi->pnj[nb_pnj].pnj->pos.x < posx) {
		while (s->fi->pnj[nb_pnj].pnj->pos.x <= posx + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.x += 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 96;
			update_pos_pnj_zach(s, nb_pnj);
		}
	}
}

void move_pnj_zach(st_rpg *s, sfVector2f pos, int nb_pnj)
{
	if (s->fi->pnj[nb_pnj].pnj->pos.y > pos.y) {
		while (s->fi->pnj[nb_pnj].pnj->pos.y >= pos.y + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.y -= 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 144;
			update_pos_pnj_zach(s, nb_pnj);
		}
	} if (s->fi->pnj[nb_pnj].pnj->pos.y < pos.y) {
		while (s->fi->pnj[nb_pnj].pnj->pos.y <= pos.y + 10) {
			s->fi->pnj[nb_pnj].pnj->pos.y += 8;
			s->fi->pnj[nb_pnj].pnj->rect.top = 0;
			update_pos_pnj_zach(s, nb_pnj);
		}
	}
	move_pnj_x_zach(s, pos.x, nb_pnj);
}
