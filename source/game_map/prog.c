/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void create(st_rpg *s)
{
	s->player.obj->pos = create_vector2f(7934, 4497);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	character_setup(s);
	get_all_pnj(s, "ressources/pnj/pnj/");
	setup_pnj_value(s);
	setup_variable(s);
	setup_music(s);
	setup_loading(s);
	get_all_quests(s, "ressources/quests/quests_info/");
	create_ingame_inventory(s);
	s->fi->text_finish_quests = create_text("quests_finish",
	create_vector2f(100, 100), "ressources/fonts/quests2.otf");
	sfText_setColor(s->fi->text_finish_quests->text, sfWhite);
	sfText_setCharacterSize(s->fi->text_finish_quests->text, 100);
	s->fi->quests[s->player.cdata.quest]->status = 1;
	s->fi->quests[0]->status_text = 1;
	s->fi->camera = create_vector2f(7839, 4497);
	s->fi->camera_prec = s->fi->camera;
	s->fi->camera_pos = 2;
}

int start_game(st_rpg *s)
{
	struct stat a;

	if (stat("ressources/map_preset/parsing", &a) == -1)
		return (0);
	create(s);
	parsing(a, s);
	create_map(s);
	sfMusic_play(s->fi->music.music);
	sfClock_restart(s->proc.gman.clock);
	return (1);
}

int prog(st_rpg *s)
{
	if (start_game(s) == 0)
		return (0);
	while (sfRenderWindow_isOpen(s->window)) {
		if (s->fi->return_value == 3 || s->returnv == 3) {
			s->fi->camera.x = 960;
			s->fi->camera.y = 540;
			sfView_setCenter(s->fi->view, s->fi->camera);
			sfRenderWindow_setView(s->window, s->fi->view);
			loading(s);
			destroy(s);
			return (main_menu(s));
		}
		game_update(s);
		if (event_game(s) == 1 || s->fi->return_value == 1) {
			destroy(s);
			return (1);
		}
	}
	return (0);
}
