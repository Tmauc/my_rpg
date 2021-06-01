/*
** EPITECH PROJECT, 2018
** init_dungeon.c
** File description:
** file to stock all functions about init struct dungeon
*/

#include "my.h"
#include "my_rpg.h"

void init_player_movement(st_rpg *rpg)
{
	rpg->player.acceleration.x = 0;
	rpg->player.acceleration.y = 0;
	rpg->player.max_speed = 200;
	rpg->player.nbr_frame.x = 0;
	rpg->player.nbr_frame.y = 0;
}

void init_player_camera(st_rpg *rpg)
{
	rpg->proc.gman.camera_pos = rpg->player.obj->pos;
	rpg->proc.gman.camera =
	sfView_copy(sfRenderWindow_getDefaultView(rpg->window));
	sfView_setCenter(rpg->proc.gman.camera, rpg->proc.gman.camera_pos);
	sfRenderWindow_setView(rpg->window, rpg->proc.gman.camera);
}

void init_dungeon_game(st_rpg *rpg)
{
	rpg->player.obj->pos = get_entry_pos(&rpg->proc);
	if (!rpg->boss)
		init_minimap(&rpg->proc);
	rpg->proc.gman.clock = sfClock_create();
	rpg->proc.gman.dt = 1.;
}
