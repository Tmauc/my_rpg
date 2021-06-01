/*
** EPITECH PROJECT, 2018
** collision_id.c
** File description:
** collision_id.c file for my_rpg
*/

#include "my.h"
#include "game_map.h"

int case_tp(st_rpg *s, int nb_ID)
{
	switch (s->fi->map.layer_relief[nb_ID]) {
	case 314:
		tp_bridge(s);
		return (1);
	case 93:
		tp_bridge2(s);
		return (1);
	case 25:
		tp_orphanage(s);
		return (1);
	case 26:
		tp_village(s);
		return (1);
	case 57:
		tp_inside4(s);
		return (1);
	case 91:
		tp_bedroom(s);
		return (1);
	case 121:
		tp_bedroom2(s);
		return (1);
	case 123:
		tp_bedroom3(s);
		return (1);
	case 88:
		tp_cook1(s);
		return (1);
	case 92:
		tp_corridor1(s);
		return (1);
	case 120:
		tp_corridor2(s);
		return (1);
	case 122:
		tp_corridor3(s);
		return (1);
	case 56:
		tp_outside4(s);
		return (1);
	case 87:
		tp_cook2(s);
		return (1);
	case 119:
		tp_inside2(s);
		return (1);
	case 118:
		tp_outside2(s);
		return (1);
	case 150:
		tp_inside3(s);
		return (1);
	case 149:
		tp_outside3(s);
		return (1);
	case 151:
		tp_inside1(s);
		return (1);
	case 152:
		tp_outside1(s);
		return (1);
	default:
		return (0);
		break;
	}
	return (0);
}

int case_id(st_rpg *s, int nb_ID)
{
	switch (s->fi->map.layer_colID[nb_ID]) {
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 42:
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
	case 50:
	case 51:
	case 63:
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 73:
	case 74:
	case 75:
	case 76:
	case 77:
	case 78:
	case 79:
	case 80:
	case 81:
	case 82:
	case 156:
	case 157:
	case 158:
	case 159:
	case 168:
	case 169:
	case 170:
	case 171:
	case 173:
	case 174:
	case 175:
	case 176:
	case 177:
	case 178:
	case 187:
	case 188:
	case 189:
	case 190:
	case 199:
	case 200:
	case 201:
	case 202:
	case 204:
	case 205:
	case 206:
	case 207:
	case 208:
	case 209:
		return (1);
		break;
	default:
		return (0);
		break;
	}
}
