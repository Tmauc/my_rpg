/*
** EPITECH PROJECT, 2018
** create_inv.c
** File description:
** file to stock all functions about creating inv on screen
*/

#include "my.h"
#include "my_rpg.h"

void create_inventory_screen(ing_inv_t *inv)
{
	inv->texture =
	sfTexture_createFromFile(
	"ressources/images/inventory/inventory.png", NULL);
	inv->sprite = sfSprite_create();
	inv->rect.width = 1500;
	inv->rect.height = 800;
	inv->rect.left = 0;
	inv->rect.top = 0;
	sfSprite_setTextureRect(inv->sprite, inv->rect);
	sfSprite_setTexture(inv->sprite, inv->texture, sfTrue);
}

item_t *create_first_slot(void)
{
	item_t *slot = malloc(sizeof(item_t));

	clear_inventory_slot(slot);
	slot->pos = 0;
	slot->next = NULL;
	return (slot);
}

void update_inventory_size(ing_inv_t *inv)
{
	item_t *current;

	while (current->next != NULL)
		current = current->next;
	if (current->pos + 1 < (signed)inv->size)
		for (unsigned int i = 0; i < inv->size - current->pos + 1; i++)
			add_inventory_slot(inv->first_slot);
}

void create_inventory_var(ing_inv_t *inv)
{
	inv->size = 53;
	if (inv->first_slot == NULL) {
		inv->first_slot = create_first_slot();
		for (unsigned int i = 0; i < inv->size; i++)
			add_inventory_slot(inv->first_slot);
	}
	inv->sheet = sfTexture_createFromFile(
	"ressources/images/inventory/item_sheet.png", NULL);
	inv->highlight = sfSprite_create();
	sfSprite_setTexture(inv->highlight, inv->sheet, sfTrue);
	sfSprite_setTextureRect(inv->highlight, (sfIntRect){0, 0, 115, 115});
	sfSprite_setColor(inv->highlight, (sfColor){255, 255, 255, 128});
	inv->selected_texture = sfTexture_createFromFile(
	"ressources/images/inventory/item_border.png", NULL);
	inv->selected = sfSprite_create();
	sfSprite_setTexture(inv->selected, inv->selected_texture, sfTrue);
	sfSprite_setTextureRect(inv->selected, (sfIntRect){0, 0, 130, 130});
}

void create_ingame_inventory(st_rpg *rpg)
{
	create_inventory_screen(&rpg->inv);
	create_inventory_var(&rpg->inv);
	create_armor_weapon_slot(rpg);
	create_fast_inventory_screen(&rpg->finv);
	create_fast_inventory_slots(rpg);
	create_fast_inventory_sprites(rpg);
	rpg->inv.use_item = 0;
	rpg->inv.is_open = 0;
	rpg->inv.focused = NULL;
	rpg->inv.resume = NULL;
	rpg->inv.inventory_font =
	sfFont_createFromFile("ressources/fonts/bars.otf");
}
