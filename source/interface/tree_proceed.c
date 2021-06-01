/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game file for my_rpg
*/

#include "my_rpg.h"
#include "my.h"

void reset_sp(st_rpg *s)
{
	char *temp;

	destroy_text(s->treem.skillp);
	temp = int_to_str(s->player.tree.skillp);
	s->treem.skillp = create_text(my_strcat("SP : ", temp),
	create_vector2f(s->origin.x + 1720, s->origin.y + 45),
	"ressources/fonts/button.ttf");
	free(temp);
}

int get_price(int lock)
{
	int price = lock / 3 + 2;

	if (lock > 6)
		price = (lock - 6) / 2 + 4;
	return (price);
}

char *unlock_line_price(int lock)
{
	char *tmp;
	char *tmp2;

	tmp = int_to_str(get_price(lock));
	tmp2 = my_strcat("Locked : Price ", tmp);
	free(tmp);
	tmp = my_strcat(tmp2, " SP");
	free(tmp2);
	return (tmp);
}

void select_spell(st_rpg *s, int lock)
{
	sfText_setString(s->treem.sp[2]->text, "Unlocked");
	sfText_setColor(s->treem.sp[2]->text, sfGreen);
	if (lock >= 0 && lock <= 2)
		s->player.tree.passive = lock;
	if (lock >= 3 && lock <= 5)
		s->player.tree.spell1 = lock - 3;
	if (lock == 6 || lock == 7)
		s->player.tree.spell2 = lock - 6;
	if (lock == 8 || lock == 9)
		s->player.tree.spell3 = lock - 8;
}

void tree_proceed(st_rpg *s, int lock)
{
	sfText_setString(s->treem.sp[0]->text, s->treem.spells[lock * 2]);
	sfText_setString(s->treem.sp[1]->text, s->treem.spells[lock * 2 + 1]);
	if (s->treem.status == lock && s->player.tree.lock[lock] &&
	s->player.tree.skillp >= get_price(lock)) {
		s->player.tree.lock[lock] = 0;
		s->player.tree.skillp -= get_price(lock);
		reset_sp(s);
		select_spell(s, lock);
	} else if (s->player.tree.lock[lock]) {
		s->treem.status = lock;
		sfText_setString(s->treem.sp[2]->text, unlock_line_price(lock));
		sfText_setColor(s->treem.sp[2]->text, sfRed);
	} else {
		select_spell(s, lock);
		s->treem.status = lock;
	}
}
