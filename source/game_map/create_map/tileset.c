/*
** EPITECH PROJECT, 2018
** tileset.c
** File description:
** tilset file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void create_layers(st_rpg *s)
{
	s->fi->map.tab_tileset = get_layer("ressources/map_preset/layers", s);
	s->fi->map.layer_background = s->fi->map.tab_tileset[0];
	s->fi->map.layer_relief = s->fi->map.tab_tileset[1];
	s->fi->map.layer_colID = s->fi->map.tab_tileset[2];
	s->fi->map.layer_col = s->fi->map.tab_tileset[3];
	s->fi->map.layer_prof = s->fi->map.tab_tileset[4];
}

void create_images(st_rpg *s)
{
	s->fi->map.x2 = 0;
	s->fi->map.image =
	sfImage_createFromFile("ressources/map_preset/map_tileset.png");
	s->fi->map.map_backgound = sfImage_create(1920, 3200);
	s->fi->map.map_relief = sfImage_create(1920, 3200);
	s->fi->map.map_col = sfImage_create(1920, 3200);
	s->fi->map.map_colID = sfImage_create(1920, 3200);
	s->fi->map.map_prof = sfImage_create(1920, 3200);
	s->fi->map.square.left = 0;
	s->fi->map.square.top = 0;
	s->fi->map.square.height = 640;
	s->fi->map.square.width = 640;
	create_layers(s);
}

void create_map(st_rpg *s)
{
	create_images(s);
	transfer_pixel(s);
	set_background(s);
	set_relief(s);
	set_col(s);
	set_colid(s);
	set_prof(s);
}
