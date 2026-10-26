#pragma once

// Generated from 0x72 DungeonTilesetII v1.7 (tile_list_v1.7). Do not edit by hand.
// Texture: assets/0x72_dungeon.png (512x512). Animation frames are consecutive: SPRITE_X_F0 + Frame.

#include <array>
#include <raylib.h>

enum sprite_id : int {
  SPRITE_ANGEL_IDLE_ANIM_F0,
  SPRITE_ANGEL_IDLE_ANIM_F1,
  SPRITE_ANGEL_IDLE_ANIM_F2,
  SPRITE_ANGEL_IDLE_ANIM_F3,
  SPRITE_ANGEL_RUN_ANIM_F0,
  SPRITE_ANGEL_RUN_ANIM_F1,
  SPRITE_ANGEL_RUN_ANIM_F2,
  SPRITE_ANGEL_RUN_ANIM_F3,
  SPRITE_BIG_DEMON_IDLE_ANIM_F0,
  SPRITE_BIG_DEMON_IDLE_ANIM_F1,
  SPRITE_BIG_DEMON_IDLE_ANIM_F2,
  SPRITE_BIG_DEMON_IDLE_ANIM_F3,
  SPRITE_BIG_DEMON_RUN_ANIM_F0,
  SPRITE_BIG_DEMON_RUN_ANIM_F1,
  SPRITE_BIG_DEMON_RUN_ANIM_F2,
  SPRITE_BIG_DEMON_RUN_ANIM_F3,
  SPRITE_BIG_ZOMBIE_IDLE_ANIM_F0,
  SPRITE_BIG_ZOMBIE_IDLE_ANIM_F1,
  SPRITE_BIG_ZOMBIE_IDLE_ANIM_F2,
  SPRITE_BIG_ZOMBIE_IDLE_ANIM_F3,
  SPRITE_BIG_ZOMBIE_RUN_ANIM_F0,
  SPRITE_BIG_ZOMBIE_RUN_ANIM_F1,
  SPRITE_BIG_ZOMBIE_RUN_ANIM_F2,
  SPRITE_BIG_ZOMBIE_RUN_ANIM_F3,
  SPRITE_BOMB_F0,
  SPRITE_BOMB_F1,
  SPRITE_BOMB_F2,
  SPRITE_BUTTON_BLUE_DOWN,
  SPRITE_BUTTON_BLUE_UP,
  SPRITE_BUTTON_RED_DOWN,
  SPRITE_BUTTON_RED_UP,
  SPRITE_CHEST_EMPTY_OPEN_ANIM_F0,
  SPRITE_CHEST_EMPTY_OPEN_ANIM_F1,
  SPRITE_CHEST_EMPTY_OPEN_ANIM_F2,
  SPRITE_CHEST_FULL_OPEN_ANIM_F0,
  SPRITE_CHEST_FULL_OPEN_ANIM_F1,
  SPRITE_CHEST_FULL_OPEN_ANIM_F2,
  SPRITE_CHEST_MIMIC_OPEN_ANIM_F0,
  SPRITE_CHEST_MIMIC_OPEN_ANIM_F1,
  SPRITE_CHEST_MIMIC_OPEN_ANIM_F2,
  SPRITE_CHORT_IDLE_ANIM_F0,
  SPRITE_CHORT_IDLE_ANIM_F1,
  SPRITE_CHORT_IDLE_ANIM_F2,
  SPRITE_CHORT_IDLE_ANIM_F3,
  SPRITE_CHORT_RUN_ANIM_F0,
  SPRITE_CHORT_RUN_ANIM_F1,
  SPRITE_CHORT_RUN_ANIM_F2,
  SPRITE_CHORT_RUN_ANIM_F3,
  SPRITE_COIN_ANIM_F0,
  SPRITE_COIN_ANIM_F1,
  SPRITE_COIN_ANIM_F2,
  SPRITE_COIN_ANIM_F3,
  SPRITE_COLUMN,
  SPRITE_COLUMN_WALL,
  SPRITE_CRATE,
  SPRITE_DOC_IDLE_ANIM_F0,
  SPRITE_DOC_IDLE_ANIM_F1,
  SPRITE_DOC_IDLE_ANIM_F2,
  SPRITE_DOC_IDLE_ANIM_F3,
  SPRITE_DOC_RUN_ANIM_F0,
  SPRITE_DOC_RUN_ANIM_F1,
  SPRITE_DOC_RUN_ANIM_F2,
  SPRITE_DOC_RUN_ANIM_F3,
  SPRITE_DOORS_FRAME_LEFT,
  SPRITE_DOORS_FRAME_RIGHT,
  SPRITE_DOORS_FRAME_TOP,
  SPRITE_DOORS_LEAF_CLOSED,
  SPRITE_DOORS_LEAF_OPEN,
  SPRITE_DWARF_F_HIT_ANIM_F0,
  SPRITE_DWARF_F_IDLE_ANIM_F0,
  SPRITE_DWARF_F_IDLE_ANIM_F1,
  SPRITE_DWARF_F_IDLE_ANIM_F2,
  SPRITE_DWARF_F_IDLE_ANIM_F3,
  SPRITE_DWARF_F_RUN_ANIM_F0,
  SPRITE_DWARF_F_RUN_ANIM_F1,
  SPRITE_DWARF_F_RUN_ANIM_F2,
  SPRITE_DWARF_F_RUN_ANIM_F3,
  SPRITE_DWARF_M_HIT_ANIM_F0,
  SPRITE_DWARF_M_IDLE_ANIM_F0,
  SPRITE_DWARF_M_IDLE_ANIM_F1,
  SPRITE_DWARF_M_IDLE_ANIM_F2,
  SPRITE_DWARF_M_IDLE_ANIM_F3,
  SPRITE_DWARF_M_RUN_ANIM_F0,
  SPRITE_DWARF_M_RUN_ANIM_F1,
  SPRITE_DWARF_M_RUN_ANIM_F2,
  SPRITE_DWARF_M_RUN_ANIM_F3,
  SPRITE_EDGE_DOWN,
  SPRITE_ELF_F_HIT_ANIM_F0,
  SPRITE_ELF_F_IDLE_ANIM_F0,
  SPRITE_ELF_F_IDLE_ANIM_F1,
  SPRITE_ELF_F_IDLE_ANIM_F2,
  SPRITE_ELF_F_IDLE_ANIM_F3,
  SPRITE_ELF_F_RUN_ANIM_F0,
  SPRITE_ELF_F_RUN_ANIM_F1,
  SPRITE_ELF_F_RUN_ANIM_F2,
  SPRITE_ELF_F_RUN_ANIM_F3,
  SPRITE_ELF_M_HIT_ANIM_F0,
  SPRITE_ELF_M_IDLE_ANIM_F0,
  SPRITE_ELF_M_IDLE_ANIM_F1,
  SPRITE_ELF_M_IDLE_ANIM_F2,
  SPRITE_ELF_M_IDLE_ANIM_F3,
  SPRITE_ELF_M_RUN_ANIM_F0,
  SPRITE_ELF_M_RUN_ANIM_F1,
  SPRITE_ELF_M_RUN_ANIM_F2,
  SPRITE_ELF_M_RUN_ANIM_F3,
  SPRITE_FLASK_BIG_BLUE,
  SPRITE_FLASK_BIG_GREEN,
  SPRITE_FLASK_BIG_RED,
  SPRITE_FLASK_BIG_YELLOW,
  SPRITE_FLASK_BLUE,
  SPRITE_FLASK_GREEN,
  SPRITE_FLASK_RED,
  SPRITE_FLASK_YELLOW,
  SPRITE_FLOOR_1,
  SPRITE_FLOOR_2,
  SPRITE_FLOOR_3,
  SPRITE_FLOOR_4,
  SPRITE_FLOOR_5,
  SPRITE_FLOOR_6,
  SPRITE_FLOOR_7,
  SPRITE_FLOOR_8,
  SPRITE_FLOOR_LADDER,
  SPRITE_FLOOR_SPIKES_ANIM_F0,
  SPRITE_FLOOR_SPIKES_ANIM_F1,
  SPRITE_FLOOR_SPIKES_ANIM_F2,
  SPRITE_FLOOR_SPIKES_ANIM_F3,
  SPRITE_FLOOR_STAIRS,
  SPRITE_GOBLIN_IDLE_ANIM_F0,
  SPRITE_GOBLIN_IDLE_ANIM_F1,
  SPRITE_GOBLIN_IDLE_ANIM_F2,
  SPRITE_GOBLIN_IDLE_ANIM_F3,
  SPRITE_GOBLIN_RUN_ANIM_F0,
  SPRITE_GOBLIN_RUN_ANIM_F1,
  SPRITE_GOBLIN_RUN_ANIM_F2,
  SPRITE_GOBLIN_RUN_ANIM_F3,
  SPRITE_HOLE,
  SPRITE_ICE_ZOMBIE_ANIM_F0,
  SPRITE_ICE_ZOMBIE_ANIM_F1,
  SPRITE_ICE_ZOMBIE_ANIM_F2,
  SPRITE_ICE_ZOMBIE_ANIM_F3,
  SPRITE_IMP_IDLE_ANIM_F0,
  SPRITE_IMP_IDLE_ANIM_F1,
  SPRITE_IMP_IDLE_ANIM_F2,
  SPRITE_IMP_IDLE_ANIM_F3,
  SPRITE_IMP_RUN_ANIM_F0,
  SPRITE_IMP_RUN_ANIM_F1,
  SPRITE_IMP_RUN_ANIM_F2,
  SPRITE_IMP_RUN_ANIM_F3,
  SPRITE_KNIGHT_F_HIT_ANIM_F0,
  SPRITE_KNIGHT_F_IDLE_ANIM_F0,
  SPRITE_KNIGHT_F_IDLE_ANIM_F1,
  SPRITE_KNIGHT_F_IDLE_ANIM_F2,
  SPRITE_KNIGHT_F_IDLE_ANIM_F3,
  SPRITE_KNIGHT_F_RUN_ANIM_F0,
  SPRITE_KNIGHT_F_RUN_ANIM_F1,
  SPRITE_KNIGHT_F_RUN_ANIM_F2,
  SPRITE_KNIGHT_F_RUN_ANIM_F3,
  SPRITE_KNIGHT_M_HIT_ANIM_F0,
  SPRITE_KNIGHT_M_IDLE_ANIM_F0,
  SPRITE_KNIGHT_M_IDLE_ANIM_F1,
  SPRITE_KNIGHT_M_IDLE_ANIM_F2,
  SPRITE_KNIGHT_M_IDLE_ANIM_F3,
  SPRITE_KNIGHT_M_RUN_ANIM_F0,
  SPRITE_KNIGHT_M_RUN_ANIM_F1,
  SPRITE_KNIGHT_M_RUN_ANIM_F2,
  SPRITE_KNIGHT_M_RUN_ANIM_F3,
  SPRITE_LEVER_LEFT,
  SPRITE_LEVER_RIGHT,
  SPRITE_LIZARD_F_HIT_ANIM_F0,
  SPRITE_LIZARD_F_IDLE_ANIM_F0,
  SPRITE_LIZARD_F_IDLE_ANIM_F1,
  SPRITE_LIZARD_F_IDLE_ANIM_F2,
  SPRITE_LIZARD_F_IDLE_ANIM_F3,
  SPRITE_LIZARD_F_RUN_ANIM_F0,
  SPRITE_LIZARD_F_RUN_ANIM_F1,
  SPRITE_LIZARD_F_RUN_ANIM_F2,
  SPRITE_LIZARD_F_RUN_ANIM_F3,
  SPRITE_LIZARD_M_HIT_ANIM_F0,
  SPRITE_LIZARD_M_IDLE_ANIM_F0,
  SPRITE_LIZARD_M_IDLE_ANIM_F1,
  SPRITE_LIZARD_M_IDLE_ANIM_F2,
  SPRITE_LIZARD_M_IDLE_ANIM_F3,
  SPRITE_LIZARD_M_RUN_ANIM_F0,
  SPRITE_LIZARD_M_RUN_ANIM_F1,
  SPRITE_LIZARD_M_RUN_ANIM_F2,
  SPRITE_LIZARD_M_RUN_ANIM_F3,
  SPRITE_MASKED_ORC_IDLE_ANIM_F0,
  SPRITE_MASKED_ORC_IDLE_ANIM_F1,
  SPRITE_MASKED_ORC_IDLE_ANIM_F2,
  SPRITE_MASKED_ORC_IDLE_ANIM_F3,
  SPRITE_MASKED_ORC_RUN_ANIM_F0,
  SPRITE_MASKED_ORC_RUN_ANIM_F1,
  SPRITE_MASKED_ORC_RUN_ANIM_F2,
  SPRITE_MASKED_ORC_RUN_ANIM_F3,
  SPRITE_MUDDY_ANIM_F0,
  SPRITE_MUDDY_ANIM_F1,
  SPRITE_MUDDY_ANIM_F2,
  SPRITE_MUDDY_ANIM_F3,
  SPRITE_NECROMANCER_ANIM_F0,
  SPRITE_NECROMANCER_ANIM_F1,
  SPRITE_NECROMANCER_ANIM_F2,
  SPRITE_NECROMANCER_ANIM_F3,
  SPRITE_OGRE_IDLE_ANIM_F0,
  SPRITE_OGRE_IDLE_ANIM_F1,
  SPRITE_OGRE_IDLE_ANIM_F2,
  SPRITE_OGRE_IDLE_ANIM_F3,
  SPRITE_OGRE_RUN_ANIM_F0,
  SPRITE_OGRE_RUN_ANIM_F1,
  SPRITE_OGRE_RUN_ANIM_F2,
  SPRITE_OGRE_RUN_ANIM_F3,
  SPRITE_ORC_SHAMAN_IDLE_ANIM_F0,
  SPRITE_ORC_SHAMAN_IDLE_ANIM_F1,
  SPRITE_ORC_SHAMAN_IDLE_ANIM_F2,
  SPRITE_ORC_SHAMAN_IDLE_ANIM_F3,
  SPRITE_ORC_SHAMAN_RUN_ANIM_F0,
  SPRITE_ORC_SHAMAN_RUN_ANIM_F1,
  SPRITE_ORC_SHAMAN_RUN_ANIM_F2,
  SPRITE_ORC_SHAMAN_RUN_ANIM_F3,
  SPRITE_ORC_WARRIOR_IDLE_ANIM_F0,
  SPRITE_ORC_WARRIOR_IDLE_ANIM_F1,
  SPRITE_ORC_WARRIOR_IDLE_ANIM_F2,
  SPRITE_ORC_WARRIOR_IDLE_ANIM_F3,
  SPRITE_ORC_WARRIOR_RUN_ANIM_F0,
  SPRITE_ORC_WARRIOR_RUN_ANIM_F1,
  SPRITE_ORC_WARRIOR_RUN_ANIM_F2,
  SPRITE_ORC_WARRIOR_RUN_ANIM_F3,
  SPRITE_PUMPKIN_DUDE_IDLE_ANIM_F0,
  SPRITE_PUMPKIN_DUDE_IDLE_ANIM_F1,
  SPRITE_PUMPKIN_DUDE_IDLE_ANIM_F2,
  SPRITE_PUMPKIN_DUDE_IDLE_ANIM_F3,
  SPRITE_PUMPKIN_DUDE_RUN_ANIM_F0,
  SPRITE_PUMPKIN_DUDE_RUN_ANIM_F1,
  SPRITE_PUMPKIN_DUDE_RUN_ANIM_F2,
  SPRITE_PUMPKIN_DUDE_RUN_ANIM_F3,
  SPRITE_SKELET_IDLE_ANIM_F0,
  SPRITE_SKELET_IDLE_ANIM_F1,
  SPRITE_SKELET_IDLE_ANIM_F2,
  SPRITE_SKELET_IDLE_ANIM_F3,
  SPRITE_SKELET_RUN_ANIM_F0,
  SPRITE_SKELET_RUN_ANIM_F1,
  SPRITE_SKELET_RUN_ANIM_F2,
  SPRITE_SKELET_RUN_ANIM_F3,
  SPRITE_SKULL,
  SPRITE_SLUG_ANIM_F0,
  SPRITE_SLUG_ANIM_F1,
  SPRITE_SLUG_ANIM_F2,
  SPRITE_SLUG_ANIM_F3,
  SPRITE_SWAMPY_ANIM_F0,
  SPRITE_SWAMPY_ANIM_F1,
  SPRITE_SWAMPY_ANIM_F2,
  SPRITE_SWAMPY_ANIM_F3,
  SPRITE_TINY_SLUG_ANIM_F0,
  SPRITE_TINY_SLUG_ANIM_F1,
  SPRITE_TINY_SLUG_ANIM_F2,
  SPRITE_TINY_SLUG_ANIM_F3,
  SPRITE_TINY_ZOMBIE_IDLE_ANIM_F0,
  SPRITE_TINY_ZOMBIE_IDLE_ANIM_F1,
  SPRITE_TINY_ZOMBIE_IDLE_ANIM_F2,
  SPRITE_TINY_ZOMBIE_IDLE_ANIM_F3,
  SPRITE_TINY_ZOMBIE_RUN_ANIM_F0,
  SPRITE_TINY_ZOMBIE_RUN_ANIM_F1,
  SPRITE_TINY_ZOMBIE_RUN_ANIM_F2,
  SPRITE_TINY_ZOMBIE_RUN_ANIM_F3,
  SPRITE_UI_HEART_EMPTY,
  SPRITE_UI_HEART_FULL,
  SPRITE_UI_HEART_HALF,
  SPRITE_WALL_BANNER_BLUE,
  SPRITE_WALL_BANNER_GREEN,
  SPRITE_WALL_BANNER_RED,
  SPRITE_WALL_BANNER_YELLOW,
  SPRITE_WALL_EDGE_BOTTOM_LEFT,
  SPRITE_WALL_EDGE_BOTTOM_RIGHT,
  SPRITE_WALL_EDGE_LEFT,
  SPRITE_WALL_EDGE_MID_LEFT,
  SPRITE_WALL_EDGE_MID_RIGHT,
  SPRITE_WALL_EDGE_RIGHT,
  SPRITE_WALL_EDGE_TOP_LEFT,
  SPRITE_WALL_EDGE_TOP_RIGHT,
  SPRITE_WALL_EDGE_TSHAPE_BOTTOM_LEFT,
  SPRITE_WALL_EDGE_TSHAPE_BOTTOM_RIGHT,
  SPRITE_WALL_EDGE_TSHAPE_LEFT,
  SPRITE_WALL_EDGE_TSHAPE_RIGHT,
  SPRITE_WALL_FOUNTAIN_BASIN_BLUE_ANIM_F0,
  SPRITE_WALL_FOUNTAIN_BASIN_BLUE_ANIM_F1,
  SPRITE_WALL_FOUNTAIN_BASIN_BLUE_ANIM_F2,
  SPRITE_WALL_FOUNTAIN_BASIN_RED_ANIM_F0,
  SPRITE_WALL_FOUNTAIN_BASIN_RED_ANIM_F1,
  SPRITE_WALL_FOUNTAIN_BASIN_RED_ANIM_F2,
  SPRITE_WALL_FOUNTAIN_MID_BLUE_ANIM_F0,
  SPRITE_WALL_FOUNTAIN_MID_BLUE_ANIM_F1,
  SPRITE_WALL_FOUNTAIN_MID_BLUE_ANIM_F2,
  SPRITE_WALL_FOUNTAIN_MID_RED_ANIM_F0,
  SPRITE_WALL_FOUNTAIN_MID_RED_ANIM_F1,
  SPRITE_WALL_FOUNTAIN_MID_RED_ANIM_F2,
  SPRITE_WALL_FOUNTAIN_TOP_1,
  SPRITE_WALL_FOUNTAIN_TOP_2,
  SPRITE_WALL_FOUNTAIN_TOP_3,
  SPRITE_WALL_GOO,
  SPRITE_WALL_GOO_BASE,
  SPRITE_WALL_HOLE_1,
  SPRITE_WALL_HOLE_2,
  SPRITE_WALL_LEFT,
  SPRITE_WALL_MID,
  SPRITE_WALL_OUTER_FRONT_LEFT,
  SPRITE_WALL_OUTER_FRONT_RIGHT,
  SPRITE_WALL_OUTER_MID_LEFT,
  SPRITE_WALL_OUTER_MID_RIGHT,
  SPRITE_WALL_OUTER_TOP_LEFT,
  SPRITE_WALL_OUTER_TOP_RIGHT,
  SPRITE_WALL_RIGHT,
  SPRITE_WALL_TOP_LEFT,
  SPRITE_WALL_TOP_MID,
  SPRITE_WALL_TOP_RIGHT,
  SPRITE_WEAPON_ANIME_SWORD,
  SPRITE_WEAPON_ARROW,
  SPRITE_WEAPON_AXE,
  SPRITE_WEAPON_BATON_WITH_SPIKES,
  SPRITE_WEAPON_BIG_HAMMER,
  SPRITE_WEAPON_BOW,
  SPRITE_WEAPON_BOW_2,
  SPRITE_WEAPON_CLEAVER,
  SPRITE_WEAPON_DOUBLE_AXE,
  SPRITE_WEAPON_DUEL_SWORD,
  SPRITE_WEAPON_GOLDEN_SWORD,
  SPRITE_WEAPON_GREEN_MAGIC_STAFF,
  SPRITE_WEAPON_HAMMER,
  SPRITE_WEAPON_KATANA,
  SPRITE_WEAPON_KNIFE,
  SPRITE_WEAPON_KNIGHT_SWORD,
  SPRITE_WEAPON_LAVISH_SWORD,
  SPRITE_WEAPON_MACE,
  SPRITE_WEAPON_MACHETE,
  SPRITE_WEAPON_RED_GEM_SWORD,
  SPRITE_WEAPON_RED_MAGIC_STAFF,
  SPRITE_WEAPON_REGULAR_SWORD,
  SPRITE_WEAPON_RUSTY_SWORD,
  SPRITE_WEAPON_SAW_SWORD,
  SPRITE_WEAPON_SPEAR,
  SPRITE_WEAPON_THROWING_AXE,
  SPRITE_WEAPON_WARAXE,
  SPRITE_WIZZARD_F_HIT_ANIM_F0,
  SPRITE_WIZZARD_F_IDLE_ANIM_F0,
  SPRITE_WIZZARD_F_IDLE_ANIM_F1,
  SPRITE_WIZZARD_F_IDLE_ANIM_F2,
  SPRITE_WIZZARD_F_IDLE_ANIM_F3,
  SPRITE_WIZZARD_F_RUN_ANIM_F0,
  SPRITE_WIZZARD_F_RUN_ANIM_F1,
  SPRITE_WIZZARD_F_RUN_ANIM_F2,
  SPRITE_WIZZARD_F_RUN_ANIM_F3,
  SPRITE_WIZZARD_M_HIT_ANIM_F0,
  SPRITE_WIZZARD_M_IDLE_ANIM_F0,
  SPRITE_WIZZARD_M_IDLE_ANIM_F1,
  SPRITE_WIZZARD_M_IDLE_ANIM_F2,
  SPRITE_WIZZARD_M_IDLE_ANIM_F3,
  SPRITE_WIZZARD_M_RUN_ANIM_F0,
  SPRITE_WIZZARD_M_RUN_ANIM_F1,
  SPRITE_WIZZARD_M_RUN_ANIM_F2,
  SPRITE_WIZZARD_M_RUN_ANIM_F3,
  SPRITE_WOGOL_IDLE_ANIM_F0,
  SPRITE_WOGOL_IDLE_ANIM_F1,
  SPRITE_WOGOL_IDLE_ANIM_F2,
  SPRITE_WOGOL_IDLE_ANIM_F3,
  SPRITE_WOGOL_RUN_ANIM_F0,
  SPRITE_WOGOL_RUN_ANIM_F1,
  SPRITE_WOGOL_RUN_ANIM_F2,
  SPRITE_WOGOL_RUN_ANIM_F3,
  SPRITE_ZOMBIE_ANIM_F0,
  SPRITE_ZOMBIE_ANIM_F1,
  SPRITE_ZOMBIE_ANIM_F2,
  SPRITE_ZOMBIE_ANIM_F3,
  SPRITE_COUNT,
};

constexpr std::array<Rectangle, SPRITE_COUNT> SPRITE_RECTS = { {
  { .x = 368.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_idle_anim_f0
  { .x = 384.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_idle_anim_f1
  { .x = 400.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_idle_anim_f2
  { .x = 416.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_idle_anim_f3
  { .x = 432.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_run_anim_f0
  { .x = 448.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_run_anim_f1
  { .x = 464.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_run_anim_f2
  { .x = 480.F, .y = 304.F, .width = 16.F, .height = 16.F },// angel_run_anim_f3
  { .x = 16.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_idle_anim_f0
  { .x = 48.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_idle_anim_f1
  { .x = 80.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_idle_anim_f2
  { .x = 112.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_idle_anim_f3
  { .x = 144.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_run_anim_f0
  { .x = 176.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_run_anim_f1
  { .x = 208.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_run_anim_f2
  { .x = 240.F, .y = 428.F, .width = 32.F, .height = 36.F },// big_demon_run_anim_f3
  { .x = 16.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_idle_anim_f0
  { .x = 48.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_idle_anim_f1
  { .x = 80.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_idle_anim_f2
  { .x = 112.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_idle_anim_f3
  { .x = 144.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_run_anim_f0
  { .x = 176.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_run_anim_f1
  { .x = 208.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_run_anim_f2
  { .x = 240.F, .y = 332.F, .width = 32.F, .height = 36.F },// big_zombie_run_anim_f3
  { .x = 288.F, .y = 320.F, .width = 16.F, .height = 16.F },// bomb_f0
  { .x = 304.F, .y = 320.F, .width = 16.F, .height = 16.F },// bomb_f1
  { .x = 320.F, .y = 320.F, .width = 16.F, .height = 16.F },// bomb_f2
  { .x = 64.F, .y = 208.F, .width = 16.F, .height = 16.F },// button_blue_down
  { .x = 48.F, .y = 208.F, .width = 16.F, .height = 16.F },// button_blue_up
  { .x = 32.F, .y = 208.F, .width = 16.F, .height = 16.F },// button_red_down
  { .x = 16.F, .y = 208.F, .width = 16.F, .height = 16.F },// button_red_up
  { .x = 304.F, .y = 400.F, .width = 16.F, .height = 16.F },// chest_empty_open_anim_f0
  { .x = 320.F, .y = 400.F, .width = 16.F, .height = 16.F },// chest_empty_open_anim_f1
  { .x = 336.F, .y = 400.F, .width = 16.F, .height = 16.F },// chest_empty_open_anim_f2
  { .x = 304.F, .y = 416.F, .width = 16.F, .height = 16.F },// chest_full_open_anim_f0
  { .x = 320.F, .y = 416.F, .width = 16.F, .height = 16.F },// chest_full_open_anim_f1
  { .x = 336.F, .y = 416.F, .width = 16.F, .height = 16.F },// chest_full_open_anim_f2
  { .x = 304.F, .y = 432.F, .width = 16.F, .height = 16.F },// chest_mimic_open_anim_f0
  { .x = 320.F, .y = 432.F, .width = 16.F, .height = 16.F },// chest_mimic_open_anim_f1
  { .x = 336.F, .y = 432.F, .width = 16.F, .height = 16.F },// chest_mimic_open_anim_f2
  { .x = 368.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_idle_anim_f0
  { .x = 384.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_idle_anim_f1
  { .x = 400.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_idle_anim_f2
  { .x = 416.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_idle_anim_f3
  { .x = 432.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_run_anim_f0
  { .x = 448.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_run_anim_f1
  { .x = 464.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_run_anim_f2
  { .x = 480.F, .y = 273.F, .width = 16.F, .height = 23.F },// chort_run_anim_f3
  { .x = 289.F, .y = 385.F, .width = 6.F, .height = 7.F },// coin_anim_f0
  { .x = 297.F, .y = 385.F, .width = 6.F, .height = 7.F },// coin_anim_f1
  { .x = 305.F, .y = 385.F, .width = 6.F, .height = 7.F },// coin_anim_f2
  { .x = 313.F, .y = 385.F, .width = 6.F, .height = 7.F },// coin_anim_f3
  { .x = 80.F, .y = 80.F, .width = 16.F, .height = 48.F },// column
  { .x = 96.F, .y = 80.F, .width = 16.F, .height = 48.F },// column_wall
  { .x = 288.F, .y = 408.F, .width = 16.F, .height = 24.F },// crate
  { .x = 368.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_idle_anim_f0
  { .x = 384.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_idle_anim_f1
  { .x = 400.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_idle_anim_f2
  { .x = 416.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_idle_anim_f3
  { .x = 432.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_run_anim_f0
  { .x = 448.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_run_anim_f1
  { .x = 464.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_run_anim_f2
  { .x = 480.F, .y = 345.F, .width = 16.F, .height = 23.F },// doc_run_anim_f3
  { .x = 16.F, .y = 240.F, .width = 16.F, .height = 32.F },// doors_frame_left
  { .x = 64.F, .y = 240.F, .width = 16.F, .height = 32.F },// doors_frame_right
  { .x = 32.F, .y = 224.F, .width = 32.F, .height = 16.F },// doors_frame_top
  { .x = 32.F, .y = 240.F, .width = 32.F, .height = 32.F },// doors_leaf_closed
  { .x = 80.F, .y = 240.F, .width = 32.F, .height = 32.F },// doors_leaf_open
  { .x = 256.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_hit_anim_f0
  { .x = 128.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_idle_anim_f0
  { .x = 144.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_idle_anim_f1
  { .x = 160.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_idle_anim_f2
  { .x = 176.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_idle_anim_f3
  { .x = 192.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_run_anim_f0
  { .x = 208.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_run_anim_f1
  { .x = 224.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_run_anim_f2
  { .x = 240.F, .y = 260.F, .width = 16.F, .height = 28.F },// dwarf_f_run_anim_f3
  { .x = 256.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_hit_anim_f0
  { .x = 128.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_idle_anim_f0
  { .x = 144.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_idle_anim_f1
  { .x = 160.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_idle_anim_f2
  { .x = 176.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_idle_anim_f3
  { .x = 192.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_run_anim_f0
  { .x = 208.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_run_anim_f1
  { .x = 224.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_run_anim_f2
  { .x = 240.F, .y = 292.F, .width = 16.F, .height = 28.F },// dwarf_m_run_anim_f3
  { .x = 96.F, .y = 128.F, .width = 16.F, .height = 16.F },// edge_down
  { .x = 256.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_hit_anim_f0
  { .x = 128.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_idle_anim_f0
  { .x = 144.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_idle_anim_f1
  { .x = 160.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_idle_anim_f2
  { .x = 176.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_idle_anim_f3
  { .x = 192.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_run_anim_f0
  { .x = 208.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_run_anim_f1
  { .x = 224.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_run_anim_f2
  { .x = 240.F, .y = 4.F, .width = 16.F, .height = 28.F },// elf_f_run_anim_f3
  { .x = 256.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_hit_anim_f0
  { .x = 128.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_idle_anim_f0
  { .x = 144.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_idle_anim_f1
  { .x = 160.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_idle_anim_f2
  { .x = 176.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_idle_anim_f3
  { .x = 192.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_run_anim_f0
  { .x = 208.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_run_anim_f1
  { .x = 224.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_run_anim_f2
  { .x = 240.F, .y = 36.F, .width = 16.F, .height = 28.F },// elf_m_run_anim_f3
  { .x = 304.F, .y = 336.F, .width = 16.F, .height = 16.F },// flask_big_blue
  { .x = 320.F, .y = 336.F, .width = 16.F, .height = 16.F },// flask_big_green
  { .x = 288.F, .y = 336.F, .width = 16.F, .height = 16.F },// flask_big_red
  { .x = 336.F, .y = 336.F, .width = 16.F, .height = 16.F },// flask_big_yellow
  { .x = 304.F, .y = 352.F, .width = 16.F, .height = 16.F },// flask_blue
  { .x = 320.F, .y = 352.F, .width = 16.F, .height = 16.F },// flask_green
  { .x = 288.F, .y = 352.F, .width = 16.F, .height = 16.F },// flask_red
  { .x = 336.F, .y = 352.F, .width = 16.F, .height = 16.F },// flask_yellow
  { .x = 16.F, .y = 64.F, .width = 16.F, .height = 16.F },// floor_1
  { .x = 32.F, .y = 64.F, .width = 16.F, .height = 16.F },// floor_2
  { .x = 48.F, .y = 64.F, .width = 16.F, .height = 16.F },// floor_3
  { .x = 16.F, .y = 80.F, .width = 16.F, .height = 16.F },// floor_4
  { .x = 32.F, .y = 80.F, .width = 16.F, .height = 16.F },// floor_5
  { .x = 48.F, .y = 80.F, .width = 16.F, .height = 16.F },// floor_6
  { .x = 16.F, .y = 96.F, .width = 16.F, .height = 16.F },// floor_7
  { .x = 32.F, .y = 96.F, .width = 16.F, .height = 16.F },// floor_8
  { .x = 48.F, .y = 96.F, .width = 16.F, .height = 16.F },// floor_ladder
  { .x = 16.F, .y = 192.F, .width = 16.F, .height = 16.F },// floor_spikes_anim_f0
  { .x = 32.F, .y = 192.F, .width = 16.F, .height = 16.F },// floor_spikes_anim_f1
  { .x = 48.F, .y = 192.F, .width = 16.F, .height = 16.F },// floor_spikes_anim_f2
  { .x = 64.F, .y = 192.F, .width = 16.F, .height = 16.F },// floor_spikes_anim_f3
  { .x = 80.F, .y = 192.F, .width = 16.F, .height = 16.F },// floor_stairs
  { .x = 368.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_idle_anim_f0
  { .x = 384.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_idle_anim_f1
  { .x = 400.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_idle_anim_f2
  { .x = 416.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_idle_anim_f3
  { .x = 432.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_run_anim_f0
  { .x = 448.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_run_anim_f1
  { .x = 464.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_run_anim_f2
  { .x = 480.F, .y = 40.F, .width = 16.F, .height = 16.F },// goblin_run_anim_f3
  { .x = 96.F, .y = 144.F, .width = 16.F, .height = 16.F },// hole
  { .x = 432.F, .y = 136.F, .width = 16.F, .height = 16.F },// ice_zombie_anim_f0
  { .x = 448.F, .y = 136.F, .width = 16.F, .height = 16.F },// ice_zombie_anim_f1
  { .x = 464.F, .y = 136.F, .width = 16.F, .height = 16.F },// ice_zombie_anim_f2
  { .x = 480.F, .y = 136.F, .width = 16.F, .height = 16.F },// ice_zombie_anim_f3
  { .x = 368.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_idle_anim_f0
  { .x = 384.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_idle_anim_f1
  { .x = 400.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_idle_anim_f2
  { .x = 416.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_idle_anim_f3
  { .x = 432.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_run_anim_f0
  { .x = 448.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_run_anim_f1
  { .x = 464.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_run_anim_f2
  { .x = 480.F, .y = 64.F, .width = 16.F, .height = 16.F },// imp_run_anim_f3
  { .x = 256.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_hit_anim_f0
  { .x = 128.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_idle_anim_f0
  { .x = 144.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_idle_anim_f1
  { .x = 160.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_idle_anim_f2
  { .x = 176.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_idle_anim_f3
  { .x = 192.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_run_anim_f0
  { .x = 208.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_run_anim_f1
  { .x = 224.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_run_anim_f2
  { .x = 240.F, .y = 68.F, .width = 16.F, .height = 28.F },// knight_f_run_anim_f3
  { .x = 256.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_hit_anim_f0
  { .x = 128.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_idle_anim_f0
  { .x = 144.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_idle_anim_f1
  { .x = 160.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_idle_anim_f2
  { .x = 176.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_idle_anim_f3
  { .x = 192.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_run_anim_f0
  { .x = 208.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_run_anim_f1
  { .x = 224.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_run_anim_f2
  { .x = 240.F, .y = 100.F, .width = 16.F, .height = 28.F },// knight_m_run_anim_f3
  { .x = 80.F, .y = 208.F, .width = 16.F, .height = 16.F },// lever_left
  { .x = 96.F, .y = 208.F, .width = 16.F, .height = 16.F },// lever_right
  { .x = 256.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_hit_anim_f0
  { .x = 128.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_idle_anim_f0
  { .x = 144.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_idle_anim_f1
  { .x = 160.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_idle_anim_f2
  { .x = 176.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_idle_anim_f3
  { .x = 192.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_run_anim_f0
  { .x = 208.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_run_anim_f1
  { .x = 224.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_run_anim_f2
  { .x = 240.F, .y = 196.F, .width = 16.F, .height = 28.F },// lizard_f_run_anim_f3
  { .x = 256.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_hit_anim_f0
  { .x = 128.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_idle_anim_f0
  { .x = 144.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_idle_anim_f1
  { .x = 160.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_idle_anim_f2
  { .x = 176.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_idle_anim_f3
  { .x = 192.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_run_anim_f0
  { .x = 208.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_run_anim_f1
  { .x = 224.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_run_anim_f2
  { .x = 240.F, .y = 228.F, .width = 16.F, .height = 28.F },// lizard_m_run_anim_f3
  { .x = 368.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_idle_anim_f0
  { .x = 384.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_idle_anim_f1
  { .x = 400.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_idle_anim_f2
  { .x = 416.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_idle_anim_f3
  { .x = 432.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_run_anim_f0
  { .x = 448.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_run_anim_f1
  { .x = 464.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_run_anim_f2
  { .x = 480.F, .y = 153.F, .width = 16.F, .height = 23.F },// masked_orc_run_anim_f3
  { .x = 368.F, .y = 112.F, .width = 16.F, .height = 16.F },// muddy_anim_f0
  { .x = 384.F, .y = 112.F, .width = 16.F, .height = 16.F },// muddy_anim_f1
  { .x = 400.F, .y = 112.F, .width = 16.F, .height = 16.F },// muddy_anim_f2
  { .x = 416.F, .y = 112.F, .width = 16.F, .height = 16.F },// muddy_anim_f3
  { .x = 368.F, .y = 225.F, .width = 16.F, .height = 23.F },// necromancer_anim_f0
  { .x = 384.F, .y = 225.F, .width = 16.F, .height = 23.F },// necromancer_anim_f1
  { .x = 400.F, .y = 225.F, .width = 16.F, .height = 23.F },// necromancer_anim_f2
  { .x = 416.F, .y = 225.F, .width = 16.F, .height = 23.F },// necromancer_anim_f3
  { .x = 16.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_idle_anim_f0
  { .x = 48.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_idle_anim_f1
  { .x = 80.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_idle_anim_f2
  { .x = 112.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_idle_anim_f3
  { .x = 144.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_run_anim_f0
  { .x = 176.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_run_anim_f1
  { .x = 208.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_run_anim_f2
  { .x = 240.F, .y = 380.F, .width = 32.F, .height = 36.F },// ogre_run_anim_f3
  { .x = 368.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_idle_anim_f0
  { .x = 384.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_idle_anim_f1
  { .x = 400.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_idle_anim_f2
  { .x = 416.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_idle_anim_f3
  { .x = 432.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_run_anim_f0
  { .x = 448.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_run_anim_f1
  { .x = 464.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_run_anim_f2
  { .x = 480.F, .y = 201.F, .width = 16.F, .height = 23.F },// orc_shaman_run_anim_f3
  { .x = 368.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_idle_anim_f0
  { .x = 384.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_idle_anim_f1
  { .x = 400.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_idle_anim_f2
  { .x = 416.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_idle_anim_f3
  { .x = 432.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_run_anim_f0
  { .x = 448.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_run_anim_f1
  { .x = 464.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_run_anim_f2
  { .x = 480.F, .y = 177.F, .width = 16.F, .height = 23.F },// orc_warrior_run_anim_f3
  { .x = 368.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_idle_anim_f0
  { .x = 384.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_idle_anim_f1
  { .x = 400.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_idle_anim_f2
  { .x = 416.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_idle_anim_f3
  { .x = 432.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_run_anim_f0
  { .x = 448.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_run_anim_f1
  { .x = 464.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_run_anim_f2
  { .x = 480.F, .y = 321.F, .width = 16.F, .height = 23.F },// pumpkin_dude_run_anim_f3
  { .x = 368.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_idle_anim_f0
  { .x = 384.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_idle_anim_f1
  { .x = 400.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_idle_anim_f2
  { .x = 416.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_idle_anim_f3
  { .x = 432.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_run_anim_f0
  { .x = 448.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_run_anim_f1
  { .x = 464.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_run_anim_f2
  { .x = 480.F, .y = 88.F, .width = 16.F, .height = 16.F },// skelet_run_anim_f3
  { .x = 288.F, .y = 432.F, .width = 16.F, .height = 16.F },// skull
  { .x = 368.F, .y = 369.F, .width = 16.F, .height = 23.F },// slug_anim_f0
  { .x = 384.F, .y = 369.F, .width = 16.F, .height = 23.F },// slug_anim_f1
  { .x = 400.F, .y = 369.F, .width = 16.F, .height = 23.F },// slug_anim_f2
  { .x = 416.F, .y = 369.F, .width = 16.F, .height = 23.F },// slug_anim_f3
  { .x = 432.F, .y = 112.F, .width = 16.F, .height = 16.F },// swampy_anim_f0
  { .x = 448.F, .y = 112.F, .width = 16.F, .height = 16.F },// swampy_anim_f1
  { .x = 464.F, .y = 112.F, .width = 16.F, .height = 16.F },// swampy_anim_f2
  { .x = 480.F, .y = 112.F, .width = 16.F, .height = 16.F },// swampy_anim_f3
  { .x = 432.F, .y = 376.F, .width = 16.F, .height = 16.F },// tiny_slug_anim_f0
  { .x = 448.F, .y = 376.F, .width = 16.F, .height = 16.F },// tiny_slug_anim_f1
  { .x = 464.F, .y = 376.F, .width = 16.F, .height = 16.F },// tiny_slug_anim_f2
  { .x = 480.F, .y = 376.F, .width = 16.F, .height = 16.F },// tiny_slug_anim_f3
  { .x = 368.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_idle_anim_f0
  { .x = 384.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_idle_anim_f1
  { .x = 400.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_idle_anim_f2
  { .x = 416.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_idle_anim_f3
  { .x = 432.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_run_anim_f0
  { .x = 448.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_run_anim_f1
  { .x = 464.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_run_anim_f2
  { .x = 480.F, .y = 16.F, .width = 16.F, .height = 16.F },// tiny_zombie_run_anim_f3
  { .x = 321.F, .y = 370.F, .width = 13.F, .height = 12.F },// ui_heart_empty
  { .x = 289.F, .y = 370.F, .width = 13.F, .height = 12.F },// ui_heart_full
  { .x = 305.F, .y = 370.F, .width = 13.F, .height = 12.F },// ui_heart_half
  { .x = 32.F, .y = 32.F, .width = 16.F, .height = 16.F },// wall_banner_blue
  { .x = 16.F, .y = 48.F, .width = 16.F, .height = 16.F },// wall_banner_green
  { .x = 16.F, .y = 32.F, .width = 16.F, .height = 16.F },// wall_banner_red
  { .x = 32.F, .y = 48.F, .width = 16.F, .height = 16.F },// wall_banner_yellow
  { .x = 32.F, .y = 168.F, .width = 16.F, .height = 16.F },// wall_edge_bottom_left
  { .x = 48.F, .y = 168.F, .width = 16.F, .height = 16.F },// wall_edge_bottom_right
  { .x = 32.F, .y = 136.F, .width = 16.F, .height = 16.F },// wall_edge_left
  { .x = 32.F, .y = 152.F, .width = 16.F, .height = 16.F },// wall_edge_mid_left
  { .x = 48.F, .y = 152.F, .width = 16.F, .height = 16.F },// wall_edge_mid_right
  { .x = 48.F, .y = 136.F, .width = 16.F, .height = 16.F },// wall_edge_right
  { .x = 31.F, .y = 120.F, .width = 16.F, .height = 16.F },// wall_edge_top_left
  { .x = 48.F, .y = 120.F, .width = 16.F, .height = 16.F },// wall_edge_top_right
  { .x = 80.F, .y = 152.F, .width = 16.F, .height = 16.F },// wall_edge_tshape_bottom_left
  { .x = 64.F, .y = 152.F, .width = 16.F, .height = 16.F },// wall_edge_tshape_bottom_right
  { .x = 80.F, .y = 168.F, .width = 16.F, .height = 16.F },// wall_edge_tshape_left
  { .x = 64.F, .y = 168.F, .width = 16.F, .height = 16.F },// wall_edge_tshape_right
  { .x = 64.F, .y = 64.F, .width = 16.F, .height = 16.F },// wall_fountain_basin_blue_anim_f0
  { .x = 80.F, .y = 64.F, .width = 16.F, .height = 16.F },// wall_fountain_basin_blue_anim_f1
  { .x = 96.F, .y = 64.F, .width = 16.F, .height = 16.F },// wall_fountain_basin_blue_anim_f2
  { .x = 64.F, .y = 32.F, .width = 16.F, .height = 16.F },// wall_fountain_basin_red_anim_f0
  { .x = 80.F, .y = 32.F, .width = 16.F, .height = 16.F },// wall_fountain_basin_red_anim_f1
  { .x = 96.F, .y = 32.F, .width = 16.F, .height = 16.F },// wall_fountain_basin_red_anim_f2
  { .x = 64.F, .y = 48.F, .width = 16.F, .height = 16.F },// wall_fountain_mid_blue_anim_f0
  { .x = 80.F, .y = 48.F, .width = 16.F, .height = 16.F },// wall_fountain_mid_blue_anim_f1
  { .x = 96.F, .y = 48.F, .width = 16.F, .height = 16.F },// wall_fountain_mid_blue_anim_f2
  { .x = 64.F, .y = 16.F, .width = 16.F, .height = 16.F },// wall_fountain_mid_red_anim_f0
  { .x = 80.F, .y = 16.F, .width = 16.F, .height = 16.F },// wall_fountain_mid_red_anim_f1
  { .x = 96.F, .y = 16.F, .width = 16.F, .height = 16.F },// wall_fountain_mid_red_anim_f2
  { .x = 64.F, .y = 0.F, .width = 16.F, .height = 16.F },// wall_fountain_top_1
  { .x = 80.F, .y = 0.F, .width = 16.F, .height = 16.F },// wall_fountain_top_2
  { .x = 96.F, .y = 0.F, .width = 16.F, .height = 16.F },// wall_fountain_top_3
  { .x = 64.F, .y = 80.F, .width = 16.F, .height = 16.F },// wall_goo
  { .x = 64.F, .y = 96.F, .width = 16.F, .height = 16.F },// wall_goo_base
  { .x = 48.F, .y = 32.F, .width = 16.F, .height = 16.F },// wall_hole_1
  { .x = 48.F, .y = 48.F, .width = 16.F, .height = 16.F },// wall_hole_2
  { .x = 16.F, .y = 16.F, .width = 16.F, .height = 16.F },// wall_left
  { .x = 32.F, .y = 16.F, .width = 16.F, .height = 16.F },// wall_mid
  { .x = 0.F, .y = 168.F, .width = 16.F, .height = 16.F },// wall_outer_front_left
  { .x = 16.F, .y = 168.F, .width = 16.F, .height = 16.F },// wall_outer_front_right
  { .x = 0.F, .y = 152.F, .width = 16.F, .height = 16.F },// wall_outer_mid_left
  { .x = 16.F, .y = 152.F, .width = 16.F, .height = 16.F },// wall_outer_mid_right
  { .x = 0.F, .y = 136.F, .width = 16.F, .height = 16.F },// wall_outer_top_left
  { .x = 16.F, .y = 136.F, .width = 16.F, .height = 16.F },// wall_outer_top_right
  { .x = 48.F, .y = 16.F, .width = 16.F, .height = 16.F },// wall_right
  { .x = 16.F, .y = 0.F, .width = 16.F, .height = 16.F },// wall_top_left
  { .x = 32.F, .y = 0.F, .width = 16.F, .height = 16.F },// wall_top_mid
  { .x = 48.F, .y = 0.F, .width = 16.F, .height = 16.F },// wall_top_right
  { .x = 322.F, .y = 65.F, .width = 12.F, .height = 30.F },// weapon_anime_sword
  { .x = 324.F, .y = 202.F, .width = 7.F, .height = 21.F },// weapon_arrow
  { .x = 341.F, .y = 74.F, .width = 9.F, .height = 21.F },// weapon_axe
  { .x = 323.F, .y = 41.F, .width = 10.F, .height = 22.F },// weapon_baton_with_spikes
  { .x = 291.F, .y = 26.F, .width = 10.F, .height = 37.F },// weapon_big_hammer
  { .x = 289.F, .y = 195.F, .width = 14.F, .height = 26.F },// weapon_bow
  { .x = 305.F, .y = 195.F, .width = 14.F, .height = 26.F },// weapon_bow_2
  { .x = 310.F, .y = 108.F, .width = 9.F, .height = 19.F },// weapon_cleaver
  { .x = 288.F, .y = 167.F, .width = 16.F, .height = 24.F },// weapon_double_axe
  { .x = 325.F, .y = 97.F, .width = 9.F, .height = 30.F },// weapon_duel_sword
  { .x = 291.F, .y = 137.F, .width = 10.F, .height = 22.F },// weapon_golden_sword
  { .x = 340.F, .y = 129.F, .width = 8.F, .height = 30.F },// weapon_green_magic_staff
  { .x = 307.F, .y = 39.F, .width = 10.F, .height = 24.F },// weapon_hammer
  { .x = 293.F, .y = 66.F, .width = 6.F, .height = 29.F },// weapon_katana
  { .x = 293.F, .y = 10.F, .width = 6.F, .height = 13.F },// weapon_knife
  { .x = 339.F, .y = 98.F, .width = 10.F, .height = 29.F },// weapon_knight_sword
  { .x = 307.F, .y = 129.F, .width = 10.F, .height = 30.F },// weapon_lavish_sword
  { .x = 339.F, .y = 39.F, .width = 10.F, .height = 24.F },// weapon_mace
  { .x = 294.F, .y = 105.F, .width = 5.F, .height = 22.F },// weapon_machete
  { .x = 339.F, .y = 10.F, .width = 10.F, .height = 21.F },// weapon_red_gem_sword
  { .x = 324.F, .y = 129.F, .width = 8.F, .height = 30.F },// weapon_red_magic_staff
  { .x = 323.F, .y = 10.F, .width = 10.F, .height = 21.F },// weapon_regular_sword
  { .x = 307.F, .y = 10.F, .width = 10.F, .height = 21.F },// weapon_rusty_sword
  { .x = 307.F, .y = 70.F, .width = 10.F, .height = 25.F },// weapon_saw_sword
  { .x = 309.F, .y = 161.F, .width = 6.F, .height = 30.F },// weapon_spear
  { .x = 340.F, .y = 161.F, .width = 10.F, .height = 14.F },// weapon_throwing_axe
  { .x = 324.F, .y = 168.F, .width = 12.F, .height = 23.F },// weapon_waraxe
  { .x = 256.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_hit_anim_f0
  { .x = 128.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_idle_anim_f0
  { .x = 144.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_idle_anim_f1
  { .x = 160.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_idle_anim_f2
  { .x = 176.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_idle_anim_f3
  { .x = 192.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_run_anim_f0
  { .x = 208.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_run_anim_f1
  { .x = 224.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_run_anim_f2
  { .x = 240.F, .y = 132.F, .width = 16.F, .height = 28.F },// wizzard_f_run_anim_f3
  { .x = 256.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_hit_anim_f0
  { .x = 128.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_idle_anim_f0
  { .x = 144.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_idle_anim_f1
  { .x = 160.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_idle_anim_f2
  { .x = 176.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_idle_anim_f3
  { .x = 192.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_run_anim_f0
  { .x = 208.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_run_anim_f1
  { .x = 224.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_run_anim_f2
  { .x = 240.F, .y = 164.F, .width = 16.F, .height = 28.F },// wizzard_m_run_anim_f3
  { .x = 368.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_idle_anim_f0
  { .x = 384.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_idle_anim_f1
  { .x = 400.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_idle_anim_f2
  { .x = 416.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_idle_anim_f3
  { .x = 432.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_run_anim_f0
  { .x = 448.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_run_anim_f1
  { .x = 464.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_run_anim_f2
  { .x = 480.F, .y = 249.F, .width = 16.F, .height = 23.F },// wogol_run_anim_f3
  { .x = 368.F, .y = 136.F, .width = 16.F, .height = 16.F },// zombie_anim_f0
  { .x = 384.F, .y = 136.F, .width = 16.F, .height = 16.F },// zombie_anim_f1
  { .x = 400.F, .y = 136.F, .width = 16.F, .height = 16.F },// zombie_anim_f2
  { .x = 416.F, .y = 136.F, .width = 16.F, .height = 16.F },// zombie_anim_f3
} };
