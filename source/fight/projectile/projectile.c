/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "math.h"
#include "my_rpg.h"
#include "my.h"

void update_projectile(proj_t *proj, float dt)
{
	proj->obj->pos.x += proj->ratios.x * proj->obj->speed * dt;
	proj->obj->pos.y += proj->ratios.y * proj->obj->speed * dt;
	proj->used -= hypot(proj->ratios.x * proj->obj->speed * dt,
	proj->ratios.y * proj->obj->speed * dt);
	if (proj->used <= 0 && proj->shot != 2)
		proj->shot = 0;
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
}

void launch_projectile(st_rpg *s, proj_t *proj, float angle)
{
	proj->ratios = get_ratios(angle);
	proj->used = proj->range;
	proj->obj->pos.x = s->origin.x + 960 - proj->ratios.x * proj->obj
	->rect.width / 2 + proj->ratios.y * proj->obj->rect.height / 2;
	proj->obj->pos.y = s->origin.y + 540 - proj->ratios.y * proj->obj
	->rect.width / 2 - proj->ratios.x * proj->obj->rect.height / 2;
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
	sfSprite_setRotation(proj->obj->sprite, angle);
	proj->shot = 1;
}

void create_projectile2(proj_t *proj)
{
	proj->obj->rect.width = sfTexture_getSize(sfSprite_getTexture(proj
	->obj->sprite)).x;
	proj->obj->rect.height = sfTexture_getSize(sfSprite_getTexture(proj
	->obj->sprite)).y;
	proj->obj->pos.x = 0;
	proj->obj->pos.y = 0;
	sfSprite_setPosition(proj->obj->sprite, proj->obj->pos);
	sfSprite_setTextureRect(proj->obj->sprite, proj->obj->rect);
	proj->ratios = create_vector2f(0, 0);
	proj->rpos = create_vector2f(0, 0);
	proj->shot = 0;
	proj->angle = 0;
}

proj_t *create_projectile(char *path)
{
	int fd = open(path, O_RDONLY);
	proj_t *proj = malloc(sizeof(proj_t));

	proj->obj = create_object(get_next_line(fd),
	create_vector2f(0, 0),
	create_rect(0, 0, 0, 0), 0);
	proj->obj->speed = str_to_int(get_next_line(fd)) / 100;
	proj->range = str_to_int(get_next_line(fd)) / 100;
	proj->used = proj->range;
	proj->dmg = str_to_int(get_next_line(fd)) / 100;
	proj->dmgratio = str_to_int(get_next_line(fd)) / 100;
	proj->cd = str_to_int(get_next_line(fd));
	proj->cd = proj->cd / 100;
	proj->effect = get_next_line(fd);
	proj->duration = str_to_int(get_next_line(fd)) / 100;
	close(fd);
	create_projectile2(proj);
	return (proj);
}

void destroy_projectile(proj_t *proj)
{
	destroy_object(proj->obj);
	free(proj);
}
