/*
** EPITECH PROJECT, 2018
** create_difquests.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

void create_farm_quests(char *buffer, quests_list_t *quests_list)
{
	int i = 0;
	int j = 0;
	int size = my_strlen(buffer);
	char *buf = malloc(sizeof(char) * size);

	quests_list->farm_quests.name_item = malloc(sizeof(char) * size);
	for (i = 0; buffer[i] != '|'; i++);
	i++;
	for (j = 0; buffer[i] != '|'; i++, j++)
		quests_list->farm_quests.name_item[j] = buffer[i];
	quests_list->farm_quests.name_item[j] = '\0';
	i++;
	for (j = 0; buffer[i] != '\0'; i++, j++)
		buf[j] = buffer[i];
	buf[j] = '\0';
	quests_list->farm_quests.nbr_item = str_to_int(buf);
	free(buf);
}

void create_kill_quests(char *buffer, quests_list_t *quests_list)
{
	int i = 0;
	int j = 0;
	int size = my_strlen(buffer);
	char *buf = malloc(sizeof(char) * size);

	quests_list->kill_quests.name_kill = malloc(sizeof(char) * size);
	for (i = 0; buffer[i] != '|'; i++);
	i++;
	for (j = 0; buffer[i] != '|'; i++, j++)
		quests_list->kill_quests.name_kill[j] = buffer[i];
	quests_list->kill_quests.name_kill[j] = '\0';
	i++;
	for (j = 0; buffer[i] != '\0'; i++, j++)
		buf[j] = buffer[i];
	buf[j] = '\0';
	quests_list->kill_quests.nbr_kill = str_to_int(buf);
	free(buf);
}

void create_go_quests(char *buffer, quests_list_t *quests_list)
{
	int i = 0;
	int j = 0;
	int size = my_strlen(buffer);

	quests_list->go_quests.name_place = malloc(sizeof(char) * size);
	for (i = 0; buffer[i] != '|'; i++);
	i++;
	for (j = 0; buffer[i] != '\0'; i++, j++)
		quests_list->go_quests.name_place[j] = buffer[i];
	quests_list->go_quests.name_place[j] = '\0';
}

void create_speak_quests(char *buffer, quests_list_t *quests_list)
{
	int i = 0;
	int j = 0;
	int size = my_strlen(buffer);

	quests_list->speak_quests.name_character = malloc(sizeof(char) * size);
	for (i = 0; buffer[i] != '|'; i++);
	i++;
	for (j = 0; buffer[i] != '\0'; i++, j++)
		quests_list->speak_quests.name_character[j] = buffer[i];
	quests_list->speak_quests.name_character[j] = '\0';
}
