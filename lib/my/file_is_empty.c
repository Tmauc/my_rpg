/*
** EPITECH PROJECT, 2018
** file_is_empty.c
** File description:
** verify if a file is empty
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int file_is_empty(char *name)
{
	int fd = open(name, O_RDONLY);
	char *tmp = malloc(sizeof(char) * (1));

	read(fd, tmp, 1);
	if (tmp[0] == '\0')
		return (1);
	return (0);
}
