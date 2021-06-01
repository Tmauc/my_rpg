/*
** EPITECH PROJECT, 2018
** draw_items_finventory.c
** File description:
** draw item on fast inventory
*/

#include "my.h"
#include "my_rpg.h"

void verify_destroy_sprites_finv(st_rpg *rpg)
{
	if (rpg->finv.item_spr[0] != NULL && rpg->finv.slots[0] == NULL) {
		sfSprite_destroy(rpg->finv.item_spr[0]);
		rpg->finv.item_spr[0] = NULL;
	} if (rpg->finv.item_spr[1] != NULL && rpg->finv.slots[1] == NULL) {
		sfSprite_destroy(rpg->finv.item_spr[1]);
		rpg->finv.item_spr[1] = NULL;
	} if (rpg->finv.item_spr[2] != NULL && rpg->finv.slots[2] == NULL) {
		sfSprite_destroy(rpg->finv.item_spr[2]);
		rpg->finv.item_spr[2] = NULL;
	}
}

void verify_sprites_finv(st_rpg *rpg)
{
	if (rpg->finv.item_spr[0] == NULL && rpg->finv.slots[0] != NULL) {
		rpg->finv.item_spr[0] =
		sfSprite_copy(rpg->finv.slots[0]->sprite);
		sfSprite_setScale(rpg->finv.item_spr[0],
		(sfVector2f){0.5, 0.5});
	} if (rpg->finv.item_spr[1] == NULL && rpg->finv.slots[1] != NULL) {
		rpg->finv.item_spr[1] =
		sfSprite_copy(rpg->finv.slots[1]->sprite);
		sfSprite_setScale(rpg->finv.item_spr[1],
		(sfVector2f){0.5, 0.5});
	} if (rpg->finv.item_spr[2] == NULL && rpg->finv.slots[2] != NULL) {
		rpg->finv.item_spr[2] =
		sfSprite_copy(rpg->finv.slots[2]->sprite);
		sfSprite_setScale(rpg->finv.item_spr[2],
		(sfVector2f){0.5, 0.5});
	}
}

void draw_items_fast_inventory(st_rpg *rpg)
{
	sfVector2f i_pos = {rpg->finv.created_pos.x + rpg->player.obj->pos.x,
		rpg->finv.created_pos.y + rpg->player.obj->pos.y};

	verify_sprites_finv(rpg);
	if (rpg->finv.item_spr[0] != NULL) {
		sfSprite_setPosition(rpg->finv.item_spr[0],
		(sfVector2f){i_pos.x, i_pos.y});
		sfRenderWindow_drawSprite(rpg->window,
		rpg->finv.item_spr[0], NULL);
	} if (rpg->finv.item_spr[1] != NULL) {
		sfSprite_setPosition(rpg->finv.item_spr[1],
		(sfVector2f){i_pos.x, i_pos.y});
		sfRenderWindow_drawSprite(rpg->window,
		rpg->finv.item_spr[1], NULL);
	} if (rpg->finv.item_spr[2] != NULL) {
		sfSprite_setPosition(rpg->finv.item_spr[2],
		(sfVector2f){i_pos.x, i_pos.y});
		sfRenderWindow_drawSprite(rpg->window,
		rpg->finv.item_spr[2], NULL);
	}
	verify_destroy_sprites_finv(rpg);
}
