/*
** EPITECH PROJECT, 2018
** create_weapon_armor.c
** File description:
** file to stock all functions about creating weapon and armor
*/

#include "my.h"
#include "my_rpg.h"

void draw_armor_weapon_slot(st_rpg *rpg)
{
	sfVector2f armor_pos = {rpg->player.obj->pos.x + WIDTH / 4.12,
		rpg->player.obj->pos.y - HEIGHT / 6};
	sfVector2f weapon_pos = {rpg->player.obj->pos.x + WIDTH / 4.12,
		rpg->player.obj->pos.y - HEIGHT / 3};

	if (rpg->inv.armor->sprite == NULL)
		create_item_sprite(rpg, rpg->inv.armor);
	if (rpg->inv.weapon->sprite == NULL)
		create_item_sprite(rpg, rpg->inv.weapon);
	sfSprite_setPosition(rpg->inv.armor->sprite, weapon_pos);
	sfSprite_setPosition(rpg->inv.weapon->sprite, armor_pos);
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.armor->sprite, NULL);
	sfRenderWindow_drawSprite(rpg->window, rpg->inv.weapon->sprite, NULL);
}

void create_armor_weapon_slot(st_rpg *rpg)
{
	rpg->inv.armor = create_first_slot();
	rpg->inv.armor->pos = -1;
	rpg->inv.weapon = create_first_slot();
	rpg->inv.weapon->pos = -2;
}
