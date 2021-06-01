/*
** EPITECH PROJECT, 2018
** procedural.h
** File description:
** ezwin
*/

#ifndef PROC_H_
#define PROC_H_

#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "my_rpg.h"

#define MIN(a, b) ((a < b)? a : b)
#define MAX(a, b) ((a > b)? a : b)

//INPUTS
static const sfKeyCode key_up = sfKeyZ;
static const sfKeyCode key_down = sfKeyS;
static const sfKeyCode key_left = sfKeyQ;
static const sfKeyCode key_right = sfKeyD;
static const sfKeyCode key_map = sfKeyTab;
static const sfKeyCode key_inv = sfKeyLShift;
static const sfKeyCode key_fishing = sfKeySpace;
static const sfMouseButton key_fast_inv = sfMouseMiddle;
static const sfMouseButton key_select_item = sfMouseLeft;
static const sfMouseButton key_use_item = sfMouseRight;

//LAUNCH DUNGEON FUNCTION
int launch_dungeon(st_rpg *rpg, void (*function_pvar)(proc_var_t *));

//MAKE MAP
void map_creation(proc_t *proc);
void make_positions_proom(proc_t *proc);
void make_holes(proom_t *proom, char **map);
void make_map_better(char **map);
void increment_proc_struct(proc_var_t *pvar, proc_t *proc);
char **border_map(proc_var_t *pvar, char **map);
void print_map(char **map);
int count_rooms(proom_t *proom);

//CORRIDORS
void v_corridor(char **map, int y1, int y2, int x);
void h_corridor(char **map, int x1, int x2, int y);
void make_corridors(proc_t *proc, int length);

//CREATE MANDATORY BLOCKS
void create_entry(proc_t *proc);
void create_leave(proc_t *proc);
sfVector2f get_entry_pos(proc_t *proc);
sfVector2f get_exit_pos(proc_t *proc);
int verify_exit_player(st_rpg *rpg);
int vcollide(char block);
int is_wall(char block);

//MAKE BOSS MAP
void map_boss_creation(st_rpg *rpg);

//CREATE SPRITE MAP
smap_t **create_sprite_map(proc_t *proc, char **map);
void free_map_tbl(proc_t *proc);

//MANAGER
int verif_input_map(st_rpg *rpg);
void update_camera_position(st_rpg *rpg);
void update_player_position(st_rpg *rpg);
void verify_y_movement(st_rpg *rpg);
void verify_x_movement(st_rpg *rpg);
void verify_collide_map(st_rpg *rpg);
int interval(float value, float less, float max);

//MINIMAP
void init_minimap(proc_t *proc);
void verify_minimap(st_rpg *rpg);
void update_minimap(st_rpg *rpg);
void draw_rect_room(proc_t *proc, int x, int y);
void draw_rect_corridor(proc_t *proc, int x, int y);
void draw_rect_player(st_rpg *rpg);

//INIT MAP
void init_dungeon_game(st_rpg *rpg);

//FRAMEBUFFER
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_fill_screen(framebuffer_t *buffer, sfColor color);
void my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);
void fill_minimap_screen(framebuffer_t *buffer, sfColor color);
void reset_screen(framebuffer_t *buffer);
void my_draw_rect(framebuffer_t *buff, int pos[2], int size[2], sfColor color);
void my_draw_f_rect(framebuffer_t *buff, int pos[2], int size[2], int diag[4]);
void my_draw_vrect(framebuffer_t *buff, int pos[2], int size[2], sfColor color);
void my_draw_line(framebuffer_t *b, int pos1[2], int pos2[2], sfColor c);
void my_draw_octan(framebuffer_t *buffer, int r, int pos[2], sfColor color);
void my_draw_circle(framebuffer_t *buffer, int pos[2], int r, sfColor c);
void my_draw_circle_filled(framebuffer_t *b, int pos[2], int r, sfColor c);

//CREATE BLOCKS
int is_ground(char chr);
int many_around(char **map, int x, int y);

void make_ground_block(sfTexture *blocks, smap_t *smap);
void make_exit_block(sfTexture *blocks, smap_t *smap);
void make_leftright_block(sfTexture *blocks, smap_t *smap);
void make_bot_block(sfTexture *blocks, smap_t *smap);
void make_top_block(sfTexture *blocks, smap_t *smap);

void make_corner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_botright_block(sfTexture *blocks, smap_t *smap);
void make_corner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_topright_block(sfTexture *blocks, smap_t *smap);

void make_icorner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_icorner_botright_block(sfTexture *blocks, smap_t *smap);
void make_icorner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_icorner_topright_block(sfTexture *blocks, smap_t *smap);

void make_deadlock_top_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_bot_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_right_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_left_block(sfTexture *blocks, smap_t *smap);

//MAIN GAME
int launch_dungeon_game(st_rpg *rpg);
void free_dungeon(st_rpg *rpg, proc_t *proc);

//START A NEW LEVEL
int next_level_screen(st_rpg *rpg);
void fade_in_text(sfRenderWindow *window, sfText *text);
void fade_out_text(sfRenderWindow *window, sfText *text);

//INVENTORY
void create_ingame_inventory(st_rpg *rpg);
void destroy_inventory(st_rpg *rpg);
void destroy_inventory_items(st_rpg *rpg);
void clear_inventory_slot(item_t *slot);
void add_inventory_slot(item_t *first_slot);
void remove_inventory_slot(item_t *first_slot);
void verify_inventory(st_rpg *rpg);
item_t *create_first_slot(void);
int search_item(item_t *first_slot, unsigned int id);
int add_inventory_item(item_t *first_slot, unsigned int id);
void use_inventory_item(st_rpg *rpg, item_t *current);
void verify_mouse_inv_events(st_rpg *rpg);
void draw_focused_item(st_rpg *rpg);
void draw_inventory_background(st_rpg *rpg);
void create_item_sprite(st_rpg *rpg, item_t *current);
int mouse_on_inventory_slot(st_rpg *rpg, int posx, int posy);
void draw_resume_item(st_rpg *rpg);
void remove_inventory_item(st_rpg *rpg, item_t *to_remove);

//USE ITEM
void create_use_item(st_rpg *rpg);
void destroy_use_item(st_rpg *rpg);
void update_use_item(st_rpg *rpg, float dt);
void add_speed(st_rpg *rpg, int to_add);
void add_cdr(st_rpg *rpg, int to_add);

//LOAD SAVE INVENTORY
void save_current_inventory(st_rpg *rpg);
void load_inventory(st_rpg *rpg);

//WEAPON AND ARMOR SLOT
void draw_armor_weapon_slot(st_rpg *rpg);
void create_armor_weapon_slot(st_rpg *rpg);
void verify_armor_weapon_highlight(st_rpg *rpg, int *clicked);
void update_pos_weapon_armor_focus(st_rpg *rpg, sfVector2f *pos);

//FAST INVENTORY
void verify_fast_inventory(st_rpg *rpg);
void create_fast_inventory_slots(st_rpg *rpg);
void create_fast_inventory_screen(ing_finv_t *finv);
void create_fast_inventory_sprites(st_rpg *rpg);
void verify_mouse_focused(st_rpg *rpg);
void verify_mouse_released(st_rpg *rpg);
void draw_items_fast_inventory(st_rpg *rpg);
void draw_fast_inv_slot(st_rpg *rpg);

//ITEM INSIDE DUNGEONS
void create_items_list(st_rpg *rpg);
void destroy_items_list(st_rpg *rpg);
void draw_item_on_ground(st_rpg *rpg);
void update_item_ground(st_rpg *rpg);

//NPC
//ENNEMIES
sfVector2f create_ennemy_position(st_rpg *rpg);

//OTHER LOUIS WORK ON OTHER PARTICULAR EVENTS
//FISHING
int launch_fishing_instance(st_rpg *rpg);
void create_fishing_instance(st_rpg *rpg, fish_t *fish);
void draw_fishing_instance(st_rpg *rpg, fish_t *fish);
void update_fishing_instance(st_rpg *rpg, fish_t *fish, float elapsed);

#endif
