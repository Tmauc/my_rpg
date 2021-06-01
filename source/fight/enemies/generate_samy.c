/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void generate_samy_cosmos(st_rpg *s)
{
	s->f.boss.samy_roda =
	sfMusic_createFromFile("ressources/audio/sound/roda.ogg");
	s->f.boss.samy_rage =
	sfMusic_createFromFile("ressources/audio/sound/samy_rage.ogg");
	sfMusic_setVolume(s->f.boss.samy_rage, s->s_effect);
	sfMusic_setVolume(s->f.boss.samy_roda, s->s_effect);
	s->f.boss.samy_part = create_particle(
	"ressources/particles/samy_rage");
	s->f.boss.samy_fus = create_particle(
	"ressources/particles/samy_fus");
}

void generate_samy(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1)
		destroy_enemy(s->f.mob[i]);
	s->proc.pvar.enemy_nbr = 1;
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	s->f.mob[0] = generate_enemy("ressources/enemies/Samy");
	s->f.mob[0]->obj->pos.x = s->player.obj->pos.x;
	s->f.mob[0]->obj->pos.y = s->player.obj->pos.y - 400;
	sfSprite_setPosition(s->f.mob[0]->obj->sprite,
	s->f.mob[0]->obj->pos);
	sfSprite_setScale(s->f.mob[0]->obj->sprite, (sfVector2f){3, 3});
	s->f.boss.dash = create_dash(5, 200);
	s->f.boss.fus = create_dash(60, 800);
	s->f.boss.rage = create_effect("rage", 0, 5);
	s->f.boss.casting = 0;
	generate_samy_cosmos(s);
}
