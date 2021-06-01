/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "game_map.h"

void verify_collide_village(st_rpg *rpg)
{
	rpg->player.obj->pos.y +=
	rpg->player.acceleration.y * rpg->proc.gman.dt;
	rpg->player.obj->pos.x +=
	rpg->player.acceleration.x * rpg->proc.gman.dt;
	move_id_player(rpg);
	if (collision(rpg) == 1) {
		rpg->player.obj->pos.y -=
		rpg->player.acceleration.y * rpg->proc.gman.dt;
		rpg->player.obj->pos.x -=
		rpg->player.acceleration.x * rpg->proc.gman.dt;
		sfSprite_setPosition(rpg->player.obj->sprite,
		rpg->player.obj->pos);
		stop_player(rpg);
	}
	move_camera(rpg);
}

void update_player_position_village(st_rpg *rpg)
{
	rpg->player.acceleration.y =
	rpg->player.max_speed * (rpg->player.nbr_frame.y / 10.);
	rpg->player.acceleration.x =
	rpg->player.max_speed * (rpg->player.nbr_frame.x / 10.);
	verify_collide_village(rpg);
}
