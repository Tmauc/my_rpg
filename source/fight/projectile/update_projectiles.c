/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void update_projectile_archer(st_rpg *s, float dt)
{
	for (int i = 0; i != 20; i += 1)
		update_projectile(s->f.arc.arrow[i], dt);
}

void update_projectile_gunner(st_rpg *s, float dt)
{
	for (int i = 0; i != 100; i += 1)
		update_projectile(s->f.gun.flame[i], dt);
	for (int i = 0; i != 10; i += 1) {
		update_projectile(s->f.gun.bullet[i], dt);
		update_projectile(s->f.gun.ultb[i], dt);
	}
	update_projectile(s->f.gun.blitz, dt);
	update_projectile(s->f.gun.net, dt);
	gunner_update_grenade(s, dt);
}

void update_projectile_rogue(st_rpg *s, float dt)
{
	for (int i = 0; i != 30; i += 1)
		update_projectile(s->f.rog.dagger[i], dt);
	update_projectile(s->f.rog.dance, dt);
}

void update_projectile_warrior(st_rpg *s, float dt)
{
	warrior_update_hasagi(s, dt);
}

void update_projectiles(st_rpg *s, float dt)
{
	void (*list[4])(st_rpg *s, float dt) = {update_projectile_archer,
		update_projectile_gunner, update_projectile_rogue,
		update_projectile_warrior};

	(list[s->player.cdata.classe])(s, dt);
}
