/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_dmg_show(st_rpg *s)
{
	s->f.cdmg = 0;
	for (int i = 0; i != 50; i += 1) {
		s->f.dmgshot[i] = 0;
		s->f.dmg[i] = create_text("dmg", (sfVector2f){0, 0},
		"ressources/fonts/bars.otf");
		sfText_setCharacterSize(s->f.dmg[i]->text, 12);
	}
}

void destroy_dmg_show(st_rpg *s)
{
	for (int i = 0; i != 50; i += 1)
		destroy_text(s->f.dmg[i]);
}

void launch_dmg_show(st_rpg *s, float amount, g_object *obj)
{
	char *buffer = int_to_str((int)amount);
	sfVector2f pos = create_vector2f(obj->pos.x + rand() % obj->rect.width
	- 20, obj->pos.y - 20);

	sfText_setString(s->f.dmg[s->f.cdmg]->text, my_strdup(buffer));
	sfText_setPosition(s->f.dmg[s->f.cdmg]->text, pos);
	s->f.dmgshot[s->f.cdmg] = 1;
	s->f.cdmg += 1;
	if (s->f.cdmg == 50)
		s->f.cdmg = 0;
	free(buffer);
}

void update_dmg_show(st_rpg *s)
{
	for (int i = 0; i != 50; i += 1) {
		if (s->f.dmgshot[i] != 0) {
			sfText_setPosition(s->f.dmg[i]->text,
			(sfVector2f){sfText_getPosition(s->f.dmg[i]->text).x,
				sfText_getPosition(s->f.dmg[i]->text).y - 1});
			s->f.dmgshot[i] += 1;
		} if (s->f.dmgshot[i] > 50)
			s->f.dmgshot[i] = 0;
	}
}

void display_dmg_show(st_rpg *s)
{
	for (int i = 49; i != -1; i -= 1) {
		if (s->f.dmgshot[i] != 0)
			sfRenderWindow_drawText(s->window,
			s->f.dmg[i]->text, NULL);
	}
}
