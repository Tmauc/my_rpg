/*
** EPITECH PROJECT, 2018
** my_str_chrpos.c
** File description:
** get first chr pos in str
*/

#include "my.h"

int my_str_chrpos(char *str, char chr)
{
	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] == chr)
			return (i);
	}
	return (-1);
}
