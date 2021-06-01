/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void display_life_bar(st_rpg *s)
{
	sfRenderWindow_drawSprite(s->window, s->bar.bars->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->bar.life->sprite, NULL);
	sfRenderWindow_drawSprite(s->window, s->bar.xp->sprite, NULL);
	for (int i = 0; i != 3; i += 1)
		sfRenderWindow_drawText(s->window, s->bar.values[i]->text,
		NULL);
}

void update_bars(st_rpg *s)
{
	if (s->player.stat->exp >= 100)
		set_level_up(s);
	s->bar.life->rect.width = 316 * s->player.stat->pva /
	s->player.stat->pvm;
	s->bar.xp->rect.width = 316 * s->player.stat->exp / 100;
	sfSprite_setTextureRect(s->bar.life->sprite, s->bar.life->rect);
	sfSprite_setTextureRect(s->bar.xp->sprite, s->bar.xp->rect);
	sfText_setString(s->bar.values[0]->text,
	int_to_str(s->player.stat->lvl));
	sfText_setString(s->bar.values[1]->text,
	int_to_str(s->player.stat->pva));
	sfText_setString(s->bar.values[2]->text,
	int_to_str(s->player.stat->exp));
}

void create_life_bar(st_rpg *s)
{
	int x = s->origin.x;
	int y = s->origin.y;

	s->bar.bars = create_object("ressources/images/interface/bars.png",
	create_vector2f(x + 40, y + 40),
	create_rect(0, 0, 408, 82), 0);
	s->bar.life = create_object("ressources/images/interface/life.png",
	create_vector2f(x + s->bar.bars->pos.x + 82, y + s->bar.bars->pos.y
	+ 18), create_rect(0, 0, 316, 18), 0);
	s->bar.xp = create_object("ressources/images/interface/xp.png",
	create_vector2f(x + s->bar.life->pos.x, y + s->bar.bars->pos.y + 47),
	create_rect(0, 0, 316, 18), 0);
	s->bar.values[0] = create_text("0", create_vector2f(x + 67, y + 67),
	"ressources/fonts/bars.otf");
	s->bar.values[1] = create_text("0", create_vector2f(x + 125, y + 60),
	"ressources/fonts/bars.otf");
	sfText_setCharacterSize(s->bar.values[1]->text, 14);
	s->bar.values[2] = create_text("0", create_vector2f(x + 125, y + 88),
	"ressources/fonts/bars.otf");
	sfText_setCharacterSize(s->bar.values[2]->text, 14);
}

void destroy_life_bar(st_rpg *s)
{
	destroy_object(s->bar.bars);
	destroy_object(s->bar.life);
	destroy_object(s->bar.xp);
}
