/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** structurates
*/

#ifndef ST_RPG_
#define ST_RPG_
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#include "particle.h"
#include "game_object.h"
#include "projectile.h"
#include "ingame_struct.h"
#include "procedural_struct.h"

#define WIDTH (1920)
#define HEIGHT (1080)

typedef struct struct_music
{
	sfMusic *music;
	int volume;
} st_music;

typedef struct s_shader
{
	sfShader *shader;
	sfRenderStates state;
	st_time time;
} shader_t;

typedef struct struct_button
{
	t_object *text;
	g_object *obj;
} st_button;

typedef struct s_clock
{
	sfClock *clock;
	sfTime tmp;
	float seconds;
} clockz_t;

typedef struct s_pnj
{
	char *name;
	st_button *name_box;
	st_button *dialog_box;
	g_object *pnj;
	g_object *choice_box_edge[2];
	g_object *cursor;
	st_button **choice_box;
} pnj_t;

typedef struct s_pos
{
	int x;
	int y;
} pos_t;

typedef struct s_map
{
	int x;
	int x2;
	int y;
	int **tab_tileset;
	int *layer_background;
	int *layer_relief;
	int *layer_col;
	int *layer_colID;
	int *layer_prof;
	sfImage *image;
	sfImage *map_backgound;
	sfImage *map_relief;
	sfImage *map_col;
	sfImage *map_colID;
	sfImage *map_prof;
	sfSprite *sprite;
	sfTexture *texture;
	sfSprite *sprite2;
	sfTexture *texture2;
	sfSprite *sprite3;
	sfTexture *texture3;
	sfSprite *sprite4;
	sfTexture *texture4;
	sfSprite *sprite5;
	sfTexture *texture5;
	sfIntRect square;
	sfColor color;
} map_t;

typedef struct s_rewards
{
	char **objects;
	int money;
	int xp;
} rewards_t;

typedef struct s_farm_quests
{
	char *name_item;
	int nbr_item;
} farm_quests_t;

typedef struct s_kill_quests
{
	char *name_kill;
	int nbr_kill;
} kill_quests_t;

typedef struct s_go_quests
{
	char *name_place;
} go_quests_t;

typedef struct s_speak_quests
{
	char *name_character;
} speak_quests_t;

typedef struct s_quests_list
{
	int type;
	farm_quests_t farm_quests;
	kill_quests_t kill_quests;
	go_quests_t go_quests;
	speak_quests_t speak_quests;
	struct s_quests_list *next;
} quests_list_t;

typedef struct s_quests
{
	char *title;
	char *path;
	int nbr_quests;
	int status;
	int status_text;
	rewards_t rewards;
	quests_list_t *quests_list;
} quests_t;

typedef struct s_colsquare
{
	pos_t pos;
	int width;
	int height;
} colsquare_t;

typedef struct s_quests_box
{
	int nb_quests;
	int status;
	st_button *quests_box;
	st_button *quests_des;
} quests_box_t;

typedef struct s_colcircle
{
	int rayon_circle;
	int center_circle_x;
	int center_circle_y;
} colcircle_t;

typedef struct s_files
{
	shader_t shader;
	shader_t shade_white;
	int direction;
	int nbr_colcircle;
	int nbr_colsquare;
	int camera_pos;
	int dialog_box_isopen;
	int nb_pnj;
	int max_pnj;
	int choice_cursor;
	int var_choice;
	int nb_choice_pre;
	int loading_timer;
	int pre_var;
	int relief;
	int return_value;
	float var_for_quests;
	int pnj_shade;
	int oui;
	int size_name_pnj;
	int num_dungeon;
	int map_status;
	int zach_status;
	int samy_status;
	int dream_status;
	int son_status;
	int samy_boss_status;
	int boss_status;
	int boss_ly_status;
	int final_status;
	int begin_status;
	st_button **name_head;
	g_object *name_head_edge[2];
	g_object *lake;
	sfClock *clock;
	sfView *view;
	quests_t **quests;
	sfVector2f last_pos;
	sfVector2i nbr_frame;
	sfVector2f acceleration;
	g_object *ID_character;
	g_object *loading;
	t_object *text_finish_quests;
	quests_box_t quests_box;
	sfVector2f camera;
	sfVector2f camera_prec;
	sfVector2f speed;
	sfVector2f velocity;
	sfVector2f invers;
	sfVector2f maxspeed;
	sfVector2f vect_ID_player;
	pnj_t pnj[18];
	pos_t pos[10];
	colcircle_t colcircle[42];
	colsquare_t colsquare[479];
	map_t map;
	clockz_t time;
	clockz_t lake_clock;
	clockz_t pnj_clock;
	st_music music;
	st_music samys_music;
	st_music reflexion_music;
	st_music samy_boss;
	st_music boss_music;
} files_t;

typedef struct struct_animation
{
	int height;
	int width;
	int c;
	int li;
	g_object *obj;
	st_time t;
	int hor;
	int ver;
	float speed;
} st_anim;

typedef struct custom_data
{
	int sex;
	char *name;
	int classe;
	int quest;
} st_cdata;

typedef struct struct_st_custom
{
	st_cdata cdata;
	int option;
	float sens;
	int menu;
	float rot;
	int cmin;
	int cmax;
	int pos;
	int chosen;
	g_object *face;
	g_object *cursor;
	st_button *bt[5];
	g_object *circle;
	g_object *back;
} st_custom;

typedef struct aoe
{
	sfCircleShape *circle;
	int shot;
	st_anim *anim;
	char *effect;
	float dmg;
	float dmgratio;
	float duration;
	float count;
} aoe_t;

typedef struct effect
{
	float duration;
	float count;
	char *type;
	int amount;
} effect_t;

typedef struct struct_dash
{
	float speed;
	int on;
	sfVector2f ratios;
	float range;
	float count;
} dash_t;

typedef struct struct_stat_entity
{
	int pvm;
	int pva;
	int frc;
	int def;
	int prc;
	int vit;
	int cha;
	int exp;
	int lvl;
} stat_t;

typedef struct enemy
{
	int animcol;
	int animsens;
	effect_t *poison;
	effect_t *stun;
	int aggro;
	sfVector2f ratios;
	float cd;
	float cdcount;
	int cast;
	int alive;
	int type;
	int spell1;
	int spell2;
	g_object *obj;
	g_object *life;
	stat_t *stat;
	sfVector2f scale;
	float idlecount;
	int idle;
} enemy_t;

typedef struct boss_spells
{
	int attack;
	int attack_ly;
	int ctent;
	sfVector2f trat;
	sfVector2f ballpos;
	sfVector2f ballrat;
	sfVector2f rayrat;
	g_object *bar;
	g_object *life[2];
	t_object *name;
	float rayused;
	float used;
	aoe_t *tent[6];
	aoe_t *well;
	aoe_t *ball;
	aoe_t *ray;
	dash_t *dash;
	dash_t *fus;
	effect_t *rage;
	float casting;
	sfMusic *s_tent;
	sfMusic *s_ball;
	sfMusic *samy_rage;
	sfMusic *samy_roda;
	sfMusic *thunder;
	particle_t *samy_part;
	particle_t *samy_fus;
} boss_t;

typedef struct struct_archer_spells
{
	aoe_t *barrage;
	aoe_t *heal;
	effect_t *leaf;
	dash_t *leap;
	int kalash;
	int current;
	float kalashspeed;
	int kalashcount;
	proj_t *arrow[20];
	proj_t *axe;
	float axeangle;
	st_anim *anim;
	st_time kal;
	particle_t *parta[20];
	sfMusic *l_click;
	sfMusic *s_leap;
	sfMusic *s_arrow_rain;
	sfMusic *s_fountain;
} archer_t;

typedef struct struct_gunner_spells
{
	int auto_a;
	int flamet;
	float flamestay;
	int cflame;
	float cdiminution;
	int autocount;
	float autospeed;
	st_time t;
	proj_t *blitz;
	proj_t *grenade;
	proj_t *net;
	dash_t *jump;
	sfCircleShape *explo;
	st_anim *boots;
	float grenadespeed;
	st_anim *explosion;
	st_anim *expbullet;
	sfCircleShape *expbt;
	float delay;
	st_time blitzt;
	proj_t *bullet[10];
	int current;
	int ult;
	proj_t *ultb[10];
	proj_t *flame[100];
	effect_t *rush;
	g_object *trait[10];
	sfVector2f ultrat;
	int dmg;
	int origin;
	particle_t *partf;
	particle_t *partg;
	sfMusic *l_click;
	sfMusic *s_explo;
	sfMusic *zap;
	sfMusic *h_noon;
	sfMusic *s_flam;
	sfMusic *s_net;
} gunner_t;

typedef struct struct_melee_swing
{
	float begin;
	float angle;
	float count;
	float speed;
	int dmg;
	int dmgratio;
	int able;
	int shot;
	int sens;
	sfVector2f scale;
	st_time t;
} swing_t;

typedef struct struct_rogue_spells
{
	proj_t *dagger[30];
	aoe_t *zone;
	aoe_t *flash;
	float fscale;
	float vanish;
	float ultangle;
	int side;
	int auto_bool;
	int current;
	int ultcount;
	int ulting;
	float ultspeed;
	int bstab;
	float bcount;
	st_button *backstab;
	sfVector2f bpos[2];
	sfVector2f brat;
	float bdmg;
	st_time ultt;
	proj_t *dance;
	dash_t *tp;
	dash_t *draw;
	swing_t *auto_a[2];
	sfIntRect ultr;
	particle_t *partp;
	particle_t *partd;
	sfMusic *l_click;
	sfMusic *flashbang;
	sfMusic *s_vanish;
	sfMusic *s_ult;
	sfMusic *s_dag_toss;
} rogue_t;

typedef struct struct_warrior_spells
{
	swing_t *auto_a;
	swing_t *whirl;
	proj_t *hasagi;
	sfVector2f hpos;
	sfVector2f hrat;
	float hdmg;
	int sound;
	aoe_t *shield;
	aoe_t *crack;
	int estoc;
	float count;
	dash_t *rush;
	dash_t *ultd;
	effect_t *endure;
	effect_t *lifesteal;
	effect_t *destroyer;
	effect_t *parade;
	g_object *paricon;
	sfMusic *s_shield;
	sfMusic *s_sword1;
	sfMusic *s_sword2;
	sfMusic *s_hasaki;
	sfMusic *s_rush;
	sfMusic *s_endure;
	sfMusic *s_stomp;
} warrior_t;

typedef struct fight_tree
{
	int lock[10];
	int passive;
	int spell1;
	int spell2;
	int spell3;
	int skillp;
} tree_t;

typedef struct fight_bars
{
	g_object *bars;
	g_object *life;
	g_object *xp;
	t_object *values[3];
} bars_t;

typedef struct shader_fight
{
	shader_t vanish;
	shader_t power;
	shader_t endure;
	shader_t armor;
	shader_t poison;
	shader_t stun;
	shader_t bless;
	shader_t samy_roda;
	shader_t samy_rush;
	shader_t champ;
} f_shader_t;

typedef struct main_fight
{
	boss_t boss;
	effect_t *recover;
	dash_t *knock;
	st_time ent;
	enemy_t **mob;
	st_button *icons[4];
	g_object *cd[4];
	g_object *locks[3];
	float cdcount[4];
	float cds[4];
	int cast;
	int panim;
	st_time cdt;
	st_time proc;
	archer_t arc;
	rogue_t rog;
	gunner_t gun;
	warrior_t war;
	f_shader_t shade;
	t_object *dmg[50];
	int dmgshot[50];
	int cdmg;
	t_object *die_msg;
	g_object *die_fade;
	int fade;
} fight_t;

typedef struct struct_status_menu
{
	int show;
	g_object *window;
	g_object *face;
	st_button *classe;
	st_button *stats[6];
	t_object *lvl;
	t_object *exp;
	t_object *name;
} status_menu_t;

typedef struct status_tree_menu
{
	char **spells;
	int status;
	g_object *window;
	st_button *classe;
	t_object *skillp;
	g_object *pas[3];
	g_object *m2[3];
	g_object *e[2];
	g_object *r[2];
	g_object *select[4];
	g_object *lock[10];
	t_object *sp[4];
} tree_menu_t;

typedef struct struct_main_menu
{
	sfMusic *music;
	sfMusic *s_effect;
	int menu;
	int create;
	st_time t;
	int option;
	int sens;
	st_button *button[4];
	g_object *cursor;
	g_object *rope;
	g_object *first;
	g_object *abyss[2];
	g_object *rockback[2];
	g_object *rock2[2];
	g_object *guy;
	g_object *title;
	t_object *sound[2];
	st_button *s_button[4];
	shader_t shader;
} st_menu;

typedef struct struct_pause_menu
{
	t_object *saved;
	int opac;
	int sens;
	int menu;
	int option;
	st_button *title;
	st_button *button[5];
	g_object *cursor;
	g_object *window;
} pause_menu_t;

typedef struct struct_player_info
{
	stat_t *stat;
	tree_t tree;
	effect_t *speed_effect;
	effect_t *cdr_effect;
	st_cdata cdata;
	g_object *obj;
	g_object *weapon[2];
	int max_speed;
	float animspeed;
	int animcol;
	int animsens;
	st_time t;
	sfVector2f last_pos;
	sfVector2i nbr_frame;
	sfVector2f acceleration;
} player_t;

typedef struct particle_all
{
	particle_t *lvlup;
} all_part_t;

typedef struct cutscene
{
	int champ_status;
	int samy_boss_status;
	int samy_value;
	int zac_value;
	int jade_value;
	int son_value;
	g_object *map;
	g_object *map_son;
	g_object *zachd;
	g_object *map_samy;
	g_object *map_samy_boss;
	g_object *samy_boss;
	g_object *map_boss;
	g_object *samyd;
	g_object *champ;
	g_object *champ_boss;
	g_object *ly_boss;
	g_object *ly_death;
	g_object *champ_death;
	g_object *begin;
} ct_cutscene;

typedef struct struct_rpg
{
	int boss;
	int s_music;
	int s_effect;
	all_part_t part;
	proc_t proc;
	ing_inv_t inv;
	ing_finv_t finv;
	fight_t f;
	bars_t bar;
	player_t player;
	status_menu_t statm;
	tree_menu_t treem;
	pause_menu_t pausm;
	sfVector2f origin;
	sfEvent event;
	g_object *loading;
	ct_cutscene cut;
	int returnv;
	st_custom cust;
	st_menu mainm;
	int save;
	st_time partime;
	files_t *fi;
	st_music dungeon_music;
	sfRenderWindow *window;
} st_rpg;

#include "procedural.h"
#include "game_map.h"

void dialog_samy_boss_2(st_rpg *s);
void samy_boss_part2_in_if(st_rpg *s);
void dialog_final(st_rpg *s);
void setup_pos_for_scene_final(st_rpg *s, sfVector2f scale,
sfVector2f scale2);
void dialog_boss_ly(st_rpg *s);
void setup_pos_for_scene_final_fight_ly(st_rpg *s, sfVector2f scale,
sfVector2f scale2);
void generate_samy(st_rpg *s);
void test_destroy_loop_pause(st_rpg *s);
void choose_sound(st_rpg *s);
int boss_is_dead(st_rpg *s);
int win(st_rpg *s, char *str);
int die(st_rpg *s);
int security_map(st_rpg *s);
int security_map_enemy(st_rpg *s, float dt, int i);
void create_boss_name(st_rpg *s);
void display_boss_life_bar(st_rpg *s);
void destroy_boss_life_bar(st_rpg *s);
void update_boss_life_bar_origin(st_rpg *s);
void update_boss_life_bar_width(st_rpg *s);
void create_boss_life_bar(st_rpg *s);
void update_ly_ray(st_rpg *s, float dt);
void launch_ly_spell(st_rpg *s);
void destroy_boss(st_rpg *s);
void display_boss(st_rpg *s);
void update_boss(st_rpg *s, float dt);
void generate_boss(st_rpg *s);
void generate_ly(st_rpg *s);
void destroy_ly(st_rpg *s);
void display_ly(st_rpg *s);
void update_ly(st_rpg *s, float dt);
void choose_display_enemies(st_rpg *s, int i);
int corupt_save(void);
int check_stat_value(char *buffer);
int check_tree(char *saves);
int check_stat(char *saves);
int check_cust(char *saves);
void update_samy_fusrohdah(st_rpg *s);
void display_samy(st_rpg *s);
void destroy_samy(st_rpg *s);
void update_samy(st_rpg *s, float dt);
void launch_samy_spell(st_rpg *s);
void launch_samy_dash(st_rpg *s);
void update_samy_dash(st_rpg *s, float dt);
void generate_samy(st_rpg *s);
int enemy_is_able(st_rpg *s, int i);
void update_well(st_rpg *s);
void proc_enemy_aoe(st_rpg *s, aoe_t *aoe, int i);
void get_object_ends(g_object *object, sfVector2f points[4]);
int enemy_hitbox(g_object *attack, enemy_t *mob);
int circle_hitbox_enemy(sfCircleShape *circle, enemy_t *mob);
void update_shadowball(st_rpg *s, float dt);
int precedent_tentacle_is_mid(st_rpg *s);
void update_tentacle(st_rpg *s);
void generate_champ(st_rpg *s);
void destroy_champ(st_rpg *s);
void display_champ(st_rpg *s);
void update_champ(st_rpg *s, float dt);
void launch_champ_spells(st_rpg *s);
int mouse_in_press(g_object *obj, sfRenderWindow *window, sfEvent event);
void set_text_option(st_rpg *s);
void set_new_sound(st_rpg *s);
void choose_set_sound(st_rpg *s, sfEvent event);
void set_tree_positions(st_rpg *s);
void generate_pause_menu_window(st_rpg *s);
void generate_pause_menu_buttons(st_rpg *s);
void get_sound_option(st_rpg *s);
void resume(st_rpg *s);
void destroy_warrior_sound(st_rpg *s);
void create_warrior_sound(st_rpg *s);
void attack_enemy(st_rpg *s, int i);
int player_is_dead(st_rpg *s);
int hurt(st_rpg *s, float amount);
void create_spells_warrior1(st_rpg *s);
void create_spells_warrior2(st_rpg *s);
void draw_all(st_rpg *s);
void pause_menu_manage_cursor_events(st_rpg *s, sfEvent event);
void set_origin_map(st_rpg *s);
void pathfinding(st_rpg *s, float dt, int i);
void verify_collide_map_enemies(st_rpg *rpg, float dt, int i);
void create_archer_sound(st_rpg *s);
void destroy_archer_sound(st_rpg *s);
float get_angle_enemy(st_rpg *s, int i);
void enemies_animation(st_rpg *s);
void enemy_animation(st_rpg *s, int i);
void set_shader_map(st_rpg *s);
void destroy_rogue_sound(st_rpg *s);
void final_fight_ly(st_rpg *s);
void create_rogue_sound(st_rpg *s);
void destroy_gunner_sound(st_rpg *s);
void create_gunner_sound(st_rpg *s);
void handle_rage(st_rpg *s, float amount, enemy_t *mob);
void handle_lifesteal(st_rpg *s, float amount, effect_t *effect);
void handle_poison(st_rpg *s, enemy_t *mob);
void handle_stun(char *str, enemy_t *mob, float duration);
void proc_enemy_stun(st_rpg *s, int i);
void proc_enemy_poison(st_rpg *s, int i);
void loot_enemy(st_rpg *s);
void set_level_up(st_rpg *s);
void destroy_main_particles(st_rpg *s);
void update_main_particles(st_rpg *s, float dt);
void display_main_particles(st_rpg *s);
void create_main_particles(st_rpg *s);
void create_dmg_show(st_rpg *s);
void destroy_dmg_show(st_rpg *s);
void launch_dmg_show(st_rpg *s, float amount, g_object *obj);
void update_dmg_show(st_rpg *s);
void display_dmg_show(st_rpg *s);
void rogue_update_shadowstep(st_rpg *s);
void destroy_dungeon_shader(st_rpg *s);
void display_player_shade(st_rpg *s);
void set_shader(st_rpg *s);
shader_t create_shader(char *frag, int is_clock);
void destroy_shader(shader_t *shader);
void display_dungeon(st_rpg *s);
void draw_map_block(st_rpg *rpg, int y);
void update_particles(st_rpg *s);
void update_particles_class(st_rpg *s, float dt);
void destroy_particle(particle_t *part);
void display_particle(particle_t *part, sfRenderWindow *window);
void set_particle(particle_t *part, uint id, sfVector2f pos, sfColor color);
void launch_particle(particle_t *part, sfVector2f pos, float angle);
void update_particle(particle_t *part, float dt);
particle_t *create_particle(char *str);
void movement_enemies(st_rpg *s, int i, float dt);
void set_aggro_enemies(st_rpg *s, int i);
void update_life_bars_enemies(st_rpg *s, int i);
void destroy_enemies(st_rpg *s);
void update_enemies(st_rpg *s);
void destroy_enemy(enemy_t *enemy);
void display_enemies(st_rpg *s);
void generate_enemies(st_rpg *s);
enemy_t *generate_enemy(char *str);
void warrior_update_quake(st_rpg *s);
void warrior_update_rush(st_rpg *s);
void rogue_update_flash(st_rpg *s);
void destroy_dash(dash_t *dash);
void update_dash(st_rpg *s, dash_t *dash);
void launch_dash(st_rpg *s, dash_t *dash);
dash_t *create_dash(float speed, float range);
void gunner_update_flamet(st_rpg *s);
void handle_status(st_rpg *s, float amount, enemy_t *mob);
void stop_player(st_rpg *s);
int orientation_from_mouse(st_rpg *s);
void player_animation(st_rpg *s);
void create_player(st_rpg *s);
int mouse_in_origin(st_rpg *s, g_object *obj);
int dungeon_loop(st_rpg *s);
void verify_other_input(sfEvent event, st_rpg *rpg);
void origin_life_bar(st_rpg *s);
void destroy_main_fight(st_rpg *s);
void origin_icons(st_rpg *s);
void origin_spells(st_rpg *s);
void create_main_fight(st_rpg *s);
void make_proc_variables(proc_var_t *pvar);
int draw_sprites_map(st_rpg *rpg);
int update_sprite(st_rpg *rpg);
int verify_exit_player(st_rpg *rpg);
void create_gunner_ults(st_rpg *s);
void create_gunner_second(st_rpg *s);
void create_gunner_explosions(st_rpg *s);
void create_gunner_bullets(st_rpg *s);
void create_archer_passive(st_rpg *s);
void create_archer_projectiles(st_rpg *s);
void create_rogue_autos(st_rpg *s);
void create_rogue_daggers(st_rpg *s);
void my_set_string(sfText *text, char *str);
char *get_stat_string(int i);
char *get_stat_value(st_rpg *s, int i);
void update_status_menu(st_rpg *s);
void display_locked_spells(st_rpg *s);
void display_locked_spells_cd(st_rpg *s);
void update_cursor_pos_pause(st_rpg *s);
void set_colors_pause(st_rpg *s);
void which_update(st_rpg *s);
void display_fight(st_rpg *s);
void cursor_animation_pause(st_rpg *s, int min, int max);
void update_status_menu(st_rpg *s);
int pause_main(st_rpg *s);
void which_display(st_rpg *s);
int left_clicked_on_pause(st_rpg *s, sfEvent event);
int which_pause_menu(st_rpg *s);
void update_pause_menu(st_rpg *s);
void display_pause_menu(st_rpg *s);
void destroy_pause_menu(st_rpg *s);
void generate_pause_menu(st_rpg *s);
char *get_tree_path(st_rpg *s, int spell, int number);
void select_spell(st_rpg *s, int lock);
char **get_spinfo(st_rpg *s);
void tree_set_rects(st_rpg *s);
void update_tree_pos(st_rpg *s);
void generate_tree_menu(st_rpg *s);
void tree_proceed(st_rpg *s, int lock);
void display_object(sfRenderWindow *window, g_object *object);
void game_update(st_rpg *s);
void update_tree_menu(st_rpg *s);
char *get_class_string(int i);
void generate_tree_menu(st_rpg *s);
void destroy_tree_menu(st_rpg *s);
void display_tree_menu(st_rpg *s);
int prog(st_rpg *s);
void update_menu_stat_mouse_over(st_rpg *s);
void destroy_status_menu(st_rpg *s);
void display_status_menu(st_rpg *s);
void generate_status_menu(st_rpg *s);
void display_button(sfRenderWindow *window, st_button *button);
char *get_save_path(st_rpg *s);
void save_stat(stat_t *stat, char *path);
void save_game(st_rpg *s);
void write_a_value(int fd, char *value, int len);
void save_tree(tree_t tree, char *path);
void rogue_backstab(st_rpg *s);
void handle_invulnerability_lifesteal(st_rpg *s, float amount, char *effect);
void handle_explosive(st_rpg *s, proj_t *proj);
void handle_bounce(st_rpg *s, proj_t *proj);
void handle_pierce(proj_t *proj);
void rogue_update_auto_attack(st_rpg *s);
void update_pos_weapon(st_rpg *s);
void destroy_player(st_rpg *s);
int check_double_class(st_rpg *s);
void display_player(st_rpg *s);
void create_player_from_cust(st_rpg *s);
void proc_effects(st_rpg *s, float dt);
void proc_effect(effect_t *effect, float dt);
void destroy_effect(effect_t *effect);
void apply_projectiles(st_rpg *s);
effect_t *create_effect(char *type, int amount, float duration);
void warrior_update_hasagi(st_rpg *s, float dt);
void gunner_update_ultimate(st_rpg *s);
void warrior_update_auto_attack(st_rpg *s);
void swing_damage_enemy(st_rpg *s, swing_t *swing, enemy_t *mob);
swing_t *create_swing_from_file(char *path);
void destroy_swing(swing_t *swing);
void update_swing(st_rpg *s, swing_t *swing, g_object *obj);
void launch_swing(st_rpg *s, swing_t *swing, g_object *obj);
void create_weapon(st_rpg *s);
void update_fight(st_rpg *s);
void apply_aoe(st_rpg *s, aoe_t *aoe, enemy_t *mob);
void proc_aoe(st_rpg *s, aoe_t *aoe, float dt);
void proc_aoes(st_rpg *s, float dt);
aoe_t *create_aoe_from_file(char *path);
void apply_projectile(st_rpg *s, proj_t *proj, enemy_t **mob);
void projectile_damage_enemy(st_rpg *s, proj_t *proj, enemy_t *mob);
int circle_hitbox(sfCircleShape *circle, g_object *target);
int hitbox(g_object *attack, g_object *target);
void update_projectiles(st_rpg *s, float dt);
void create_mob_example(st_rpg *s);
void update_mob_example(st_rpg *s);
void destroy_mob_example(st_rpg *s);
void display_mob_example(st_rpg *s);
void load_tree(st_rpg *s, char *path);
void heal(st_rpg *s, int amount);
void load_save(st_rpg *s);
int launch_main_menu_load_slots(st_rpg *s);
void create_first_tree(st_rpg *s);
stat_t *load_stat(char *path);
stat_t *create_first_stat(void);
void update_bars(st_rpg *s);
void rogue_update_storm(st_rpg *s);
void display_projectile(sfRenderWindow *window, proj_t *proj);
sfCircleShape *create_circle(int radius, int thickness, sfColor color);
void launch_aoe(st_rpg *s, aoe_t *aoe);
void display_aoe(sfRenderWindow *window, aoe_t *aoe);
void update_aoe(aoe_t *aoe);
void destroy_aoe(aoe_t *aoe);
aoe_t *create_aoe(sfCircleShape *circle, st_anim *anim, float duration);
void update_life_bar(st_rpg *s);
void display_life_bar(st_rpg *s);
void destroy_life_bar(st_rpg *s);
void create_life_bar(st_rpg *s);
void gunner_update_blitz(st_rpg *s);
void gunner_update_grenade(st_rpg *s, float dt);
void get_cooldowns(st_rpg *s);
void archer_auto_attack(st_rpg *s);
void gunner_auto_attack(st_rpg *s);
void rogue_auto_attack(st_rpg *s);
void warrior_auto_attack(st_rpg *s);
void gunner_update_auto_attack(st_rpg *s);
void update_axe(st_rpg *s);
void update_aoe_barrage(st_rpg *s);
void update_kalash(st_rpg *s);
void update_current_arrow(st_rpg *s);
void destroy_class(st_rpg *s);
void launch_spells(st_rpg *s);
void choose_spell1_archer(st_rpg *s);
void choose_spell2_archer(st_rpg *s);
void choose_spell3_archer(st_rpg *s);
void choose_spell1_gunner(st_rpg *s);
void choose_spell2_gunner(st_rpg *s);
void choose_spell3_gunner(st_rpg *s);
void choose_spell1_rogue(st_rpg *s);
void choose_spell2_rogue(st_rpg *s);
void choose_spell3_rogue(st_rpg *s);
void choose_spell1_warrior(st_rpg *s);
void choose_spell2_warrior(st_rpg *s);
void choose_spell3_warrior(st_rpg *s);
void update_class(st_rpg *s);
void display_class(st_rpg *s);
void destroy_icons_cd(st_rpg *s);
void update_cdcount_icons(st_rpg *s, int i);
void update_icons_cd(st_rpg *s);
void create_icons_cd(st_rpg *s);
void create_class(st_rpg *s);
void destroy_spells_gunner(st_rpg *s);
void destroy_spells_archer(st_rpg *s);
void display_icons(st_rpg *s);
void destroy_icons(st_rpg *s);
char *which_spell(st_rpg *s, int spell);
char *get_spell_path(st_rpg *s, int spell);
void create_icons(st_rpg *s);
sfVector2f get_ratios(float angle);
float get_angle(st_rpg *s);
int fight_instance(st_rpg *s);
void launch_projectile(st_rpg *s, proj_t *proj, float angle);
void loading(st_rpg *s);
int cust_left_clicked(st_rpg *s, sfEvent event);
void cust_menu_togo_name(st_rpg *s);
void cust_menu_togo_classes(st_rpg *s);
void cust_menu_togo_sex(st_rpg *s);
int cust_menu_backto_main(st_rpg *s);
void display_cust(st_rpg *s);
void destroy_cust_buttons(st_rpg *s);
void custom_destroy(st_rpg *s);
void create_st_custom(st_rpg *s);
void custom_manage_cursor_events_mouse(st_rpg *s);
void custom_manage_cursor_events_key(st_rpg *s, sfEvent event);
void cust_cursor_animation(st_rpg *s);
void get_cursor_pos_classes(st_rpg *s);
void get_cursor_pos(st_rpg *s);
int custom_launch(st_rpg *s, sfEvent event);
int cust_get_buttons(int menu);
int cust_minx_buttons(int menu);
int cust_maxx_buttons(int menu);
int cust_miny_buttons(int menu);
int cust_maxy_buttons(int menu);
int custom_main(st_rpg *s);
int event_main_menu(st_rpg *s);
int launch_main_menu_options(st_rpg *s);
int launch_main_menu_create_slots(st_rpg *s);
int launch_main_menu_main(st_rpg *s);
int launch_main_menu_saves(st_rpg *s);
void main_menu_togo_main(st_rpg *s);
void main_menu_togo_slots(st_rpg *s);
void main_menu_togo_saves(st_rpg *s);
void main_menu_togo_options(st_rpg *s);
int get_max_buttons(st_rpg *s);
void destroy_main_menu(st_rpg *s);
void initialize_menu(st_rpg *s);
int left_clicked_on_buttons(st_rpg *s, sfEvent event);
st_time create_st_time(void);
void destroy_anim(st_anim *anim);
st_anim *create_anim(g_object *obj, sfVector2i max, float speed);
void clocked_animation(st_anim *anim);
int mouse_in_object(g_object *obj, sfRenderWindow *window);
st_button *create_button(char *str, g_object *object, sfColor c, int size);
st_button *create_vbutton(char *str, sfVector2f pos, sfColor c, int size);
void destroy_button(st_button *button);
void movement_mainm(st_rpg *s);
void destroy_main_menu(st_rpg *s);
int main_menu(st_rpg *s);
void display_menu_background(st_rpg *s);
int main_menu_cutscene(st_rpg *s);
sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vector2f(float x, float y);
sfVector2i create_vector2i(int x, int y);
void shader_move(st_rpg *s);
void init_player_movement(st_rpg *rpg);
void init_player_camera(st_rpg *rpg);
void walk_animation(st_rpg *s);
void player_animation_village(st_rpg *s);
void create_dungeon_loop(st_rpg *s);
int dungeon_loop(st_rpg *s);
void update_dungeon_loop(st_rpg *s);
void destroy_dungeon_loop(st_rpg *s);

void update_current_bullet(st_rpg *s);
void update_current_dagger(st_rpg *s);
void change_side_player(st_rpg *s);
void display_gunner(st_rpg *s);
void display_main_menu_interface(st_rpg *s);
void modify_music(st_rpg *s, sfEvent event);
void modify_effect(st_rpg *s, sfEvent event);

void dungeon1(proc_var_t *hey);
void dungeon2(proc_var_t *hey);
void dungeon3(proc_var_t *hey);
void dungeon4_1(proc_var_t *hey);
void dungeon4_2(proc_var_t *hey);
void dungeon5(proc_var_t *hey);
void dungeon_boss_samy(proc_var_t *hey);

#endif
