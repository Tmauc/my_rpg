/*
** EPITECH PROJECT, 2018
** update_fishing.c
** File description:
**
*/

#include "my.h"
#include "my_rpg.h"

void catch_fish(void)
{
	my_putstr("catched !\n");
}

void events_fishing_instance(st_rpg *rpg, fish_t *fish)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(rpg->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(rpg->window);
			fish->returnv = 1;
			fish->done = 1;
		} if (event.type == sfEvtKeyPressed &&
		event.key.code == key_fishing && fish->in_catch) {
			catch_fish();
			fish->in_catch = 0;
			fish->catch_clock = NULL;
			sfClock_destroy(fish->catch_clock);
		} if (event.type == sfEvtKeyPressed &&
			event.key.code == key_fishing && !fish->in_catch)
			fish->score -= 1;
	}
}

void verify_catch_fish(fish_t *fish)
{
	sfTime catch_time;

	if (fish->in_catch == 0 && rand() % 300 == 0) {
		fish->in_catch = 1;
		fish->catch_clock = sfClock_create();
	} if (fish->in_catch == 1) {
		catch_time = sfClock_getElapsedTime(fish->catch_clock);
	} if (fish->in_catch && fish->catch_clock != NULL &&
	sfTime_asSeconds(catch_time) > 2) {
		fish->in_catch = 0;
		fish->catch_clock = NULL;
		sfClock_destroy(fish->catch_clock);
	}
}

void update_fishing_instance(st_rpg *rpg, fish_t *fish, float elapsed)
{
	char *elapsed_txt = int_to_str(60 - (int)elapsed);
	char *score = int_to_str(fish->score);

	events_fishing_instance(rpg, fish);
	if (60 - elapsed < 5)
		sfText_setColor(fish->time_rem, sfRed);
	else
		sfText_setColor(fish->time_rem, sfWhite);
	if (fish->score < 0)
		sfText_setColor(fish->cur_score, sfRed);
	else
		sfText_setColor(fish->time_rem, sfWhite);
	sfText_setString(fish->time_rem, elapsed_txt);
	sfText_setString(fish->cur_score, score);
	verify_catch_fish(fish);
	free(elapsed_txt);
	free(score);
}
