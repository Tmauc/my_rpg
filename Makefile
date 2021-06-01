##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME		=	my_rpg

CC		=	cc

CFLAGS		+=	-g -Iinclude -W -Wall -Wextra

LDFLAGS		+=	-L lib/my/ -lmy -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm -fdiagnostics-color=always

FILES		=	source/main.c							\
			source/graphic/create_particle.c				\
			source/graphic/particle.c					\
			source/graphic/create_rect.c					\
			source/graphic/game_object.c					\
			source/graphic/mouse_in_object.c				\
			source/graphic/create_circle.c					\
			source/graphic/st_time.c					\
			source/graphic/create_shader.c					\
			source/graphic/animation.c					\
			source/graphic/get_angles.c					\
			source/main_menu/main.c						\
			source/main_menu/cutscene.c					\
			source/main_menu/togo.c						\
			source/main_menu/launcher.c					\
			source/main_menu/base.c						\
			source/main_menu/base_part2.c					\
			source/main_menu/events.c					\
			source/main_menu/sound_set.c					\
			source/main_menu/sound_set_part2.c				\
			source/main_menu/set_text_option.c				\
			source/main_menu/shader.c					\
			source/main_menu/display_main_menu_interface.c			\
			source/custom/main.c						\
			source/custom/get_buttons.c					\
			source/custom/base.c						\
			source/custom/togo.c						\
			source/custom/to_player.c					\
			source/custom/launch.c						\
			source/custom/cursor.c						\
			source/fight/damage/damage_show.c				\
			source/fight/damage/apply_damage.c				\
			source/fight/icons/icons.c					\
			source/fight/icons/icons_cd.c					\
			source/fight/display_class.c					\
			source/fight/display_gunner.c					\
			source/fight/update_class.c					\
			source/fight/get_cooldowns.c					\
			source/fight/main.c						\
			source/fight/win.c						\
			source/fight/die.c						\
			source/fight/aoe/aoe.c						\
			source/fight/aoe/create_aoe.c					\
			source/fight/aoe/proc_aoes.c					\
			source/fight/dash.c						\
			source/fight/cosmetic/diplay_player_shader.c			\
			source/fight/cosmetic/set_shader.c				\
			source/fight/projectile/projectile.c				\
			source/fight/projectile/apply_projectiles.c			\
			source/fight/projectile/display_projectile.c			\
			source/fight/projectile/update_projectiles.c			\
			source/fight/projectile/projectile_effects.c			\
			source/fight/hitbox.c						\
			source/fight/enemies/champ.c					\
			source/fight/enemies/champ_generation.c				\
			source/fight/enemies/generate_samy.c				\
			source/fight/enemies/samy.c					\
			source/fight/enemies/samy_spells.c				\
			source/fight/enemies/lauch_samy_spells.c			\
			source/fight/enemies/champ_spells.c				\
			source/fight/enemies/champ_update.c				\
			source/fight/enemies/ly.c					\
			source/fight/enemies/ly_spells.c				\
			source/fight/enemies/boss.c					\
			source/fight/enemies/create_boss_name.c				\
			source/fight/enemies/boss_life_bars.c				\
			source/fight/enemies/hitbox.c					\
			source/fight/enemies/attack.c					\
			source/fight/enemies/enemy.c					\
			source/fight/enemies/aggro.c					\
			source/fight/enemies/enemy_effects.c				\
			source/fight/enemies/collisions.c				\
			source/fight/enemies/loot_enemy.c				\
			source/fight/enemies/animation.c				\
			source/fight/enemies/generate_enemy.c				\
			source/fight/enemies/base_enemies.c				\
			source/fight/effect/handle_effects.c				\
			source/fight/update_fight.c					\
			source/fight/effect/handle_status.c				\
			source/fight/effect/effect.c					\
			source/fight/effect/proc_effects.c				\
			source/fight/cosmetic/update_particles.c			\
			source/fight/cosmetic/update_particles_class.c			\
			source/fight/levelup.c						\
			source/fight/weapon/create_weapon.c				\
			source/fight/weapon/update_weapon_pos.c				\
			source/fight/swing.c						\
			source/spells/create_spells.c					\
			source/spells/launch_spells.c					\
			source/spells/destroy_class_sound.c				\
			source/spells/locked_spells.c					\
			source/spells/create_spells_archer.c				\
			source/spells/create_spells_gunner.c				\
			source/spells/create_spells_rogue.c				\
			source/spells/create_spells_warrior.c				\
			source/spells/destroy_spells.c					\
			source/spells/auto_attacks.c					\
			source/spells/archer_m.c					\
			source/spells/archer_e.c					\
			source/spells/archer_r.c					\
			source/spells/gunner_m.c					\
			source/spells/gunner_e.c					\
			source/spells/gunner_r.c					\
			source/spells/rogue_m.c						\
			source/spells/rogue_e.c						\
			source/spells/rogue_r.c						\
			source/spells/warrior_m.c					\
			source/spells/warrior_e.c					\
			source/spells/warrior_r.c					\
			source/spells/update_archer_1.c					\
			source/spells/update_gunner_1_1.c				\
			source/spells/update_gunner_1_2.c				\
			source/spells/update_gunner_1_3.c				\
			source/spells/update_rogue_1_1.c				\
			source/spells/update_rogue_1_2.c				\
			source/spells/update_warrior_1_1.c				\
			source/spells/update_warrior_1_2.c				\
			source/scenes/final.c						\
			source/scenes/begin_scene.c					\
			source/interface/life_bar.c					\
			source/interface/main_particles.c				\
			source/interface/status_menu.c					\
			source/interface/status_info.c					\
			source/interface/tree_menu.c					\
			source/interface/update_tree.c					\
			source/interface/generate_pause_menu.c				\
			source/interface/pause_menu.c					\
			source/interface/pause_main.c					\
			source/interface/pause_events.c					\
			source/interface/pause_launch.c					\
			source/interface/pause_design.c					\
			source/interface/tree_proceed.c					\
			source/interface/generate_tree_menu.c				\
			source/interface/button_generator.c				\
			source/interface/get_stat.c					\
			source/save/create_stat.c					\
			source/save/create_tree.c					\
			source/save/write_save.c					\
			source/save/load_save.c						\
			source/save/corupt_cust.c					\
			source/save/corupt_save.c					\
			source/save/corupt_stat.c					\
			source/save/corupt_tree.c					\
			source/game_map/prog.c						\
			source/game_map/game.c						\
			source/game_map/collisions/collision.c				\
			source/game_map/collisions/collision_prog.c			\
			source/game_map/collisions/collision_id.c			\
			source/game_map/collisions/check_pos_camera.c			\
			source/game_map/move/move.c					\
			source/game_map/move/move_prog.c				\
			source/game_map/move/move_infos.c				\
			source/game_map/move/move_pnj.c					\
			source/game_map/setup_destroy/setup.c				\
			source/game_map/setup_destroy/setup2.c				\
			source/game_map/setup_destroy/setup_scene.c			\
			source/game_map/setup_destroy/free.c				\
			source/game_map/setup_destroy/destroy.c				\
			source/game_map/setup_destroy/destroy_quests.c			\
			source/game_map/fcnt/remalloc_tab.c				\
			source/game_map/fcnt/create_music.c				\
			source/game_map/fcnt/lib_func.c					\
			source/game_map/fcnt/set_shader_map.c				\
			source/game_map/create_map/tileset.c				\
			source/game_map/create_map/parsing_tab_to.c			\
			source/game_map/create_map/set_pixeltoimage.c			\
			source/game_map/create_map/parsing.c				\
			source/game_map/create_map/setpixel_to_image.c			\
			source/game_map/create_map/get_layer.c				\
			source/game_map/create_map/transfer_pixel.c			\
			source/game_map/create_map/transfer_pixel_all.c			\
			source/game_map/draw/draw.c					\
			source/game_map/draw/draw_dialog.c				\
			source/game_map/pnj/check_pnj.c					\
			source/game_map/pnj/get_pnj.c					\
			source/game_map/pnj/events/events_fishing.c			\
			source/game_map/pnj/events/update_fishing.c			\
			source/game_map/pnj/events/draw_fishing.c			\
			source/game_map/pnj/events/create_fishing.c			\
			source/game_map/dialog/zone_text_create.c			\
			source/game_map/dialog/zone_text.c				\
			source/game_map/dialog/choice_box.c				\
			source/game_map/dialog/choice_box_quit.c			\
			source/game_map/dialog/choicebox_create_event.c			\
			source/game_map/dialog/mouse_in_object_dialogbox.c		\
			source/game_map/dialog/name_top_head.c				\
			source/game_map/tp/tp_bedroom.c					\
			source/game_map/tp/tp_bridge.c					\
			source/game_map/tp/tp_cook.c					\
			source/game_map/tp/tp_corridor.c				\
			source/game_map/tp/tp_inside.c					\
			source/game_map/tp/tp_orphanage.c				\
			source/game_map/tp/tp_outside.c					\
			source/quests/create_difquests.c				\
			source/quests/get_quests_rewards.c				\
			source/quests/get_all_quests.c					\
			source/quests/check_quests.c					\
			source/quests/get_quests.c					\
			source/quests/quests.c						\
			source/quests/quests1.c						\
			source/quests/check_pnj_for_quests.c				\
			source/quests/check_pnj_for_quests_part2.c			\
			source/quests/mouse_in_object_quest_box.c			\
			source/quests/print_text_finish_quests.c			\
			source/scenes/night.c						\
			source/scenes/background_with_text.c				\
			source/scenes/death_zach.c					\
			source/scenes/death_zach_setup.c				\
			source/scenes/final_fight.c					\
			source/scenes/death_samy.c					\
			source/scenes/death_samy_setup.c				\
			source/scenes/move_pnj_zach.c					\
			source/scenes/move_player_to_zach.c				\
			source/scenes/ly_cutscene.c					\
			source/scenes/final_cutscene.c					\
			source/scenes/scene_recup_son.c					\
			source/scenes/samy_boss.c					\
			source/scenes/samy_boss2.c					\
			source/scenes/after_quests.c					\
			source/scenes/death_fcnt.c					\
			source/scenes/final_fight_ly.c					\
			source/player/player.c						\
			source/player/security_collide.c				\
			source/player/player_movement_map.c				\
			source/player/player_animation_village.c			\
			source/player/player_movement.c					\
			source/player/player_animations.c				\
			source/player/player_hp.c					\
			source/player/verify_collisions.c				\
			source/dungeon/main_proc.c					\
			source/dungeon/update_origin/icons.c				\
			source/dungeon/update_origin/life_bar.c				\
			source/dungeon/make_array/create_map_boss.c			\
			source/dungeon/make_array/map_creation.c			\
			source/dungeon/make_array/verify_collide.c			\
			source/dungeon/make_array/corridors.c				\
			source/dungeon/make_array/mandatory_blocks.c			\
			source/dungeon/make_array/make_map_better.c			\
			source/dungeon/make_array/make_map_border.c			\
			source/dungeon/make_array/get_blocks_positions.c		\
			source/dungeon/make_sprite_map/main_draw_map.c			\
			source/dungeon/make_sprite_map/create_blocks.c			\
			source/dungeon/make_sprite_map/create_blocks_corner.c		\
			source/dungeon/make_sprite_map/create_blocks_icorner.c		\
			source/dungeon/make_sprite_map/create_blocks_deadlock.c		\
			source/dungeon/launch_game/launch_dungeon.c			\
			source/dungeon/launch_game/dungeon_loop.c			\
			source/dungeon/launch_game/dungeon_loop_create_update.c		\
			source/dungeon/launch_game/camera_manager.c			\
			source/dungeon/launch_game/input_manager.c			\
			source/dungeon/launch_game/free_dungeon.c			\
			source/dungeon/launch_game/init_dungeon.c			\
			source/dungeon/restart_game/restart_game.c			\
			source/dungeon/restart_game/text_anims.c			\
			source/dungeon/minimap_system/main_minimap.c			\
			source/dungeon/minimap_system/fill_screen.c			\
			source/dungeon/minimap_system/put_pixel.c			\
			source/dungeon/minimap_system/update_minimap.c			\
			source/dungeon/minimap_system/draw_minimap.c			\
			source/dungeon/draw_geometry/draw_rect.c			\
			source/dungeon/draw_geometry/draw_circle.c			\
			source/dungeon/inventory_system/handle_inventory.c		\
			source/dungeon/inventory_system/draw_inventory.c		\
			source/dungeon/inventory_system/create_inventory.c		\
			source/dungeon/inventory_system/create_fast_inventory.c		\
			source/dungeon/inventory_system/draw_fast_inventory.c		\
			source/dungeon/inventory_system/inv_handle_mouse.c		\
			source/dungeon/inventory_system/inventory_items_handling.c	\
			source/dungeon/inventory_system/create_weapon_armor.c		\
			source/dungeon/inventory_system/highlight_weapon_armor.c	\
			source/dungeon/inventory_system/item_resume.c			\
			source/dungeon/inventory_system/destroy_inventory.c		\
			source/dungeon/inventory_system/save_inventory.c		\
			source/dungeon/inventory_system/load_inventory.c		\
			source/dungeon/inventory_system/draw_finv_focused.c		\
			source/dungeon/inventory_system/draw_items_finventory.c		\
			source/dungeon/inventory_system/fast_inventory_hgt.c		\
			source/dungeon/increment_stats/speed_item_use.c			\
			source/dungeon/ground_item_system/create_items_on_ground.c	\
			source/dungeon/ground_item_system/draw_item_ground.c		\
			source/dungeon/ground_item_system/update_ground_item.c		\
			source/dungeon/npc/ennemies_dungeon.c				\
			source/dungeon/dungeons_preset/dungeon_preset1-5.c		\
			source/dungeon/dungeons_preset/dungeon_preset5.c		\
			source/dungeon/dungeons_preset/dungeon_preset_boss.c		\

SRCS		=	$(FILES)

OBJ		=	$(SRCS:.c=.o) $(MAIN:.c=.o)

.PHONY: fclean clean all re debug

RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[46m

all:			$(NAME)

$(NAME):	$(OBJ)
	@echo -e '${BG_COLOR}Flags: $(LDFLAGS) $(CFLAGS)${NC}'
	@echo -e '${GREEN}Create${NC}: ${GREY}./$(NAME)${NC}'
	@make --no-print-directory -C lib/my/
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o:		%.c
	@echo -e '${GREEN} [ OK ]${NC} Building : $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)


clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@make clean -C lib/my/
	@echo -e '${RED}Clean${NC} : OK'

fclean:		clean
	@rm -rf $(NAME)
	@make fclean -C lib/my/
	@echo -e '${RED}Fclean${NC}: ./$(NAME) removed'

re:		fclean all
