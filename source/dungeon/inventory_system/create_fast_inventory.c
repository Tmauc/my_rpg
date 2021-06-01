/*
** EPITECH PROJECT, 2018
** create_fast_inventory.c
** File description:
** file to stock all functions about creating fast inv
*/

#include "my.h"
#include "my_rpg.h"

void destroy_texture_finv(st_rpg *rpg)
{
	sfTexture_destroy(rpg->finv.txr_slots[0]);
	sfTexture_destroy(rpg->finv.txr_slots[1]);
	sfTexture_destroy(rpg->finv.txr_slots[2]);
}

void destory_fast_inventory(st_rpg *rpg)
{
	if (rpg->finv.spr[0] != NULL)
		sfSprite_destroy(rpg->finv.spr[0]);
	if (rpg->finv.spr[1] != NULL)
		sfSprite_destroy(rpg->finv.spr[1]);
	if (rpg->finv.spr[2] != NULL)
		sfSprite_destroy(rpg->finv.spr[2]);
	if (rpg->finv.item_spr[0] != NULL)
		sfSprite_destroy(rpg->finv.item_spr[0]);
	if (rpg->finv.item_spr[1] != NULL)
		sfSprite_destroy(rpg->finv.item_spr[1]);
	if (rpg->finv.item_spr[2] != NULL)
		sfSprite_destroy(rpg->finv.item_spr[2]);
	destroy_texture_finv(rpg);
}

void create_fast_inventory_screen(ing_finv_t *finv)
{
	finv->rect.width = 230;
	finv->rect.height = 230;
	finv->rect.left = 0;
	finv->rect.top = 0;
	finv->sprite = sfSprite_create();
	finv->texture =
	sfTexture_createFromFile(
	"ressources/images/inventory/fast_inv.png", NULL);
	sfSprite_setTexture(finv->sprite, finv->texture, sfTrue);
	sfSprite_setTextureRect(finv->sprite, finv->rect);
}

void create_fast_inventory_sprites(st_rpg *rpg)
{
	rpg->finv.txr_slots[0] = sfTexture_createFromFile(
	"ressources/images/inventory/sel_2_fast_inv.png", NULL);
	rpg->finv.txr_slots[1] = sfTexture_createFromFile(
	"ressources/images/inventory/sel_3_fast_inv.png", NULL);
	rpg->finv.txr_slots[2] = sfTexture_createFromFile(
	"ressources/images/inventory/sel_1_fast_inv.png", NULL);
	rpg->finv.spr[0] = sfSprite_create();
	rpg->finv.spr[1] = sfSprite_create();
	rpg->finv.spr[2] = sfSprite_create();
	sfSprite_setTexture(rpg->finv.spr[0],
	rpg->finv.txr_slots[0], sfTrue);
	sfSprite_setTexture(rpg->finv.spr[1],
	rpg->finv.txr_slots[1], sfTrue);
	sfSprite_setTexture(rpg->finv.spr[2],
	rpg->finv.txr_slots[2], sfTrue);
	for (int i = 0; i < 3; i++) {
		sfSprite_setColor(rpg->finv.spr[i],
		(sfColor){255, 255, 255, 128});
	}
}

void create_fast_inventory_slots(st_rpg *rpg)
{
	rpg->finv.slots[0] = NULL;
	rpg->finv.slots[1] = NULL;
	rpg->finv.slots[2] = NULL;
	rpg->finv.item_spr[0] = NULL;
	rpg->finv.item_spr[1] = NULL;
	rpg->finv.item_spr[2] = NULL;
	rpg->finv.focused_slot = -1;
	rpg->finv.mouse_released = 0;
}
