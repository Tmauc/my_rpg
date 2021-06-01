/*
** EPITECH PROJECT, 2018
** launch_dungeon.c
** File description:
** launch the dungeon game
*/

#include "my.h"
#include "my_rpg.h"

void draw_map_block(st_rpg *rpg, int y)
{
	for (int x = 0; rpg->proc.map[y][x] != '\0'; x++) {
		if (rpg->proc.smap[y][x].sprite != NULL) {
			sfRenderWindow_drawSprite(rpg->window,
			rpg->proc.smap[y][x].sprite, NULL);
		}
	}
}

int update_sprite(st_rpg *rpg)
{
	sfVector2f player_pos;

	rpg->player.last_pos = rpg->player.obj->pos;
	update_player_position(rpg);
	rpg->origin.x = rpg->player.obj->pos.x - WIDTH / 2;
	rpg->origin.y = rpg->player.obj->pos.y - HEIGHT / 2;
	player_pos.x = rpg->player.obj->pos.x -
	(rpg->player.obj->rect.width);
	player_pos.y = rpg->player.obj->pos.y -
	(rpg->player.obj->rect.height);
	sfSprite_setPosition(rpg->player.obj->sprite, player_pos);
	update_camera_position(rpg);
	if (!rpg->boss)
		update_minimap(rpg);
	rpg->proc.gman.time = sfClock_restart(rpg->proc.gman.clock);
	rpg->proc.gman.dt = sfTime_asSeconds(rpg->proc.gman.time);
	return (1);
}

int launch_dungeon_game(st_rpg *rpg)
{
	int done = 0;

	init_dungeon_game(rpg);
	while (!done) {
		verif_input_map(rpg);
		update_sprite(rpg);
		sfRenderWindow_clear(rpg->window, rpg->proc.pvar.background);
		sfRenderWindow_display(rpg->window);
		done = verify_exit_player(rpg);
	}
	return (1);
}
