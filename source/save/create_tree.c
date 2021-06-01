/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_first_tree(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1)
		s->player.tree.lock[i] = 1;
	s->player.tree.passive = 0;
	s->player.tree.spell1 = 0;
	s->player.tree.spell2 = 0;
	s->player.tree.spell3 = 0;
	s->player.tree.skillp = 0;
}

void load_tree(st_rpg *s, char *path)
{
	int fd = open(path, O_RDONLY);

	for (int i = 0; i != 10; i += 1)
		s->player.tree.lock[i] = str_to_int(get_next_line(fd));
	s->player.tree.passive = str_to_int(get_next_line(fd));
	s->player.tree.spell1 = str_to_int(get_next_line(fd));
	s->player.tree.spell2 = str_to_int(get_next_line(fd));
	s->player.tree.spell3 = str_to_int(get_next_line(fd));
	s->player.tree.skillp = str_to_int(get_next_line(fd));
	close(fd);
}

void save_tree_2(int fd, tree_t tree)
{
	char value = tree.lock[7] + 48;
	char *buffer = int_to_str(tree.skillp);

	write_a_value(fd, &value, 1);
	value = tree.lock[8] + 48;
	write_a_value(fd, &value, 1);
	value = tree.lock[9] + 48;
	write_a_value(fd, &value, 1);
	value = tree.passive + 48;
	write_a_value(fd, &value, 1);
	value = tree.spell1 + 48;
	write_a_value(fd, &value, 1);
	value = tree.spell2 + 48;
	write_a_value(fd, &value, 1);
	value = tree.spell3 + 48;
	write_a_value(fd, &value, 1);
	write_a_value(fd, buffer, 1);
	free(buffer);
}

void save_tree(tree_t tree, char *path)
{
	char *path_tree = my_strcat(path, "tree");
	int fd = open(path_tree, O_WRONLY | O_TRUNC | O_CREAT);
	char value = tree.lock[0] + 48;

	write_a_value(fd, &value, 1);
	value = tree.lock[1] + 48;
	write_a_value(fd, &value, 1);
	value = tree.lock[2] + 48;
	write_a_value(fd, &value, 1);
	value = tree.lock[3] + 48;
	write_a_value(fd, &value, 1);
	value = tree.lock[4] + 48;
	write_a_value(fd, &value, 1);
	value = tree.lock[5] + 48;
	write_a_value(fd, &value, 1);
	value = tree.lock[6] + 48;
	write_a_value(fd, &value, 1);
	save_tree_2(fd, tree);
	close(fd);
	free(path_tree);
}
