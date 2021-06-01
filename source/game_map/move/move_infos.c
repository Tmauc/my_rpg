/*
** EPITECH PROJECT, 2018
** move_infos.c
** File description:
** move_info file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void move_infos_box_des(st_rpg *s, sfVector2f pos_quests_des,
sfVector2f pos_quests_des_text)
{
	s->fi->quests_box.quests_des->obj->pos = pos_quests_des;
	sfSprite_setPosition(s->fi->quests_box.quests_des->obj->sprite,
	s->fi->quests_box.quests_des->obj->pos);
	s->fi->quests_box.quests_des->text->pos = pos_quests_des_text;
	sfText_setPosition(s->fi->quests_box.quests_des->text->text,
	s->fi->quests_box.quests_des->text->pos);
}

void move_infos_box(st_rpg *s)
{
	sfVector2f pos_quests_box =
	create_vector2f(s->fi->camera.x - 960, s->fi->camera.y - 540);
	sfVector2f pos_quests_box_text =
	create_vector2f(pos_quests_box.x + 10, pos_quests_box.y + 27);
	sfVector2f pos_quests_des =
	create_vector2f(s->fi->camera.x - 960, s->fi->camera.y - 540 +
	s->fi->quests_box.quests_box->obj->rect.height);
	sfVector2f pos_quests_des_text =
	create_vector2f(pos_quests_box.x + 10, pos_quests_box.y + 90);

	s->fi->quests_box.quests_box->obj->pos = pos_quests_box;
	sfSprite_setPosition(s->fi->quests_box.quests_box->obj->sprite,
	s->fi->quests_box.quests_box->obj->pos);
	s->fi->quests_box.quests_box->text->pos = pos_quests_box_text;
	sfText_setPosition(s->fi->quests_box.quests_box->text->text,
	s->fi->quests_box.quests_box->text->pos);
	move_infos_box_des(s, pos_quests_des, pos_quests_des_text);
}
