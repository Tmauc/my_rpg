/*
** EPITECH PROJECT, 2018
** input_manager.c
** File description:
** main input file
*/

#include "my.h"
#include "my_rpg.h"

void verify_other_input(sfEvent event, st_rpg *rpg)
{
	if (event.type == sfEvtKeyPressed && event.key.code == key_inv &&
	rpg->inv.is_open == 0) {
		rpg->inv.is_open = 1;
	} else if (event.type == sfEvtKeyPressed && event.key.code == key_inv &&
	rpg->inv.is_open == 1) {
		rpg->inv.is_open = 0;
		rpg->inv.focused = NULL;
	} if (event.type == sfEvtMouseButtonPressed &&
	event.mouseButton.button == key_use_item) {
		rpg->inv.use_item = 1;
	}

}

int verif_input_map(st_rpg *rpg)
{
	verify_y_movement(rpg);
	verify_x_movement(rpg);
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			sfRenderWindow_close(rpg->window);
		verify_other_input(rpg->event, rpg);
	}
	return (0);
}

int verify_exit_player(st_rpg *rpg)
{
	int px = rpg->player.obj->pos.x / 96;
	int py = rpg->player.obj->pos.y / 96;
	int ex = get_exit_pos(&rpg->proc).x / 96;
	int ey = get_exit_pos(&rpg->proc).y / 96;

	if (!rpg->boss && px == ex && py == ey)
		return (next_level_screen(rpg));
	return (0);
}
