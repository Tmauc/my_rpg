/*
** EPITECH PROJECT, 2018
** free_dungeon.c
** File description:
** free dungeon and everythings
*/

#include "my.h"
#include "my_rpg.h"

void free_sprite_map(smap_t *smap)
{
	if (smap->sprite != NULL)
		sfSprite_destroy(smap->sprite);
}

void free_map_tbl(proc_t *proc)
{
	free_tbl(proc->map);
	free(proc->proom);
	sfTexture_destroy(proc->blocks_texture);
}

void free_minimap(proc_t *proc)
{
	free(proc->minimap.f_background->pixels);
	free(proc->minimap.f_minimap->pixels);
	free(proc->minimap.f_background);
	free(proc->minimap.f_minimap);
	sfTexture_destroy(proc->minimap.fb_texture);
	sfTexture_destroy(proc->minimap.fm_texture);
	sfSprite_destroy(proc->minimap.fb_sprite);
	sfSprite_destroy(proc->minimap.fm_sprite);
}

void free_dungeon(st_rpg *rpg, proc_t *proc)
{
	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++)
			free_sprite_map(&proc->smap[y][x]);
		free(proc->smap[y]);
	}
	destroy_items_list(rpg);
	destroy_use_item(rpg);
	free(proc->smap);
	free_map_tbl(proc);
}
