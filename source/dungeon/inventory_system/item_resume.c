/*
** EPITECH PROJECT, 2018
** item_resume.c
** File description:
** file to stock all functions about drawing resume of an item
*/

#include "my.h"
#include "my_rpg.h"

char *read_entire_resume(char *path)
{
	int fd = open(path, O_RDONLY);
	char *result = my_calloc(sizeof(char) * (1024));

	read(fd, result, 1024);
	return (result);
}

void create_resume(st_rpg *rpg)
{
	char *resume_file;
	char *temp_id = int_to_str(rpg->inv.focused->id);
	char *path = my_strcat("ressources/resumes/", temp_id);

	if (rpg->inv.focused != NULL)
		sfText_destroy(rpg->inv.resume);
	resume_file = read_entire_resume(path);
	free(temp_id);
	free(path);
	rpg->inv.resume = sfText_create();
	sfText_setFont(rpg->inv.resume, rpg->inv.inventory_font);
	sfText_setCharacterSize(rpg->inv.resume, 15);
	sfText_setString(rpg->inv.resume, resume_file);
	rpg->inv.drawed = 1;
	free(resume_file);
}

void draw_resume_item(st_rpg *rpg)
{
	float x_res = rpg->player.obj->pos.x + 375.5;
	float y_res = rpg->player.obj->pos.y + 10.5;

	if (rpg->inv.focused != NULL && rpg->inv.focused->id < 1)
		return;
	if (rpg->inv.focused != NULL && rpg->inv.drawed == 0)
		create_resume(rpg);
	sfText_setPosition(rpg->inv.resume, (sfVector2f){x_res, y_res});
	sfRenderWindow_drawText(rpg->window, rpg->inv.resume, NULL);
}
