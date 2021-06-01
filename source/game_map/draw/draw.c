/*
** EPITECH PROJECT, 2018
** draw.c
** File description:
** draw file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void draw_loading(st_rpg *s)
{
	s->fi->time.tmp = sfClock_getElapsedTime(s->fi->time.clock);
	s->fi->time.seconds = s->fi->time.tmp.microseconds / 20000.0;
	if (s->fi->time.seconds > 0.8) {
		if (s->fi->loading->rect.left == 3762)
			s->fi->loading->rect.left = 0;
		else
			s->fi->loading->rect.left += 99;
		sfSprite_setTextureRect(s->fi->loading->sprite,
		s->fi->loading->rect);
		sfRenderWindow_clear(s->window, sfBlack);
		sfRenderWindow_drawSprite(s->window, s->fi->loading->sprite,
		NULL);
		sfRenderWindow_display(s->window);
		sfClock_restart(s->fi->time.clock);
	}
}

void draw_pnj(st_rpg *s)
{
	int i = 0;
	int nbpnj = 18;

	while (i != nbpnj) {
		if (s->fi->oui == 1 && i == s->fi->pnj_shade) {
			sfRenderWindow_drawSprite(s->window,
			s->fi->pnj[i].pnj->sprite, &s->fi->shade_white.state);
		}
		sfRenderWindow_drawSprite(s->window,
		s->fi->pnj[i].pnj->sprite, NULL);
		i++;
	}
}

void draw_quests(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window,
	s->fi->quests_box.quests_box->obj->sprite, NULL);
	sfRenderWindow_drawText(s->window,
	s->fi->quests_box.quests_box->text->text, NULL);
	if (s->fi->quests_box.status == 1) {
		sfRenderWindow_drawSprite(s->window,
		s->fi->quests_box.quests_des->obj->sprite, NULL);
		sfRenderWindow_drawText(s->window,
		s->fi->quests_box.quests_des->text->text, NULL);
	}
}

void draw_all(st_rpg *s)
{
	sfSprite_setTextureRect(s->player.obj->sprite,
	s->player.obj->rect);
	sfSprite_setPosition(s->player.obj->sprite, s->player.obj->pos);
	sfRenderWindow_clear(s->window, sfBlack);
	sfRenderWindow_drawSprite(s->window, s->fi->lake->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->fi->map.sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->fi->map.sprite5, NULL);
	sfRenderWindow_drawSprite(s->window, s->fi->map.sprite3, NULL);
	sfRenderWindow_drawSprite(s->window, s->fi->map.sprite2, NULL);
	draw_pnj(s);
	sfRenderWindow_drawSprite(s->window, s->player.obj->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->fi->map.sprite4, NULL);
	draw_quests(s);
	draw_cut_scene(s);
	print_text_finish_quests(s);
}

void draw(st_rpg *s)
{
	draw_all(s);
	sfRenderWindow_display(s->window);
}
