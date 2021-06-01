/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void get_particle_extra(particle_t *part, int fd, char *buffer)
{
	buffer = get_next_line(fd);
	part->info[0].a = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].angle = (float)str_to_int(buffer);
	free(buffer);
}

void get_particle_color(particle_t *part, int fd, char *buffer)
{
	buffer = get_next_line(fd);
	part->info[0].r.x = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].r.y = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].g.x = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].g.y = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].b.x = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].b.y = str_to_int(buffer);
	free(buffer);
	get_particle_extra(part, fd, buffer);
}

void get_particle_info(particle_t *part, int fd, char *buffer)
{
	buffer = get_next_line(fd);
	part->info[0].size.x = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].size.y = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].speed = (float)str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].rands = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	part->info[0].lsave = (float)str_to_int(buffer) / 100;
	free(buffer);
	part->info[0].life = 0;
	buffer = get_next_line(fd);
	part->info[0].fade = (float)str_to_int(buffer);
	free(buffer);
	get_particle_color(part, fd, buffer);
}

void copy_particle(particle_t *part, uint id)
{
	part->info[id].size.x = part->info[0].size.x;
	part->info[id].size.y = part->info[0].size.y;
	part->info[id].speed = part->info[0].speed;
	part->info[id].rands = part->info[0].rands;
	part->info[id].lsave = part->info[0].lsave;
	part->info[id].life = 0;
	part->info[id].fade = part->info[0].fade;
	part->info[id].r.x = part->info[0].r.x;
	part->info[id].r.y = part->info[0].r.y;
	part->info[id].g.x = part->info[0].g.x;
	part->info[id].g.y = part->info[0].g.y;
	part->info[id].b.x = part->info[0].b.x;
	part->info[id].b.y = part->info[0].b.y;
	part->info[id].a = part->info[0].a;
	part->info[id].angle = part->info[0].angle;
}

particle_t *create_particle(char *str)
{
	int fd = open(str, O_RDONLY);
	char *buffer = get_next_line(fd);
	int size = str_to_int(buffer);
	particle_t *part;
	const size_t size_m = (sizeof(particle_t) + sizeof(sfVertex) * size * 4
	+ sizeof(infopart_t) * size);
	void *ptn = malloc(size_m);

	free(buffer);
	if (ptn == NULL)
		return (NULL);
	memset(ptn, 0, size_m);
	part = (particle_t *)(ptn);
	part->size = size;
	part->vertex = (sfVertex *)(ptn + sizeof(particle_t));
	part->info = (infopart_t *)(part->vertex + (size * 4));
	get_particle_info(part, fd, buffer);
	for (uint i = 0; i < part->size; i += 1)
		copy_particle(part, i);
	close(fd);
	return (part);
}
