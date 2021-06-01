/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void destroy_particle(particle_t *part)
{
	free(part);
}

void display_particle(particle_t *part, sfRenderWindow *window)
{
	sfRenderWindow_drawPrimitives(window, part->vertex, part->size * 4,
	sfQuads, NULL);
}

void set_particle(particle_t *part, uint id, sfVector2f pos, sfColor color)
{
	part->vertex[(id * 4) + 0].position = (sfVector2f){pos.x + 0,
		pos.y + 0};
	part->vertex[(id * 4) + 1].position = (sfVector2f){pos.x +
		part->info->size.x, pos.y + 0};
	part->vertex[(id * 4) + 2].position = (sfVector2f){pos.x +
		part->info->size.x, pos.y + part->info->size.y};
	part->vertex[(id * 4) + 3].position = (sfVector2f){pos.x + 0,
		pos.y + part->info->size.y};
	part->info[id].life = part->info[id].lsave;
	for (int cnt = 0; cnt != 4; cnt++)
		part->vertex[(id * 4) + cnt].color = color;
}

void launch_particle(particle_t *part, sfVector2f pos, float angle)
{
	float value;

	for (uint id = 0; id < part->size; id += 1) {
		set_particle(part, id, pos,
		(sfColor){part->info->r.x + rand() % part->info->r.y,
			part->info->g.x + rand() % part->info->g.y,
			part->info->b.x + rand() % part->info->b.y,
			part->info->a});
		if (part->info[id].angle != 0)
			part->info[id].ratios = get_ratios(angle +
			rand() % (int)part->info[id].angle -
			part->info[id].angle / 2);
		else
			part->info[id].ratios = get_ratios(angle);
		value = rand() % part->info[id].rands;
		part->info[id].ratios.x = part->info[id].ratios.x *
		(part->info[id].speed + value);
		part->info[id].ratios.y = part->info[id].ratios.y *
		(part->info[id].speed + value);
	}
}

void update_particle(particle_t *part, float dt)
{
	for (uint id = 0; id < part->size; id += 1) {
		if (part->info[id].life >= 0)
			part->info[id].life -= dt;
		if (part->info[id].life <= 0) {
			memset(part->vertex + (id * 4), 0,
			sizeof(sfVertex) * 4);
			continue;
		}
		for (int i = 0; i != 4; i += 1) {
			part->vertex[(id * 4) + i].position.x +=
			part->info[id].ratios.x * dt;
			part->vertex[(id * 4) + i].position.y +=
			part->info[id].ratios.y * dt;
			part->vertex[(id * 4) + i].color.a -=
			part->info[id].fade;
		}
	}
}
