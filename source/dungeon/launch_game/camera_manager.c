/*
** EPITECH PROJECT, 2018
** camera_manager.c
** File description:
** camera main file to move camera
*/

#include "my.h"
#include "my_rpg.h"

void update_camera_position(st_rpg *rpg)
{
	rpg->proc.gman.camera_pos.x = rpg->player.obj->pos.x;
	rpg->proc.gman.camera_pos.y = rpg->player.obj->pos.y;
	sfView_setCenter(rpg->proc.gman.camera, rpg->proc.gman.camera_pos);
	sfRenderWindow_setView(rpg->window, rpg->proc.gman.camera);
}
