/*
** EPITECH PROJECT, 2018
** create_music.c
** File description:
** create_music.c
*/

#include "my.h"
#include "game_map.h"

sfMusic *create_music(float volume, char *path)
{
	sfMusic *music;

	music = sfMusic_createFromFile(path);
	sfMusic_setVolume(music, volume);
	sfMusic_setLoop(music, 1);
	return (music);
}
