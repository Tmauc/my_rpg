/*
** EPITECH PROJECT, 2018
** events_fishing.c
** File description:
**
*/

#include "my.h"
#include "my_rpg.h"

void destroy_fishing_instance(st_rpg *rpg, fish_t *fish, sfClock *trem)
{
	sfClock_destroy(trem);
	sfSprite_destroy(fish->character);
	sfSprite_destroy(fish->rod);
	sfTexture_destroy(fish->rod_sheet);
	sfText_destroy(fish->time_rem);
	sfText_destroy(fish->cur_score);
	sfFont_destroy(fish->fishing_font);
	sfMusic_play(rpg->fi->music.music);
}

int launch_fishing_instance(st_rpg *rpg)
{
	int returnv;
	sfClock *time_remaining = sfClock_create();
	sfTime elapsed_time = sfClock_getElapsedTime(time_remaining);
	fish_t fish;

	create_fishing_instance(rpg, &fish);
	while (sfTime_asSeconds(elapsed_time) <= 60 && !fish.done) {
		update_fishing_instance(rpg, &fish,
		sfTime_asSeconds(elapsed_time));
		draw_fishing_instance(rpg, &fish);
		elapsed_time = sfClock_getElapsedTime(time_remaining);
	}
	returnv = fish.returnv;
	destroy_fishing_instance(rpg, &fish, time_remaining);
	return (returnv);
}
