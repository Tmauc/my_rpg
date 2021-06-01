/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_dash(dash_t *dash)
{
	free(dash);
}

void update_dash(st_rpg *s, dash_t *dash)
{
	if (dash->on) {
		dash->count -= dash->speed;
		if (dash->count <= 0) {
			stop_player(s);
			s->f.cast = 0;
			dash->on = 0;
		}
	}
}

void launch_dash(st_rpg *s, dash_t *dash)
{
	dash->ratios = get_ratios(get_angle(s));
	s->f.cast = 2;
	dash->on = 1;
	dash->count = dash->range;
	s->player.nbr_frame.x = dash->ratios.x * dash->speed;
	s->player.nbr_frame.y = dash->ratios.y * dash->speed;
}

dash_t *create_dash(float speed, float range)
{
	dash_t *dash = malloc(sizeof(dash_t));

	dash->range = range;
	dash->speed = speed;
	dash->count = 0;
	dash->on = 0;
	dash->ratios = create_vector2f(0, 0);
	return (dash);
}
