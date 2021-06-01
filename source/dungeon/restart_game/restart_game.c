/*
** EPITECH PROJECT, 2018
** restart_game.c
** File description:
** file to stock all functions about restarting a game
*/

#include "my.h"
#include "my_rpg.h"

void create_char_map_restart(proc_t *proc)
{
	increment_proc_struct(&proc->pvar, proc);
	make_positions_proom(proc);
	for (int i = 0; proc->proom[i].last == 0; i++)
		make_holes(&proc->proom[i], proc->map);
	proc->map = border_map(&proc->pvar, proc->map);
	create_entry(proc);
	create_leave(proc);
	make_map_better(proc->map);
}

void init_next_level(st_rpg *rpg)
{
	char *cur_level = int_to_str(rpg->proc.pvar.current_floor);
	char *level_string = my_strcat("Floor ", cur_level);

	create_char_map_restart(&rpg->proc);
	rpg->proc.smap = create_sprite_map(&rpg->proc, rpg->proc.map);
	create_items_list(rpg);
	rpg->player.obj->pos = get_entry_pos(&rpg->proc);
	rpg->player.acceleration.x = 0;
	rpg->player.acceleration.y = 0;
	rpg->player.nbr_frame.x = 0;
	rpg->player.nbr_frame.y = 0;
	rpg->proc.gman.dt = 1;
	reset_screen(rpg->proc.minimap.f_minimap);
	sfText_setString(rpg->proc.minimap.current_level_text, level_string);
	create_use_item(rpg);
	free(cur_level);
	free(level_string);
}

void draw_floor_restart(st_rpg *rpg)
{
	sfVector2f screen_center = rpg->proc.gman.camera_pos;
	char *cur_level = int_to_str(rpg->proc.pvar.current_floor);
	char *level_string = my_strcat("Floor ", cur_level);
	sfFont *font = sfFont_createFromFile("ressources/fonts/OpenSans.ttf");
	sfText *next_level = sfText_create();

	screen_center.y -= 25;
	screen_center.x -= (my_strlen(level_string) * 25) / 2;
	sfText_setString(next_level, level_string);
	sfText_setFont(next_level, font);
	sfText_setCharacterSize(next_level, 50);
	sfText_setPosition(next_level, screen_center);
	fade_in_text(rpg->window, next_level);
	init_next_level(rpg);
	fade_out_text(rpg->window, next_level);
	sfText_destroy(next_level);
	sfFont_destroy(font);
	free(cur_level);
	free(level_string);
}

int next_level_screen(st_rpg *rpg)
{
	if (rpg->proc.pvar.current_floor < rpg->proc.pvar.max_floor &&
	rpg->proc.pvar.max_floor > 0) {
		rpg->proc.pvar.current_floor += 1;
	} else if (rpg->proc.pvar.current_floor > rpg->proc.pvar.max_floor &&
	rpg->proc.pvar.max_floor < 0) {
		rpg->proc.pvar.current_floor -= 1;
	} else {
		rpg->boss = 0;
		return (1);
	}
	free_dungeon(rpg, &rpg->proc);
	destroy_enemies(rpg);
	draw_floor_restart(rpg);
	generate_enemies(rpg);
	sfClock_restart(rpg->proc.gman.clock);
	sfClock_restart(rpg->f.proc.clock);
	return (0);
}
