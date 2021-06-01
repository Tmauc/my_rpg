/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_cust(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->cust.back->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->cust.circle->sprite, NULL);
	for (int i = 0; i != cust_get_buttons(s->cust.menu); i += 1)
		sfRenderWindow_drawText(s->window,
		s->cust.bt[i]->text->text, NULL);
	sfRenderWindow_drawSprite(s->window, s->cust.cursor->sprite, NULL);
	if (s->cust.chosen)
		sfRenderWindow_drawSprite(s->window,
		s->cust.face->sprite, NULL);
}

void destroy_cust_buttons(st_rpg *s)
{
	int i = cust_minx_buttons(s->cust.menu);

	while (i != cust_maxx_buttons(s->cust.menu) + 1) {
		destroy_button(s->cust.bt[i]);
		i += 1;
	}
}

void custom_destroy(st_rpg *s)
{
	destroy_object(s->cust.back);
	destroy_object(s->cust.face);
	destroy_object(s->cust.cursor);
	destroy_object(s->cust.circle);
	destroy_cust_buttons(s);
}

void cust_initialize_buttons(st_rpg *s)
{
	sfColor grey = {96, 96, 96, 255};

	s->cust.bt[0] = create_vbutton("Back to menu",
	create_vector2f(25, 880), grey, 70);
	s->cust.bt[1] = create_vbutton("Male", create_vector2f(1100, 600),
	grey, 70);
	s->cust.bt[2] = create_vbutton("Female", create_vector2f(1400, 600),
	grey, 70);
	s->cust.face = create_object("ressources/images/heroface.png",
	create_vector2f(450,
	500), create_rect(0, 0, 100, 100), 0);
	sfSprite_setScale(s->cust.face->sprite, create_vector2f(2, 2));
	s->cust.chosen = 0;
}

void create_st_custom(st_rpg *s)
{
	s->cust.sens = 0.25;
	s->cust.pos = 0;
	s->cust.menu = 1;
	s->cust.option = 1;
	s->cust.cdata.classe = 0;
	s->cust.cdata.sex = 0;
	s->cust.cdata.name = my_calloc(sizeof(char) * 14);
	s->cust.option = 1;
	s->cust.cmin = 710;
	s->cust.cmax = 715;
	s->cust.circle = create_object("ressources/images/cust/circle.png",
	create_vector2f(300, 600), create_rect(0, 0, 520, 170), 0);
	s->cust.back = create_object("ressources/images/cust/bg.png",
	create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 0);
	cust_initialize_buttons(s);
	s->cust.cursor = create_object("ressources/images/interface/cursor.png",
	create_vector2f(1180, 710), create_rect(0, 0, 150, 150), 0);
	sfSprite_setScale(s->cust.cursor->sprite, create_vector2f(0.5, 0.5));
	sfSprite_setRotation(s->cust.cursor->sprite, -90);
}
