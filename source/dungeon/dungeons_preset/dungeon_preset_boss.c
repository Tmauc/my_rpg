/*
** EPITECH PROJECT, 2018
** dungeon_preset_boss.c
** File description:
** file to stock all functions about dungeon preset for boss
*/

#include "my.h"
#include "my_rpg.h"

void dungeon_boss_champ(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl7_tiles.png";
	hey->map_width = 21;
	hey->map_height = 21;
	hey->max_room_s = 12;
	hey->min_room_s = 12;
	hey->nbr_rooms = 6;
	hey->current_floor = 0;
	hey->max_floor = 1;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 0;
	hey->max_enemies = 1;
	hey->dungeon_music = "ressources/audio/boss.ogg";
	hey->volume = 0;
}

void dungeon_boss_samy(proc_var_t *hey)
{
	hey->texture_path =
	"ressources/dungeons_tilesets/dungeon_lvl4_tiles.png";
	hey->map_width = 19;
	hey->map_height = 19;
	hey->max_room_s = 12;
	hey->min_room_s = 12;
	hey->nbr_rooms = 6;
	hey->current_floor = 0;
	hey->max_floor = 1;
	hey->background.r = 20;
	hey->background.g = 11;
	hey->background.b = 40;
	hey->background.a = 255;
	hey->min_enemies = 0;
	hey->max_enemies = 1;
	hey->dungeon_music = "ressources/audio/boss_samy.ogg";
	hey->volume = 0;
}
