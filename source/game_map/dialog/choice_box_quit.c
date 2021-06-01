/*
** EPITECH PROJECT, 2018
** choice_box_quit.c
** File description:
** choice_box_quit.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int choice_dungeon_part2(st_rpg *s, char **tab, char *str, int compter)
{
	if (my_strcmp(tab[s->fi->choice_cursor], "Chaotic Maze") == 0 &&
	s->fi->quests[6]->status != 0) {
		s->fi->num_dungeon = 3;
		choice_box_quit(s, tab, str, compter);
		quit_game_for_dungeon(s);
		return (launch_dungeon(s, &dungeon3));
	} if (my_strcmp(tab[s->fi->choice_cursor], "Vegetable Cave") == 0 &&
	s->fi->quests[7]->status != 0) {
		s->fi->num_dungeon = 4;
		quit_game_for_dungeon(s);
		return (launch_dungeon(s, &dungeon4_1));
	} if (!my_strcmp(tab[s->fi->choice_cursor], "Of course ! (25$)") &&
	s->inv.money >= 25) {
		choice_box_quit(s, tab, str, compter);
		s->inv.money -= 25;
		return (launch_fishing_instance(s));
	}
	return (0);
}

int choice_dungeon(st_rpg *s, char **tab, char *str, int compter)
{
	if (my_strcmp(tab[s->fi->choice_cursor], "Rocky Cavern") == 0 &&
	s->fi->quests[1]->status != 0) {
		s->fi->num_dungeon = 1;
		choice_box_quit(s, tab, str, compter);
		quit_game_for_dungeon(s);
		return (launch_dungeon(s, &dungeon1));
	} if (my_strcmp(tab[s->fi->choice_cursor], "White Cavern") == 0 &&
	s->fi->quests[4]->status != 0) {
		s->fi->num_dungeon = 2;
		choice_box_quit(s, tab, str, compter);
		quit_game_for_dungeon(s);
		return (launch_dungeon(s, &dungeon2));
	} if (my_strcmp(tab[s->fi->choice_cursor], "Volcanic Point") == 0 &&
	s->fi->quests[8]->status != 0) {
		s->fi->num_dungeon = 5;
		choice_box_quit(s, tab, str, compter);
		quit_game_for_dungeon(s);
		return (launch_dungeon(s, &dungeon5));
	}
	return (choice_dungeon_part2(s, tab, str, compter));
}

void quit_game_for_dungeon(st_rpg *s)
{
	sfView_setCenter(s->fi->view, create_vector2f(960, 540));
	sfRenderWindow_setView(s->window, s->fi->view);
	sfMusic_stop(s->fi->music.music);
}

void choice_box_quit(st_rpg *s, char **tab, char *str, int compter)
{
	s->fi->nb_choice_pre = compter;
	s->fi->choice_cursor = 0;
	free_tab_withnull(tab);
	free(str);
}

int choice_box_check_quit(st_rpg *s, char **tab, char *str, int compter)
{
	int return_value = 0;

	if ((return_value = choice_dungeon(s, tab, str, compter)) != 0) {
		set_all_var_at_zero(s);
		return (return_value);
	}
	choice_box_quit(s, tab, str, compter);
	return (0);
}
