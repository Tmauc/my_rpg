/*
** EPITECH PROJECT, 2018
** zone_text.c
** File description:
** zone_text.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void take_good_option(st_rpg *s, int fd)
{
	char *str;
	char *un;

	while ((str = get_next_line(fd)) != NULL) {
		un = int_to_str(s->fi->var_choice);
		if (!my_strcmp(str, un)) {
			free(un);
			s->fi->choice_cursor = 0;
			free(str);
			break;
		}
		free(un);
		free(str);
	}
	s->fi->pre_var = s->fi->var_choice;
	s->fi->var_choice = s->fi->nb_choice_pre;
}

int update_dialog_box(st_rpg *s, int fd)
{
	char *str = get_next_line(fd);
	char *tra = int_to_str(s->fi->pre_var + 1);

	if (str == NULL || my_strcmp(str, tra) == 0) {
		free(str);
		free(tra);
		return (1);
	} else if (!my_strcmp(str, ">")) {
		s->fi->return_value = choice_box(s, fd);
		if (s->fi->return_value == 2)
			s->fi->num_dungeon = 0;
		free(str);
		take_good_option(s, fd);
		str = get_next_line(fd);
	}
	sfText_setString(s->fi->pnj[s->fi->nb_pnj].dialog_box->text->text, str);
	free(str);
	free(tra);
	return (0);
}

void open_or_no(st_rpg *s, int fd)
{
	if (update_dialog_box(s, fd) == 1)
		s->fi->dialog_box_isopen = 0;
	if (s->fi->return_value == 2)
		s->fi->dialog_box_isopen = 0;
}

void event_dialog_box(st_rpg *s, sfEvent event, int fd)
{
	if (event.type == sfEvtKeyPressed ||
	event.type == sfEvtMouseButtonPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyReturn) ||
		(sfMouse_isButtonPressed(sfMouseLeft) &&
		(mouse_in_object_dialogbox(s->fi
		->pnj[s->fi->nb_pnj].dialog_box->obj,
		s->window, s) == 1))) {
			open_or_no(s, fd);
		} if (sfKeyboard_isKeyPressed(sfKeyEscape))
			s->fi->return_value = 6;
	}
}

void dialog_box(st_rpg *s, char *deux, char *name)
{
	char *un = my_strdup("ressources/pnj/text/");
	char *path = my_strcat(un, deux);
	int fd = open(path, O_RDONLY);
	sfEvent event;

	free(un);
	check_pnj_for_quests(s);
	create_dialog_box(s);
	create_name_box(s, name);
	update_dialog_box(s, fd);
	while (s->fi->dialog_box_isopen == 1 && s->fi->return_value == 0) {
		while (sfRenderWindow_pollEvent(s->window, &event))
			event_dialog_box(s, event, fd);
		draw_dialog_box(s);
	}
	destroy_dialog_box(s);
	close(fd);
	free(path);
	if (s->fi->return_value == 2)
		death_fcnt(s);
}
