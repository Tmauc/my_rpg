/*
** EPITECH PROJECT, 2017
** game_map.h
** File description:
** .h file to stock all functions from our screensaver librairy
*/

#include <dirent.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "my_rpg.h"

static const float speed = 3;

int game(st_rpg *s);
void destroy(st_rpg *s);
void destroy_dialog_box(st_rpg *s);
void destroy_name_box(st_rpg *s);
void destroy_pnj(st_rpg *s);
void destroy_quests(st_rpg *s);
char **remalloc_tab(char **tab, char *str);

void check_pos_camera_x(st_rpg *s);
void check_pos_camera_y(st_rpg *s);
void check_pos_angles(st_rpg *s);

void draw(st_rpg *s);
void draw_pnj(st_rpg *s);
void draw_all(st_rpg *s);
void draw_dialog_box(st_rpg *s);
void draw_loading(st_rpg *s);
void draw_name_box(st_rpg *s);
void draw_choice_menu(st_rpg *s, int compter);

int event_game(st_rpg *s);
int event_choice_box(st_rpg *s, int compter);
void up_cursor(st_rpg *s);
void down_cursor(st_rpg *s, int compter);

void character_setup(st_rpg *s);
void setup_camera(st_rpg *s);
void setup_variable(st_rpg *s);
void setup_loading(st_rpg *s);
void setup_col(st_rpg *s);
void setup_variable_scene_quests(st_rpg *s);
void pnj_setup(st_rpg *s);
void get_all_pnj(st_rpg *s, char *path);
void game_update(st_rpg *s);

void move(st_rpg *s);
void move_camera(st_rpg *s);
void move_ok(st_rpg *s);
void move_up(st_rpg *s);
void move_down(st_rpg *s);
void move_right(st_rpg *s);
void move_left(st_rpg *s);
void move_allpts(pos_t *pos, st_rpg *s);
void move_id_player(st_rpg *s);
void move_infos_box(st_rpg *s);
void choice_box_quit(st_rpg *s, char **tab, char *str, int compter);

int my_getnbr_i(char const *str, int i);
int is_num(char a);
char *my_strcat_dup(char *str1, char *str2);

sfMusic *create_music(float volume, char *path);

int collision(st_rpg *s);
int case_id(st_rpg *s, int nb_ID);
int case_tp(st_rpg *s, int nb_ID);
int check_colcircle(st_rpg *s, int nbr);
int check_colsquare(st_rpg *s, int nbr);
int check_colpnj(st_rpg *s, int nbr);
void check_pnj(st_rpg *s);
int collision_id(st_rpg *s);
void create_dialog_box(st_rpg *s);
void create_choice_box(st_rpg *s, int compter, char **tab);
void create_name_box(st_rpg *s, char *name);

int **get_layer(char *name, st_rpg *s);
void create_map(st_rpg *s);
void parsing(struct stat a, st_rpg *s);
void update_player_position_village(st_rpg *s);

void free_tab(char **tab, int y);
void free_all(st_rpg *s);
void free_tab_withnull(char **tab);

void dialog_box(st_rpg *s, char *deux, char *name);
int choice_box(st_rpg *s, int fd);
void choice_box_quit(st_rpg *s, char **tab, char *str, int compter);
int choice_box_check_quit(st_rpg *s, char **tab, char *str, int compter);
int mouse_in_object_dialogbox(g_object *obj,
sfRenderWindow *window, st_rpg *s);
int mouse_in_object_quest_box(g_object *obj,
sfRenderWindow *window, st_rpg *s);

void transfer_pixel(st_rpg *s);
void transfer_pixel_prof(st_rpg *s, int compter, int height);
void transfer_pixel_colid(st_rpg *s, int compter, int height);
void transfer_pixel_col(st_rpg *s, int compter, int height);
void transfer_pixel_relief(st_rpg *s, int compter, int height);
void transfer_pixel_background(st_rpg *s, int compter, int height);

void tab_to_struct(st_rpg *s, char **tab, int y);
int tab_square(char **tab, int i, st_rpg *s, int square);
int tab_circle(char **tab, int i, st_rpg *s, int circle);

void setpixel_to_image_background(st_rpg *s, int col, int c, int p);
void setpixel_to_image_col(st_rpg *s, int col, int c, int p);
void setpixel_to_image_colid(st_rpg *s, int col, int c, int p);
void setpixel_to_image_prof(st_rpg *s, int col, int c, int p);
void setpixel_to_image_relief(st_rpg *s, int col, int c, int p);

void set_prof(st_rpg *s);
void set_colid(st_rpg *s);
void set_col(st_rpg *s);
void set_relief(st_rpg *s);
void set_background(st_rpg *s);

void create_farm_quests(char *buffer, quests_list_t *quests_list);
void create_kill_quests(char *buffer, quests_list_t *quests_list);
void create_go_quests(char *buffer, quests_list_t *quests_list);
void create_speak_quests(char *buffer, quests_list_t *quests_list);
void get_all_quests(st_rpg *s, char *path);
quests_t *get_quests(char *name);
void get_rewards(char *buffer, quests_t *quests);
void display_all(st_rpg *s, int size);
void check_quests(st_rpg *s);
void update_quests_box_des(st_rpg *s);
void check_pnj_for_quests(st_rpg *s);

void print_text_finish_quests(st_rpg *s);
void move_pnj(st_rpg *s, int posx, int posy, int nb_pnj);

void quests_1(st_rpg *s);
void quests_3(st_rpg *s);
void start_quests_4(st_rpg *s);
void after_quests(st_rpg *s);
void wake_up(st_rpg *s);

void setup_music(st_rpg *s);

void create_box_name(st_rpg *s, int i);
void check_pnj_name(st_rpg *s);

sfIntRect set_texturerect_top(g_object *obj, int top);

void night_scene(st_rpg *s);
void background_with_text(st_rpg *s, char *path_sprite, char *text, char *font);
void death_zac(st_rpg *s);
void death_samy(st_rpg *s);
void move_pnj_zach(st_rpg *s, sfVector2f pos, int nb_pnj);
void move_player_to_zach(st_rpg *s, sfVector2f pos);
void draw_scene_zach(st_rpg *s);
void walk_animation_pnj(st_rpg *s, int nb_pnj);
void reset_pos_friends(st_rpg *s);
void draw_scene_samy(st_rpg *s);

void draw_floor_nbr(st_rpg *rpg);
void quit_game_for_dungeon(st_rpg *s);
void lake_update(st_rpg *s);
void setup_pnj_value(st_rpg *s);
void setup_variable_scene_quests(st_rpg *s);
void samy_boss(st_rpg *s);
void scene_recup_son(st_rpg *s);
void draw_scene_son(st_rpg *s);
void draw_scene_samy_boss(st_rpg *s);
void draw_cut_scene(st_rpg *s);
void print_letter(st_rpg *s);
void final_fight(st_rpg *s);
void setup_pos_for_scene_zach(st_rpg *s, sfVector2f scale, sfVector2f scale2);
void setup_pos_for_scene_samy(st_rpg *s, sfVector2f scale, sfVector2f scale2);
void check_pnj_for_quests6(st_rpg *s);
void draw_scene_final_fight(st_rpg *s);
void death_fcnt(st_rpg *s);
void dungeon_boss_champ(proc_var_t *hey);
void set_all_var_at_zero(st_rpg *s);
void final_fight_ly(st_rpg *s);
void draw_scene_final_fight_ly(st_rpg *s);
void final_scene(st_rpg *s);
void draw_scene_final(st_rpg *s);
void begin_scene(st_rpg *s);
void draw_begin(st_rpg *s);
void update_death(st_rpg *s);
void draw_dialog_box(st_rpg *s);

void tp_bridge(st_rpg *s);
void tp_bridge2(st_rpg *s);
void tp_inside1(st_rpg *s);
void tp_inside2(st_rpg *s);
void tp_inside3(st_rpg *s);
void tp_inside4(st_rpg *s);

void tp_outside1(st_rpg *s);
void tp_outside2(st_rpg *s);
void tp_outside3(st_rpg *s);
void tp_outside4(st_rpg *s);

void tp_orphanage(st_rpg *s);
void tp_village(st_rpg *s);

void tp_cook1(st_rpg *s);
void tp_cook2(st_rpg *s);

void tp_bedroom(st_rpg *s);
void tp_bedroom2(st_rpg *s);
void tp_bedroom3(st_rpg *s);

void tp_corridor1(st_rpg *s);
void tp_corridor2(st_rpg *s);
void tp_corridor3(st_rpg *s);

#endif
