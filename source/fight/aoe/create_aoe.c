/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_aoe_data(aoe_t *aoe, int fd)
{
	aoe->anim->speed = aoe->anim->speed / 100;
	aoe->anim->width = sfTexture_getSize(sfSprite_getTexture(aoe->anim->obj
	->sprite)).x / aoe->anim->hor;
	aoe->anim->height = sfTexture_getSize(sfSprite_getTexture(aoe->anim->obj
	->sprite)).y / aoe->anim->ver;
	aoe->anim->obj->rect.width = aoe->anim->width;
	aoe->anim->obj->rect.height = aoe->anim->height;
	aoe->shot = 0;
	aoe->count = 0;
	aoe->effect = get_next_line(fd);
	aoe->dmg = str_to_int(get_next_line(fd));
	aoe->dmgratio = str_to_int(get_next_line(fd));
	aoe->duration = str_to_int(get_next_line(fd)) / 100;
}

aoe_t *create_aoe_from_file(char *path)
{
	aoe_t *aoe = malloc(sizeof(aoe_t));
	int fd = open(path, O_RDONLY);
	sfColor color = {str_to_int(get_next_line(fd)),
		str_to_int(get_next_line(fd)), str_to_int(get_next_line(fd)),
		str_to_int(get_next_line(fd))};

	aoe->circle = create_circle(str_to_int(get_next_line(fd)),
	str_to_int(get_next_line(fd)), color);
	aoe->anim = create_anim(create_object(get_next_line(fd),
	create_vector2f(0, 0), create_rect(0, 0, 0, 0), 0),
	create_vector2i(str_to_int(get_next_line(fd)),
	str_to_int(get_next_line(fd))), str_to_int(get_next_line(fd)));
	create_aoe_data(aoe, fd);
	close(fd);
	return (aoe);
}

aoe_t *create_aoe(sfCircleShape *circle, st_anim *anim, float duration)
{
	aoe_t *aoe = malloc(sizeof(aoe_t));

	aoe->circle = circle;
	aoe->anim = anim;
	aoe->duration = duration;
	aoe->shot = 0;
	aoe->dmg = 0;
	aoe->dmgratio = 0;
	return (aoe);
}
