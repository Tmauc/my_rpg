/*
** EPITECH PROJECT, 2017
** int_to_str.c
** File description:
** int_to_str.c
*/

#include "my.h"

int my_nblen(int nb)
{
	int i = 0;

	if (nb == 0)
		return (1);
	while (nb != 0) {
		nb = nb / 10;
		i++;
	}
	return (i);
}

char *int_to_str(int nbr)
{
	int len = my_nblen(nbr);
	int iter = 0;
	unsigned int dis = my_compute_power_rec(10, len - 1);
	int neg = 0;
	char *str = my_calloc(sizeof(char) * (len + 2));

	if (nbr < 0) {
		str[0] = '-';
		neg += 1;
	}
	while (iter < len) {
		str[iter + neg] = nbr / dis % 10 + 48;
		dis = dis / 10;
		iter += 1;
	}
	return (str);
}
