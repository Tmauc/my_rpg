/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

char *get_class_string(int i)
{
	switch (i) {
	case 0 :
		return ("Archer");
	case 1 :
		return ("Gunner");
	case 2 :
		return ("Rogue");
	case 3 :
		return ("Warrior");
	}
	return (NULL);
}

void destroy_status_menu(st_rpg *s)
{
	destroy_object(s->statm.window);
	destroy_object(s->statm.face);
	destroy_button(s->statm.classe);
	destroy_text(s->statm.name);
	destroy_text(s->statm.lvl);
	destroy_text(s->statm.exp);
	for (int i = 0; i != 6; i += 1) {
		destroy_button(s->statm.stats[i]);
	}
}

void display_status_menu(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->statm.window->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->statm.face->sprite, NULL);
	sfRenderWindow_drawText(s->window, s->statm.name->text, NULL);
	sfRenderWindow_drawText(s->window, s->statm.lvl->text, NULL);
	sfRenderWindow_drawText(s->window, s->statm.exp->text, NULL);
	display_button(s->window, s->statm.classe);
	for (int i = 0; i != 6; i += 1)
		display_button(s->window, s->statm.stats[i]);
}

void generate_status_info(st_rpg *s, int x, int y)
{
	s->statm.classe = create_button(get_class_string(s->
	player.cdata.classe),
	create_object("ressources/images/interface/pictoclass.png",
	create_vector2f(x + 1620, y + 100), create_rect(0, 32 *
	s->player.cdata.classe, 32, 32), 0), sfWhite, 30);
	for (int i = 0; i != 6; i += 1) {
		s->statm.stats[i] = create_button(get_stat_value(s, i),
		create_object("ressources/images/interface/pictostat.png",
		create_vector2f(x + 1540, y + 300 + i * 50),
		create_rect(0, i * 32, 32, 32), 0), sfWhite, 30);
		sfText_setPosition(s->statm.stats[i]->text->text,
		create_vector2f(x + 1590, y + 300 + i * 50));
		sfFont_destroy(s->statm.stats[i]->text->font);
		s->statm.stats[i]->text->font =
		sfFont_createFromFile("ressources/fonts/bars.otf");
		sfText_setFont(s->statm.stats[i]->text->text,
		s->statm.stats[i]->text->font);
	}
	sfText_setPosition(s->statm.classe->text->text,
	create_vector2f(x + 1660, y + 100));
}

void generate_status_menu(st_rpg *s)
{
	char *temp;
	int x = s->origin.x;
	int y = s->origin.y;

	s->statm.window = create_object(
	"ressources/images/interface/pause_window.png",
	create_vector2f(x + 1490, y + 30), create_rect(0, 0, 400, 600), 0);
	s->statm.face = create_object("ressources/images/heroface.png",
	create_vector2f(x + 1500, y + 40),
	create_rect(0, s->player.cdata.sex * 100, 100, 100), 0);
	s->statm.name = create_text(s->player.cdata.name, create_vector2f(x +
	1620,
	y + 50), "ressources/fonts/button.ttf");
	temp = int_to_str(s->player.stat->lvl);
	s->statm.lvl = create_text(my_strcat("Level ", temp),
	create_vector2f(x + 1525, y + 150), "ressources/fonts/button.ttf");
	temp = int_to_str(s->player.stat->exp);
	s->statm.exp = create_text(my_strcat(temp, " / 100 XP"),
	create_vector2f(x + 1525, y + 200), "ressources/fonts/button.ttf");
	generate_status_info(s, x, y);
}
