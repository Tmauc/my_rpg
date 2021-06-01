/*
** EPITECH PROJECT, 2018
** create_items_on_ground.c
** File description:
** file to stock all functions about creating items on ground during loading
*/

#include "my.h"
#include "my_rpg.h"

gitem_t *create_gritem(st_rpg *rpg, unsigned int id, int x, int y)
{
	gitem_t *new = malloc(sizeof(gitem_t));
	int left = 115 * (id % 10);
	int top = 115 * (id / 10);

	new->next = NULL;
	new->id = id;
	new->sprite = sfSprite_create();
	sfSprite_setTexture(new->sprite, rpg->inv.sheet, sfTrue);
	sfSprite_setTextureRect(new->sprite, (sfIntRect){left, top, 115, 115});
	new->pos.x = (x + 2) * 96;
	new->pos.y = (y + 2) * 96;
	sfSprite_setPosition(new->sprite, new->pos);
	sfSprite_setScale(new->sprite, (sfVector2f){0.84, 0.84});
	return (new);
}

int rand_item_ground(void)
{
	if (rand() % 4 == 0)
		return (rand() % 3 + 2);
	if (rand() % 8 == 0)
		return (5);
	if (rand() % 10 == 0)
		return (6);
	if (rand() % 18 == 0)
		return (7);
	return (-1);
}

void verif_block_creating(st_rpg *rpg, proom_t *proom, int y, gitem_t **crt)
{
	int result;
	int prev;
	int cx;
	int cy = proom->pos1[1] + y;

	for (int x = 1; x < proom->width - 1; x++) {
		cx = proom->pos1[0] + x;
		if ((prev = rand_item_ground()) == -1)
			continue;
		if ((result = rand() % 32) == 0 &&
		rpg->proc.first_gritem == NULL) {
			rpg->proc.first_gritem =
			create_gritem(rpg, prev, cx, cy);
			*crt = rpg->proc.first_gritem;
		} else if (result == 0) {
			(*crt)->next = create_gritem(rpg, prev, cx, cy);
			*crt = (*crt)->next;
		}
	}
}

void destroy_items_list(st_rpg *rpg)
{
	gitem_t *last = NULL;
	gitem_t *crt = rpg->proc.first_gritem;

	while (crt != NULL) {
		sfSprite_destroy(crt->sprite);
		last = crt->next;
		free(crt);
		crt = last;
	}
	rpg->proc.first_gritem = NULL;
}

void create_items_list(st_rpg *rpg)
{
	gitem_t *crt;

	rpg->proc.first_gritem = NULL;
	for (int i = 0; rpg->proc.proom[i].last != 1; i++) {
		for (int y = 1; y < rpg->proc.proom[i].height - 1; y++)
			verif_block_creating(rpg, &rpg->proc.proom[i], y, &crt);
	}
}
