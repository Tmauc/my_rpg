/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my_rpg.h"
#include "my.h"

void destroy_tree_menu(st_rpg *s)
{
	destroy_object(s->treem.window);
	destroy_button(s->treem.classe);
	destroy_text(s->treem.skillp);
	for (int i = 0; i != 4; i += 1)
		destroy_text(s->treem.sp[i]);
	free_tbl(s->treem.spells);
	for (int i = 0; i != 10; i += 1) {
		destroy_object(s->treem.lock[i]);
		if (i < 2) {
			destroy_object(s->treem.e[i]);
			destroy_object(s->treem.r[i]);
		} if (i < 3) {
			destroy_object(s->treem.m2[i]);
			destroy_object(s->treem.pas[i]);
		}
	}
	for (int i = 0; i != 4; i += 1)
		destroy_object(s->treem.select[i]);
}

void display_tree_menu2(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		if (i < 2) {
			display_object(s->window, s->treem.e[i]);
			display_object(s->window, s->treem.r[i]);
		} if (i < 3) {
			display_object(s->window, s->treem.m2[i]);
			display_object(s->window, s->treem.pas[i]);
		} if (s->player.tree.lock[i])
			display_object(s->window, s->treem.lock[i]);
	}
	if (!s->player.tree.lock[0] || !s->player.tree.lock[1]
		|| !s->player.tree.lock[2])
		display_object(s->window, s->treem.select[0]);
	if (!s->player.tree.lock[3] || !s->player.tree.lock[4]
		|| !s->player.tree.lock[5])
		display_object(s->window, s->treem.select[1]);
	if (!s->player.tree.lock[6] || !s->player.tree.lock[7])
		display_object(s->window, s->treem.select[2]);
	if (!s->player.tree.lock[8] || !s->player.tree.lock[9])
		display_object(s->window, s->treem.select[3]);
}

void display_tree_menu(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->treem.window->sprite, NULL);
	sfRenderWindow_drawText(s->window, s->treem.skillp->text, NULL);
	for (int i = 0; i != 3; i += 1) {
		if (s->treem.status != -1)
			sfRenderWindow_drawText(s->window,
			s->treem.sp[i]->text, NULL);
	}
	if (s->player.tree.lock[s->treem.status])
		sfRenderWindow_drawText(s->window,
		s->treem.sp[3]->text, NULL);
	display_button(s->window, s->treem.classe);
	display_tree_menu2(s);
}

char *get_spell_char(int i)
{
	switch (i) {
	case 0 :
		return ("p");
	case 1 :
		return ("m");
	case 2 :
		return ("e");
	case 3 :
		return ("r");
	}
	return ("NULL");
}

char *get_tree_path(st_rpg *s, int spell, int number)
{
	char *tmp;
	char *tmp2 = int_to_str(number);
	char *str = my_strcat("ressources/spells/",
	int_to_str(s->player.cdata.classe));

	tmp = my_strcat(str, "/");
	free(str);
	str = my_strcat(tmp, get_spell_char(spell));
	free(tmp);
	tmp = my_strcat(str, tmp2);
	free(str);
	free(tmp2);
	str = my_strcat(tmp, ".png");
	return (str);
}
