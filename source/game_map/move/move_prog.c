/*
** EPITECH PROJECT, 2018
** move_prog.c
** File description:
** move file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void move_allpts2(pos_t *pos, st_rpg *s)
{
	pos[6].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 4);
	pos[6].y = s->fi->ID_character->pos.y;
	pos[7].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2) +
	(s->fi->ID_character->rect.width / 4);
	pos[7].y = s->fi->ID_character->pos.y;
	pos[8].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 4);
	pos[8].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	pos[9].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2) +
	(s->fi->ID_character->rect.width / 4);
	pos[9].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
}

void move_allpts(pos_t *pos, st_rpg *s)
{
	pos[0].x = s->fi->ID_character->pos.x - 5;
	pos[0].y = s->fi->ID_character->pos.y;
	pos[1].x = s->fi->ID_character->pos.x +
	s->fi->ID_character->rect.width;
	pos[1].y = s->fi->ID_character->pos.y;
	pos[2].x = s->fi->ID_character->pos.x - 5;
	pos[2].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	pos[3].x = s->fi->ID_character->pos.x +
	s->fi->ID_character->rect.width;
	pos[3].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	pos[4].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2);
	pos[4].y = s->fi->ID_character->pos.y;
	pos[5].x = s->fi->ID_character->pos.x +
	(s->fi->ID_character->rect.width / 2);
	pos[5].y = s->fi->ID_character->pos.y +
	s->fi->ID_character->rect.height;
	move_allpts2(pos, s);
}

void move_id_player(st_rpg *s)
{
	s->fi->ID_character->rect.left = s->player.obj->rect.left;
	s->fi->ID_character->rect.top = s->player.obj->rect.top;
	s->fi->ID_character->rect.width = s->player.obj->rect.width + 10;
	s->fi->ID_character->rect.height = s->player.obj->rect.height - 16;
	s->fi->ID_character->pos.x = s->player.obj->pos.x + 14;
	s->fi->ID_character->pos.y = s->player.obj->pos.y + 66;
	move_allpts(s->fi->pos, s);
	sfSprite_setTextureRect(s->fi->ID_character->sprite,
	s->fi->ID_character->rect);
	sfSprite_setPosition(s->fi->ID_character->sprite,
	s->fi->ID_character->pos);
}

void move_ok(st_rpg *s)
{
	verify_x_movement(s);
	verify_y_movement(s);
}
