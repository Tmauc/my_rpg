/*
** EPITECH PROJECT, 2017
** my sort params
** File description:
** sort params
*/

#include <unistd.h>
#include "../../include/my.h"

int count_nbr_str(char **table)
{
	int len = 0;

	while (table[len] != NULL) {
		len = len + 1;
	}
	return (len);
}

char **my_sort_params_part2(int i, int j, int len, char **table)
{
	char *temp;

	while (j < len) {
		if (my_strcmp(table[i], table[j]) < 0) {
			temp = table[i];
			table[i] = table[j];
			table[j] = temp;
		} else
			j = j + 1;
	}
	return (table);
}

char **my_sort_params(char **table)
{
	int i = 0;
	int j = 1;
	int len = count_nbr_str(table);

	while (i < len) {
		table = my_sort_params_part2(i, j, len, table);
		j = 0;
		i = i + 1;
	}
	return (table);
}
