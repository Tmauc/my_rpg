/*
** EPITECH PROJECT, 2018
** corupt_tree.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

int check_tree_unlock(char *buffer)
{
	for (int a = 0; buffer[a] != '\0'; a++) {
		if (buffer[a] != '0' && buffer[a] != '1') {
			return (84);
		}
	}
	return (0);

}

int check_tree_select(char *buffer)
{
	for (int a = 0; buffer[a] != '\0'; a++) {
		if (buffer[a] != '0' && buffer[a] != '1' && buffer[a] != '2') {
			return (84);
		}
	}
	return (0);

}

int check_tree_value(char *buffer, int i)
{
	if (buffer == NULL) {
		return (84);
	}
	if (i < 10) {
		return (check_tree_unlock(buffer));
	} if (i < 12) {
		return (check_tree_select(buffer));
	} if (i < 14) {
		return (check_tree_unlock(buffer));
	} else {
		return (check_stat_value(buffer));
	}
}

int check_tree(char *saves)
{
	char *path = my_strcat(saves, "/tree");
	int fd = open(path, O_RDONLY);
	char *buffer = NULL;
	int a = 0;

	free(path);
	if (fd == -1) {
		return (84);
	}
	while (a != 9) {
		buffer = get_next_line(fd);
		if (check_tree_value(buffer, a) == 84) {
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
