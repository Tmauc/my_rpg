/*
** EPITECH PROJECT, 2018
** choicebox_create_event.c
** File description:
** choicebox_create_event.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int create_choice_box_middle(st_rpg *s, int i, char **tab, int j)
{
	float pos_x = s->fi->camera.x + 446;
	float pos_y = s->fi->camera.y + 230;
	float pos_text_x = pos_x + 70;
	float posy = 0;

	posy = pos_y - 60 - (60 * i);
	s->fi->pnj[s->fi->nb_pnj].choice_box[i] = create_button(tab[j],
	create_object("ressources/images/dialog_box/choice_box2.png",
	create_vector2f(pos_x, posy),
	create_rect(0, 0, 460, 60), 0), sfWhite, 35);
	sfText_setPosition(s->fi->pnj[s->fi->nb_pnj].choice_box[i]->text->text,
	create_vector2f(pos_text_x, posy + 10));
	return (posy);
}

void create_choice_box(st_rpg *s, int compter, char **tab)
{
	int i;
	int j = compter - 1;
	float pos_x = s->fi->camera.x + 446;
	float pos_y = s->fi->camera.y + 230;
	float posy = 0;

	s->fi->pnj[s->fi->nb_pnj].choice_box =
	malloc(sizeof(st_button) * compter + 4);
	s->fi->pnj[s->fi->nb_pnj].choice_box_edge[1] =
	create_object("ressources/images/dialog_box/choice_box3.png",
	create_vector2f(pos_x, pos_y), create_rect(0, 0, 460, 32), 0);
	for (i = 0; i != compter; i++, j--)
		posy = create_choice_box_middle(s, i, tab, j);
	posy = pos_y - 60 - (60 * i);
	s->fi->pnj[s->fi->nb_pnj].choice_box_edge[0] =
	create_object("ressources/images/dialog_box/choice_box1.png",
	create_vector2f(pos_x, posy + 28), create_rect(0, 0, 460, 32), 0);
	s->fi->pnj[s->fi->nb_pnj].cursor =
	create_object("ressources/images/dialog_box/cursor.png",
	create_vector2f(pos_x + 38, posy + 77), create_rect(0, 0, 24, 24), 0);
}

int event_keyreturn(st_rpg *s, int a, int compter, sfEvent event)
{
	if (event.type == sfEvtKeyPressed ||
	event.type == sfEvtMouseButtonPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			a++;
		} if (sfKeyboard_isKeyPressed(sfKeyUp) ||
		sfKeyboard_isKeyPressed(sfKeyZ)) {
			up_cursor(s);
		} if (sfKeyboard_isKeyPressed(sfKeyDown) ||
		sfKeyboard_isKeyPressed(sfKeyS)) {
			down_cursor(s, compter);
		}
	}
	return (a);
}

int event_choice_box(st_rpg *s, int compter)
{
	int a = 0;
	sfEvent event;

	while (sfRenderWindow_pollEvent(s->window, &event)) {
		a = event_keyreturn(s, a, compter, event);
	}
	return (a);
}
