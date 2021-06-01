/*
** EPITECH PROJECT, 2018
** save.c
** File description:
** description
*/

#include "my_rpg.h"
#include "my.h"

void write_a_value(int fd, char *value, int len)
{
	write(fd, value, len);
	write(fd, "\n", 1);
}

void save_cust(st_cdata cdata, char *path, st_rpg *s)
{
	char *cust = my_strcat(path, "cust");
	int fd = open(cust, O_WRONLY | O_TRUNC | O_CREAT);
	char value = cdata.sex + 48;
	char *buffer = int_to_str(s->fi->quests_box.nb_quests);

	write_a_value(fd, &value, 1);
	value = cdata.classe + 48;
	write_a_value(fd, &value, 1);
	write_a_value(fd, cdata.name, my_strlen(cdata.name));
	write_a_value(fd, buffer, my_strlen(buffer));
	free(buffer);
	close(fd);
	free(cust);
}

void save_game(st_rpg *s)
{
	char *path = get_save_path(s);

	save_cust(s->player.cdata, path, s);
	save_stat(s->player.stat, path);
	save_tree(s->player.tree, path);
	save_current_inventory(s);
	free(path);
	s->pausm.opac = 255;
}
