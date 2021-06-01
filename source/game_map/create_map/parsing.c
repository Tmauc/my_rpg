/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing file for my_rpg
*/

#include "my.h"
#include "game_map.h"

void parsing_step(int y, st_rpg *s, char *str)
{
	int i = 0;
	int x = 0;
	int a = 0;
	char **tab = my_calloc(sizeof(char *) * y + 1);

	while (a != y) {
		x = 0;
		tab[a] = my_calloc(sizeof(char) * 6 + 1);
		while (str[i] != '\n' && str[i] != 0) {
			tab[a][x] = str[i];
			i++;
			x++;
		}
		tab[a][x] = '\0';
		i++;
		a++;
	}
	free(str);
	tab_to_struct(s, tab, y);
}

int check_buff(char *buff, int i, int y)
{
	if (buff[i] == 10)
		y++;
	return (y);
}

void parsing(struct stat a, st_rpg *s)
{
	int y = 0;
	int k = 0;
	int len = 0;
	int file = open("ressources/map_preset/parsing", O_RDONLY);
	char *buff = my_calloc(sizeof(char) * a.st_size + 1);
	char *str = my_calloc(sizeof(char) * a.st_size + 1);

	while ((len = read(file, buff, a.st_size))) {
		buff[len] = 0;
		if (len == 0)
			break;
		for (int i = 0; buff[i]; i++) {
			str[k++] = buff[i];
			y = check_buff(buff, i, y);
		}
	}
	str[k] = 0;
	parsing_step(y, s, str);
	free(buff);
	close(file);
}
