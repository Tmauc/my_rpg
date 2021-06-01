/*
** EPITECH PROJECT, 2018
** print_text_finish_quests.c
** File description:
** print_text_finish_quests.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void print_text_finish_quests2(st_rpg *s, int posx, int posy)
{
	sfText_setColor(s->fi->text_finish_quests->text,
	(sfColor){0, 0, 0, s->fi->var_for_quests});
	sfText_setPosition(s->fi->text_finish_quests->text,
	create_vector2f(posx, posy - 3));
	sfRenderWindow_drawText(s->window,
	s->fi->text_finish_quests->text, NULL);
	sfText_setColor(s->fi->text_finish_quests->text,
	(sfColor){0, 0, 0, s->fi->var_for_quests});
	sfText_setPosition(s->fi->text_finish_quests->text,
	create_vector2f(posx, posy + 3));
	sfRenderWindow_drawText(s->window,
	s->fi->text_finish_quests->text, NULL);
	sfText_setColor(s->fi->text_finish_quests->text,
	(sfColor){255, 255, 255, s->fi->var_for_quests});
	sfText_setPosition(s->fi->text_finish_quests->text,
	create_vector2f(posx, posy));
	sfRenderWindow_drawText(s->window,
	s->fi->text_finish_quests->text, NULL);
}

void print_text_finish_quests(st_rpg *s)
{
	float posx = s->fi->camera.x - 200;
	float posy = s->fi->camera.y - 200;

	if (s->fi->quests[0]->status_text == 1 && s->fi->var_for_quests != 0) {
		sfText_setColor(s->fi->text_finish_quests->text,
		(sfColor){0, 0, 0, s->fi->var_for_quests});
		sfText_setPosition(s->fi->text_finish_quests->text,
		create_vector2f(posx - 3, posy));
		sfRenderWindow_drawText(s->window,
		s->fi->text_finish_quests->text, NULL);
		sfText_setColor(s->fi->text_finish_quests->text,
		(sfColor){0, 0, 0, s->fi->var_for_quests});
		sfText_setPosition(s->fi->text_finish_quests->text,
		create_vector2f(posx + 3, posy));
		sfRenderWindow_drawText(s->window,
		s->fi->text_finish_quests->text, NULL);
		print_text_finish_quests2(s, posx, posy);
		s->fi->var_for_quests -= 1;
	}
}
