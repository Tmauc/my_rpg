/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

int launch_cust_menu_sex(st_rpg *s)
{
	if (s->cust.option == 0)
		return (cust_menu_backto_main(s));
	else {
		if (s->cust.option == 1)
			s->cust.cdata.sex = 0;
		else
			s->cust.cdata.sex = 1;
		cust_menu_togo_name(s);
	}
	return (0);
}

int launch_cust_menu_classes(st_rpg *s)
{
	if (s->cust.option == 0)
		return (cust_menu_backto_main(s));
	else {
		s->cust.cdata.classe = s->cust.option - 1;
		create_player_from_cust(s);
		custom_destroy(s);
		create_player(s);
		s->inv.first_slot = NULL;
		return (prog(s));
	}
	return (0);
}

int launch_cust_menu_name(st_rpg *s)
{
	if (s->cust.option == 0)
		return (cust_menu_backto_main(s));
	else {
		if (s->cust.option == 1)
			cust_menu_togo_sex(s);
		else if (s->cust.option == 2)
			cust_menu_togo_classes(s);
	}
	return (0);
}

int which_cust_menu(st_rpg *s)
{
	if (s->cust.menu == 1)
		return (launch_cust_menu_sex(s));
	if (s->cust.menu == 2)
		return (launch_cust_menu_name(s));
	if (s->cust.menu == 3)
		return (launch_cust_menu_classes(s));
	return (0);
}

int custom_launch(st_rpg *s, sfEvent event)
{
	if ((event.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyE)
	|| sfKeyboard_isKeyPressed(sfKeyReturn)))
	|| cust_left_clicked(s, event)) {
		if (which_cust_menu(s))
			return (1);
	}
	return (0);
}
