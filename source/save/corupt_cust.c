/*
** EPITECH PROJECT, 2018
** corupt_cust.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

int check_cust_sex_class(int fd)
{
	char *buffer = get_next_line(fd);

	if (buffer == NULL || my_strlen(buffer) > 1 ||
	(buffer[0] != '0' && buffer[0] != '1')) {
		free(buffer);
		return (84);
	}
	free(buffer);
	buffer = get_next_line(fd);
	if (buffer == NULL || my_strlen(buffer) > 1 ||
	buffer[0] < 48 || buffer[0] >= 52) {
		free(buffer);
		return (84);
	}
	free(buffer);
	return (0);
}

int check_cust_name_quest(int fd)
{
	char *buffer = get_next_line(fd);

	if (buffer == NULL) {
		free(buffer);
		return (84);
	}
	free(buffer);
	buffer = get_next_line(fd);
	if (buffer == NULL || my_strlen(buffer) > 2 ||
	buffer[0] < 48 || buffer[0] > 57) {
		free(buffer);
		return (84);
	}
	free(buffer);
	return (0);
}

int check_cust(char *saves)
{
	char *path = my_strcat(saves, "/cust");
	int fd = open(path, O_RDONLY);

	free(path);
	if (fd == -1) {
		return (84);
	}
	if (check_cust_sex_class(fd) == 84) {
		close(fd);
		return (84);
	}
	if (check_cust_name_quest(fd) == 84) {
		close(fd);
		return (84);
	}
	close(fd);
	return (0);
}
