/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void generate_enemy_stat(enemy_t *enemy)
{
	enemy->cast = 0;
	enemy->stun = create_effect("stun", 0, 0);
	enemy->poison = create_effect("poison", 0, 0);
	enemy->animcol = 1;
	enemy->animsens = 1;
	enemy->aggro = 0;
	enemy->idle = 0;
	enemy->idlecount = 0;
	enemy->cdcount = 0;
	enemy->alive = 1;
	enemy->stat->pva = enemy->stat->pvm;
	enemy->ratios = create_vector2f(0, 0);
	enemy->life = create_object("ressources/images/interface/minibar.png",
	create_vector2f(enemy->obj->pos.x, enemy->obj->pos.y - 20),
	create_rect(0, 0, 50, 10), 0);
}

void generate_enemy_fight(enemy_t *enemy, int fd, char *buffer)
{
	buffer = get_next_line(fd);
	enemy->cd = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->stat->lvl = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->stat->pvm = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->stat->frc = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->stat->def = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->stat->vit = str_to_int(buffer);
	free(buffer);
	close(fd);
}

void generate_enemy_object(enemy_t *enemy, int fd, char *buffer)
{
	buffer = get_next_line(fd);
	enemy->type = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->spell1 = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->spell2 = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->scale.x = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->scale.y = str_to_int(buffer);
	free(buffer);
}

enemy_t *generate_enemy(char *str)
{
	int fd = open(str, O_RDONLY);
	enemy_t *enemy = malloc(sizeof(enemy_t));
	char *buffer = NULL;

	enemy->obj = create_object(get_next_line(fd), create_vector2f(0, 0),
	create_rect(0, 0, 0, 0), 0);
	buffer = get_next_line(fd);
	enemy->obj->rect.width = str_to_int(buffer);
	free(buffer);
	buffer = get_next_line(fd);
	enemy->obj->rect.height = str_to_int(buffer);
	free(buffer);
	enemy->stat = malloc(sizeof(stat_t));
	enemy->obj->rect.left = enemy->obj->rect.width;
	sfSprite_setTextureRect(enemy->obj->sprite, enemy->obj->rect);
	generate_enemy_object(enemy, fd, buffer);
	generate_enemy_fight(enemy, fd, buffer);
	generate_enemy_stat(enemy);
	return (enemy);
}
