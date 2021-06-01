/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "game_map.h"
#include "my_rpg.h"
#include "my.h"

void create_dungeon_loop_part2(st_rpg *s)
{
	create_items_list(s);
	create_main_fight(s);
	create_icons(s);
	create_class(s);
	create_dmg_show(s);
	create_life_bar(s);
	generate_enemies(s);
	create_main_particles(s);
	set_shader(s);
	sfClock_restart(s->proc.gman.clock);
	sfClock_restart(s->f.proc.clock);
}

void create_dungeon_loop(st_rpg *s)
{
	s->f.rog.vanish = 0;
	s->dungeon_music.music =
	create_music(s->proc.pvar.volume, s->proc.pvar.dungeon_music);
	sfMusic_play(s->dungeon_music.music);
	sfMusic_setLoop(s->dungeon_music.music, 1);
	if (s->boss == 0)
		sfMusic_setVolume(s->dungeon_music.music, s->s_music);
	create_player(s);
	create_weapon(s);
	if (!s->boss)
		map_creation(&s->proc);
	else
		map_boss_creation(s);
	s->proc.smap = create_sprite_map(&s->proc, s->proc.map);
	init_dungeon_game(s);
	create_use_item(s);
	create_dungeon_loop_part2(s);
}

void destroy_dungeon_loop(st_rpg *s)
{
	create_dmg_show(s);
	destroy_class(s);
	destroy_icons(s);
	destroy_life_bar(s);
	destroy_enemies(s);
	destroy_main_fight(s);
	destroy_dungeon_shader(s);
	destroy_main_particles(s);
	if (s->returnv != 0)
		free_dungeon(s, &s->proc);
	sfMusic_destroy(s->dungeon_music.music);
	sfMusic_play(s->fi->music.music);
	s->fi->map_status = 0;
}

void update_origin(st_rpg *s)
{
	origin_life_bar(s);
	origin_icons(s);
}

void update_dungeon_loop(st_rpg *s)
{
	update_dmg_show(s);
	update_pos_weapon(s);
	update_bars(s);
	update_icons_cd(s);
	update_fight(s);
	apply_projectiles(s);
	update_enemies(s);
	update_origin(s);
	update_sprite(s);
	if (!s->f.panim)
		player_animation(s);
	update_class(s);
	update_particles(s);
	update_item_ground(s);
}
