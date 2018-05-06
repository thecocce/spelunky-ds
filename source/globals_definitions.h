//
// Created by xdbeef on 06.05.18.
//

#ifndef SPELUNKYDS_GLOBALS_DEFINITIONS_H
#define SPELUNKYDS_GLOBALS_DEFINITIONS_H

#include <nds/jtypes.h>
#include <mm_types.h>
#include "sprites/spritesheet_type.h"
#include "sprites/sprite_type.h"
#include "sprites/sprite_info.h"
#include "hud/hud.h"
#include "tiles/level_generator.h"
#include "sprites/main_dude/main_dude.h"

namespace global {

    InputHandler *input_handler = new InputHandler();
    Camera *camera = new Camera();
    MainDude *main_dude = new MainDude();
    LevelGenerator *level_generator = new LevelGenerator();
    OAMManager *main_oam_manager = new OAMManager();
    OAMManager *sub_oam_manager = new OAMManager();
    Hud *hud = new Hud();
    std::vector<MovingObject *> sprites(0, nullptr);
    std::vector<SpriteInfo *> spriteInfos(0, nullptr);
    int bg_main_address = 0;
    int bg_sub_address = 0;
    bool bombed = false;
    double *timer = nullptr;
    bool splash_screen = false;
    bool scores_screen = false;
    bool in_main_menu = true;
    bool levels_transition_screen = false;
    mm_sfxhand menu_music_handler = 0;
    mm_sfxhand cave_music_handler = 0;
    std::vector <SpritesheetType> killed_npcs(0);
    std::vector <SpriteType> collected_loot(0);
    PrintConsole *printConsole = nullptr;

    u16 current_map[4096];

    u16 base_map[4096] = {
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5, 0, 1, 4, 5,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7, 2, 3, 6, 7,
            8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12,
            13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9, 12, 13, 8, 9,
            12, 13,
            10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14,
            15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11, 14, 15, 10, 11,
            14, 15, 10, 11, 14, 15, 10, 11, 14, 15,

    };

}
#endif //SPELUNKYDS_GLOBALS_DEFINITIONS_H
