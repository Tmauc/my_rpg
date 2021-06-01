/*
** EPITECH PROJECT, 2018
** setup_scene.c
** File description:
** setup_scene file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void update_death(st_rpg *s)
{
	if (s->fi->quests[8]->status > 0) {
		s->fi->pnj[s->cut.samy_value].pnj->pos =
		create_vector2f(10000, 10000);
		sfSprite_setPosition(s->fi->pnj[s->cut.samy_value].pnj->sprite,
		s->fi->pnj[s->cut.samy_value].pnj->pos);
	} if (s->fi->quests[6]->status > 0) {
		s->fi->pnj[s->cut.zac_value].pnj->pos =
		create_vector2f(10000, 10000);
		sfSprite_setPosition(s->fi->pnj[s->cut.zac_value].pnj->sprite,
		s->fi->pnj[s->cut.zac_value].pnj->pos);
	}
}

void setup_obj_for_scene_part2(st_rpg *s)
{
	s->cut.ly_death =
	create_object("ressources/images/scenes/ly_death.png",
	create_vector2f(0, 0), create_rect(0, 0, 41, 28), 0);
	s->cut.champ_death =
	create_object("ressources/images/scenes/champ_death.png",
	create_vector2f(0, 0), create_rect(0, 0, 41, 33), 0);
	s->cut.begin =
	create_object("ressources/images/scenes/begin.png",
	create_vector2f(0, 0), create_rect(0, 0, 1920, 1080), 0);
}

void setup_obj_for_scene(st_rpg *s)
{
	s->cut.zachd =
	create_object("ressources/images/scenes/zach_is_dead.png",
	create_vector2f(0, 0), create_rect(0, 0, 61, 39), 0);
	s->cut.samyd =
	create_object("ressources/images/scenes/samy_is_dead.png",
	create_vector2f(0, 0), create_rect(0, 0, 70, 50), 0);
	s->cut.samy_boss =
	create_object("ressources/images/scenes/samy_boss.png",
	create_vector2f(0, 0), create_rect(0, 0, 29, 48), 0);
	s->cut.champ =
	create_object("ressources/images/scenes/champ.png",
	create_vector2f(0, 0), create_rect(0, 0, 60, 46), 0);
	s->cut.champ_boss =
	create_object("ressources/images/scenes/champ_boss.png",
	create_vector2f(0, 0), create_rect(0, 0, 90, 48), 0);
	s->cut.ly_boss =
	create_object("ressources/images/scenes/ly_boss.png",
	create_vector2f(0, 0), create_rect(0, 0, 95, 47), 0);
	setup_obj_for_scene_part2(s);
}

void setup_obj_for_scene_map(st_rpg *s)
{
	s->cut.map =
	create_object("ressources/images/scenes/map_death_of_zach.png",
	create_vector2f(0, 0), create_rect(0, 0, 528, 528), 0);
	s->cut.map_samy =
	create_object("ressources/images/scenes/map_death_of_samy.png",
	create_vector2f(0, 0), create_rect(0, 0, 816, 528), 0);
	s->cut.map_samy_boss =
	create_object("ressources/images/scenes/map_samy_boss.png",
	create_vector2f(0, 0), create_rect(0, 0, 816, 816), 0);
	s->cut.map_son =
	create_object("ressources/images/scenes/map_son.png",
	create_vector2f(0, 0), create_rect(0, 0, 528, 528), 0);
	s->cut.map_boss =
	create_object("ressources/images/scenes/map_boss.png",
	create_vector2f(0, 0), create_rect(0, 0, 912, 913), 0);
}

void setup_variable_scene_quests(st_rpg *s)
{
	s->fi->oui = 0;
	s->fi->num_dungeon = 0;
	s->fi->map_status = 0;
	s->fi->zach_status = 0;
	s->fi->dream_status = 0;
	setup_obj_for_scene_map(s);
	setup_obj_for_scene(s);
}
