/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

st_button *create_button(char *str, g_object *object, sfColor c, int size)
{
	st_button *button = malloc(sizeof(st_button));

	button->text = create_text(str, object->pos,
	"ressources/fonts/button.ttf");
	button->obj = object;
	sfText_setColor(button->text->text, c);
	sfText_setCharacterSize(button->text->text, size);
	return (button);
}

st_button *create_vbutton(char *str, sfVector2f pos, sfColor c, int size)
{
	st_button *button = malloc(sizeof(st_button));

	button->text = create_text(str, pos, "ressources/fonts/button.ttf");
	button->obj = create_object("ressources/images/interface/void.png", pos,
	create_rect(0, 0, 0, size), 0);
	sfText_setColor(button->text->text, c);
	sfText_setCharacterSize(button->text->text, size);
	button->obj->rect.width = sfText_findCharacterPos(button->text->text,
	1000).x - sfText_findCharacterPos(button->text->text, 0).x;
	return (button);
}

void destroy_button(st_button *button)
{
	destroy_text(button->text);
	destroy_object(button->obj);
	free(button);
}

void display_button(sfRenderWindow *window, st_button *button)
{
	sfRenderWindow_drawSprite(window, button->obj->sprite, NULL);
	sfRenderWindow_drawText(window, button->text->text, NULL);
}
