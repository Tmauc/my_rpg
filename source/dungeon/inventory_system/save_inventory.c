/*
** EPITECH PROJECT, 2018
** save_load_inventory.c
** File description:
** file to stock all functions about saving and loading inventory
*/

#include "my.h"
#include "my_rpg.h"

char *free_save_inv(item_t *current)
{
	char *id;
	char *nbr;
	char *temp;
	char *line;

	id = int_to_str(current->id);
	nbr = int_to_str(current->stacks);
	temp = my_strcat(id, ",");
	line = my_strcat(temp, nbr);
	free(id);
	free(nbr);
	free(temp);
	return (line);
}

void free_and_close(char *path, char *pathname, int fd)
{
	close(fd);
	free(path);
	free(pathname);
}

void save_current_inventory(st_rpg *rpg)
{
	char *temp = int_to_str(rpg->inv.money);
	char *path = get_save_path(rpg);
	char *pathname = my_strcat(path, "inventory");
	int fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
	item_t *current = rpg->inv.first_slot;

	write(fd, temp, my_strlen(temp));
	write(fd, "\n", 1);
	free(temp);
	while (current != NULL) {
		temp = free_save_inv(current);
		write(fd, temp, my_strlen(temp));
		write(fd, "\n", 1);
		current = current->next;
		free(temp);
	}
	free_and_close(path, pathname, fd);
}
