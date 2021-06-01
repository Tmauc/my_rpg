/*
** EPITECH PROJECT, 2018
** create_map_boss.c
** File description:
** file to stock all boss map creation
*/

#include "my.h"
#include "my_rpg.h"

void read_map_boss(st_rpg *rpg)
{
	char *str;
	char *pathname =
	my_strcat("ressources/map_preset/", int_to_str(rpg->boss));
	int fd = open(pathname, O_RDONLY);

	rpg->proc.map =
	malloc(sizeof(char *) * (rpg->proc.pvar.map_height));
	for (int y = 0; (str = get_next_line(fd)) != NULL; y++)
		rpg->proc.map[y] = str;
	rpg->proc.map[rpg->proc.pvar.map_height - 1] = NULL;
	close(fd);
}

void map_boss_creation(st_rpg *rpg)
{
	rpg->proc.proom = my_calloc(sizeof(proom_t) * (1));
	rpg->proc.proom[0].last = 1;
	read_map_boss(rpg);
}
