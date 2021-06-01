/*
** EPITECH PROJECT, 2018
** remalloc_tab.c
** File description:
** remalloc_tab.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

char **remalloc_tab(char **tab, char *str)
{
	char **tmp = tab;
	int i = 0;
	int compter = 0;

	for (int j = 0; tmp[j]; j++)
		compter++;
	tab = malloc(sizeof(char *) * (compter + 2));
	for (int j = 0; tmp[j]; j++)
		tab[i++] = my_strdup(tmp[j]);
	tab[i++] = my_strdup(str);
	tab[i] = 0;
	i = 0;
	return (tab);
}
