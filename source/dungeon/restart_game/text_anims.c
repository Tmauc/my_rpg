/*
** EPITECH PROJECT, 2018
** text_anims.c
** File description:
** anims for text in menu loading for next level
*/

#include "my.h"
#include "my_rpg.h"

void fade_in_text(sfRenderWindow *window, sfText *text)
{
	sfColor anim_color = sfWhite;

	anim_color.a = 0;
	while (anim_color.a < 255) {
		anim_color.a += 3;
		sfRenderWindow_clear(window, sfBlack);
		sfText_setColor(text, anim_color);
		sfRenderWindow_drawText(window, text, NULL);
		sfRenderWindow_display(window);
	}
}

void fade_out_text(sfRenderWindow *window, sfText *text)
{
	sfColor anim_color = sfWhite;

	while (anim_color.a > 0) {
		anim_color.a -= 3;
		sfRenderWindow_clear(window, sfBlack);
		sfText_setColor(text, anim_color);
		sfRenderWindow_drawText(window, text, NULL);
		sfRenderWindow_display(window);
	}
}
