/*
** EPITECH PROJECT, 2018
** get_all_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

int take_nbr_quests(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	int size = 0;

	while ((entry = readdir(dir)) != 0) {
		if (entry->d_name[0] != '.')
			size++;
	}
	closedir(dir);
	return (size);
}

void get_all_quests_plus(st_rpg *s, char **tab, int i)
{
	tab = my_sort_params(tab);
	for (; tab[i] != NULL; i++) {
		s->fi->quests[i] = get_quests(tab[i]);
	}
	s->fi->quests[i] = NULL;
}

void get_all_quests(st_rpg *s, char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	char *name;
	int i = 0;
	int size = take_nbr_quests(path);
	char **tab = my_calloc(sizeof(char*) * 1);

	s->fi->quests = malloc(sizeof(quests_t) * size + 1);
	for (int i = 0; i != size; i++) {
		s->fi->quests[i] = malloc(sizeof(quests_t));
	} while ((entry = readdir(dir)) != 0) {
		if (entry->d_name[0] != '.') {
			name = my_strcat_dup(path, entry->d_name);
			tab = remalloc_tab(tab, name);
			free(name);
		}
	}
	get_all_quests_plus(s, tab, i);
	closedir(dir);
}
