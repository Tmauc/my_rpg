/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_ly(st_rpg *s, float dt)
{
	if (s->f.mob[1]->cdcount >= 0)
		s->f.mob[1]->cdcount -= dt;
	if (s->f.mob[1]->cdcount < 0 && enemy_is_able(s, 1)) {
		s->f.mob[1]->cast = 2;
		s->f.boss.casting = 1;
		s->f.boss.attack_ly = rand() % 2;
	} if (s->f.boss.casting > 0) {
		s->f.boss.casting -= dt;
	} if (s->f.boss.casting < 0) {
		s->f.mob[1]->cdcount = s->f.mob[1]->cd;
		s->f.mob[1]->cast = 0;
		s->f.boss.casting = 0;
		launch_ly_spell(s);
	}
	update_ly_ray(s, dt);
}

void display_ly(st_rpg *s)
{
	if (s->f.mob[1]->alive)
		choose_display_enemies(s, 1);
	display_aoe(s->window, s->f.boss.ray);
}

void destroy_ly(st_rpg *s)
{
	destroy_aoe(s->f.boss.ray);
	sfMusic_destroy(s->f.boss.thunder);
}

void generate_ly(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1)
		destroy_enemy(s->f.mob[i]);
	s->proc.pvar.enemy_nbr = 2;
	s->f.mob = malloc(sizeof(enemy_t *) * s->proc.pvar.enemy_nbr);
	generate_champ(s);
	s->f.mob[1] = generate_enemy("ressources/enemies/Ly");
	s->f.mob[1]->obj->pos.x = s->player.obj->pos.x - 100;
	s->f.mob[1]->obj->pos.y = s->player.obj->pos.y - 400;
	sfSprite_setPosition(s->f.mob[1]->obj->sprite,
	s->f.mob[1]->obj->pos);
	sfSprite_setScale(s->f.mob[1]->obj->sprite, (sfVector2f){3, 3});
	s->f.boss.ray = create_aoe_from_file("ressources/spells/enemies/ray");
	s->f.boss.attack_ly = 0;
	s->f.boss.casting = 0;
	s->f.boss.rayused = 0;
	s->f.boss.rayrat = create_vector2f(0, 0);
	sfMusic_createFromFile("ressources/audio/sound/roda.ogg");
	s->f.boss.thunder =
	sfMusic_createFromFile("ressources/audio/sound/thunder.ogg");
	sfMusic_setVolume(s->f.boss.thunder, s->s_effect);
}
