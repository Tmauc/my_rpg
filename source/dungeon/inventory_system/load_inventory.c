/*
** EPITECH PROJECT, 2018
** load_inventory.c
** File description:
** load inventory from file
*/

#include "my.h"
#include "my_rpg.h"

void load_item_inventory(st_rpg *rpg, int id, int stacks)
{
	item_t *current = rpg->inv.first_slot;

	if (current == NULL) {
		rpg->inv.first_slot = create_first_slot();
		rpg->inv.first_slot->stacks = stacks;
		rpg->inv.first_slot->id = id;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = create_first_slot();
	current->next->pos = current->pos + 1;
	current->next->stacks = stacks;
	current->next->id = id;
}

int init_load_inventory(st_rpg *rpg, int fd)
{
	char *str;

	rpg->inv.first_slot = NULL;
	rpg->inv.money = 0;
	if (fd < 0)
		return (0);
	destroy_inventory_items(rpg);
	str = get_next_line(fd);
	rpg->inv.money = str_to_int(str);
	free(str);
	return (1);
}

void load_inventory(st_rpg *rpg)
{
	char *str;
	char *path = get_save_path(rpg);
	char *pathname = my_strcat(path, "inventory");
	int fd = open(pathname, O_RDONLY);
	int spac_pos;

	if (!init_load_inventory(rpg, fd))
		return;
	while ((str = get_next_line(fd)) != NULL) {
		spac_pos = my_str_chrpos(str, ',');
		str[spac_pos] = '\0';
		load_item_inventory(rpg, str_to_int(str),
		str_to_int(&str[spac_pos + 1]));
		free(str);
	}
	close(fd);
	free(path);
	free(pathname);
}
