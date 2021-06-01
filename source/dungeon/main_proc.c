/*
** EPITECH PROJECT, 2018
** main_proc.c
** File description:
** main_proc file for procedural gen
*/

#include "my.h"
#include "my_rpg.h"

int launch_dungeon(st_rpg *rpg, void (*function_pvar)(proc_var_t *))
{
	rpg->fi->map_status = 1;
	function_pvar(&rpg->proc.pvar);
	create_dungeon_loop(rpg);
	return (dungeon_loop(rpg));
}
