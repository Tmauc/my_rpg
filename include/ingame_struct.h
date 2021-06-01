/*
** EPITECH PROJECT, 2018
** ingame_struct.h
** File description:
** file to stock all struct about game
*/

#ifndef ING_STRUCT_H_
#define ING_STRUCT_H_

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

//INVENTORY
typedef struct inventory_item
{
	unsigned int id;
	unsigned int stacks;
	int pos;
	sfText *show_stacks;
	sfText *description;
	sfSprite *sprite;
	struct inventory_item *next;
} item_t;

typedef struct fast_inventory
{
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f created_pos;
	int created;
	item_t *slots[3];
	sfTexture *txr_slots[3];
	sfSprite *spr[3];
	sfSprite *item_spr[3];
	int focused_slot;
	int mouse_released;
} ing_finv_t;

typedef struct ingame_inventory_manager
{
	sfSprite *sprite;
	sfSprite *highlight;
	sfSprite *selected;
	sfTexture *selected_texture;
	sfTexture *texture;
	sfTexture *sheet;
	sfIntRect rect;
	sfFont *inventory_font;
	unsigned int size;
	item_t *first_slot;
	item_t *focused;
	sfText *resume;
	int drawed;
	item_t *armor;
	item_t *weapon;
	int is_open;
	int use_item;
	unsigned int money;
} ing_inv_t;

#endif
