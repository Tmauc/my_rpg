/*
** EPITECH PROJECT, 2018
** create_fishing.c
** File description:
** file to stock all functions about creating and destorying fishing
*/

#include "my.h"
#include "my_rpg.h"

void create_fishing_text(st_rpg *rpg, fish_t *fish)
{
	fish->cur_score = sfText_create();
	fish->time_rem = sfText_create();
	fish->fishing_font =
	sfFont_createFromFile("ressources/fonts/bars.otf");
	sfText_setFont(fish->cur_score, fish->fishing_font);
	sfText_setFont(fish->time_rem, fish->fishing_font);
	sfText_setCharacterSize(fish->cur_score, 40);
	sfText_setCharacterSize(fish->time_rem, 40);
	sfText_setPosition(fish->cur_score, (sfVector2f){2600, 75});
	sfText_setPosition(fish->time_rem, (sfVector2f){4225, 75});
	sfMusic_stop(rpg->fi->music.music);
}

void create_fishing_instance(st_rpg *rpg, fish_t *fish)
{
	fish->catch_clock = NULL;
	fish->done = 0;
	fish->score = 0;
	fish->returnv = 0;
	fish->in_catch = 0;
	fish->character = sfSprite_create();
	fish->rod = sfSprite_create();
	fish->rod_rect = (sfIntRect){0, 0, 150, 150};
	fish->rod_sheet =
	sfTexture_createFromFile("ressources/images/fishing/rods.png", NULL);
	sfSprite_setTexture(fish->character, rpg->player.obj->texture, sfTrue);
	sfSprite_setTextureRect(fish->character, (sfIntRect){0, 48, 48, 48});
	sfSprite_setPosition(fish->character, (sfVector2f){3431, 514});
	sfSprite_setScale(fish->character, (sfVector2f){2, 2});
	sfSprite_setTexture(fish->rod, fish->rod_sheet, sfTrue);
	sfSprite_setTextureRect(fish->rod, fish->rod_rect);
	sfSprite_setPosition(fish->rod, (sfVector2f){3431, 514});
	create_fishing_text(rpg, fish);
}
