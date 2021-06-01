/*
** EPITECH PROJECT, 2018
** get_layer.c
** File description:
** get_layer file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void get_int(int **end, char *all, int *where, int count)
{
	int a = 0;

	while (all[where[0]] != '\n' && all[where[0]] != '\0') {
		end[count][a] = my_getnbr_i(all, where[0]);
		while (is_num(all[where[0]])) {
			where[0]++;
		}
		if (all[where[0]] == ' ') {
			where[0]++;
		}
		a++;
	}
	where[0]++;
}

int size_malloc(char *all)
{
	int ret = 3;
	int a = 0;

	while (all[a] != '\n') {
		if (all[a] == ' ') {
			ret++;
		}
		a++;
	}
	return (ret);
}

void set_int(int **end, char *all, int i, int a)
{
	int where = 0;
	int count = 0;

	while (count != a) {
		end[count] = my_calloc(sizeof(int) * i);
		get_int(end, all, &where, count);
		count++;
	}
}

int **get_layer(char *name, st_rpg *s)
{
	int fd = open(name, O_RDONLY);
	char *buffer;
	char *all = get_next_line(fd);
	int **end;
	int a = 2;
	int i = 0;

	while ((buffer = get_next_line(fd)) != NULL) {
		draw_loading(s);
		all = my_strcat_dup(all, "\n");
		all = my_strcat_dup(all, buffer);
		a++;
		free(buffer);
	}
	end = my_calloc(sizeof(int *) * a);
	i = size_malloc(all);
	set_int(end, all, i, a);
	close(fd);
	free(all);
	return (end);
}
