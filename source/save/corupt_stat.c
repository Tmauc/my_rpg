/*
** EPITECH PROJECT, 2018
** check_stat.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

int check_stat_value(char *buffer)
{
	if (buffer == NULL) {
		return (84);
	}
	for (int a = 0; buffer[a] != '\0'; a++) {
		if (buffer[a] > 57 && buffer[a] < 48) {
			return (84);
		}
	}
	return (0);
}

int check_stat(char *saves)
{
	char *path = my_strcat(saves, "/stat");
	int fd = open(path, O_RDONLY);
	char *buffer = NULL;
	int a = 0;

	free(path);
	if (fd == -1) {
		return (84);
	}
	while (a != 9) {
		buffer = get_next_line(fd);
		if (check_stat_value(buffer) == 84) {
			free(buffer);
			close(fd);
			return (84);
		}
		a++;
		free(buffer);
	}
	close(fd);
	return (0);
}
