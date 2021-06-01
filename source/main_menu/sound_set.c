/*
** EPITECH PROJECT, 2018
** sound_set.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

void get_sound_option(st_rpg *s)
{
	int fd = open("saves/sound", O_RDONLY);
	char *buffer = get_next_line(fd);

	s->s_music = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	s->s_effect = str_to_int(buffer);
	free(buffer);
	close(fd);
	s->mainm.music = sfMusic_createFromFile("ressources/audio/menu.ogg");
	s->mainm.s_effect =
	sfMusic_createFromFile("ressources/audio/sound/stomp.ogg");
	sfMusic_setVolume(s->mainm.music, s->s_music);
	sfMusic_setVolume(s->mainm.s_effect, s->s_effect);
	sfMusic_play(s->mainm.music);
}

void set_new_sound(st_rpg *s)
{
	int fd = open("saves/sound", O_WRONLY | O_TRUNC | O_CREAT);
	char *buffer = int_to_str(s->s_music);

	write_a_value(fd, buffer, my_strlen(buffer));
	free(buffer);
	buffer = int_to_str(s->s_effect);
	write_a_value(fd, buffer, my_strlen(buffer));
	free(buffer);
	close(fd);
}

void choose_set_sound(st_rpg *s, sfEvent event)
{
	if (s->mainm.option == 0) {
		modify_effect(s, event);
	}
	if (s->mainm.option == 1) {
		modify_music(s, event);
	}
}
