/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my_rpg.h"
#include "my.h"

void create_gunner_bullets(st_rpg *s)
{
	for (int i = 0; i != 10; i += 1) {
		s->f.gun.bullet[i] =
		create_projectile("ressources/proj/Bullet");
		if (s->player.tree.passive == 0)
			s->f.gun.bullet[i]->range += s->f.gun.bullet[i]
			->range * 0.3;
		else if (s->player.tree.passive == 2 && i == 9) {
			destroy_projectile(s->f.gun.bullet[i]);
			s->f.gun.bullet[i] =
			create_projectile("ressources/spells/1/xblt");
		}
		s->f.gun.ultb[i] =
		create_projectile("ressources/spells/1/ultBullet");
		s->f.gun.trait[i] =
		create_object("ressources/spells/1/trait.png",
		create_vector2f(0, 0), create_rect(0, 0, 0, 10), 0);
	}
}

void create_gunner_explosions(st_rpg *s)
{
	s->f.gun.explosion =
	create_anim(create_object("ressources/spells/1/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	sfSprite_setScale(s->f.gun.explosion->obj->sprite,
	create_vector2f(1.8, 1.8));
	s->f.gun.expbullet =
	create_anim(create_object("ressources/spells/1/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	s->f.gun.explo = create_circle(90, 0, sfTransparent);
	s->f.gun.expbt = create_circle(50, 0, sfTransparent);
	s->f.gun.partf = create_particle("ressources/particles/explosion");
	s->f.gun.partg = create_particle("ressources/particles/gunpan");
}

void create_gunner_second(st_rpg *s)
{
	s->f.gun.current = 0;
	s->f.gun.ultrat = create_vector2f(0, 0);
	s->f.gun.ult = 0;
	s->f.gun.autospeed = 0.15;
	s->f.gun.origin = s->f.gun.ultb[0]->dmg;
	s->f.gun.auto_a = 0;
	s->f.gun.blitz = create_projectile("ressources/proj/Blitz");
	s->f.gun.blitz->obj->rect = create_rect(0, 0, 40, 15);
	sfSprite_setTextureRect(s->f.gun.blitz->obj->sprite,
	s->f.gun.blitz->obj->rect);
	s->f.gun.t = create_st_time();
	s->f.gun.blitzt = create_st_time();
	s->f.gun.delay = 0.8;
	s->f.gun.grenade = create_projectile("ressources/proj/Grenade");
	s->f.gun.net = create_projectile("ressources/proj/Net");
	s->f.gun.grenadespeed = s->f.gun.grenade->obj->speed;
	s->f.gun.jump = create_dash(80, 1400);
}

void create_gunner_ults(st_rpg *s)
{
	s->f.gun.rush = create_effect("speed", s->player.obj->speed / 2, 3);
	for (int i = 0; i != 100; i += 1) {
		s->f.gun.flame[i] = create_projectile("ressources/proj/Flame");
		s->f.gun.flame[i]->obj->rect.height = 30;
		sfSprite_setTextureRect(s->f.gun.flame[i]->obj->sprite,
		s->f.gun.flame[i]->obj->rect);
	}
	s->f.gun.flamet = 0;
	s->f.gun.flamestay = 0;
	s->f.gun.cflame = 0;
	s->f.gun.cdiminution = s->f.gun.flame[0]->obj->speed;
	s->f.gun.boots =
	create_anim(create_object("ressources/spells/1/explosion.png",
	create_vector2f(0, 0), create_rect(0, 0, 100, 100), 0.2),
	create_vector2i(9, 9), 0.002);
	sfSprite_setScale(s->f.gun.boots->obj->sprite,
	create_vector2f(1.8, 1.8));
}

void create_gunner_sound(st_rpg *s)
{
	s->f.gun.l_click =
	sfMusic_createFromFile("ressources/audio/sound/unload.ogg");
	s->f.gun.s_explo =
	sfMusic_createFromFile("ressources/audio/sound/explosion.ogg");
	s->f.gun.zap =
	sfMusic_createFromFile("ressources/audio/sound/zap.ogg");
	s->f.gun.h_noon =
	sfMusic_createFromFile("ressources/audio/sound/h_noon.ogg");
	s->f.gun.s_flam =
	sfMusic_createFromFile("ressources/audio/sound/flam.ogg");
	s->f.gun.s_net =
	sfMusic_createFromFile("ressources/audio/sound/net.ogg");
	sfMusic_setVolume(s->f.gun.l_click, s->s_effect);
	sfMusic_setVolume(s->f.gun.s_explo, s->s_effect);
	sfMusic_setVolume(s->f.gun.zap, s->s_effect);
	sfMusic_setVolume(s->f.gun.h_noon, s->s_effect);
	sfMusic_setVolume(s->f.gun.s_flam, s->s_effect);
	sfMusic_setVolume(s->f.gun.s_net, s->s_effect);
}
