/*
** EPITECH PROJECT, 2018
** procedural_struct.h
** File description:
**
*/

#ifndef PROC_STRUCT_H_
#define PROC_STRUCT_H_

#include "my_rpg.h"

//MINIMAP

typedef struct minimap {
	framebuffer_t *f_background;
	framebuffer_t *f_minimap;
	sfTexture *fb_texture;
	sfTexture *fm_texture;
	sfSprite *fb_sprite;
	sfSprite *fm_sprite;
	sfFont *current_level_font;
	sfText *current_level_text;
} minimap_t;

//GROUND ITEM
typedef struct ground_item
{
	sfSprite *sprite;
	sfVector2f pos;
	unsigned int id;
	struct ground_item *next;
} gitem_t;

//MAP SYSTEM
typedef struct proc_room
{
	int pos1[2];
	int pos2[2];
	int width;
	int height;
	int center[2];
	int visited;
	int drawed;
	int last;
} proom_t;

typedef struct map_sprite
{
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
} smap_t;

typedef struct game_manager
{
	sfView *camera;
	sfVector2f camera_pos;
	sfClock *clock;
	sfTime time;
	float dt;
} gmanager_t;

typedef struct proc_var
{
	char *dungeon_music;
	float volume;
	char *texture_path;
	int map_width;
	int map_height;
	int max_room_s;
	int min_room_s;
	int nbr_rooms;
	int min_enemies;
	int max_enemies;
	int enemy_nbr;
	int current_floor;
	int max_floor;
	sfColor background;
} proc_var_t;

typedef struct proc_gen
{
	proc_var_t pvar;
	gmanager_t gman;
	proom_t *proom;
	smap_t **smap;
	minimap_t minimap;
	gitem_t *first_gritem;
	char **map;
	sfTexture *blocks_texture;
	unsigned int current_floor;
} proc_t;

typedef struct fishing
{
	int score;
	int in_catch;
	int returnv;
	int done;
	sfClock *catch_clock;
	sfSprite *character;
	sfSprite *rod;
	sfIntRect rod_rect;
	sfTexture *rod_sheet;
	sfText *time_rem;
	sfText *cur_score;
	sfFont *fishing_font;
} fish_t;

#endif
