/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr to print a number on the screen
*/

#include <unistd.h>
#include "../../include/my.h"

int reduceneg(int nb)
{
	long int disaine = -1;

	my_putchar(45);
	while (disaine >= nb) {
		disaine = disaine * 10;
	}
	while (disaine != -1) {
		my_putchar(((nb % disaine) / (disaine / 10)) + 48);
		disaine = disaine / 10;
	}
	return (0);
}

int reducepos(int nb)
{
	long int disaine = 1;

	while (disaine <= nb) {
		disaine = disaine * 10;
	}
	while (disaine != 1) {
		my_putchar(((nb % disaine) / (disaine / 10)) + 48);
		disaine = disaine / 10;
	}
	return (0);
}

int my_put_nbr(int nb)
{
	if (nb == 0)
		my_putchar(48);
	if (nb > 0)
		reducepos(nb);
	else if (nb < 0)
		reduceneg(nb);
	return (0);
}
