/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "game_map.h"
#include "my_rpg.h"
#include "my.h"

void set_for_quit(st_rpg *s)
{
	s->returnv = 0;
	destroy_dungeon_loop(s);
	s->fi->camera_pos = 1;
	s->player.obj->pos.x = 3707;
	s->player.obj->pos.y = 3550;
	s->fi->dialog_box_isopen = 0;
	s->fi->var_choice = 0;
	s->fi->nb_choice_pre = 0;
	sfClock_restart(s->proc.gman.clock);
}

void stop_player(st_rpg *s)
{
	s->player.acceleration.x = 0;
	s->player.acceleration.y = 0;
	s->player.nbr_frame.x = 0;
	s->player.nbr_frame.y = 0;
}

void display_dungeon(st_rpg *s)
{
	sfRenderWindow_clear(s->window, s->proc.pvar.background);
	for (int y = 0; s->proc.map[y] != NULL; y++)
		draw_map_block(s, y);
	draw_item_on_ground(s);
	display_player(s);
	display_enemies(s);
	display_class(s);
	display_icons(s);
	display_life_bar(s);
	display_dmg_show(s);
	display_main_particles(s);
	if (!s->boss)
		verify_minimap(s);
	verify_inventory(s);
	verify_fast_inventory(s);
}

int dungeon_events(st_rpg *s)
{
	sfEvent event;

	if (s->f.cast != 2) {
		verify_x_movement(s);
		verify_y_movement(s);
	}
	while (sfRenderWindow_pollEvent(s->window, &event)) {
		if (event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyEscape)) {
			stop_player(s);
			return (pause_main(s));
		} if (event.type == sfEvtClosed) {
			s->returnv = 1;
			destroy_dungeon_loop(s);
			return (1);
		}
		verify_other_input(event, s);
	}
	return (0);
}

int dungeon_loop(st_rpg *s)
{
	while (sfRenderWindow_isOpen(s->window)) {
		if (dungeon_events(s))
			break;
		if (!s->f.cast && !s->inv.is_open)
			launch_spells(s);
		if (player_is_dead(s))
			return	(die(s));
		update_dungeon_loop(s);
		display_dungeon(s);
		sfRenderWindow_display(s->window);
		if (verify_exit_player(s) || boss_is_dead(s)) {
			set_for_quit(s);
			return (4);
		}
	}
	return (s->returnv);
}
