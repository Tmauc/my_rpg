/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create_obj
*/

#include <stdlib.h>
#include "game_object.h"

st_time create_st_time(void)
{
	st_time t;

	t.clock = sfClock_create();
	t.sec = 0.0;
	return (t);
}
