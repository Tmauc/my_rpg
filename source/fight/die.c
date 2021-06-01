/*
** EPITECH PROJECT, 2018
** verify_collisions.c
** File description:
** verify collisions for player and map
*/

#include "my_rpg.h"
#include "my.h"

void create_die(st_rpg *s)
{
	s->f.die_msg = create_text("YOU DIED",
	(sfVector2f){s->origin.x + 560, s->origin.y + 400},
	"ressources/fonts/boss.otf");
	sfText_setCharacterSize(s->f.die_msg->text, 250);
	s->f.die_fade = create_object(
	"ressources/images/interface/semiblack.png",
	(sfVector2f){s->origin.x, s->origin.y},
	create_rect(0, 0, 1920, 1080), 0);
	s->f.fade = 0;
}

void update_die(st_rpg *s)
{
	int fade = s->f.fade;

	if (s->f.fade > 255)
		fade = 255;
	sfSprite_setColor(s->f.die_fade->sprite,
	(sfColor){255, 255, 255, fade});
	sfText_setColor(s->f.die_msg->text,
	(sfColor){255, 255, 255, fade});
	s->f.fade += 2;
}

void destroy_die(st_rpg *s)
{
	destroy_text(s->f.die_msg);
	destroy_object(s->f.die_fade);
}

int die(st_rpg *s)
{
	create_die(s);
	update_bars(s);
	while (s->f.fade < 400) {
		display_dungeon(s);
		update_die(s);
		sfRenderWindow_drawSprite(s->window,
		s->f.die_fade->sprite, NULL);
		sfRenderWindow_drawText(s->window,
		s->f.die_msg->text, NULL);
		sfRenderWindow_display(s->window);
	}
	destroy_die(s);
	destroy_dungeon_loop(s);
	s->player.stat->pva = s->player.stat->pvm;
	return (2);
}
