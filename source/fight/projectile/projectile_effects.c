/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void explosive_proc(st_rpg *s)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (circle_hitbox_enemy(s->f.gun.expbt, s->f.mob[i]) &&
		s->f.mob[i]->alive) {
			s->f.mob[i]->stat->pva -= 20 + 10 * s->player.stat->lvl;
		}
	}
}

void handle_explosive(st_rpg *s, proj_t *proj)
{
	if (!my_strcmp(proj->effect, "explosive")) {
		sfMusic_play(s->f.gun.s_explo);
		s->f.gun.expbullet->obj->pos = create_vector2f(s
		->f.gun.bullet[9]->obj->pos.x - 50, s->f.gun.bullet[9]
		->obj->pos.y - 50);
		sfSprite_setPosition(s->f.gun.expbullet->obj->sprite,
		s->f.gun.expbullet->obj->pos);
		sfCircleShape_setPosition(s->f.gun.expbt,
		s->f.gun.expbullet->obj->pos);
		s->f.gun.bullet[9]->shot = 2;
		s->f.gun.expbullet->li = 0;
		s->f.gun.expbullet->c = 0;
		explosive_proc(s);
	}
}

void handle_bounce(st_rpg *s, proj_t *proj)
{
	sfVector2f pos = proj->obj->pos;

	if (!my_strcmp(proj->effect, "bounce")) {
		proj->shot = 1;
		launch_projectile(s, proj, rand() % 360);
		proj->obj->pos = pos;
	}
}

void handle_pierce(proj_t *proj)
{
	if (!my_strcmp(proj->effect, "pierce"))
		proj->shot = 1;
}
