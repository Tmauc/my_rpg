/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void choose_sound(st_rpg *s)
{
	if (s->f.boss.attack == 1) {
		sfMusic_play(s->f.boss.samy_roda);
	} else if (s->f.boss.attack == 2) {
		sfMusic_play(s->f.boss.samy_rage);

	}
}

void launch_samy_dash(st_rpg *s)
{
	s->f.boss.dash->ratios = get_ratios(get_angle_enemy(s, 0));
	s->f.mob[0]->cast = 2;
	s->f.boss.dash->on = 1;
	s->f.boss.dash->count = s->f.boss.dash->range;
	s->f.mob[0]->ratios.x =
	s->f.boss.dash->ratios.x * s->f.boss.dash->speed;
	s->f.mob[0]->ratios.y =
	s->f.boss.dash->ratios.y * s->f.boss.dash->speed;
}

void launch_samy_fusrohdah(st_rpg *s)
{
	launch_particle(s->f.boss.samy_fus,
	(sfVector2f){s->f.mob[0]->obj->pos.x +
		(s->f.mob[0]->obj->rect.width * 3 / 2),
		s->f.mob[0]->obj->pos.y +
		(s->f.mob[0]->obj->rect.height * 3 / 2)},
	get_angle_enemy(s, 0));
	s->f.boss.fus->ratios = get_ratios(get_angle_enemy(s, 0));
	s->f.mob[0]->cast = 2;
	s->f.boss.fus->on = 1;
	s->f.boss.fus->count = s->f.boss.fus->range;
	s->player.nbr_frame.x = s->f.boss.fus->ratios.x * s->f.boss.fus->speed;
	s->player.nbr_frame.y = s->f.boss.fus->ratios.y * s->f.boss.fus->speed;
}

void launch_samy_rage(st_rpg *s)
{
	launch_particle(s->f.boss.samy_part,
	(sfVector2f){s->f.mob[0]->obj->pos.x +
		(s->f.mob[0]->obj->rect.width * 3 / 2),
		s->f.mob[0]->obj->pos.y +
		(s->f.mob[0]->obj->rect.height * 3 / 2)},
	rand() % 360);
	s->f.boss.rage->amount = 1;
	s->f.boss.fus->speed = s->f.boss.fus->speed * 1.5;
	s->f.boss.fus->range = s->f.boss.fus->range * 1.5;
	s->f.boss.dash->speed = s->f.boss.dash->speed * 1.2;
	s->f.boss.dash->range = s->f.boss.dash->range * 1.2;
}

void launch_samy_spell(st_rpg *s)
{
	void (*list[3])(st_rpg *s) = {launch_samy_dash,
		launch_samy_fusrohdah, launch_samy_rage};

	(list[s->f.boss.attack])(s);
}
