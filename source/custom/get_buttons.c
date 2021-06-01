/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"

int cust_get_buttons(int menu)
{
	return (menu + 2);
}

int cust_maxx_buttons(int menu)
{
	if (menu == 1)
		return (2);
	if (menu == 2)
		return (3);
	return (4);
}

int cust_minx_buttons(int menu)
{
	if (menu == 1 || menu == 2)
		return (0);
	return (0);
}
