/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"
#include "game_map.h"

void destroy_pause_menu(st_rpg *s)
{
	sfView_setCenter(s->fi->view, s->fi->camera);
	sfRenderWindow_setView(s->window, s->fi->view);
	destroy_tree_menu(s);
	destroy_status_menu(s);
	destroy_button(s->pausm.title);
	for (int i = 0; i != 5; i += 1)
		destroy_button(s->pausm.button[i]);
	destroy_object(s->pausm.cursor);
	destroy_object(s->pausm.window);
	destroy_text(s->pausm.saved);
}

void display_pause_menu(st_rpg *s)
{
	display_object(s->window, s->pausm.window);
	display_object(s->window, s->pausm.cursor);
	for (int i = 0; i != 5; i += 1)
		display_button(s->window, s->pausm.button[i]);
	display_button(s->window, s->pausm.title);
	if (s->pausm.opac > 0) {
		sfText_setColor(s->pausm.saved->text,
		(sfColor){255, 255, 255, s->pausm.opac});
		sfRenderWindow_drawText(s->window,
		s->pausm.saved->text, NULL);
		s->pausm.opac -= 2;
	}
}

void which_display(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {display_pause_menu, display_status_menu,
		display_tree_menu};

	(list[s->pausm.menu])(s);
}

void which_update(st_rpg *s)
{
	if (s->pausm.menu == 1)
		update_status_menu(s);
	if (s->pausm.menu == 2)
		update_tree_menu(s);
}

void generate_pause_menu(st_rpg *s)
{
	generate_pause_menu_window(s);
	generate_pause_menu_buttons(s);
}
