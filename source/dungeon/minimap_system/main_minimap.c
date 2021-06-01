/*
** EPITECH PROJECT, 2018
** minimap_system.c
** File description:
** make minimap on screen
*/

#include "my.h"
#include "my_rpg.h"

void init_minimap_framebuffers(minimap_t *minimap)
{
	minimap->f_background =
	framebuffer_create(WIDTH / 1.5, HEIGHT / 1.5);
	minimap->fb_texture =
	sfTexture_create(WIDTH / 1.5, HEIGHT / 1.5);
	minimap->fb_sprite = sfSprite_create();
	sfSprite_setTexture(
	minimap->fb_sprite, minimap->fb_texture, sfTrue);
	fill_minimap_screen(minimap->f_background, sfBlack);
	minimap->f_minimap =
	framebuffer_create(WIDTH / 1.7, HEIGHT / 1.7);
	minimap->fm_texture =
	sfTexture_create(WIDTH / 1.7, HEIGHT / 1.7);
	minimap->fm_sprite = sfSprite_create();
	sfSprite_setTexture(
	minimap->fm_sprite, minimap->fm_texture, sfTrue);
	reset_screen(minimap->f_minimap);
}

void init_minimap(proc_t *proc)
{
	char *cur_level = int_to_str(proc->pvar.current_floor);
	char *level_string = my_strcat("Floor ", cur_level);
	sfColor trans_white = {255, 255, 255, 128};

	proc->minimap.current_level_font =
	sfFont_createFromFile("ressources/fonts/OpenSans.ttf");
	proc->minimap.current_level_text = sfText_create();
	sfText_setString(proc->minimap.current_level_text, level_string);
	sfText_setFont(proc->minimap.current_level_text,
	proc->minimap.current_level_font);
	sfText_setColor(proc->minimap.current_level_text, trans_white);
	sfText_setCharacterSize(proc->minimap.current_level_text, 26);
	init_minimap_framebuffers(&proc->minimap);
	free(cur_level);
	free(level_string);
}

void draw_minimap(st_rpg *rpg)
{
	sfVector2f player_pos_b = rpg->player.obj->pos;
	sfVector2f player_pos_m = rpg->player.obj->pos;

	player_pos_b.x -= WIDTH / 3;
	player_pos_b.y -= HEIGHT / 3;
	player_pos_m.x -= WIDTH / 3.4;
	player_pos_m.y -= HEIGHT / 3.4;
	sfTexture_updateFromPixels(rpg->proc.minimap.fb_texture,
	rpg->proc.minimap.f_background->pixels, WIDTH / 1.5,
	HEIGHT / 1.5, 0, 0);
	sfTexture_updateFromPixels(rpg->proc.minimap.fm_texture,
	rpg->proc.minimap.f_minimap->pixels, WIDTH / 1.7, HEIGHT / 1.7, 0, 0);
	sfSprite_setPosition(rpg->proc.minimap.fb_sprite, player_pos_b);
	sfSprite_setPosition(rpg->proc.minimap.fm_sprite, player_pos_m);
	sfRenderWindow_drawSprite(
	rpg->window, rpg->proc.minimap.fb_sprite, NULL);
	sfRenderWindow_drawSprite(
	rpg->window, rpg->proc.minimap.fm_sprite, NULL);
	sfRenderWindow_drawText(
	rpg->window, rpg->proc.minimap.current_level_text, NULL);
}

void verify_minimap(st_rpg *rpg)
{
	if (sfKeyboard_isKeyPressed(key_map) == sfTrue) {
		draw_minimap(rpg);
	}
}
