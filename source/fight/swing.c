/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

swing_t *create_swing_from_file(char *path)
{
	swing_t *swing = malloc(sizeof(swing_t));
	int fd = open(path, O_RDONLY);

	swing->begin = str_to_int(get_next_line(fd));
	swing->angle = str_to_int(get_next_line(fd));
	swing->count = 0;
	swing->speed = str_to_int(get_next_line(fd)) / 100;
	swing->shot = 0;
	swing->able = 0;
	swing->sens = -1;
	swing->scale.x = str_to_int(get_next_line(fd)) / 100;
	swing->scale.y = str_to_int(get_next_line(fd)) / 100;
	swing->dmg = str_to_int(get_next_line(fd));
	swing->dmgratio = str_to_int(get_next_line(fd));
	swing->t = create_st_time();
	return (swing);
}

void destroy_swing(swing_t *swing)
{
	sfClock_destroy(swing->t.clock);
	free(swing);
}

void launch_swing(st_rpg *s, swing_t *swing, g_object *obj)
{
	swing->able = 1;
	swing->shot = 1;
	swing->count = 0;
	sfSprite_setRotation(obj->sprite, get_angle(s) +
	swing->begin);
}

void apply_swing(st_rpg *s, swing_t *swing, g_object *obj)
{
	for (int i = 0; i != s->proc.pvar.enemy_nbr; i += 1) {
		if (enemy_hitbox(obj, s->f.mob[i]) && swing->able &&
		s->f.mob[i]->alive) {
			swing_damage_enemy(s, swing, s->f.mob[i]);
			swing->able -= 1;
		}
	}
}

void update_swing(st_rpg *s, swing_t *swing, g_object *obj)
{
	swing->t.time = sfClock_getElapsedTime(swing->t.clock);
	swing->t.sec = swing->t.time.microseconds / 1000000.0;
	if (swing->t.sec > swing->speed && swing->shot) {
		apply_swing(s, swing, obj);
		swing->count += 10 * swing->sens;
		sfSprite_setRotation(obj->sprite, sfSprite_getRotation(obj
		->sprite) + 10 * swing->sens);
		sfSprite_setScale(obj->sprite, swing->scale);
		if (abs(swing->count) >= swing->angle) {
			s->f.cast = 0;
			swing->shot = 0;
		}
		sfClock_restart(swing->t.clock);
	}
}
