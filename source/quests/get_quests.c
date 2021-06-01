/*
** EPITECH PROJECT, 2018
** get_quests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

int *get_all_type(char *buffer)
{
	int size = 0;
	int j = 0;
	int i = 0;
	int *type;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] != ' ')
			size++;
	}
	type = malloc(sizeof(int *) * size + 1);
	for (i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] != ' ') {
			type[j] = buffer[i] - 48;
			j++;
		}
	}
	type[j] = 666;
	free(buffer);
	return (type);
}

void get_type_and_create_quests(char *buffer, quests_list_t *quests_list)
{
	quests_list->type = buffer[0] - 48;
	if (quests_list->type == 1)
		create_farm_quests(buffer, quests_list);
	if (quests_list->type == 2)
		create_kill_quests(buffer, quests_list);
	if (quests_list->type == 3)
		create_go_quests(buffer, quests_list);
	if (quests_list->type == 4)
		create_speak_quests(buffer, quests_list);
}

quests_list_t *get_next_quests(quests_list_t *quests_list,
int fd, int i, int size)
{
	char *buffer = NULL;

	quests_list->next = NULL;
	if (i != size) {
		i += 1;
		buffer = get_next_line(fd);
		get_type_and_create_quests(buffer, quests_list);
		quests_list->next = malloc(sizeof(quests_list_t));
		get_next_quests(quests_list->next, fd, i, size);
		free(buffer);
	}
	return (quests_list);
}

quests_t *get_quests(char *name)
{
	int fd = open(name, O_RDONLY);
	int i = 0;
	char *buffer = NULL;
	quests_t *quests = malloc(sizeof(quests_t));

	quests->status = 0;
	quests->title = get_next_line(fd);
	quests->path = get_next_line(fd);
	buffer = get_next_line(fd);
	get_rewards(buffer, quests);
	free(buffer);
	quests->nbr_quests = str_to_int(get_next_line(fd));
	quests->quests_list = malloc(sizeof(quests_list_t));
	quests->quests_list = get_next_quests(quests->quests_list,
	fd, i, quests->nbr_quests);
	return (quests);
}
