/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void generate_champ_part2(st_rpg *s)
{
	s->f.boss.well = create_aoe_from_file("ressources/spells/enemies/well");
	s->f.boss.ball = create_aoe_from_file("ressources/spells/enemies/ball");
	s->f.boss.s_ball =
	sfMusic_createFromFile("ressources/audio/sound/ball.ogg");
	s->f.boss.s_tent =
	sfMusic_createFromFile("ressources/audio/sound/tent.ogg");
	sfMusic_setVolume(s->f.boss.s_tent, s->s_effect);
	sfMusic_setVolume(s->f.boss.s_ball, s->s_effect);
}

void generate_champ(st_rpg *s)
{
	s->f.mob[0] = generate_enemy("ressources/enemies/Champ");
	s->f.boss.attack = 0;
	s->f.boss.ctent = 0;
	s->f.boss.used = 0;
	s->f.boss.trat = create_vector2f(0, 0);
	s->f.boss.ballpos = create_vector2f(0, 0);
	s->f.boss.ballrat = create_vector2f(0, 0);
	s->f.mob[0]->obj->pos.x = s->player.obj->pos.x;
	s->f.mob[0]->obj->pos.y = s->player.obj->pos.y - 400;
	sfSprite_setPosition(s->f.mob[0]->obj->sprite,
	s->f.mob[0]->obj->pos);
	sfSprite_setScale(s->f.mob[0]->obj->sprite, (sfVector2f){3, 3});
	for (int i = 0; i != 6; i += 1)
		s->f.boss.tent[i] = create_aoe_from_file(
		"ressources/spells/enemies/tent");
	generate_champ_part2(s);
}
