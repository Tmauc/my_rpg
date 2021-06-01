/*
** EPITECH PROJECT, 2018
** corupt_save.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

int corupt_save(void)
{
	char *path;
	char *numb;

	for (int i = 1; i != 4; i++) {
		numb = int_to_str(i);
		path = my_strcat("saves/", numb);
		free(numb);
		if (check_cust(path) == 84) {
			free(path);
			return (84);
		} if (check_stat(path) == 84) {
			free(path);
			return (84);
		} if (check_tree(path) == 84) {
			free(path);
			return (84);
		}
		free(path);
	}
	return (0);
}
