//
// Created by xdbeef on 03.03.18.
//

#ifndef SPELUNKYDS_MAPA_H
#define SPELUNKYDS_MAPA_H

#include <nds.h>
#include "../input/InputHandler.h"
#include "../console/TextManager.h"
#include "../animations/Camera.h"
#include "../animations/MainDude.h"
#include "../hud/Hud.h"

//One line width is 512px/8px = 64 elements (4 rows)
namespace global {

    InputHandler *input_handler = new InputHandler();
    TextManager *textManager = new TextManager();
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
    double *timer = 0;

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
#endif //SPELUNKYDS_MAPA_H
