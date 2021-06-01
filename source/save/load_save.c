/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

char *get_save_path(st_rpg *s)
{
	char *tmp2;
	char *tmp;
	char *str;

	tmp2 = int_to_str(s->save);
	tmp = my_strcat("saves/", tmp2);
	free(tmp2);
	str = my_strcat(tmp, "/");
	free(tmp);
	return (str);
}

st_cdata load_cdata(char *path)
{
	st_cdata cdata;
	int fd = open(path, O_RDONLY);

	cdata.sex = str_to_int(get_next_line(fd));
	cdata.classe = str_to_int(get_next_line(fd));
	cdata.name = get_next_line(fd);
	cdata.quest = str_to_int(get_next_line(fd));
	close(fd);
	return (cdata);
}

void load_save(st_rpg *s)
{
	char *path = get_save_path(s);
	char *tmp = my_strcat(path, "stat");

	s->player.stat = load_stat(tmp);
	free(tmp);
	tmp = my_strcat(path, "cust");
	s->player.cdata = load_cdata(tmp);
	free(tmp);
	tmp = my_strcat(path, "tree");
	load_tree(s, tmp);
	load_inventory(s);
	free(tmp);
	free(path);
}
