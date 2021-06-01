/*
** EPITECH PROJECT, 2018
** get_quests_rewards.c
** File description:
** description
*/

#include "my.h"
#include "game_map.h"

int take_size(char *objects_buffer)
{
	int nbr_object = 1;

	for (int i = 0; objects_buffer[i] != '\0'; i++) {
		if (objects_buffer[i] == '|')
			nbr_object++;
	}
	return (nbr_object);
}

int take_big_size(char *objects_buffer)
{
	int size_word = 0;
	int presize = 0;

	for (int i = 0; objects_buffer[i] != '\0'; i++, size_word++) {
		if (objects_buffer[i] == '|' && size_word > presize)
			presize = size_word;
		if (objects_buffer[i] == '|')
			size_word = 0;
	}
	return (presize);
}

char **get_objects(char *objects_buffer, int x, int y)
{
	char **objects;
	int nbr_object = take_size(objects_buffer);
	int presize = take_big_size(objects_buffer);

	objects = malloc(sizeof(char *) * nbr_object + 8);
	objects[0] = malloc(sizeof(char) * presize + 10);
	for (int i = 0; objects_buffer[i] != '\0'; i++) {
		if (objects_buffer[i] != '|') {
			objects[y][x] = objects_buffer[i];
			x++;
		} else {
			objects[y][x] = '\0';
			x = 0;
			y++;
			objects[y] = malloc(sizeof(char) * presize + 10);
		}
	}
	objects[y][x] = '\0';
	objects[y + 1] = NULL;
	return (objects);
}

void get_money_xp(int size, char *buffer, int i, quests_t *quests)
{
	int x = 0;
	char *buf_money = malloc(sizeof(char) * size);
	char *buf_xp = malloc(sizeof(char) * size);

	for (; buffer[i] != '|'; i++, x++) {
		buf_money[x] = buffer[i];
	}
	buf_money[x] = '\0';
	quests->rewards.money = str_to_int(buf_money);
	i++;
	for (x = 0; buffer[i] != '\0'; i++, x++) {
		buf_xp[x] = buffer[i];
	}
	buf_xp[x] = '\0';
	quests->rewards.xp = str_to_int(buf_xp);
	free(buf_money);
	free(buf_xp);
}

void get_rewards(char *buffer, quests_t *quests)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int size = my_strlen(buffer);
	char *buf = malloc(sizeof(char) * size);

	for (i = 0; buffer[i + 1] < 48 || buffer[i + 1] > 57; i++) {
		buf[i] = buffer[i];
	}
	buf[i++] = '\0';
	quests->rewards.objects = get_objects(buf, x, y);
	get_money_xp(size, buffer, i, quests);
	free(buf);
}
