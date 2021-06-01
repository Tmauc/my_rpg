/*
** EPITECH PROJECT, 2017
** my_putcharror.c
** File description:
** putchar on error output
*/

#include "my.h"

void my_putcharror(char chr)
{
	write(2, &chr, 1);
}
